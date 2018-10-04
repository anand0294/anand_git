obj-m :=chr_dev_dynamic.o

KDIR= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	rm -rf $(wildcard *.o *.ko  Mo* *.mod.* *.order )
	
