#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <limits>
#include <conio.h>

using namespace std;

struct User {
    string name, pin;
    float balance = 0.0, daily_withdrawal = 0.0;
    vector<string> transactions;
};

class ATM {
private:
    map<string, User> users;
    string currentUser;

public:
    ATM() { loadUsers(); }

    void loadUsers() {
        ifstream file("users.txt");
        if (!file) return;
        string account, name, pin;
        float balance, daily_withdrawal;
        while (file >> account >> name >> pin >> balance >> daily_withdrawal) {
            users[account] = {name, pin, balance, daily_withdrawal};
        }
        file.close();
    }

    void saveUsers() {
        ofstream file("users.txt");
        for (const auto &entry : users) {
            file << entry.first << " " << entry.second.name << " " 
                 << entry.second.pin << " " << entry.second.balance 
                 << " " << entry.second.daily_withdrawal << endl;
        }
        file.close();
    }

    bool login() {
        string account, pin;
        int attempts = 3;
        while (attempts--) {
            cout << "Enter Account Number: ";
            cin >> account;
            cout << "Enter PIN: ";
            pin = maskInput();
            if (account == "admin" && pin == "admin123") {
                showAdminPanel();
                return false;
            }
            if (users.count(account) && users[account].pin == pin) {
                currentUser = account;
                cout << "\n Welcome, " << users[currentUser].name << "! 🎉\n";
                return true;
            }
            cout << "Invalid credentials! Remaining attempts: " << attempts << "\n";
        }
        cout << "Too many failed attempts. Exiting.\n";
        exit(0);
    }

    void registerUser() {
        string account, name, pin;
        cout << "Enter a new Account Number: ";
        cin >> account;
        cout << "Enter your Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Set a PIN: ";
        pin = maskInput();
        users[account] = {name, pin, 0.0, 0.0};
        saveUsers();
        cout << "Account registered successfully!\n";
    }

    void atmMachine() {
        int choice;
        do {
            cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. View Transactions\n5. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
                case 1: deposit(); break;
                case 2: withdraw(); break;
                case 3: cout << "  Balance: Rs." << users[currentUser].balance << "\n"; break;
                case 4: viewTransactions(); break;
                case 5: cout << "Thank you for using the ATM!\n"; break;
                default: cout << " Invalid option! Try again.\n";
            }
        } while (choice != 5);
    }

    void deposit() {
        float amount;
        cout << "Enter deposit amount: ";
        cin >> amount;
        if (amount <= 0) {
            cout << " Invalid amount!\n";
            return;
        }
        users[currentUser].balance += amount;
        users[currentUser].transactions.push_back("Deposited: Rs." + to_string(amount));
        saveUsers();
        cout << " Deposit successful!\n";
    }

    void withdraw() {
        float amount;
        cout << "Enter withdrawal amount: ";
        cin >> amount;

        if (amount <= 0 || amount > users[currentUser].balance || users[currentUser].daily_withdrawal + amount > 10000) {
            cout << " Invalid withdrawal (Check balance or daily limit Rs. 10000)!\n";
            return;
        }

        users[currentUser].balance -= amount;
        users[currentUser].daily_withdrawal += amount;
        users[currentUser].transactions.push_back("Withdrawn: Rs." + to_string(amount));
        saveUsers();
        
        cout << " Withdrawal successful! Dispensed Notes:\n";
        dispenseNotes(amount);
    }

    void viewTransactions() {
        cout << users[currentUser].name << "'s Transactions:\n";
        for (const string &t : users[currentUser].transactions) {
            cout << t << endl;
        }
    }

    void showAdminPanel() {
        cout << "\n Admin Panel - All Users:\n";
        for (const auto &entry : users) {
            cout << "Account: " << entry.first << " | Name: " << entry.second.name 
                 << " | Balance: Rs." << entry.second.balance << "\n";
        }
        exit(0);
    }

    string maskInput() {
        string pin = "";
        char ch;
        while ((ch = _getch()) != '\r') {
            pin += ch;
            cout << "*";
        }
        cout << endl;
        return pin;
    }

    void dispenseNotes(int amount) {
        cout << "Rs. 500 x " << (amount / 500) << endl;
        amount %= 500;
        cout << "Rs. 200 x " << (amount / 200) << endl;
        amount %= 200;
        cout << "Rs. 100 x " << (amount / 100) << endl;
    }
};

int main() {
    ATM atm;
    int option;

    while (true) {
        cout << "\n1. Login\n2. Register\nChoose an option: ";
        cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " Invalid input! Enter 1 or 2.\n";
            continue;
        }

        if (option == 1 || option == 2) break;
        cout << " Invalid option! Enter 1 or 2.\n";
    }

    if (option == 2) atm.registerUser();
    while (!atm.login());
    atm.atmMachine();
    return 0;
}
