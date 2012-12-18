# config.mk

BINDIR=$(topdir)/bin
LIBDIR=$(topdir)/lib
SRCDIR=$(topdir)/src

CC:=gcc
DEFS:=-D_ENABLE_TILT -D_ENABLE_FORCE #-D_DISABLE_NONBLOCK_UPDATES -D_DISABLE_AUTO_SELECT_DEVICE
#CFLAGS:=-O3 -march=athlon-xp -Wall -pipe
CFLAGS:=-Os -Wall -pipe $(DEFS) -march=i686 -mtune=generic -O2 -pipe -fstack-protector --param=ssp-buffer-size=4 -D_FORTIFY_SOURCE=2 -fpic
INCLUDES:=-I$(topdir)/src
LIBS:=-Wl,-O1,--sort-common,--as-needed,-z,relro

VPATH=$(BINDIR) $(LIBDIR)
