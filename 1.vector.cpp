/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: Mendy
	> Mail: dolai_c@163.com
	> Course: 
	> Created Time: 二  4/ 9 19:03:12 2019
 ************************************************************************/

#include<stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct Vector{
    int *data;
    int size, length;
} Vector;

Vector *init(int n){
    Vector *p = (Vector *)malloc(sizeof(Vector));
    p->data = (int *)malloc(sizeof(int) * n);
    p->size = n;
    p->length= 0;
    return p;
}

int expand(Vector *v){
    int extra_size = v->size;
    int *p;
    while (extra_size){
        p = (int *)realloc(v->data, sizeof(int) * (v->size + extra_size));
        if(p) break;
        extra_size /= 2;
    }
    if(extra_size == 0) return 0;
    //v->data = (int *)realloc(v->data, sizeof(int) * v->size * 2);//首地址，字节大小。返回值为void *  注意realloc不成功 注意优化扩容大小
    v->data = p;
    v->size += extra_size;
    return 1;
}


int insert(Vector *v, int ind, int val){
    //if(v->length == v->size) return 0;//满了
    if(v->length == v->size){
        if(!expand(v)){
            return 0;
        }
    }
    if (ind < 0 || ind > v->length) return 0;
    for(int i = v->length - 1; i >= ind; i--){
        v->data[i + 1] = v->data[i];//循环后移
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

int erase(Vector *v, int ind){
    if(ind < 0 || ind >= v->length) return 0;
    for(int i = ind + 1; i < v->length; i++){
        v->data[i - 1] = v->data[i];//循环前移
    }
    v->length -= 1;
    return 1;
}

void clear(Vector *v){
    if(v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

void output(Vector *v){
    printf("array = [");
    for(int i = 0; i < v->length; i++){
        printf(" %d", v->data[i]);
    }
    printf("]\n");
    return ;
}

int main(){
    #define MAX_OP 20
    int op, ind, val;
    Vector *v = init(MAX_OP);
    for(int i = 0; i < MAX_OP; i++){
        op = rand() % 4;
        ind = rand() % (v->length + 3) - 1;
        val = rand() % 100;
        switch (op){
            case 0:
            case 1:
            case 2:{
                printf("insert %d to vector at %d = %d\n", val, ind, insert(v, ind, val));
                output(v);
            } break;
            case 3:{
                printf("erase element at %d from vector = %d\n", ind, erase(v, ind));
                output(v);
            } break;
            defalut: 
            fprintf(stderr, "wrong option %d", op);
            break;
        }
    }
    clear(v);
    return 0;
}
