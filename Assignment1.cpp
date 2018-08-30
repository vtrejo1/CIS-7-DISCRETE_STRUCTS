#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>

using namespace std;

int main()
{
	string userInput;
	bool isStatement = false;
	bool successXD = true;
	bool impTest = false;
	cout << "Enter Statement ";
	getline(cin, userInput);
	cout << endl;

		for (char &c : userInput)
		{
/*			if (impTest == true)
			{
				if (c == '>')
				{
					isStatement = false;
					impTest = false;
					break;
				}
				else
					successXD = false;
				break;
				
			}*/
			if (isalpha(c) == true)
			{
				if (isStatement == isalpha(c))
				{
					successXD = false;
					break;
				}
				else
					isStatement = true;
			}
			else if ((c == '^') || (c == 'v'))
			{
				if (isStatement)
				{
					isStatement = false;
				}
				else
				{
					successXD = false;
					break;
				}
			}
			else if (c == '!')
			{
				if (isStatement)
					isStatement = false;
			}
			else if (c == '-')
			{
				impTest = true;
				break;
			}
			else if (c == ' ')
				continue;
			else
			{
				successXD = false;
				break;
			}

		}
		if (successXD)
			cout << "Is a wff" << endl;
		else
			cout << "Is not a wff" << endl;
	
	
	system("pause");
	return 0;
}
