#UNIX/Linux 编程实践教程
From 2019.7.15
SHELL

1.who 
显示当前用户

~~~
2.cp
拷贝文件
原理 :如果源文件为空或者不存在则提示.如果目标文件不存在则新建或者覆盖.然后将源文件读取 读取到一个缓存里再写到目标文件里
函数原型:
#include <fcntl.h>

int open(const char* pathname,int flags)

int open(const char* pathname,int flags,mode_t mode);

 

2)函数功能：

打开或建立一个文件。对于open函数，仅当创建文件时，才用到第三个参数

 

3)参数说明：

pathname：打开或创建的文件名

 

flags：用下列一个或多个常量进行“或”运算构成flags参数（这些常量定义在<fcntl.h>

O_RDONLY   只读打开

O_WRONLY   只写打开

O_RDWR     读写打开
以上三个常量只能选一个，下面的则可以多选：

O_APPEND   每次写时都追加到文件的尾端。

O_CREAT     若此文件不存在，则创建它。使用此选项时，需要第三个参数mode，用其     

              指定新文件的访问权限。

O_EXCL      如果同时制定了O_CREAT,而文件已经存在，则会报错。因此可以测试一个

              文件是否存在，如果不存在，则创建此文件，这使测试和创建两者成为一个

              原子操作。

O_TRUNC     如果此文件存在，而且为只读或读写成功打开，则将其长度截短为0。

O_NOCTTY    如果pathname指的是终端设备，则不将该设备分配作为此进程的控制终端。

O_NONBLOCK 如果pathname指的是一个FIFO、一个块特殊文件或一个字符特殊文件，

               则此选项为文件的本次打开操作和后续的I/O操作设置非阻塞模式。

 

mode：用下列一个或多个常量进行“或”运算构成mode参数（这些常量定义在sys/stat.h）

S_IRWXU：00700 拥有者读写执行权限

S_IRUSR： 00400 拥有者读权限

S_IWUSR：00200  拥有者写权限

S_IXUSR： 00100 拥有者执行权限

S_IRWXG：00070 组内成员读写执行权限

S_IRGRP： 00040 组内成员读权限

S_IWGRP：00020  组内成员写权限

S_IXGRP： 00010 组内成员执行权限

S_IRWXO：00007 其他成员读写执行权限

S_IROTH： 00004 其他成员读权限

S_IWOTH：00002  其他成员写权限

S_IXOTH： 00001 其他成员执行权限

 

也可以直接指定mode的值，如0777,0541等

注意：此处设定的mode的值并不是文件最终的权限，文件最终的权限是按照mode & ~umask得到的，而默认的umask是0022，所以如果想按照mode的值设置文件权限，需要在建立文件之前将umask的值设置为0000


int open(char *path,int mode)
返回打开的文件描述符号

2.creat函数

1)函数原型：

#include <fcntl.h>

int creat(const char *pathname ,mode_t  mode);

 

2)函数功能：

创建一个新文件。

creat函数等效于如下函数：

open(pathname,O_WRONLY | O_CREAT | O_TRUNC, mode)

注意：creat只能以只写方式打开，不能读，读出的将是乱码！

 

3)参数说明：

pathname：创建的文件名

mode：与open的mode相同

用户进程位于用户空间,内核位于系统空间,磁盘只能被内核直接访问,程序要读取磁盘上的数据只能通过系统调用read,read代码在内核,所以当read被调用发生时,执行权会从用户代码转移到内核代码,运行环境切换需要耗费时间.

指针是与文件描述符相管理,而不是与文件相管理,所以如果两个程序同时打开一个文件就会有两个指针,两个程序对文件的读操作互不干扰

unix可以通过内核缓冲来减少访问磁盘I/O的次数.也可以直接写到磁盘上,具体见apue.
