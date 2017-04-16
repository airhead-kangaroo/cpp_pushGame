#include "Main.h"

using namespace std;

int main() {
	Stage *stage = new Stage();
	stage->show();
	string str;
	while (true) {
		cin.clear();
		cin >> str;
		if (str.length() == 1) {
			if (stage->move(str[0])) {
				stage->show();
			}
			else {
				break;
			}
		}
	}
	cout << "Congratulations!";
	cin.clear();
	cin >> str;
}