
obj-m += void.o

PWD   := $(shell pwd)
KDIR  := /lib/modules/$(shell uname -r)/build/

all:
	make -C $(KDIR) M=$(PWD) modules
install:
	make -C $(KDIR) M=$(PWD) modules_install
clean:
	make -C $(KDIR) M=$(PWD) clean
