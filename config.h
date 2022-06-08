#include<iostream>
#include<string>
#include<fstream>
#include "util.h"
using namespace std;

// print menu
void Menu_print() {
	cout << "Available Login operations: " << endl;
	cout << "1. Admin Login " << endl;
	cout << "2. Student Login" << endl;
	cout << "3. Exit" << endl;
	cout << "\nEnter menu : (���ڷ� �Է�)" << endl;
	
}
// select Menu & return Menu_number
int Menu_select() {
	bool Bool = true;
	int menu_num =0;
	
	while (Bool) {
		cin >> menu_num;
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
void File_read(string login_name) {
	string line;
	ifstream fin("Login.txt");
	if (fin.fail()) {
		cerr << "������ ã�� �� ����" << endl;
		exit(100);
	}
	while (getline(fin, line)) {
		//line�� ��� �ִ� id, pw�и� 
		cout << line << endl;
	}
	fin.close();
}
// sprite line
void Line_sprite() {

}
// wrtie file
void File_write() {
	ofstream fout("Login.txt");

}

// Login id, pw
void Login() {
	int id, pw;
	cout << "ID : " << endl;
	cin >> id;
	cout << "PW : " << endl;
	cin >> pw;
}