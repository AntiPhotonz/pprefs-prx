/*
 * file.c
 *
 *  Created on: 2009/12/26
 *      Author: takka
 */


 /*
 * iso tool�̃\�[�X���
 *
 * mod by hiroi01
 */


#include <string.h>
#include <stdlib.h>

#ifndef EMU
#include <pspkernel.h>
#include <pspmscm.h>
#endif



#include "main.h"
/*

#include "file.h"
#include "ciso.h"
#include "umd.h"
#include "error.h"
#include "screen.h"
#include "macro.h"
*/

#include "button.h"
#include "libmenu.h"
#include "file.h"

#define FIO_CST_SIZE    0x0004

//--------------------------------------------------------


typedef enum {
  ERR_OPEN          = -1,
  ERR_READ          = -2,
  ERR_WRITE         = -3,
  ERR_SEEK          = -4,
  ERR_CLOSE         = -5,

  ERR_DECRYPT       = -6,
  ERR_NOT_CRYPT     = -7,

  ERR_DEFLATE       = -8,
  ERR_DEFLATE_SIZE  = -9,
  ERR_INFLATE       = -10,

  ERR_INIT          = -11,

  ERR_PRX           = -12,

  ERR_NOT_FOUND     = -13,
  ERR_SIZE_OVER     = -14,

  ERR_CHG_STAT      = -15,

  ERR_NO_UMD        = -16,

  ERR_RENAME        = -17,

  ERR_NO_MEMORY     = -18,

} err_msg_num;

#define YES                 (1)
#define NO                  (0)

#define DONE                (0)
#define CANCEL              (-1)
//--------------------------------------------------------




int compare_dir_int(const void* c1, const void* c2);
int compare_dir_str(const void* c1, const void* c2);
int compare_dir_dir(const void* c1, const void* c2);

/*---------------------------------------------------------------------------
  �t�@�C���T�C�Y�ύX // ���삵�܂���
  const char *path : �p�X
  int length       : �T�C�Y

  return int       : �ύX��̃t�@�C���T�C�Y, �G���[�̏ꍇ��ERR_CHG_STAT��Ԃ�
---------------------------------------------------------------------------*/
/*
int file_truncate(const char *path, int length)
{
    SceIoStat psp_stat;
    int ret;

    psp_stat.st_size = length;
    ret = sceIoChstat(path, &psp_stat, FIO_CST_SIZE);
    if(ret < 0)
      ret = ERR_CHG_STAT;

    return ret;
}
*/


// �\�[�g���̗D�揇��
const char dir_type_sort[] = {
    'c', // TYPE_ISO
    'c', // TYPE_CSO
    'b', // TYPE_DIR
    'a', // TYPE_UMD
    'c', // TYPE_SYS
    'c', // TYPE_PBT
    'a', // TYPE_PRX
    'c', // TYPE_ETC
};

int compare_dir_str(const void* c1, const void* c2)
{
  return strcasecmp(&(((dir_t *)c1)->sort_type), &(((dir_t *)c2)->sort_type));
}

/*---------------------------------------------------------------------------
  �f�B���N�g���ǎ��
  dir_t dir[]      : dir_t�z��̃|�C���^
  const char *path : �p�X

  return int       : �t�@�C����, dir[0].num�ɂ��ۑ������
---------------------------------------------------------------------------*/
int read_dir(dir_t dir[], const char *path, int dir_only)
{
  SceUID dp;
  SceIoDirent entry;
  int num;
  int file_num = 0;
  
  checkMs();
//  int ret  = check_ms();
/*
  if(dir_only == 0)
  {
    strcpy(dir[0].name, "[UMD DRIVE]");
    dir[0].type = TYPE_UMD;
    dir[file_num].sort_type = dir_type_sort[TYPE_UMD];
    file_num++;
  }
*/
  dp = sceIoDopen(path);
  if(dp >= 0)
  {
    memset(&entry, 0, sizeof(entry));

    while((sceIoDread(dp, &entry) > 0))
    {
      num = strlen(entry.d_name);

      strcpy(dir[file_num].name, entry.d_name);
      switch(entry.d_stat.st_mode & FIO_S_IFMT)
      {
        case FIO_S_IFREG:
          if(dir_only == 0)
          {
            if(strncasecmp(&entry.d_name[num - 4], ".iso", 4) == 0)
            {
              dir[file_num].type = TYPE_ISO;
              dir[file_num].sort_type = dir_type_sort[TYPE_ISO];
              file_num++;
            }
            else if(strncasecmp(&entry.d_name[num - 4], ".cso", 4) == 0)
            {
              dir[file_num].type = TYPE_CSO;
              dir[file_num].sort_type = dir_type_sort[TYPE_CSO];
              file_num++;
            }
            else if(strncasecmp(entry.d_name, "PBOOT.PBP", 4) == 0)
            {
              dir[file_num].type = TYPE_PBT;
              dir[file_num].sort_type = dir_type_sort[TYPE_PBT];
              file_num++;
            }
            else if(strncasecmp(&entry.d_name[num - 4], ".prx", 4) == 0)
            {
              dir[file_num].type = TYPE_PRX;
              dir[file_num].sort_type = dir_type_sort[TYPE_PRX];
              file_num++;
            }
            else
            {
              dir[file_num].type = TYPE_ETC;
              dir[file_num].sort_type = dir_type_sort[TYPE_ETC];
              file_num++;
            }
          }
          break;

        case FIO_S_IFDIR:
          if((strcmp(&entry.d_name[0], ".") != 0) && (strcmp(&entry.d_name[0], "..") != 0))
          {
            dir[file_num].type = TYPE_DIR;
            dir[file_num].sort_type = dir_type_sort[TYPE_DIR];
            file_num++;
          }
          break;
      }
    }
    sceIoDclose(dp);
  }

  qsort(dir, file_num, sizeof(dir_t), compare_dir_str);

//  dir[0].num = file_num;

  return file_num;
}

/*---------------------------------------------------------------------------
  �f�B���N�g���ǎ��
  dir_t dir[]      : dir_t�z��̃|�C���^
  const char *path : �p�X

  return int       : �t�@�C����, dir[0].num�ɂ��ۑ������
---------------------------------------------------------------------------*/
/*
int read_dir_2(dir_t dir[], const char *path, int read_dir_flag)
{
  SceUID dp;
  SceIoDirent entry;
  int num;
  int file_num = 0;
  int ret;

  ret = check_ms();

  dp = sceIoDopen(path);
  if(dp >= 0)
  {
    memset(&entry, 0, sizeof(entry));

    while((sceIoDread(dp, &entry) > 0))
    {
      num = strlen(entry.d_name);

      strcpy(dir[file_num].name, entry.d_name);
      switch(entry.d_stat.st_mode & FIO_S_IFMT)
      {
        case FIO_S_IFREG:
          dir[file_num].type = TYPE_ETC;
          dir[file_num].sort_type = dir_type_sort[TYPE_ETC];
          file_num++;
          break;

        case FIO_S_IFDIR:
          if(read_dir_flag == 1)
          {
            if((strcmp(&entry.d_name[0], ".") != 0) && (strcmp(&entry.d_name[0], "..") != 0))
            {
              dir[file_num].type = TYPE_DIR;
              dir[file_num].sort_type = dir_type_sort[TYPE_DIR];
              file_num++;
            }
          }
          break;
      }
    }
    sceIoDclose(dp);
  }

  dir[0].num = file_num;

  // �t�@�C�����Ń\�[�g
//  qsort(&dir[0], file_num - 1, sizeof(dir_t), compare_dir_str);

  return file_num;
}
*/

/*---------------------------------------------------------------------------
  MS�̃��[�h
  void* buf        : �ǎ��o�b�t�@
  const char* path : �p�X
  int pos          : �Ǎ��݊J�n�ꏊ
  int size         : �Ǎ��݃T�C�Y, 0���w�肷��ƑS�Ă�Ǎ���

  return int       : �Ǎ��݃T�C�Y, �G���[�̏ꍇ�� ERR_OPEN/ERR_READ ��Ԃ�
---------------------------------------------------------------------------*/
/*
int ms_read(void* buf, const char* path, int pos, int size)
{
  SceUID fp;
  SceIoStat stat;
  int ret = ERR_OPEN;

  if(size == 0)
  {
    pos = 0;
    sceIoGetstat(path, &stat);
    size = stat.st_size;
  }

  fp = sceIoOpen(path, PSP_O_RDONLY, 0777);
  if(fp > 0)
  {
    sceIoLseek32(fp, pos, PSP_SEEK_SET);
    ret = sceIoRead(fp, buf, size);
    sceIoClose(fp);
    if(ret < 0)
      ret = ERR_READ;
  }
  return ret;
}
*/
/*---------------------------------------------------------------------------
  MS�ւ̃��C�g
  const void* buf  : �����݃o�b�t�@
  const char* path : �p�X
  int pos          : �����݊J�n�ꏊ
  int size         : �����݃T�C�Y

  return int       : �����񂾃T�C�Y, �G���[�̏ꍇ�� ERR_OPEN/ERR_WRITE ��Ԃ�
---------------------------------------------------------------------------*/
/*
int ms_write(const void* buf, const char* path, int pos, int size)
{
  SceUID fp;
  int ret = ERR_OPEN;

  fp = sceIoOpen(path, PSP_O_WRONLY|PSP_O_CREAT, 0777);
  if(fp > 0)
  {
    sceIoLseek32(fp, pos, PSP_SEEK_SET);
    ret = sceIoWrite(fp, buf, size);
    sceIoClose(fp);
    if(ret < 0)
      ret = ERR_WRITE;
  }
  return ret;
}

int ms_write_apend(const void* buf, const char* path, int pos, int size)
{
  SceUID fp;
  int ret = ERR_OPEN;

  fp = sceIoOpen(path, PSP_O_WRONLY|PSP_O_CREAT|PSP_O_APPEND, 0777);
  if(fp > 0)
  {
    sceIoLseek32(fp, pos, PSP_SEEK_SET);
    ret = sceIoWrite(fp, buf, size);
    sceIoClose(fp);
    if(ret < 0)
      ret = ERR_WRITE;
  }
  return ret;
}
*/
/*---------------------------------------------------------------------------
  �t�@�C�����[�h
---------------------------------------------------------------------------*/
/*
int file_read(void* buf, const char* path, file_type type, int pos, int size)
{
  int ret = ERR_OPEN;

  switch(type)
  {
    case TYPE_ISO:
    case TYPE_SYS:
      ret = ms_read(buf, path, pos, size);
      break;

    case TYPE_CSO:
      ret = cso_read(buf, path, pos, size);
      break;

    case TYPE_UMD:
      ret = umd_read(buf, path, pos, size);
      break;

    default:
      break;
  }
  return ret;
}
*/
/*---------------------------------------------------------------------------
  �t�@�C�����C�g
---------------------------------------------------------------------------*/
/*
int file_write(const void* buf, const char* path, file_type type, int pos, int size)
{
  u32 ret = ERR_OPEN;

  switch(type)
  {
    case TYPE_ISO:
      ret = ms_write(buf, path, pos, size);
      break;

    case TYPE_CSO:
      ret = cso_write(buf, path, pos, size, 9);
      break;

    case TYPE_UMD:
      break;

    default:
      break;
  }
  return ret;
}

// FIO_S_IWUSR | FIO_S_IWGRP | FIO_S_IWOTH
int set_file_mode(const char* path, int bits)
{
  SceIoStat stat;
  int ret;

  ret = sceIoGetstat(path, &stat);

  if(ret >= 0)
  {
    stat.st_mode |= (bits);
    ret = sceIoChstat(path, &stat, (FIO_S_IRWXU | FIO_S_IRWXG | FIO_S_IRWXO));
  }
  if(ret < 0)
    ret = ERR_CHG_STAT;

  return ret;
}
*/
/*---------------------------------------------------------------------------
---------------------------------------------------------------------------*/
int up_dir(char *path)
{
  int loop;
  int ret = ERR_OPEN;

  loop = strlen(path) - 2;

  while(path[loop--] != '/')
    ;

  if(path[loop - 1] != ':')
  {
    path[loop + 2] = '\0';
    ret = 0;
  }

  return ret;
}


#if 0
/*---------------------------------------------------------------------------
---------------------------------------------------------------------------*/
/*
int get_file_data_2(int* pos, int* size, int* size_pos, const char* path, file_type type, const char *name)
{
  char buf[50 * SECTOR_SIZE];
  int ptr = 0;
  int len;
  int ret;

  // 22�`63�Z�N�^(42�Z�N�^��)��ǂݍ���
  ret = file_read(buf, path, type, 22 * SECTOR_SIZE, 42 * SECTOR_SIZE);

  if(ret == (42 * SECTOR_SIZE))
  {
    len = strlen(name) - 1;

    while(strncasecmp(&buf[ptr], &name[1], len) != 0)
    {
      while(buf[ptr++] != name[0])
        if(ptr > 42 * SECTOR_SIZE)
          return ERR_NOT_FOUND;
    }

    ptr--;

    // �t�@�C���� - 0x1f �Ƀt�@�C���擪�Z�N�^
    memcpy(pos, &buf[ptr - 0x1f], 4);
    *pos *= SECTOR_SIZE;

    // �t�@�C���� - 0x17 �Ƀt�@�C���T�C�Y
    memcpy(size, &buf[ptr - 0x17], 4);

    // �t�@�C���T�C�Y�̈ʒu
    *size_pos = 22 * 0x800 + ptr - 0x17;

    ret = *pos;
  }

  return ret;
}
*/
#endif

int read_line(char* str,  SceUID fp, int num)
{
  char buf;
  int len = 0;
  int ret;

  do{
    ret = sceIoRead(fp, &buf, 1);
    if(ret == 1)
    {
      if(buf == '\n')
      {
        str[len] = '\0';
        len++;
        break;
      }
      if(buf != '\r')
      {
        str[len] = buf;
        len++;
      }
    }
  }while((ret > 0) && (len < num));

  return len;
}



//from umd dumper
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




int read_line_file_keepn(SceUID fp, char* line, int num)
{
  char buff[num];
  char* end;
  int len;
  int tmp;

  tmp = 1;
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

  //���̏����͐������H
  //buff�̑傫���������Ȃ��悤�ɁA������\0��ǉ�������
  if( &end[1] < &buff[num] ){
    end[1] = '\0';
    /*
    if( (end[0] == '\r') )
    {
      end[0] = '\0';
      tmp = 0;
    }
    */
  }else{
    end[0] = '\0';
    tmp = 0;
  }

  strcpy(line, buff);
  sceIoLseek(fp, - len + (end - buff) + 1, SEEK_CUR);
  return end - buff + tmp;
}



/*
int get_umd_sector(const char* path, file_type type)
{
  int size = 0;
  int ret;

  ret = file_read(&size, path, type, 0x8050, 4); // 0x50����4byte���Z�N�^��
  if(ret < 0)
    size = ret;

  return size;
}

int get_umd_id(char* id, const char* path, file_type type)
{
  int ret;
  // 0x8373����10byte��UMD ID
  ret = file_read(id, path, type, 0x8373, 10);
  if(ret == 10)
    id[10] = '\0';
  else
    strcpy(id, "**********");

  return ret;
}

int get_umd_name(char* name, char* e_name, const char* id, int mode)
{
  static char buf[1024*256]; // 256KB
  static int init = 0;
  char *ptr;
  int ptr2 = 0;
  int ret = 0;

  if((init == 0)||(mode == 1))
  {
    ms_read(buf, "UMD_ID.csv", 0, 0);
    init = 1;
    if(mode == 1)
      return 0;
  }

  ptr = strstr((const char *)buf, id);

  if(ptr != NULL)
  {
    ptr += 11;

    while(*ptr == '\\')
      ptr++;

    while(*ptr != '\\')
    {
      name[ptr2] = *ptr;
      ptr++;
      ptr2++;
    }
    name[ptr2] = '\0';

    while(*ptr == '\\')
      ptr++;

    ptr2 = 0;
    while((*ptr != '\r') && (*ptr != '\n'))
    {
      e_name[ptr2] = *ptr;
      ptr++;
      ptr2++;
    }
    e_name[ptr2] = '\0';

  }
  else
  {
    ret = -1;
    name[0] = '\0';
    e_name[0] = '\0';
  }

  return ret;
}

int get_ms_free()
{
    unsigned int buf[5];
    unsigned int *pbuf = buf;
    int free = 0;
    int ret;

    //    buf[0] = ���v�N���X�^��
    //    buf[1] = �t���[�ȃN���X�^��(�M���M���܂Ŏg�������Ȃ炱����)
    //    buf[2] = �t���[�ȃN���X�^��(buf[3]��buf[4]�Ɗ|����1MB�P�ʂɂȂ�悤�ɂȂ��Ă�)
    //    buf[3] = �Z�N�^������o�C�g��
    //    buf[4] = �N���X�^������Z�N�^��
    ret = sceIoDevctl("ms0:", 0x02425818, &pbuf, sizeof(pbuf), 0, 0);

    if(ret >= 0)
      free = buf[1] * ((buf[3] * buf[4]) / 1024);// �󂫗e�ʎ擾(kb)

    return free;
}

*/

int checkMs(void)
{
	int ret = 0;
	SceUID dp = sceIoDopen("ms0:/");
	if(dp < 0){
		ret = check_ms();
	}else{
		sceIoDclose(dp);
	}
	
	return ret;
}

int check_ms()
{
  SceUID ms;
  int ret = DONE;

  ms = MScmIsMediumInserted();
  if(ms <= 0)
  {
 //   msg_win("", 0, MSG_CLEAR, 0);
 //   msg_win("Memory Stick�����ĉ�����", 1, MSG_WAIT, 0);
 	makeWindow(LIBM_CHAR_WIDTH*9 ,LIBM_CHAR_HEIGHT*9 ,LIBM_CHAR_WIDTH*30 ,LIBM_CHAR_WIDTH*14, FG_COLOR,BG_COLOR );
	libmPrint( LIBM_CHAR_WIDTH*10 ,LIBM_CHAR_HEIGHT*10 , FG_COLOR,BG_COLOR,"Memory Stick�����ĉ�����");
	libmPrint( LIBM_CHAR_WIDTH*10 ,LIBM_CHAR_HEIGHT*12 + 4 , FG_COLOR,BG_COLOR,"HOME:�G�X�P�[�v");

    ms = -1;
    while(ms <= 0)
    {
      if( isButtonDown(PSP_CTRL_HOME) ) return -2;
      sceKernelDelayThread(1000);
      ms = MScmIsMediumInserted();
    }
 //   msg_win("", 0, MSG_CLEAR, 0);
//    msg_win("�}�E���g���ł�", 1, MSG_WAIT, 0);
	libmPrint( LIBM_CHAR_WIDTH*10 ,LIBM_CHAR_HEIGHT*11 + 2 , FG_COLOR,BG_COLOR,"�}�E���g���ł�");
	sceKernelDelayThread(1000000);
    ret = CANCEL;
  }
  return ret;
}

int check_file(const char* path)
{
  SceIoStat stat;

  return sceIoGetstat(path, &stat);
}
