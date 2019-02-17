                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Apr  7 2010) (MINGW32)
                              4 ; This file was generated Sun Feb 10 22:27:00 2019
                              5 ;--------------------------------------------------------
                              6 	.module map
                              7 	.optsdcc -mgbz80
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _f_DisplayMap
                             13 ;--------------------------------------------------------
                             14 ;  ram data
                             15 ;--------------------------------------------------------
                             16 	.area _DATA
                             17 ;--------------------------------------------------------
                             18 ; overlayable items in  ram 
                             19 ;--------------------------------------------------------
                             20 	.area _OVERLAY
                             21 ;--------------------------------------------------------
                             22 ; external initialized ram data
                             23 ;--------------------------------------------------------
                             24 ;--------------------------------------------------------
                             25 ; global & static initialisations
                             26 ;--------------------------------------------------------
                             27 	.area _HOME
                             28 	.area _GSINIT
                             29 	.area _GSFINAL
                             30 	.area _GSINIT
                             31 ;--------------------------------------------------------
                             32 ; Home
                             33 ;--------------------------------------------------------
                             34 	.area _HOME
                             35 	.area _HOME
                             36 ;--------------------------------------------------------
                             37 ; code
                             38 ;--------------------------------------------------------
                             39 	.area _CODE
                             40 ;src/map.c:21: void f_DisplayMap(
                             41 ;	---------------------------------
                             42 ; Function f_DisplayMap
                             43 ; ---------------------------------
   0000                      44 _f_DisplayMap:
                             45 	
   03BC F5                   46 	push	af
   03BD F5                   47 	push	af
                             48 ;src/map.c:30: i = 0;
   03BE F8 03                49 	lda	hl,3(sp)
   03C0 36 00                50 	ld	(hl),#0x00
                             51 ;src/map.c:33: pointerOnMap = mapAddress;
   03C2 F8 06                52 	lda	hl,6(sp)
   03C4 4E                   53 	ld	c,(hl)
   03C5 23                   54 	inc	hl
   03C6 46                   55 	ld	b,(hl)
                             56 ;src/map.c:35: while(j != _DungeonMapHeight)
   03C7 F8 00                57 	lda	hl,0(sp)
   03C9 71                   58 	ld	(hl),c
   03CA 23                   59 	inc	hl
   03CB 70                   60 	ld	(hl),b
   03CC 23                   61 	inc	hl
   03CD 36 00                62 	ld	(hl),#0x00
   0013                      63 00103$:
   03CF F8 02                64 	lda	hl,2(sp)
   03D1 7E                   65 	ld	a,(hl)
   03D2 D6 10                66 	sub	a,#0x10
   03D4 CA 2B 04             67 	jp	Z,00106$
   001B                      68 00112$:
                             69 ;src/map.c:37: set_bkg_tiles(i, j, 2, 2, (metaTileAddress + *(pointerOnMap)*4));
   03D7 F8 00                70 	lda	hl,0(sp)
   03D9 5E                   71 	ld	e,(hl)
   03DA 23                   72 	inc	hl
   03DB 56                   73 	ld	d,(hl)
   03DC 1A                   74 	ld	a,(de)
   03DD 47                   75 	ld	b,a
   03DE 48                   76 	ld	c,b
   03DF 06 00                77 	ld	b,#0x00
   03E1 CB 21                78 	sla	c
   03E3 CB 10                79 	rl	b
   03E5 CB 21                80 	sla	c
   03E7 CB 10                81 	rl	b
   03E9 F8 08                82 	lda	hl,8(sp)
   03EB 2A                   83 	ld	a,(hl+)
   03EC 66                   84 	ld	h,(hl)
   03ED 6F                   85 	ld	l,a
   03EE 09                   86 	add	hl,bc
   03EF 4D                   87 	ld	c,l
   03F0 44                   88 	ld	b,h
   03F1 C5                   89 	push	bc
   03F2 21 02 02             90 	ld	hl,#0x0202
   03F5 E5                   91 	push	hl
   03F6 F8 06                92 	lda	hl,6(sp)
   03F8 7E                   93 	ld	a,(hl)
   03F9 F5                   94 	push	af
   03FA 33                   95 	inc	sp
   03FB 23                   96 	inc	hl
   03FC 7E                   97 	ld	a,(hl)
   03FD F5                   98 	push	af
   03FE 33                   99 	inc	sp
   03FF CD 12 08            100 	call	_set_bkg_tiles
   0402 E8 06               101 	lda	sp,6(sp)
                            102 ;src/map.c:39: pointerOnMap++;
   0404 F8 00               103 	lda	hl,0(sp)
   0406 34                  104 	inc	(hl)
   0407 20 02               105 	jr	NZ,00115$
   0409 23                  106 	inc	hl
   040A 34                  107 	inc	(hl)
   004F                     108 00115$:
                            109 ;src/map.c:40: i += 2;
   040B F8 03               110 	lda	hl,3(sp)
   040D 34                  111 	inc	(hl)
   040E 34                  112 	inc	(hl)
                            113 ;src/map.c:41: if(i%_DungeonMapWidth == 0)
   040F 3E 14               114 	ld	a,#0x14
   0411 F5                  115 	push	af
   0412 33                  116 	inc	sp
   0413 7E                  117 	ld	a,(hl)
   0414 F5                  118 	push	af
   0415 33                  119 	inc	sp
   0416 CD 6C 06            120 	call	__moduchar_rrx_s
   0419 E8 02               121 	lda	sp,2(sp)
   041B 4B                  122 	ld	c,e
   041C AF                  123 	xor	a,a
   041D B1                  124 	or	a,c
   041E C2 CF 03            125 	jp	NZ,00103$
                            126 ;src/map.c:43: i = 0;
   0421 F8 03               127 	lda	hl,3(sp)
   0423 36 00               128 	ld	(hl),#0x00
                            129 ;src/map.c:44: j += 2;
   0425 2B                  130 	dec	hl
   0426 34                  131 	inc	(hl)
   0427 34                  132 	inc	(hl)
   0428 C3 CF 03            133 	jp	00103$
   006F                     134 00106$:
   042B E8 04               135 	lda	sp,4(sp)
   042D C9                  136 ret
                            137 	.area _CODE
                            138 	.area _CABS
