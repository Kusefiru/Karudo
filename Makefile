#===============================================#
# Karudo project makefile					    #
#                                               #
#===============================================#

.PHONY: clean

#===============================================#
# Data software
SOFTNAME = Karudo
VERSION = 0.0.1

#===============================================#
# Dossiers
SDCCDIR = "D:\devlog\SDCC-2.9"
GBDKDIR = "D:\devlog\GBDK-3.0"
CRTDIR = $(GBDKDIR)/lib/crt0.o
OBJDIR = ./obj
SRCDIR = ./src
ASMDIR = $(SRCDIR)/asm
INCDIR = $(SRCDIR)/include

#===============================================#
# Localisation des includes
INCLUDE = -I$(GBDKDIR)/include          \
            -I$(SDCCDIR)/device/include    \
            -I$(INCDIR)
LNKINC = -l$(GBDKDIR)/lib/gbdk.lib      \
            -l$(SDCCDIR)/device/lib/build/gbz80/gbz80.lib

#===============================================#
# Compilateurs et flags
CC = $(SDCCDIR)/bin/sdcc.bat
CCFLAGS = -c -o
AS = $(SDCCDIR)/bin/as-gbz80
ASFLAGS = -lpo
LINK = $(SDCCDIR)/bin/link-gbz80
LINKFLAGS = -- -m -u -b_CODE=0x200 -b_DATA=0xc0a0 -yo4 -yt1

#===============================================#
# Directives de compilation
$(OBJDIR)/%.o: $(SRCDIR)/%.c
    $(CC) $(CCFLAGS) $(INCLUDE) $@ $<

$(OBJDIR)/%.o: $(ASMDIR)/%.s
    $(AS) $(ASFLAGS) $@ $<

#===============================================#
# Directive de clean
clean:
    rm -f *.gb
    rm -f $(OBJDIR)/*