#ifdef LNGENG
#define PB_SYM_PSP_UP			"\x80"
#define PB_SYM_PSP_RIGHT		"\x81"
#define PB_SYM_PSP_DOWN			"\x82"
#define PB_SYM_PSP_LEFT			"\x83"
#define PB_SYM_PSP_TRIANGLE		"\x84"
#define PB_SYM_PSP_CIRCLE		"\x85"
#define PB_SYM_PSP_CROSS		"\x86"
#define PB_SYM_PSP_SQUARE		"\x87"
#define PB_SYM_PSP_NOTE			"\x88"
#else
#define PB_SYM_PSP_UP			"��"
#define PB_SYM_PSP_RIGHT		"��"
#define PB_SYM_PSP_DOWN			"��"
#define PB_SYM_PSP_LEFT			"��"
#define PB_SYM_PSP_TRIANGLE		"��"
#define PB_SYM_PSP_CIRCLE		"��"
#define PB_SYM_PSP_CROSS		"�~"
#define PB_SYM_PSP_SQUARE		"��"
#define PB_SYM_PSP_NOTE			"��"

#define PPREFSMSG_BOOTMESSAGE " pprefs �N����������! / �N���{�^��:"
#define PPREFSMSG_ADD_TOP " <<�ǋL>> : �ǋL�������v���O�C����I�����Ă������� "
#define PPREFSMSG_ADD_HOWTOUSE " %s:�I�� HOME:��߂� L:�t�H���_�K�w��� R:�t�H���_�J�� "
#define PPREFSMSG_ADD_HOWTOUSE_2 " %s:�I�� HOME:��߂� L:�t�H���_�K�w��� R:�t�H���_�J�� START:���݈ʒu�̃t�H���_��I�� "
#define PPREFSMSG_ADD_HOWTOUSE_3 " HOME:��߂� L:�t�H���_�K�w��� R/%s:�t�H���_�J�� START:���݈ʒu�̃t�H���_��I��"
#define PPREFSMSG_SUBMENU_LIST "�ǋL","�폜","pergame�ҏW","�ݒ�","COPY ME",NULL
#define PPREFSMSG_SUBMENU_LIST_GO "�ǋL","�폜","pergame�ҏW","�ݒ�",NULL
#define PPREFSMSG_SUBMENU_LIST_GO_HITOBASHIRA "�ǋL","�폜","pergame�ҏW","�ݒ�","���f�Q�[���t�@�C���M��",NULL
#define PPREFSMSG_SUBMENU_HOTOUSE " %s:�I�� %s:�߂� "
#define PPREFSMSG_SUBMENU_TITLE "���j���["
#define PPREFSMSG_COPYME_ERROR "�G���[���������܂���"
#define PPREFSMSG_COPYME_INSERTERROR "pprefs�������Ă���MS�����Ă�������"
#define PPREFSMSG_MAINMENU_HOTOUSE " %s:�I�� ��:���j���[ ��+��/��:���ёւ� L+R:txt�Ǐ���ύX"
#define PPREFSMSG_MAINMENU_HOTOUSE_2 " SELECT:�ҏW�j��&�����[�h HOME:�ۑ�&�I�� START:�ۑ�&VSH�ċN��"
#define PPREFSMSG_MAINMENU_REPUSHSTART "������xSTART��������\nRESTART VSH"
#define PPREFSMSG_MAINMENU_RELOAD " �ҏW��j�����āA�����[�h���Ă���낵���ł���? "
#define PPREFSMSG_YESORNO "%s:�͂� %s:������"
#define PPREFSMSG_YESORNO_LIST "�͂�","������",NULL
#define PPREFSMSG_COPYME_FIRSTCONFIRM "���̑�������s����O�Ɍ��݂̕ҏW��ۑ����Ă�������"
#define PPREFSMSG_COPYME_FIRSTCONFIRMHOTOUSE "START:�ۑ����đ����� SELECT:�ҏW�j����������\nHOME:��߂�"
#define PPREFSMSG_COPYME_SELECTLIST "�ۑ����đ�����","�ҏW�j����������","��߂�",NULL
#define PPREFSMSG_COPYME_INSERT2NDMS "2���ڂ̃������[�X�e�B�b�N��\n����Ă�������"
#define PPREFSMSG_COPYME_INSERT2NDMSHOWTOUSE "%s:���ꂽ HOME:�R�s�[��߂�"
#define PPREFSMSG_COPYME_DONETOCOPY "�R�s�[���������܂���"
#define PPREFSMSG_COPYME_FAILTOCOPY "�������R�s�[�ł��܂���ł���"
#define PPREFSMSG_FAILTOWRITE "%s�̏������݂Ɏ��s���܂���"
#define PPREFSMSG_FAILTOWRITEHOWTOUSE "%s:���g���C %s:�X�L�b�v "
#define PPREFSMSG_EDITPERGAME_SELECTPRX "�v���O�C����I�����Ă�"
#define PPREFSMSG_EDITPERGAME_SELECTGAME "�Q�[����I�����Ă�"
#define PPREFSMSG_EDITPERGAME_HOTOUSE "HOME:��߂� START:�ۑ� %s����:�s�폜 L�g���K:�ŏ�� R�g���K:�ŉ���"
#define PPREFSMSG_EDITPERGAME_HOTOUSE_2 "��:�R�����g�A�E�g(#)�ؑ� ��:�u���b�N���X�g(!)�ؑ� ��+��/��:���ёւ�"
#define PPREFSMSG_EDITPERGAME_TOP " pergame�ҏW "
#define PPREFSMSG_SELECTBOX_HOTOUSE " %s:�I�� "
#define PPREFSMSG_SELECTBOX_HOTOUSE_2 " %s:�I�� HOME:��߂� "
#define PPREFSMSG_HITOBASHIRA "�l��"
#define PPREFSMSG_SELECTBASEPATH "vsh.txt,game.txt,pops.txt������t�H���_���w�肵�Ă�������"
#define PPREFSMSG_PAUSEGAMETEST "�M�������RESTART VSH���ĉ�����"
#define PPREFSMSG_DETECTKEY_1 "�L�[���o �c�� �b"
#define PPREFSMSG_DETECTKEY_2 "�L�[���o �c��%d�b"
#define PPREFSMSG_CONFIGMENU_WHATISTHIS \
	"pprefs���N��������{�^���̎w��(�f�t�H���g��HOME)", \
	"�{�̂��N�������Ƃ��ɍ����ɕ\\�������upprefs�N����������!�`�v��\\�����邩?\ntrue���\\�� false����\\��\(�f�t�H���g��true)", \
	"�~/���{�^���̖��������ւ���\ntrue��������/�~�L�����Z�� false���~����/���L�����Z��(�f�t�H���g��false)", \
	"�g�b�v���j���[�ɂ�VSH�ċN������̂�START����x��������x������\ntrue����x���� false����x����(�f�t�H���g��false)", \
	"���̃v���O�C�����e�L�X�g�������o���Ƃ��Ɏg�����s�R�[�h(�f�t�H���g��CR+LF)", \
	"vsh.txt,game.txt,pops.txt������t�H���_�̃p�X", \
	"�ʏ�̕����F", \
	"�w�i�̐F", \
	"�I�����ꂽ�����F", \
	"���ɕ\\�����������̕����F",
#define PPREFSMSG_CONFIGMENU_TITLE " �ݒ� "
#define PPREFSMSG_CONFIGMENU_MENU_1 "��L�̐ݒ�ŕۑ�����"
#define PPREFSMSG_CONFIGMENU_MENU_2 "�f�t�H���g�l�ɂ���"
#define PPREFSMSG_CONFIGMENU_MENU_3 "��߂�"
#define PPREFSMSG_CONFIGMENU_HOWTOUSE " %s:�I�� HOME:��߂� "
#define PPREFSMSG_HITOBASHIRA_2 "�l��2"
#define PPREFSMSG_CONFIG_BASEPATH_LIST "�w�肷��","�w�肵�Ȃ�",NULL
#define PPREFSMSG_CONFIG_BASEPATH_TITLE "BasePath"
#endif
