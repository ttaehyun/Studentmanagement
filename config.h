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
		cout << "\nEnter menu(숫자로 입력) : ";
		cin >> num;
		if (typeid(num).name() == typeid(string).name()) {
			cout << "숫자를 입력해주세요. " << endl;
			check = true;
		}
		else {
			if (purpose == "main") {
				if (num <= 3) {
					check = false;
				}
				else {
					cout << "메뉴를 다시 입력해주세요. " << endl;
					check = true;
				}
			}
			else if (purpose == "Admin") {
				if (num <= 5) {
					check = false;
				}
				else {
					cout << "메뉴를 다시 입력해주세요. " << endl;
					check = true;
				}
			}
			else if (purpose == "Student") {
				if (num <= 3) {
					check = false;
				}
				else {
					cout << "메뉴를 다시 입력해주세요. " << endl;
					check = true;
				}
			}
		}
	}
	
	return num;
}

// read file
void File_read() {	//딕셔너리 만들어서 id, pw별로 리스트로 저장
	string line;
	ifstream adminFile("Admin.txt");	//Admin 파일
	ifstream guestFile("Guest.txt");
	ifstream guestInfoFile("GuestInfo.txt");	//Guest 파일
	if (adminFile.fail()) {
		cerr << "파일을 찾을 수 없음" << endl;
		exit(100);
	}
	if (guestFile.fail()) {
		cerr << "파일을 찾을 수 없음" << endl;
		exit(100);
	}
	if (guestInfoFile.fail()) {
		cerr << "파일을 찾을 수 없음" << endl;
		exit(100);
	}
	// Admin 파일 임시 파일에 저장
	while (getline(adminFile, line)) {
		string id, pw;
		//line에 담겨 있는 id, pw분리 
		Line_sprite(line, &id, &pw);
		//cout << "id : " << id << "pw : " << pw << endl;
		Diction.Admin_append(id, pw);
	}
	// Guest 파일 임시 파일에 저장
	while (getline(guestFile, line)) {
		string id, pw;
		//line에 담겨 있는 id, pw분리 
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
	*pw = copy_line.erase(0, space_index+1);	//인덱스번호가 한칸 뒤에 있다
	
}

// wrtie file
void File_write(string filename, string content) {   
	ofstream fout(filename);   
	if (fout.fail()) {
		cerr << "파일을 찾을 수 없음" << endl;
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
		cout << "비번이 틀렸습니다." << endl;
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
		cout << "계속 입력하시겠습니까?(y or n) ";
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
	cout << "삭제할 이름을 입력하시오 : ";
	cin >> name;
	Diction.Guest_Del(name);
	List.Delete(name);
}

// Exit program
void Exit() {
	exit(0);
}