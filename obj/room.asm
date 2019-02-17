;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Apr  7 2010) (MINGW32)
; This file was generated Sun Feb 10 22:24:29 2019
;--------------------------------------------------------
	.module room
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _area_tiles_palette
	.globl _area_tiles
;--------------------------------------------------------
;  ram data
;--------------------------------------------------------
	.area _DATA
_area_tiles::
	.ds 80
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
;src/room.c:28: T_U08 area_tiles[] =
	ld	hl,#_area_tiles
	call	__initrleblock
	.db	45
	.db	0xEF, 0x10, 0x77, 0x88, 0x34, 0x4B, 0x80, 0x3C
	.db	0xF3, 0x08, 0xE7, 0x10, 0xCF, 0x20, 0xCF, 0x20
	.db	0xFF, 0xFF, 0xFF, 0x00, 0x44, 0x99, 0x44, 0x99
	.db	0x44, 0x99, 0x44, 0x99, 0x44, 0x99, 0x44, 0x99
	.db	0x44, 0x99, 0x44, 0x99, 0x44, 0x99, 0x00, 0xFF
	.db	0xFF, 0x00, 0x00, 0xFF, 0x00
	.db	#-21,#0xFF
	.db	4
	.db	0x00, 0x20, 0xFF, 0x80
	.db	#-5,#0xFF
	.db	5
	.db	0x4B, 0x20, 0xCF, 0xCF, 0xFF
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
	.area _CODE
_area_tiles_palette:
	.dw #0x471E
	.dw #0x25FF
	.dw #0x050D
	.dw #0x0043
	.dw #0x739C
	.dw #0x5294
	.dw #0x294A
	.dw #0x0842
	.dw #0x739C
	.dw #0x5294
	.dw #0x294A
	.dw #0x0842
	.dw #0x739C
	.dw #0x5294
	.dw #0x294A
	.dw #0x0842
	.dw #0x739C
	.dw #0x5294
	.dw #0x294A
	.dw #0x0842
	.area _CABS
