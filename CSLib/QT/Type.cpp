#include<iostream>
#include <limits>
using namespace std;

int maintype()
{

    std::cout << std::boolalpha; //1 ----> true
    std::cout << "INT----------------------------------------" <<endl;
    std::cout << "Minimum value for int: " << std::numeric_limits<int>::min() << '\n';
    std::cout << "Maximum value for int: " << std::numeric_limits<int>::max() << '\n';
    std::cout << "int is signed: " << std::numeric_limits<int>::is_signed << '\n';
    std::cout << "Non-sign bits in int: " << std::numeric_limits<int>::digits << '\n';
    std::cout << "int has infinity: " << std::numeric_limits<int>::has_infinity << '\n';

    std::cout << "UNSIGNED INT--------------------------------" <<endl;
    std::cout << "Minimum value for int: " << std::numeric_limits<unsigned int>::min() << '\n';
    std::cout << "Maximum value for int: " << std::numeric_limits<unsigned int>::max() << '\n';
    std::cout << "int is signed: " << std::numeric_limits<unsigned int>::is_signed << '\n';
    std::cout << "Non-sign bits in int: " << std::numeric_limits<unsigned int>::digits << '\n';
    std::cout << "int has infinity: " << std::numeric_limits<unsigned int>::has_infinity << '\n';

    std::cout << "LONG----------------------------------------" <<endl;
    std::cout << "Minimum value for int: " << std::numeric_limits<unsigned long long>::min() << '\n';
    std::cout << "Maximum value for int: " << std::numeric_limits<unsigned long long>::max() << '\n';
    std::cout << "int is signed: " << std::numeric_limits<long>::is_signed << '\n';
    std::cout << "Non-sign bits in int: " << std::numeric_limits<long>::digits << '\n';
    std::cout << "int has infinity: " << std::numeric_limits<long>::has_infinity << '\n';


    return 0;
}
