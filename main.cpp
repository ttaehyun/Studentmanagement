#include<iostream>
#include "config.h"





int main() {
	bool main = true, loop_bool = true; 
	int menu = 0;
	File_read();
	while (main) {
		while (loop_bool) {
			Menu_print();
			menu = MenuSelect("main");
			if (menu == 1) {
				loop_bool = AdminLogin();
			}
			else if (menu == 2) {
				loop_bool = StudentLogin();
			}
			else {
				Exit();
			}
		}
		if (menu == 1) {
			Admin_Menu();

		}
		else if (menu == 2) {
			Student_Menu();
		}
	}

}
