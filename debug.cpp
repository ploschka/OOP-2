#include <iostream>
#include "KVC.h"
#include "Stack.h"
#include "BigInteger.h"

int main()
{
    KVC<char, int> mapa;
    mapa['a'] = 5;
    std::cout << mapa['a'] << std::endl;
    mapa['a'] = 6;
    mapa['b'] = 7;
    std::cout << mapa['b'] << std::endl;
    std::cout << mapa['a'] << std::endl;

    KVC<char, int> mapa2(mapa);

    std::cout << "===================" << std::endl;

    std::cout << mapa2['a'] << std::endl << mapa2['b'] << std::endl;
    std::cout << "===================================\n" << "===================================\n";

    Stack<int> staka;
    staka.push(5);
    staka.push(3);
    staka.push(2);
    std::cout << staka << std::endl;
    std::cout << staka.pop() << std::endl;
    std::cout << staka << std::endl;
    std::cout << "===================================\n" << "===================================\n";

    BigInteger biga("-492104");
    BigInteger bigb("-740430");
    std::cout << (biga - bigb) << std::endl;
    //6912
}
