// Name: Olivia Bacca
// Date: July 31, 2026
// Course: CS-210
// Purpose: This program collects an initial investment amount,
// monthly deposit, annual interest rate, and number of
// years from the user, then displays two year-by-year
// tables projecting the investment's growth through
// monthly compounding -- one without additional
// deposits, and one with a fixed monthly deposit.

#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include "Investment.h"

using namespace std;

// Prompts for a double and re-prompts until a valid, positive number is entered.
// Exits gracefully instead of looping forever if input runs out (EOF).
double getValidatedDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.eof()) {
            cout << "\nNo more input available. Exiting.\n";
            exit(1);
        }

        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid, positive number.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Prompts for an integer and re-prompts until a valid, positive whole number is entered.
// Exits gracefully instead of looping forever if input runs out (EOF).
int getValidatedInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.eof()) {
            cout << "\nNo more input available. Exiting.\n";
            exit(1);
        }

        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid, positive whole number.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    // Collect the four required inputs
    double initialInvestment = getValidatedDouble("Initial Investment Amount: ");
    double monthlyDeposit   = getValidatedDouble("Monthly Deposit: ");
    double annualInterest   = getValidatedDouble("Annual Interest: ");
    int numberOfYears        = getValidatedInt("Number of Years: ");

    cout << "Press any key to continue...";
    cin.get();

    // Build the Investment object that owns the calculation logic
    Investment investment(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

    // Confirm the values that were entered
    investment.displayInputValues();
    cin.get();

    // Show both required year-by-year projections
    investment.displayBalanceWithoutDeposits();
    investment.displayBalanceWithDeposits();

    return 0;
}
