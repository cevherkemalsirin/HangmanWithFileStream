#include "Cutilities.h"



char getCharacterFromUser(const char promt[], const char error[],CharacterCaseType CaseType)
{
	char input;
	bool failure;
	do {
		failure = false;

		cout << promt << endl;
		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << error << endl;
			failure = true;
		}
		else
		{

			if (isalpha(input))
			{
				if (CaseType==CCL_LOWERCASE)
				{
					input = tolower(input);
				}
				else if(CaseType==CC_UPPERCASE)
				{
					input = toupper(input);
				}
				
				
			}
			else
			{
				cin.ignore(256, '\n');
				cout << error << endl;
				failure = true;
			}

		}


	}

	while (failure);

	return input;


}

char getCharacterFromUser(const char promt[], const  char error[], const char ValidInputs[], int len, CharacterCaseType CaseType)

{

	char input;
	bool failure;
	do {
		failure = false;

		cout << promt << endl;
		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << error << endl;
			failure = true;
		}
		else
		{

			for (int i = 0; i < len; i++)
			{
				
				if (input == ValidInputs[i])
				{
					if (CaseType == CCL_LOWERCASE)
					{
						input = tolower(input);
					}
					else if (CaseType == CC_UPPERCASE)
					{
						input = toupper(input);
					}
					
					return input;
				}

			}

			cin.ignore(256, '\n');
			cout << error << endl;
			failure = true;

		}


	} while (failure);

}

int getNumberFromUser(const char promt[], const  char error[])
{

	int input;
	bool failure;
	do {
		failure = false;

		cout << promt << endl;
		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << error << endl;
			failure = true;
		}
		else
		{

			if (isalpha(input))
			{
				cin.ignore(256, '\n');
				cout << error << endl;
				failure = true;
			}
			

		}


	}

	while (failure);

	return input;

}
int getNumberFromUser(const char promt[], const  char error[], const int min, const int max)
{


	int input;
	bool failure;
	do {
		failure = false;

		cout << promt << endl;
		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << error << endl;
			failure = true;
		}
		else
		{

			if (isalpha(input))
			{
				cin.ignore(256, '\n');
				cout << error << endl;
				failure = true;
			}
			else
			{
				if (input > max || input < min)
				{
					cin.ignore(256, '\n');
					cout << "Please enter between" <<min<<" - "<<max << endl;
					failure = true;
				}
			}


		}


	}

	while (failure);

	return input;
}