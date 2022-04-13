#include <iostream>
using namespace std;
// 在此处补充你的代码
template<class T1, class T2> 
class f{
    T1 n;
    public:
        f(T1 _n): n(_n) {}

        T2 operator() (T2 m) {
            return m + n;
        }
};

int main()
{
   cout << f<int,int>(7)(9) << endl;   //16
   cout << f<string,string> (" hello!")("world")  <<endl; // world hello!
   cout << f<char,string> ('!')("world") << endl;
   
   
   return 0;    //world!
}