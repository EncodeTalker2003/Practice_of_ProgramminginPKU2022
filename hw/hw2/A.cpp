#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
    private:
        char name[30];
        int age, id, g[4];
        double ave;

    public:
        void input() {
            cin.get(name, 21, ',');
            scanf(",%d,%d,%d,%d,%d,%d", &age, &id, &g[0], &g[1], &g[2], &g[3]);
        }

        void calculate() {
            ave = 0;
            for (int i = 0; i < 4; i++) ave += g[i];
            ave = 1.0 * ave / 4;
        }

        void output() {
            bool ok = 0; int aveInt = ave;
            printf("%s,%d,%d,", name, age, id);
            if ((ave-aveInt < 1e-7) && (ave - aveInt > -1e-7)) {
                printf("%d", aveInt);
            }
            else {
                printf("%.1lf", ave);
            }
        }

};

int main() {
    Student student;        // 定义类的对象
    student.input();        // 输入数据
    student.calculate();    // 计算平均成绩
    student.output();       // 输出数据
}