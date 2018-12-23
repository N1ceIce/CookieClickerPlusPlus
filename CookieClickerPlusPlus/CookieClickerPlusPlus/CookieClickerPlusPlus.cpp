//extremely unfinished
//blablabla

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <ctime>
using namespace std; 

void cookie_time(double cookies, double cursor_rate, int manual_rate, int cursor, int cursor_price, int rate_price) {
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
	cout << "                                                 " "You have " << cookies << " cookies!\n";
	cout << "                                                 " "You have " << cursor << " cursors!\n";
	cout << "                                                      " << manual_rate << " per click\n";
	cout << "                                                    " << cursor * cursor_rate << " per second\n\n";
	cout << "       Press A to upgrade Cursor                                                      Press S to upgrade Rate\n";
	cout << "              Price: " << cursor_price << "                                                                      Price: " << rate_price;
}

int main() {
	double cookies = 0, cursor_rate = 0.1;
	int manual_rate = 1, cursor = 0, cursor_price = 15, rate_price = 100;
	time_t ntime, counter = 0;
	string out;
	ifstream savefile("savedata.json");
	if (savefile) {
		string line;
		for (int x = 0; getline(savefile, line) && 6 > x; ++x) {
			if (x == 0) {
				cookies = stof(line);
			}
			if (x == 1) {
				cursor_rate = stof(line);
			}
			if (x == 2) {
				manual_rate = atoi(line.c_str());
			}
			if (x == 3) {
				cursor = atoi(line.c_str());
			}
			if (x == 4) {
				cursor_price = atoi(line.c_str());
			}
			if (x == 5) {
				rate_price = atoi(line.c_str());
			}
		}
		//cout << cookies << endl << cursor_rate << endl << manual_rate << endl << cursor << endl << cursor_price << endl << rate_price;
		cookie_time(cookies, cursor_rate, manual_rate, cursor, cursor_price, rate_price);
	}
	while (1) {
		if (GetKeyState(VK_SPACE) & (0x8000)) {
			cookies += manual_rate;
			while (GetKeyState(VK_SPACE) & (0x8000)) {
				Sleep(1);
			}
			cookie_time(cookies, cursor_rate, manual_rate, cursor, cursor_price, rate_price);
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
			cookie_time(cookies, cursor_rate, manual_rate, cursor, cursor_price, rate_price);
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
			cookie_time(cookies, cursor_rate, manual_rate, cursor, cursor_price, rate_price);
		}
		ntime = time(NULL);
		if (counter == 0) {
			counter = ntime + 1;
		}
		if (ntime >= counter) {
			cookies += cursor_rate * cursor;
			if (cursor >= 1) {
				cookie_time(cookies, cursor_rate, manual_rate, cursor, cursor_price, rate_price);
			}
			counter = ntime + 1;
		}
		ofstream savefile("savedata.json");
		savefile << cookies << endl << cursor_rate << endl << manual_rate << endl << cursor << endl << cursor_price << endl << rate_price;
		savefile.close();
   }
	return 0;
}
