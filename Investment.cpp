// Name: Olivia Bacca
// Date: July 29, 2026
// Course: CS-210
// Purpose: This program collects an initial investment amount,
// monthly deposit, annual interest rate, and number of
// years from the user, then displays two year-by-year
// tables projecting the investment's growth through
// monthly compounding -- one without additional
// deposits, and one with a fixed monthly deposit.

#include "Investment.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

namespace {
    // Formats a dollar amount as "$1234.56" so it can be right-justified
    // as a single unit in a table column.
    string formatCurrency(double amount) {
        ostringstream oss;
        oss << "$" << fixed << setprecision(2) << amount;
        return oss.str();
    }
}

Investment::Investment(double initial, double deposit, double rate, int years)
    : initialInvestment(initial),
      monthlyDeposit(deposit),
      annualInterestRate(rate),
      numberOfYears(years)
{
}

void Investment::displayInputValues() const {
    cout << "\nInitial Investment Amount: $" << fixed << setprecision(2) << initialInvestment << endl;
    cout << "Monthly Deposit: $" << fixed << setprecision(2) << monthlyDeposit << endl;
    cout << defaultfloat << "Annual Interest: %" << annualInterestRate << endl;
    cout << "Number of Years: " << numberOfYears << endl;
    cout << "Press any key to continue...";
}

void Investment::displayBalanceWithoutDeposits() const {
    double balance = initialInvestment;
    double monthlyRate = (annualInterestRate / 100.0) / 12.0;

    cout << "\n\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << left << setw(8) << "Year"
         << right << setw(20) << "Year End Balance"
         << setw(28) << "Year End Earned Interest" << '\n';

    for (int year = 1; year <= numberOfYears; ++year) {
        double yearStartBalance = balance;

        // Apply interest once per month for the 12 months in this year
        for (int month = 1; month <= 12; ++month) {
            balance += balance * monthlyRate;
        }

        double interestEarned = balance - yearStartBalance;

        cout << left << setw(8) << year
             << right << setw(20) << formatCurrency(balance)
             << setw(28) << formatCurrency(interestEarned) << '\n';
    }
}

void Investment::displayBalanceWithDeposits() const {
    double balance = initialInvestment;
    double monthlyRate = (annualInterestRate / 100.0) / 12.0;

    cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
    cout << left << setw(8) << "Year"
         << right << setw(20) << "Year End Balance"
         << setw(28) << "Year End Earned Interest" << '\n';

    for (int year = 1; year <= numberOfYears; ++year) {
        double yearStartBalance = balance;
        double totalDepositsThisYear = 0.0;

        for (int month = 1; month <= 12; ++month) {
            balance += monthlyDeposit;              // Deposit made at the start of the month
            totalDepositsThisYear += monthlyDeposit;
            balance += balance * monthlyRate;        // Interest applied for the month
        }

        double interestEarned = balance - yearStartBalance - totalDepositsThisYear;

        cout << left << setw(8) << year
             << right << setw(20) << formatCurrency(balance)
             << setw(28) << formatCurrency(interestEarned) << '\n';
    }
}
