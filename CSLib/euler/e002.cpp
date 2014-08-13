
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>      // for abs()
using namespace std;

class Fib {
  public:
    Fib() : a0_(1),a1_(1) {}
    Fib(const int& a0,const int& a1) : a0_(a0),a1_(a1) {}
    int operator()() {
        int temp = a0_;
        a0_ = a1_;
        a1_ = temp + a0_;
        return temp;
    }
  private:
    int a0_,a1_;
};

int main002()
{
    int sum = 0;
    Fib fib(1,2);
    while(1)
    {
        int temp = fib();
        if(temp>4000000) break;
        if(temp%2==0) sum+=temp;
    }
    cout << sum <<endl;

    return 0;
}
