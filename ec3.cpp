#include <iostream>
#include <string>

class Account {
protected:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    Account(const std::string& number, const std::string& holder, double initialBalance)
        : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

    virtual ~Account() = default;

    virtual Account* operator+(Account& other) {
        balance += other.balance;
        other.balance = 0;
        return this;
    }

    virtual std::ostream& display(std::ostream& os) const {
        os << "Account Details for " << accountType() << " Account (ID: " << accountNumber << "):" << std::endl;
        os << "   Holder: " << accountHolder << std::endl;
        os << "   Balance: $" << balance << std::endl;
        displaySpecificDetails(os);
        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, const Account& account) {
        return account.display(os);
    }

    virtual std::string accountType() const {
        return "Generic";
    }

    virtual void displaySpecificDetails(std::ostream& os) const {
    
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double rate)
        : Account(number, holder, initialBalance), interestRate(rate) {}

    Account* operator+(Account& other) override {
        if (SavingsAccount* derived = dynamic_cast<SavingsAccount*>(&other)) {
            balance += derived->balance;
            derived->balance = 0;
            return this;
        }
        return &other;
    }

    std::string accountType() const override {
        return "Savings";
    }

    void displaySpecificDetails(std::ostream& os) const override {
        os << "   Interest Rate: " << (interestRate * 100) << "%" << std::endl;
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(const std::string& number, const std::string& holder, double initialBalance, double limit)
        : Account(number, holder, initialBalance), overdraftLimit(limit) {}

    Account* operator+(Account& other) override {
        if (CurrentAccount* derived = dynamic_cast<CurrentAccount*>(&other)) {
            balance += derived->balance;
            derived->balance = 0;
            return this;
        }
        return &other;
    }

    std::string accountType() const override {
        return "Current";
    }

    void displaySpecificDetails(std::ostream& os) const override {
        os << "   Overdraft Limit: $" << overdraftLimit << std::endl;
    }
};

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    std::cout << savings << std::endl;
    std::cout << current << std::endl;

    savings.operator+(current);

    std::cout << savings << std::endl;
    std::cout << current << std::endl;

    return 0;
}
