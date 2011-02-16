#ifdef PPREFS_LITE
#define PB_SYM_PSP_UP			"\x80"
#define PB_SYM_PSP_RIGHT		"\x81"
#define PB_SYM_PSP_DOWN			"\x82"
#define PB_SYM_PSP_LEFT			"\x83"
#define PB_SYM_PSP_TRIANGLE		"\x84"
#define PB_SYM_PSP_CIRCLE		"\x85"
#define PB_SYM_PSP_CROSS		"\x86"
#define PB_SYM_PSP_SQUARE		"\x87"
#define PB_SYM_PSP_NOTE			"\x88"



#define PPREFSMSG_SUBMENU_TITLE " MENU "
#define PPREFSMSG_ADD_TOP " select plugin you want to add "
#define PPREFSMSG_COPYME_ERROR "error!"
#define PPREFSMSG_COPYME_INSERTERROR "insert MS that has 'pprefs_lite'"
#define PPREFSMSG_HITOBASHIRA_2 "��2"
#define PPREFSMSG_HITOBASHIRA "��"
#define PPREFSMSG_MAINMENU_HOTOUSE " %s:Sel. \x84:Menu \x87+\x80/\x82:Move L+R:ChangeDir"
#define PPREFSMSG_MAINMENU_HOTOUSE_2 "SELECT:re-read(notSaving) HOME:Save&Quit START:Save&RESTART VSH"
#define PPREFSMSG_MAINMENU_REPUSHSTART "re-press START\n,and RESTART VSH"
#define PPREFSMSG_MAINMENU_RELOAD " re-read(not saving)  Really? "
#define PPREFSMSG_YESORNO "%s:YES %s:NO"
#define PPREFSMSG_YESORNO_LIST "YES","NO",NULL


#define PPREFSMSG_COPYME_FIRSTCONFIRM "Save your edit?"
#define PPREFSMSG_COPYME_FIRSTCONFIRMHOTOUSE "START:Save & Go to next SELECT:Not Save & Go to next\nHOME:Quit"
#define PPREFSMSG_COPYME_SELECTLIST "Save & Go to next","Not Save & Go to next","Quit",NULL
#define PPREFSMSG_COPYME_INSERT2NDMS "Insert another MS"
#define PPREFSMSG_COPYME_INSERT2NDMSHOWTOUSE "%s:Ok,Done HOME:Quit"
#define PPREFSMSG_COPYME_DONETOCOPY "Done!"
#define PPREFSMSG_COPYME_FAILTOCOPY "Fail to copy"
#define PPREFSMSG_FAILTOWRITE "Fail to write %s"
#define PPREFSMSG_FAILTOWRITEHOWTOUSE "%s:Retry %s:Skip "
#define PPREFSMSG_SELECTBOX_HOTOUSE " %s:Sel. "
#define PPREFSMSG_SELECTBOX_HOTOUSE_2 " %s:Sel. HOME:Quit "
#define PPREFSMSG_CONFIGMENU_WHATISTHIS \
	"Hot key to start this plugin", \
	"Swap X and O", \
	"to RESTART VSH on start menu ... true -> one press START false -> two press START", \
	"Line Feed Code", \
	"Folder that has vsh.txt , game.txt , pops.txt", \
	"Foreground color", \
	"Background color", \
	"Selected color", \
	"Color of explanation on bottom of screen", \

#define PPREFSMSG_SELECTBASEPATH "Where is the folder that has vsh.txt,game.txt,pops.txt?"

#define PPREFSMSG_DETECTKEY_1 "Detect Key   "
#define PPREFSMSG_DETECTKEY_2 "Detect Key %d"
#define PPREFSMSG_CONFIGMENU_TITLE " Config "
#define PPREFSMSG_CONFIGMENU_MENU_1 "Save this config"
#define PPREFSMSG_CONFIGMENU_MENU_2 "Set default"
#define PPREFSMSG_CONFIGMENU_MENU_3 "Quit"
#define PPREFSMSG_CONFIGMENU_HOWTOUSE " %s:Sel. HOME:Quit "
#define PPREFSMSG_CONFIG_BASEPATH_TITLE "BasePath"
#define PPREFSMSG_CONFIG_BASEPATH_LIST "Set","not Set",NULL

#define PPREFSMSG_ADD_HOWTOUSE " %s:Sel. HOME:Quit L:UpDir R:OpenDir "
#define PPREFSMSG_ADD_HOWTOUSE_2 " %s:Sel. HOME:Quit L:UpDir R:OpenDir START:Select current dir "
#define PPREFSMSG_ADD_HOWTOUSE_3 " HOME:Quit L:UpDir R/%s:OpenDir START:Select current dir"

#else ///////////////////////////////////////////////////////////////////////////////////


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
#define PPREFSMSG_SUBMENU_LIST "�ǋL","�폜","pergame�ҏW","SORT GAME��","�ݒ�","COPY ME",NULL
#define PPREFSMSG_SUBMENU_LIST_GO "�ǋL","�폜","pergame�ҏW","SORT GAME��","�ݒ�",NULL
#define PPREFSMSG_SUBMENU_LIST_GO_HITOBASHIRA "�ǋL","�폜","pergame�ҏW","SORT GAME��","�ݒ�","���f�Q�[���t�@�C���M��",NULL
#define PPREFSMSG_SUBMENU_HOTOUSE " %s:�I�� %s:�߂� "
#define PPREFSMSG_SUBMENU_TITLE "���j���["
#define PPREFSMSG_COPYME_ERROR "�G���[���������܂���"
#define PPREFSMSG_COPYME_INSERTERROR "pprefs�������Ă���MS�����Ă�������"
#define PPREFSMSG_MAINMENU_HOTOUSE " %s:�I�� ��:���j���[ ��+��/��:���ёւ� L+R:txt�Ǐ���ύX"
#define PPREFSMSG_MAINMENU_HOTOUSE_2 " SELECT:�ҏW�j��&�����[�h HOME:�ۑ�&�I�� START:�ۑ�&VSH�ċN��"
#define PPREFSMSG_MAINMENU_REPUSHSTART "������xSTART��������\nRESTART VSH"
#define PPREFSMSG_MAINMENU_RELOAD " �ҏW��j�����ă����[�h? "
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
	"pprefs���N��������{�^���̎w��", \
	"�{�̂��N�������Ƃ��ɍ����ɕ\\�������upprefs�N����������!�`�v���E�E�E\ntrue���\\�� false����\\��", \
	"�~/���{�^���̖��������ւ���\ntrue��������/�~�L�����Z�� false���~����/���L�����Z��(�f�t�H���g��false)", \
	"�g�b�v���j���[�ɂ�VSH�ċN������̂�START���E�E�E\ntrue����x���� false����x����", \
	"���̃v���O�C�����e�L�X�g�������o���Ƃ��Ɏg�����s�R�[�h", \
	"vsh.txt,game.txt,pops.txt������t�H���_�̃p�X", \
	"�ʏ�̕����F", \
	"�w�i�̐F", \
	"�I�����ꂽ�����F", \
	"���ɕ\\�����������̕����F", \
	"USB�ڑ��@�\\���� true���L�� false������ �����̋@�\\��5.XX��p\n�e�X�g�����Ȃ̂ł�������肪���� �L��������؂�ւ�����{��(VSH)���ċN�����K�v", \
	"USB�ڑ��{�^��(USB�ؒf�{�^���Ɠ����ł�OK)", \
	"USB�ؒf�{�^��(USB�ڑ��{�^���Ɠ����ł�OK)", \
	"SORT GAME�Ɋւ���ݒ�", \


#define PPREFSMSG_CONFIGMENU_TITLE " �ݒ� "
#define PPREFSMSG_CONFIGMENU_MENU_1 "��L�̐ݒ�ŕۑ�����"
#define PPREFSMSG_CONFIGMENU_MENU_2 "�f�t�H���g�l�ɂ���"
#define PPREFSMSG_CONFIGMENU_MENU_3 "��߂�"
#define PPREFSMSG_CONFIGMENU_HOWTOUSE " %s:�I�� HOME:��߂� "
#define PPREFSMSG_HITOBASHIRA_2 "�l��2"
#define PPREFSMSG_CONFIG_BASEPATH_LIST "�w�肷��","�w�肵�Ȃ�",NULL
#define PPREFSMSG_CONFIG_BASEPATH_TITLE "BasePath"
#define PPREFSMSG_SORTGAME_SAVE " �ۑ����܂���? "
#define PPREFSMSG_SORTGAME_HOWTOUSE "��+��/��:���ёւ� HOME:�I�� START:�ۑ� SELECT:�ҏW�j��&�����[�h %s/R:�J�� L:�߂�"
#define PPREFSMSG_SORTGAME_TITLE "SORT GAME�� ���ёւ�����RESTART VSH����Ȃǂ��ăL���b�V�����N���A���Ă�"
#define PPREFSMSG_CONFIG_SORTTYPE_ISOCSO "*.iso/*.cso�t�@�C�����܂߂�?"
#define PPREFSMSG_CONFIG_SORTTYPE_GAME150 "GAME150�t�H���_���܂߂�?"
#define PPREFSMSG_CONFIG_SORTTYPE_GAME500 "GAME500�t�H���_���܂߂�?"
#define PPREFSMSG_CONFIG_SORTTYPE_TYPE "�ǂ�plugin���g���Ă��܂���?"
#define PPREFSMSG_CONFIG_SORTTYPE_TYPE_LIST "�g���ĂȂ�","gamecategories","gamecategories light",NULL
#define PPREFSMSG_SORTGAME_PLEASECONFIG "\"�ݒ�\"��SortType�̐ݒ���s���Ă�������"


#endif



