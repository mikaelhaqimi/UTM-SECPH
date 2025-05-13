// EXERCISE 1: INTRODUCTION TO CLASSES AND OBJECTS

// Programming Technique II
// Semester 2, 2024/2025

// Section: 03
// Member 1's Name: MUHAMMAD FIRDAUS BIN MD LANI (A24CS0132)
// Member 2's Name: MIKAEL HAQIMI BIN NAHAR JUNAIDI (A24CS0111)

// Date and time of pair programming sessions:
// 20/4/2025, 23:30 , 2.5 hours

#include <iostream>
#include <string>

using namespace std;

class Subject { // 1
	
	private:
		string name, code, grade;
		int score;
	
	public:
		
		Subject(string n, string c, int s) { // 2a
			name = n;
			code = c;
			score = s;
		}
		
		Subject() { // 2b
			name = "";
			code = "";
			score = 0;
		}
		
		~Subject() {} // 3
		
		// 4 (Accessors)
		string getName() const { return name; } 
		string getCode() const { return code; }
		int getScore() const { return score; }
		
		string calcGrade() const { // 5a
				 if (score>=90 && score<=100) return "A+";
			else if (score>=80 && score<=89)  return "A";
			else if (score>=75 && score<=79)  return "A-";
			else if (score>=70 && score<=74)  return "B+";
			else if (score>=65 && score<=69)  return "B";
			else if (score>=60 && score<=64)  return "B-";
			else if (score>=55 && score<=59)  return "C+";
			else if (score>=50 && score<=54)  return "C";
			else if (score>=45 && score<=49)  return "C-";
			else if (score>=40 && score<=44)  return "D+";
			else if (score>=35 && score<=39)  return "D";
			else if (score>=30 && score<=34)  return "D-";
										else  return "E";
		}
		
		double calcPointVal() { // 5b
			grade = calcGrade();
			
				 if (grade == "A+") return 4.00;	
			else if (grade == "A")  return 4.00;
			else if (grade == "A-") return 3.67;
			else if (grade == "B+") return 3.33;
			else if (grade == "B")  return 3.00;
			else if (grade == "B-") return 2.67;
			else if (grade == "C+") return 2.33;
			else if (grade == "C")  return 2.00;
			else if (grade == "C-") return 1.67;
			else if (grade == "D+") return 1.33;
			else if (grade == "D")  return 1.00;
			else if (grade == "D-") return 0.67;
							   else return 0.00;
		}
		
		int getCreditHour() {
			return (code[code.length()-1] - '0');
		}
		
		double calcPointEarned() { // 5c
			return calcPointVal() * getCreditHour();
		}
		
		// 4 (Mutators)
		void setName(string n) { name = n; }
		void setCode(string c) { code = c; }
		void setScore(int s) { score = s; }
};


int main()
{
	Subject s; // 6a
	string name, code;
	int score;
	
	// 6b
	cout << "Enter the following data: " << endl;
	cout << "  Subject name => ";
	getline(cin, name);
	s.setName(name);

	cout << "  Subject code => ";
	getline(cin, code);
	s.setCode(code);

	cout << "  Score earned => ";
	cin >> score;
	s.setScore(score);

	cout << endl
		 << endl;

	// 6c
	cout << "THE RESULT" << endl
		 << endl;

	cout << "Subject Code : " << s.getCode() << endl;
	cout << "Subject Name : " << s.getName() << endl;
	cout << "Credit Hour  : " << s.getCreditHour() << endl;
	cout << "Score Earned : " << s.getScore() << endl;
	cout << "Grade Earned : " << s.calcGrade() << endl;
	cout << "Grade Point  : " << s.calcPointVal() << endl;
	cout << "Point Earned : " << s.calcPointEarned() << endl;
	cout << endl;
	
	system("pause");
	
	return 0;
}