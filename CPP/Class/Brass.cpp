#include <iostream>
#include <cstring>
#include "Brass.h"
using namespace std;
Brass::Brass(const char* s = "NoBody", long an = -1, double bal = 0.0)
{
	strncpy(name, s, MAX - 1);
	name[MAX - 1] = '\0';
	acctnum = an;
	balance = bal;
}
void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "UNAC\n";
	else 
		balance += amt;
}
void Brass::withdraw(double amt)
{
	if (amt < 0)
		cout << "withdraw\n";
	else
		if (amt <= balance)
			balance -= amt;
		else
			cout << "cancel\n";
}
double Brass::Balance()const
{
	return balance;
}
void Brass::ViewAcct()const
{
	cout << "client:" << name;
	cout << "\nAcct num:" << acctnum;
	cout << "\nBalance:" << balance << endl;
}

BrassPlus::BrassPlus(const char* s = "NoBody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10):Brass(s,an,bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
BrassPlus::BrassPlus(const Brass & ba, double ml = 500, double = 0.1) : Brass(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
void BrassPlus::ViewAcct()const
{
	Brass::ViewAcct();
	cout << "endl\n";
}
void BrassPlus::withdraw(double amt)
{
	cout << "tbc";
}