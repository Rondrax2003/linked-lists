#include <iostream>
#include "Node.h"
using namespace std;

int main(){
    List Phone;
    Phone.InsertOrdened(100);
    Phone.InsertOrdened(50);
    Phone.InsertOrdened(27);
    Phone.InsertOrdened(45);
    Phone.getsize();
    Phone.~List();

    return 0;
}