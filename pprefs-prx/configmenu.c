#include "common.h"
#include "libmenu.h"
#include "button.h"
#include "main.h"
#include "language.h"
#include "pprefs.h"

u32 detect_key(void)
{
	
	double timesec;
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

	timesec = gettimeofday_sec();
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
		libmPrintf  ( 24 + LIBM_CHAR_WIDTH, 28 + LIBM_CHAR_HEIGHT    , FG_COLOR, BG_COLOR, "�L�[���o �c��%d�b", (int)(3 - (gettimeofday_sec() - timesec)) );
		if( (gettimeofday_sec() - timesec) >= 3 ) break;
	}
	
	return padData.Buttons;
}

int config_menu(void)
{
	Conf_Key newConfig = config;
	char *temp;
	int now_arrow = 0,menuNum = 9;
	char *lineFeedCodeName[] = {
		"CR+LF",
		"LF",
//		"CF"
	};
	
	while(1){
		PRINT_SCREEN();
		
		libmPrint(15,28,BG_COLOR,FG_COLOR," �ݒ� ");
		strcpy(commonBuf,"�N���L�[:");
		GET_KEY_NAME(newConfig.bootKey, commonBuf);
		temp = strrchr(commonBuf, '+');
		if( temp != NULL ) temp[-1] = '\0';
		libmPrint (15, 46                         , FG_COLOR, BG_COLOR,commonBuf);
		libmPrint (15, 46 + 1*(LIBM_CHAR_HEIGHT+2), SILVER  , BG_COLOR, "pprefs���N��������{�^���̎w��(�f�t�H���g��HOME)");

		libmPrintf(15, 46 + 2*(LIBM_CHAR_HEIGHT+2), FG_COLOR, BG_COLOR, "�{�̋N�������b�Z�[�W:%s",newConfig.bootMessage?"O N":"OFF");
		libmPrint (15, 46 + 3*(LIBM_CHAR_HEIGHT+2), SILVER  , BG_COLOR, "�{�̂��N�������Ƃ��ɍ����ɕ\\�������upprefs�N����������!�`�v��\\�����邩?(�f�t�H���g��ON)");
	
		libmPrintf(15, 46 + 4*(LIBM_CHAR_HEIGHT+2), FG_COLOR, BG_COLOR, "�~/���̖�������ւ�:%s", newConfig.swapButton?"O N":"OFF");
		libmPrint (15, 46 + 5*(LIBM_CHAR_HEIGHT+2), SILVER  , BG_COLOR, "�~/���{�^���̖��������ւ��� ON��������/�~�L�����Z�� OFF���~����/���L�����Z��(�f�t�H���g��OFF)");
		
		libmPrintf(15, 46 + 6*(LIBM_CHAR_HEIGHT+2), FG_COLOR, BG_COLOR, "��x������VSH�ċN��:%s", newConfig.onePushRestart?"O N":"OFF");
		libmPrint (15, 46 + 7*(LIBM_CHAR_HEIGHT+2), SILVER  , BG_COLOR, "VSH�ċN������̂�START����x��������x������ ON����x���� OFF����x����(�f�t�H���g��OFF)");

		libmPrintf(15, 46 + 8*(LIBM_CHAR_HEIGHT+2), FG_COLOR, BG_COLOR, "���s�R�[�h:%s", lineFeedCodeName[newConfig.lineFeedCode]);
		libmPrint (15, 46 + 9*(LIBM_CHAR_HEIGHT+2), SILVER  , BG_COLOR, "���̃v���O�C�����e�L�X�g�������o���Ƃ��Ɏg�����s�R�[�h(�f�t�H���g��CR+LF)");

		libmPrintf(15, 46 + 10*(LIBM_CHAR_HEIGHT+2), FG_COLOR, BG_COLOR, "�f�t�H���g�p�X:%s", (newConfig.defaultPath == 0)?"ms0:/seplugins/":"ms0:/plugins/" );
		libmPrint (15, 46 + 11*(LIBM_CHAR_HEIGHT+2), SILVER  , BG_COLOR, "vsh.txt,game.txt,pops.txt�̃p�X(���̍��ڂ�ύX������蓮�Ń����[�h���ĉ�����)");

		libmPrint (15, 46 +12*(LIBM_CHAR_HEIGHT+2), FG_COLOR, BG_COLOR, "��L�̐ݒ�ŕۑ�����");

		libmPrint (15, 46 +14*(LIBM_CHAR_HEIGHT+2), FG_COLOR, BG_COLOR, "�f�t�H���g�l�ɂ���");

		libmPrint (15, 46 +16*(LIBM_CHAR_HEIGHT+2), FG_COLOR, BG_COLOR, "��߂�");

		libmPrintf(5, 46 + now_arrow*2*(LIBM_CHAR_HEIGHT+2), FG_COLOR, BG_COLOR, ">");

		libmPrintf(5,264,FG_COLOR,BG_COLOR," %s:�I�� HOME:��߂�",buttonData[buttonNum[0]].name);

		wait_button_up(&padData);
		while(1){
			get_button(&padData);
			if( padData.Buttons & PSP_CTRL_DOWN ){
				libmPrintf(5,46 + now_arrow*2*(LIBM_CHAR_HEIGHT+2),BG_COLOR,BG_COLOR," ");
				if( now_arrow + 1 < menuNum ) now_arrow++;
				else now_arrow = 0;
				libmPrintf(5,46 + now_arrow*2*(LIBM_CHAR_HEIGHT+2),FG_COLOR,BG_COLOR,">");
				wait_button_up(&padData);
			}else if( padData.Buttons & PSP_CTRL_UP ){
				libmPrintf(5,46 + now_arrow*2*(LIBM_CHAR_HEIGHT+2),BG_COLOR,BG_COLOR," ");
				if( now_arrow - 1 >= 0 ) now_arrow--;
				else now_arrow = menuNum - 1;
				libmPrintf(5,46 + now_arrow*2*(LIBM_CHAR_HEIGHT+2),FG_COLOR,BG_COLOR,">");
				wait_button_up(&padData);
			}else if( padData.Buttons & buttonData[buttonNum[0]].flag ){
				if( now_arrow == 0 ){
					newConfig.bootKey = detect_key();
					if( newConfig.bootKey == 0 ) newConfig.bootKey = PSP_CTRL_HOME;
					break;
				}else if( now_arrow == 1 ){
					newConfig.bootMessage = ! newConfig.bootMessage;
					break;
				}else if( now_arrow == 2 ){
					newConfig.swapButton = ! newConfig.swapButton;
					break;
				}else if( now_arrow == 3 ){
					newConfig.onePushRestart = ! newConfig.onePushRestart;
					break;
				}else if( now_arrow == 4 ){
					newConfig.lineFeedCode++;
					if( newConfig.lineFeedCode > 1 ) newConfig.lineFeedCode = 0;
					break;
				}else if( now_arrow == 5 ){
					newConfig.defaultPath++;
					if( newConfig.defaultPath > 1 ) newConfig.defaultPath = 0;
					break;
				}else if( now_arrow == (menuNum -3) ){
					SUSPEND_THREADS();
					config = newConfig;
					if( config.swapButton ){
						buttonNum[0] = 1;
						buttonNum[1] = 0;
					}else{
						buttonNum[0] = 0;
						buttonNum[1] = 1;
					}
					Set_Default_Path( sepluginsTextPath,config.defaultPath);
					Write_Conf(ownPath,&newConfig);
					wait_button_up(&padData);
					return 0;
				}else if( now_arrow == (menuNum -2) ){
					Set_Default_Conf(&newConfig);
					break;
				}else if( now_arrow == (menuNum -1) ){
					wait_button_up(&padData);
					return 1;
				}
			}else if( padData.Buttons & PSP_CTRL_HOME ){
					wait_button_up(&padData);
					return 1;
			}
		}

	}
	
}
