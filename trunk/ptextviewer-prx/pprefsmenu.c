#include "pprefsmenu.h"
#include "button.h"


char pprefsPrintBuf[128];

void pprefsSleep(clock_t sleepTime)
{
	clock_t time = sceKernelLibcClock();
	
	while( (sceKernelLibcClock()- time) < sleepTime );
}
//�ɂ�[���Ăł鑋�����
void makeWindow(int sx, int sy, int ex, int ey, u32 fgcolor ,u32 bgcolor)
{
	int nowx = sx,nowy = sy;
	while(1){
		nowx += 8;
		nowy += 8;
		if( nowx > ex ) nowx = ex;
		if( nowy > ey ) nowy = ey;
		libmFillRect(sx , sy , nowx , nowy , bgcolor );
		libmFrame(sx , sy , nowx ,nowy , fgcolor );
		if( nowx == ex && nowy == ey ) break;
		pprefsSleep(8 * 1000);
	}
	
}

//�ɂ�[���Ă��Ă���Œ��ɂ��{�^����get����
void makeWindowWithGettingButton(int sx, int sy, int ex, int ey, u32 fgcolor ,u32 bgcolor, SceCtrlData *pad)
{
	int nowx = sx,nowy = sy;
	while(1){
		get_button(pad);
		nowx += 8;
		nowy += 8;
		if( nowx > ex ) nowx = ex;
		if( nowy > ey ) nowy = ey;
		libmFillRect(sx , sy , nowx , nowy , bgcolor );
		libmFrame(sx , sy , nowx ,nowy , fgcolor );
		if( nowx == ex && nowy == ey ) break;
		pprefsSleep(8 * 1000);
	}
	
}


