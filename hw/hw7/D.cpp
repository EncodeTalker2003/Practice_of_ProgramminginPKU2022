#include <iostream>
using namespace std;
class MyCin
{

    private:
        int endFlag;
    public:
        MyCin() {
            endFlag = 1;
        }

        MyCin& operator >> (int& n) {
            if (!endFlag) return *this;
            cin >> n;
            if (n == -1) endFlag = 0;
            return *this;
        }

        operator bool() {
            return endFlag;
        }

};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}