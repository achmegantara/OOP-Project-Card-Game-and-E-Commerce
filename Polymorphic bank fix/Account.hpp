#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
    public:
    Account(double);

    void credit(double);
    bool debit(double);
    double getBalance() const
    {
        return balance;
    } 

    private:
    double balance;

};

#endif