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
		int m_accountType;

	
	public:
		Account(int customerID, std::string customerFirstName, 
			std::string customerLastName, int acountType);
 		
		int CustomerID();
		std::string getCustomerFullName();
		
	};

class Checking : public Account 
{
	public:
		Checking(int customerID, std::string custoemrFirstName, 
			std::string customerLastName, int initialBalance, int accountType);
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
			std::string customerLastName, int initialBalance, int accountType);
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
			std::string customerLastName, int initialBalance, int accountType);
		int getBalance();
		void debitAccount(int amount);
		void creditAccount(int amount);
	private:
		int m_balance;
};

Account::Account(int customerID, std::string customerFirstName,
	std::string customerLastName, int accountType)
{
			m_customerID = customerID;
			m_customerFirstName = customerFirstName;
			m_customerLastName = customerLastName;
			m_accountType = accountType;
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
	std::string customerLastName, int initialBalance, int accountType)
	: Account(customerID, customerFirstName, customerLastName, accountType)
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
	std::string customerLastName, int initialBalance, int accountType)
	: Account(customerID, customerFirstName, customerLastName, accountType)
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
	std::string customerLastName, int initialBalance, int accountType)
: Account(customerID, customerFirstName, customerLastName, accountType)
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

void displayMainMenu(int customerID, std::string customerName)
{
		

		newConsoleLine();
		std::cout << "Welcome " << customerName   
			<< ".\n\n";
		std::cout << "1 - View Account Balance\n";
		std::cout << "2 - Withdrawl\n";
		std::cout << "3 - Deposit\n";
		newConsoleLine();
		std::cout << "Please select an action: ";
		
}	


int main(int argc, char *argv[])
{

	//Create custoemr accounts and add the ID numbers to a vector for
	//lookup later
	
	std::vector<int> customerIDS;

	//Create a list of account types, the account type will show
	// what type of account is stored by each ID at the matching
	// position on the customer IDS  vector.

	std::vector<int> customerAccountTypes;

	bool foundCustomer = false;
	bool success;
	int selectedID = 0;
	int selectedCustomerID = 0;
	int selectedCustomerAccountType = 0;
	int menuSelection;
	std::string selectedCustomerName = "";

	Checking checking (1000, "John", "Doe", 240, 1);
	customerIDS.push_back(1000);
	customerAccountTypes.push_back(1);
	Savings savings (1001, "Jane", "Smith", 6700, 2);
	customerIDS.push_back(1001);
	customerAccountTypes.push_back(2);
	Business business (1002, "Elon", "Musk", 140000, 3);
	customerIDS.push_back(1002);
	customerAccountTypes.push_back(3);
	
	std::string input;

	//Account account (123456);
	newConsoleLine();

	
	while(!foundCustomer)
	{

		std::cout << "Welcome to ATM System v1.1\n\n";
		newConsoleLine;
		std::cout << "Please enter your ID number: ";
		std::cin >> input;
		
		int selectedID = convertInt(input, success);

		if(success)
		{
			for(int i = 0; i < customerIDS.size(); i++)
			{
				if(customerIDS[i] == selectedID)
				{

					std::cout << "size: " << customerIDS.size() << std::endl;
					std::cout << "i: " << i << std::endl;
					std::cout << "Id list: " << customerIDS[i]
						<< "selection: " << selectedID << std::endl;
					std::cout << std::endl << customerIDS[0] <<
					std::endl << customerIDS[1] << std::endl <<
					customerIDS[2] << std::endl;
					if(!foundCustomer)
					{
						selectedCustomerID = customerIDS[i];
						selectedCustomerAccountType = customerAccountTypes[i];
				
/*						
						if(selectedCustomerAccountType == 1)
						{
							selectedCustomerName = checking.getCustomerFullName();
							std::cout << "\nrun 1";
						}
						else if (selectedCustomerAccountType == 2)
						{
							selectedCustomerName = savings.getCustomerFullName();
							std::cout << "\nrun 2";
						}
						else if (selectedCustomerAccountType == 3)
						{
		
							selectedCustomerName = business.getCustomerFullName();
							std::cout << "\nrun 3";
						}
*/
						switch(selectedCustomerAccountType)
						{
							case 1:
								selectedCustomerName = checking.getCustomerFullName();
								break;
							case 2:
								selectedCustomerName = savings.getCustomerFullName();
								break;
							case 3:
								selectedCustomerName = business.getCustomerFullName();
								break;
						}
						foundCustomer = true;
					}
				}
			}
		}
	}
  //TODO display main menu
	displayMainMenu(selectedCustomerID, selectedCustomerName);

	std::cin >> input;
	bool inputValid;
	menuSelection = convertInt(input, inputValid);
			
	if(inputValid)
	{
		if(menuSelection > 0 && menuSelection < 4)
		{
			switch(menuSelection)
			{
				case 1:
					newConsoleLine();
					std::cout << "Your account balance is: ";
					switch(selectedCustomerAccountType)
					{
						case 1: 
							std::cout << checking.getBalance();
							break;
						case 2:
							std::cout << savings.getBalance();
							break;
						case 3:
							std::cout << business.getBalance();
							break;
					}
					std::cout << std::endl;
					newConsoleLine();
					break;
			}
			
			
		}
	}
	
	return 0;
}
