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

void StudentInfo::SelectShowInfo(char name) {

}

void StudentInfo::AllShowInfo() {

}

class Admin{

};

class FileDictionary
{
private:
	map<string, string> IdPw;
public:
	void Dict_append(string id, string pw) {
		IdPw.insert({id, pw});
	};
	void Dict_Del(string id) {
		IdPw.erase(id);
	};
	void Show() {
		for (auto iter = IdPw.begin(); iter != IdPw.end(); iter++)
		{
			cout << iter->first << " " << iter->second << endl;
		}
		cout << endl;
	}
	string Find(string id) {
		return IdPw.find(id)->second;
	}
};

//void FileDictionary::Dict_append(id, pw) {
//	IdPw.insert({id, pw});
//}

//void FileDictionary::Dict_Del(char id, char pw) {
//	IdPw.erase(id);
//}