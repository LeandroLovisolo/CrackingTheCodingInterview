#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
	if(argc != 3) return -1;
	string s(argv[1]), t(argv[2]);
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	if(s == t) {
		cout << "One is a permutation of the other." << endl;
	} else {
		cout << "The strings are not permutations." << endl;
	}
	return 0;
}