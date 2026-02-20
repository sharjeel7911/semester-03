#include <iostream>
#include <string>
using namespace std;

template <class type>
class Box {
private:
    type value;
public:
    Box() :value() {}
    Box(type val) { value = val; }

    void setValue(type val) { value = val; }
    type getValue() { return value; }
};

int main() {
    Box<int>* ptr0 = new Box<int>(5);
    Box<string>* ptr1 = new Box<string>("Sharjeel");

    Box<string>* ptr2 = new Box<string>;
    ptr2->setValue("Ahmad");

    Box<double> b;
    b.setValue(1.5);

    cout << "ptr0 value: " << ptr0->getValue() << endl;
    cout << "ptr1 value: " << ptr1->getValue() << endl;
    cout << "ptr2 value: " << ptr2->getValue() << endl;
    cout << "b value: " << b.getValue() << endl;

    delete ptr0;
    delete ptr1;
    delete ptr2;
    return 0;
}