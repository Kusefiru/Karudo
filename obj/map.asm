;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Apr  7 2010) (MINGW32)
; This file was generated Sun Sep 22 13:16:31 2019
;--------------------------------------------------------
	.module map
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _f_DisplayMap
;--------------------------------------------------------
;  ram data
;--------------------------------------------------------
	.area _DATA
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
;src/map.c:21: void f_DisplayMap(
;	---------------------------------
; Function f_DisplayMap
; ---------------------------------
_f_DisplayMap:
	
	push	af
	push	af
;src/map.c:29: i = 0;
	lda	hl,3(sp)
	ld	(hl),#0x00
;src/map.c:31: pointerOnMap = mapAddress;
	lda	hl,6(sp)
	ld	c,(hl)
	inc	hl
	ld	b,(hl)
;src/map.c:33: while(j != _DungeonMapHeight)
	lda	hl,0(sp)
	ld	(hl),c
	inc	hl
	ld	(hl),b
	inc	hl
	ld	(hl),#0x00
00103$:
	lda	hl,2(sp)
	ld	a,(hl)
	sub	a,#0x10
	jp	Z,00106$
00112$:
;src/map.c:35: set_bkg_tiles(i, j, 2, 2, (metaTileAddress + *(pointerOnMap)*4));
	lda	hl,0(sp)
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	ld	a,(de)
	ld	b,a
	ld	c,b
	ld	b,#0x00
	sla	c
	rl	b
	sla	c
	rl	b
	lda	hl,8(sp)
	ld	a,(hl+)
	ld	h,(hl)
	ld	l,a
	add	hl,bc
	ld	c,l
	ld	b,h
	push	bc
	ld	hl,#0x0202
	push	hl
	lda	hl,6(sp)
	ld	a,(hl)
	push	af
	inc	sp
	inc	hl
	ld	a,(hl)
	push	af
	inc	sp
	call	_set_bkg_tiles
	lda	sp,6(sp)
;src/map.c:37: pointerOnMap++;
	lda	hl,0(sp)
	inc	(hl)
	jr	NZ,00115$
	inc	hl
	inc	(hl)
00115$:
;src/map.c:38: i += 2;
	lda	hl,3(sp)
	inc	(hl)
	inc	(hl)
;src/map.c:39: if(i%_DungeonMapWidth == 0)
	ld	a,#0x14
	push	af
	inc	sp
	ld	a,(hl)
	push	af
	inc	sp
	call	__moduchar_rrx_s
	lda	sp,2(sp)
	ld	c,e
	xor	a,a
	or	a,c
	jp	NZ,00103$
;src/map.c:41: i = 0;
	lda	hl,3(sp)
	ld	(hl),#0x00
;src/map.c:42: j += 2;
	dec	hl
	inc	(hl)
	inc	(hl)
	jp	00103$
00106$:
	lda	sp,4(sp)
ret
	.area _CODE
	.area _CABS
