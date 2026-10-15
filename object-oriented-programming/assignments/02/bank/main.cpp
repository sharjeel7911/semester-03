#include "bank.h"

int main() {
    clearScreen();

    cout << "================ POINTER BASED OBJECTS (DYNAMIC) ================\n";

    BankAccount* pAcc1 = new BankAccount(101, "Ali", 5000);
    pAcc1->deposit(1500);
    pAcc1->withdraw(1000);
    pAcc1->display();

    BankAccount* pAcc2 = new BankAccount(*pAcc1);
    pAcc2->display();

    BankAccount mergedPtr = mergeAccounts(*pAcc1, *pAcc2);
    mergedPtr.display();

    const BankAccount* constAcc = new BankAccount(202, "Sara", 8000);
    constAcc->showSummary();

    BankAccount::showBankStats();

    delete pAcc1;
    delete pAcc2;
    delete constAcc;

    cout << "\n================ ARRAY USING POINTER (DYNAMIC ARRAY) ================\n";

    BankAccount* arr = new BankAccount[2]{ BankAccount(301, "Usman", 3000), BankAccount(302, "Hina", 4000) };

    for (int i = 0; i < 2; i++) {
        (arr + i)->display();
    }

    delete[] arr;

    cout << "\n================ ARRAY OF POINTERS ================\n";

    BankAccount* accPtrs[2];
    accPtrs[0] = new BankAccount(401, "Hamza", 7000);
    accPtrs[1] = new BankAccount(402, "Noor", 9000);

    for (int i = 0; i < 2; i++) accPtrs[i]->display();
    for (int i = 0; i < 2; i++) delete accPtrs[i];

    /*________________________________________________________________________________________________________________*/

    cout << "\n================ STACK BASED OBJECTS ================\n";

    BankAccount acc1(501, "Ayesha", 6000);
    BankAccount acc2(502, "Bilal", 8500);

    acc1.deposit(1000);
    acc2.withdraw(500);

    acc1.display();
    acc2.display();

    BankAccount accCopy = acc1;
    accCopy.display();

    BankAccount mergedStack = mergeAccounts(acc1, acc2);
    mergedStack.display();

    cout << "\n================ FRIEND FUNCTION & LOAN =================\n";

    Loan loan1(1, 100000, 5.5f, 24);
    loan1.displayLoan();

    showLoanDetails(acc1, loan1);

    cout << "\n================ FINAL BANK STATS =================\n";
    BankAccount::showBankStats();

    cout << "\n===== Program End (Destructors will now be called) =====\n";
    pauseScreen();
    return 0;
}