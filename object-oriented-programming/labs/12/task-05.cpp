#include <iostream>
#include <string>
using namespace std;

template<class type = int> //default argument
class Storage {
private:
    type value;
public:
    Storage() : value(0) {}
    Storage(type val) : value(val) {}

    void display() { cout << "Storage holds: " << value << endl; }
};

int main() {
    Storage<>* ptr0 = new Storage;
    Storage<>* ptr1 = new Storage(89);
    Storage<> defaultStorage(50);

    Storage<string>* ptr2 = new Storage<string>("Sharjeel"); //Storage<string>* ptr2 = new Storage<string>; {can set value with set func}
    Storage<double>* ptr3 = new Storage(89.89);
    Storage<double> doubleStorage(3.14);

    cout << "ptr0: "; ptr0->display();
    cout << "ptr1: "; ptr1->display();
    cout << "defaultStorage: "; defaultStorage.display();

    cout << "ptr2: "; ptr2->display();
    cout << "ptr3: "; ptr3->display();
    cout << "doubleStorage: "; doubleStorage.display();

    delete ptr0; delete ptr1; delete ptr2; delete ptr3;
    return 0;
}