/* 
	Title		: Lab Exercise 2 (SECJ1013)
	Name		: Mikael Haqimi Bin Nahar Junaidi
	Matrics No.	: A24CS0111
	Section		: 03
	Lecturer	: Dr. Alif Ridzuan Bin Khairuddin
	Date		: 14th November 2024
*/

#include <iostream>
using namespace std;

int main() {
	
	int sum = 0, integer;
	
	cout << "Enter an integer: ";
	cin >> integer;
	
	// Loop to calculate the sum of digits.
	do {
		
		int digit = integer % 10;
		cout << digit;
		sum += digit;
		
		if (integer > 10) {
			cout << " + ";
		}
		else {
			cout << " = " << sum << endl;
		}
		
		integer = (integer - digit) / 10;
		
	} while (integer > 0);
	
	// Check if sum is even or odd.
	if (sum % 2 == 0) {
		cout << sum << " is even number";
	}
	else {
		cout << sum << " is odd number";
	}
	
	// Check if sum is a multiple of 3, 4 and/or 5.
	if (sum % 3 == 0 && sum % 4 == 0 && sum % 5 == 0) {
		cout << " & multiples of 3, 4 and 5" << endl;
	}
	else if (sum % 3 == 0 && sum % 4 == 0) {
		cout << " & multiples of 3 and 4" << endl;
	}
	else if (sum % 3 == 0 && sum % 5 == 0) {
		cout << " & multiples of 3 and 5" << endl;
	}
	else if (sum % 4 == 0 && sum % 5 == 0) {
		cout << " & multiples of 4 and 5" << endl;
	}
	else if (sum % 3 == 0) {
		cout << " & multiples of 3" << endl;
	}
	else if (sum % 4 == 0) {
		cout << " & multiples of 4" << endl;
	}
	else if (sum % 5 == 0) {
		cout << " & multiples of 5" << endl;
	}
	
	return 0;
}
