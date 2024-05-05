#include <iostream>
#include <string>

using namespace std;

int main() {
	string str = "aaa";

	int not_unique;
	for (int i = 0; i < str.size() - 1; i += 2) {
		cout << str[i] << " " << str[i + 1] << endl;
		not_unique = static_cast<int>(str[i]) ^ static_cast<int>(str[i + 1]);
		if (not_unique) {
			break;
		}
	}
	cout << (not_unique ? false : true) << endl;
	return 0;
}
