#include<bits/stdc++.h>
using namespace std;
class Bank{
private:
    double balance;


public:
    Bank(double b){
        balance = b;
    }

    void deposit(double amount){
        balance+=amount;
    }

    void withdraw(double amount){
        if(amount<=balance){
            balance-=amount;

        }
        else{
            cout<<"futi kauri h tere pass";
        }
    }
    
    double getBalance(){
        return balance;
    }

};

int main(){
    Bank acc(100000);
    
    acc.deposit(500);
    acc.withdraw(500);

    cout<<acc.getBalance();
    
}