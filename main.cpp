/* Main.cpp Main function for atm-example program.
** This is the main file for the atm-example.
*/

//Includes
#include <iostream>
#include <string>


class Account
{
	
	private:
		int m_customerID;
		std::string m_customerFirstName;
		std::string m_customerLastName;

	
	public:
		Account(int customerID, std::string customerFirstName, 
			std::string customerLastName);
 		
		int CustomerID();
		std::string getCustomerFullName();
		
	};

class Checking : public Account 
{
	public:
		Checking(int customerID, std::string custoemrFirstName, 
			std::string customerLastName, int initialBalance);
		int getBalance();
		void debitAccount(int amount);
		void creditAccount(int amount);


	private:
		int m_balance;
};

class Savings : public Account
{
	public:
		Savings(int customerID, std::string customerFirstName,
			std::string customerLastName, int initialBalance);
		int getBalance();
		void debitAccount(int amount);
		void creditAccount(int amount);

	private:
		int m_balance;
};

class Business : public Account
{
	public:
		Business(int customerID, std::string customerFirstName,
			std::string customerLastName, int initialBalance);
		int getBalance();
		void debitAccount(int amount);
		void creditAccount(int amount);
	private:
		int m_balance;
};

Account::Account(int customerID, std::string customerFirstName,
	std::string customerLastName)
{
			m_customerID = customerID;
			m_customerFirstName = customerFirstName;
			m_customerLastName = customerLastName;
}

int Account::CustomerID()
{
	return m_customerID;
}

std::string Account::getCustomerFullName()
{
	return m_customerFirstName + " " + m_customerLastName;
}

int Checking::getBalance()
{
	return m_balance;
}

Checking::Checking(int customerID, std::string customerFirstName, 
	std::string customerLastName, int initialBalance)
	: Account(customerID, customerFirstName, customerLastName)
{
	m_balance = initialBalance;
}
void Checking::debitAccount(int amount)
{
	if(amount > 0)
	{
		m_balance -= amount;
	}
}

void Checking::creditAccount(int amount)
{
	if(amount > 0)
	{
		m_balance += amount;
	}
}

Savings::Savings(int customerID, std::string customerFirstName,
	std::string customerLastName, int initialBalance)
	: Account(customerID, customerFirstName, customerLastName)
{
	m_balance = initialBalance;
}

int Savings::getBalance()
{
	return m_balance;
}

void Savings::debitAccount(int amount)
{
	if(amount>0)
	{
		m_balance -= amount;
	}
}

void Savings::creditAccount(int amount)
{
	if(amount>0)
	{
		m_balance += amount;
	}
}

Business::Business(int customerID, std::string customerFirstName,
	std::string customerLastName, int initialBalance)
: Account(customerID, customerFirstName, customerLastName)
{
	m_balance = initialBalance;
}

int Business::getBalance()
{
	return m_balance;
}

void Business::debitAccount(int amount)
{
	if(amount>0)
	{
		m_balance -= amount;
	}
}

void Business::creditAccount(int amount)
{
	if(amount>0)
	{
		m_balance += amount;
	}
}

void newConsoleLine()
{
	std::cout << std::endl << 
		"------------------------------------------\n\n";
}


int main(int argc, char *argv[])
{
	//Account account (123456);
	newConsoleLine();
	Checking checking (12345, "Chuck", "Haines", 1000);
	std::cout << "Customer ID: " << checking.CustomerID() << ".\n";
	std::cout << "Checking Account Balance: $" << checking.getBalance() 
		<< std::endl;
	std::cout << "Customer Name: " << checking.getCustomerFullName() << 
		std::endl;
	std::cout << "Adding $500 Debit to account.\n";
	checking.debitAccount(500);
	std::cout << "Checking account new balance: $" << checking.getBalance()
		<< std::endl;
	std::cout << "Crediting account $250.\n";
	checking.creditAccount(250);
	std::cout << "Checking account new balance: $" << 
		checking.getBalance() << std::endl;
	newConsoleLine();

	std::cout << "Adding savings account with initial balance of 3500"
		<< std::endl;

	Savings savings (86868, "Bob", "Jones", 3500);
	std::cout << "Savings account balance: $" <<
		savings.getBalance() << std::endl;

	newConsoleLine();

	std::cout << "Creating new business account.\n";
	Business business (23456, "Mike", "Jackson", 15000);
	std::cout << "Business Account Balance: $" << 
		business.getBalance() << std::endl;
	std::cout << "Crediting business account by $500.\n";
		business.creditAccount(500);
	std::cout << "Business Account Balance: $" << 
		business.getBalance() << std::endl;
	std::cout << "Business Account Holder Name: " <<
		business.getCustomerFullName() << std::endl;
	newConsoleLine();	

	return 0;
}
