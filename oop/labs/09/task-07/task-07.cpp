#include "class.h"

void elecDevice() {
    clearScreen();
    ElectronicDevice* eD = new ElectronicDevice("Lg", 6);
    eD->display();
    cout << endl;
    ElectronicDevice* sD = new SmartDevice("Apple", 10, 1);
    sD->display();
    cout << endl;
    ElectronicDevice* sP = new SmartPhone("Samsung", 11, 0, 256, 48, 150000);
    sP->display();
    cout << endl;
    delete eD;
    eD = nullptr;
    delete sD;
    sD = nullptr;
    delete sP;
    sP = nullptr;

    SmartDevice* sd0 = new SmartDevice("SuperEurope", 19, 0);
    sd0->display();
    cout << endl;
    SmartPhone* sp0 = new SmartPhone("Vivo", 41, 1, 512, 72, 11000);
    sp0->display();
    cout << endl;

    ElectronicDevice** ed1 = new ElectronicDevice * [2] { sd0, sp0 };

    for (int i = 0; i < 2; i++) {
        ed1[i]->display();
        cout << endl;
    }
    delete[] ed1;

    //_______________________________________________________________________________

    ElectronicDevice ed("Sony", 5);
    ed.display();
    cout << endl;
    SmartDevice sd("SuperAsia", 14, 0);
    sd.display();
    cout << endl;
    SmartPhone sp("Oppo", 18, 0, 64, 32, 10000);
    sp.display();
    cout << endl;

    SmartDevice sd1("SuperEurope", 19, 0); //stack obj
    sd1.display();
    cout << endl;
    SmartPhone sp1("Vivo", 41, 1, 512, 72, 11000); //stack obj
    sp1.display();
    cout << endl;

    ElectronicDevice* ed2[] = { &sd1, &sp1 };
    for (int i = 0; i < 2; i++) {
        ed2[i]->display();
        cout << endl;
    }
    pauseScreen();
}