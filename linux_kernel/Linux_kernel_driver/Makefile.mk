
KERNDIR:= /lib/modules/3.2.0-29-generic-pae/build/
PWD:=$(shell pwd)

obj-m:=demo.o

all:
	make -C $(KERNDIR) M=$(PWD) modules

clean:
	make -C $(KERNDIR) M=$(PWD) clean

# 假设Makefile和demo.c都存放在某一test目录下
# 进入该目录,使用make命令编译模块