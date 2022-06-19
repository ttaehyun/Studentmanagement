#include "util.h"

void Add_Student() {

}
void Delete_Student() {
	string name = "";
	cout << "삭제할 이름을 입력하시오 : ";
	cin >> name;
	// Fix this
	for (auto iter = ClassINFO.begin(); iter != ClassINFO.end(); iter++) {
		EachStudentInfo a = *iter;
		if (a.getName() == name) {
			
		}
		else continue;
	}
}