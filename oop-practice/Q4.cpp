#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    float balance;

public:
    BankAccount()
    {
        accountNumber = 0;
        accountHolderName = "";
        balance = 0;
    }

    void getData()
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cin.ignore();
        cout << "Enter Account Holder Name: ";
        getline(cin, accountHolderName);

        cout << "Enter Balance: ";
        cin >> balance;
    }

    BankAccount operator+(float amount)
    {
        balance = balance + amount;
        return *this;
    }

    BankAccount operator-(float amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }

        return *this;
    }

    bool operator>(BankAccount &account)
    {
        return balance > account.balance;
    }

    BankAccount& operator+=(BankAccount &account)
    {
        float amount;

        cout << "Enter amount to transfer: ";
        cin >> amount;

        if (amount <= balance)
        {
            balance = balance - amount;
            account.balance = account.balance + amount;
        }
        else
        {
            cout << "Insufficient balance for transfer." << endl;
        }

        return *this;
    }

    friend ostream& operator<<(ostream &out, BankAccount &account)
    {
        out << "Account Number: " << account.accountNumber << endl;
        out << "Account Holder Name: " << account.accountHolderName << endl;
        out << "Balance: " << account.balance << endl;

        return out;
    }
};

int main()
{
    BankAccount account1, account2;
    float amount;

    cout << "Enter details of Account 1" << endl;
    account1.getData();

    cout << "\nEnter details of Account 2" << endl;
    account2.getData();

    cout << "\nEnter amount to deposit in Account 1: ";
    cin >> amount;
    account1 = account1 + amount;

    cout << "\nEnter amount to withdraw from Account 1: ";
    cin >> amount;
    account1 = account1 - amount;

    cout << "\nAccount 1 Details:" << endl;
    cout << account1;

    cout << "\nAccount 2 Details:" << endl;
    cout << account2;

    if (account1 > account2)
    {
        cout << "\nAccount 1 has a higher balance." << endl;
    }
    else
    {
        cout << "\nAccount 2 has a higher or equal balance." << endl;
    }

    cout << "\nTransferring money from Account 1 to Account 2" << endl;
    account1 += account2;

    cout << "\nAccount 1 Details After Transfer:" << endl;
    cout << account1;

    cout << "\nAccount 2 Details After Transfer:" << endl;
    cout << account2;

    return 0;
}