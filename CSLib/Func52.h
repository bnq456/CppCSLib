#ifndef FUNC52_H
#define FUNC52_H

#include <iostream>
#include <list>
#include <set>
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
    //! const_iterator 只读方式遍历
    //! iterator 读写遍历
    //! D1      D2      D3      D4     D5
    //! |               |                      |
    //! begin()        pos                    end()
    //!
    //!
    //! ++pos 前式递增！ 效率高
    for(pos = coll.begin();pos != coll.end();++pos) {
        cout << *pos << ' ';
    }
    cout << endl;

}

//! Set和Multisets
void SetTest()
{
    typedef set<int> IntSet;
    IntSet coll;

    coll.insert(3);
    coll.insert(1);
    coll.insert(5);
    coll.insert(4);
    coll.insert(6);
    coll.insert(2);

    IntSet::const_iterator pos;
    for (pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << *pos << ' ';
    }
    cout << endl;
}











#endif // FUNC52_H
