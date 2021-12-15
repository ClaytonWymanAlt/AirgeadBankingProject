#include <iostream>>
#include <string>
#include "Investment.h"
using namespace std;

/**
* This program will accept user input for an initial deposit, monthly deposit, interest rate, and length of years, and will list interest and closing balance for each year
* author: Clayton Wyman
* date: 12/1/2021
*/

int main() {
	auto userAccount = std::unique_ptr<Investment>(new Investment());;
	//auto userAccount = std::make_unique<Investment>();
	//Investment userAccount;

	userAccount->useDataInput();
	cout << endl;
	userAccount->calculateBalance();

	return 1;
}