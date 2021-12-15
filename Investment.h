#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>
using namespace std;

class Investment {
public:
	void setInvestment(double t_investment);
	double getInvestment();
	void setDeposit(double t_deposit);
	double getDeposit();
	void setClosingBalance(double t_balance);
	double getClosingBalance();
	void setTotal(double t_total);
	double getTotal();
	void setInterest(int t_interest);
	double getInterest();
	void setInterestPercentage(double t_interestPercentage);
	double getInterestPercentage();
	void setInterestMonthly(double t_interestMonthly);
	double getInterestMonthly();
	void setYears(int t_years);
	int getYears();
	void setMonths(int t_months);
	int getMonths();

	void useDataInput();
	void calculateBalance();
private:
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_closingBalance;
	double m_total;
	int m_interest;
	double m_interestPercentage;
	double m_interestMonthly;
	int m_years;
	int m_months;
};

#endif