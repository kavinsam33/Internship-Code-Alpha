#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }
};

class Account {
private:
    int accountNumber;
    double balance;
    vector<Transaction> history;

public:
    Account(int accNo) {
        accountNumber = accNo;
        balance = 0;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Amount Deposited Successfully!\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amount;
            history.push_back(Transaction("Withdrawal", amount));
            cout << "Amount Withdrawn Successfully!\n";
        }
    }

    void transfer(Account &receiver, double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amount;
            receiver.balance += amount;

            history.push_back(Transaction("Transfer Sent", amount));
            receiver.history.push_back(
                Transaction("Transfer Received", amount));

            cout << "Fund Transfer Successful!\n";
        }
    }

    void showTransactions() {
        cout << "\nTransaction History:\n";
        if (history.empty()) {
            cout << "No Transactions Found.\n";
            return;
        }

        for (int i = 0; i < history.size(); i++) {
            cout << i + 1 << ". "
                 << history[i].type
                 << " : Rs." << history[i].amount << endl;
        }
    }
};

class Customer {
private:
    int customerId;
    string name;
    Account account;

public:
    Customer(int id, string n, int accNo)
        : account(accNo) {
        customerId = id;
        name = n;
    }

    int getCustomerId() {
        return customerId;
    }

    Account& getAccount() {
        return account;
    }

    void display() {
        cout << "\nCustomer ID : " << customerId;
        cout << "\nName        : " << name;
        cout << "\nAccount No  : "
             << account.getAccountNumber();
        cout << "\nBalance     : Rs."
             << account.getBalance() << endl;
    }
};

int main() {
    vector<Customer> customers;
    int choice;

    do {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Create Customer Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Funds\n";
        cout << "5. Display Customer Details\n";
        cout << "6. View Transaction History\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, accNo;
            string name;

            cout << "Enter Customer ID: ";
            cin >> id;

            cin.ignore();
            cout << "Enter Customer Name: ";
            getline(cin, name);

            cout << "Enter Account Number: ";
            cin >> accNo;

            customers.push_back(
                Customer(id, name, accNo));

            cout << "Account Created Successfully!\n";
        }

        else if (choice == 2) {
            int id;
            double amount;

            cout << "Enter Customer ID: ";
            cin >> id;
            cout << "Enter Amount: ";
            cin >> amount;

            for (auto &c : customers) {
                if (c.getCustomerId() == id) {
                    c.getAccount().deposit(amount);
                }
            }
        }

        else if (choice == 3) {
            int id;
            double amount;

            cout << "Enter Customer ID: ";
            cin >> id;
            cout << "Enter Amount: ";
            cin >> amount;

            for (auto &c : customers) {
                if (c.getCustomerId() == id) {
                    c.getAccount().withdraw(amount);
                }
            }
        }

        else if (choice == 4) {
            int senderId, receiverId;
            double amount;

            cout << "Enter Sender Customer ID: ";
            cin >> senderId;

            cout << "Enter Receiver Customer ID: ";
            cin >> receiverId;

            cout << "Enter Amount: ";
            cin >> amount;

            Customer *sender = nullptr;
            Customer *receiver = nullptr;

            for (auto &c : customers) {
                if (c.getCustomerId() == senderId)
                    sender = &c;
                if (c.getCustomerId() == receiverId)
                    receiver = &c;
            }

            if (sender && receiver) {
                sender->getAccount().transfer(
                    receiver->getAccount(), amount);
            } else {
                cout << "Customer Not Found!\n";
            }
        }

        else if (choice == 5) {
            int id;
            cout << "Enter Customer ID: ";
            cin >> id;

            for (auto &c : customers) {
                if (c.getCustomerId() == id) {
                    c.display();
                }
            }
        }

        else if (choice == 6) {
            int id;
            cout << "Enter Customer ID: ";
            cin >> id;

            for (auto &c : customers) {
                if (c.getCustomerId() == id) {
                    c.getAccount().showTransactions();
                }
            }
        }

    } while (choice != 7);

    cout << "Thank You for Using Banking System!\n";

    return 0;
}