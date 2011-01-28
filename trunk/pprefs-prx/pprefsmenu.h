
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
libmClearBuffers(); \
libmPrint(10,10,FG_COLOR,BG_COLOR,"pprefs Ver. 1.091   by hiroi01"); \
libmPrint(440,10,FG_COLOR,BG_COLOR,modelName[deviceModel]);
extern char pprefsPrintBuf[128];
#define libmPrintf(x,y,fg,bg,format, ... ) libmPrintfXY(x,y,fg,bg,pprefsPrintBuf,COMMON_BUF_LEN,format, ##__VA_ARGS__)
#define libmPrint libmPrintXY
#define fillLine(sy,color) libmFillRect( 0 , sy , 480 , sy + LIBM_CHAR_HEIGHT ,color);

int pprefsMakeSelectBox( int start_x, int start_y,char *titleLabel, char *itemName[] , u32 selectKey, int type);
void makeWindow(int sx, int sy, int ex, int ey, u32 fgcolor ,u32 bgcolor);
void makeWindowWithGettingButton(int sx, int sy, int ex, int ey, u32 fgcolor ,u32 bgcolor, SceCtrlData *pad);


#endif
