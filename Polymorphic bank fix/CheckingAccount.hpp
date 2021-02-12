#ifndef CHECKING_H
#define CHECKING_H

#include "Account.hpp"

//inherritence
class CheckingAccount: public Account{
    public:
    CheckingAccount(double,double);

    void credit(double);
    void debit(double);

    private:
    double feeTransaction;

};


#endif