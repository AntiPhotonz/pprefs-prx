// from libmenu sample
// thank you maxem

#include <pspkernel.h>
#include <string.h>
#include <math.h>

#include "memory.h"
#include "nidresolve.h"


void *memoryAllocEx( const char *name, MemoryPartition partition, unsigned int align, SceSize size, int type, void *addr )
{
	/* 0�o�C�g�m�ۂ��悤�Ƃ����ꍇ�́A�ŏ��l�Ŋm�� */
	if( ! size ) size = 1;

	memory_header header;
	void *memblock;
	SceSize real_size = MEMORY_PAGE_SIZE * (unsigned int)ceil( (double)size / (double)MEMORY_PAGE_SIZE );
	//memory_real_size( size ); /* MEMORY_PAGE_SIZE��؂�̎��ۂɊm�ۂ��ꂽ�l�ɕ␳ */
	
	header.blockId	= sceKernelAllocPartitionMemory( partition, name, type, sizeof(memory_header) + real_size + align, addr );
	header.size		= real_size; 	
	
	if( header.blockId < 0 ) return NULL;
	
	//Info���v���X�����A�h���X��Ԃ�
	memblock = (void *)( (uintptr_t)(sceKernelGetBlockHeadAddr( header.blockId )) + sizeof(memory_header) );

	if( align )
	{
		if( ! MEMORY_POWER_OF_TWO( align ) )
		{
			sceKernelFreePartitionMemory( header.blockId );
			return NULL;
		}

		memblock = (void *)MEMORY_ALIGN_ADDR( align, memblock );
	}
	
	memcpy( (void *)( (uintptr_t)memblock - sizeof(memory_header) ), (void *)&header, sizeof(memory_header) );
	
	
	return memblock;
}


#ifdef USE_KERNEL_LIBRARY
void *malloc( size_t size )
#else
void *memoryAlloc( size_t size )
#endif
{
	return memoryAllocEx( "ms_malloc", MEMORY_USER, 0, size, PSP_SMEM_Low, NULL );
}

#ifdef USE_KERNEL_LIBRARY
void *memalign(size_t boundary, size_t size)
#else
void *memoryAlign(size_t boundary, size_t size)
#endif
{
	return memoryAllocEx( "ms_memalign", MEMORY_USER, boundary, size, PSP_SMEM_Low, NULL );
}

#ifdef USE_KERNEL_LIBRARY
void free( void *memblock )
#else
void memoryFree( void *memblock )
#endif
{
	if( ! memblock ) return;
	 memory_header *header = (memory_header*)( (uintptr_t)memblock - sizeof(memory_header) );
	
	//return 
	sceKernelFreePartitionMemory( header->blockId );
}



