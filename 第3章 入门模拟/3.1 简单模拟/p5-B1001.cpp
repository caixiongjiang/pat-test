//
// Created by Jarson's mac on 2021/12/22.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    //在此输入你的代码
    int n, step = 0;
    cin >> n;
    while(n != 1)
    {
        if(n % 2 == 0) n = n / 2;
        else n = (3 * n + 1) / 2;
        step++;
    }
    cout << step << endl;
    return 0;
}
