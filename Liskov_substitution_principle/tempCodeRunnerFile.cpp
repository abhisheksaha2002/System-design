 
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