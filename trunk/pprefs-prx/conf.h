//from mp3play


// 


#ifndef __CONF_H__
#define	__CONF_H__

#include <stdbool.h>


typedef struct
{
	u32 bootKey;
	bool swapButton;
	bool bootMessage;
	bool onePushRestart;
	int lineFeedCode;// = 0:CR+LF  =1:CR  =2:LF
	char basePath[64];
	char basePathOri[64];
	char basePathDefault[64];
	u32 color0;
	u32 color1;
	u32 color2;
	u32 color3;
	u32 sortType;
} Conf_Key;


//���(�t���O) for INI_Key foo.type
enum
{
	INI_TYPE_DYNAMIC = 1,	//
	INI_TYPE_STATIC = 2,	//
	INI_TYPE_HEX = 4,	//
	INI_TYPE_BUTTON = 8,	//
	INI_TYPE_STRING = 16,	//
	INI_TYPE_LIST = 32,
	INI_TYPE_BOOL = 64,
};

typedef struct
{
	char key[64];//����
	
	//�L���X�g����̂��ʓ|�Ȃ̂ł��낢��Ȍ^�̃|�C���^�[�𑵂��Ă���
	union{
		int *i;
		char *s;
		u32 *u;
		bool *b;
	}value;//�E��
	
	union{
		int i;
		char *s;
		u32 u;
		bool b;
	}defaultValue;//�f�t�H���g�l
	
	u32 type;//���(�t���O)
	
	//�g��(��ނɂ���Ďg������g��Ȃ�������)
	void *ex;
//	void **exx;
	

	
	int keyNum;//key[0]�ł����g���Ȃ����烁�����[�̖��ʌ���?
	
} INI_Key;





int INI_Read_Conf(const char *path, INI_Key *key);
void INI_Add_Hex(INI_Key *key, char *keyName,  u32 *value, u32 defaultValue, int *ex);
void INI_Add_Button(INI_Key *key, char *keyName,  u32 *value, u32 defaultValue);
void INI_Add_String(INI_Key *key, char *keyName, char *value, char *defaultValue);
void INI_Add_List(INI_Key *key, char *keyName, int *value, int defaultValue, const char *list[] );
void INI_Init_Key(INI_Key *key);
void INI_Add_Bool(INI_Key *key, char *keyName, bool *value, bool defaultValue);
void INI_Set_Default(INI_Key *key);

int INI_Write_Conf(const char *ms_path, INI_Key *key, const char *lineFeedCode);

#endif

