#include <iostream>
#include <iomanip>


using namespace std;

void displayMenu();
void displayYearlyBalance(double intitialInvestment, double monthlyDeposit, double interestRate, int numberOfYears, bool withMonthlyDeposit);
void getUserInput(double &initialInvestment, double &monthlyDeposit, double &interestRate, int &numberOfYers);
double calculateYearlyBalanceWithMonthlyDeposits(double &balance, double monthlyDeposit, double interestRate);


int main() {
    double intitialInvestment;
    double monthlyDeposit;
    double interestRate;
    int numberOfYears;
    char userChoice;

    //do-while loop to allow user to enter different inputs
    do {
        displayMenu();
        getUserInput(intitialInvestment, monthlyDeposit, interestRate, numberOfYears);

        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();

        cout << endl << "\tBalance and Interest Without Additional Monthly Deposits" << endl;
        displayYearlyBalance(intitialInvestment, 0, interestRate, numberOfYears, false);

        cout << endl << "\tBalance and Interest With Additional Monthly Deposits" << endl;
        displayYearlyBalance(intitialInvestment, monthlyDeposit, interestRate, numberOfYears, true);

        cout << endl << "Do you wish to enter new variables?";
        cin >> userChoice;
        userChoice = toupper(userChoice);
        cin.ignore();
    } while (userChoice == 'Y');

    return 0;
}

//function to display menu
void displayMenu() {
    cout << "**********************************" << endl;
    cout << "**********";
    cout << " Data Input ";
    cout << "************" << endl;
}

void displayYearlyBalance(double intitialInvestment, double monthlyDeposit, double interestRate, int numberOfYears, bool withMonthlyDeposit) {
    double balance = intitialInvestment;
    double totalInterest;
    double yearlyInterest;

    cout << "================================================================" << endl;
    cout << fixed << setprecision(2);
    cout << "\tYear\tYear End Balance\tYear End Earned Interest";
    cout << endl;
    cout << "----------------------------------------------------------------" << endl;

    for (int year = 1; year <= numberOfYears; year++) {
        totalInterest = 0;
        if (withMonthlyDeposit) {
            totalInterest = calculateYearlyBalanceWithMonthlyDeposits(balance, monthlyDeposit, interestRate);
        }
        else {
            for (int month = 1; month <= 12; month++) {
                double monthlyInterest = balance * ((interestRate / 100) / 12);
                totalInterest += monthlyInterest;
                balance += monthlyInterest;
            }
        }

        yearlyInterest = totalInterest;

        cout <<"\t" << year << "\t\t" << balance << "\t\t\t\t" << yearlyInterest << endl;
    }

}

//function to calcualte with montly deposits
double calculateYearlyBalanceWithMonthlyDeposits(double &balance, double monthlyDeposit, double interestRate) {
    double totalInterest = 0;

    for (int month = 1; month <= 12; month++) {
        double monthlyInterest = (balance + monthlyDeposit) * ((interestRate / 100) / 12);
        totalInterest += monthlyInterest;
        balance += monthlyInterest;
        balance += monthlyDeposit;
    }
    return totalInterest;
}

//function to get user input
void getUserInput(double &initialInvestment, double &monthlyDeposit, double &interestRate, int &numberOfYers) {
    cout << "Initial Investment Amount: $";
    cin >> initialInvestment;

    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;

    cout << "Annual Interest: %";
    cin >> interestRate;

    cout << "Number of years: ";
    cin >> numberOfYers;
}

