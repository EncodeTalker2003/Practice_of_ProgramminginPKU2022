#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
int n, m;
	int** ptr;

	public:

	Array2() {
		n = 0; 
		m = 0;
		ptr = NULL;
	}

	Array2(int _n, int _m) : n(_n), m(_m) {
		ptr = new int* [n];
		for (int i = 0; i < n; i++) {
			ptr[i] = new int [m];
		}
	}

	int& operator () (int x, int y) {
		return *(*(ptr + x) + y);
	}

	int* operator[] (int x) {
		return ptr[x];
	}
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}