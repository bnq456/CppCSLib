/*
 * Multiples of 3 and 5
 * Problem 1
 * Published on 05 October 2001 at 06:00 pm [Server Time]
 * If we list all the natural numbers below 10 that are multiples of 3 or 5,
 * we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 */

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

int mainp001()
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
