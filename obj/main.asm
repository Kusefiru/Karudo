;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Apr  7 2010) (MINGW32)
; This file was generated Sun Sep 22 14:22:20 2019
;--------------------------------------------------------
	.module main
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _character_tiles
	.globl _CHAR_FRAME
	.globl _CHAR_LAST_ANIM
	.globl _CHAR_Y
	.globl _CHAR_X
	.globl _link_map
	.globl _is_taken
	.globl _seed
	.globl _GLOBAL_TIMER
	.globl _TIMER_MOVE
	.globl _marisa_palette
	.globl _f_LoadSprites
	.globl _f_MoveCharacter
	.globl _game_init
	.globl _interrupt_init
	.globl _timer_interrupt
;--------------------------------------------------------
;  ram data
;--------------------------------------------------------
	.area _DATA
_TIMER_MOVE::
	.ds 1
_GLOBAL_TIMER::
	.ds 4
_seed::
	.ds 2
_is_taken::
	.ds 256
_link_map::
	.ds 256
_CHAR_X::
	.ds 1
_CHAR_Y::
	.ds 1
_CHAR_LAST_ANIM::
	.ds 1
_CHAR_FRAME::
	.ds 1
_character_tiles::
	.ds 256
;--------------------------------------------------------
; overlayable items in  ram 
;--------------------------------------------------------
	.area _OVERLAY
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;src/main.c:35: T_U08 character_tiles[] =
	ld	hl,#_character_tiles
	call	__initrleblock
	.db	2
	.db	0xFF, 0xFF
	.db	#-8,#0x80
	.db	4
	.db	0x83, 0x83, 0x8E, 0x8E
	.db	#-10,#0x80
	.db	10
	.db	0x8F, 0x8F, 0x80, 0x80, 0x80, 0x80, 0xFF, 0xFF
	.db	0xFF, 0xFF
	.db	#-6,#0x01
	.db	#-6,#0xC1
	.db	#-8,#0x81
	.db	98
	.db	0xBD, 0xBD, 0xE1, 0xE1, 0x01, 0x01, 0x01, 0x01
	.db	0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0x80
	.db	0x83, 0x83, 0x86, 0x86, 0x84, 0x84, 0x80, 0x80
	.db	0x80, 0x80, 0x81, 0x81, 0x83, 0x83, 0x8E, 0x8E
	.db	0x98, 0x98, 0x9F, 0x9F, 0x80, 0x80, 0x80, 0x80
	.db	0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01
	.db	0x81, 0x81, 0xC1, 0xC1, 0x41, 0x41, 0xC1, 0xC1
	.db	0x81, 0x81, 0x81, 0x81, 0x01, 0x01, 0x01, 0x01
	.db	0x71, 0x71, 0xC1, 0xC1, 0x01, 0x01, 0x01, 0x01
	.db	0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0x80
	.db	0x87, 0x87, 0x84, 0x84, 0x80, 0x80, 0x80, 0x80
	.db	0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x88, 0x88
	.db	0x8F, 0x8F
	.db	#-6,#0x80
	.db	26
	.db	0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01
	.db	0xE1, 0xE1, 0x21, 0x21, 0x61, 0x61, 0xE1, 0xE1
	.db	0xB1, 0xB1, 0x11, 0x11, 0x11, 0x11, 0x31, 0x31
	.db	0xE1, 0xE1
	.db	#-6,#0x01
	.db	20
	.db	0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0x80
	.db	0x81, 0x81, 0x87, 0x87, 0x8C, 0x8C, 0x98, 0x98
	.db	0xB0, 0xB0, 0xBF, 0xBF
	.db	#-12,#0x80
	.db	10
	.db	0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0xC1, 0xC1
	.db	0xC1, 0xC1
	.db	#-6,#0x41
	.db	4
	.db	0x71, 0x71, 0xC1, 0xC1
	.db	#-6,#0x41
	.db	8
	.db	0x61, 0x61, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF
	.db	0
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;src/main.c:80: void main(void)
;	---------------------------------
; Function main
; ---------------------------------
_main:
	
;src/main.c:82: game_init();
	call	_game_init
;src/main.c:84: set_bkg_palette(0,5,area_tiles_palette);
	ld	hl,#_area_tiles_palette
	push	hl
	ld	hl,#0x0500
	push	hl
	call	_set_bkg_palette
	lda	sp,4(sp)
;src/main.c:85: set_bkg_data(0,5,area_tiles);
	ld	hl,#_area_tiles
	push	hl
	ld	hl,#0x0500
	push	hl
	call	_set_bkg_data
	lda	sp,4(sp)
;src/main.c:87: CHAR_X 		= 64;
	ld	hl,#_CHAR_X
	ld	(hl),#0x40
;src/main.c:88: CHAR_Y		= 64;
	ld	hl,#_CHAR_Y
	ld	(hl),#0x40
;src/main.c:89: CHAR_LAST_ANIM	= 0;
	ld	hl,#_CHAR_LAST_ANIM
	ld	(hl),#0x00
;src/main.c:90: CHAR_FRAME  = 0;
	ld	hl,#_CHAR_FRAME
	ld	(hl),#0x00
;src/main.c:92: f_DisplayMap(map_room, metatiles);
	ld	hl,#_metatiles
	push	hl
	ld	hl,#_map_room
	push	hl
	call	_f_DisplayMap
	lda	sp,4(sp)
;src/main.c:94: f_LoadSprites();
	call	_f_LoadSprites
;src/main.c:96: while(1){
00102$:
;src/main.c:97: f_MoveCharacter();
	call	_f_MoveCharacter
;src/main.c:100: CHAR_LAST_ANIM++;
	ld	hl,#_CHAR_LAST_ANIM
	inc	(hl)
;src/main.c:103: wait_vbl_done();
	call	_wait_vbl_done
	jp	00102$
00104$:
	
ret
_marisa_palette:
	.dw #0x7C00
	.dw #0x7FFF
	.dw #0x18C6
	.dw #0x0000
	.dw #0x7C00
	.dw #0x039C
	.dw #0x18C6
	.dw #0x0000
;src/main.c:109: void f_LoadSprites(void)
;	---------------------------------
; Function f_LoadSprites
; ---------------------------------
_f_LoadSprites:
	
	push	af
	dec	sp
;src/main.c:112: SPRITES_8x8;
	lda	hl,0(sp)
	ld	(hl),#0x40
	inc	hl
	ld	(hl),#0xFF
	ld	bc,#0xFF40
	ld	a,(bc)
	ld	c,a
	ld	b,#0x00
	ld	a,c
	and	a,#0xFB
	ld	c,a
	ld	b,#0x00
	ld	a,c
	dec	hl
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	ld	(de),a
;src/main.c:114: for(k=0;k!=8;k++){
	inc	hl
	ld	(hl),#0x00
00101$:
	lda	hl,2(sp)
	ld	a,(hl)
	sub	a,#0x08
	jp	Z,00104$
00110$:
;src/main.c:115: set_sprite_palette_entry((k>>2),k%4,character_tiles[k]);
	ld	de,#_character_tiles
	lda	hl,2(sp)
	ld	l,(hl)
	ld	h,#0x00
	add	hl,de
	ld	c,l
	ld	b,h
	ld	a,(bc)
	ld	c,a
	lda	hl,0(sp)
	ld	(hl),c
	inc	hl
	ld	(hl),#0x00
	inc	hl
	ld	a,(hl)
	and	a,#0x03
	ld	c,a
	ld	b,(hl)
	srl	b
	srl	b
	dec	hl
	dec	hl
	ld	a,(hl+)
	ld	h,(hl)
	ld	l,a
	push	hl
	ld	a,c
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_set_sprite_palette_entry
	lda	sp,4(sp)
;src/main.c:114: for(k=0;k!=8;k++){
	lda	hl,2(sp)
	inc	(hl)
	jp	00101$
00104$:
;src/main.c:118: set_data(0x8000,character_tiles,16);
	ld	hl,#0x0010
	push	hl
	ld	hl,#_character_tiles
	push	hl
	ld	hl,#0x8000
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:119: set_data(0x8010,character_tiles+0x10U,16);
	ld	bc,#_character_tiles + 16
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	h, #0x80
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:120: set_data(0x8020,character_tiles+0x20U,16);
	ld	bc,#_character_tiles + 32
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	hl,#0x8020
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:121: set_data(0x8030,character_tiles+0x30U,16);
	ld	bc,#_character_tiles + 48
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	hl,#0x8030
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:123: set_data(0x8040,character_tiles+0x40U,16);
	ld	bc,#_character_tiles + 64
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	hl,#0x8040
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:124: set_data(0x8050,character_tiles+0x50U,16);
	ld	bc,#_character_tiles + 80
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	hl,#0x8050
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:125: set_data(0x8060,character_tiles+0x60U,16);
	ld	bc,#_character_tiles + 96
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	hl,#0x8060
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:126: set_data(0x8070,character_tiles+0x70U,16);
	ld	bc,#_character_tiles + 112
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	hl,#0x8070
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:128: set_data(0x8080,character_tiles+0x80U,16);
	ld	bc,#_character_tiles + 128
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	hl,#0x8080
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:129: set_data(0x8090,character_tiles+0x90U,16);
	ld	bc,#_character_tiles + 144
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	hl,#0x8090
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:130: set_data(0x80A0,character_tiles+0xA0U,16);
	ld	bc,#_character_tiles + 160
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	hl,#0x80A0
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:131: set_data(0x80B0,character_tiles+0xB0U,16);
	ld	bc,#_character_tiles + 176
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	hl,#0x80B0
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:133: set_data(0x80C0,character_tiles+0xC0U,16);
	ld	bc,#_character_tiles + 192
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	hl,#0x80C0
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:134: set_data(0x80D0,character_tiles+0xD0U,16);
	ld	bc,#_character_tiles + 208
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	hl,#0x80D0
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:135: set_data(0x80E0,character_tiles+0xE0U,16);
	ld	bc,#_character_tiles + 224
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	hl,#0x80E0
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:136: set_data(0x80F0,character_tiles+0xF0U,16);
	ld	bc,#_character_tiles + 240
	ld	hl,#0x0010
	push	hl
	push	bc
	ld	hl,#0x80F0
	push	hl
	call	_set_data
	lda	sp,6(sp)
;src/main.c:138: set_sprite_tile(0,0);				// S0 is the first tile of the sprite VRAM
	ld	hl,#0x0000
	push	hl
	call	_set_sprite_tile
	lda	sp,2(sp)
;src/main.c:139: set_sprite_prop(0,0);				// S0 got palette 0
	ld	hl,#0x0000
	push	hl
	call	_set_sprite_prop
	lda	sp,2(sp)
;src/main.c:140: move_sprite(0,CHAR_X,CHAR_Y);		// Move sprite to its initial position (given in level initialization)
	ld	hl,#_CHAR_Y
	ld	a,(hl)
	push	af
	inc	sp
	ld	hl,#_CHAR_X
	ld	a,(hl)
	push	af
	inc	sp
	ld	a,#0x00
	push	af
	inc	sp
	call	_move_sprite
	lda	sp,3(sp)
;src/main.c:141: set_sprite_tile(1,2);				// S1 is the second tile of the sprite VRAM
	ld	hl,#0x0201
	push	hl
	call	_set_sprite_tile
	lda	sp,2(sp)
;src/main.c:142: set_sprite_prop(1,0);				// S1 got palette 0
	ld	hl,#0x0001
	push	hl
	call	_set_sprite_prop
	lda	sp,2(sp)
;src/main.c:143: move_sprite(1,CHAR_X+8,CHAR_Y);		// etc...
	ld	hl,#_CHAR_X
	ld	a,(hl)
	add	a,#0x08
	ld	c,a
	ld	hl,#_CHAR_Y
	ld	a,(hl)
	push	af
	inc	sp
	ld	b,c
	ld	c,#0x01
	push	bc
	call	_move_sprite
	lda	sp,3(sp)
;src/main.c:144: set_sprite_tile(2,1);
	ld	hl,#0x0102
	push	hl
	call	_set_sprite_tile
	lda	sp,2(sp)
;src/main.c:145: set_sprite_prop(2,0);
	ld	hl,#0x0002
	push	hl
	call	_set_sprite_prop
	lda	sp,2(sp)
;src/main.c:146: move_sprite(2,CHAR_X,CHAR_Y+8);
	ld	hl,#_CHAR_Y
	ld	a,(hl)
	add	a,#0x08
	ld	c,a
	push	af
	inc	sp
	ld	hl,#_CHAR_X
	ld	a,(hl)
	push	af
	inc	sp
	ld	a,#0x02
	push	af
	inc	sp
	call	_move_sprite
	lda	sp,3(sp)
;src/main.c:147: set_sprite_tile(3,3);
	ld	hl,#0x0303
	push	hl
	call	_set_sprite_tile
	lda	sp,2(sp)
;src/main.c:148: set_sprite_prop(3,0);
	ld	hl,#0x0003
	push	hl
	call	_set_sprite_prop
	lda	sp,2(sp)
;src/main.c:149: move_sprite(3,CHAR_X+8,CHAR_Y+8);
	ld	hl,#_CHAR_Y
	ld	a,(hl)
	add	a,#0x08
	ld	c,a
	ld	hl,#_CHAR_X
	ld	a,(hl)
	add	a,#0x08
	ld	b,a
	ld	a,c
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a,#0x03
	push	af
	inc	sp
	call	_move_sprite
	lda	sp,3(sp)
;src/main.c:151: SHOW_SPRITES;
	lda	hl,0(sp)
	ld	(hl),#0x40
	inc	hl
	ld	(hl),#0xFF
	ld	bc,#0xFF40
	ld	a,(bc)
	ld	c,a
	ld	b,#0x00
	ld	a,c
	or	a,#0x02
	ld	c,a
	dec	hl
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	ld	(de),a
00105$:
	lda	sp,3(sp)
ret
;src/main.c:154: void f_MoveCharacter(void)
;	---------------------------------
; Function f_MoveCharacter
; ---------------------------------
_f_MoveCharacter:
	
;src/main.c:157: if(joypad() & J_RIGHT)
	call	_joypad
	ld	c,e
	ld	b,#0x00
	ld	a,c
	and	a,#0x01
	jr	NZ,00133$
	jp	00104$
00133$:
;src/main.c:159: CHAR_X++;
	ld	hl,#_CHAR_X
	inc	(hl)
;src/main.c:160: if(CHAR_X==137) CHAR_X--;
	ld	hl,#_CHAR_X
	ld	a,(hl)
	sub	a,#0x89
	jp	NZ,00134$
	jr	00135$
00134$:
	jp	00104$
00135$:
	ld	hl,#_CHAR_X
	dec	(hl)
00104$:
;src/main.c:162: if(joypad() & J_LEFT)
	call	_joypad
	ld	c,e
	ld	b,#0x00
	ld	a,c
	and	a,#0x02
	jr	NZ,00136$
	jp	00108$
00136$:
;src/main.c:164: CHAR_X--;
	ld	hl,#_CHAR_X
	dec	(hl)
;src/main.c:165: if(CHAR_X==23) CHAR_X++;
	ld	hl,#_CHAR_X
	ld	a,(hl)
	sub	a,#0x17
	jp	NZ,00137$
	jr	00138$
00137$:
	jp	00108$
00138$:
	ld	hl,#_CHAR_X
	inc	(hl)
00108$:
;src/main.c:167: if(joypad() & J_UP)
	call	_joypad
	ld	c,e
	ld	b,#0x00
	ld	a,c
	and	a,#0x04
	jr	NZ,00139$
	jp	00112$
00139$:
;src/main.c:169: CHAR_Y--;
	ld	hl,#_CHAR_Y
	dec	(hl)
;src/main.c:170: if(CHAR_Y==31) CHAR_Y++;
	ld	hl,#_CHAR_Y
	ld	a,(hl)
	sub	a,#0x1F
	jp	NZ,00140$
	jr	00141$
00140$:
	jp	00112$
00141$:
	ld	hl,#_CHAR_Y
	inc	(hl)
00112$:
;src/main.c:172: if(joypad() & J_DOWN)
	call	_joypad
	ld	c,e
	ld	b,#0x00
	ld	a,c
	and	a,#0x08
	jr	NZ,00142$
	jp	00116$
00142$:
;src/main.c:174: CHAR_Y++;
	ld	hl,#_CHAR_Y
	inc	(hl)
;src/main.c:175: if(CHAR_Y==113) CHAR_Y--;
	ld	hl,#_CHAR_Y
	ld	a,(hl)
	sub	a,#0x71
	jp	NZ,00143$
	jr	00144$
00143$:
	jp	00116$
00144$:
	ld	hl,#_CHAR_Y
	dec	(hl)
00116$:
;src/main.c:179: if(16U == CHAR_LAST_ANIM){
	ld	hl,#_CHAR_LAST_ANIM
	ld	c,(hl)
	ld	b,#0x00
	ld	a,c
	sub	a,#0x10
	jp	NZ,00145$
	or	a,b
	jp	NZ,00145$
	jr	00146$
00145$:
	jp	00120$
00146$:
;src/main.c:180: CHAR_FRAME++;
	ld	hl,#_CHAR_FRAME
	inc	(hl)
;src/main.c:181: if(4U == CHAR_FRAME){
	ld	hl,#_CHAR_FRAME
	ld	c,(hl)
	ld	b,#0x00
	ld	a,c
	sub	a,#0x04
	jp	NZ,00147$
	or	a,b
	jp	NZ,00147$
	jr	00148$
00147$:
	jp	00118$
00148$:
;src/main.c:182: CHAR_FRAME = 0U;
	ld	hl,#_CHAR_FRAME
	ld	(hl),#0x00
00118$:
;src/main.c:185: set_sprite_tile(0,0+(CHAR_FRAME<<2));
	ld	hl,#_CHAR_FRAME
	ld	a,(hl)
	add	a,a
	add	a,a
	ld	c,a
	push	af
	inc	sp
	ld	a,#0x00
	push	af
	inc	sp
	call	_set_sprite_tile
	lda	sp,2(sp)
;src/main.c:186: set_sprite_tile(1,2+(CHAR_FRAME<<2));
	ld	hl,#_CHAR_FRAME
	ld	a,(hl)
	add	a,a
	add	a,a
	ld	c,a
	inc	c
	inc	c
	ld	b,c
	ld	c,#0x01
	push	bc
	call	_set_sprite_tile
	lda	sp,2(sp)
;src/main.c:187: set_sprite_tile(2,1+(CHAR_FRAME<<2));
	ld	hl,#_CHAR_FRAME
	ld	a,(hl)
	add	a,a
	add	a,a
	ld	c,a
	inc	c
	ld	b,c
	ld	c,#0x02
	push	bc
	call	_set_sprite_tile
	lda	sp,2(sp)
;src/main.c:188: set_sprite_tile(3,3+(CHAR_FRAME<<2));
	ld	hl,#_CHAR_FRAME
	ld	a,(hl)
	add	a,a
	add	a,a
	ld	c,a
	inc	c
	inc	c
	inc	c
	ld	b,c
	ld	c,#0x03
	push	bc
	call	_set_sprite_tile
	lda	sp,2(sp)
;src/main.c:191: CHAR_LAST_ANIM = 0U;
	ld	hl,#_CHAR_LAST_ANIM
	ld	(hl),#0x00
00120$:
;src/main.c:195: move_sprite(0,CHAR_X,CHAR_Y);
	ld	hl,#_CHAR_Y
	ld	a,(hl)
	push	af
	inc	sp
	ld	hl,#_CHAR_X
	ld	a,(hl)
	push	af
	inc	sp
	ld	a,#0x00
	push	af
	inc	sp
	call	_move_sprite
	lda	sp,3(sp)
;src/main.c:196: move_sprite(1,CHAR_X+8,CHAR_Y);
	ld	hl,#_CHAR_X
	ld	a,(hl)
	add	a,#0x08
	ld	c,a
	ld	hl,#_CHAR_Y
	ld	a,(hl)
	push	af
	inc	sp
	ld	b,c
	ld	c,#0x01
	push	bc
	call	_move_sprite
	lda	sp,3(sp)
;src/main.c:197: move_sprite(2,CHAR_X,CHAR_Y+8);
	ld	hl,#_CHAR_Y
	ld	a,(hl)
	add	a,#0x08
	ld	c,a
	push	af
	inc	sp
	ld	hl,#_CHAR_X
	ld	a,(hl)
	push	af
	inc	sp
	ld	a,#0x02
	push	af
	inc	sp
	call	_move_sprite
	lda	sp,3(sp)
;src/main.c:198: move_sprite(3,CHAR_X+8,CHAR_Y+8);
	ld	hl,#_CHAR_Y
	ld	a,(hl)
	add	a,#0x08
	ld	c,a
	ld	hl,#_CHAR_X
	ld	a,(hl)
	add	a,#0x08
	ld	b,a
	ld	a,c
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a,#0x03
	push	af
	inc	sp
	call	_move_sprite
	lda	sp,3(sp)
00121$:
	
ret
;src/main.c:201: void game_init(void)
;	---------------------------------
; Function game_init
; ---------------------------------
_game_init:
	
;src/main.c:203: GLOBAL_TIMER = 0;
	xor	a,a
	ld	hl,#_GLOBAL_TIMER
	ld	(hl),a
	ld	hl,#_GLOBAL_TIMER + 1
	ld	(hl),a
	ld	hl,#_GLOBAL_TIMER + 2
	ld	(hl),a
	ld	hl,#_GLOBAL_TIMER + 3
	ld	(hl),a
;src/main.c:204: TAC_REG = 0x07U;
	ld	bc,#0xFF07
	ld	a,#0x07
	ld	(bc),a
;src/main.c:206: interrupt_init();
	call	_interrupt_init
00101$:
	
ret
;src/main.c:209: void interrupt_init(void)
;	---------------------------------
; Function interrupt_init
; ---------------------------------
_interrupt_init:
	
;src/main.c:211: disable_interrupts();
	call	_disable_interrupts
;src/main.c:212: add_TIM(timer_interrupt);
	ld	hl,#_timer_interrupt
	push	hl
	call	_add_TIM
	lda	sp,2(sp)
;src/main.c:213: add_VBL(timer_interrupt);
	ld	hl,#_timer_interrupt
	push	hl
	call	_add_VBL
	lda	sp,2(sp)
;src/main.c:214: enable_interrupts();
	call	_enable_interrupts
;src/main.c:216: set_interrupts(VBL_IFLAG | TIM_IFLAG);
	ld	a,#0x05
	push	af
	inc	sp
	call	_set_interrupts
	lda	sp,1(sp)
00101$:
	
ret
;src/main.c:219: void timer_interrupt(void)
;	---------------------------------
; Function timer_interrupt
; ---------------------------------
_timer_interrupt:
	
;src/main.c:221: GLOBAL_TIMER++;
	ld	hl,#_GLOBAL_TIMER
	inc	(hl)
	jr	NZ,00103$
	ld	hl,#_GLOBAL_TIMER + 1
	inc	(hl)
	jr	NZ,00103$
	ld	hl,#_GLOBAL_TIMER + 2
	inc	(hl)
	jr	NZ,00103$
	ld	hl,#_GLOBAL_TIMER + 3
	inc	(hl)
00103$:
;src/main.c:222: TIMER_MOVE++;
	ld	hl,#_TIMER_MOVE
	inc	(hl)
00101$:
	
ret
	.area _CODE
	.area _CABS
