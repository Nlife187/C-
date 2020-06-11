// account.h
#include <string>

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

class Account
{
    private:
	std::string name;
	std::string account;
	float deposit;

    public:
	Account();
	Account(const std::string & A_name, const std::string & A_account, float A_deposit = 0.0);
	~Account();
	void show() const;
	bool save(float money);
	bool withdraw(float money);
};
#endif
