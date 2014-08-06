#include <iostream>
#include <cstdlib>

using namespace std;

void reverse(char *str) {
	int lenght = strlen(str);
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
	cout << reverse(argv[1]);
	return 0;
}