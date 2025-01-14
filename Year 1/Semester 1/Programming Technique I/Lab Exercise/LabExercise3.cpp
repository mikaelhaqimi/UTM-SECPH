/* 
	Title		: Lab Exercise 3 (SECJ1013)
	Name		: Mikael Haqimi Bin Nahar Junaidi
	Matrics No.	: A24CS0111
	Section		: 03
	Lecturer	: Dr. Alif Ridzuan Bin Khairuddin
	Date		: 20th November 2024
*/

#include <iostream>
using namespace std;

void dispStatus(int&);
void getInput(int&, int&, int&, int&);
void dispOutput(int&);
int calcAverage(int, int);

int main() {
	
	int SIZE = 20, totalCases, newCases, totalDeath, totalRecovered, activeCases, average;
	int totalState = 0, totalActiveCases = 0, highestActiveState = 0;
	char state[SIZE], highestState[SIZE];
	
	do {
		
		cout << "\n<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>" << endl;
		cout << "State name     : ";
		cin.getline(state, SIZE);
		
		totalState++;
		
		getInput(totalCases, newCases, totalDeath, totalRecovered);
		
		activeCases = totalCases + newCases - totalDeath - totalRecovered;
		
		dispOutput(activeCases);
		
		totalActiveCases += activeCases;
		
		if (activeCases > highestActiveState) {
			highestActiveState = activeCases;
			strcpy(highestState, state);
		}
		
		cout << "\nPress <ENTER> to continue...";
		
		if (cin.get() != '\n') 
			break;
			
	} while (cin.get() == '\n');
	
	cout << "\n<<<<<<<<< ACTIVE CASES >>>>>>>>>>" << endl;
	cout << "Total  : " << totalActiveCases << endl;
	cout << "Highest: " << highestActiveState << " (" << highestState << ")" << endl;
	
	average = calcAverage(totalState, totalActiveCases);
	
	cout << "Average for " << totalState << " states: " << average; 
	
	return 0;
}

void getInput(int &totalCases, int &newCases, int &totalDeath, int &totalRecovered) {
	
	cout << "Total cases    : ";
	cin >> totalCases;
	
	cout << "New cases      : ";
	cin >> newCases;
	
	cout << "Total death    : ";
	cin >> totalDeath;
	
	cout << "Total recovered: ";
	cin >> totalRecovered;	
}

void dispOutput(int &activeCases) {
	
	cout << "\n<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>" << endl;
	cout << "Active cases   : " << activeCases << endl;
	cout << "Status         : ";
	
	dispStatus(activeCases);
	
	cout << endl;
}

void dispStatus(int &activeCases) {
	
	if (activeCases == 0)
		cout << "Green zone";
	else if (activeCases >= 1 && activeCases <= 20)
		cout << "Yellow zone";
	else if (activeCases >= 21 && activeCases <= 40) 
		cout << "Orange zone";
	else
		cout << "Red zone";
}

int calcAverage(int totalState, int totalActiveCases) {
	
	int average;
	
	average = totalActiveCases / totalState;
	
	return average;
}
