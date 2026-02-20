#include "class.h"

void person() {
    clearScreen();
    Person* p = new Person("Sharjeel", 30);
    Person* e = new Employee("Swe", 101, "Ahmad", 28);
    Person* m = new Manager(5, "IT", 201, "A$AP", 35);
    p->display();
    e->display();
    m->display();
    delete p;
    delete e;
    delete m;

    //_____________________________________________________________________

    Person person("Ali", 45);
    Employee employee("HR", 102, "Imam", 32);
    Manager manager(10, "Finance", 202, "Feroze", 40);

    cout << "\nDisplaying Person details:\n";
    person.display();
    employee.display();
    manager.display();
    pauseScreen();
}