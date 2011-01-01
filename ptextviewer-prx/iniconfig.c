#include <string.h>
#include <stdbool.h>
#include <pspctrl.h>

#include "libini.h"
#include "iniconfig.h"


// Libini�̃T���v�����
void strutilRemoveChar( char *__restrict__ str, const char *__restrict__ search )
{
	int offset = 0,ins_offset = 0;
	
	while( str[offset] != '\0' )
	{
		if( ! strchr( search, str[offset] )  )
		{
			str[ins_offset++] = str[offset];
		}
		
		offset++;
	}
	
	str[ins_offset] = str[offset];
}


/*
	iniSplit�̃R�[���o�b�N�֐�
	�w�肵����؂蕶���ŕ������ꂽ�l�������Ă���
*/
void callbackToSplit(const char *val,void *opt)
{
	int i;
	int *pad = (int*)opt;
	
	//Pad Code�֕ϊ��\�ȕ�����
	
	struct pad_data
	{
		char *name;
		unsigned int code;
	} pad_list[] =
	{
		{ "SELECT"		,PSP_CTRL_SELECT	},
		{ "START"		,PSP_CTRL_START		},
		{ "Up"			,PSP_CTRL_UP		},
		{ "Right"		,PSP_CTRL_RIGHT		},
		{ "Down"		,PSP_CTRL_DOWN		},
		{ "Left"		,PSP_CTRL_LEFT		},
		{ "LTrigger"	,PSP_CTRL_LTRIGGER	},
		{ "RTrigger"	,PSP_CTRL_RTRIGGER	},
		{ "Triangle"	,PSP_CTRL_TRIANGLE	},
		{ "Circle"		,PSP_CTRL_CIRCLE	},
		{ "Cross"		,PSP_CTRL_CROSS		},
		{ "Square"		,PSP_CTRL_SQUARE	},
		{ "HOME"		,PSP_CTRL_HOME		},
//		{ "HOLD"		,PSP_CTRL_HOLD		},
		{ "NOTE"		,PSP_CTRL_NOTE		},
		{ "SCREEN"		,PSP_CTRL_SCREEN	},
		{ "VolUp"		,PSP_CTRL_VOLUP		},
		{ "VolDown"		,PSP_CTRL_VOLDOWN	},
//		{ "WLAN"		,PSP_CTRL_WLAN_UP	},
//		{ "REMOTE"		,PSP_CTRL_REMOTE	},
//		{ "DISC"		,PSP_CTRL_DISC		},
//		{ "MS"			,PSP_CTRL_MS		},
	};
	
	
	const int pad_list_size = sizeof(pad_list) / sizeof(struct pad_data);
	
	
	//pad_list�̊ePad Name�Ɣ�r
	for( i = 0 ; i < pad_list_size ; i++ )
	{
		//�啶����������ʂ�����r����
		//��v���镨�������Pad Code�֕ϊ����A���[�v�𔲂���(=�֐��I��)
		if( !strcasecmp(val,pad_list[i].name) )
		{
			*pad |= pad_list[i].code;
			break;
		}
	}
}

bool callbackForIni(const char *key, char *val,void *opt){
	if( strcasecmp(key,"BootKey") == 0 ){
		int *bootKey = (int *)opt;
		
		//iniSplit�ŏ������邽�߂�
		//�s�v�ȕ���(�^�u�A���p/�S�p�X�y�[�X�j��l���珜��
		strutilRemoveChar( val,"\t\x20�@" );
		
		//iniSplitVal�ł���ɒl��'+'��؂�ŕ���
		//�R�[���o�b�N�֐��� 'pad'�ϐ����I�v�V�����Ƃ��ēn���Č��ʂ��󂯎��
		iniSplitVal(val,"+",callbackToSplit,bootKey);
		
		return true;
	}


	return false;
}


int readConfig( const char *file_name , int *buttonNum )
{

	ini_pair list[2];
	ini_data data;
	int bootKey = 0;
	char buf[256];
	bool swapButtonFlag;

	memset(&data,0,sizeof(ini_data));
	memset(list,0,sizeof(list));
	
	data.pair	= list;
	data.size	= sizeof(list);
	data.buf	= buf;
	data.bufLen	= 256;
	
	iniAddKey( &data ,"SwapButton"	,INI_TYPE_BOOL	,&swapButtonFlag	,false	);
	iniAddKey( &data ,"BootKey"		,INI_TYPE_STR ,NULL ,0);
	
	iniLoad(file_name,&data,callbackForIni,&bootKey);
	
	if( swapButtonFlag ){
		buttonNum[0] = 1;
		buttonNum[1] = 0;
	}else{
		buttonNum[0] = 0;
		buttonNum[1] = 1;
	}
	
	if(bootKey == 0){
		bootKey = PSP_CTRL_RTRIGGER | PSP_CTRL_LTRIGGER | PSP_CTRL_NOTE;
	}
	return bootKey;
}