#include<string>
#include<list>
#include<map>
using namespace std;

class StudentInfo {
private:
	int StudentID;
	char Name[30];
	char Department;
public:
	void SelectShowInfo(char);
	void AllShowInfo();
};

 
struct StudentInfo {
	int StudentID;
	string Name;
	string Department;
};

// List Student Info 
list<StudentInfo> Infopack = { 
	{1, "ttaehyun", "AI"},
	{2, "minari", "EE"},
	{3, "Kodari", "EE"},
	{4, "Gadari", "IRE"},
	};

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