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
int Menu_select();
void File_read();
void Line_sprite(string, string*, string*);
void File_write(string);
bool Login(string* , string*);

// print menu
void Menu_print() {
	cout << "Available Login operations: " << endl;
	cout << "1. Admin Login " << endl;
	cout << "2. Student Login" << endl;
	cout << "3. Exit" << endl;
}

// select Menu & return Menu_number
int Menu_select() {
	bool Bool = true;
	bool check = true;

	int menu_num =0;

	while (Bool) {
		//���ڿ��� �ԷµǸ� �����ߴ� ���� ���ľߵ�
		while (check) {
			cout << "\nEnter menu(���ڷ� �Է�) : ";
			cin >> menu_num;
			if (typeid(menu_num).name() == typeid(string).name()) {
				cout << "���ڸ� �Է����ּ���. " << endl;
				check = true;
			}
			else					check = false;
		}
		if (menu_num == 1) {
			Bool = false;
		}	
		else if(menu_num == 2) {
			Bool = false;
		}
		else if (menu_num == 3) {
			Bool = false;
		}
		else cout << "�޴��� �ٽ� �Է����ּ���. " << endl;
	}
	return menu_num;
}
// read file
void File_read() {	//��ųʸ� ���� id, pw���� ����Ʈ�� ����
	string line, id, pw;
	ifstream fin("Login.txt");
	if (fin.fail()) {
		cerr << "������ ã�� �� ����" << endl;
		exit(100);
	}
	while (getline(fin, line)) {
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
	*pw = copy_line.erase(0, space_index);
	
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
	cout << "* Admin Login *" << endl;
	bool Bool;
	Bool = Login(&id, &pw);
	if (Bool == true) {
		cout << "����� Ʋ�Ƚ��ϴ�." << endl;
	}
	return Bool;
}

// Student Login
bool StudentLogin() {
	string id, pw;
	cout << "* Student Login *" << endl;
	bool Bool;
	Bool = Login(&id, &pw);
	return Bool;
}

// Login id, pw
bool Login(string* id, string* pw) {
	
	cout << "ID : ";
	cin >> *id;
	cout << "PW : ";
	cin >> *pw;
	if (*pw == Diction.Find(*id)) {
		return false;
	}
	else return true;
}

// check id in FileDictionary(id)

// check pw in FileDictionary(pw)

// Exit program
void Exit() {
	exit(0);
}