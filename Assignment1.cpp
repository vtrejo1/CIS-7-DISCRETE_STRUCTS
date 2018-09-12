/*
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
			if (impTest == true)
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
				
			}
			if (isalpha(c) == true)
			{
				if (isStatement == isalpha(c))
				{
					successXD = false;
					continue;
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
					continue;
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
				continue;
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
}*/

//reg expressions ftw :3
#include <string>
#include <regex>
#include <iostream>

using namespace std;

int main()
{
        string userInput;
        cout << "Enter Statement ";
        getline(cin, userInput);
        cout << endl;

        if(regex_match(userInput, regex("(\\!?[A-Z])((v|\\^|\\-\\>)(\\!?[A-Z]))+")))
            cout << "Is a WFF" << endl;
        else
            cout << "Is NOT a WFF" << endl;


        system("pause");
    return 0;
}