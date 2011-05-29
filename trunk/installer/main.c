#include <pspsdk.h>
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <pspsuspend.h>
#include <psppower.h>
#include <pspreg.h>
#include <psprtc.h>
#include <psputils.h>
#include <pspgu.h>
#include <pspgum.h>
#include <psputility_sysparam.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>

#include <vlf.h>
#include "utf8text.h"

PSP_MODULE_INFO("pprefs_installer", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(0);



int languageNumber = 0;
char rootPath[16];
VlfPicture splashscreen;

int flagToGoBackTop = 0;

//thanks for takka
int read_line_file(SceUID fp, char* line, int num)
{
  char buff[num];
  char* end;
  int len;
  int tmp;

  tmp = 0;
  len = sceIoRead(fp, buff, num);
  // �G���[�̏ꍇ / on error
  if(len == 0)
    return -1;

  end = strchr(buff, '\n');

  // \n��������Ȃ��ꍇ / not found \n
  if(end == NULL)
  {
    buff[num - 1] = '\0';
    strcpy(line, buff);
    return len;
  }

  end[0] = '\0';
  if((end != buff) && (end[-1] == '\r'))
  {
    end[-1] = '\0';
    tmp = -1;
  }

  strcpy(line, buff);
  sceIoLseek(fp, - len + (end - buff) + 1, SEEK_CUR);
  return end - buff + tmp;
}


int copyFile(const char *src, const char *dst)
{
	SceUID fd = -1, fdw = -1;
	int readSize;
	char buf[1024 * 10];

	fd = sceIoOpen(src, PSP_O_RDONLY, 0777);
	if (fd < 0){
		goto error;
	}

	fdw = sceIoOpen(dst, PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777);

	if (fdw < 0) {
		goto error;
	}


	while(1){
		readSize = sceIoRead(fd, buf, sizeof(buf));
		if( ! (readSize > 0) ) break;
		if( sceIoWrite(fdw, buf, readSize) != readSize ){
			goto error;
		}
	}


	sceIoClose(fd);
	sceIoClose(fdw);

	return 0;

error:
	if( fd > 0 ) sceIoClose(fd);
	if( fdw > 0 ) sceIoClose(fdw);

	return -1;
}

//thanks for plum
//int Check_EOF(SceUID fd)
int isEOF(SceUID fd)
{
	char c;

	if(sceIoRead(fd, &c, 1) == 1)
	{
		sceIoLseek(fd, -1, PSP_SEEK_CUR);
		return 0;
	}

	return 1;
}

#define LEN_PER_LINE 256

int install(int sel){
	
	SceUID fd, fdw;
	int readSize, ret;
	char line[LEN_PER_LINE];
	char *ptr;
	char pprefsPath[256];
	char pprefsPath_another[256];
	char *vshPath = "ms0:/seplugins/vsh.txt";
	char *vshtmpPath = "ms0:/seplugins/vsh.txt.pprefstmp";
	

	fdw = sceIoOpen(vshtmpPath, PSP_O_WRONLY|PSP_O_CREAT|PSP_O_APPEND, 0777);
	if( fdw < 0 ){
		return -1;
	}

	fd = sceIoOpen(vshPath, PSP_O_RDONLY, 0777);
	
	strcpy(pprefsPath, rootPath);
	strcat(pprefsPath, (sel == 1 || sel == 3)?"seplugins/pprefs_lite.prx":"seplugins/pprefs.prx");

	strcpy(pprefsPath_another, rootPath);
	strcat(pprefsPath_another, (sel == 1 || sel == 3)?"seplugins/pprefs.prx":"seplugins/pprefs_lite.prx");

	int flag = 0;
	
	if( fd >= 0 ){
		while( ! isEOF(fd) ){
			readSize = read_line_file(fd, line, LEN_PER_LINE - 1);
			if( (ptr = strchr(line,' ')) != NULL ){
				*ptr = '\0';
				if( strcasecmp(line, pprefsPath) == 0 ){
					flag = 1;
					strcat(line, " 1");
				}else if( strcasecmp(line, pprefsPath_another) == 0 ){
					strcat(line, " 0");
				}else{
					*ptr = ' ';
				}
			}
			strcat(line, "\n");
			sceIoWrite(fdw, line, strlen(line));
		}
		sceIoClose(fd);
	}
	
	if( ! flag ){
		strcpy(line, pprefsPath);
		strcat(line, " 1\n");
		sceIoWrite(fdw, line, strlen(line));
	}
	
	
	sceIoClose(fdw);

	sceIoRemove(vshPath);
	sceIoRename(vshtmpPath, vshPath);
	
	char *srcPath = (sel == 0)?"japanese/pprefs.prx":(sel == 1)?"japanese/pprefs_lite.prx":(sel == 2)?"english/pprefs.prx":"english/pprefs_lite.prx";

	ret = copyFile(srcPath, pprefsPath);


	return ret;

}

int menu_sel(int sel)
{
	char *dialogMessage[] = {DONE_JPN, "Done"};
	char *dialogMessageFailed[] = {FAILED_JPN, "Failed"};
	VlfShadowedPicture waitIcon;
	int ret;
	
	switch (sel)
	{
		case 0:
		case 1:
		case 2:
		case 3:
			
			waitIcon = vlfGuiAddWaitIcon();
			ret = install(sel);
			vlfGuiRemoveShadowedPicture(waitIcon);
			vlfGuiMessageDialog(ret < 0?dialogMessageFailed[languageNumber]:dialogMessage[languageNumber], VLF_MD_TYPE_NORMAL | VLF_MD_BUTTONS_NONE);
//			flagToGoBackTop = 1;
			
//		return VLF_EV_RET_REMOVE_HANDLERS | VLF_EV_RET_REMOVE_OBJECTS;
		return VLF_EV_RET_NOTHING;
		
		case 4:
			sceKernelExitGame();
			return VLF_EV_RET_NOTHING;
		break;
	}
	
	return VLF_EV_RET_NOTHING;
}

void getRootPath(char *dst,char *src)
{
	int i;
	for( i = 0; src[i] != '\0'; i++ ){
		dst[i] = src[i];
		if( dst[i] == '/' ){
			dst[i+1] = '\0';
			return;
		}
	}
	return;
}

void sleep_(clock_t sleepTime)
{
	clock_t time = sceKernelLibcClock();
	
	while( (sceKernelLibcClock()- time) < sleepTime ) vlfGuiDrawFrame();
}

int app_main(int argc, char *argv[])
{
	char *mainmenuItems[][5] = {
		{
			"pprefs(���{���)�C���X�g�[��",
			"pprefs lite(���{���)�C���X�g�[��",
			"pprefs(�p���)�C���X�g�[��",
			"pprefs lite(�p���)�C���X�g�[��",
			"�I��"
		},{
			"Install pprefs(Japanese ver.)",
			"Install pprefs lite(Japanese ver.)",
			"Install pprefs(English ver.)",
			"Install pprefs lite(English ver.)",
			"Exit"
		}
	};
	
	//init
	languageNumber = vlfGuiGetLanguage();
	if( languageNumber > 0 ) languageNumber = 1;
	getRootPath(rootPath, argv[0]);
	vlfGuiSystemSetup(1, 1, 1);
	
	
	//splashscreen
	splashscreen = vlfGuiAddPictureFile("splashscreen.png", 0, 0);
	

	if( splashscreen ){
		sleep_(1 * 1000 * 1000);
		vlfGuiSetPictureFade(splashscreen,VLF_FADE_MODE_OUT, VLF_FADE_SPEED_FAST, 0);
	}
	
	
	while(1){
		flagToGoBackTop = 0;
		vlfGuiCentralMenu(5, mainmenuItems[languageNumber], 0, menu_sel, 0, 0);
		
		while(!flagToGoBackTop)
		{
			vlfGuiDrawFrame();
		}
	}
	
	return 0;
}
