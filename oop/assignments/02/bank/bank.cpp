#include "bank.h"

int BankAccount::m_TOTAL_ACCOUNTS = 0;
float BankAccount::m_TOTAL_BANK_BALANCE = 0.0f;

BankAccount::BankAccount() {
    m_accountNumber = 0;
    m_holderName = "Unknown";
    m_balance = 0.0f;
    m_TOTAL_ACCOUNTS++;
}

BankAccount::BankAccount(int accNo, const string& name, float balance) {
    m_accountNumber = accNo;
    m_holderName = name;
    m_balance = balance;
    m_TOTAL_ACCOUNTS++;
    m_TOTAL_BANK_BALANCE += balance;
}

BankAccount::BankAccount(const BankAccount& obj) {
    m_accountNumber = obj.m_accountNumber;
    m_holderName = obj.m_holderName;
    m_balance = obj.m_balance;

    m_TOTAL_ACCOUNTS++;
    m_TOTAL_BANK_BALANCE += m_balance;
}

BankAccount::~BankAccount() {
    m_TOTAL_ACCOUNTS--;
    m_TOTAL_BANK_BALANCE -= m_balance;
    cout << "Destructor called for Account: " << m_accountNumber << endl;
}

void BankAccount::deposit(float amount) {
    if (amount > 0) {
        this->m_balance += amount;
        m_TOTAL_BANK_BALANCE += amount;
    }
}

void BankAccount::withdraw(float amount) {
    if (amount > 0 && amount <= this->m_balance) {
        this->m_balance -= amount;
        m_TOTAL_BANK_BALANCE -= amount;
    }
}

void BankAccount::display() const {
    cout << "Account Number: " << m_accountNumber << endl;
    cout << "Holder Name   : " << m_holderName << endl;
    cout << "Balance       : " << m_balance << endl;
    cout << "-----------------------------" << endl;
}

void BankAccount::showSummary() const {
    cout << "[SUMMARY] " << m_holderName << " | Balance: " << m_balance << endl;
}

void BankAccount::showBankStats() {
    cout << "\n===== BANK STATISTICS =====" << endl;
    cout << "Total Accounts     : " << m_TOTAL_ACCOUNTS << endl;
    cout << "Total Bank Balance : " << m_TOTAL_BANK_BALANCE << endl;
}

float BankAccount::getBalance() const {
    return m_balance;
}

int BankAccount::getAccountNumber() const {
    return m_accountNumber;
}

string BankAccount::getHolderName() const {
    return m_holderName;
}

/*__________________________________________________________________________________________________________________*/

Loan::Loan(int id, float amount, float rate, int months) {
    m_loanId = id;
    m_amount = amount;
    m_interestRate = rate;
    m_durationMonths = months;
}

void Loan::displayLoan() const {
    cout << "Loan ID         : " << m_loanId << endl;
    cout << "Loan Amount     : " << m_amount << endl;
    cout << "Interest Rate   : " << m_interestRate << "%" << endl;
    cout << "Duration        : " << m_durationMonths << " months" << endl;
}

/*_____________________________________________________________________________________________________________*/

void showLoanDetails(const BankAccount& acc, const Loan& loan) {
    cout << "\n=== FRIEND FUNCTION ACCESS ===" << endl;

    cout << "Account Holder : " << acc.m_holderName << endl;
    cout << "Account Balance: " << acc.m_balance << endl;

    cout << "Loan ID        : " << loan.m_loanId << endl;
    cout << "Loan Amount    : " << loan.m_amount << endl;
    cout << "Interest Rate  : " << loan.m_interestRate << "%" << endl;
    cout << "Duration       : " << loan.m_durationMonths << " months" << endl;
}

BankAccount mergeAccounts(const BankAccount& a1, const BankAccount& a2) {
    return BankAccount(
        a1.getAccountNumber() + a2.getAccountNumber(),
        a1.getHolderName() + " & " + a2.getHolderName(),
        a1.getBalance() + a2.getBalance()
    );
}