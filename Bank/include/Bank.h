#ifndef BANK_H
#define BANK_H

#include<iostream>
#include <map>

class account; //to declare the account not the all details of the class account

class Bank
{

    Bank(const Bank& other)= delete;
    private:
       Bank(){};
       //std::map<int,account> accounts;  the same as under
       std::map<int,account*> accounts;
       int tempAccoutNum=0;
    public:
        static Bank& createBank(){
            static Bank obj;
            return obj;
        };
        void openAccount(std::string f_name,std::string l_name,float user_balance);
        void Deposit(long accountnumber,float amount);
        void Withdraw(long accountnumber ,float amount);
        float balanceEnquiry(long accountnumber);
        void deleteAccount(long accountnumber);
        void showAllAccounts();
        int getAccountNumber()const;
        ~Bank();

};

#endif // BANK_H
