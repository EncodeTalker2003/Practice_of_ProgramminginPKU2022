#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class IntegralImage{
// 在此处补充你的代码
    int H, W;
    int *sum;
    int row;
    public: 
    IntegralImage(int _H, int _W) {
        H = _H; W = _W;
        sum = new int[H * W];
        row = 0;
    }

    void operator ()(int *a) {
        if (row == 0) {
            sum[0] = a[0];
            for (int j = 1; j < W; j++) sum[j] = sum[j - 1] + a[j];
        } else {
            sum[row * W] = sum[(row - 1) * W] + a[0];
            for (int j = 1; j < W; j++) 
                sum[row * W + j] = sum[(row - 1) * W + j] + sum[row * W + j - 1] + a[j] - sum[(row - 1) * W + j - 1];
        }
        row++;
    }

    int* operator[] (int i) {
        return sum + i * W;
    }

};
int main(){
    int H, W;
    cin >> H >> W;
    int ** image = new int*[H];
    for(int i=0;i<H;++i){
        image[i]=new int[W];
    }
    for(int i=0;i<H;++i)
    for(int j=0;j<W;++j)
        cin >> image[i][j];
    IntegralImage it(H,W);
    for_each(image, image+H, it);
    //it.out();
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j)
            cout<<it[i][j]<<" ";
        cout<<endl;
    }
   
}