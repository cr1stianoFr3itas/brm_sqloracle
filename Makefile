###########
#   Dev. Cristiano Freitas
#   email: junior.brown.eda@gmail.com
#   Data de inicio do projeto: 20/05/2021
#   Data de "Final" do projeto: 07/06/2021 
#   MAKE FILE CREATE CLIENT / CUST CUSTOM
#
###########
OS=linux
VERSION=7.5

###########
PINDIR=../../..
INCDIR=$(PINDIR)/include
LIBDIR=$(PINDIR)/lib

##########
CC_solaris = cc
CC_hpux = cc
CC_hpux_ia64 = cc
CC_aix = xlc_r
CC_linux = gcc
CC = $(CC_$(OS))

##########

CFLAGS_solaris= -g -xcg92
CFLAGS_hpux= -g -Ae +Z +DAportable
CFLAGS_hpux_ia64= -g -Ae +Z 
CFLAGS_aix= -g -Drs6000 -D__aix -Dunix -D__unix
CFLAGS_linux= -m32 -fPIC
CFLAGS= $(CFLAGS_$(OS)) -DFOR_CM -DFM_INV_POL_DLL

CPPFLAGS = -I$(INCDIR) -DPCMCPP_CONST_SAFE -DFOR_CM  -DFM_INV_POL_DLL

LDFLAGS_solaris= -G
LDFLAGS_hpux= -b
LDFLAGS_hpux_ia64= -b
LDFLAGS_aix= -G -bnoentry -bexpall -lc -brtl
LDFLAGS_linux= -m elf_i386 -shared -L/usr/lib
LDFLAGS = $(LDFLAGS_$(OS)) -L$(LIBDIR)

SL_EXT_solaris= so
SL_EXT_hpux= sl
SL_EXT_hpux_ia64= so
SL_EXT_aix= a 
SL_EXT_linux= so
SL_EXT= $(SL_EXT_$(OS))

###########

INCFILES= $(INCDIR)/pin_cust.h $(INCDIR)/pcm.h \
	$(INCDIR)/pin_errs.h $(INCDIR)/pinlog.h \
	$(INCDIR)/pin_act.h $(INCDIR)/pin_bill.h \
	$(INCDIR)/pin_flds.h $(INCDIR)/pin_currency.h \
	$(INCDIR)/pin_inv.h

#

FILES= fm_cust_custom_config.c \
       fm_cust_custom_mycustomop.c\
       fm_cust_create_client.c\
       fm_new_op_code.c


#

OBJECTS= fm_cust_custom_config.o \
       fm_cust_custom_mycustomop.o\
       fm_cust_create_client.o\
       fm_new_op_code.o

LIBBILL=fm_cust_custom.$(SL_EXT)

###########

all: $(LIBBILL)

clean:
	rm -f $(OBJECTS) core

clobber: clean
	rm -f $(LIBBILL)

lint:
	lint $(CPPFLAGS) $(FILES)

tags: FRC

###########

$(LIBBILL): $(OBJECTS) $(INCFILES) Makefile
	$(LD) -o $(LIBBILL) $(LDFLAGS) $(OBJECTS) -lm -lpsiu_for_cm

$(OBJECTS): $(INCFILES) Makefile
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(FILES)

#

FRC:

