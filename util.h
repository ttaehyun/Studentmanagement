#include "header.h"

// Class studentInfo
class EachStudentInfo {
private:
	string StudentID;
	string Name;
	string Department;
public:
	EachStudentInfo(string _StudentID, string _Name, string _Department)
	{
		StudentID = _StudentID;
		Name = _Name;
		Department = _Department;
	}
	string Get_Info();
	string getName();
};

string EachStudentInfo::Get_Info() {
	string str;
	str = StudentID + " " + Department;
	return str;
}
string EachStudentInfo::getName() {
	return Name;
}

//vector class 
class ListInfo {
private:
	vector<EachStudentInfo> ClassINFO;	//map 으로 수정? 
public:
	/*ListInfo(string _Name, string _StudentID, string _Department)
	{
		ClassINFO.emplace_back(EachStudentInfo(_Name, _StudentID, _Department));
	}*/
	void Append(string);
	string ContentList();
	string ContentMe(string);
	void Delete(string);
};

void ListInfo::Append(string line) {
	vector<string> words;
	string space = " ";
	size_t pos = 0;
	string last = "";
	while ((pos = line.find(space)) != string::npos) {
		words.push_back(line.substr(0, pos));
		line.erase(0, pos + space.length());
		last = line;
	}
	words.push_back(last);
	//cout << words.size();
	ClassINFO.emplace_back(EachStudentInfo(words.at(1), words.at(0), words.at(2)));
}
void ListInfo::Delete(string name) {
	for (auto iter = ClassINFO.begin(); iter != ClassINFO.end(); iter++) {
		EachStudentInfo a = *iter;
		if (a.getName() == name) {
			ClassINFO.erase(iter);
			break;
		}
		else continue;
	}
}
string ListInfo::ContentList() {
	string str="";
	for (auto iter = ClassINFO.begin(); iter != ClassINFO.end(); iter++) {
		EachStudentInfo a = *iter;
		str += a.getName() + " " + a.Get_Info() + "\n";
	}
	return str;
}
string ListInfo::ContentMe(string name) {
	string str = "";
	for (auto iter = ClassINFO.begin(); iter != ClassINFO.end(); iter++) {
		EachStudentInfo a = *iter;
		if (a.getName() == name) {
			str += a.getName() + "\n" + a.Get_Info() + "\n";
			break;
		}
		else continue;
	}
	return str;
}

// ID, PW File
class FileDictionary
{
private:
	map<string, string> IdPw_Admin;
	map<string, string> IdPw_Student;
public:
	string IDpasswordMe(string);
	void Admin_append(string id, string pw) {
		IdPw_Admin.insert({ id,pw });	// 관리자 id,pw 임시파일에 저장
	};
	void Guest_append(string id, string pw) {
		IdPw_Student.insert({ id,pw }); // 게스트 id,pw 임시파일에 저장
	};

	// id, pw Delete
	void Admin_Del(string id) {
		IdPw_Admin.erase(id);
	};
	void Guest_Del(string id) {
		IdPw_Student.erase(id);
	};

	string Admin_Content() {
		string IDstring = "";
		for (auto iter = IdPw_Admin.begin(); iter != IdPw_Admin.end(); iter++)
		{
			IDstring += iter->first + " " + iter->second + "\n";
		}
		return IDstring;
	}
	string Student_content() {
		string IDstring = "";
		for (auto iter = IdPw_Student.begin(); iter != IdPw_Student.end(); iter++)
		{
			IDstring += iter->first + " " + iter->second + "\n";
		}
		return IDstring;
	}

	// Find id in map
	string Find(string id) {

		auto Firstitem = IdPw_Admin.find(id);
		if (Firstitem != IdPw_Admin.end()) {
			return Firstitem->second;
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

string FileDictionary::IDpasswordMe(string name) {
	string str;
	for (auto iter = IdPw_Student.begin(); iter != IdPw_Student.end(); iter++)
	{
		if (iter->first == name) {
			str += "ID : " + iter->first + "\n" + "PW : " + iter->second + "\n";
			break;
		}
		else continue;
	}
	return str;
}