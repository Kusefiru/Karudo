                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Apr  7 2010) (MINGW32)
                              4 ; This file was generated Sun Feb 10 22:24:29 2019
                              5 ;--------------------------------------------------------
                              6 	.module main
                              7 	.optsdcc -mgbz80
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _link_map
                             14 	.globl _is_taken
                             15 	.globl _seed
                             16 	.globl _GLOBAL_TIMER
                             17 	.globl _TIMER_MOVE
                             18 	.globl _display_map
                             19 	.globl _game_init
                             20 	.globl _interrupt_init
                             21 	.globl _timer_interrupt
                             22 ;--------------------------------------------------------
                             23 ;  ram data
                             24 ;--------------------------------------------------------
                             25 	.area _DATA
   0000                      26 _TIMER_MOVE::
   0000                      27 	.ds 1
   0001                      28 _GLOBAL_TIMER::
   0001                      29 	.ds 4
   0005                      30 _seed::
   0005                      31 	.ds 2
   0007                      32 _is_taken::
   0007                      33 	.ds 256
   0107                      34 _link_map::
   0107                      35 	.ds 256
                             36 ;--------------------------------------------------------
                             37 ; overlayable items in  ram 
                             38 ;--------------------------------------------------------
                             39 	.area _OVERLAY
                             40 ;--------------------------------------------------------
                             41 ; external initialized ram data
                             42 ;--------------------------------------------------------
                             43 ;--------------------------------------------------------
                             44 ; global & static initialisations
                             45 ;--------------------------------------------------------
                             46 	.area _HOME
                             47 	.area _GSINIT
                             48 	.area _GSFINAL
                             49 	.area _GSINIT
                             50 ;--------------------------------------------------------
                             51 ; Home
                             52 ;--------------------------------------------------------
                             53 	.area _HOME
                             54 	.area _HOME
                             55 ;--------------------------------------------------------
                             56 ; code
                             57 ;--------------------------------------------------------
                             58 	.area _CODE
                             59 ;src/main.c:28: void main(void)
                             60 ;	---------------------------------
                             61 ; Function main
                             62 ; ---------------------------------
   0000                      63 _main:
                             64 	
                             65 ;src/main.c:30: game_init();
   042E CD BC 04             66 	call	_game_init
                             67 ;src/main.c:32: set_bkg_palette(0,5,area_tiles_palette);
   0431 21 14 05             68 	ld	hl,#_area_tiles_palette
   0434 E5                   69 	push	hl
   0435 21 00 05             70 	ld	hl,#0x0500
   0438 E5                   71 	push	hl
   0439 CD 1E 07             72 	call	_set_bkg_palette
   043C E8 04                73 	lda	sp,4(sp)
                             74 ;src/main.c:33: set_bkg_data(0,5,area_tiles);
   043E 21 03 C3             75 	ld	hl,#_area_tiles
   0441 E5                   76 	push	hl
   0442 21 00 05             77 	ld	hl,#0x0500
   0445 E5                   78 	push	hl
   0446 CD 74 07             79 	call	_set_bkg_data
   0449 E8 04                80 	lda	sp,4(sp)
                             81 ;src/main.c:35: f_DisplayMap(map_room, metatiles);
   044B 21 A0 C0             82 	ld	hl,#_metatiles
   044E E5                   83 	push	hl
   044F 21 AC C0             84 	ld	hl,#_map_room
   0452 E5                   85 	push	hl
   0453 CD BC 03             86 	call	_f_DisplayMap
   0456 E8 04                87 	lda	sp,4(sp)
   002A                      88 00101$:
                             89 	
   0458 C9                   90 ret
                             91 ;src/main.c:40: void display_map(void)
                             92 ;	---------------------------------
                             93 ; Function display_map
                             94 ; ---------------------------------
   002B                      95 _display_map:
                             96 	
   0459 F5                   97 	push	af
                             98 ;src/main.c:42: set_bkg_palette(0,5,area_tiles_palette);
   045A 21 14 05             99 	ld	hl,#_area_tiles_palette
   045D E5                  100 	push	hl
   045E 21 00 05            101 	ld	hl,#0x0500
   0461 E5                  102 	push	hl
   0462 CD 1E 07            103 	call	_set_bkg_palette
   0465 E8 04               104 	lda	sp,4(sp)
                            105 ;src/main.c:43: set_bkg_data(0,5,area_tiles);
   0467 21 03 C3            106 	ld	hl,#_area_tiles
   046A E5                  107 	push	hl
   046B 21 00 05            108 	ld	hl,#0x0500
   046E E5                  109 	push	hl
   046F CD 74 07            110 	call	_set_bkg_data
   0472 E8 04               111 	lda	sp,4(sp)
                            112 ;src/main.c:45: VBK_REG = 1;
   0474 01 4F FF            113 	ld	bc,#0xFF4F
   0477 3E 01               114 	ld	a,#0x01
   0479 02                  115 	ld	(bc),a
                            116 ;src/main.c:46: set_bkg_tiles(0, 0, _DungeonMapWidth, _DungeonMapHeight, map_room);
   047A 21 AC C0            117 	ld	hl,#_map_room
   047D E5                  118 	push	hl
   047E 21 14 10            119 	ld	hl,#0x1014
   0481 E5                  120 	push	hl
   0482 21 00 00            121 	ld	hl,#0x0000
   0485 E5                  122 	push	hl
   0486 CD 12 08            123 	call	_set_bkg_tiles
   0489 E8 06               124 	lda	sp,6(sp)
                            125 ;src/main.c:47: VBK_REG = 0;
   048B 01 4F FF            126 	ld	bc,#0xFF4F
   048E 3E 00               127 	ld	a,#0x00
   0490 02                  128 	ld	(bc),a
                            129 ;src/main.c:48: set_bkg_tiles(0, 0, _DungeonMapWidth, _DungeonMapHeight, map_room);
   0491 21 AC C0            130 	ld	hl,#_map_room
   0494 E5                  131 	push	hl
   0495 21 14 10            132 	ld	hl,#0x1014
   0498 E5                  133 	push	hl
   0499 21 00 00            134 	ld	hl,#0x0000
   049C E5                  135 	push	hl
   049D CD 12 08            136 	call	_set_bkg_tiles
   04A0 E8 06               137 	lda	sp,6(sp)
                            138 ;src/main.c:49: SHOW_BKG;
   04A2 F8 00               139 	lda	hl,0(sp)
   04A4 36 40               140 	ld	(hl),#0x40
   04A6 23                  141 	inc	hl
   04A7 36 FF               142 	ld	(hl),#0xFF
   04A9 01 40 FF            143 	ld	bc,#0xFF40
   04AC 0A                  144 	ld	a,(bc)
   04AD 4F                  145 	ld	c,a
   04AE 06 00               146 	ld	b,#0x00
   04B0 79                  147 	ld	a,c
   04B1 F6 01               148 	or	a,#0x01
   04B3 4F                  149 	ld	c,a
   04B4 2B                  150 	dec	hl
   04B5 5E                  151 	ld	e,(hl)
   04B6 23                  152 	inc	hl
   04B7 56                  153 	ld	d,(hl)
   04B8 12                  154 	ld	(de),a
   008B                     155 00101$:
   04B9 E8 02               156 	lda	sp,2(sp)
   04BB C9                  157 ret
                            158 ;src/main.c:53: void game_init(void)
                            159 ;	---------------------------------
                            160 ; Function game_init
                            161 ; ---------------------------------
   008E                     162 _game_init:
                            163 	
                            164 ;src/main.c:55: GLOBAL_TIMER = 0;
   04BC AF                  165 	xor	a,a
   04BD 21 FD C0            166 	ld	hl,#_GLOBAL_TIMER
   04C0 77                  167 	ld	(hl),a
   04C1 21 FE C0            168 	ld	hl,#_GLOBAL_TIMER + 1
   04C4 77                  169 	ld	(hl),a
   04C5 21 FF C0            170 	ld	hl,#_GLOBAL_TIMER + 2
   04C8 77                  171 	ld	(hl),a
   04C9 21 00 C1            172 	ld	hl,#_GLOBAL_TIMER + 3
   04CC 77                  173 	ld	(hl),a
                            174 ;src/main.c:56: TAC_REG = 0x07U;
   04CD 01 07 FF            175 	ld	bc,#0xFF07
   04D0 3E 07               176 	ld	a,#0x07
   04D2 02                  177 	ld	(bc),a
                            178 ;src/main.c:58: interrupt_init();
   04D3 CD D7 04            179 	call	_interrupt_init
   00A8                     180 00101$:
                            181 	
   04D6 C9                  182 ret
                            183 ;src/main.c:61: void interrupt_init(void)
                            184 ;	---------------------------------
                            185 ; Function interrupt_init
                            186 ; ---------------------------------
   00A9                     187 _interrupt_init:
                            188 	
                            189 ;src/main.c:63: disable_interrupts();
   04D7 CD FD 02            190 	call	_disable_interrupts
                            191 ;src/main.c:64: add_TIM(timer_interrupt);
   04DA 21 F9 04            192 	ld	hl,#_timer_interrupt
   04DD E5                  193 	push	hl
   04DE CD 6C 03            194 	call	_add_TIM
   04E1 E8 02               195 	lda	sp,2(sp)
                            196 ;src/main.c:65: add_VBL(timer_interrupt);
   04E3 21 F9 04            197 	ld	hl,#_timer_interrupt
   04E6 E5                  198 	push	hl
   04E7 CD 56 03            199 	call	_add_VBL
   04EA E8 02               200 	lda	sp,2(sp)
                            201 ;src/main.c:66: enable_interrupts();
   04EC CD 06 03            202 	call	_enable_interrupts
                            203 ;src/main.c:68: set_interrupts(VBL_IFLAG | TIM_IFLAG);
   04EF 3E 05               204 	ld	a,#0x05
   04F1 F5                  205 	push	af
   04F2 33                  206 	inc	sp
   04F3 CD 10 03            207 	call	_set_interrupts
   04F6 E8 01               208 	lda	sp,1(sp)
   00CA                     209 00101$:
                            210 	
   04F8 C9                  211 ret
                            212 ;src/main.c:71: void timer_interrupt(void)
                            213 ;	---------------------------------
                            214 ; Function timer_interrupt
                            215 ; ---------------------------------
   00CB                     216 _timer_interrupt:
                            217 	
                            218 ;src/main.c:73: GLOBAL_TIMER++;
   04F9 21 FD C0            219 	ld	hl,#_GLOBAL_TIMER
   04FC 34                  220 	inc	(hl)
   04FD 20 10               221 	jr	NZ,00103$
   04FF 21 FE C0            222 	ld	hl,#_GLOBAL_TIMER + 1
   0502 34                  223 	inc	(hl)
   0503 20 0A               224 	jr	NZ,00103$
   0505 21 FF C0            225 	ld	hl,#_GLOBAL_TIMER + 2
   0508 34                  226 	inc	(hl)
   0509 20 04               227 	jr	NZ,00103$
   050B 21 00 C1            228 	ld	hl,#_GLOBAL_TIMER + 3
   050E 34                  229 	inc	(hl)
   00E1                     230 00103$:
                            231 ;src/main.c:74: TIMER_MOVE++;
   050F 21 FC C0            232 	ld	hl,#_TIMER_MOVE
   0512 34                  233 	inc	(hl)
   00E5                     234 00101$:
                            235 	
   0513 C9                  236 ret
                            237 	.area _CODE
                            238 	.area _CABS
