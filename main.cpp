#include <iostream>
#include <fstream>
#include <iomanip>

class BankAccount
{
private:
    int accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount() : accountNumber(0), accountHolderName(""), balance(0.0) {}

    // Function to create a new account
    void createAccount()
    {
        std::cout << "Enter Account Number: ";
        std::cin >> accountNumber;
        std::cin.ignore(); // clear the input buffer
        std::cout << "Enter Account Holder Name: ";
        std::getline(std::cin, accountHolderName);
        std::cout << "Enter Initial Balance: ";
        std::cin >> balance;

        if (balance < 0)
        {
            std::cout << "Invalid balance! Setting balance to 0.\n";
            balance = 0;
        }

        std::cout << "Account created successfully!\n";
    }

    // Function to deposit money into the account
    void deposit()
    {
        double amount;
        std::cout << "Enter the amount to deposit: ";
        std::cin >> amount;

        if (amount <= 0)
        {
            std::cout << "Invalid amount! Deposit amount must be positive.\n";
            return;
        }

        balance += amount;
        std::cout << "Amount deposited successfully!\n";
    }

    // Function to withdraw money from the account
    void withdraw()
    {
        double amount;
        std::cout << "Enter the amount to withdraw: ";
        std::cin >> amount;

        if (amount <= 0)
        {
            std::cout << "Invalid amount! Withdrawal amount must be positive.\n";
            return;
        }

        if (amount > balance)
        {
            std::cout << "Insufficient balance!\n";
        }
        else
        {
            balance -= amount;
            std::cout << "Amount withdrawn successfully!\n";
        }
    }

    // Function to display account details
    void displayAccount() const
    {
        std::cout << std::setw(20) << "Account Number: " << accountNumber << '\n';
        std::cout << std::setw(20) << "Account Holder: " << accountHolderName << '\n';
        std::cout << std::setw(20) << "Balance: $" << std::fixed << std::setprecision(2) << balance << '\n';
    }

    // Function to get the account number
    int getAccountNumber() const
    {
        return accountNumber;
    }

    // Function to update the account details in the file
    void updateFile() const
    {
        std::ofstream outFile("accounts.txt", std::ios::app);
        if (outFile.is_open())
        {
            outFile << accountNumber << ' ' << accountHolderName << ' ' << balance << '\n';
            outFile.close();
        }
    }
};

// Function to display the main menu
void displayMenu()
{
    std::cout << "\nBank Management System\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money\n";
    std::cout << "4. Display Account Details\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main()
{
    int choice;
    BankAccount account;

    do
    {
        displayMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            account.createAccount();
            account.updateFile();
            break;
        case 2:
            account.deposit();
            break;
        case 3:
            account.withdraw();
            break;
        case 4:
            account.displayAccount();
            break;
        case 5:
            std::cout << "Exiting the program. Thank you!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
