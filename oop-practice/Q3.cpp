#include <iostream>
#include <string>
using namespace std;

class Customer
{
protected:
    int customerID;
    string name;

public:
    void getCustomerData()
    {
        cout << "Enter Customer ID: ";
        cin >> customerID;

        cin.ignore();
        cout << "Enter Customer Name: ";
        getline(cin, name);
    }
};

class Account
{
protected:
    float balance;

public:
    void getAccountData()
    {
        cout << "Enter Account Balance: ";
        cin >> balance;
    }

    void deposit()
    {
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        balance = balance + amount;
    }

    void withdraw()
    {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= balance)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    float getBalance()
    {
        return balance;
    }
};

class BankServices : public Customer, public Account
{
public:
    float calculateSimpleInterest(float rate, float time)
    {
        return (balance * rate * time) / 100;
    }

    void display(float interest)
    {
        cout << "\n----- Bank Details -----" << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Customer Name: " << name << endl;
        cout << "Updated Balance: " << balance << endl;
        cout << "Simple Interest: " << interest << endl;
    }
};

int main()
{
    BankServices customer;
    float rate, time;
    int choice;

    customer.getCustomerData();
    customer.getAccountData();

    cout << "\n1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Skip Transaction" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        customer.deposit();
    }
    else if (choice == 2)
    {
        customer.withdraw();
    }

    cout << "\nEnter Rate of Interest: ";
    cin >> rate;

    cout << "Enter Time in Years: ";
    cin >> time;

    float interest = customer.calculateSimpleInterest(rate, time);

    customer.display(interest);

    return 0;
}