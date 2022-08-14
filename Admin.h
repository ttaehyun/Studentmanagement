#include "header.h"


//void Add_Student(FileDictionary* dic) {
//	bool broken = true;
//	string yesorno = "";
//	string name = "";
//	int Studentid = 0;
//	string department = "";
//	string id = "";
//	string pw = "";
//	FileDictionary dc = *dic;
//
//	while (broken) {
//		cout << "계속 입력하시겠습니까?(y or n) ";
//		cin >> yesorno;
//		if (yesorno == "y") {
//			cout << "Name : ";
//			cin >> name;
//			cout << "StudentID : ";
//			cin >> Studentid;
//			cout << "Department : ";
//			cin >> department;
//			cout << "ID : ";
//			cin >> id;
//			cout << "PW : ";
//			cin >> pw;
//			dc.Dict_append(id, pw);
//			ClassINFO.push_back(EachStudentInfo(Studentid, name, department));
//		}
//		else broken = false;
//	}
//}
//void Delete_Student(FileDictionary dic, list<EachStudentInfo> list) {
//	string name = "";
//	cout << "삭제할 이름을 입력하시오 : ";
//	cin >> name;
//	//int n = 0;
//	// Fix this
//	dic.Dict_Del(name);
//	for (auto iter = list.begin(); iter != list.end(); iter++) {
//		EachStudentInfo a = *iter;
//		if (a.getName() == name) {
//			list.erase(iter);
//		}
//		else break;
//	}
//}