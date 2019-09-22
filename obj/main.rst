                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Apr  7 2010) (MINGW32)
                              4 ; This file was generated Sun Sep 22 14:22:20 2019
                              5 ;--------------------------------------------------------
                              6 	.module main
                              7 	.optsdcc -mgbz80
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _character_tiles
                             14 	.globl _CHAR_FRAME
                             15 	.globl _CHAR_LAST_ANIM
                             16 	.globl _CHAR_Y
                             17 	.globl _CHAR_X
                             18 	.globl _link_map
                             19 	.globl _is_taken
                             20 	.globl _seed
                             21 	.globl _GLOBAL_TIMER
                             22 	.globl _TIMER_MOVE
                             23 	.globl _marisa_palette
                             24 	.globl _f_LoadSprites
                             25 	.globl _f_MoveCharacter
                             26 	.globl _game_init
                             27 	.globl _interrupt_init
                             28 	.globl _timer_interrupt
                             29 ;--------------------------------------------------------
                             30 ;  ram data
                             31 ;--------------------------------------------------------
                             32 	.area _DATA
   0000                      33 _TIMER_MOVE::
   0000                      34 	.ds 1
   0001                      35 _GLOBAL_TIMER::
   0001                      36 	.ds 4
   0005                      37 _seed::
   0005                      38 	.ds 2
   0007                      39 _is_taken::
   0007                      40 	.ds 256
   0107                      41 _link_map::
   0107                      42 	.ds 256
   0207                      43 _CHAR_X::
   0207                      44 	.ds 1
   0208                      45 _CHAR_Y::
   0208                      46 	.ds 1
   0209                      47 _CHAR_LAST_ANIM::
   0209                      48 	.ds 1
   020A                      49 _CHAR_FRAME::
   020A                      50 	.ds 1
   020B                      51 _character_tiles::
   020B                      52 	.ds 256
                             53 ;--------------------------------------------------------
                             54 ; overlayable items in  ram 
                             55 ;--------------------------------------------------------
                             56 	.area _OVERLAY
                             57 ;--------------------------------------------------------
                             58 ; external initialized ram data
                             59 ;--------------------------------------------------------
                             60 ;--------------------------------------------------------
                             61 ; global & static initialisations
                             62 ;--------------------------------------------------------
                             63 	.area _HOME
                             64 	.area _GSINIT
                             65 	.area _GSFINAL
                             66 	.area _GSINIT
                             67 ;src/main.c:35: T_U08 character_tiles[] =
   403F 21 07 C3             68 	ld	hl,#_character_tiles
   4042 CD 62 09             69 	call	__initrleblock
   4045 02                   70 	.db	2
   4046 FF FF                71 	.db	0xFF, 0xFF
   4048 F8 80                72 	.db	#-8,#0x80
   404A 04                   73 	.db	4
   404B 83 83 8E 8E          74 	.db	0x83, 0x83, 0x8E, 0x8E
   404F F6 80                75 	.db	#-10,#0x80
   4051 0A                   76 	.db	10
   4052 8F 8F 80 80 80 80    77 	.db	0x8F, 0x8F, 0x80, 0x80, 0x80, 0x80, 0xFF, 0xFF
        FF FF
   405A FF FF                78 	.db	0xFF, 0xFF
   405C FA 01                79 	.db	#-6,#0x01
   405E FA C1                80 	.db	#-6,#0xC1
   4060 F8 81                81 	.db	#-8,#0x81
   4062 62                   82 	.db	98
   4063 BD BD E1 E1 01 01    83 	.db	0xBD, 0xBD, 0xE1, 0xE1, 0x01, 0x01, 0x01, 0x01
        01 01
   406B FF FF FF FF 80 80    84 	.db	0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0x80
        80 80
   4073 83 83 86 86 84 84    85 	.db	0x83, 0x83, 0x86, 0x86, 0x84, 0x84, 0x80, 0x80
        80 80
   407B 80 80 81 81 83 83    86 	.db	0x80, 0x80, 0x81, 0x81, 0x83, 0x83, 0x8E, 0x8E
        8E 8E
   4083 98 98 9F 9F 80 80    87 	.db	0x98, 0x98, 0x9F, 0x9F, 0x80, 0x80, 0x80, 0x80
        80 80
   408B FF FF FF FF 01 01    88 	.db	0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01
        01 01
   4093 81 81 C1 C1 41 41    89 	.db	0x81, 0x81, 0xC1, 0xC1, 0x41, 0x41, 0xC1, 0xC1
        C1 C1
   409B 81 81 81 81 01 01    90 	.db	0x81, 0x81, 0x81, 0x81, 0x01, 0x01, 0x01, 0x01
        01 01
   40A3 71 71 C1 C1 01 01    91 	.db	0x71, 0x71, 0xC1, 0xC1, 0x01, 0x01, 0x01, 0x01
        01 01
   40AB FF FF FF FF 80 80    92 	.db	0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0x80
        80 80
   40B3 87 87 84 84 80 80    93 	.db	0x87, 0x87, 0x84, 0x84, 0x80, 0x80, 0x80, 0x80
        80 80
   40BB 81 81 80 80 80 80    94 	.db	0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x88, 0x88
        88 88
   40C3 8F 8F                95 	.db	0x8F, 0x8F
   40C5 FA 80                96 	.db	#-6,#0x80
   40C7 1A                   97 	.db	26
   40C8 FF FF FF FF 01 01    98 	.db	0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01
        01 01
   40D0 E1 E1 21 21 61 61    99 	.db	0xE1, 0xE1, 0x21, 0x21, 0x61, 0x61, 0xE1, 0xE1
        E1 E1
   40D8 B1 B1 11 11 11 11   100 	.db	0xB1, 0xB1, 0x11, 0x11, 0x11, 0x11, 0x31, 0x31
        31 31
   40E0 E1 E1               101 	.db	0xE1, 0xE1
   40E2 FA 01               102 	.db	#-6,#0x01
   40E4 14                  103 	.db	20
   40E5 FF FF FF FF 80 80   104 	.db	0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0x80
        80 80
   40ED 81 81 87 87 8C 8C   105 	.db	0x81, 0x81, 0x87, 0x87, 0x8C, 0x8C, 0x98, 0x98
        98 98
   40F5 B0 B0 BF BF         106 	.db	0xB0, 0xB0, 0xBF, 0xBF
   40F9 F4 80               107 	.db	#-12,#0x80
   40FB 0A                  108 	.db	10
   40FC FF FF FF FF 01 01   109 	.db	0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0xC1, 0xC1
        C1 C1
   4104 C1 C1               110 	.db	0xC1, 0xC1
   4106 FA 41               111 	.db	#-6,#0x41
   4108 04                  112 	.db	4
   4109 71 71 C1 C1         113 	.db	0x71, 0x71, 0xC1, 0xC1
   410D FA 41               114 	.db	#-6,#0x41
   410F 08                  115 	.db	8
   4110 61 61 01 01 01 01   116 	.db	0x61, 0x61, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF
        FF FF
   4118 00                  117 	.db	0
                            118 ;--------------------------------------------------------
                            119 ; Home
                            120 ;--------------------------------------------------------
                            121 	.area _HOME
                            122 	.area _HOME
                            123 ;--------------------------------------------------------
                            124 ; code
                            125 ;--------------------------------------------------------
                            126 	.area _CODE
                            127 ;src/main.c:80: void main(void)
                            128 ;	---------------------------------
                            129 ; Function main
                            130 ; ---------------------------------
   0000                     131 _main:
                            132 	
                            133 ;src/main.c:82: game_init();
   042E CD 27 08            134 	call	_game_init
                            135 ;src/main.c:84: set_bkg_palette(0,5,area_tiles_palette);
   0431 21 7F 08            136 	ld	hl,#_area_tiles_palette
   0434 E5                  137 	push	hl
   0435 21 00 05            138 	ld	hl,#0x0500
   0438 E5                  139 	push	hl
   0439 CD 89 0A            140 	call	_set_bkg_palette
   043C E8 04               141 	lda	sp,4(sp)
                            142 ;src/main.c:85: set_bkg_data(0,5,area_tiles);
   043E 21 07 C4            143 	ld	hl,#_area_tiles
   0441 E5                  144 	push	hl
   0442 21 00 05            145 	ld	hl,#0x0500
   0445 E5                  146 	push	hl
   0446 CD A0 0B            147 	call	_set_bkg_data
   0449 E8 04               148 	lda	sp,4(sp)
                            149 ;src/main.c:87: CHAR_X 		= 64;
   044B 21 03 C3            150 	ld	hl,#_CHAR_X
   044E 36 40               151 	ld	(hl),#0x40
                            152 ;src/main.c:88: CHAR_Y		= 64;
   0450 21 04 C3            153 	ld	hl,#_CHAR_Y
   0453 36 40               154 	ld	(hl),#0x40
                            155 ;src/main.c:89: CHAR_LAST_ANIM	= 0;
   0455 21 05 C3            156 	ld	hl,#_CHAR_LAST_ANIM
   0458 36 00               157 	ld	(hl),#0x00
                            158 ;src/main.c:90: CHAR_FRAME  = 0;
   045A 21 06 C3            159 	ld	hl,#_CHAR_FRAME
   045D 36 00               160 	ld	(hl),#0x00
                            161 ;src/main.c:92: f_DisplayMap(map_room, metatiles);
   045F 21 A0 C0            162 	ld	hl,#_metatiles
   0462 E5                  163 	push	hl
   0463 21 AC C0            164 	ld	hl,#_map_room
   0466 E5                  165 	push	hl
   0467 CD BC 03            166 	call	_f_DisplayMap
   046A E8 04               167 	lda	sp,4(sp)
                            168 ;src/main.c:94: f_LoadSprites();
   046C CD 8D 04            169 	call	_f_LoadSprites
                            170 ;src/main.c:96: while(1){
   0041                     171 00102$:
                            172 ;src/main.c:97: f_MoveCharacter();
   046F CD B7 06            173 	call	_f_MoveCharacter
                            174 ;src/main.c:100: CHAR_LAST_ANIM++;
   0472 21 05 C3            175 	ld	hl,#_CHAR_LAST_ANIM
   0475 34                  176 	inc	(hl)
                            177 ;src/main.c:103: wait_vbl_done();
   0476 CD 88 02            178 	call	_wait_vbl_done
   0479 C3 6F 04            179 	jp	00102$
   004E                     180 00104$:
                            181 	
   047C C9                  182 ret
   004F                     183 _marisa_palette:
   047D 00 7C               184 	.dw #0x7C00
   047F FF 7F               185 	.dw #0x7FFF
   0481 C6 18               186 	.dw #0x18C6
   0483 00 00               187 	.dw #0x0000
   0485 00 7C               188 	.dw #0x7C00
   0487 9C 03               189 	.dw #0x039C
   0489 C6 18               190 	.dw #0x18C6
   048B 00 00               191 	.dw #0x0000
                            192 ;src/main.c:109: void f_LoadSprites(void)
                            193 ;	---------------------------------
                            194 ; Function f_LoadSprites
                            195 ; ---------------------------------
   005F                     196 _f_LoadSprites:
                            197 	
   048D F5                  198 	push	af
   048E 3B                  199 	dec	sp
                            200 ;src/main.c:112: SPRITES_8x8;
   048F F8 00               201 	lda	hl,0(sp)
   0491 36 40               202 	ld	(hl),#0x40
   0493 23                  203 	inc	hl
   0494 36 FF               204 	ld	(hl),#0xFF
   0496 01 40 FF            205 	ld	bc,#0xFF40
   0499 0A                  206 	ld	a,(bc)
   049A 4F                  207 	ld	c,a
   049B 06 00               208 	ld	b,#0x00
   049D 79                  209 	ld	a,c
   049E E6 FB               210 	and	a,#0xFB
   04A0 4F                  211 	ld	c,a
   04A1 06 00               212 	ld	b,#0x00
   04A3 79                  213 	ld	a,c
   04A4 2B                  214 	dec	hl
   04A5 5E                  215 	ld	e,(hl)
   04A6 23                  216 	inc	hl
   04A7 56                  217 	ld	d,(hl)
   04A8 12                  218 	ld	(de),a
                            219 ;src/main.c:114: for(k=0;k!=8;k++){
   04A9 23                  220 	inc	hl
   04AA 36 00               221 	ld	(hl),#0x00
   007E                     222 00101$:
   04AC F8 02               223 	lda	hl,2(sp)
   04AE 7E                  224 	ld	a,(hl)
   04AF D6 08               225 	sub	a,#0x08
   04B1 CA E7 04            226 	jp	Z,00104$
   0086                     227 00110$:
                            228 ;src/main.c:115: set_sprite_palette_entry((k>>2),k%4,character_tiles[k]);
   04B4 11 07 C3            229 	ld	de,#_character_tiles
   04B7 F8 02               230 	lda	hl,2(sp)
   04B9 6E                  231 	ld	l,(hl)
   04BA 26 00               232 	ld	h,#0x00
   04BC 19                  233 	add	hl,de
   04BD 4D                  234 	ld	c,l
   04BE 44                  235 	ld	b,h
   04BF 0A                  236 	ld	a,(bc)
   04C0 4F                  237 	ld	c,a
   04C1 F8 00               238 	lda	hl,0(sp)
   04C3 71                  239 	ld	(hl),c
   04C4 23                  240 	inc	hl
   04C5 36 00               241 	ld	(hl),#0x00
   04C7 23                  242 	inc	hl
   04C8 7E                  243 	ld	a,(hl)
   04C9 E6 03               244 	and	a,#0x03
   04CB 4F                  245 	ld	c,a
   04CC 46                  246 	ld	b,(hl)
   04CD CB 38               247 	srl	b
   04CF CB 38               248 	srl	b
   04D1 2B                  249 	dec	hl
   04D2 2B                  250 	dec	hl
   04D3 2A                  251 	ld	a,(hl+)
   04D4 66                  252 	ld	h,(hl)
   04D5 6F                  253 	ld	l,a
   04D6 E5                  254 	push	hl
   04D7 79                  255 	ld	a,c
   04D8 F5                  256 	push	af
   04D9 33                  257 	inc	sp
   04DA C5                  258 	push	bc
   04DB 33                  259 	inc	sp
   04DC CD CF 08            260 	call	_set_sprite_palette_entry
   04DF E8 04               261 	lda	sp,4(sp)
                            262 ;src/main.c:114: for(k=0;k!=8;k++){
   04E1 F8 02               263 	lda	hl,2(sp)
   04E3 34                  264 	inc	(hl)
   04E4 C3 AC 04            265 	jp	00101$
   00B9                     266 00104$:
                            267 ;src/main.c:118: set_data(0x8000,character_tiles,16);
   04E7 21 10 00            268 	ld	hl,#0x0010
   04EA E5                  269 	push	hl
   04EB 21 07 C3            270 	ld	hl,#_character_tiles
   04EE E5                  271 	push	hl
   04EF 21 00 80            272 	ld	hl,#0x8000
   04F2 E5                  273 	push	hl
   04F3 CD 22 0B            274 	call	_set_data
   04F6 E8 06               275 	lda	sp,6(sp)
                            276 ;src/main.c:119: set_data(0x8010,character_tiles+0x10U,16);
   04F8 01 17 C3            277 	ld	bc,#_character_tiles + 16
   04FB 21 10 00            278 	ld	hl,#0x0010
   04FE E5                  279 	push	hl
   04FF C5                  280 	push	bc
   0500 26 80               281 	ld	h, #0x80
   0502 E5                  282 	push	hl
   0503 CD 22 0B            283 	call	_set_data
   0506 E8 06               284 	lda	sp,6(sp)
                            285 ;src/main.c:120: set_data(0x8020,character_tiles+0x20U,16);
   0508 01 27 C3            286 	ld	bc,#_character_tiles + 32
   050B 21 10 00            287 	ld	hl,#0x0010
   050E E5                  288 	push	hl
   050F C5                  289 	push	bc
   0510 21 20 80            290 	ld	hl,#0x8020
   0513 E5                  291 	push	hl
   0514 CD 22 0B            292 	call	_set_data
   0517 E8 06               293 	lda	sp,6(sp)
                            294 ;src/main.c:121: set_data(0x8030,character_tiles+0x30U,16);
   0519 01 37 C3            295 	ld	bc,#_character_tiles + 48
   051C 21 10 00            296 	ld	hl,#0x0010
   051F E5                  297 	push	hl
   0520 C5                  298 	push	bc
   0521 21 30 80            299 	ld	hl,#0x8030
   0524 E5                  300 	push	hl
   0525 CD 22 0B            301 	call	_set_data
   0528 E8 06               302 	lda	sp,6(sp)
                            303 ;src/main.c:123: set_data(0x8040,character_tiles+0x40U,16);
   052A 01 47 C3            304 	ld	bc,#_character_tiles + 64
   052D 21 10 00            305 	ld	hl,#0x0010
   0530 E5                  306 	push	hl
   0531 C5                  307 	push	bc
   0532 21 40 80            308 	ld	hl,#0x8040
   0535 E5                  309 	push	hl
   0536 CD 22 0B            310 	call	_set_data
   0539 E8 06               311 	lda	sp,6(sp)
                            312 ;src/main.c:124: set_data(0x8050,character_tiles+0x50U,16);
   053B 01 57 C3            313 	ld	bc,#_character_tiles + 80
   053E 21 10 00            314 	ld	hl,#0x0010
   0541 E5                  315 	push	hl
   0542 C5                  316 	push	bc
   0543 21 50 80            317 	ld	hl,#0x8050
   0546 E5                  318 	push	hl
   0547 CD 22 0B            319 	call	_set_data
   054A E8 06               320 	lda	sp,6(sp)
                            321 ;src/main.c:125: set_data(0x8060,character_tiles+0x60U,16);
   054C 01 67 C3            322 	ld	bc,#_character_tiles + 96
   054F 21 10 00            323 	ld	hl,#0x0010
   0552 E5                  324 	push	hl
   0553 C5                  325 	push	bc
   0554 21 60 80            326 	ld	hl,#0x8060
   0557 E5                  327 	push	hl
   0558 CD 22 0B            328 	call	_set_data
   055B E8 06               329 	lda	sp,6(sp)
                            330 ;src/main.c:126: set_data(0x8070,character_tiles+0x70U,16);
   055D 01 77 C3            331 	ld	bc,#_character_tiles + 112
   0560 21 10 00            332 	ld	hl,#0x0010
   0563 E5                  333 	push	hl
   0564 C5                  334 	push	bc
   0565 21 70 80            335 	ld	hl,#0x8070
   0568 E5                  336 	push	hl
   0569 CD 22 0B            337 	call	_set_data
   056C E8 06               338 	lda	sp,6(sp)
                            339 ;src/main.c:128: set_data(0x8080,character_tiles+0x80U,16);
   056E 01 87 C3            340 	ld	bc,#_character_tiles + 128
   0571 21 10 00            341 	ld	hl,#0x0010
   0574 E5                  342 	push	hl
   0575 C5                  343 	push	bc
   0576 21 80 80            344 	ld	hl,#0x8080
   0579 E5                  345 	push	hl
   057A CD 22 0B            346 	call	_set_data
   057D E8 06               347 	lda	sp,6(sp)
                            348 ;src/main.c:129: set_data(0x8090,character_tiles+0x90U,16);
   057F 01 97 C3            349 	ld	bc,#_character_tiles + 144
   0582 21 10 00            350 	ld	hl,#0x0010
   0585 E5                  351 	push	hl
   0586 C5                  352 	push	bc
   0587 21 90 80            353 	ld	hl,#0x8090
   058A E5                  354 	push	hl
   058B CD 22 0B            355 	call	_set_data
   058E E8 06               356 	lda	sp,6(sp)
                            357 ;src/main.c:130: set_data(0x80A0,character_tiles+0xA0U,16);
   0590 01 A7 C3            358 	ld	bc,#_character_tiles + 160
   0593 21 10 00            359 	ld	hl,#0x0010
   0596 E5                  360 	push	hl
   0597 C5                  361 	push	bc
   0598 21 A0 80            362 	ld	hl,#0x80A0
   059B E5                  363 	push	hl
   059C CD 22 0B            364 	call	_set_data
   059F E8 06               365 	lda	sp,6(sp)
                            366 ;src/main.c:131: set_data(0x80B0,character_tiles+0xB0U,16);
   05A1 01 B7 C3            367 	ld	bc,#_character_tiles + 176
   05A4 21 10 00            368 	ld	hl,#0x0010
   05A7 E5                  369 	push	hl
   05A8 C5                  370 	push	bc
   05A9 21 B0 80            371 	ld	hl,#0x80B0
   05AC E5                  372 	push	hl
   05AD CD 22 0B            373 	call	_set_data
   05B0 E8 06               374 	lda	sp,6(sp)
                            375 ;src/main.c:133: set_data(0x80C0,character_tiles+0xC0U,16);
   05B2 01 C7 C3            376 	ld	bc,#_character_tiles + 192
   05B5 21 10 00            377 	ld	hl,#0x0010
   05B8 E5                  378 	push	hl
   05B9 C5                  379 	push	bc
   05BA 21 C0 80            380 	ld	hl,#0x80C0
   05BD E5                  381 	push	hl
   05BE CD 22 0B            382 	call	_set_data
   05C1 E8 06               383 	lda	sp,6(sp)
                            384 ;src/main.c:134: set_data(0x80D0,character_tiles+0xD0U,16);
   05C3 01 D7 C3            385 	ld	bc,#_character_tiles + 208
   05C6 21 10 00            386 	ld	hl,#0x0010
   05C9 E5                  387 	push	hl
   05CA C5                  388 	push	bc
   05CB 21 D0 80            389 	ld	hl,#0x80D0
   05CE E5                  390 	push	hl
   05CF CD 22 0B            391 	call	_set_data
   05D2 E8 06               392 	lda	sp,6(sp)
                            393 ;src/main.c:135: set_data(0x80E0,character_tiles+0xE0U,16);
   05D4 01 E7 C3            394 	ld	bc,#_character_tiles + 224
   05D7 21 10 00            395 	ld	hl,#0x0010
   05DA E5                  396 	push	hl
   05DB C5                  397 	push	bc
   05DC 21 E0 80            398 	ld	hl,#0x80E0
   05DF E5                  399 	push	hl
   05E0 CD 22 0B            400 	call	_set_data
   05E3 E8 06               401 	lda	sp,6(sp)
                            402 ;src/main.c:136: set_data(0x80F0,character_tiles+0xF0U,16);
   05E5 01 F7 C3            403 	ld	bc,#_character_tiles + 240
   05E8 21 10 00            404 	ld	hl,#0x0010
   05EB E5                  405 	push	hl
   05EC C5                  406 	push	bc
   05ED 21 F0 80            407 	ld	hl,#0x80F0
   05F0 E5                  408 	push	hl
   05F1 CD 22 0B            409 	call	_set_data
   05F4 E8 06               410 	lda	sp,6(sp)
                            411 ;src/main.c:138: set_sprite_tile(0,0);				// S0 is the first tile of the sprite VRAM
   05F6 21 00 00            412 	ld	hl,#0x0000
   05F9 E5                  413 	push	hl
   05FA CD 95 0B            414 	call	_set_sprite_tile
   05FD E8 02               415 	lda	sp,2(sp)
                            416 ;src/main.c:139: set_sprite_prop(0,0);				// S0 got palette 0
   05FF 21 00 00            417 	ld	hl,#0x0000
   0602 E5                  418 	push	hl
   0603 CD EC 0A            419 	call	_set_sprite_prop
   0606 E8 02               420 	lda	sp,2(sp)
                            421 ;src/main.c:140: move_sprite(0,CHAR_X,CHAR_Y);		// Move sprite to its initial position (given in level initialization)
   0608 21 04 C3            422 	ld	hl,#_CHAR_Y
   060B 7E                  423 	ld	a,(hl)
   060C F5                  424 	push	af
   060D 33                  425 	inc	sp
   060E 21 03 C3            426 	ld	hl,#_CHAR_X
   0611 7E                  427 	ld	a,(hl)
   0612 F5                  428 	push	af
   0613 33                  429 	inc	sp
   0614 3E 00               430 	ld	a,#0x00
   0616 F5                  431 	push	af
   0617 33                  432 	inc	sp
   0618 CD 06 0B            433 	call	_move_sprite
   061B E8 03               434 	lda	sp,3(sp)
                            435 ;src/main.c:141: set_sprite_tile(1,2);				// S1 is the second tile of the sprite VRAM
   061D 21 01 02            436 	ld	hl,#0x0201
   0620 E5                  437 	push	hl
   0621 CD 95 0B            438 	call	_set_sprite_tile
   0624 E8 02               439 	lda	sp,2(sp)
                            440 ;src/main.c:142: set_sprite_prop(1,0);				// S1 got palette 0
   0626 21 01 00            441 	ld	hl,#0x0001
   0629 E5                  442 	push	hl
   062A CD EC 0A            443 	call	_set_sprite_prop
   062D E8 02               444 	lda	sp,2(sp)
                            445 ;src/main.c:143: move_sprite(1,CHAR_X+8,CHAR_Y);		// etc...
   062F 21 03 C3            446 	ld	hl,#_CHAR_X
   0632 7E                  447 	ld	a,(hl)
   0633 C6 08               448 	add	a,#0x08
   0635 4F                  449 	ld	c,a
   0636 21 04 C3            450 	ld	hl,#_CHAR_Y
   0639 7E                  451 	ld	a,(hl)
   063A F5                  452 	push	af
   063B 33                  453 	inc	sp
   063C 41                  454 	ld	b,c
   063D 0E 01               455 	ld	c,#0x01
   063F C5                  456 	push	bc
   0640 CD 06 0B            457 	call	_move_sprite
   0643 E8 03               458 	lda	sp,3(sp)
                            459 ;src/main.c:144: set_sprite_tile(2,1);
   0645 21 02 01            460 	ld	hl,#0x0102
   0648 E5                  461 	push	hl
   0649 CD 95 0B            462 	call	_set_sprite_tile
   064C E8 02               463 	lda	sp,2(sp)
                            464 ;src/main.c:145: set_sprite_prop(2,0);
   064E 21 02 00            465 	ld	hl,#0x0002
   0651 E5                  466 	push	hl
   0652 CD EC 0A            467 	call	_set_sprite_prop
   0655 E8 02               468 	lda	sp,2(sp)
                            469 ;src/main.c:146: move_sprite(2,CHAR_X,CHAR_Y+8);
   0657 21 04 C3            470 	ld	hl,#_CHAR_Y
   065A 7E                  471 	ld	a,(hl)
   065B C6 08               472 	add	a,#0x08
   065D 4F                  473 	ld	c,a
   065E F5                  474 	push	af
   065F 33                  475 	inc	sp
   0660 21 03 C3            476 	ld	hl,#_CHAR_X
   0663 7E                  477 	ld	a,(hl)
   0664 F5                  478 	push	af
   0665 33                  479 	inc	sp
   0666 3E 02               480 	ld	a,#0x02
   0668 F5                  481 	push	af
   0669 33                  482 	inc	sp
   066A CD 06 0B            483 	call	_move_sprite
   066D E8 03               484 	lda	sp,3(sp)
                            485 ;src/main.c:147: set_sprite_tile(3,3);
   066F 21 03 03            486 	ld	hl,#0x0303
   0672 E5                  487 	push	hl
   0673 CD 95 0B            488 	call	_set_sprite_tile
   0676 E8 02               489 	lda	sp,2(sp)
                            490 ;src/main.c:148: set_sprite_prop(3,0);
   0678 21 03 00            491 	ld	hl,#0x0003
   067B E5                  492 	push	hl
   067C CD EC 0A            493 	call	_set_sprite_prop
   067F E8 02               494 	lda	sp,2(sp)
                            495 ;src/main.c:149: move_sprite(3,CHAR_X+8,CHAR_Y+8);
   0681 21 04 C3            496 	ld	hl,#_CHAR_Y
   0684 7E                  497 	ld	a,(hl)
   0685 C6 08               498 	add	a,#0x08
   0687 4F                  499 	ld	c,a
   0688 21 03 C3            500 	ld	hl,#_CHAR_X
   068B 7E                  501 	ld	a,(hl)
   068C C6 08               502 	add	a,#0x08
   068E 47                  503 	ld	b,a
   068F 79                  504 	ld	a,c
   0690 F5                  505 	push	af
   0691 33                  506 	inc	sp
   0692 C5                  507 	push	bc
   0693 33                  508 	inc	sp
   0694 3E 03               509 	ld	a,#0x03
   0696 F5                  510 	push	af
   0697 33                  511 	inc	sp
   0698 CD 06 0B            512 	call	_move_sprite
   069B E8 03               513 	lda	sp,3(sp)
                            514 ;src/main.c:151: SHOW_SPRITES;
   069D F8 00               515 	lda	hl,0(sp)
   069F 36 40               516 	ld	(hl),#0x40
   06A1 23                  517 	inc	hl
   06A2 36 FF               518 	ld	(hl),#0xFF
   06A4 01 40 FF            519 	ld	bc,#0xFF40
   06A7 0A                  520 	ld	a,(bc)
   06A8 4F                  521 	ld	c,a
   06A9 06 00               522 	ld	b,#0x00
   06AB 79                  523 	ld	a,c
   06AC F6 02               524 	or	a,#0x02
   06AE 4F                  525 	ld	c,a
   06AF 2B                  526 	dec	hl
   06B0 5E                  527 	ld	e,(hl)
   06B1 23                  528 	inc	hl
   06B2 56                  529 	ld	d,(hl)
   06B3 12                  530 	ld	(de),a
   0286                     531 00105$:
   06B4 E8 03               532 	lda	sp,3(sp)
   06B6 C9                  533 ret
                            534 ;src/main.c:154: void f_MoveCharacter(void)
                            535 ;	---------------------------------
                            536 ; Function f_MoveCharacter
                            537 ; ---------------------------------
   0289                     538 _f_MoveCharacter:
                            539 	
                            540 ;src/main.c:157: if(joypad() & J_RIGHT)
   06B7 CD 79 0B            541 	call	_joypad
   06BA 4B                  542 	ld	c,e
   06BB 06 00               543 	ld	b,#0x00
   06BD 79                  544 	ld	a,c
   06BE E6 01               545 	and	a,#0x01
   06C0 20 03               546 	jr	NZ,00133$
   06C2 C3 DB 06            547 	jp	00104$
   0297                     548 00133$:
                            549 ;src/main.c:159: CHAR_X++;
   06C5 21 03 C3            550 	ld	hl,#_CHAR_X
   06C8 34                  551 	inc	(hl)
                            552 ;src/main.c:160: if(CHAR_X==137) CHAR_X--;
   06C9 21 03 C3            553 	ld	hl,#_CHAR_X
   06CC 7E                  554 	ld	a,(hl)
   06CD D6 89               555 	sub	a,#0x89
   06CF C2 D4 06            556 	jp	NZ,00134$
   06D2 18 03               557 	jr	00135$
   02A6                     558 00134$:
   06D4 C3 DB 06            559 	jp	00104$
   02A9                     560 00135$:
   06D7 21 03 C3            561 	ld	hl,#_CHAR_X
   06DA 35                  562 	dec	(hl)
   02AD                     563 00104$:
                            564 ;src/main.c:162: if(joypad() & J_LEFT)
   06DB CD 79 0B            565 	call	_joypad
   06DE 4B                  566 	ld	c,e
   06DF 06 00               567 	ld	b,#0x00
   06E1 79                  568 	ld	a,c
   06E2 E6 02               569 	and	a,#0x02
   06E4 20 03               570 	jr	NZ,00136$
   06E6 C3 FF 06            571 	jp	00108$
   02BB                     572 00136$:
                            573 ;src/main.c:164: CHAR_X--;
   06E9 21 03 C3            574 	ld	hl,#_CHAR_X
   06EC 35                  575 	dec	(hl)
                            576 ;src/main.c:165: if(CHAR_X==23) CHAR_X++;
   06ED 21 03 C3            577 	ld	hl,#_CHAR_X
   06F0 7E                  578 	ld	a,(hl)
   06F1 D6 17               579 	sub	a,#0x17
   06F3 C2 F8 06            580 	jp	NZ,00137$
   06F6 18 03               581 	jr	00138$
   02CA                     582 00137$:
   06F8 C3 FF 06            583 	jp	00108$
   02CD                     584 00138$:
   06FB 21 03 C3            585 	ld	hl,#_CHAR_X
   06FE 34                  586 	inc	(hl)
   02D1                     587 00108$:
                            588 ;src/main.c:167: if(joypad() & J_UP)
   06FF CD 79 0B            589 	call	_joypad
   0702 4B                  590 	ld	c,e
   0703 06 00               591 	ld	b,#0x00
   0705 79                  592 	ld	a,c
   0706 E6 04               593 	and	a,#0x04
   0708 20 03               594 	jr	NZ,00139$
   070A C3 23 07            595 	jp	00112$
   02DF                     596 00139$:
                            597 ;src/main.c:169: CHAR_Y--;
   070D 21 04 C3            598 	ld	hl,#_CHAR_Y
   0710 35                  599 	dec	(hl)
                            600 ;src/main.c:170: if(CHAR_Y==31) CHAR_Y++;
   0711 21 04 C3            601 	ld	hl,#_CHAR_Y
   0714 7E                  602 	ld	a,(hl)
   0715 D6 1F               603 	sub	a,#0x1F
   0717 C2 1C 07            604 	jp	NZ,00140$
   071A 18 03               605 	jr	00141$
   02EE                     606 00140$:
   071C C3 23 07            607 	jp	00112$
   02F1                     608 00141$:
   071F 21 04 C3            609 	ld	hl,#_CHAR_Y
   0722 34                  610 	inc	(hl)
   02F5                     611 00112$:
                            612 ;src/main.c:172: if(joypad() & J_DOWN)
   0723 CD 79 0B            613 	call	_joypad
   0726 4B                  614 	ld	c,e
   0727 06 00               615 	ld	b,#0x00
   0729 79                  616 	ld	a,c
   072A E6 08               617 	and	a,#0x08
   072C 20 03               618 	jr	NZ,00142$
   072E C3 47 07            619 	jp	00116$
   0303                     620 00142$:
                            621 ;src/main.c:174: CHAR_Y++;
   0731 21 04 C3            622 	ld	hl,#_CHAR_Y
   0734 34                  623 	inc	(hl)
                            624 ;src/main.c:175: if(CHAR_Y==113) CHAR_Y--;
   0735 21 04 C3            625 	ld	hl,#_CHAR_Y
   0738 7E                  626 	ld	a,(hl)
   0739 D6 71               627 	sub	a,#0x71
   073B C2 40 07            628 	jp	NZ,00143$
   073E 18 03               629 	jr	00144$
   0312                     630 00143$:
   0740 C3 47 07            631 	jp	00116$
   0315                     632 00144$:
   0743 21 04 C3            633 	ld	hl,#_CHAR_Y
   0746 35                  634 	dec	(hl)
   0319                     635 00116$:
                            636 ;src/main.c:179: if(16U == CHAR_LAST_ANIM){
   0747 21 05 C3            637 	ld	hl,#_CHAR_LAST_ANIM
   074A 4E                  638 	ld	c,(hl)
   074B 06 00               639 	ld	b,#0x00
   074D 79                  640 	ld	a,c
   074E D6 10               641 	sub	a,#0x10
   0750 C2 59 07            642 	jp	NZ,00145$
   0753 B0                  643 	or	a,b
   0754 C2 59 07            644 	jp	NZ,00145$
   0757 18 03               645 	jr	00146$
   032B                     646 00145$:
   0759 C3 C7 07            647 	jp	00120$
   032E                     648 00146$:
                            649 ;src/main.c:180: CHAR_FRAME++;
   075C 21 06 C3            650 	ld	hl,#_CHAR_FRAME
   075F 34                  651 	inc	(hl)
                            652 ;src/main.c:181: if(4U == CHAR_FRAME){
   0760 21 06 C3            653 	ld	hl,#_CHAR_FRAME
   0763 4E                  654 	ld	c,(hl)
   0764 06 00               655 	ld	b,#0x00
   0766 79                  656 	ld	a,c
   0767 D6 04               657 	sub	a,#0x04
   0769 C2 72 07            658 	jp	NZ,00147$
   076C B0                  659 	or	a,b
   076D C2 72 07            660 	jp	NZ,00147$
   0770 18 03               661 	jr	00148$
   0344                     662 00147$:
   0772 C3 7A 07            663 	jp	00118$
   0347                     664 00148$:
                            665 ;src/main.c:182: CHAR_FRAME = 0U;
   0775 21 06 C3            666 	ld	hl,#_CHAR_FRAME
   0778 36 00               667 	ld	(hl),#0x00
   034C                     668 00118$:
                            669 ;src/main.c:185: set_sprite_tile(0,0+(CHAR_FRAME<<2));
   077A 21 06 C3            670 	ld	hl,#_CHAR_FRAME
   077D 7E                  671 	ld	a,(hl)
   077E 87                  672 	add	a,a
   077F 87                  673 	add	a,a
   0780 4F                  674 	ld	c,a
   0781 F5                  675 	push	af
   0782 33                  676 	inc	sp
   0783 3E 00               677 	ld	a,#0x00
   0785 F5                  678 	push	af
   0786 33                  679 	inc	sp
   0787 CD 95 0B            680 	call	_set_sprite_tile
   078A E8 02               681 	lda	sp,2(sp)
                            682 ;src/main.c:186: set_sprite_tile(1,2+(CHAR_FRAME<<2));
   078C 21 06 C3            683 	ld	hl,#_CHAR_FRAME
   078F 7E                  684 	ld	a,(hl)
   0790 87                  685 	add	a,a
   0791 87                  686 	add	a,a
   0792 4F                  687 	ld	c,a
   0793 0C                  688 	inc	c
   0794 0C                  689 	inc	c
   0795 41                  690 	ld	b,c
   0796 0E 01               691 	ld	c,#0x01
   0798 C5                  692 	push	bc
   0799 CD 95 0B            693 	call	_set_sprite_tile
   079C E8 02               694 	lda	sp,2(sp)
                            695 ;src/main.c:187: set_sprite_tile(2,1+(CHAR_FRAME<<2));
   079E 21 06 C3            696 	ld	hl,#_CHAR_FRAME
   07A1 7E                  697 	ld	a,(hl)
   07A2 87                  698 	add	a,a
   07A3 87                  699 	add	a,a
   07A4 4F                  700 	ld	c,a
   07A5 0C                  701 	inc	c
   07A6 41                  702 	ld	b,c
   07A7 0E 02               703 	ld	c,#0x02
   07A9 C5                  704 	push	bc
   07AA CD 95 0B            705 	call	_set_sprite_tile
   07AD E8 02               706 	lda	sp,2(sp)
                            707 ;src/main.c:188: set_sprite_tile(3,3+(CHAR_FRAME<<2));
   07AF 21 06 C3            708 	ld	hl,#_CHAR_FRAME
   07B2 7E                  709 	ld	a,(hl)
   07B3 87                  710 	add	a,a
   07B4 87                  711 	add	a,a
   07B5 4F                  712 	ld	c,a
   07B6 0C                  713 	inc	c
   07B7 0C                  714 	inc	c
   07B8 0C                  715 	inc	c
   07B9 41                  716 	ld	b,c
   07BA 0E 03               717 	ld	c,#0x03
   07BC C5                  718 	push	bc
   07BD CD 95 0B            719 	call	_set_sprite_tile
   07C0 E8 02               720 	lda	sp,2(sp)
                            721 ;src/main.c:191: CHAR_LAST_ANIM = 0U;
   07C2 21 05 C3            722 	ld	hl,#_CHAR_LAST_ANIM
   07C5 36 00               723 	ld	(hl),#0x00
   0399                     724 00120$:
                            725 ;src/main.c:195: move_sprite(0,CHAR_X,CHAR_Y);
   07C7 21 04 C3            726 	ld	hl,#_CHAR_Y
   07CA 7E                  727 	ld	a,(hl)
   07CB F5                  728 	push	af
   07CC 33                  729 	inc	sp
   07CD 21 03 C3            730 	ld	hl,#_CHAR_X
   07D0 7E                  731 	ld	a,(hl)
   07D1 F5                  732 	push	af
   07D2 33                  733 	inc	sp
   07D3 3E 00               734 	ld	a,#0x00
   07D5 F5                  735 	push	af
   07D6 33                  736 	inc	sp
   07D7 CD 06 0B            737 	call	_move_sprite
   07DA E8 03               738 	lda	sp,3(sp)
                            739 ;src/main.c:196: move_sprite(1,CHAR_X+8,CHAR_Y);
   07DC 21 03 C3            740 	ld	hl,#_CHAR_X
   07DF 7E                  741 	ld	a,(hl)
   07E0 C6 08               742 	add	a,#0x08
   07E2 4F                  743 	ld	c,a
   07E3 21 04 C3            744 	ld	hl,#_CHAR_Y
   07E6 7E                  745 	ld	a,(hl)
   07E7 F5                  746 	push	af
   07E8 33                  747 	inc	sp
   07E9 41                  748 	ld	b,c
   07EA 0E 01               749 	ld	c,#0x01
   07EC C5                  750 	push	bc
   07ED CD 06 0B            751 	call	_move_sprite
   07F0 E8 03               752 	lda	sp,3(sp)
                            753 ;src/main.c:197: move_sprite(2,CHAR_X,CHAR_Y+8);
   07F2 21 04 C3            754 	ld	hl,#_CHAR_Y
   07F5 7E                  755 	ld	a,(hl)
   07F6 C6 08               756 	add	a,#0x08
   07F8 4F                  757 	ld	c,a
   07F9 F5                  758 	push	af
   07FA 33                  759 	inc	sp
   07FB 21 03 C3            760 	ld	hl,#_CHAR_X
   07FE 7E                  761 	ld	a,(hl)
   07FF F5                  762 	push	af
   0800 33                  763 	inc	sp
   0801 3E 02               764 	ld	a,#0x02
   0803 F5                  765 	push	af
   0804 33                  766 	inc	sp
   0805 CD 06 0B            767 	call	_move_sprite
   0808 E8 03               768 	lda	sp,3(sp)
                            769 ;src/main.c:198: move_sprite(3,CHAR_X+8,CHAR_Y+8);
   080A 21 04 C3            770 	ld	hl,#_CHAR_Y
   080D 7E                  771 	ld	a,(hl)
   080E C6 08               772 	add	a,#0x08
   0810 4F                  773 	ld	c,a
   0811 21 03 C3            774 	ld	hl,#_CHAR_X
   0814 7E                  775 	ld	a,(hl)
   0815 C6 08               776 	add	a,#0x08
   0817 47                  777 	ld	b,a
   0818 79                  778 	ld	a,c
   0819 F5                  779 	push	af
   081A 33                  780 	inc	sp
   081B C5                  781 	push	bc
   081C 33                  782 	inc	sp
   081D 3E 03               783 	ld	a,#0x03
   081F F5                  784 	push	af
   0820 33                  785 	inc	sp
   0821 CD 06 0B            786 	call	_move_sprite
   0824 E8 03               787 	lda	sp,3(sp)
   03F8                     788 00121$:
                            789 	
   0826 C9                  790 ret
                            791 ;src/main.c:201: void game_init(void)
                            792 ;	---------------------------------
                            793 ; Function game_init
                            794 ; ---------------------------------
   03F9                     795 _game_init:
                            796 	
                            797 ;src/main.c:203: GLOBAL_TIMER = 0;
   0827 AF                  798 	xor	a,a
   0828 21 FD C0            799 	ld	hl,#_GLOBAL_TIMER
   082B 77                  800 	ld	(hl),a
   082C 21 FE C0            801 	ld	hl,#_GLOBAL_TIMER + 1
   082F 77                  802 	ld	(hl),a
   0830 21 FF C0            803 	ld	hl,#_GLOBAL_TIMER + 2
   0833 77                  804 	ld	(hl),a
   0834 21 00 C1            805 	ld	hl,#_GLOBAL_TIMER + 3
   0837 77                  806 	ld	(hl),a
                            807 ;src/main.c:204: TAC_REG = 0x07U;
   0838 01 07 FF            808 	ld	bc,#0xFF07
   083B 3E 07               809 	ld	a,#0x07
   083D 02                  810 	ld	(bc),a
                            811 ;src/main.c:206: interrupt_init();
   083E CD 42 08            812 	call	_interrupt_init
   0413                     813 00101$:
                            814 	
   0841 C9                  815 ret
                            816 ;src/main.c:209: void interrupt_init(void)
                            817 ;	---------------------------------
                            818 ; Function interrupt_init
                            819 ; ---------------------------------
   0414                     820 _interrupt_init:
                            821 	
                            822 ;src/main.c:211: disable_interrupts();
   0842 CD FD 02            823 	call	_disable_interrupts
                            824 ;src/main.c:212: add_TIM(timer_interrupt);
   0845 21 64 08            825 	ld	hl,#_timer_interrupt
   0848 E5                  826 	push	hl
   0849 CD 6C 03            827 	call	_add_TIM
   084C E8 02               828 	lda	sp,2(sp)
                            829 ;src/main.c:213: add_VBL(timer_interrupt);
   084E 21 64 08            830 	ld	hl,#_timer_interrupt
   0851 E5                  831 	push	hl
   0852 CD 56 03            832 	call	_add_VBL
   0855 E8 02               833 	lda	sp,2(sp)
                            834 ;src/main.c:214: enable_interrupts();
   0857 CD 06 03            835 	call	_enable_interrupts
                            836 ;src/main.c:216: set_interrupts(VBL_IFLAG | TIM_IFLAG);
   085A 3E 05               837 	ld	a,#0x05
   085C F5                  838 	push	af
   085D 33                  839 	inc	sp
   085E CD 10 03            840 	call	_set_interrupts
   0861 E8 01               841 	lda	sp,1(sp)
   0435                     842 00101$:
                            843 	
   0863 C9                  844 ret
                            845 ;src/main.c:219: void timer_interrupt(void)
                            846 ;	---------------------------------
                            847 ; Function timer_interrupt
                            848 ; ---------------------------------
   0436                     849 _timer_interrupt:
                            850 	
                            851 ;src/main.c:221: GLOBAL_TIMER++;
   0864 21 FD C0            852 	ld	hl,#_GLOBAL_TIMER
   0867 34                  853 	inc	(hl)
   0868 20 10               854 	jr	NZ,00103$
   086A 21 FE C0            855 	ld	hl,#_GLOBAL_TIMER + 1
   086D 34                  856 	inc	(hl)
   086E 20 0A               857 	jr	NZ,00103$
   0870 21 FF C0            858 	ld	hl,#_GLOBAL_TIMER + 2
   0873 34                  859 	inc	(hl)
   0874 20 04               860 	jr	NZ,00103$
   0876 21 00 C1            861 	ld	hl,#_GLOBAL_TIMER + 3
   0879 34                  862 	inc	(hl)
   044C                     863 00103$:
                            864 ;src/main.c:222: TIMER_MOVE++;
   087A 21 FC C0            865 	ld	hl,#_TIMER_MOVE
   087D 34                  866 	inc	(hl)
   0450                     867 00101$:
                            868 	
   087E C9                  869 ret
                            870 	.area _CODE
                            871 	.area _CABS
