/*************************************************************************
	> File Name: myrandom.cpp
	> Author: Mendy
	> Mail: dolai_c@163.com
	> Course: 
	> Created Time: 四  4/11 20:51:16 2019
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
static int seed = 1;
void my_srand(int s){
    int seed = ((s * s * s) % 100 + 100 ) % 100 + 1;
}

int my_random(){
    seed = (seed * 3) % 101;
    return seed;
}

int main(){
    int b = rand(), length = 0;
    while(b != rand()) length++;
    printf("%d\n", length);
}

