#include "bank.h"

void bank() {
    clearScreen();
    BankAccount* accounts[5];

    accounts[0] = new SavingsAccount("Alice", 1001, 60000, 500);
    accounts[1] = new CheckingAccount("Bob", 1002, 30000, 50);
    accounts[2] = new SavingsAccount("Charlie", 1003, 40000, 300);
    accounts[3] = new CheckingAccount("Diana", 1004, 20000, 30);
    accounts[4] = new SavingsAccount("Eve", 1005, 55000, 400);

    for (int i = 0; i < 5; ++i) {
        accounts[i]->display();
        cout << endl;
    }

    /*using deposit and withdraw in array*/
    accounts[0]->deposit(10000);
    accounts[1]->withdraw(5000);
    accounts[2]->deposit(20000);
    accounts[3]->withdraw(25000); //should show invalid withdrawal
    accounts[4]->deposit(5000);
    cout << "\nAfter Transactions:\n" << endl;
    for (int i = 0; i < 5; ++i) {
        accounts[i]->display();
        cout << endl;
    }

    for (int i = 0; i < 5; ++i) delete accounts[i];

    pauseScreen();
}