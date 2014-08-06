#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
	if(argc != 2) return -1;
	string str(argv[1]);
	sort(str.begin(), str.end());
	for(int i = 0; i < str.size(); i++) {
		if(i > 0 && str[i - 1] == str[i]) {
			cout << "Not all characters unique." << endl;
			return 0;
		}
	}
	cout << "All characters unique." << endl;
	return 0;
}