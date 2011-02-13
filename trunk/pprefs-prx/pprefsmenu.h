
#ifndef __PPREFSMENU_H_
#define __PPREFSMENU_H_
#include <pspkernel.h>
#include "libmenu.h"

#include "color.h"

#define FG_COLOR config.color0
#define BG_COLOR config.color1
#define SL_COLOR config.color2
#define EX_COLOR config.color3

#define FG_COLOR_DEFAULT WHITE
#define BG_COLOR_DEFAULT BLACK
#define SL_COLOR_DEFAULT RED
#define EX_COLOR_DEFAULT SILVER

#define PRINT_SCREEN() \
libmFillRect( 0 , 0 , 480 , 272 , BG_COLOR); \
libmPrint(10,10,FG_COLOR,BG_COLOR,"pprefs Ver. 1.096beta2   by hiroi01"); \
libmPrint(440,10,FG_COLOR,BG_COLOR,modelName[deviceModel]);

extern char pprefsPrintBuf[128];

#define libmPrintf(x,y,fg,bg,format, ... ) libmPrintfXY(x,y,fg,bg,pprefsPrintBuf,COMMON_BUF_LEN,format, ##__VA_ARGS__)
#define libmPrint libmPrintXY
#define fillLine(sy,color) libmFillRect( 0 , sy , 480 , sy + LIBM_CHAR_HEIGHT ,color);

/*-----------------------------------------------
�Z���N�g�{�b�N�X�����
���ƍ����͕������ɂ���Ď�������
@prams : start_x
         �`��J�n�ʒu��x���W
@prams : start_y
         �`��J�n�ʒu��y���W
@prams : titleLabel
         �Z���N�g�{�b�N�X�̏�ɕ\�������^�C�g��
@prams : itemName
         �I�΂��鍀��
         char *itemName[] = { "1st", "2nd", "3rd" , NULL };
         �̂悤�ȕϐ�(�Ō��NULL)�̃|�C���^���킽��
@prams : selectKey
         ����{�^���̃{�^���t���O
@prams : type
         == 0 �m�[�}��
         == 1 HOME�{�^���őI�����u�~�߂�v�����o����Z���N�g�{�b�N�X�ɂȂ�
@returns :
            >= 0  �I�΂ꂽ���ڂ�1�ԖڂȂ�0,2�ԖڂȂ�1,...�Ƃ����l
            <  0  @params : type ��1�̂Ƃ��u�~�߂�v���I�����ꂽ��

-----------------------------------------------*/
int pprefsMakeSelectBox( int start_x, int start_y,char *titleLabel, char *itemName[] , u32 selectKey, int type);
void makeWindow(int sx, int sy, int ex, int ey, u32 fgcolor ,u32 bgcolor);
void makeWindowWithGettingButton(int sx, int sy, int ex, int ey, u32 fgcolor ,u32 bgcolor, SceCtrlData *pad);
void makeWindowQuick(int sx, int sy, int ex, int ey, u32 fgcolor ,u32 bgcolor);

#endif
