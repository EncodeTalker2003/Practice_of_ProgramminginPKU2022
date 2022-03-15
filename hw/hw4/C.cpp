#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
    public: 
        friend istream& operator >> (istream& is, Point &a) {
			cin >> a.x >> a.y;
			return is;
		}

		friend ostream& operator << (ostream& os, Point &a) {
			cout << a.x << ',' << a.y;
			return os;
		}

}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}