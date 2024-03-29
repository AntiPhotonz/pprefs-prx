//MacroFireで使われていた font_cg.c を少し微調整した物
//左部分がつぶれて見にくかったので、全文字とも横へ1列ずらしてある

const char font_cg[] = {
	/* 0x00-0x7F */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* NUL */
	0x3c, 0x42, 0xa5, 0x81, 0xa5, 0x99, 0x42, 0x3c, /* SOH */
	0x3c, 0x7e, 0xdb, 0xff, 0xff, 0xdb, 0x66, 0x3c, /* STX */
	0x6c, 0xfe, 0xfe, 0xfe, 0x7c, 0x38, 0x10, 0x00, /* ETX */
	0x10, 0x38, 0x7c, 0xfe, 0x7c, 0x38, 0x10, 0x00, /* EOT */
	0x10, 0x38, 0x54, 0xfe, 0x54, 0x10, 0x38, 0x00, /* ENQ */
	0x10, 0x38, 0x7c, 0xfe, 0xfe, 0x10, 0x38, 0x00, /* ACK */
	0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, /* BEL */
	0xff, 0xff, 0xff, 0xe7, 0xe7, 0xff, 0xff, 0xff, /* BS  */
	0x38, 0x44, 0x82, 0x82, 0x82, 0x44, 0x38, 0x00, /* HT  */
	0xc7, 0xbb, 0x7d, 0x7d, 0x7d, 0xbb, 0xc7, 0xff, /* LF  */
	0x0f, 0x03, 0x05, 0x79, 0x88, 0x88, 0x88, 0x70, /* VT  */
	0x38, 0x44, 0x44, 0x44, 0x38, 0x10, 0x7c, 0x10, /* FF  */
	0x30, 0x28, 0x24, 0x24, 0x28, 0x20, 0xe0, 0xc0, /* CR  */
	0x3c, 0x24, 0x3c, 0x24, 0x24, 0xe4, 0xdc, 0x18, /* SO  */
	0x10, 0x54, 0x38, 0xee, 0x38, 0x54, 0x10, 0x00, /* SI  */
	0x10, 0x10, 0x10, 0x7c, 0x10, 0x10, 0x10, 0x10, /* DLE */
	0x10, 0x10, 0x10, 0xff, 0x00, 0x00, 0x00, 0x00, /* DC1 */
	0x00, 0x00, 0x00, 0xff, 0x10, 0x10, 0x10, 0x10, /* DC2 */
	0x10, 0x10, 0x10, 0xf0, 0x10, 0x10, 0x10, 0x10, /* DC3 */
	0x10, 0x10, 0x10, 0x1f, 0x10, 0x10, 0x10, 0x10, /* DC4 */
	0x10, 0x10, 0x10, 0xff, 0x10, 0x10, 0x10, 0x10, /* NAK */
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, /* SYN */
	0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, /* ETB */
	0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x10, 0x10, /* CAN */
	0x00, 0x00, 0x00, 0xf0, 0x10, 0x10, 0x10, 0x10, /* EM  */
	0x10, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, /* SUB */
	0x10, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, /* ESC */
	0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81, /* FS  */
	0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, /* GS  */
	0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, /* RS  */
	0x00, 0x10, 0x10, 0xff, 0x10, 0x10, 0x00, 0x00, /* US  */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* (WHITESPACE) */
	0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x10, 0x00, /* ! */
	0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, /* " */
	0x28, 0x28, 0x7C, 0x28, 0x7C, 0x28, 0x28, 0x00, /* # */
	0x10, 0x3C, 0x50, 0x38, 0x14, 0x78, 0x10, 0x00, /* $ */
	0x60, 0x64, 0x08, 0x10, 0x20, 0x4C, 0x0C, 0x00, /* % */
	0x20, 0x50, 0x20, 0x54, 0x48, 0x4C, 0x30, 0x00, /* & */
	0x08, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, /* ' */
	0x08, 0x10, 0x20, 0x20, 0x20, 0x10, 0x08, 0x00, /* ( */
	0x20, 0x10, 0x08, 0x08, 0x08, 0x10, 0x20, 0x00, /* ) */
	0x10, 0x54, 0x38, 0x10, 0x38, 0x54, 0x10, 0x00, /* * */
	0x00, 0x10, 0x10, 0x7C, 0x10, 0x10, 0x00, 0x00, /* + */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x20, /* , */
	0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, /* - */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, /* . */
	0x00, 0x04, 0x08, 0x10, 0x20, 0x40, 0x00, 0x00, /* / */
	0x38, 0x44, 0x4C, 0x54, 0x64, 0x44, 0x38, 0x00, // 0
	0x10, 0x30, 0x50, 0x10, 0x10, 0x10, 0x7C, 0x00, // 1
	0x38, 0x44, 0x04, 0x08, 0x30, 0x40, 0x7C, 0x00, // 2
	0x38, 0x44, 0x04, 0x18, 0x04, 0x44, 0x38, 0x00, // 3
	0x08, 0x18, 0x28, 0x48, 0x7C, 0x08, 0x08, 0x00, // 4
	0x7C, 0x40, 0x40, 0x78, 0x04, 0x04, 0x78, 0x00, // 5
	0x18, 0x20, 0x40, 0x78, 0x44, 0x44, 0x38, 0x00, // 6
	0x7C, 0x44, 0x08, 0x10, 0x10, 0x10, 0x10, 0x00, // 7
	0x38, 0x44, 0x44, 0x38, 0x44, 0x44, 0x38, 0x00, // 8
	0x38, 0x44, 0x44, 0x3C, 0x04, 0x08, 0x30, 0x00, // 9
	0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, /* : */
	0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x10, 0x20, /* ; */
	0x0C, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0C, 0x00, /* < */
	0x00, 0x00, 0x7C, 0x00, 0x7C, 0x00, 0x00, 0x00, /* = */
	0x30, 0x18, 0x0C, 0x06, 0x0C, 0x18, 0x30, 0x00, /* > */
	0x38, 0x44, 0x04, 0x08, 0x10, 0x00, 0x10, 0x00, /* ? */
	0x38, 0x44, 0x04, 0x34, 0x54, 0x54, 0x38, 0x00, /* @ */
	0x38, 0x44, 0x44, 0x44, 0x7C, 0x44, 0x44, 0x00, // A
	0x78, 0x44, 0x44, 0x78, 0x44, 0x44, 0x78, 0x00, // B
	0x3C, 0x40, 0x40, 0x40, 0x40, 0x40, 0x3C, 0x00, // C
	0x78, 0x44, 0x44, 0x44, 0x44, 0x44, 0x78, 0x00, // D
	0x7C, 0x40, 0x40, 0x78, 0x40, 0x40, 0x7C, 0x00, // E
	0x7C, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40, 0x00, // F
	0x3C, 0x40, 0x40, 0x5C, 0x44, 0x44, 0x3C, 0x00, // G
	0x44, 0x44, 0x44, 0x7C, 0x44, 0x44, 0x44, 0x00, // H
	0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00, // I
	0x1C, 0x04, 0x04, 0x04, 0x04, 0x44, 0x38, 0x00, // J
	0x44, 0x48, 0x50, 0x60, 0x50, 0x48, 0x44, 0x00, // K
	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7C, 0x00, // L
	0x44, 0x6C, 0x54, 0x54, 0x44, 0x44, 0x44, 0x00, // M
	0x44, 0x64, 0x64, 0x54, 0x4C, 0x4C, 0x44, 0x00, // N
	0x38, 0x44, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00, // O
	0x78, 0x44, 0x44, 0x78, 0x40, 0x40, 0x40, 0x00, // P
	0x38, 0x44, 0x44, 0x44, 0x54, 0x4C, 0x3C, 0x00, // Q
	0x78, 0x44, 0x44, 0x78, 0x44, 0x44, 0x44, 0x00, // R
	0x3C, 0x40, 0x40, 0x38, 0x04, 0x04, 0x78, 0x00, // S
	0x7C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, // T
	0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00, // U
	0x44, 0x44, 0x44, 0x44, 0x44, 0x28, 0x10, 0x00, // V
	0x44, 0x44, 0x44, 0x54, 0x54, 0x6C, 0x44, 0x00, // W
	0x44, 0x44, 0x28, 0x10, 0x28, 0x44, 0x44, 0x00, // X
	0x44, 0x44, 0x44, 0x28, 0x10, 0x10, 0x10, 0x00, // Y
	0x7C, 0x04, 0x08, 0x10, 0x20, 0x40, 0x7C, 0x00, // Z
	0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x00, /* [ */
	0x00, 0x40, 0x20, 0x10, 0x08, 0x04, 0x00, 0x00, /* \ */
	0x38, 0x08, 0x08, 0x08, 0x08, 0x08, 0x38, 0x00, /* ] */
	0x10, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, /* ^ */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, /* _ */
	0x20, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, /* ` */
	0x00, 0x00, 0x3C, 0x44, 0x44, 0x4C, 0x34, 0x00, // a
	0x40, 0x40, 0x78, 0x44, 0x44, 0x44, 0x78, 0x00, // b
	0x00, 0x00, 0x3C, 0x40, 0x40, 0x40, 0x3C, 0x00, // c
	0x04, 0x04, 0x3C, 0x44, 0x44, 0x44, 0x3C, 0x00, // d
	0x00, 0x00, 0x38, 0x44, 0x7C, 0x40, 0x3C, 0x00, // e
	0x0C, 0x10, 0x10, 0x7C, 0x10, 0x10, 0x10, 0x00, // f
	0x00, 0x00, 0x3C, 0x44, 0x44, 0x3C, 0x04, 0x38, // g
	0x40, 0x40, 0x78, 0x44, 0x44, 0x44, 0x44, 0x00, // h
	0x10, 0x00, 0x30, 0x10, 0x10, 0x10, 0x38, 0x00, // i
	0x04, 0x00, 0x0C, 0x04, 0x04, 0x04, 0x44, 0x38, // j
	0x40, 0x48, 0x50, 0x60, 0x50, 0x48, 0x44, 0x00, // k
	0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00, // l
	0x00, 0x00, 0x68, 0x54, 0x54, 0x54, 0x54, 0x00, // m
	0x00, 0x00, 0x78, 0x44, 0x44, 0x44, 0x44, 0x00, // n
	0x00, 0x00, 0x38, 0x44, 0x44, 0x44, 0x38, 0x00, // o
	0x00, 0x00, 0x78, 0x44, 0x44, 0x44, 0x78, 0x40, // p
	0x00, 0x00, 0x3C, 0x44, 0x44, 0x44, 0x3C, 0x04, // q
	0x00, 0x00, 0x5C, 0x60, 0x40, 0x40, 0x40, 0x00, // r
	0x00, 0x00, 0x3C, 0x40, 0x38, 0x04, 0x78, 0x00, // s
	0x20, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x1C, 0x00, // t
	0x00, 0x00, 0x44, 0x44, 0x44, 0x4C, 0x34, 0x00, // u
	0x00, 0x00, 0x44, 0x44, 0x44, 0x28, 0x10, 0x00, // v
	0x00, 0x00, 0x44, 0x54, 0x54, 0x54, 0x28, 0x00, // w
	0x00, 0x00, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00, // x
	0x00, 0x00, 0x44, 0x44, 0x44, 0x3C, 0x04, 0x38, // y
	0x00, 0x00, 0x7C, 0x08, 0x10, 0x20, 0x7C, 0x00, // z
	0x0C, 0x10, 0x10, 0x20, 0x10, 0x10, 0x0C, 0x00, /* { */
	0x10, 0x10, 0x10, 0x00, 0x10, 0x10, 0x10, 0x00, /* | */
	0x60, 0x10, 0x10, 0x08, 0x10, 0x10, 0x60, 0x00, /* } */
	0x20, 0x54, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, /* ~ */
	0x00, 0x00, 0x20, 0x50, 0xf8, 0x00, 0x00, 0x00,  /* (DEL) */
	
	/* 0x80-0xFF */
	0x00, 0x10, 0x38, 0x54, 0x10, 0x10, 0x00, 0x00, /* PSP_CTRL_UP */
	0x00, 0x10, 0x08, 0x7C, 0x08, 0x10, 0x00, 0x00, /* PSP_CTRL_RIGHT */
	0x00, 0x10, 0x10, 0x54, 0x38, 0x10, 0x00, 0x00, /* PSP_CTRL_DOWN */
	0x00, 0x10, 0x20, 0x7C, 0x20, 0x10, 0x00, 0x00, /* PSP_CTRL_LEFT */
	0x10, 0x10, 0x28, 0x28, 0x44, 0x7C, 0x00, 0x00, /* PSP_CTRL_TRIANGLE */
	0x00, 0x38, 0x44, 0x44, 0x44, 0x38, 0x00, 0x00, /* PSP_CTRL_CIRCLE */
	0x00, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00, 0x00, /* PSP_CTRL_CROSS */
	0x00, 0x7C, 0x44, 0x44, 0x44, 0x7C, 0x00, 0x00, /* PSP_CTRL_SQUARE */
	0x10, 0x18, 0x14, 0x14, 0x10, 0x30, 0x70, 0x60, /* PSP_CTRL_NOTE */
	0x10, 0x10, 0x10, 0x28, 0x28, 0x44, 0x82, 0x00, // 3f4d(人) 0x89
	0x50, 0xc8, 0x7e, 0xc8, 0xdc, 0x48, 0x7e, 0x00, // 436c(柱) 0x8a
	0x2e, 0xf2, 0x2e, 0xf8, 0x6e, 0x60, 0x9e, 0x00, // 352f(起) 0x8b
	0xe8, 0x5e, 0xea, 0xea, 0xea, 0x4a, 0xf6, 0x00, // 4630(動) 0x8c
	0x94, 0x1e, 0xb4, 0x1e, 0x90, 0xfe, 0x10, 0x00, // 3d60(準) 0x8d
	0x7e, 0x7e, 0x4c, 0x78, 0x4e, 0x78, 0x8e, 0x00, // 4878(備) 0x8e
	0x10, 0xfe, 0xba, 0x00, 0xfe, 0x28, 0xce, 0x00, // 3430(完) 0x8f
	0xfe, 0x04, 0x18, 0x10, 0x10, 0x10, 0x30, 0x00, // 4e3b(了) 0x90
	0x0c, 0x12, 0x2c, 0x22, 0x32, 0x4c, 0x40, 0x00, // 2642(β) 0x91
};
