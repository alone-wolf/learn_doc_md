# whatis loop device

什么是loop设备？
loop设备是一种伪设备，是使用文件来模拟块设备的一种技术，文件模拟成块设备后, 就像一个磁盘或光盘一样使用。在使用之前，一个 loop 设备必须要和一个文件进行连接。这种结合方式给用户提供了一个替代块特殊文件的接口。因此，如果这个文件包含有一个完整的文件系统，那么这个文件就可以像一个磁盘设备一样被 mount 起来。之所以叫loop设备（回环），其实是从文件系统这一层来考虑的，因为这种被 mount 起来的镜像文件它本身也包含有文件系统，通过loop设备把它mount起来，它就像是文件系统之上再绕了一圈的文件系统，所以称为 loop。

loop设备的使用
一般在linux中会有8个loop设备，一般是/dev/loop0~loop7，可用通过losetup -a查看所有的loop设备，如果命令没有输出就说明所有的loop设备都没有被占用，你可以按照以下步骤创建自己的loop设备。

1）创建一个文件
dd if=/dev/zero of=/var/loop.img bs=1M count=10240

2）使用losetup将文件转化为块设备
losetup /dev/loop0 /var/loop.img

3）通过lsblk查看刚刚创建的块设备
lsblk |grep loop0
losetup -a

4）当然，你也可以将这个块设备格式化并创建其他的文件系统，然后再mount到某个目录，有点多余啊，一般人不这么干。

5）要删除这个loop设备可以执行以下命令
losetup -d /dev/loop0

作者：ppdjs
链接：https://www.jianshu.com/p/add423a1f01f
来源：简书
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。