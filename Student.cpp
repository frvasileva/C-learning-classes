#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>


using namespace std;

struct StudentMarks {
	string Subject;
	double Mark;
};

class Student {

private:
	string Name;
	int Age;


	StudentMarks studentMarks[2];

public:
	//	Student(int age, string name);
	void ReadStudentBaseInfo();
	string GetName();

	void InputStudentMarks();
	void GetStudentMarks();
	//void Get() const;
	void WriteInFile();
	//void ReadFromFile();

};

int main() {

	Student student;
	student.ReadStudentBaseInfo();

	cout << "Student name is: " << student.GetName();


	student.InputStudentMarks();
	student.GetStudentMarks();

	student.WriteInFile();

	system("pause");

	return -1;
}

void Student::ReadStudentBaseInfo()
{
	cout << "What is student name?\n";
	cin >> Name;

	cout << "What is student age?\n";
	cin >> Age;
}

void Student::InputStudentMarks() {

	for (int i = 0; i < 2; i++) {
		cout << "\nSubject name: ";
		cin >> studentMarks[i].Subject;

		cout << "Mark: ";
		cin >> studentMarks[i].Mark;
	}
}

void Student::GetStudentMarks() {

	cout << "\n\n" << GetName() << "\nMarks: \n";

	for (int i = 0; i < 2; i++) {
		cout << "\n - " << studentMarks[i].Subject << " -- " << studentMarks[i].Mark;
	}
}

string Student::GetName() {
	return Name;
}

void Student::WriteInFile() {
	ofstream myfile;
	string fileName;
	cout << "\nWrite the name of file:";
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