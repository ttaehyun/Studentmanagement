#include "util.h"

void Add_Student() {

}
void Delete_Student() {
	string name = "";
	cout << "������ �̸��� �Է��Ͻÿ� : ";
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