#include <QCoreApplication>
#include <iostream>
#include <memory>
using namespace std;

class ClassA {

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto_ptr<ClassA> ptr1(new ClassA);
    auto_ptr<ClassA> ptr2(new ClassA);

    ptr2 = ptr1;

    return a.exec();
}
