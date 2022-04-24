#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector> 
#include <set>
#include <cstdio>
using namespace std;
// 在此处补充你的代码
template<class T>
class MySet: public set<T, greater<T> > {
    public:
        typedef typename set<T>::iterator iterator;
        iterator find(T x) {
            return this->set<T, greater<T> >::find(x);
        }

        void erase(iterator x) {
            this->set<T, greater<T> >::erase(x);
        }

        template<class T2>
        void erase(T2* st, T2* ed) {
            for (T2* i = st; i != ed; i++) {
                this->set<T, greater<T> >::erase(*i);
            }
        }
};

struct A {
	int n;
	A(int i):n(i) { }
	operator int() {
		return n;
	}
	bool operator >(const A & a) const {
		return n > a.n;
	}
};
template <class IT>
void print(IT s,IT e)
{	
	for(; s != e; ++s)
		cout << *s << ",";
	cout << endl;
}
int main()
{
	MySet<int> mst;
	for (int i = 0;i < 10; ++i)
		mst.insert(i);
	print(mst.begin(),mst.end());
	int a[] = {1,2,3,4};
	mst.erase(a,a+3);
	print(mst.begin(),mst.end());
	
	A b[] = {{7},{8}};
	mst.erase(b,b+2);
	print(mst.begin(),mst.end());	
	mst.erase(mst.find(6));
	print(mst.begin(),mst.end());
	for(int i = 0;i < 1000000; ++i)
		mst.insert(i);
	for(int i = 0; i < 1000000 - 10; ++i) 
		mst.erase(mst.find(i));
	int n;
	cin >> n;
	MySet<A> msta;
	
	for(int i = 0;i < n; ++i) {
		string cmd;
		int n;
		cin >> cmd >> n;
		if( cmd == "ADD") 
			msta.insert(A(n));
		else {
			if (msta.find(A(n))!= msta.end())
				cout << "YES"  <<endl; 
			else
				cout << "NO" <<endl;
		}
	}
	return 0;
}