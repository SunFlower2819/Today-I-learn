#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccout.h"
#include "String.h"

void AccountHandler::ShowMenu() const
{
	cout << "-----Menu-----" << '\n';
	cout << "1. ���°���\n";
	cout << "2. �� ��\n";
	cout << "3. �� ��\n";
	cout << "4. �������� ��ü ���\n";
	cout << "5. ���α׷� ����\n\n";
}

void AccountHandler::MakeAccount()
{
	int sel;
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� ";
	cout << "2.�ſ�ŷڰ��� " << endl;
	cout << "����:  ";
	cin >> sel;

	if (sel == NORMAL)
		MakeNormalAccout();
	else
		MakeCreditAccout();
}

void AccountHandler::MakeNormalAccout()
{
	int id;
	String name;
	int balance;
	int interRate;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccout()
{
	int id;
	String name;
	int balance;
	int interRate;
	int creditLevel;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	}
}

void AccountHandler::DepositMoney()
{
	int money, id;

	cout << "[��  ��]\n";
	cout << "����ID: "; cin >> id;

	while (true)
	{
		cout << "�Աݾ�: "; cin >> money;

		try
		{
			for (int i = 0; i < accNum; i++)
			{
				if (accArr[i]->GetAccID() == id)
				{
					accArr[i]->Deposit(money);
					cout << "�ԱݿϷ�" << endl << endl;
					return;
				}
			}
			cout << "��ȿ���� �ʴ� ID �Դϴ�.\n\n";
			return;
		}
		catch (MinusException& expt)
		{
			expt.ShowExceptionInfo();
			cout << "�Աݾ׸� ���Է��ϼ���." << endl;
		}
	}
}

void AccountHandler::WidthdrawMoney()
{
	int id, money;

	cout << "[��  ��]\n";
	cout << "����ID: "; cin >> id;

	while (true)
	{
		cout << "��ݾ�: "; cin >> money;
		
		try
		{
			for (int i = 0; i < accNum; i++)
			{
				if (accArr[i]->GetAccID() == id)
				{
					accArr[i]->Widthdraw(money);
					cout << "��ݿϷ�\n\n";
					return;
				}
			}
			cout << "��ȿ���� �ʴ� ID �Դϴ�.\n\n";
			return;
		}
		catch (MinusException& expt)
		{
			expt.ShowExceptionInfo();
			cout << "�Աݾ׸� ���Է��ϼ���." << endl;
		}
		catch (InsuffException& expt)
		{
			expt.ShowExceptionInfo();
			cout << "��ݾ׸� ���Է��ϼ���." << endl;
		}
	}
}

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}