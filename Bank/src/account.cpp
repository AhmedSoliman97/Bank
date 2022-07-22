#include<stdlib.h>
#include<time.h>
#include "account.h"




account::account(const std::string& f_name,const std::string& l_name,float& m_balance):firstName(f_name),lastName(l_name),accountNumber(account::nextAccountNumber),balance(m_balance)
{
   srand(time(nullptr));
   account::nextAccountNumber = rand() % 100 + 1; //random number from 1 to 100
};


std::string account::operator<< (const account& m_account){

    std::cout<<m_account.firstName<<" "<<m_account.lastName<<"with balance: "<<m_account.balance<<"Account Number : "<<m_account.accountNumber<<std::endl;

}

/********** to print account details from account object **********/
std::ostream & operator << (std::ostream &out, const account &obj)
{
    out << obj.firstName<<" "<<obj.lastName<<"with balance : "<<obj.balance<< std::endl;
    return out;
}

/********************************************************************/
