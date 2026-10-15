#include "main.h"

class Loan;

class BankAccount {
private:
    int m_accountNumber;
    string m_holderName;
    float m_balance;

    static int m_TOTAL_ACCOUNTS;
    static float m_TOTAL_BANK_BALANCE;

public:
    BankAccount();
    BankAccount(int, const string&, float);
    BankAccount(const BankAccount&);
    ~BankAccount();

    void deposit(float);
    void withdraw(float);
    void display() const;
    void showSummary() const;

    static void showBankStats();

    float getBalance() const;
    int getAccountNumber() const;
    string getHolderName() const;

    friend void showLoanDetails(const BankAccount&, const Loan&);
    friend class Loan;
};

class Loan {
private:
    int m_loanId;
    float m_amount;
    float m_interestRate;
    int m_durationMonths;

public:
    Loan(int, float, float, int);
    void displayLoan() const;
    friend void showLoanDetails(const BankAccount&, const Loan&);
};

void showLoanDetails(const BankAccount&, const Loan&);
BankAccount mergeAccounts(const BankAccount& a1, const BankAccount& a2);