class Brass
{
private:
	enum{MAX=35};
	int acctnum;
	char name[MAX];
	double balance;
public:
	Brass(const char* s = "NoBody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void withdraw(double amt);
	double Balance()const;
	virtual void ViewAcct()const;
	virtual ~Brass() {};
};

class BrassPlus : public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const char* s = "NoBody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
	BrassPlus(const Brass & ba, double ml = 500, double = 0.1);
	virtual void withdraw(double amt);
	virtual void ViewAcct()const;
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void Resetowes() { owesBank = 0; }
};