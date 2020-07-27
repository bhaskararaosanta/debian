obj-m:=driver1.o
#obj-m:= driver23.o
#driver23-objs:=driver2.o driver3.o

KERNELVER= $(shell uname -r)

all:
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) clean
