obj-m+=statiAllocation.o
obj-m+=dynamicAllocation.o

KDIR = /lib/modules/$(shell uname -r)/build

all:
	make	-C	$(KDIR)	M=$(shell pwd)	modules
clean:
	make -C	$(KDIR)	M=$(shell pwd)	clean
