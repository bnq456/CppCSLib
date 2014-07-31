#ifndef CLASSA42_H
#define CLASSA42_H

class ClassA42
{
public:
    ClassA42() {}
private:
    int number;
};

class ClassB42
{
private:
    ClassA42* ptr1;
    ClassA42* ptr2;
public:
    ClassB42(ClassA42 val1,ClassA42 val2)
        :ptr1(new ClassA42(val1)),
         ptr2(new ClassA42(val2)) {
    }

    ClassB42 (const ClassB42& x)
        :ptr1(new ClassA42(*x.ptr1)),
         ptr2(new ClassA42(*x.ptr2)) {
    }

    const ClassB42& operator= (const ClassB42& x) {
        *ptr1 = *x.ptr1;
        *ptr2 = *x.ptr2;
        return *this;
    }

    ~ClassB42 () {
        delete ptr1;
        delete ptr2;
    }
};













#endif // CLASSA42_H
