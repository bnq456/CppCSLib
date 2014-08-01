#ifndef FUNC52_H
#define FUNC52_H

#include <iostream>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void ListTeas()
{
    list<char> coll;
    for(char c='a';c<'z';++c) {
        coll.push_back(c);
    }
    while(!coll.empty()) {
        cout << coll.front() << ' ';
        coll.pop_front();
    }
    cout << endl;
}


void ListOperate()
{
    list<char> coll;
    for(char c='a';c<'z';++c) {
        coll.push_back(c);
    }
    list<char>::const_iterator pos;
    // const_iterator 只读方式遍历
    // iterator 读写遍历
    // D1      D2      D3      D4     D5
    // |               |                      |
    // begin()        pos                    end()
    //
    //
    // ++pos 前式递增！ 效率高
    for(pos = coll.begin();pos != coll.end();++pos) {
        cout << *pos << ' ';
    }
    cout << endl;

}

//! Set和Multisets
void SetTest()
{
    set<int> coll;
    //set< int,greater<int> > coll;

    // 无权指定元素的位置
    coll.insert(3);
    coll.insert(1);
    coll.insert(5);
    coll.insert(4);
    coll.insert(6);
    coll.insert(2);

    set<int>::const_iterator pos;
    for (pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << *pos << ' ';
    }
    cout << endl;
}

void MulmapTest()
{
    multimap<int,string> coll;

    coll.insert(make_pair(5,"tagged"));
    coll.insert(make_pair(2,"is"));
    coll.insert(make_pair(1,"this "));
    coll.insert(make_pair(4,"str"));
    coll.insert(make_pair(3,"a"));

    multimap<int,string>::const_iterator pos;
    for(pos = coll.begin(); pos != coll.end(); ++pos)
        cout << (*pos).second << ' ';

    cout << endl;

}

void MapTest()
{
    map<string,float> coll;
    coll["VAT"] = 0.15;
    coll["Pi"] = 3.1415;
    coll["an arbitrary number"] = 4983.223;
    coll["Null"] =0;

    map<string,float>::const_iterator pos;
    for(pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << "key: \"" << pos->first << "\" " << "value: " << pos->second <<endl;
    }
}

void AlgoTest1()
{
    vector<int> coll;
    vector<int>::iterator pos;
    coll.push_back(2);
    coll.push_back(5);
    coll.push_back(4);
    coll.push_back(1);
    coll.push_back(6);
    coll.push_back(3);
    pos = min_element (coll.begin(),coll.end());
    cout << "min: " << *pos << endl;
    pos = max_element (coll.begin(),coll.end());
    cout << "max: " << *pos << endl;

    sort (coll.begin(),coll.end());

    pos = find (coll.begin(),coll.end(),3);

    reverse (pos,coll.end());

    for(pos=coll.begin();pos!=coll.end();++pos) {
        cout << *pos << ' ';
    }
    cout << endl;


}







#endif // FUNC52_H
