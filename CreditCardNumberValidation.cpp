#include <iostream>
#include <string>

bool validateCreditCard(const std::string cardNumber);

int main()
{
	bool is_valid=0;
	std::string cardNumber = "6011000990139424";// 6011 0009 9013 9424
	is_valid = validateCreditCard(cardNumber);
	
	if (is_valid)
	{
		std::cout << "The credit card number provided is VALID!: " << "\n";
		std::cout << cardNumber << "\n";
	}
	else
	{
		std::cout << "The credit card number provided is INVALID!: " << "\n";
		std::cout << cardNumber << "\n";
	}

	return 0;
}


// CHECKS IF A CREDIT CARD NUMBER FORMAT IS VALID
bool validateCreditCard(const std::string cardNumber)
{
	int sum = 0;
	int decimal = 0;
	int units = 0;
	int converted_digit = 0;

	int j = 0;
	for (int i = cardNumber.size()-1; i >= 0; i--)
	{
		converted_digit = (cardNumber[i] - 48); //SUBTRACTING 48 (FROM ASCII TABLE, 48 IS 0 IN A STRING, SO WE CAN CAST THE NUMBER FROM A STRING TO AN INTEGER)
		if (i % 2 == 0)// ONLY DO THIS TO EVEN POSITIONS
		{
			decimal = (converted_digit * 2) / 10; // GETTING THE DECIMAL PORTION OF THE NUMBER (EG: 12/10 = 1)
			units = (converted_digit * 2) % 10; // GETTING THE REMAINDER PORTION OF THE DIVISION (EG: 12%10 = 2)
			sum += decimal + units; // SUMMING UP EACH INDIVIDUAL DIGIT AFTER DOUBLING NUMBER
		}
		if (i % 2 != 0)// ONLY DO THIS TO ODD POSITIONS
		{
			sum += converted_digit; // SUMMING UP THE RAW NUMBER
		}
	}

	std::cout << "THE SUM IS: " << sum << "\n";

	return (sum % 10 == 0) ?  1 : 0; // IF THE SUM IS DIVISIBLE BY 10, THE CREDIT CARD NUMBER IS VALID, OTHERWISE IS INVALID
}