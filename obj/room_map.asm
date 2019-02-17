;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Apr  7 2010) (MINGW32)
; This file was generated Sun Feb 10 22:24:29 2019
;--------------------------------------------------------
	.module room_map
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _map_room
	.globl _metatiles
;--------------------------------------------------------
;  ram data
;--------------------------------------------------------
	.area _DATA
_metatiles::
	.ds 12
_map_room::
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
;src/room_map.c:28: T_U08 metatiles[] =
	ld	hl,#_metatiles
	call	__initrleblock
	.db	12
	.db	0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x02, 0x02
	.db	0x00, 0x00, 0x00, 0x00
	.db	0
;src/room_map.c:35: T_U08 map_room[] =
	ld	hl,#_map_room
	call	__initrleblock
	.db	1
	.db	0x00
	.db	#-8,#0x01
	.db	2
	.db	0x00, 0x00
	.db	#-8,#0x02
	.db	2
	.db	0x00, 0x00
	.db	#-8,#0x02
	.db	2
	.db	0x00, 0x00
	.db	#-8,#0x02
	.db	2
	.db	0x00, 0x00
	.db	#-8,#0x02
	.db	2
	.db	0x00, 0x00
	.db	#-8,#0x02
	.db	2
	.db	0x00, 0x00
	.db	#-8,#0x02
	.db	#-11,#0x00
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
	.area _CABS
