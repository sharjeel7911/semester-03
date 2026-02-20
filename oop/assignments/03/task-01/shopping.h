#include "../main.h"

class Category {
private:
    int m_category_id;
    string m_name;
    string m_description;
public:
    Category(int id = 0, const string& name = "", const string& desc = "");
    void applyDiscount(double price, double percentage);
    void display() const;
};

class Product {
protected:
    int m_product_id;
    double m_price;
    string m_name;
    Category* m_category; //association 
public:
    Product(int id = 0, double price = 0.0, const string& name = "", Category* cat = nullptr);
    virtual ~Product() {}

    double getPrice() const;
    virtual void applyDiscount(double percentage);
    virtual void display() const;
};

class ShoppingCart {
private:
    Product* m_products[20]; //aggregation
    int m_count;
public:
    ShoppingCart();
    void addProduct(Product* p);
    void removeProduct(int index);
    double calculateTotal();
    void displayCart();
};

class Electronics : public Product {
private:
    int m_warranty;
public:
    Electronics(int id, double price, const string& name, Category* cat, int warranty);
    void applyDiscount(double percentage) override;
    void display() const override;
};

class Clothing : public Product {
private:
    string m_size;
public:
    Clothing(int id, double price, const string& name, Category* cat, const string& size);
    void applyDiscount(double percentage) override;
    void display() const override;
};