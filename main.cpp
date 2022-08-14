#include<iostream>
#include "config.h"

int main() {
	bool main = true, loop_bool = true; 
	int menu = 0;
	File_read();
	string id ="", pw="";
	while (main) {
		while (loop_bool) {
			Menu_print();
			menu = MenuSelect("main");
			if (menu == 1) {
				loop_bool = AdminLogin(&id,&pw);
			}
			else if (menu == 2) {
				loop_bool = StudentLogin(&id, &pw);
			}
			else {
				Exit();
			}
		}
		if (menu == 1) {
			Admin_Menu();
			LoggedAdmin(&main, &loop_bool, MenuSelect("Admin"));
		}
		else if (menu == 2) {
			Student_Menu();
			LoggedStudent(&main, &loop_bool, &id, MenuSelect("Student"));
		}
	}

}
