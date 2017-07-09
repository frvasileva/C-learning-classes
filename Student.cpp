#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct StudentMarks {
	string Subject;
	double Mark;
};

class Person {
protected:
	string Name;
	int Age;

public:
	void InputPersonData();
};

class Student : public Person {

private:
	char StudentNumber[5];
	StudentMarks studentMarks[2];

	friend istream& operator>>(istream&, Person&);

public:
	void InputStudentBaseInfo();
	string GetName() const;

	void InputStudentMarks();
	void GetStudentMarks() const;
	void SaveInFile();

};

int main() {

	Student student;

	student.InputPersonData();
	student.InputStudentBaseInfo();
	student.InputStudentMarks();

	student.SaveInFile();

	system("pause");

	return -1;
}

void Person::InputPersonData() {
	cout << "What is person name?\n";
	cin >> Name;

	do
	{
		cout << "What is person age?\n";
		cin >> Age;
	} while (Age <= 18 || Age >= 65);

}
void Student::InputStudentBaseInfo()
{
	cout << "What is student number?\n";
	cin >> StudentNumber;
}

void Student::InputStudentMarks() {

	for (int i = 0; i < 2; i++) {
		cout << "\nSubject name: ";
		cin >> studentMarks[i].Subject;

		cout << "Mark: ";
		cin >> studentMarks[i].Mark;
	}
}

void Student::GetStudentMarks() const {

	cout << "\n\n" << GetName() << "\nMarks: \n";

	for (int i = 0; i < 2; i++) {
		cout << "\n - " << studentMarks[i].Subject << " -- " << studentMarks[i].Mark;
	}
}

string Student::GetName() const {
	return Name;
}

void Student::SaveInFile() {
	ofstream myfile;
	string fileName;
	cout << "\nWrite the name of file: ";
	cin >> fileName;

	myfile.open(fileName + ".txt");

	if (myfile.is_open())
	{
		cout << "the file is opened";
	}

	myfile << "Writing this to a file.\n";
	myfile << "Student name: " << Name << "\n";
	myfile << "Student age: " << Age << "\n";
	for (int i = 0; i < 2; i++) {
		myfile << "\n - " << studentMarks[i].Subject << " -- " << studentMarks[i].Mark;
	}
	myfile.close();
}


//istream& operator>> (istream& is, Date& dt)
//{
//	is >> dt.mo >> dt.da >> dt.yr;
//	return is;
//}