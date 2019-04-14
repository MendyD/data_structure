/*************************************************************************
	> File Name: chafenshangshu.cpp
	> Author: Mendy
	> Mail: dolai_c@163.com
	> Course: 
	> Created Time: 六  4/13 18:33:00 2019
 ************************************************************************/

#include<stdio.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define MAX_N 1000000
#define MAX_M 500000
#define MAX_K 19
//树高
struct Edge {
    int to, next;
} g[MAX_M + 5];
int head[MAX_N + 5] = {0}, cnt = 0;//head存储的是g的下标           
int gas[MAX_N + 5][MAX_K + 5] = {0}, deep[MAX_N + 5] = {0};
int father[MAX_N + 5] = {0};
int val[MAX_N + 5] = {0};
//链式前向星
inline void add(int a, int b){
    g[++cnt].to = b;
    g[cnt].next = head[a];
    head[a] = cnt;
    return ;
}

//ind 当前节点
void dfs1(int fa, int ind){
    father[ind] = fa;
    //初始化
    for(int i = 1; i <= MAX_K; i++) {
        gas[ind][i] = gas[gas[ind][i - 1]][i - 1];
    }
    for(int i = head[ind]; i;i = g[i].next){
        if(g[i].to == fa) continue;
        int to = g[i].to;
        deep[to] = deep[ind] + 1;
        gas[to][0] = ind;//从to向上跳到ind
        dfs1(ind, to);
    }//遍历ind为边的所有边编号
    return ;
}

//lca
int lca(int x, int y){
    if(deep[x] < deep[y]) swap(x, y);//保持x深
    for(int i = MAX_K; i >= 0; i--) {
        if(deep[gas[x][i]] < deep[y]) continue;
        x = gas[x][i];
        //从x向上跳2^i次方
    }
    if(x == y) return x;//x就是最近祖先
    for(int i = MAX_K; i >= 0; i--){
        if(gas[x][i] == gas[y][i]) continue;
        x = gas[x][i], y = gas[y][i];
    }
    return gas[x][0];
}


int quary(int ind){
    int ans = 0;
    for(int i = head[ind]; i; i = g[i].next){
        if(g[i].to == father[ind]) continue;
        ans += quary(g[i].to);
    }
    ans += val[ind];
    return ans;
}
int main(){
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
        add(b, a);
    }
    deep[0] = -1;
    dfs1(0, s);
    for(int i = 0; i < m; i++){
        int a, b, c, d, temp;
        scanf("%d", &a);//
        switch (a){
            case 1: {
                //某个链加值
                scanf("%d %d %d", &b, &c, &d);
                val[b] += d;
                val[c] += d;
                temp = lca(b, c);
                val[temp] -= d;
                val[father[temp]] -= d;
            } break;
            case 2: {
                //查询某个值
                scanf("%d", &b);
                printf("%d", quary(b));
            } break;
        }
        for(int i = 1; i <= n; i++){
            printf("%d ", val[i]);
        }
        printf("\n");
    }
    return 0;
}
