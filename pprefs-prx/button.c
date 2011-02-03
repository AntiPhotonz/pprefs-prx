
#include "button.h"
#include "nidresolve.h"

static SceCtrlData data;

void waitButtonUp(void)
{
  do{
    sceCtrlPeekBufferPositive( &data, 1 );
  }while((data.Buttons & CHEACK_KEY_2) != 0);
}

void waitAnyButtonDown(unsigned int key)
{
	while(1){
		get_button(&data);
		if( data.Buttons & key ) break;
	}
}

void waitButtonDown(unsigned int key)
{
	while(1){
		get_button(&data);
		if((data.Buttons & key) == key) break;
	}
}


void waitButtonUpEx(unsigned int exception_key)
{
  do{
    sceCtrlPeekBufferPositive( &data, 1 );
  }while((data.Buttons & (CHEACK_KEY_2 & ~exception_key)) != 0);
}

bool isButtonDown(unsigned int key)
{
	get_button(&data);
	if((data.Buttons & key) == key) return true;
	return false;
}









void get_button(SceCtrlData *data)
{
  sceCtrlPeekBufferPositive( data, 1 );
  data->Buttons &= CHEACK_KEY_2;
}






void wait_button_up_multithread(SceCtrlData *data)
{
	while((data->Buttons & CHEACK_KEY_2) != 0)
	{
		sceCtrlPeekBufferPositive( data, 1 );
		sceKernelDelayThread( 50000 );
	}
}



void wait_button_up(SceCtrlData *data)
{
  while((data->Buttons & CHEACK_KEY_2) != 0)
  {
    sceCtrlPeekBufferPositive( data, 1 );
  }
}

void wait_button_down(SceCtrlData *data,unsigned int key)
{
	while(1){
		get_button(data);
		if((data->Buttons & key) == key) break;
	}
}


void wait_any_button_down(SceCtrlData *data,unsigned int key)
{
	while(1){
		get_button(data);
		if( data->Buttons & key ) break;
	}
}

void wait_button_up_ex(SceCtrlData *data,unsigned int exception_key)
{
  while((data->Buttons & (CHEACK_KEY_2 & ~exception_key)) != 0)
  {
    sceCtrlPeekBufferPositive( data, 1 );
  }
}

bool is_button_down(SceCtrlData *data,unsigned int key)
{
	get_button(data);
	if((data->Buttons & key) == key) return true;
	return false;
}

//made by plum
//thank you plum
// �֐�
int Count_Buttons(u32 buttons, int count)
{
	SceCtrlData pad;
	clock_t time;

	// �w�肷��{�^�����Z�b�g
	pad.Buttons = buttons;

	// ���݂̎��� + �w�肵������
	time = sceKernelLibcClock() + count;

	// �{�^���������܂Ń��[�v
	while((pad.Buttons & buttons) == buttons)
	{
		// �f�B���C
		sceKernelDelayThread(50000);

		// �p�b�h�����擾����
//		sceCtrlReadBufferPositive(&pad, 1);
		sceCtrlPeekBufferPositive(&pad, 1);
		// ���݂̎��Ԃ��w�肵�����Ԃ��߂�����
		if(sceKernelLibcClock() > time)
			return 1;
	}

	return 0;
}
