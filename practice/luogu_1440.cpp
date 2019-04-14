/*************************************************************************
	> File Name: luogu_1440.cpp
	> Author: Mendy
	> Mail: dolai_c@163.com
	> Course: 单调队列。数列中，一个数前m个中的最小值
	> Created Time: 日  4/14 16:23:22 2019
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX_N 2000000
int q[MAX_N + 5], head = 0, tail = 0;
int ind[MAX_N + 5] = {0};

int main(){
    int n, m, a;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        printf("%d\n", q[head]);
        scanf("%d", &a);
        while (tail - head && i - ind[head] >= m) head++;//窗口之外了出队
        while (tail - head && q[tail -1] > a) tail--;//队尾出队
        q[tail] = a;
        ind[tail] = i;
        tail++;
    }
    return 0;
}
