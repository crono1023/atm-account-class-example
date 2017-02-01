/* Main.cpp Main function for atm-example program.
** This is the main file for the atm-example.
*/

//Includes
#include <iostream>
#include <string>
#include <vector>

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

int convertInt(std::string input, bool &success)
{
	int buffer = 0;
	success = true;
	try
	{
		buffer = stof(input);
	}
	catch (const std::invalid_argument& ia)
	{
		std::cerr << "Invalid argument\n";
		success = false;
	}
	catch (const std::out_of_range& oor)
	{
		std::cerr << "Out of range\n";
		success = false;
	}

	return buffer;
}


int main(int argc, char *argv[])
{

	//Create custoemr accounts and add the ID numbers to a vector for
	//lookup later
	
	std::vector<int> customerIDS;

	bool foundCustomer = false;
	bool success;
	int selectedID = 0;

	Checking checking (1000, "John", "Doe", 240);
	customerIDS.push_back(1000);
	Savings savings (1001, "Jane", "Smith", 6700);
	customerIDS.push_back(1001);
	Business business (1002, "Elon", "Musk", 140000);
	customerIDS.push_back(1002);

	std::string input;

	//Account account (123456);
	newConsoleLine();

	
	while(!foundCustomer)
	{

		std::cout << "Welcome to ATM System v1.1";
		newConsoleLine;
		std::cout << "Please enter your ID number: ";
		std::cin >> input;
		
		int selectedID = convertInt(input, success);

		if(success)
		{
			for(int i = 0; i < customerIDS.size() ; i++)
			{
				if(customerIDS[i] == selectedID)
				{
					if(!foundCustomer)
					{
						std::cout << "i: " << i << std::endl;		
						std::cout << "Matched at position: " << i <<
						std::endl;
						foundCustomer = true;
					}
				}
			}

			//TODO display main menu
		}

	}
	
	return 0;
}
