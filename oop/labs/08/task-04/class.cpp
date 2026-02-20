#include "class.h"

Book::Book(const string& title, const string& author) : m_title(title), m_author(author) {}

void Book::displayBook() const {
    cout << "Title: " << m_title << endl << "Author: " << m_author << endl;
}

/*_______________________________________________________________________________________________________________*/

Library::Library(Book* books[], int bookCount) : m_bookCount(bookCount) {
    for (int i = 0; i < 10; i++) m_books[i] = nullptr;
    for (int i = 0; i < bookCount && i < 10; i++) m_books[i] = books[i];
}

void Library::addBook(Book* book) {
    if (m_bookCount < 10) m_books[m_bookCount++] = book;
    else cout << "Library is full. Cannot add more books." << endl;
}

void Library::displayLibrary() const {
    cout << "Library contains " << m_bookCount << " book(s):" << endl;
    for (int i = 0; i < m_bookCount; i++) m_books[i]->displayBook();
}