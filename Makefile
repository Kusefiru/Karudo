#===============================================#
# Karudo project makefile					    #
#                                               #
#===============================================#

.PHONY: clean

#===============================================#
# Data software
SOFTNAME = Karudo
VERSION = 0.0.1
GBFILE = $(SOFTNAME)-$(VERSION).gb

#===============================================#
# Dossiers
SDCCDIR = "D:\devlog\SDCC-2.9"
GBDKDIR = "D:\devlog\GBDK-3.0"
CRTDIR = $(GBDKDIR)/lib/crt0.o
OBJDIR = obj
SRCDIR = src
ASMDIR = $(SRCDIR)/asm
INCDIR = $(SRCDIR)/include

#===============================================#
# Localisation des includes
INCLUDE = -I$(GBDKDIR)/include          \
			-I$(SDCCDIR)/device/include \
			-I$(INCDIR)
LNKINC = -l$(GBDKDIR)/lib/gbdk.lib      \
			-l$(SDCCDIR)/device/lib/build/gbz80/gbz80.lib

#===============================================#
# Compilateurs et flags
CC = $(SDCCDIR)/bin/sdcc.bat
CCFLAGS = $(INCLUDE)
AS = $(SDCCDIR)/bin/as-gbz80
ASFLAGS = -lpo
LINK = $(SDCCDIR)/bin/link-gbz80 -- -m -u -b_CODE=0x200 -b_DATA=0xc0a0 -yp0x143=0x80 -yo4 -yt1

#===============================================#
# Liste des fichiers
A_SRC = $(wildcard $(ASMDIR)/*.s)
C_SRC = $(wildcard $(SRCDIR)/*.c)
H_SRC = $(wildcard $(INCDIR)/*.h)

#===============================================#
# Objets
OBJ  = $(patsubst $(ASMDIR)/%.s, $(OBJDIR)/%.o, $(A_SRC))
OBJ += $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(C_SRC))

#===============================================#
# Directives de compilation
all: $(OBJ)
	$(LINK) -Z $(GBFILE) $(CRTDIR) $(OBJ) $(LNKINC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(ASMDIR)/%.s
	$(AS) $(ASFLAGS) -c $< -o $@

#===============================================#
# Directive de clean
clean:
	rm -f *.gb *.map
	rm -f $(OBJDIR)/*