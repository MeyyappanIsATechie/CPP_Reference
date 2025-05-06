#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class I_Printable {
	friend ostream& operator<<( ostream& os , const I_Printable& obj );
public:
	//I_Printable( ){} - shouldnt be constructor in interface
	//only pure virtual fucntions
	//no data members
	virtual void print ( ostream& os ) const = 0;
	~I_Printable ( ) = default;
	};

ostream& operator<<( ostream& os , I_Printable& obj ) {
	obj.print ( os );
	return os;
	}

class Account: public I_Printable {
	//friend ostream& operator<< ( ostream& os , const Account& acc );
protected:
	double balance;
	string name;
public:
	//Account ( ) :balance { 0.0 } , name { "Holder" } {}
	Account ( double x ,string y ):balance(x ),name(y ){}
	Account ( ) :Account ( 0.0 , "holder" ) {} //delegating
	Account ( const Account& other ) : balance { other.balance } , name { other.name } {
		//base class copy constructor
		}
	Account& operator=( const Account& rhs ) {
		if ( this == &rhs ) return *this;
		balance = rhs.balance;
		name = rhs.name;
		return *this;
		}
	virtual ~Account ( ) = default; //optimality
	virtual bool deposit ( double amount ) = 0;
	virtual bool withdraw ( double amount ) = 0;
	virtual void print ( ostream& os ) const override {
		os.precision ( 2 );
		os << fixed;
		os << "account: " << name << ":" << balance << endl;
		}
	double get_balance ( ) const {
		return balance;
		}
	};

bool Account::deposit ( double amt ) {
	if ( balance < 0 || ( balance + amt ) > 100000.0 ) {
		return false;
		}
	balance += amt;
	return true;
	}

bool Account::withdraw ( double amt ) {
	if ( balance - amt < 0 ) {
		return false;
		}
	balance -= amt;
	return true;
	}

//ostream& operator<< ( ostream& os , const Account& acc ) {
//	os << "account" << acc.name << ":" << acc.balance;
//	return os;
//	}

//dervied class does not inherit 
// base class constructors
// base class destructors
//base class overloaded assignment operators
// base class friend functions
//derived class constructors, destructors, and overloaded assignment operators can invoke the base-class versions

//copy/move constructos and overloaded operator=
//dont need own
//dont means will create automatically and call base class
//else if provide derived version you must invoke base versions explicitly
  

class Savings_Account : public Account {
	//using Account::Account
	//friend ostream& operator<< ( ostream& os , const Savings_Account& acc );
protected:
	double interest;
public:
	Savings_Account ( ):Account(), interest{3.0 }{}
	Savings_Account ( double x ) :Account ( 5 * x , "holder" ) , interest { x } {}
	Savings_Account(string name, double balance, double interest ):Account{balance,name },interest{interest}{}
	Savings_Account ( const Savings_Account& other ) :Account ( other ) , interest { other.interest } {} //slicing
	Savings_Account& operator=( const Savings_Account& rhs ) {
		if ( this == &rhs ) return *this;
		Account::operator=( rhs ); //is-A relatiosnhip //slicing
		interest = rhs.interest;
		return *this;
		}
	virtual ~Savings_Account ( ) = default;
	bool deposit ( double amount ) override {
		amount += ( amount * interest / 100 );
		cout << "deposit savings" <<amount << endl;
		return Account::deposit ( amount );
		}
	bool withdraw ( double amount ) override {
		return Account::withdraw ( amount );
		}
	virtual void print ( ostream& os ) const override {
		os.precision ( 2 );
		os << fixed;
		os << "savings account: " << name << ":" << balance << ":"<<interest<< endl;
		}
	};

//ostream& operator<<( ostream& os , const Savings_Account& acc ) {
//	os << "savings accont" << acc.name<<acc.balance<<acc.interest;
//	return os;
//	}

class Checking_Account : public Account {
	//friend ostream& operator<<( ostream& os , const Checking_Account& acc );
protected:
	static constexpr double per_check_fee = 1.5;
public:
	//Checking_Account ( string name = "unnamed" , double balance = 0.0 ) :Account {balance,name} {}
	
	Checking_Account ( string s , double b ) : Account { b,s } {}
	Checking_Account ( ) :Checking_Account ( "unnamed" , 5000 ) {}
	bool withdraw ( double amt ) override {
		amt += per_check_fee;
		return Account::withdraw ( amt );
		}
	bool deposit ( double amt ) override {
		return Account::deposit ( amt );
		}

	virtual void print ( ostream& os ) const override {
		os.precision ( 2 );
		os << fixed;
		os << "checking account: " << name << ":" << balance << ":"<<per_check_fee<< endl;
		}

	virtual ~Checking_Account ( ) = default;
	};

//ostream& operator<<( ostream& os , const Checking_Account& acc ) {
//	os << "checking account" << acc.name << ":" << acc.balance;
//	return os;
//	}

class Trust_Account : public Savings_Account {
	//friend ostream& operator<<( ostream& os , const Trust_Account& acc );
private:
	static constexpr const char* dname = "unnamed";
	static constexpr double dbalance = 0.0;
	static constexpr double dinterest = 0.0;
	static constexpr double bonus = 50.0;
	static constexpr double bonus_threshold = 5000.0;
	static constexpr int max_withdrawals = 3;
	static constexpr double max_withdraw_percent = 0.2;
protected:
	int num_withdrawals;
public:
	Trust_Account ( string name = dname , double balance = dbalance , double interest = dinterest ) :Savings_Account { name,balance,interest } , num_withdrawals { 0 }{}
	bool deposit ( double amount ) override {
		if ( amount >= bonus_threshold ) amount += bonus;
		return Savings_Account::deposit ( amount );
		}
	bool withdraw ( double amount ) override {
		if ( num_withdrawals >= max_withdrawals || ( amount > balance * max_withdraw_percent ) ) return false;
		else {
			++num_withdrawals;
			return Savings_Account::withdraw ( amount );
			}
		}

	virtual void print ( ostream& os ) const override {
		os.precision ( 2 );
		os << fixed;
		os << "trust account: " << name << ":" << balance <<":"<<interest<<":"<<num_withdrawals<< endl;
		}
	virtual ~Trust_Account ( ) = default;
	};

//ostream& operator<<( ostream& os , const Trust_Account& acc ) {
//	os <<"trust account"<< acc.name << ":" << acc.balance << ":" << acc.interest << ":" << acc.num_withdrawals;
//	return os;
//	}

void display ( const vector<Account*>& acc ) {
	for ( const auto& a : acc ) {
		cout << *a << endl;
		}
	}

int main ( ) {
	/*Account acc { };
	cout << acc;
	acc.deposit ( 2000 );
	acc.withdraw ( 500 );
	Account* acc2 { nullptr };
	acc2 = new Account ( );
	acc2->deposit ( 1000 );
	acc2->withdraw ( 200 );
	delete acc2;

	Savings_Account sacc { };
	sacc.deposit ( 2000 );
	sacc.withdraw ( 500 );
	Account* sacc2 { nullptr };
	sacc2 = new Savings_Account ( );
	sacc2->deposit ( 1000 );
	sacc2->withdraw ( 200 );
	delete sacc2;*/

	//Account acc1 ( 1000, "John Doe" );
	//cout << acc1 << endl;
	//acc1.deposit ( 500 );
	//cout << "After deposit: " << acc1 << endl;
	//acc1.withdraw ( 200 );
	//cout << "After withdrawal: " << acc1 << endl;

	//// Create and test Savings Account
	//Savings_Account sacc1 ( "Jane Doe" , 2000 , 5.0 );
	//cout << sacc1 << endl;
	//sacc1.deposit ( 1000 );
	//cout << "After deposit: " << sacc1 << endl;
	//sacc1.withdraw ( 500 );
	//cout << "After withdrawal: " << sacc1 << endl;

	//// Create and test Checking Account
	//Checking_Account cacc1 ( "Jack Smith" , 1000 );
	//cout << cacc1 << endl;
	//cacc1.deposit ( 1000 );
	//cout << "After deposit: " << cacc1 << endl;
	//cacc1.withdraw ( 200 );
	//cout << "After withdrawal: " << cacc1 << endl;

	//// Create and test Trust Account
	//Trust_Account tacc1 ( "Alice Brown" , 10000 , 3.0 );
	//cout << tacc1 << endl;
	//tacc1.deposit ( 6000 );
	//cout << "After deposit (with bonus): " << tacc1 << endl;
	//tacc1.withdraw ( 1500 );
	//cout << "After withdrawal: " << tacc1 << endl;

	//// Test invalid withdrawal in Trust Account
	//tacc1.withdraw ( 3000 );
	//cout << "After invalid withdrawal attempt: " << tacc1 << endl;

	//Account a2; - doesnt work

	Checking_Account c;

	cout << c << endl;

	Savings_Account s { "name",5000,2.4 };
	cout << s << endl;
	s.deposit ( 10000 );
	cout << s << endl;

	Account* ptr = new Trust_Account ( "name2" , 1000 , 1.5 );
	cout << *ptr << endl;

	Trust_Account t;

	vector<Account*> v = { &c,&s,&t, ptr };

	display ( v );

	return 5;
	}