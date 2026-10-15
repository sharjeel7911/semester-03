#include "class.h"

void animal() {
    clearScreen();
    Animal* a = new Animal("Guess", 5);
    Animal* c = new Cat("Meow", 3);
    Animal* d = new Dog("Buddy", 4);
    a->display();
    a->makeSound();
    cout << endl;
    c->display();
    c->makeSound();
    cout << endl;
    d->display();
    d->makeSound();
    cout << endl;
    delete a;
    delete c;
    delete d;

    //_______________________________________________________________________________________________//

    Animal a0;
    Animal A("Leo", 2);
    Cat C("Whiskers", 1);
    Dog D("Rex", 3);
    a0.display();
    a0.makeSound();
    cout << endl;
    A.display();
    A.makeSound();
    cout << endl;
    C.display();
    C.makeSound();
    cout << endl;
    D.display();
    D.makeSound();
    pauseScreen();
}