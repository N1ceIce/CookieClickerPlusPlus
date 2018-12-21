//extremely unfinished

#include "pch.h"
#include <iostream>
#include <Windows.h>
using namespace std; 

int main() {
	float cookies = 0, cursor_rate = 0.1;
	int counter = 0, manual_rate = 1, cursor = 0, cursor_price = 15, rate_price = 100;
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
		cout << "                                                 " "You have "<< cookies << " cookies!\n";
		cout << "                                                 " "You have " << cursor << " cursors!\n";
		cout << "                                                      " << manual_rate << " per click\n";
		cout << "                                                    " << cursor * cursor_rate << " per second\n\n";
		cout << "       Press A to upgrade Cursor                                                      Press S to upgrade Rate\n";
		cout << "              Price: " << cursor_price << "                                                                      Price: " << rate_price;
	
		if (GetKeyState(VK_SPACE) & (0x8000)) {
			cookies += manual_rate;
			while (GetKeyState(VK_SPACE) & (0x8000)) {
				Sleep(1);
			}
		}
		if (GetKeyState('A') & (0x8000)) {
			if (cookies >= cursor_price) {
				cookies -= cursor_price;
				cursor_price += 3;
				cursor += 1;
			}
			while (GetKeyState('A') & (0x8000)) {
				Sleep(1);
			}
		}
		if(GetKeyState('S') & (0x8000)) {
			if (cookies >= rate_price) {
				cookies -= rate_price;
				rate_price *= 5;
				manual_rate *= 2;
				cursor_rate *= 2;
			}
			while (GetKeyState('S') & (0x8000)) {
				Sleep(1);
			}
		}
		if (counter == 15) {
			cookies += cursor_rate * cursor;
			counter = -1;
		}
		counter++;
   }
}
