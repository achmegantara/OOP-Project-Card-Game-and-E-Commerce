#include <iostream>

#include "Account.hpp"
#include "CheckingAccount.hpp"
#include "SavingAccount.hpp"

using namespace std;

Account::Account(double initial_balance)
: balance(0)
{
    if(initial_balance <= 0.0){
        cout << "invalid balance!" << endl;
        balance = 0.0;
    } else
    {
        balance = initial_balance;
    }
}

void Account::credit(double credit)
{
    if (credit >= 0.0){
        balance = balance + credit;
    } else {
        balance = balance + 0;
        cout << "cannot credit negative amount" << endl;
    }
}

bool Account::debit(double debit){
    if(debit >= 0.0){
        if (debit <= balance){
            balance = balance - debit;
            return true;
        } else
        {
            return false;
        }
    cout << "canoot debit negative amount." << endl;
    return false;
    }
    }

CheckingAccount::CheckingAccount(double balance, double feeTrans)
: Account(balance), feeTransaction(feeTrans)
{

}

//credit
void CheckingAccount::credit(double credit){
    Account::credit(credit+feeTransaction);
}

//debit
void CheckingAccount::debit(double debit){
    if(Account::debit(debit)){
        Account::debit(feeTransaction);
    } else {
        cout << "error checking account" << endl;
    }
}

SavingAccount::SavingAccount(double balance, double interestRate)
: Account(balance), rateInterest(interestRate)
{
    //constructor
}

//calculating interest
double SavingAccount::calInterest() const
{
    return Account::getBalance()*rateInterest;
}

int main(){
    SavingAccount save(1000, 0.8);
    CheckingAccount cek(1000, 0.5);

    //save
    cout << "Initial balance : " << save.getBalance() << endl;
    save.credit(50);
    cout << "after credit 50 : " << save.getBalance() << endl;
    save.debit(40);
    cout << "after debit 40 : " << save.getBalance() << endl;

    //cek
    cout << "checking initial balance : " << cek.getBalance() << endl;
    cek.credit(40);
    cout << "after credit 40 : " << cek.getBalance() << endl;
    cek.debit(100);
    cout << "after debit 100 :  " << cek.getBalance() << endl;


    return 0;
}