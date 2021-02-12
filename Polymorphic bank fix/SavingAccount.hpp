#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "Account.hpp"

//inherritence
class SavingAccount : public Account
{
    public:
    SavingAccount(double,double);

    double calInterest() const;

    private:
    double rateInterest;
};


#endif