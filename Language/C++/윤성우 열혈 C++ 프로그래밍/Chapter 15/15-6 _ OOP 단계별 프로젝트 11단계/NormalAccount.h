#ifndef __NORMAL__ACCOUNT_H__
#define __NORMAL__ACCOUNT_H__
#include "Account.h"
#include "String.h"
#include "AccountException.h"

class NormalAccount : public Account     // ���뿹�ݰ���
{
private:
	int interRate;
public:
	NormalAccount(int id, int money, String name, int interest)
		: Account(id, money, name), interRate(interest)
	{}
	virtual void Deposit(int money)
	{
		if (money < 0)
			throw MinusException(money);

		Account::Deposit(money); // �����߰�
		Account::Deposit((money * (interRate / 100.0))); // �����߰�
	}
};

#endif // !__NORMAL__ACCOUNT_H__


