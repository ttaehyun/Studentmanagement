#include<iostream>
#include "config.h"





int main() {
	bool loop_bool = true;
	File_read();
	while (loop_bool) {
		Menu_print();
		int menu = Menu_select();
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

}
