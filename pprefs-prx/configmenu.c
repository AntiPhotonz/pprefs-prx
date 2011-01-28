#include "common.h"
#include "button.h"
#include "pprefsmenu.h"
#include "language.h"
#include "fileselecter.h"



void selectBasePath(char *path)
{
	wait_button_up(&padData);
	if(  fileSelecter(config.basePath,&dirTmp, PPREFSMSG_SELECTBASEPATH, 2, NULL ) == 0  ){
		strcpy(path,dirTmp.name);
	}
	wait_button_up(&padData);
}
u32 detect_key(void)
{
	
	clock_t timesec;
	char *temp;
	u32 beforeKey = 0;
	
	wait_button_up(&padData);
	makeWindow(
		24 , 28 ,
		480 - LIBM_CHAR_WIDTH*3 , 28 + LIBM_CHAR_HEIGHT*5,
		FG_COLOR,BG_COLOR
	);
	libmPrint( 24 + LIBM_CHAR_WIDTH, 28 + LIBM_CHAR_HEIGHT    , FG_COLOR, BG_COLOR, "�L�[���o �c�� �b" );
	while(1){
		get_button(&padData);
		if( padData.Buttons != 0 ) break;
	}

	timesec = sceKernelLibcClock();
	while(1){
		get_button(&padData);
		if( beforeKey != padData.Buttons ){
			libmFillRect( 24 + LIBM_CHAR_WIDTH, 28 + LIBM_CHAR_HEIGHT*2+2, 480 - LIBM_CHAR_WIDTH*3, 28 + LIBM_CHAR_HEIGHT*3+2, BG_COLOR );
			commonBuf[0] = '\0';
			GET_KEY_NAME(padData.Buttons, commonBuf);
			temp = strrchr(commonBuf, '+');
			if( temp != NULL ) temp[-1] = '\0';
			libmPrint   ( 24 + LIBM_CHAR_WIDTH, 28 + LIBM_CHAR_HEIGHT*2+2, FG_COLOR, BG_COLOR, commonBuf);
			beforeKey = padData.Buttons;
		}
		libmPrintf  ( 24 + LIBM_CHAR_WIDTH, 28 + LIBM_CHAR_HEIGHT    , FG_COLOR, BG_COLOR, "�L�[���o �c��%d�b", (int)( 3 -  ( (sceKernelLibcClock() - timesec)/1000000) )  );
		if( (sceKernelLibcClock() - timesec) >= (3 * 1000 * 1000) ) break;
	}
	
	return padData.Buttons;
}

#define SPACE_BETWEEN_THE_LINES (LIBM_CHAR_HEIGHT + 2)
/*
#define ARROW_POSITION ( \
( now_arrow < conf[0].keyNum )? \
( now_arrow *2 ): \
( conf[0].keyNum * 2 + now_arrow - conf[0].keyNum + 1 ) \
)
*/

#define ARROW_POSITION ( now_arrow * 2 )

int config_menu(void)
{
	Conf_Key oldConfig = config;
	char *temp,**listPtr;
	char iniPath[256];
	int now_arrow = 0,i;
	char *whatIsThis[] = {
		"pprefs���N��������{�^���̎w��(�f�t�H���g��HOME)",
		"�{�̂��N�������Ƃ��ɍ����ɕ\\�������upprefs�N����������!�`�v��\\�����邩?(�f�t�H���g��true)",
		"�~/���{�^���̖��������ւ��� true��������/�~�L�����Z�� false���~����/���L�����Z��(�f�t�H���g��false)",
		"VSH�ċN������̂�START����x��������x������ true����x���� true����x����(�f�t�H���g��false)",
		"���̃v���O�C�����e�L�X�g�������o���Ƃ��Ɏg�����s�R�[�h(�f�t�H���g��CR+LF)",
		"vsh.txt,game.txt,pops.txt������t�H���_�̃p�X",
		"�ʏ�̕����F",
		"�w�i�̐F",
		"�I�����ꂽ�����F",
		"���ɕ\\�����������̕����F",
	};

	
	while(1){
		PRINT_SCREEN();
		
		libmPrint(15,28,BG_COLOR,FG_COLOR," �ݒ� ");
		for( i = 0; i < conf[0].keyNum; i++ ){
			if( 
				strcasecmp( "Color0", conf[i].key ) == 0 ||
				strcasecmp( "Color2", conf[i].key ) == 0 ||
				strcasecmp( "Color3", conf[i].key ) == 0
			){
				libmPrintf(15, 46 + i*2*SPACE_BETWEEN_THE_LINES, *conf[i].value.u, BG_COLOR,"%s = %x",conf[i].key, *conf[i].value.u);
				libmPrint (15, 46 + (i*2+1)*SPACE_BETWEEN_THE_LINES, EX_COLOR , BG_COLOR, whatIsThis[i]);
				continue;
			}else if( conf[i].type & INI_TYPE_BUTTON ){
				sprintf(commonBuf,"%s = ",conf[i].key);
				GET_KEY_NAME(*conf[i].value.u, commonBuf);
				temp = strrchr(commonBuf, '+');
				if( temp != NULL ) temp[-1] = '\0';
			}else if( conf[i].type & INI_TYPE_LIST ){
				listPtr = (char **)conf[i].ex;
				sprintf(commonBuf,"%s = %s", conf[i].key, listPtr[*conf[i].value.i]);
			}else if( conf[i].type & INI_TYPE_BOOL ){
				sprintf(commonBuf,"%s = %s",conf[i].key, *conf[i].value.b?"true":"false");
			}else if( conf[i].type & INI_TYPE_HEX ){
				sprintf(commonBuf,"%s = %x",conf[i].key, *conf[i].value.u);
			}else if( conf[i].type & INI_TYPE_STRING ){
				sprintf(commonBuf,"%s = %s",conf[i].key, conf[i].value.s);
			}
			libmPrint (15, 46 + i*2*SPACE_BETWEEN_THE_LINES, FG_COLOR, BG_COLOR,commonBuf);
			libmPrint (15, 46 + (i*2+1)*SPACE_BETWEEN_THE_LINES, EX_COLOR , BG_COLOR, whatIsThis[i]);
		}
/*		
		libmPrint (15, 46 +(i*2+1)*(SPACE_BETWEEN_THE_LINES), FG_COLOR, BG_COLOR, "��L�̐ݒ�ŕۑ�����");
		libmPrint (15, 46 +(i*2+2)*(SPACE_BETWEEN_THE_LINES), FG_COLOR, BG_COLOR, "�f�t�H���g�l�ɂ���");
		libmPrint (15, 46 +(i*2+3)*(SPACE_BETWEEN_THE_LINES), FG_COLOR, BG_COLOR, "��߂�");
*/
		libmPrintf(5, 46 +ARROW_POSITION * SPACE_BETWEEN_THE_LINES, FG_COLOR, BG_COLOR, ">");

		libmPrintf(5,264,EX_COLOR ,BG_COLOR," %s:�I�� START:�ۑ� HOME:��߂� SELECT:�f�t�H���g�l�ɂ��� ",buttonData[buttonNum[0]].name);

		wait_button_up(&padData);
		while(1){
			get_button(&padData);
			if( padData.Buttons & PSP_CTRL_DOWN ){
				libmPrintf(5, 46 +ARROW_POSITION * SPACE_BETWEEN_THE_LINES, FG_COLOR, BG_COLOR, " ");
				now_arrow++;
				if( now_arrow >= conf[0].keyNum ) now_arrow = 0;
				libmPrintf(5, 46 +ARROW_POSITION * SPACE_BETWEEN_THE_LINES, FG_COLOR, BG_COLOR, ">");
				wait_button_up(&padData);
			}else if( padData.Buttons & PSP_CTRL_UP ){
				libmPrintf(5, 46 +ARROW_POSITION * SPACE_BETWEEN_THE_LINES, FG_COLOR, BG_COLOR, " ");
				now_arrow--;
				if( now_arrow < 0 ) now_arrow = conf[0].keyNum - 1;
				libmPrintf(5, 46 +ARROW_POSITION * SPACE_BETWEEN_THE_LINES, FG_COLOR, BG_COLOR, ">");
				wait_button_up(&padData);
			}else if( padData.Buttons & buttonData[buttonNum[0]].flag ){
				if( strcasecmp( "BasePath", conf[now_arrow].key ) == 0 ){
					selectBasePath(conf[now_arrow].value.s);
				}else if( strcasecmp( "Color2", conf[now_arrow].key ) == 0 ){
					if( *conf[now_arrow].value.u == RED ){
						*conf[now_arrow].value.u = GREEN;
					}else if( *conf[now_arrow].value.u == GREEN ){
						*conf[now_arrow].value.u = RED;
					}
				}else if( conf[now_arrow].type & INI_TYPE_BUTTON ){
					*conf[now_arrow].value.u = detect_key();
					if( *conf[now_arrow].value.u == 0 ) *conf[now_arrow].value.u = conf[now_arrow].defaultValue.u;
				}else if( conf[now_arrow].type & INI_TYPE_LIST ){
					listPtr = (char **)conf[now_arrow].ex;
					(*conf[now_arrow].value.i)++;
					if( listPtr[*conf[now_arrow].value.i] == NULL ) *conf[now_arrow].value.i = 0;
				}else if( conf[now_arrow].type & INI_TYPE_BOOL ){
					*conf[now_arrow].value.b = !*conf[now_arrow].value.b;
				}
				break;
			}else if( padData.Buttons & PSP_CTRL_START ){
				strcpy(iniPath, ownPath);
				temp = strrchr(iniPath, '/');
				if( temp != NULL ) *temp = '\0';
				strcat(iniPath,INI_NAME);
				INI_Write_Conf(iniPath, conf, lineFeedCode[config.lineFeedCode]);
				SET_CONFIG();
				wait_button_up(&padData);
				return 0;
			}else if( padData.Buttons & PSP_CTRL_SELECT ){
				INI_Set_Default(conf);
				wait_button_up(&padData);
				break;
			}else if( padData.Buttons & PSP_CTRL_HOME ){
				config = oldConfig;
				wait_button_up(&padData);
				return 1;
			}
		}

	}
	
}
