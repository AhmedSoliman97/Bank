#include <iostream>
#include "Bank.h"
#include "account.h"

using namespace std;

enum transactions {
    OPENACCOUNT=1,
    QUIT,
    WITHDRAW,
    DEPOSIT,
    BALANCEENQUIRE,
    SHOWALLACCOUNTS,
    CREATENEWACCOUNT,
    DELETEACCOUNT,

};
int account::nextAccountNumber = 1;
int main()

{
    Bank& m_Bank = Bank::createBank(); // create the one and only bank object
    int user_transation = 0;


    while( user_transation != QUIT ){

    cout<<" press 1: to open new Account\n press 2: to Quit "<<endl;
    cin>>user_transation;

       while(user_transation == OPENACCOUNT){
            string f_name,l_name;float user_balance;int action,accountNum=0;
            cout<<" please enter your personal data : 1-FirstName\t 2-lastName\n 1-";
            cin>>f_name;
            cout<<" 2-";
            cin>>l_name;
            cout<<" initial Balance: ";
            cin>>user_balance;

            m_Bank.openAccount(f_name,l_name,user_balance); //pass account obj elements to Bank
            accountNum = m_Bank.getAccountNumber(); //get the account Number
            cout<<"Account Created !!!\t"<<"with Account Number : "<<accountNum<<endl;
            while(user_transation != QUIT){

                cout<<" press 3: to Withdraw\n press 4: to Deposit\n press 5: to Display Account Balance\n press 2: to Quit\n press 6: to Display All Accounts\n press 7: to Create New Account\n press 8: to Delete Account"<<endl;
                cin>>action;
                switch(action){
                    case(WITHDRAW):
                    float num;
                    cout<<"Enter the Withdraw Number : ";
                    cin>>num;
                    m_Bank.Withdraw(accountNum,num);
                    break;
                    case(DEPOSIT):
                    float num2;
                    cout<<"Enter the Deposit Number : ";
                    cin>>num2;
                    m_Bank.Deposit(accountNum,num2);
                    break;
                    case(BALANCEENQUIRE):
                    float num4;int A_num;
                    cout<<"Enter Account Number : ";
                    cin>>A_num;
                    num4 = m_Bank.balanceEnquiry(A_num);
                    cout<<"Your Balance is : "<<num4<<endl;
                    break;
                    case(SHOWALLACCOUNTS):
                    m_Bank.showAllAccounts();
                    break;
                    case(CREATENEWACCOUNT):
                    user_transation = 2;
                    break;
                    case(DELETEACCOUNT):
                    int temp_Number;
                    cout<<"Enter Account Number : ";
                    cin>>temp_Number;
                    m_Bank.deleteAccount(temp_Number);
                    break;
                    case(QUIT):
                    user_transation=2;
                    break;
                    default:
                        //
                        ;
                }
            }

        if(action == CREATENEWACCOUNT)user_transation = 1;
       }

    }

    return 0;
}
