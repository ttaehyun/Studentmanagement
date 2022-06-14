#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include "util.h"
using namespace std;

//LoginDictionary variable
FileDictionary Diction;

//func pack
void Menu_print();
void Admin_Menu();
void LoggedAdmin(bool* , int);
void Student_Menu();
void LoggedStudent(bool* , int);
int MenuSelect(string);
void File_read();
void Line_sprite(string, string*, string*);
void File_write(string);
bool Login(string, string* , string*);

// print menu
void Menu_print() {
	cout << "Available Login operations: " << endl;
	cout << "1. Admin Login " << endl;
	cout << "2. Student Login" << endl;
	cout << "3. Exit" << endl;
}

// print Admin menu
void Admin_Menu() {
	cout << "- Logged in as Admin -" << endl;
	cout << "1. Add Students" << endl;
	cout << "2. Delete Students" << endl;
	cout << "3. View Table" << endl;
	cout << "4. Main Menu" << endl;
	cout << "5. Exit" << endl;
}

// print Logged each Admin menu
void LoggedAdmin(bool* main, int num) {
	switch (num)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:

		break;
	case 4:
		*main = true;
		break;
	case 5:
		Exit();
		break;
	}
}
// print Student menu
void Student_Menu() {
	cout << "- Logged in as Admin -" << endl;
	cout << "1. View Table" << endl;
	cout << "2. Main Menu" << endl;
	cout << "3. Exit" << endl;
}

// MenuSelect
int MenuSelect(string purpose) {
	bool check = true;
	int num;
	while (check) {
		cout << "\nEnter menu(���ڷ� �Է�) : ";
		cin >> num;
		if (typeid(num).name() == typeid(string).name()) {
			cout << "���ڸ� �Է����ּ���. " << endl;
			check = true;
		}
		else {
			if (purpose == "main") {
				if (num <= 3) {
					check = false;
				}
				else {
					cout << "�޴��� �ٽ� �Է����ּ���. " << endl;
					check = true;
				}
			}
			else if (purpose == "Admin") {
				if (num <= 5) {
					check = false;
				}
				else {
					cout << "�޴��� �ٽ� �Է����ּ���. " << endl;
					check = true;
				}
			}
			else if (purpose == "Student") {
				if (num <= 3) {
					check = false;
				}
				else {
					cout << "�޴��� �ٽ� �Է����ּ���. " << endl;
					check = true;
				}
			}
		}
	}
	
	return num;
}

// read file
void File_read() {	//��ųʸ� ���� id, pw���� ����Ʈ�� ����
	string line;
	ifstream fin("Login.txt");
	if (fin.fail()) {
		cerr << "������ ã�� �� ����" << endl;
		exit(100);
	}
	while (getline(fin, line)) {
		string id, pw;
		//line�� ��� �ִ� id, pw�и� 
		Line_sprite(line, &id, &pw);
		//cout << "id : " << id << "pw : " << pw << endl;
		Diction.Dict_append(id, pw);
	}
	Diction.Show();
	fin.close();
}

// sprite line
void Line_sprite(string line, string* id, string* pw) {
	string copy_line = line;
	int index = line.length();
	int space_index = line.find(" ");
	*id = line.erase(space_index, index);
	*pw = copy_line.erase(0, space_index+1);	//�ε�����ȣ�� ��ĭ �ڿ� �ִ�
	
}

// wrtie file
void File_write(string IdPw) {   
	ofstream fout("Login.txt");   
	if (fout.fail()) {
		cerr << "������ ã�� �� ����" << endl;
		exit(100);
	}

}

// Admin Login
bool AdminLogin() {
	string id, pw;
	bool Bool;
	cout << "* Admin Login *" << endl;
	Bool = Login("Admin", &id, &pw);
	return Bool;
}

// Student Login
bool StudentLogin() {
	string id, pw;
	cout << "* Student Login *" << endl;
	bool Bool;
	Bool = Login("Student", &id, &pw);
	return Bool;
}

// Login id, pw
bool Login(string classify, string* id, string* pw) {
	
	cout << "ID : ";
	cin >> *id;
	cout << "PW : ";
	cin >> *pw;
	string password = Diction.Find(*id);
	if (*pw == password) {
		return false;
	}
	else if (*pw == "err") {
		return true;
	}
	else {
		cout << "����� Ʋ�Ƚ��ϴ�." << endl;
		return true;
	}
}

// check id in FileDictionary(id)

// check pw in FileDictionary(pw)

// Exit program
void Exit() {
	exit(0);
}