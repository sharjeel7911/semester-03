#include "../main.h"

class BankAccount {
protected:
    char* m_title;
    int m_accountNumber;
    double m_balance;
public:
    BankAccount(const char* title = nullptr, int accountNumber = 0, double balance = 0);
    ~BankAccount();
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void display() const;
};

class SavingsAccount : public BankAccount {
private:
    double m_bonus;
public:
    SavingsAccount(const char* title = nullptr, int accountNumber = 0, double balance = 0, double bonus = 0);
    void deposit(double amount) override;
    void withdraw(double amount) override;
    void display() const override;
};

class CheckingAccount : public BankAccount {
private:
    float m_transactionFee;
public:
    CheckingAccount(const char* title = nullptr, int accountNumber = 0, double balance = 0, float transactionFee = 0);
    void deposit(double amount) override;
    void withdraw(double amount) override;
    void display() const override;
};