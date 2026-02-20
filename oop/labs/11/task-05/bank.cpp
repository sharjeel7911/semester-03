#include "bank.h"

BankAccount::BankAccount(const char* title, int accountNumber, double balance) : m_accountNumber(accountNumber), m_balance(balance) {
    if (title) {
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);
    } else {
        m_title = nullptr;
    }
}

BankAccount::~BankAccount() {
    delete[] m_title;
}

void BankAccount::display() const {
    cout << "Account Title: " << (m_title ? m_title : "N/A") << endl;
    cout << "Account Number: " << m_accountNumber << endl;
    cout << "Balance: Rs. " << m_balance << endl;
}

/*______________________________________________________________________________________________*/

SavingsAccount::SavingsAccount(const char* title, int accountNumber, double balance, double bonus) : BankAccount(title, accountNumber, balance), m_bonus(bonus) {}

void SavingsAccount::deposit(double amount) {
    if (amount > 0) {
        m_balance += amount;
        if (m_balance > 50000) {
            m_balance += m_bonus;
        }
    } else {
        cout << "Deposit amount must be positive." << endl;
    }
}

void SavingsAccount::withdraw(double amount) {
    if (amount > 0 && amount <= m_balance) {
        m_balance -= amount;
    } else {
        cout << "Invalid withdrawal amount." << endl;
    }
}

void SavingsAccount::display() const {
    cout << "Savings Account Details:" << endl;
    BankAccount::display();
    cout << "Bonus on Deposit: Rs. " << m_bonus << endl;
}

/*______________________________________________________________________________________________*/

CheckingAccount::CheckingAccount(const char* title, int accountNumber, double balance, float transactionFee) : BankAccount(title, accountNumber, balance), m_transactionFee(transactionFee) {}

void CheckingAccount::deposit(double amount) {
    if (amount > m_transactionFee) {
        m_balance += (amount - m_transactionFee);
    } else {
        cout << "Deposit amount must be greater than transaction fee." << endl;
    }
}

void CheckingAccount::withdraw(double amount) {
    if (amount > 0 && (amount + m_transactionFee) <= m_balance) {
        m_balance -= (amount + m_transactionFee);
    } else {
        cout << "Invalid withdrawal amount." << endl;
    }
}

void CheckingAccount::display() const {
    cout << "Checking Account Details:" << endl;
    BankAccount::display();
    cout << "Transaction Fee: Rs. " << m_transactionFee << endl;
}