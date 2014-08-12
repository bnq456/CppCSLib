#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>      // for abs()
using namespace std;

bool isMultiple(int number)
{
    if(number%3==0||number%5==0)
        return true;
    else
        return false;
}

int main()
{
    int sum = 0;
    vector<int> coll;

    for(int i=1;i<1000;++i) {
        coll.push_back(i);
    }

    vector<int>::iterator pos_t;
    pos_t = coll.begin();

    while(1)
    {
        pos_t = find_if(pos_t,coll.end(),isMultiple);
        if(pos_t==coll.end()) break;
        sum+=*pos_t++;
    }

    cout<<"Answer to P1 is "<<sum<<endl;

    return 0;
}
