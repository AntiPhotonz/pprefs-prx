#ifndef CISO_H_

#define CISO_H_

#include "file.h"


int get_umd_id(char* id, const char* path, file_type type);


//form ciso.c in iso tool



typedef struct ciso_header
{
    unsigned char magic[4];         /* +00 : 'C','I','S','O'                 */
    unsigned long header_size;      /* +04 : header size (==0x18)            */
    unsigned long long total_bytes; /* +08 : number of original data size    */
    unsigned long block_size;       /* +10 : number of compressed block size */
    unsigned char ver;              /* +14 : version 01                      */
    unsigned char align;            /* +15 : align of index value            */
    unsigned char rsv_06[2];        /* +16 : reserved                        */
}CISO_H;

#define CISO_HEADER_SIZE (0x18)

/*---------------------------------------------------------------------------
  deflate�̉𓀂��s��
    char* o_buff �𓀐�
    int o_size   �𓀐�o�b�t�@�T�C�Y
    char* i_buff ����
    int i_size   ���̓T�C�Y

    �Ԓl �𓀌�̃T�C�Y / �G���[�̏ꍇ�͕���Ԃ�
---------------------------------------------------------------------------*/
int inflate_cso(char* o_buff, int o_size, const char* i_buff, int i_size);

/*---------------------------------------------------------------------------
  CSO����Ǎ���
    char *buf        �Ǎ��݃o�b�t�@
    const char *path �p�X
    int pos          �Ǎ��݈ʒu
    int size         �Ǎ��݃T�C�Y

    �Ԓl ���ۂɓǂݍ��񂾒��� / �G���[�̏ꍇ�͕���Ԃ�
---------------------------------------------------------------------------*/
int cso_read(char *buf, const char *path, int pos, int size);

/*---------------------------------------------------------------------------
  CSO����A���œǍ���
    char *buf �Ǎ��݃o�b�t�@
    SceUID fp �t�@�C���|�C���^
    int pos   �Ǎ��݈ʒu
    int size  �Ǎ��݃T�C�Y

    �Ԓl ���ۂɓǂݍ��񂾒��� / �G���[�̏ꍇ�͕���Ԃ�

    ���O��sceIoOpen / �I�����sceIoClose���K�v
---------------------------------------------------------------------------*/
int cso_read_fp(char *buf, SceUID fp, int pos, int size);

#endif