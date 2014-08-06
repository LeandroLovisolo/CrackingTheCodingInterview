#include <iostream>
#include <cstring>

using namespace std;

void reverse(char *str) {
	int length = strlen(str);
	if(length <= 1) return;
	int j = length - 1;
	for(int i = 0; i < length; i++) {
		char c = str[j];
		str[j] = str[i];
		str[i] = c;
		j--;
	}
}

int main(int argc, char **argv) {
	if(argc != 2) return -1;
	reverse(argv[1]);
	cout << argv[1] << endl;
	return 0;
}