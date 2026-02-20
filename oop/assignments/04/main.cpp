#include <iostream>
#include <vector>
using namespace std;

/*
An online e-commerce platform sells different types of products: Electronics, Clothing, and Groceries.
Each product has a base price, but the final price is calculated differently depending on the product category:
•	Electronics: Add warranty charges.
•	Clothing: Apply size-based tax.
•	Groceries: Apply a freshness discount.
The system should be designed using object-oriented programming principles in C++.
Tasks:
•	Create an abstract class Product with a pure virtual function calculateFinalPrice().
•	Create derived classes: Electronics, Clothing, Groceries and override calculateFinalPrice().
•	In main(), use a vector<Product*> to store multiple products.
•	Display final price of each product and calculate total amount.
•	Delete all dynamically allocated objects.
*/

class Product {
protected:
    double m_basePrice;
public:
    Product(double price) : m_basePrice(price) {}
    virtual double calculateFinalPrice() const = 0;
    virtual ~Product() {}
};

class Electronics : public Product {
private:
    double m_warrantyCharges;
public:
    Electronics(double price, double warranty) : Product(price), m_warrantyCharges(warranty) {}

    double calculateFinalPrice() const override {
        return m_basePrice + m_warrantyCharges;
    }
};

class Clothing : public Product {
    double m_sizeTax;

public:
    Clothing(double price, double tax) : Product(price), m_sizeTax(tax) {}

    double calculateFinalPrice() const override {
        return m_basePrice + (m_basePrice * m_sizeTax);
    }
};

class Groceries : public Product {
private:
    double m_freshnessDiscount;
public:
    Groceries(double price, double discount) : Product(price), m_freshnessDiscount(discount) {}

    double calculateFinalPrice() const override {
        return m_basePrice - m_freshnessDiscount;
    }
};

int main() {
    vector<Product*> products;

    products.push_back(new Electronics(1000, 150));
    products.push_back(new Clothing(500, 0.10));
    products.push_back(new Groceries(300, 50));

    double totalAmount = 0.0;

    cout << "Final Prices of Products:\n";
    for (Product* product : products) {
        double finalPrice = product->calculateFinalPrice();
        cout << finalPrice << endl;
        totalAmount += finalPrice;
    }

    cout << "\nTotal Amount: " << totalAmount << endl;

    for (Product* product : products) {
        delete product;
    }
    products.clear();
    return 0;
}