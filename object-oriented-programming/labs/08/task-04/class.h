#include "../main.h"

class Book {
private:
    string m_title;
    string m_author;
public:
    Book(const string& title = "", const string& author = "");
    void displayBook() const;

};

class Library {
private:
    Book* m_books[10];
    int m_bookCount;
public:
    Library(Book* books[] = nullptr, int bookCount = 0);
    void addBook(Book* book);
    void displayLibrary() const;
};