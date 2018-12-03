#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Tower;
int diskInquery();
char contInput();
void printTowers(Tower, Tower, Tower);
void solveTowers(int , Tower*, Tower*, Tower*);
vector<Tower> sortTowers(Tower, Tower, Tower);

class Tower
{
	public:
		Tower(){};
		Tower(string name, int diskSize);
		~Tower();
		void setName(string);
		string getName();

		int getBack();

		void pushDisk(int);
		void popDisk();

		int getVectorSize();
		bool isEmpty();
		vector<int> getDisks();
	private:
		string name;
		vector<int> diskVector;
};

int main()
{
	int disks;

	disks = diskInquery();
	Tower *towerA = new Tower("Tower A", disks);
	Tower *towerB = new Tower("Tower B", disks);
	Tower *towerC = new Tower("Tower C", disks);

	solveTowers(disks, towerA, towerB, towerC);
	return 0;
}

//func def start
int diskInquery()
{

	int userInput;
	cout << "Please enter the # of disks to start: ";
	cin >> userInput;
	while(cin.fail())
    {
        cout << "Invalid input! Please try again!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >>userInput;
        //diskInquery();
    }


	
	return userInput;
}

void printTowers(Tower a, Tower b, Tower c)
{
	
	//sorting towers in order A-C
	vector<Tower> towers = sortTowers(a, b, c);

	for(int i = 3; i > 0; --i)
	{
		for(auto &t : towers)
		{
			if(t.getVectorSize() >= i)
			{
				if(t.getName() == "Tower A")
				{
				cout << setfill(' ') << setw(7) << right << t.getBack();
				t.popDisk();
				}
				else
				{
					cout << setfill(' ') << setw(10) << right << t.getBack();
				t.popDisk();
				}
			}
			else 
			{
				if(t.getName() == "Tower A")
				{
					cout << setfill(' ') << setw(7) << right << " ";
				}
				else
				cout << setfill(' ') << setw(10) << right << " ";
			}

		}
		cout << endl;
	}
	for(auto t : towers)
	{
		cout << right << setfill(' ') << setw(10) << t.getName();
	}
	cout << endl;

	//Input to continue. only accepts y
	contInput();
}

void solveTowers(int disk, Tower* source, Tower* spare, Tower* dest)
{
	//recursive func
	if (disk == 1)
    {
    	printTowers(*source, *spare, *dest);
        dest->pushDisk(source->getBack());
        source->popDisk();
            	cout << "Move disk from " << source->getName() << " to tower " << dest->getName() << ".\n";

        printTowers(*source, *spare, *dest);
        
    }
    else
    {

    	solveTowers(disk - 1, source, dest, spare);

    	dest->pushDisk(source->getBack());
    	cout << "Move disk from " << source->getName() << " to tower " << dest->getName() << ".\n";

        source->popDisk();
    	solveTowers(disk - 1, spare, source, dest);

	}
}
vector<Tower> sortTowers(Tower a, Tower b, Tower c)
{
	//not sure why i just didnt use sort lib
	vector<Tower> towers;
	towers.push_back(a);
	towers.push_back(b);
	towers.push_back(c);
	vector<Tower> v;
	for(auto t : towers)
	{
		if(t.getName() == "Tower A")
		{
			v.push_back(t);
			break;
		}

	} 
	for(auto t : towers)
	{
		if(t.getName() == "Tower B")
		{
			v.push_back(t);
			break;
		}

	} 
	for(auto t : towers)
	{
		if(t.getName() == "Tower C")
		{
			v.push_back(t);
			break;
		}

	} 
	return v;
}
char contInput() //Prompt user input to continue to next step
{

	char input;
	cout << "Press any key to Continue!";
	cin >> input;
	while(cin.fail())
	{
		cin >> input;
	}
	cin.clear();
    cin.ignore(1000, '\n');
	system("clear");
}
//class Tower def
Tower::Tower(string name, int diskSize)
{
	diskVector.reserve(diskSize);
	setName(name);

	if(name == "Tower A")
	{
		for(int i = diskSize; i > 0; i--)
		{
			pushDisk(i);
		}
	}	
}
Tower::~Tower()
{
	//cout << "Tower is deleted" << endl;
}
void Tower::setName(string name)
{
	this->name = name;
}
string Tower::getName()
{
	return name;
}
int Tower::getBack() 
{
	if(diskVector.empty())
	{
		return -1;
	}
	else
		return diskVector.back();
}
void Tower::pushDisk(int disk)
{
	diskVector.push_back(disk);
}

void Tower::popDisk()
{
	diskVector.pop_back();
};

int Tower::getVectorSize()
{
	return diskVector.size();
}
vector<int> Tower::getDisks()
{
	return diskVector;
}
bool Tower::isEmpty()
{
	return diskVector.empty();
}