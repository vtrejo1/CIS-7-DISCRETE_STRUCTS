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

        if(regex_match(userInput, regex("\\!?(\\(+\\!?)*([A-Z])( ((v|V|\\^|\\-\\>) (\\!?(\\(+\\!?)*[A-Z](\\)*))))+")))
        {
        	int pCount = 0;
        	for(char& c : userInput)
        	{
        		if(c == '(')
        			pCount++;
        		if(c == ')')
        			pCount--;

        		if(pCount == -1)
        		{
        			cout << "Is NOT a WFF due to a missing open parenthesis" << endl;
        			break;
        		}
        	}

        	if(pCount == 0)
        	{
        		cout << "Is a WFF" << endl;
        	}
            if(pCount > 0)
            	cout << "Is NOT a WFF due to unclosed parenthesis" << endl;
        }
        else
            cout << "Is NOT a WFF" << endl;
        


        system("pause");
    return 0;
}