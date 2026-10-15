#include "class.h"

void animal() {
    clearScreen();
    Cat c("Kitty", 10);
    c.display();

    Animal* animal = new Cat("Mano Billi", 5);
    animal->display();

    Animal* a = new Animal("human", 3);
    a->display();

    delete animal;
    delete a;
    pauseScreen();
}