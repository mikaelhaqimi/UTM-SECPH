/*
	Title		: Assignment 2 (SECJ1013)
	Student 1	: Muhammad Firdaus Bin Md Lani (A24CS0132)
	Student 2	: Mikael Haqimi Bin Nahar Junaidi (A24CS0111)
	Section		: 03
	Lecturer	: Dr. Alif Ridzuan Bin Khairuddin
	Date		: 26th November 2024
	Reference 	: https://www.perodua.com.my/loan-calculator.html 
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Global declaration
char model[6][10] = {"Ativa", "Aruz", "Bezza", "Myvi", "Alza", "Axia"};
char region[4][20] = {"Peninsular Malaysia", "East Malaysia", "Labuan", "Langkawi"};
char carColour[3][40] = {"Metallic", "Special Metallic", "2-Tone Special Metallic (Black Roof)"};

string variantName[6][5] = {{"1.0L X Turbo (CVT)", "1.0L H Turbo (CVT)", "1.0L AV Turbo (CVT)"},
						   	{"1.5 AV (Auto)", "1.5 X (Auto)"},
						   	{"1.3 AV (Auto)", "1.3 X (Auto)", "1.0 G (Auto)", "1.0 G (Manual)"},
						   	{"1.5L AV (CVT)", "1.5L H (CVT)", "1.5L X (CVT)", "1.3L G (CVT)", "1.3L G (CVT) (Without PSDA)"},
						   	{"1.5L AV (D-CVT)", "1.5L H (D-CVT)", "1.5L X (D-CVT)"},
						   	{"1.0L AV (D-CVT)", "1.0L SE (D-CVT)", "1.0L X (D-CVT)", "1.0L G (D-CVT)", "1.0L E (5MT)"}};

double otrpenin[6][5] 	= {{62500, 67300, 72600},
				 	 	   {77900, 72900},
				 	 	   {49980, 43980, 36580, 34580},
				 	 	   {59900, 54900, 50900, 48500, 46500},
				 	 	   {75500, 68000, 62500},
				 	 	   {49500, 44000, 40000, 38600, 22000}};
					 
double otreast[6][5] 	= {{64500, 69300, 74600},
						   {79900, 74900},
						   {51980, 45980, 38580, 36580},
						   {61900, 56900, 52900, 50500, 48500},
						   {78000, 70500, 65000},
						   {51500, 46000, 42000, 40600, 22000}};
						
double otrlabuan[6][5] 	= {{59980, 64410, 69360},
						   {71800, 67400},
						   {49580, 44180, 36780, 34580},
						   {58810, 53980, 50050, 47860, 46500},
						   {73930, 66980, 61610},
						   {50090, 44590, 40590, 39190, 22000}};

double otrlangkawi[6][5] = {{58650, 63080, 68030},
						    {70900, 66500},
						    {48280, 42980, 35580, 33380},
						    {58010, 53180, 49250, 47060, 45060},
						    {72600, 65650, 60280},
						    {48490, 42990, 38990, 37590, 22000}};

// Function declaration
void variants(int, int &, int &);
int dispColour(int);
double carInfo(int, int, int, int);
double installment(int, float, int, double);

// Main function
int main(void) {
	
	int model, variant, region, years, ifAtiva;
	double price, deposit;
	float interest;
	char next = 'y';
	
	do {
		cout << "Perodua Loan Calculator" << endl << endl;
	
		A:
		cout << "Models Available" << endl << "----------------" << endl
			 << "[1] Ativa" << endl 
			 << "[2] Aruz" << endl
			 << "[3] Bezza" << endl 
			 << "[4] Myvi" << endl 
			 << "[5] Alza" << endl 
			 << "[6] Axia" << endl << endl
			 << ">> ";						
	
		cin >> model;
		if (!(model > 0 && model < 7)) {
			cout << "Enter Available Models Only!" << endl << endl;
			goto A;
		}
		
		variants(model, variant, ifAtiva);			
		
		B:
		cout << endl 
			 << "Region" << endl 
			 << "------" << endl
			 << "[1] Peninsular Malaysia" << endl 
			 << "[2] East Malaysia" << endl
			 << "[3] Labuan" << endl
			 << "[4] Langkawi" << endl << endl
			 <<  ">> ";
		cin >> region;
		
		if (!(region > 0 && region < 5)) {
			cout << "Enter Available Regions Only!" << endl;
			goto B;
		}
		
		price = carInfo(model, variant, region, ifAtiva);
		cout << endl << endl;
		
		cout << "Down Payment (MYR): ";
		cin >> deposit;
		
		while (deposit < (price * 0.1)) {			
			cout << "The Down Payment MUST Be At Least 10% of the OTR Price!" << endl << endl;
			cout << "Down Payment (MYR): ";
			cin >> deposit;
		}		
		
		cout << "Interest Rate (%): ";
		cin >> interest;
		
		cout << "Repayment period (in years): ";
		cin >> years;
		
		cout << endl << "MONTHLY INSTALLMENT (MYR): " << fixed << setprecision(2) 
		<< installment(deposit, interest, years, price) << endl << endl;
		
		cout << "Do you want to enter other data? [Y @ N] >> ";
		cin >> next;
		cout << endl;
				
	} while (next == 'y' || next == 'Y');
	
	cout << "Thank You :)";
	return 0;
}

// Function definitions
void variants(int x, int &y, int &z) {
	
	cout << endl << "Variants" << endl << "--------" << endl;
	
	switch (x) {
		
		case 1:
		case 5:
			A:
			cout << "[1] " << variantName[x-1][0] << endl 
				 << "[2] " << variantName[x-1][1] << endl 
				 << "[3] " << variantName[x-1][2] << endl << endl
				 << ">> ";	
			break;
			
		case 2:
			B:
			cout << "[1] " << variantName[x-1][0] << endl 
				 << "[2] " << variantName[x-1][1] << endl << endl
				 << ">> ";
			break;
			
		case 3:
			C:
			cout << "[1] " << variantName[x-1][0] << endl 
				 << "[2] " << variantName[x-1][1] << endl
				 << "[3] " << variantName[x-1][2] << endl 
				 << "[4] " << variantName[x-1][3] << endl << endl
				 << ">> ";		
			break;
			
		case 4:
		case 6:
			D:
			cout << "[1] " << variantName[x-1][0] << endl 
				 << "[2] " << variantName[x-1][1] << endl 
				 << "[3] " << variantName[x-1][2] << endl 
				 << "[4] " << variantName[x-1][3] << endl 
				 << "[5] " << variantName[x-1][4] << endl << endl
				 << ">> ";			
			break;
	}
	
	cin >> y;
	
	if ((x == 1 || x == 5) && !(y > 0 && y < 4)) {
		cout << "Enter Available Variants Only!" << endl << endl;
		goto A;	
	} 
	else if (x == 2  && !(y > 0 && y < 3)) {
		cout << "Enter Available Variants Only!" << endl << endl;
		goto B;
	}
	else if (x == 3  && !(y > 0 && y < 5)) {
		cout << "Enter Available Variants Only!" << endl << endl;
		goto C;
	}
	else if ((x == 4 || x == 6)  && !(y > 0 && y < 6)) {
		cout << "Enter Available Variants Only!" << endl << endl;
		goto D;
	}
	
	if (x == 1)
		z = dispColour(y);
	else 
		z = 0;		
}

int dispColour (int k) {
	
	int input;
	cout <<	endl
		 << "Paint Type" << endl
		 << "----------" << endl;
		 
	do {
		
		for (int i = 0; i < k; i++)
			cout << "[" << i + 1 << "] " << carColour[i] << endl;
			
		cout << endl << ">> ";
		cin >> input;
		
		if (!(input > 0 && input < (k+1)))
			cout << "Enter Available Car Colours Only!" << endl << endl;
		
	} while (!(input > 0 && input < (k+1)));	
	return input;
}

double carInfo(int a, int b, int c, int d) {
	
	cout << endl 
		 << "--------" << endl 
		 << "Car Info" << endl 
		 << "--------" << endl << endl;
	
	cout << "Model: " << model[a-1] << endl
		 << "Variant: " << variantName[a-1][b-1] << endl
		 << "Region: " << region[c-1] << endl;
		 
	switch (d) {
		
		case 1:
			cout << "Paint Type: " << carColour[d-1] << endl;
			break;
			
		case 2:
			cout << "Paint Type: " << carColour[d-1] << endl;
			if (b == 2) {
				otrpenin[a-1][b-1] = 67800;
				otreast[a-1][b-1] = 69800;
				otrlabuan[a-1][b-1] = 64900;
				otrlangkawi[a-1][b-1] = 63570;
			}
			else if (b == 3) {
				otrpenin[a-1][b-1] = 73100;
				otreast[a-1][b-1] = 75100;
				otrlabuan[a-1][b-1] = 69850;
				otrlangkawi[a-1][b-1] = 68520;
			}
			break;
			
		case 3:
			cout << "Paint Type: " << carColour[d-1] << endl;
			otrpenin[a-1][b-1] = 73400;
			otreast[a-1][b-1] = 75400;
			otrlabuan[a-1][b-1] = 70130;
			otrlangkawi[a-1][b-1] = 68800;
			break; 
	}
	
	cout << "OTR Price (MYR): " << fixed << setprecision(2);
	
	if (c == 1) {
		cout << otrpenin[a-1][b-1];
		return otrpenin[a-1][b-1];
	} 
	else if (c == 2) {
		cout << otreast[a-1][b-1];
		return otreast[a-1][b-1];
	} 
	else if (c == 3) {
		cout << otrlabuan[a-1][b-1];
		return otrlabuan[a-1][b-1];
	}
	else {
		cout << otrlangkawi[a-1][b-1];
		return otrlangkawi[a-1][b-1];
	}
}

double installment(int p, float q, int r, double s) {
	
	return ((s-p) / (12.0 * r)) + ((s-p) * (q / 100.0)) / 12.0;
}
