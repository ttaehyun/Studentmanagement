#include "util.h"

using namespace std;

//LoginDictionary variable
FileDictionary Diction;
ListInfo List;

//func pack
void Menu_print();
void Admin_Menu();
void LoggedAdmin(bool* , bool*, int);
void Student_Menu();
void LoggedStudent(bool* ,bool*, string*, int);
int MenuSelect(string);

void File_read();
void Line_sprite(string, string*, string*);
void File_write(string, string);

bool AdminLogin(string*, string*);
bool StudentLogin(string*, string*);
bool Login(string, string* , string*);
void Exit();

void Add_Student();
void Delete_Student();

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
void LoggedAdmin(bool* main,bool* loop_bool, int num) {
	switch (num)
	{
	case 1:
		Add_Student();
		//cout << Diction.Student_content() << endl;
		File_write("Guest.txt", Diction.Student_content());
		File_write("GuestInfo.txt", List.ContentList());
		break;
	case 2:
		Delete_Student();
		File_write("Guest.txt", Diction.Student_content());
		File_write("GuestInfo.txt", List.ContentList());
		break;
	case 3:
		cout << List.ContentList();
		break;
	case 4:
		*main = true;
		*loop_bool = true;
		break;
	case 5:
		Exit();
		break;
	}
}
// print Student menu
void Student_Menu() {
	cout << "- Logged in as Student -" << endl;
	cout << "1. View Table" << endl;
	cout << "2. Main Menu" << endl;
	cout << "3. Exit" << endl;
}

// print Logged each Student Menu
void LoggedStudent(bool* main, bool* loop_bool,string* id, int num) {
	switch (num)
	{
	case 1:
		cout << List.ContentMe(*id);
		cout << Diction.IDpasswordMe(*id);
		break;
	case 2:
		*main = true;
		*loop_bool = true;
		break;
	case 3:
		Exit();
		break;
	}
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
	ifstream adminFile("Admin.txt");	//Admin ����
	ifstream guestFile("Guest.txt");
	ifstream guestInfoFile("GuestInfo.txt");	//Guest ����
	if (adminFile.fail()) {
		cerr << "������ ã�� �� ����" << endl;
		exit(100);
	}
	if (guestFile.fail()) {
		cerr << "������ ã�� �� ����" << endl;
		exit(100);
	}
	if (guestInfoFile.fail()) {
		cerr << "������ ã�� �� ����" << endl;
		exit(100);
	}
	// Admin ���� �ӽ� ���Ͽ� ����
	while (getline(adminFile, line)) {
		string id, pw;
		//line�� ��� �ִ� id, pw�и� 
		Line_sprite(line, &id, &pw);
		//cout << "id : " << id << "pw : " << pw << endl;
		Diction.Admin_append(id, pw);
	}
	// Guest ���� �ӽ� ���Ͽ� ����
	while (getline(guestFile, line)) {
		string id, pw;
		//line�� ��� �ִ� id, pw�и� 
		Line_sprite(line, &id, &pw);
		//cout << "id : " << id << "pw : " << pw << endl;
		Diction.Guest_append(id, pw);
	}
	while (getline(guestInfoFile, line)) {
		List.Append(line);
	}
	cout << Diction.Student_content();

	adminFile.close();
	guestFile.close();
	guestInfoFile.close();
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
void File_write(string filename, string content) {   
	ofstream fout(filename);   
	if (fout.fail()) {
		cerr << "������ ã�� �� ����" << endl;
		exit(100);
	}
	fout.write(content.c_str(), content.size());
	fout.close();
}

// Admin Login
bool AdminLogin(string* id, string* pw) {
	bool Bool;
	cout << "* Admin Login *" << endl;
	Bool = Login("Admin", &*id, &*pw);
	return Bool;
}

// Student Login
bool StudentLogin(string *id, string *pw) {
	cout << "* Student Login *" << endl;
	bool Bool;
	Bool = Login("Student", &*id, &*pw);
	return Bool;
}

// Login id, pw
bool Login(string classify, string* id, string* pw) {
	
	cout << "ID : ";
	cin >> *id;
	cout << "PW : ";
	cin >> *pw;
	string password = Diction.Find(*id);
	if (*pw == "err") {
		return true;
	}
	else if (*pw == password) {
		return false;
	}
	else {
		cout << "����� Ʋ�Ƚ��ϴ�." << endl;
		return true;
	}
}

void Add_Student() {
	bool broken = true;
	string yesorno = "";
	string name = "";
	string Studentid = "";
	string department = "";
	string id = "";
	string pw = "";

	while (broken) {
		cout << "��� �Է��Ͻðڽ��ϱ�?(y or n) ";
		cin >> yesorno;
		if (yesorno == "y") {
			cout << "Name : ";
			cin >> name;
			cout << "StudentID : ";
			cin >> Studentid;
			cout << "Department : ";
			cin >> department;
			cout << "ID : ";
			cin >> id;
			cout << "PW : ";
			cin >> pw;
			Diction.Guest_append(id, pw);
			string str;
			str += name + " " + Studentid + " " + department;
			List.Append(str);
		}
		else broken = false;
	}
}

void Delete_Student() {
	string name = "";
	cout << "������ �̸��� �Է��Ͻÿ� : ";
	cin >> name;
	Diction.Guest_Del(name);
	List.Delete(name);
}

// Exit program
void Exit() {
	exit(0);
}