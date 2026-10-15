#pragma once
#include "main.h"

template <typename T>
class MyStack {
private:
    T m_data[500]; //fixed-size array for storing elements
    int m_top; //index of top element (-1 means empty)
    int m_maxSize; //maximum capacity
public:
    MyStack(int maxSize = 500); // Constructor

	void push(const T& value); //push element onto stack
	T pop(); //pop element from stack
	T& peek(); //peek at top element
	const T& peek() const; //const version of peek

	bool isEmpty() const; //check if stack is empty
	bool isFull() const; //check if stack is full
	int size() const; //get current size of stack
	void clear(); //clear the stack

    //for accessing move history (needed for castling, en passant)
    const T& operator[](int index) const;
    T& operator[](int index);
};

template <typename T>
MyStack<T>::MyStack(int maxSize) : m_top(-1), m_maxSize(maxSize) {
    if (m_maxSize > 500) m_maxSize = 500;
}

template <typename T>
void MyStack<T>::push(const T& value) {
    if (isFull()) {
        cout << "Stack overflow! Cannot push more elements." << endl;
        return;
    }
    m_top++;
    m_data[m_top] = value;
}

template <typename T>
T MyStack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack underflow! Cannot pop from empty stack." << endl;
        return T(); //return default-constructed object
    }
    T value = m_data[m_top];
    m_top--;
    return value;
}

template <typename T>
T& MyStack<T>::peek() {
    if (isEmpty()) {
        cout << "Stack is empty! Cannot peek." << endl;
        static T dummy;
        return dummy;
    }
    return m_data[m_top];
}

template <typename T>
const T& MyStack<T>::peek() const {
    if (isEmpty()) {
        cout << "Stack is empty! Cannot peek." << endl;
        static T dummy;
        return dummy;
    }
    return m_data[m_top];
}

template <typename T>
bool MyStack<T>::isEmpty() const {
    return m_top == -1;
}

template <typename T>
bool MyStack<T>::isFull() const {
    return m_top >= m_maxSize - 1;
}

template <typename T>
int MyStack<T>::size() const {
    return m_top + 1;
}

template <typename T>
void MyStack<T>::clear() {
    m_top = -1;
}

template <typename T>
const T& MyStack<T>::operator[](int index) const {
    if (index < 0 || index > m_top) {
        cout << "Invalid index!" << endl;
        static T dummy;
        return dummy;
    }
    return m_data[index];
}

template <typename T>
T& MyStack<T>::operator[](int index) {
    if (index < 0 || index > m_top) {
        cout << "Invalid index!" << endl;
        static T dummy;
        return dummy;
    }
    return m_data[index];
}