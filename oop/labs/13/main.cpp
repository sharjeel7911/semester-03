#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename type>
class MyVector {
private:
    type* arr;         //pointer to dynamic array
    int m_capacity;    // total capacity
    int m_size;        // current number of elements

    //resize the array when full
    void resize() {
        m_capacity *= 2;
        type* newArr = new type[m_capacity];
        for (int i = 0; i < m_size; ++i) newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }

public:
    //constructor
    MyVector(int cap = 1) {
        m_capacity = cap;
        arr = new type[m_capacity];
        m_size = 0;
    }

    ~MyVector() { delete[] arr; } //destructor
    void pop_back() { if (m_size > 0) --m_size; } //remove last element
    int size() { return m_size; } //return current size
    int capacity() { return m_capacity; } //return current capacity
    bool empty() { return m_size == 0; } //check if empty
    void clear() { m_size = 0; } //clear vector
    void printElements() { for (int i = 0; i < m_size; ++i) cout << arr[i] << " "; cout << endl; } //print all elements

    void push_back(type val) { //add element at the end
        if (m_size == m_capacity) resize();
        arr[m_size++] = val;
    }

    //print all elements
    void printElement() {
        for (int i = 0; i < size(); ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    //access element by index
    type& operator[](int index) {
        if (index < 0 || index >= m_size) {
            throw out_of_range("Index out of bounds");
        }
        return arr[index];
    }
};

class MyVec {
private:
    vector<int> data;
public:
    void addElement(int val) {
        data.push_back(val);
    }

    void popElement() {
        if (!data.empty()) {
            data.pop_back();
        }
    }

    void printElements() {
        cout << "Elements: ";
        for (int i = 0; i < data.size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void printElementsConst() {
        cout << "Elements (const): ";
        for (vector<int>::const_iterator it = data.cbegin(); it != data.cend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    void doubleElements() {
        for (vector<int>::iterator it = data.begin(); it != data.end(); ++it) {
            *it *= 2;
        }
    }

    void removeEvens() {
        vector<int>::iterator it = data.begin();
        while (it != data.end()) {
            if (*it % 2 == 0) {
                it = data.erase(it);
            } else {
                ++it;
            }
        }
    }


    void removeOdds() {
        vector<int>::iterator it = data.begin();
        while (it != data.end()) {
            if (*it % 2 != 0) {
                it = data.erase(it);
            } else {
                ++it;
            }
        }
    }

    bool isEmpty() {
        return data.empty();
    }

    int size() {
        return data.size();
    }
};

int main() {
    MyVector<double> v;

    v.push_back(11.3);
    v.push_back(2.71);
    v.push_back(1.41);
    cout << "MyVector<double>: ";
    v.printElement();

    MyVec vec;
    cout << "\nAdding elements: 1, 2, 3, 4, 5, 6" << endl;
    vec.addElement(1);
    vec.addElement(2);
    vec.addElement(3);
    vec.addElement(4);
    vec.addElement(5);
    vec.addElement(6);

    vec.printElements();
    vec.printElementsConst();

    cout << "\nRemoving even numbers" << endl;
    vec.removeEvens();
    vec.printElements();

    cout << "\nDoubling all elements" << endl;
    vec.doubleElements();
    vec.printElements();
    return 0;
}