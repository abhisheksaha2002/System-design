#include <iostream>
#include <vector>
#include <typeinfo>
#include <stdexcept>

using namespace std;


class DepositOnlyAccount {
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount {
public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawableAccount {
private:
    double balance;

public:
    SavingAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};

class CurrentAccount : public WithdrawableAccount {
    private:
        double balance;
    
    public:
        CurrentAccount() { 
            balance = 0; 
        }
    
        void deposit(double amount) {
            balance += amount;
            cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
        }
    
        void withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
            } else {
                cout << "Insufficient funds in Current Account!\n";
            }
        }
    };

class FixedTermAccount : public DepositOnlyAccount {
private:
    double balance;

public:
    FixedTermAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }
};

class BankClient {
private:
    vector<WithdrawableAccount*> withdrawableAccounts;
    vector<DepositOnlyAccount*> depositOnlyAccounts;

public:
    BankClient( vector<WithdrawableAccount*> withdrawableAccounts, 
        vector<DepositOnlyAccount*> depositOnlyAccounts) { 
        this->withdrawableAccounts = withdrawableAccounts; 
        this->depositOnlyAccounts = depositOnlyAccounts;
    }

    void processTransactions() {
        for (WithdrawableAccount* acc : withdrawableAccounts) {
            acc->deposit(1000);
            acc->withdraw(500); 
        }
        for (DepositOnlyAccount* acc : depositOnlyAccounts) {
            acc->deposit(5000);
        }
    }
};

int main() {
    vector<WithdrawableAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient (withdrawableAccounts, depositOnlyAccounts);
    client->processTransactions();

    return 0;
}

    
    //     #include <iostream>
// using namespace std;

// class DepositOnlyAccount {
// public:
//     virtual void deposit(double amount) = 0;
// };

// class WithdrawableAccount : public DepositOnlyAccount {
// public:
//     virtual void withdraw(double amount) = 0;
// };

// class SavingAccount : public WithdrawableAccount {
// public:
//     void deposit(double amount) {
//         cout << "Deposited Rs " << amount
//              << " in Savings Account" << endl;
//     }

//     void withdraw(double amount) {
//         cout << "Withdrawn Rs " << amount
//              << " from Savings Account" << endl;
//     }
// };

// class CurrentAccount : public WithdrawableAccount {
// public:
//     void deposit(double amount) {
//         cout << "Deposited Rs " << amount
//              << " in Current Account" << endl;
//     }

//     void withdraw(double amount) {
//         cout << "Withdrawn Rs " << amount
//              << " from Current Account" << endl;
//     }
// };

// class FixedTermAccount : public DepositOnlyAccount {
// public:
//     void deposit(double amount) {
//         cout << "Deposited Rs " << amount
//              << " in Fixed Term Account" << endl;
//     }
// };

// int main() {

//     WithdrawableAccount* acc1 = new SavingAccount();

//     acc1->deposit(1000);
//     acc1->withdraw(500);

//     cout << endl;

//     WithdrawableAccount* acc2 = new CurrentAccount();

//     acc2->deposit(1000);
//     acc2->withdraw(500);

//     cout << endl;

//     DepositOnlyAccount* acc3 = new FixedTermAccount();

//     acc3->deposit(5000);

//     return 0;
// }
