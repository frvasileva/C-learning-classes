#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student {

private:
	int Age;
	string Name;

public:
	//	Student(int age, string name);
	void ReadInput();
	string GetName();
	//void Get() const;
	void WriteInFile();
	//void ReadFromFile();

};

int main() {

	Student student;
	student.ReadInput();

	cout << "Student name is: " << student.GetName();

	student.WriteInFile();


	system("pause");

	return -1;
}

void Student::ReadInput()
{
	cout << "What is student name?\n";
	cin >> Name;

	cout << "What is student age?\n";
	cin >> Age;
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
	myfile.close();
}