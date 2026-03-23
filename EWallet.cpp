#include<iostream>
using namespace std;

class EWallet
{
private:
int balance;

public:
EWallet()
{
balance = 0;
}

void set_balance(int new_balance)
{
    if (new_balance >= 0)
    {
        balance = new_balance;
    }
    else
    {
        cout << "Invalid balance!" << endl;
    }
}

int get_balance()
{
    return balance;
}

void spend(int amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
    }
    else
    {
        cout << "Payment declined!" << endl;
    }
}
};

int main()
{
EWallet wallet;

int initial_balance;
int spend_amount;

cin >> initial_balance;
cin >> spend_amount;

wallet.set_balance(initial_balance);
wallet.spend(spend_amount);

cout << "Final balance: " << wallet.get_balance() << endl;

return 0;
}
