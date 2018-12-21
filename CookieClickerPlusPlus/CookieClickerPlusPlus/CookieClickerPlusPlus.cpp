//extremely unfinished

#include "pch.h"
#include <iostream>
#include <Windows.h>
using namespace std; 

int main() {
	int cookies = 0, manual_rate = 1;
	while (1) {
		system("CLS");
		cout << "\n                                                   C++Kie Clicker\n\n";
		cout << "                                           ______________________________ \n"; 
		cout << "                                          |                              |\n";
		cout << "                                          |                  *           |\n";
		cout << "                                          |       *                   *  |\n";
		cout << "                                          |                   *          |\n";
		cout << "                                          |   *                          |\n";
		cout << "                                          |          *                   |\n";
		cout << "                                          |                     *        |\n";
		cout << "                                          |                              |\n";
		cout << "                                          |   *           *              |\n";
		cout << "                                          |                        *     |\n";
		cout << "                                          |                              |\n";
		cout << "                                           ------------------------------ \n";
		cout << "                                                          " << cookies;
	
		if (GetKeyState(VK_SPACE) & (0x8000)) {
			cookies += manual_rate;
			while (GetKeyState(VK_SPACE) & (0x8000)) {
				Sleep(1);
			}
		}
   }
}
