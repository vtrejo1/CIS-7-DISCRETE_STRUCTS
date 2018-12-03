#include <iostream>
#include <chrono>
using namespace std;

void inputPrompt(int&, int&);
bool isValid(int num, int div);
void gcd(int a, int b);
bool runPrompt();

int main()
{
	int num = 0;
	int div = 0;
    do
    {
	    do
	    {
	    	inputPrompt(num, div);
	    }while(!isValid(num, div));

	    auto start = chrono::steady_clock::now();
	    gcd(num, div);
	    auto end = chrono::steady_clock::now();
	    auto diff = end - start;

	    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    }while(runPrompt());     
}

void inputPrompt(int& num, int& div)
{
	
    cout << "Enter Numerator and denominator: ";
    if(!(cin >> num >> div))
    {
    	cout << "Invalid input! Please try again!" << endl;
    	cin.clear();
    	cin.ignore(INT8_MAX, '\n');
    	inputPrompt(num, div);
    }
   
}
bool isValid(int num, int div)
{
	if(num < 0 | div < 0)
	{
		cout << "Negative integer. Please try again" << endl;
		return false;
	}
	else if (num == 0 | div == 0)
	{
		cout << "Zero is not a positive number. Please try again!\n" << endl;
		return false;
	}
	else
		return true;
}
void gcd(int a, int b)
{
	//cout << "GCD func\n";
	int remainder = a%b;
	//int wholeInt = a/b;
	//cout << "Whole: " << wholeInt << endl;
	//cout << "remainder: " << remainder << endl;
	if (remainder == 0)
    	cout << "GCD is " << b << endl;
    else
    {
        gcd(b, remainder);
    }
}
bool runPrompt()
{
	char runInput = ' ';
	while(true)
	{
		cout << "Would you like to run again? (Y/N): ";
		cin >> runInput;

		if(toupper(runInput) == 'Y')
			return true;
		else if(toupper(runInput) == 'N')
		{
			cout << "Exiting program.";
			return false;
		}
		else
		{
			cout << "Invalid input. Please try again.\n";
			cin.ignore(INT8_MAX, '\n');
			continue;
		}
	}
}
