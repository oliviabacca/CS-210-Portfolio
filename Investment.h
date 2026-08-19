// Name: Olivia Bacca
// Date: July 29, 2026
// Course: CS-210
// Purpose: This program collects an initial investment amount,
// monthly deposit, annual interest rate, and number of
// years from the user, then displays two year-by-year
// tables projecting the investment's growth through
// monthly compounding -- one without additional
// deposits, and one with a fixed monthly deposit.

#ifndef INVESTMENT_H
#define INVESTMENT_H

// Investment
// Encapsulates the inputs for a compound-interest investment projection
// and provides methods to display year-by-year growth, both with and
// without additional monthly deposits.
class Investment {
private:
    double initialInvestment;   // Starting principal amount, in dollars
    double monthlyDeposit;      // Amount deposited every month, in dollars
    double annualInterestRate;  // Annual interest rate as a whole-number percent (e.g. 5 means 5%)
    int numberOfYears;          // Number of years to project growth over

public:
    // Constructor: stores the four values collected from the user
    Investment(double initial, double deposit, double rate, int years);

    // Echoes the input values back to the user in the required format
    void displayInputValues() const;

    // Displays a year-by-year table of balance and interest earned,
    // assuming no deposits beyond the initial investment
    void displayBalanceWithoutDeposits() const;

    // Displays a year-by-year table of balance and interest earned,
    // including the additional monthly deposit each month
    void displayBalanceWithDeposits() const;
};

#endif
