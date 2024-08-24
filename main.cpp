#include <iostream>
#include "Node.h"
using namespace std;

int main(){
    List Phone;
    Phone.InsertOrdened(25);
    Phone.InsertOrdened(50);
    Phone.InsertOrdened(27);
    Phone.InsertOrdened(28);
    Phone.InsertOrdened(35);
    Phone.InsertOrdened(100);
    Phone.showList();
    Phone.deleteNode(28);
    Phone.showList();
    Phone.getsize();
    Phone.~List();

    return 0;
}