/*************************************************************************
	> File Name: 4.stack.cpp
	> Author: Mendy
	> Mail: dolai_c@163.com
	> Course: 
	> Created Time: 日  4/14 14:07:40 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Stack{
    int *data;
    int top, length;
}Stack;

Stack *init(int n){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    s->length = n;
    return s;
}

int empty(Stack *s){
    return s->top == -1;
}

int top(Stack *s){
    if(empty(s)) return 0;
    return s->data[s->top];
}

void push(Stack *s, int val){
    if(s->top == s->length -1) return ;
    s->top += 1;
    s->data[s->top] = val;
    return ;
}

void pop(Stack *s){
    if(empty(s)) return ;
    s->top -= 1;
    return ;
}

void clear(Stack *s){
    if(s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

void output(Stack *s){
    printf("stack = [");
    for(int i = s->top; i >= 0; i--){
        printf(" %d", s->data[i]);
    }
    printf(" ]\n");
    return ;
}

int func(int n){
    int sum;
    if(n == 0) sum = 1;
    for(int i = 1; i <= n; i++){
        sum += func(i - 1) * func(n - i);
    }
    return sum;
}

int main(){
    #define MAX_OP 20
    srand(time(0));
    Stack *s = init(MAX_OP);
    for(int i = 0; i < MAX_OP; i++){
        int op = rand() % 4, val = rand() % 100;
        switch(op){
            case 0:
            case 1:
            case 2:{
                printf("push %d to stack\n", val);
                push(s, val);
            } break;
            case 3:{
                printf("pop %d from stack\n", top(s));
                pop(s);
            } break;
        }
        output(s);
    }
    int n;
    scanf("%d", &n);
    printf("%d\n", func(n));
    return 0;
}
