#include<string>
#include<iostream>
#include<list>
#include<map>
using namespace std;

// Class studentInfo
class EachStudentInfo {
private:
	int StudentID;
	string Name;
	string Department;
public:
	EachStudentInfo(int _StudentID, string _Name, string _Department)
	{
		StudentID = _StudentID;
		Name = _Name;
		Department = _Department;
	}
	void Show_Info();
	string getName();
};
void EachStudentInfo::Show_Info() {
	cout << Name << "'s Info" << endl;
	cout << "StudentID : " << StudentID << endl;
	cout << "Department : " << Department << endl;
}
string EachStudentInfo::getName() {
	return Name;
}
//List class studentInfo
class ListInfo : public EachStudentInfo {
private:
	list<EachStudentInfo> ClassINFO;
public:
	void DeleteList() {

	}
};
list<EachStudentInfo> ClassINFO; /*= {
	EachStudentInfo(1, "ttaehyun", "AI"),
	EachStudentInfo(2, "minari", "EE"),
	EachStudentInfo(3, "Kodari", "EE"),
	EachStudentInfo(4, "Gadari", "IRE"),
	EachStudentInfo(5, "Jota", "CS"),
};*/

// Admin - Show List
void ShowList() {
	for (auto iter = ClassINFO.begin(); iter != ClassINFO.end(); iter++) {
		EachStudentInfo a = *iter;
		a.Show_Info();
	}
	cout << endl;
}

// Student - Show List
void ShowListMe(string name) {
	for (auto iter = ClassINFO.begin(); iter != ClassINFO.end(); iter++) {
		EachStudentInfo a = *iter;
		if (a.getName() == name) {
			a.Show_Info();
		}
		else continue;
	}
	cout << endl;
}

// ID, PW File
class FileDictionary
{
private:
	map<string, string> IdPw_Admin;
	map<string, string> IdPw_Student;
public:
	// id, pw append
	void Dict_append(string id, string pw) {
		if (id == "Admin") {
			IdPw_Admin.insert({ id,pw });
		}
		else IdPw_Student.insert({ id,pw });
	};

	// id, pw Delete
	void Dict_Del(string id) {
		if (id == "Admin") {
			IdPw_Admin.erase(id);
		}
		else IdPw_Student.erase(id);
	};

	string Content() {
		for (auto iter = IdPw_Admin.begin(); iter != IdPw_Admin.end(); iter++)
		{
			return iter->first + " " + iter->second;
		}
	}
	// 저장된 id,pw보여줌
	void Show() {
		for (auto iter = IdPw_Admin.begin(); iter != IdPw_Admin.end(); iter++)
		{
			cout << iter->first << " " << iter->second << endl;
		}
		cout << endl;
		for (auto iter = IdPw_Student.begin(); iter != IdPw_Student.end(); iter++)
		{
			cout << iter->first << " " << iter->second << endl;
		}
		cout << endl;
	}
	// Find id in map
	string Find(string id) {
		if (id == "Admin") {
			auto item = IdPw_Admin.find(id);
			if (item != IdPw_Admin.end()) {
				return item->second;
			}
			else {
				cout << "존재하지 않는 ID입니다. " << endl;
				return "err";
			}
		}
		else {
			auto item = IdPw_Student.find(id);
			if (item != IdPw_Student.end()) {
				return item->second;
			}
			else {
				cout << "존재하지 않는 ID입니다. " << endl;
				return "err";
			}
		}
	}
};