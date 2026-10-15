#include "class.h"

void task04() {
    clearScreen();
    cout << "-------------------- Task 04 --------------------" << endl << endl;

    /*
    Book book1("Udaas Naslen", "Abdullah Hussain");
    Book book2("100 years of solitude", "Gabriel Garcia Marquez");
    Book book3("My name is Red", "Orhan Pamuk");

    Book* books[] = { &book1, &book2, &book3 };

    Library library(books, 3);

    Book book4("Aag ka Darya", "Quratul Ain Haider");
    library.addBook(&book4);
    */

    Book* books[3];
    books[0] = new Book("Udaas Naslen", "Abdullah Hussain");
    books[1] = new Book("100 years of solitude", "Gabriel Garcia Marquez");
    books[2] = new Book("My name is Red", "Orhan Pamuk");

    Library library(books, 3);
    library.displayLibrary();
    pauseScreen();
    Book* book4 = new Book("Aag ka Darya", "Quratul Ain Haider");
    library.addBook(book4);
    clearScreen();

    library.displayLibrary();

    for (int i = 0; i < 3; i++) delete books[i];
    delete book4;
    pauseScreen();
}