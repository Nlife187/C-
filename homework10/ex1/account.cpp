// account.cpp
#include <iostream>
#include "account.h"

Account::Account()
{
    name = "no name";
    account = "000000";
    deposit = 0.0;
}
Account::Account(const std::string & A_name, const std::string & A_account, float A_deposit)
{
    name = A_name;
    account = A_account;
    deposit = A_deposit;
    std::cout << "Congratulations!\n";
    std::cout << account << " is created! deposit :" << deposit << '\n';
}
Account::~Account()
{
    std::cout << "Bye! " << name << '\n';
}
void Account::show() const
{
    std::cout << "dear Mr/Mrs " << name << '\n';
    std::cout << "your account: " << account << ", "
	      << "deposit: " << deposit << '\n'; 
}

bool Account::save(float money)
{
    if (money < 0)
	return false;
    else
    {
	deposit += money;
	std::cout << "Done!\n"
		  << "deposit: " << deposit << '\n';
	return true;
    }
}

bool Account::withdraw(float money)
{
    if (deposit - money < 0)
    {
	std::cout << "not sufficient funds!\n";
	return false;
    }
    else
    {
	deposit -= money;
	std::cout << "Done!\n"
		  << "deposit: " << deposit << '\n';
	return true;
    }
}


