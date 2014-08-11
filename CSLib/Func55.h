#ifndef FUNC55_H
#define FUNC55_H

#include <iostream>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

// 迭代器配接器
void copy3()
{
    list<int> coll1;

    for(int i=1;i<=9;++i) {
        coll1.push_back(i);
    }

    vector<int> coll2;
    copy(coll1.begin(),coll1.end(),back_inserter(coll2));

    deque<int> coll3;
    copy(coll1.begin(),coll1.end(),front_inserter(coll3));

    set<int> coll4;
    copy(coll1.begin(),coll1.end(),inserter(coll4,coll4.begin()));
}

// 流迭代器
void iouter1()
{
    vector<string> coll;

    copy(istream_iterator<string>(cin),
         istream_iterator<string>(),
         back_inserter(coll));

    sort(coll.begin(),coll.end());

    unique_copy(coll.begin(),coll.end(),
                ostream_iterator<string>(cout,"\n"));

}

#endif // FUNC55_H
