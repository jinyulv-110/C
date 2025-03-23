#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    BankAccount(const std::string& number, const std::string& holder, double initialBalance)
        : accountNumber(number), accountHolder(holder), balance(initialBalance) {
        if (initialBalance < 0) {
            throw std::invalid_argument("?????????");
        }
    }

    void deposit(double amount) {
        if (amount < 0) {
            throw std::invalid_argument("?????????");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount < 0) {
            throw std::invalid_argument("?????????");
        }
        if (amount > balance) {
            throw std::invalid_argument("????");
        }
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

    void display() const {
        std::cout << "???: " << accountNumber << "\n"
                  << "?????: " << accountHolder << "\n"
                  << "??: " << balance << "\n";
    }
};

int main() {
    std::vector<BankAccount> accounts;

    // ????
    accounts.emplace_back("123456789", "Alice", 1000.0);
    accounts.emplace_back("987654321", "Bob", 500.0);

    // ??
    accounts[0].deposit(200.0);
    accounts[1].deposit(100.0);

    // ??
    try {
        accounts[0].withdraw(300.0);
        accounts[1].withdraw(600.0);  // ???????
    } catch (const std::invalid_argument& e) {
        std::cerr << "??: " << e.what() << "\n";
    }

    // ??????
    for (const auto& account : accounts) {
        account.display();
        std::cout << "-----------------\n";
    }

    return 0;
}
