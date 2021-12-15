#include <iostream>
using namespace std;

#include "Investment.h"

void Investment::setInvestment(double t_investment) {
	m_initialInvestment = t_investment;
}

double Investment::getInvestment() {
	return m_initialInvestment;
}

void Investment::setDeposit(double t_deposit) {
	m_monthlyDeposit = t_deposit;
}

double Investment::getDeposit() {
	return m_monthlyDeposit;
}

void Investment::setClosingBalance(double t_balance) {
	m_closingBalance = t_balance;
}

double Investment::getClosingBalance() {
	return m_closingBalance;
}

void Investment::setTotal(double t_total) {
	m_total = t_total;
}

double Investment::getTotal() {
	return m_total;
}

void Investment::setInterest(int t_interest) {
	m_interest = t_interest;
}

double Investment::getInterest() {
	return m_interest;
}

void Investment::setInterestPercentage(double t_interestPercentage) {
	m_interestPercentage = t_interestPercentage;
}

double Investment::getInterestPercentage() {
	return m_interestPercentage;
}

void Investment::setInterestMonthly(double t_interestMonthly) {
	m_interestMonthly = t_interestMonthly;
}

double Investment::getInterestMonthly() {
	return m_interestMonthly;
}

void Investment::setYears(int t_years) {
	m_years = t_years;
}

int Investment::getYears() {
	return m_years;
}

void Investment::setMonths(int t_months) {
	m_months = t_months;
}

int Investment::getMonths() {
	return m_months;
}

void Investment::useDataInput() {
	double inputValueTmp = 0;
	int inputValueTmp2 = 0;
	string inputEnding;

	cout << "**********************************" << endl;
	cout << "********** Data Input ************" << endl;

	cout << "Initial Investment Amount: ";
	// Getting input for the Initial Investment
	while (inputValueTmp <= 0) {
		cin >> inputValueTmp;
	}
	this->setInvestment(inputValueTmp);
	inputValueTmp = 0;
	// Resetting inputValueTmp for use for the next input

	cout << "Monthly Deposit: ";
	// Getting input for the Monthly Deposit
	while (inputValueTmp <= 0) {
		cin >> inputValueTmp;
	}
	this->setDeposit(inputValueTmp);
	inputValueTmp = 0;
	// Resetting inputValueTmp for use for the next input

	cout << "Annual Interest: ";
	// Getting input for the Annual Interest
	while (inputValueTmp <= 0) {
		cin >> inputValueTmp;
	}
	this->setInterest(inputValueTmp);

	cout << "Number of years: ";
	// Getting input for the Number of years
	while (inputValueTmp2 <= 0) {
		cin >> inputValueTmp2;
	}
	this->setYears(inputValueTmp2);

	// Exit message for function
	cout << "Press any key and enter to continue . . .";
	cin >> inputEnding;
}

void Investment::calculateBalance() {
	// Temp variables for holding display values
	double tmpBalance = 100.0;
	double tmpMonthlyDeposit = 0.0;
	double tmpInterestYearlyTotal = 0.0;
	double tmpInterestAdded = 0.0;
	double tmpInterestPercent = 0.0;
	double tmpInterestMonthly = 0.0;
	int i;
	int j;
	int k;
	int h;

	// Loading the class's values into 
	tmpBalance = this->getInvestment();
	tmpMonthlyDeposit = this->getDeposit();
	// Assigning the class's percentage version of Interest
	this->setInterestPercentage(this->getInterest() / 100);
	tmpInterestPercent = this->getInterestPercentage();
	// cout << tmpInterestPercent; Commenting this test out
	// Assigning the monthly interest for compounding
	this->setInterestMonthly(tmpInterestPercent / 12);
	tmpInterestMonthly = this->getInterestMonthly();
	// cout << tmpInterestMonthly; Commenting this test out

	cout.precision(2);
	cout << "     Balance and Interest Without Additional Monthly Deposits     " << endl;
	cout << "==================================================================" << endl;
	cout << "  Year         Year End Balance      Year End Earned Interest" << endl;
	cout << "------------------------------------------------------------------" << endl;
	for (i = 1; i <= this->getYears(); i++) {
		for (j = 1; j <= 12; j++) {
			tmpInterestAdded = tmpBalance * tmpInterestMonthly;
			tmpInterestYearlyTotal += tmpInterestAdded;
			tmpBalance += tmpInterestAdded;
		}
		cout << "     " << i << "           $" << fixed << tmpBalance << "                $" << fixed << tmpInterestYearlyTotal << endl;

		// Resetting some yearly values
		tmpInterestYearlyTotal = 0.0;
	}

	cout << endl;

	// Resetting balance for 2nd chart
	tmpBalance = this->getInvestment();

	cout << "      Balance and Interest With Additional Monthly Deposits       " << endl;
	cout << "==================================================================" << endl;
	cout << "  Year         Year End Balance      Year End Earned Interest" << endl;
	cout << "------------------------------------------------------------------" << endl;
	for (i = 1; i <= this->getYears(); i++) {
		for (j = 1; j <= 12; j++) {
			tmpBalance += tmpMonthlyDeposit;
			tmpInterestAdded = tmpBalance * tmpInterestMonthly;
			tmpInterestYearlyTotal += tmpInterestAdded;
			tmpBalance += tmpInterestAdded;
		}
		cout << "     " << i << "           $" << fixed << tmpBalance << "                $" << fixed << tmpInterestYearlyTotal << endl;

		// Resetting some yearly values
		tmpInterestYearlyTotal = 0.0;
	}
}