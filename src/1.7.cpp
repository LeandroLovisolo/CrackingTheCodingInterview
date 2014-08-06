#include <iostream>
#include <vector>

using namespace std;

void propagate_zeroes(vector<int> &M, int m, int n) {
	vector<bool> zeroed(m * n, false);
	for(int y = 0; y < m; y++) {
		for(int x = 0; x < n; x++) {
			if(zeroed[y * n + x]) continue;
			if(M[y * n + x] == 0) {
				for(int xx = 0; xx < n; xx++) {
					M[y * n + xx] = 0;
					zeroed[y * n + xx] = true;
				}
				for(int yy = 0; yy < m; yy++) {
					M[yy * n + x] = 0;
					zeroed[yy * n + x] = true;
				}
			}
		}
	}
}

void print(const vector<int> &M, int m, int n) {
	for(int y = 0; y < m; y++) {
		for(int x = 0; x < n; x++) {
			cout << M[y * n + x] << '\t';
		}
		cout << endl;
	}
}

int main() {
	int m = 6, n = 5;
	int mod = 12;

	vector<int> M(m * n);
	
	int i = 0;
	for(int y = 0; y < m; y++) {
		for(int x = 0; x < n; x++) {
			M[y * n + x] = i++ % mod;
		}
	}

	print(M, m, n);
	propagate_zeroes(M, m, n);
	cout << endl;
	print(M, m, n);

	return 0;
}