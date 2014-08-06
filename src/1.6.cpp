#include <iostream>

using namespace std;

int xy2offset(int n, int x, int y) {
	return y * n + x;
}

int get_coord(int *M, int n, int x, int y) {
	return M[xy2offset(n, x, y)];
}

void set_coord(int *M, int n, int x, int y, int val) {
	M[xy2offset(n, x, y)] = val;
}

void rotate_coords(int n, int x, int y, int &xr, int &yr) {
	xr = n - 1 - y;
	yr = x;
}

void rotate_one(int *M, int n, int x, int y) {
	int a, b, c, d, x1, y1, x2, y2, x3, y3;
	rotate_coords(n, x,  y,  x1, y1);
	rotate_coords(n, x1, y1, x2, y2);
	rotate_coords(n, x2, y2, x3, y3);
	a = get_coord(M, n, x,  y);
	b = get_coord(M, n, x1, y1);
	c = get_coord(M, n, x2, y2);
	d = get_coord(M, n, x3, y3);
	set_coord(M, n, x1, y1, a);
	set_coord(M, n, x2, y2, b);
	set_coord(M, n, x3, y3, c);
	set_coord(M, n, x,  y,  d);
}

void rotate(int *M, int n) {
	for(int y = 0; y < n/2; y++) {
		for(int x = y; x < n - y - 1; x++) {
			rotate_one(M, n, x, y);
		}
	}
}

void print(int *M, int n) {
	for(int y = 0; y < n; y++) {
		for(int x = 0; x < n; x++) {
			cout << get_coord(M, n, x, y) << '\t';
		}
		cout << endl;
	}
}

int main() {
	int n = 5;
	int M[n*n];
	int i = 0;
	for(int y = 0; y < n; y++) {
		for(int x = 0; x < n; x++) {
			set_coord(M, n, x, y, i++);
		}
	}

	print(M, n);
	rotate(M, n);
	cout << endl;
	print(M, n);

	return 0;
}