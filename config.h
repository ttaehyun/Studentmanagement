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
	cout << "\nEnter menu : (숫자로 입력)" << endl;
	
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
		else cout << "메뉴를 다시 입력해주세요. " << endl;
	}
	return menu_num;
}
// read file
void File_read(string login_name) {
	string line;
	ifstream fin("Login.txt");
	if (fin.fail()) {
		cerr << "파일을 찾을 수 없음" << endl;
		exit(100);
	}
	while (getline(fin, line)) {
		//line에 담겨 있는 id, pw분리 
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