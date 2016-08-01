#include <cstdlib>
#include <iostream>
#include "LinkedList.hpp"

/*
 *
 */
void firstTask() {
    double dASide, dBSide, S;
}

void secondTask() {

}

void ptrFunc(int &nParam) {
    int nVal = 10;

    std::cout << nVal << std::endl;
    int *pNVal = &nVal;

    *pNVal = 40.5;

    std::cout << nVal << std::endl;
    nParam++;
    int intArr[5] = {4, 2, 0, 9};

    std::cout << "Значения элементов массива равны:\n";
    int* pArray = intArr;
    for (int n = 0; n < 5; n++, pArray++) {
        std::cout << n << ": " << *pArray << "\n";
    }
    std::cout << "\n";
}

int main(int argc, char** argv) {

    LinkedList linkedList;

    linkedList.add(2);
    /*linkedList.add(5);
    linkedList.add(1);
    linkedList.add(6);*/

    linkedList.out();

    linkedList.remove(0);

    linkedList.out();


    return 0;
}