#include "util.h"

void Add_Student() {

}
void Delete_Student() {
	string name = "";
	cout << "������ �̸��� �Է��Ͻÿ� : ";
	cin >> name;
	// Fix this
	for (auto iter = ClassINFO.begin(); iter != ClassINFO.end(); iter++) {
		EachStudentInfo a = *iter;
		if (a.getName() == name) {
			
		}
		else continue;
	}
}