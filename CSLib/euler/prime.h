#ifndef PRIME_H
#define PRIME_H

#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <math.h>
using namespace std;
//向量法
vector<int>  getPrimeVector(int n)
{
    vector<int> primes;
    if (n<2) return primes;//不存在小于2的素数

    primes.push_back(2);//2是第一个素数
    int square=2*2;//上限素数值的平方，如果待检验数大于它，那么要换一个更大的素数做上限
    int upperlimit=0;//素数检验上限

    for (int candidate = 3; candidate <= n; candidate++){
        bool isPrime = true;
        if (candidate>square){
            upperlimit++;
            square=primes[upperlimit] * primes[upperlimit];
        }

        for (int i=0; i<=upperlimit; i++){
            int prime = primes[i];
            if (candidate % prime == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            primes.push_back(candidate);
        }
    }
    return primes;
}

/*
//向量法，估计素数表长度*1.1
vector<int> getPrimeVector_1_1(int n){
    cout<<"预计个数"<<n/log(n)*1.1<<endl;
    int pre_num=round(n/log(n)*1.1);
    vector<int> primes(pre_num);
    if (n<2) return primes;//不存在小于2的素数

    primes[0]=2;//2是第一个素数
    int square=2*2;//上限素数值的平方，如果待检验数大于它，那么要换一个更大的素数做上限
    int upperlimit=0;//素数检验上限
    int num=1;//素数个数

    for (int candidate = 3; candidate <= n; candidate++){
        bool isPrime = true;
        if (candidate>square){
            upperlimit++;
            square=primes[upperlimit] * primes[upperlimit];
        }

        for (int i=0; i<=upperlimit; i++){
            if (candidate % primes[i] == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            primes[num]=candidate;
            num++;
        }
    }
    primes.erase(primes.begin()+num, primes.end());
    return primes;
}

//向量法，估计素数表长度*1.1
vector<int> getPrimeVector_1_1(int n){
    cout<<"预计个数"<<n/log(n)*1.2<<endl;
    int pre_num=round(n/log(n)*1.2);
    vector<int> primes(pre_num);
    if (n<2) return primes;//不存在小于2的素数

    primes[0]=2;//2是第一个素数
    int square=2*2;//上限素数值的平方，如果待检验数大于它，那么要换一个更大的素数做上限
    int upperlimit=0;//素数检验上限
    int num=1;//素数个数

    for (int candidate = 3; candidate <= n; candidate++){
        bool isPrime = true;
        if (candidate>square){
            upperlimit++;
            square=primes[upperlimit] * primes[upperlimit];
        }

        for (int i=0; i<=upperlimit; i++){
            if (candidate % primes[i] == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            primes[num]=candidate;
            num++;
        }
    }
    primes.erase(primes.begin()+num, primes.end());
    return primes;
}

//列表法
list<int> getPrimeList(int n){
    list<int> primes;
    if (n<2) return primes;//不存在小于2的素数

    primes.push_back(2);//2是第一个素数
    int square=2*2;//上限素数值的平方，如果待检验数大于它，那么要换一个更大的素数做上限
    list<int>::iterator upperlimit=primes.begin();//素数检验上限

    for (int candidate = 3; candidate <= n; candidate++){
        bool isPrime = true;
        if (candidate>square){
            upperlimit++;
            square=(*upperlimit) * (*upperlimit);
        }

        for (list<int>::iterator i=primes.begin();i!=upperlimit;i++){
            if (candidate % (*i) == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime && (candidate % (*upperlimit) != 0)) primes.push_back(candidate);//由于循环检验遗漏了上限素数，故需要补上
    }
    return primes;
}

//双向队列法，用下标遍历
deque<int> getPrimeDeque_index(int n){
    deque<int> primes;
    if (n<2) return primes;//不存在小于2的素数

    primes.push_back(2);//2是第一个素数
    int square=2*2;//上限素数值的平方，如果待检验数大于它，那么要换一个更大的素数做上限
    int upperlimit=0;//素数检验上限

    for (int candidate = 3; candidate <= n; candidate++){
        bool isPrime = true;
        if (candidate>square){
            upperlimit++;
            square=primes[upperlimit] * primes[upperlimit];
        }

        for (int i=0; i<=upperlimit; i++){
            if (candidate % primes[i] == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            primes.push_back(candidate);
        }
    }
    return primes;
}

//双向队列法，用迭代器遍历
deque<int> getPrimeDeque_iterator(int n){
    deque<int> primes;
    if (n<2) return primes;//不存在小于2的素数

    primes.push_back(2);//2是第一个素数
    int square=2*2;//上限素数值的平方，如果待检验数大于它，那么要换一个更大的素数做上限
    deque<int>::iterator upperlimit=primes.begin();//素数检验上限

    for (int candidate = 3; candidate <= n; candidate++){
        bool isPrime = true;
        if (candidate>square){
            upperlimit++;
            square=(*upperlimit) * (*upperlimit);
        }

        for (deque<int>::iterator i=primes.begin();i!=upperlimit;i++){
            if (candidate % (*i) == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime && (candidate % (*upperlimit) != 0)) primes.push_back(candidate);//由于循环检验遗漏了上限素数，故需要补上
    }
    return primes;
}

*/
#endif // PRIME_H
