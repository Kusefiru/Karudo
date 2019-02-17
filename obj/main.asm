;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Apr  7 2010) (MINGW32)
; This file was generated Sun Feb 10 22:24:29 2019
;--------------------------------------------------------
	.module main
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _link_map
	.globl _is_taken
	.globl _seed
	.globl _GLOBAL_TIMER
	.globl _TIMER_MOVE
	.globl _display_map
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
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;src/main.c:28: void main(void)
;	---------------------------------
; Function main
; ---------------------------------
_main:
	
;src/main.c:30: game_init();
	call	_game_init
;src/main.c:32: set_bkg_palette(0,5,area_tiles_palette);
	ld	hl,#_area_tiles_palette
	push	hl
	ld	hl,#0x0500
	push	hl
	call	_set_bkg_palette
	lda	sp,4(sp)
;src/main.c:33: set_bkg_data(0,5,area_tiles);
	ld	hl,#_area_tiles
	push	hl
	ld	hl,#0x0500
	push	hl
	call	_set_bkg_data
	lda	sp,4(sp)
;src/main.c:35: f_DisplayMap(map_room, metatiles);
	ld	hl,#_metatiles
	push	hl
	ld	hl,#_map_room
	push	hl
	call	_f_DisplayMap
	lda	sp,4(sp)
00101$:
	
ret
;src/main.c:40: void display_map(void)
;	---------------------------------
; Function display_map
; ---------------------------------
_display_map:
	
	push	af
;src/main.c:42: set_bkg_palette(0,5,area_tiles_palette);
	ld	hl,#_area_tiles_palette
	push	hl
	ld	hl,#0x0500
	push	hl
	call	_set_bkg_palette
	lda	sp,4(sp)
;src/main.c:43: set_bkg_data(0,5,area_tiles);
	ld	hl,#_area_tiles
	push	hl
	ld	hl,#0x0500
	push	hl
	call	_set_bkg_data
	lda	sp,4(sp)
;src/main.c:45: VBK_REG = 1;
	ld	bc,#0xFF4F
	ld	a,#0x01
	ld	(bc),a
;src/main.c:46: set_bkg_tiles(0, 0, _DungeonMapWidth, _DungeonMapHeight, map_room);
	ld	hl,#_map_room
	push	hl
	ld	hl,#0x1014
	push	hl
	ld	hl,#0x0000
	push	hl
	call	_set_bkg_tiles
	lda	sp,6(sp)
;src/main.c:47: VBK_REG = 0;
	ld	bc,#0xFF4F
	ld	a,#0x00
	ld	(bc),a
;src/main.c:48: set_bkg_tiles(0, 0, _DungeonMapWidth, _DungeonMapHeight, map_room);
	ld	hl,#_map_room
	push	hl
	ld	hl,#0x1014
	push	hl
	ld	hl,#0x0000
	push	hl
	call	_set_bkg_tiles
	lda	sp,6(sp)
;src/main.c:49: SHOW_BKG;
	lda	hl,0(sp)
	ld	(hl),#0x40
	inc	hl
	ld	(hl),#0xFF
	ld	bc,#0xFF40
	ld	a,(bc)
	ld	c,a
	ld	b,#0x00
	ld	a,c
	or	a,#0x01
	ld	c,a
	dec	hl
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	ld	(de),a
00101$:
	lda	sp,2(sp)
ret
;src/main.c:53: void game_init(void)
;	---------------------------------
; Function game_init
; ---------------------------------
_game_init:
	
;src/main.c:55: GLOBAL_TIMER = 0;
	xor	a,a
	ld	hl,#_GLOBAL_TIMER
	ld	(hl),a
	ld	hl,#_GLOBAL_TIMER + 1
	ld	(hl),a
	ld	hl,#_GLOBAL_TIMER + 2
	ld	(hl),a
	ld	hl,#_GLOBAL_TIMER + 3
	ld	(hl),a
;src/main.c:56: TAC_REG = 0x07U;
	ld	bc,#0xFF07
	ld	a,#0x07
	ld	(bc),a
;src/main.c:58: interrupt_init();
	call	_interrupt_init
00101$:
	
ret
;src/main.c:61: void interrupt_init(void)
;	---------------------------------
; Function interrupt_init
; ---------------------------------
_interrupt_init:
	
;src/main.c:63: disable_interrupts();
	call	_disable_interrupts
;src/main.c:64: add_TIM(timer_interrupt);
	ld	hl,#_timer_interrupt
	push	hl
	call	_add_TIM
	lda	sp,2(sp)
;src/main.c:65: add_VBL(timer_interrupt);
	ld	hl,#_timer_interrupt
	push	hl
	call	_add_VBL
	lda	sp,2(sp)
;src/main.c:66: enable_interrupts();
	call	_enable_interrupts
;src/main.c:68: set_interrupts(VBL_IFLAG | TIM_IFLAG);
	ld	a,#0x05
	push	af
	inc	sp
	call	_set_interrupts
	lda	sp,1(sp)
00101$:
	
ret
;src/main.c:71: void timer_interrupt(void)
;	---------------------------------
; Function timer_interrupt
; ---------------------------------
_timer_interrupt:
	
;src/main.c:73: GLOBAL_TIMER++;
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
;src/main.c:74: TIMER_MOVE++;
	ld	hl,#_TIMER_MOVE
	inc	(hl)
00101$:
	
ret
	.area _CODE
	.area _CABS
