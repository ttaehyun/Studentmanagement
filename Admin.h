#include "util.h"

void Add_Student() {

}
void Delete_Student() {
	string name = "";
	cout << "삭제할 이름을 입력하시오 : ";
	cin >> name;
	// Fix this
	for (auto iter = Infopack.begin(); iter != Infopack.end(); iter++) {
		StudentInfo a = *iter;
		if (a.Name == name) {
			Infopack.erase(iter);
		}
		else continue;
	}
}