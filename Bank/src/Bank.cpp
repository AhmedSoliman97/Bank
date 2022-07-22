#include "account.h"
#include "Bank.h"


void Bank::openAccount(std::string f_name,std::string l_name,float user_balance ){

    // account acc(f_name,l_name,user_balance);
    // accounts[acc.accountNumber] = acc;
    // tempAccoutNum = acc.accountNumber;

    account* acc = new account(f_name,l_name,user_balance);
    accounts[(*acc).accountNumber] = acc;
    tempAccoutNum = (*acc).accountNumber;
};

int Bank::getAccountNumber()const{
return tempAccoutNum;
}

float Bank::balanceEnquiry(long accountnumber){

    return accounts.at(accountnumber)->balance;
};


void Bank::deleteAccount(long accountnumber){
     accounts.erase(accountnumber);
     std::cout<<"Account Deleted"<<std::endl;
};

void Bank::showAllAccounts(){
    int i=1;
    std::map<int,account*>::iterator it; //to loop the whole map
    for(it=accounts.begin() ; it != accounts.end() ;it++){
        std::cout<<"account_"<<i<<" username is : "<<it->second->firstName<<it->second->lastName<<"\t with balance: "<<it->second->balance<<"\t and Account Number is : "<<it->second->accountNumber<<std::endl;
        i++;
    }
    if(i==1)std::cout<<"No Accounts in the Bank yet"<<std::endl;
};

void Bank::Deposit(long accountnumber, float amount){
    accounts.at(accountnumber)->balance +=amount;
    std::cout<<"Deposit Done"<<std::endl;

};

void Bank::Withdraw(long accountnumber ,float amount){
     accounts.at(accountnumber)->balance -= amount;
     if(accounts.at(accountnumber)->balance < 0)accounts.at(accountnumber)->balance=0;
     std::cout<<"Withdraw Done"<<std::endl;
};



Bank::~Bank(){

    // to remove all the objects in the heap
   std::map<int,account*>::iterator it;
    for(it=accounts.begin() ; it != accounts.end() ;it++){
       delete it->second;
    }

}
