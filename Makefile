topdir:=.
include $(topdir)/config.mk

CFLAGS:=$(CFLAGS) #-static
LIBS:=$(LIBS) -L$(LIBDIR) -lcwiimote -lbluetooth -lm

all: wiiIR

wiiIR: wiiIR.c $(LIBDIR)/libcwiimote.a
	$(CC) $(CFLAGS) $(INCLUDES) -o $(BINDIR)/$@ $< $(LIBS)

clean:
	@rm -f *.o *~ $(BINDIR)/*

