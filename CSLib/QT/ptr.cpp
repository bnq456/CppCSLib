#include <iostream>
#include <QObject>
#include <QString>
#include <Windows.h>
using namespace std;

/**
 * 其实电脑开机后物理内存的每个字节都是可读写的，从来不会因为所谓的new、delete或malloc、free而被创建、销毁。
 * 区别仅在于操作系统内存管理模块在你读写时是否能发现并是否采取相应动作而已。操作系统管理内存的粒度不是字节而是页，一页通常为4KB。
 * 推荐使用WinHex软件查看硬盘或文件或内存中的原始字节内容。
 */

class A
{
public:
    void Func(void)
    {
        cout << "Func of class A" << endl;
    }
};

int mainptr()
{
    A *p;
    for(int i=0;i<1;i++)
    {
        A a;
        p = &a; //野指针？
    }
    p->Func();
    return 0;
}

