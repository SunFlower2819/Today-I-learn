#ifndef __HIGHTCREDIT_ACCOUNT__
#define __HIGHTCREDIT_ACCOUNT__
#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public NormalAccount // �ſ�ŷڰ���
{
private:
	int speicalRate;
public:
	//HighCreditAccount(int id, int money, char* name, int interest, int rank)
	HighCreditAccount(int id, int money, String name, int interest, int rank)
		: NormalAccount(id, money, name, interest), speicalRate(rank)
	{}
	virtual void Deposit(int money)
	{
		if (money < 0)
			throw MinusException(money);

		NormalAccount::Deposit(money);   // ���ݰ� �����߰�
		Account::Deposit((money * (speicalRate / 100.0))); // Ư�������߰�
	}
};

#endif // !__HIGHTCREDIT_ACCOUNT__

