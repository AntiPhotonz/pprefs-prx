// from libmenu


#ifndef MEMORY_H
#define MEMORY_H


/*=========================================================
	�}�N��
=========================================================*/
#define MEMORY_PAGE_SIZE 256

/* �ǂ�������q�؂����A�������A���C���𒲐�����}�N�� */
#define MEMORY_ALIGN_ADDR( align, addr ) ( ( (uintptr_t)( addr ) + ( align ) - 1 ) & ( ~( ( align ) - 1 ) ) )

/*=========================================================
	���[�J���}�N��
=========================================================*/
#define MEMORY_POWER_OF_TWO( x ) ( ! ( ( x ) & ( ( x ) - 1 ) ) )

typedef struct
{
	SceUID  blockId;
	SceSize size;
} memory_header;


/*=========================================================
	�^�錾
=========================================================*/
typedef enum {
	MEMORY_KERN_HI = 1,
	MEMORY_USER,
	MEMORY_KERN_HI_MIRROR,
	MEMORY_KERN_LO,
	MEMORY_VOLATILE,
	MEMORY_USER_MIRROR
} MemoryPartition;

void *memoryAllocEx( const char *name, MemoryPartition partition, unsigned int align, SceSize size, int type, void *addr );


void *malloc( size_t size );

void free( void *memblock );

#endif


