# cc++笔记

> ## popen

在Linux gcc中stdio.h头文件

popen是一个文件类型
FILE * popen ( const char * command , const char * type );

int pclose ( FILE * stream );

popen() 函数通过创建一个管道，调用 fork 产生一个子进程，执行一个shell 以运行命令来开启一个进程。这个进程必须由 pclose() 函数关闭，而不是close() 函数。pclose() 函数关闭标准 I/O 流，等待命令执行结束，然后返回hell 的终止状态。如果 shell 不能被执行，则 pclose() 返回的终止状态与 shell 已执行 exit 一样。

> ## 内联函数

内联函数（有时称作在线函数或编译时期展开函数）是一种编程语言结构，用来建议编译器对一些特殊函数进行内联扩展（有时称作在线扩展），这样可以加速程序运行。

