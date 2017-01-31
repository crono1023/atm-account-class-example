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

Account::Account(int customerID, std::string customerFirstName,
	std::string customerLastName)
{
			m_customerID = customerID;
			m_customerFirstName = customerFirstName;
			m_customerLastName = customerLastName;
}

class Checking : public Account 
{
	public:
		Checking(int customerID, std::string custoemrFirstName, 
			std::string customerLastName, int initialBalance);
		int getBalance()
		{
			return m_balance;
		}

	private:
		int m_balance;
};

int Account::CustomerID()
{
	return m_customerID;
}

std::string Account::getCustomerFullName()
{
	return m_customerFirstName + " " + m_customerLastName;
}

Checking::Checking(int customerID, std::string customerFirstName, 
	std::string customerLastName, int initialBalance)
	: Account(customerID, customerFirstName, customerLastName)
{
	m_balance = initialBalance;
}


int main(int argc, char *argv[])
{
	//Account account (123456);
	Checking checking (12345, "Chuck", "Haines", 1000);
	std::cout << "Customer ID: " << checking.CustomerID() << ".\n";
	std::cout << "Checking Account Balance: " << checking.getBalance() 
		<< std::endl;
	std::cout << "Customer Name: " << checking.getCustomerFullName() << 
		std::endl;
	std::cout << "End\n";

	return 0;
}
