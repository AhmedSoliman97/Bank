#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>
class Bank;

class account
{
    friend class Bank;
    friend std::ostream & operator << (std::ostream &out, const account &obj); // to print account object
    private:

    std::string firstName,lastName;
    int accountNumber;
    float balance;
    static int nextAccountNumber;

    public:
        account(const std::string& f_name,const std::string& l_name,float& m_balance);
        std::string operator<<(const account& m_account);


};

#endif // ACCOUNT_H
