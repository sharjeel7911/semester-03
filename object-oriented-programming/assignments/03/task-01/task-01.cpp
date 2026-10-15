#include "shopping.h"

void shopping() {
    clearScreen();
    cout << "********** Shopping Cart System **********" << endl;

    Category* electronicsCat = new Category(1, "Electronics", "Electronic gadgets and devices");
    electronicsCat->applyDiscount(5000, 15);
    electronicsCat->display();

    Category* clothingCat = new Category(2, "Clothing", "Apparel and garments");
    clothingCat->applyDiscount(400, 3);
    clothingCat->display();

    Electronics* laptop = new Electronics(101, 50000, "Laptop", electronicsCat, 24);
    laptop->applyDiscount(10); // 10% discount on electronics
    laptop->display();
    Clothing* tshirt = new Clothing(201, 1500, "T-Shirt", clothingCat, "L");
    tshirt->applyDiscount(20); // 20% discount on clothing
    tshirt->display();

    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(laptop);
    cart->addProduct(tshirt);
    cart->displayCart();

    delete electronicsCat;
    delete clothingCat;
    delete laptop;
    delete tshirt;
    delete cart;
    pauseScreen();
}