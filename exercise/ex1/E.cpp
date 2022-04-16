#include <iostream>
#include <string>
using namespace std;
template <class T> 
class container{
// 在此处补充你的代码
    T a;
    public:
        container(T _a): a(_a) {}
        container operator +(container b) {
            T now = a;
            now += b.a;
            now += b.a;
            return container(now);
        }

        container operator +(T b) {
            T now = a;
            now += b;
            return container(now);
        }

        friend ostream& operator << (ostream &os, const container &a) {
            os << a.a;
            return os;
        }
};
int main(){
	int n,m;
	cin >> n >> m;
	string s1,s2;
	cin >> s1 >> s2;
    container <int> a = n;
    container <int> b = m;
    cout<<a+b<<endl;
    cout<<a+m<<endl;
    container <string> sa = string(s1);
    container <string> sb = string(s2);
    cout<<sa+sb<<endl;
    cout<< sa + s2<<endl;
}