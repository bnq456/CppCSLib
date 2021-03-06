#include <iostream>
#include <QObject>
#include <QString>
#include <Windows.h>
using namespace std;

int mainmem()
{
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    cout<<"机器属性："<<endl;
    cout<<"页大小="<<sysInfo.dwPageSize<<endl;
    cout<<"分配粒度="<<sysInfo.dwAllocationGranularity<<endl;
    cout<<"用户区最小值="<<sysInfo.lpMinimumApplicationAddress<<endl;
    cout<<"用户区最大值="<<sysInfo.lpMaximumApplicationAddress<<endl<<endl;

    MEMORYSTATUS memStatus;
    GlobalMemoryStatus(&memStatus);
    cout<<"内存初始状态："<<endl;
    cout<<"内存繁忙程度="<<memStatus.dwMemoryLoad<<endl;
    cout<<"总物理内存="<<memStatus.dwTotalPhys<<endl;
    cout<<"可用物理内存="<<memStatus.dwAvailPhys<<endl;
    cout<<"总页文件="<<memStatus.dwTotalPageFile<<endl;
    cout<<"可用页文件="<<memStatus.dwAvailPageFile<<endl;
    cout<<"总进程空间="<<memStatus.dwTotalVirtual<<endl;
    cout<<"可用进程空间="<<memStatus.dwAvailVirtual<<endl<<endl;

    char stat[65536];
    MEMORYSTATUS memStatus1;
    GlobalMemoryStatus(&memStatus1);
    cout<<"静态分配空间："<<endl;
    printf("指针地址=%x",stat);
    cout<<endl<<"减少物理内存="<<memStatus.dwAvailPhys-memStatus1.dwAvailPhys<<endl;
    cout<<"减少可用页文件="<<memStatus.dwAvailPageFile-memStatus1.dwAvailPageFile<<endl;
    cout<<"减少可用进程空间="<<memStatus.dwAvailVirtual-memStatus1.dwAvailVirtual<<endl<<endl;

    char *dynamic=new char[300*1024*1024];
    MEMORYSTATUS memStatus2;
    GlobalMemoryStatus(&memStatus2);
    cout<<"动态分配空间："<<endl;
    printf("指针地址=%x",dynamic);
    cout<<endl<<"减少物理内存="<<memStatus.dwAvailPhys-memStatus2.dwAvailPhys<<endl;
    cout<<"减少可用页文件="<<memStatus.dwAvailPageFile-memStatus2.dwAvailPageFile<<endl;
    cout<<"减少可用进程空间="<<memStatus.dwAvailVirtual-memStatus2.dwAvailVirtual<<endl<<endl;


    char arrayA[4097];
    char arrayB[900000];
    //第一次查询：
    long len=sizeof(MEMORY_BASIC_INFORMATION);
    MEMORY_BASIC_INFORMATION mbiA;
    VirtualQuery(arrayA,&mbiA,len);
    cout<<"静态内存地址属性："<<endl;
    cout<<"区域基地址="<<mbiA.AllocationBase<<endl;
    cout<<"区域邻近页面状态="<<mbiA.State<<endl;
    cout<<"区域保护属性="<<mbiA.AllocationProtect<<endl;
    cout<<"页面基地址="<<mbiA.BaseAddress<<endl;
    printf("arrayA指针地址=%x",arrayA);
    cout<<endl<<"从页面基地址开始的大小="<<mbiA.RegionSize<<endl;
    cout<<"邻近页面物理存储器类型="<<mbiA.Type<<endl;
    cout<<"页面保护属性="<<mbiA.Protect<<endl<<endl;
    //第二次查询：
    MEMORY_BASIC_INFORMATION mbiB;
    VirtualQuery(arrayB,&mbiB,len);
    cout<<"静态内存地址属性："<<endl;
    cout<<"区域基地址="<<mbiB.AllocationBase<<endl;
    cout<<"区域邻近页面状态="<<mbiB.State<<endl;
    cout<<"区域保护属性="<<mbiB.AllocationProtect<<endl;
    cout<<"页面基地址="<<mbiB.BaseAddress<<endl;
    printf("arrayB指针地址=%x",arrayB);
    cout<<endl<<"从页面基地址开始的大小="<<mbiB.RegionSize<<endl;
    cout<<"邻近页面物理存储器类型="<<mbiB.Type<<endl;
    cout<<"页面保护属性="<<mbiB.Protect<<endl<<endl;


    char *dynamicA=new char[1024];
    char *dynamicB=new char[65467];
    VirtualQuery(dynamicA,&mbiA,len);
    cout<<"动态内存地址属性："<<endl;
    cout<<"区域基地址="<<mbiA.AllocationBase<<endl;
    cout<<"区域邻近页面状态="<<mbiA.State<<endl;
    cout<<"区域保护属性="<<mbiA.AllocationProtect<<endl;
    cout<<"页面基地址="<<mbiA.BaseAddress<<endl;
    printf("dynamicA指针地址=%x",dynamicA);
    cout<<endl<<"从页面基地址开始的大小="<<mbiA.RegionSize<<endl;
    cout<<"邻近页面物理存储器类型="<<mbiA.Type<<endl;
    cout<<"页面保护属性="<<mbiA.Protect<<endl<<endl;

    VirtualQuery(dynamicB,&mbiB,len);
    cout<<"动态内存地址属性："<<endl;
    cout<<"区域基地址="<<mbiB.AllocationBase<<endl;
    cout<<"区域邻近页面状态="<<mbiB.State<<endl;
    cout<<"区域保护属性="<<mbiB.AllocationProtect<<endl;
    cout<<"页面基地址="<<mbiB.BaseAddress<<endl;
    printf("dynamicB指针地址=%x",dynamicB);
    cout<<endl<<"从页面基地址开始的大小="<<mbiB.RegionSize<<endl;
    cout<<"邻近页面物理存储器类型="<<mbiB.Type<<endl;
    cout<<"页面保护属性="<<mbiB.Protect<<endl<<endl;

    VirtualQuery((char*)0x007E1000,&mbiB,len);
    cout<<"动态内存地址属性："<<endl;
    cout<<"区域基地址="<<mbiB.AllocationBase<<endl;
    cout<<"区域邻近页面状态="<<mbiB.State<<endl;
    cout<<"区域保护属性="<<mbiB.AllocationProtect<<endl;
    cout<<"页面基地址="<<mbiB.BaseAddress<<endl;
    printf("dynamicB指针地址=%x",0x007E1000);
    cout<<endl<<"从页面基地址开始的大小="<<mbiB.RegionSize<<endl;
    cout<<"邻近页面物理存储器类型="<<mbiB.Type<<endl;
    cout<<"页面保护属性="<<mbiB.Protect<<endl;
    return 0;
}
