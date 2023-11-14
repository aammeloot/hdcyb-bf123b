//
//  main.cpp
//  BankAccount
//
//  Created by Aurélien Ammeloot on 14/11/2023.
//

#include <iostream>

using namespace std;


// Class BankAccount - following iLearn Brief
class BankAccount {
    // The bank balance: double
    double balance;
public:
    // Default constructor, when create, an account has
    // a balance of zero
    BankAccount(): balance(0.0) {}
    
    // Display balance
    void displayBalance() {
        cout << "£" << balance << endl;
    }
    
    // Withdraw
    void withdraw(double amount) {
        if (amount > 0.0) {
            balance -= amount;
        }
    }
    
    // Deposit
    void deposit(double amount) {
        if (amount > 0.0) {
            balance += amount;
        }
    }
};

// Menu for the program
class Menu {
    // The relies on a BankAccount to exist
    // This is a relationship called composition
    BankAccount account;
public:
    void display()
    {
        int selection;
        double amount;
        
        do {
            // Menu display
            cout << "1 - Display balance.\n2 - Deposit.\n3 - Withdraw.\n4 - Stop.\n";
            cout << "Enter your selection:\n";
            cin >> selection;
            
            switch (selection) {
                case 1:
                    account.displayBalance();
                    break;
                case 2:
                    cout << "Enter amount.\n";
                    cin >> amount;
                    account.deposit(amount);
                    break;
                case 3:
                    cout << "Enter amount.\n";
                    cin >> amount;
                    account.withdraw(amount);
                    break;
                case 4:
                    return;
                default:
                    break;
            }
        } while(selection != 4);
    }
};


int main(int argc, const char * argv[]) {
    Menu m;
    m.display();
    return 0;
}
