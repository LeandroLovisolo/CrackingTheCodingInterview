#include <iostream>
#include <string>

using namespace std;

string compress(const string &s) {
	string compressed;
	int repetitions = 0;
	for(int i = 0; i < s.length(); i++) {
		if(i == 0 || (repetitions == 0 && s[i - 1] != s[i])) {
			compressed += s[i];
			continue;
		}
		if(repetitions == 0 && s[i - 1] == s[i]) {
			repetitions++;
			continue;
		}
		if(s[i - 1] == s[i]) {
			repetitions++;
		}
		if(s[i - 1] != s[i] || i == s.length() - 1) {
			string n(repetitions + 1);
			compressed + s[i - 1] + n;
			repetitions = 0;
		}
	}
	return compressed;
}

int main(int argc, char **argv) {
	if(argc != 2) return -1;
	string s(argv[1]);
	string compressed = compress(s);
	if(compressed.length() >= s.length()) {
		cout << s << endl;
	} else {
		cout << compressed << endl;
	}
	return 0;
}
