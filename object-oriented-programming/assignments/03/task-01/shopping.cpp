#include "shopping.h"

Category::Category(int id, const string& name, const string& desc) : m_category_id(id), m_name(name), m_description(desc) {}

void Category::applyDiscount(double price, double percentage) {
    price -= price * percentage / 100;
}

void Category::display() const {
    cout << "Category: " << m_name << " | " << m_description << endl;
}

/*__________________________________________________________________________________*/

Product::Product(int id, double price, const string& name, Category* cat) : m_product_id(id), m_price(price), m_name(name), m_category(cat) {}

double Product::getPrice() const {
    return m_price;
}

void Product::applyDiscount(double percentage) {
    m_price -= m_price * percentage / 100;
}

void Product::display() const {
    cout << "Product ID: " << m_product_id << ", Name: " << m_name << ", Price: Rs." << m_price << endl;
    if (m_category) m_category->display();
}

/*__________________________________________________________________________________*/

ShoppingCart::ShoppingCart() : m_count(0) {}

void ShoppingCart::addProduct(Product* p) {
    if (m_count < 20) m_products[m_count++] = p;
}

void ShoppingCart::removeProduct(int index) {
    if (index >= 0 && index < m_count) {
        for (int i = index; i < m_count - 1; i++) m_products[i] = m_products[i + 1];
        m_count--;
    }
}

double ShoppingCart::calculateTotal() {
    double total = 0;
    for (int i = 0; i < m_count; i++) total += m_products[i]->getPrice();

    // Cart discount
    if (total > 10000) total -= total * 0.15;
    return total;
}

void ShoppingCart::displayCart() {
    cout << "\n--- Shopping Cart ---\n";
    for (int i = 0; i < m_count; i++) m_products[i]->display();
    cout << "Final Total: Rs." << calculateTotal() << endl;
}

/*__________________________________________________________________________________*/

Electronics::Electronics(int id, double price, const string& name, Category* cat, int warranty) : Product(id, price, name, cat), m_warranty(warranty) {}

void Electronics::applyDiscount(double percentage) {
    //extra discount for electronics
    Product::applyDiscount(percentage + 5);
}

void Electronics::display() const {
    Product::display();
    cout << "Warranty: " << m_warranty << " years" << endl;
}

/*__________________________________________________________________________________*/

Clothing::Clothing(int id, double price, const string& name, Category* cat, const string& size) : Product(id, price, name, cat), m_size(size) {}

void Clothing::applyDiscount(double percentage) {
    Product::applyDiscount(percentage);
}

void Clothing::display() const {
    Product::display();
    cout << "Size: " << m_size << endl;
}