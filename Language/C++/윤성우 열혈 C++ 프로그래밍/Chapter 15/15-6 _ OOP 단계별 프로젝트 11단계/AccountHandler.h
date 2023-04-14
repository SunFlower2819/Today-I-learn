#ifndef _ACCOUNT_HANDLER__
#define _ACCOUNT_HANDLER__
#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler
{
private:
	BoundCheckArray<Account*> accArr;
	int accNum;
public:
	AccountHandler();
	void ShowMenu() const;       // �޴�����
	void MakeAccount();          // ���°����� ���� �Լ�
	void DepositMoney();		     // ��     ��
	void WidthdrawMoney();		   // ��     ��
	void ShowAllAccInfo() const; // �ܾ���ȸ
	~AccountHandler();
protected:
	void MakeNormalAccout();   // ���뿹�ݰ��� ����
	void MakeCreditAccout();   // �ſ�ŷڰ��� ����
};

#endif // _ACCOUNT_HANDLER__

