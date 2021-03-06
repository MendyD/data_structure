/*************************************************************************
	> File Name: 3.queue.cpp
	> Author: Mendy
	> Mail: dolai_c@163.com
	> Course: 
	> Created Time: 六  4/13 20:40:23 2019
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
typedef struct Quque{
    int *data;
    int head, tail, length, count;
}Queue;

Queue* init(int n){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->length = n;
    q->count = 0;
    q->head = 0;
    q->tail = 0;
    return q;
}

/*查看队首元素*/
int front(Queue *q){
    return q->data[q->head];
}
/*队首判空*/
int empty(Queue *q){
    return q->count == 0;
}

void push(Queue *q, int val){
    if(q->count == q->length) return ;
    q->data[(q->tail)++] = val;
    if(q->tail >= q->length) q->tail -= q->length;
    q->count++;
    return ;
}

void pop(Queue *q){
    q->head += 1;
    if(q->head >= q->length) q->head -= q->length;
    q->count--;
    return ;
}


void clear(Queue *q){
    if(q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

void output(Queue *q){
    printf("[");
    for(int i = 0; i< q->count; i++){
        int ind = (q->head + i) % q->length;
        printf(" %d", q->data[ind]);
    }
    printf(" ]\n");
    return ;
}


int main(){
    srand(time(0));
    #define MAX_OP 20
    Queue *q = init(5);
    for(int i = 0; i < MAX_OP; i++){
        int op = rand() % 4, val = rand() % 2200;
        switch(op){
            case 0:
            case 1:
            case 2:{
                printf("insert %D to queue\n",val);
                push(q, val);
            }break;
            case 3:{
                printf("pop %d from queue\n", front(q));
                pop(q);
            } break;
        }
        output(q);
    }
    clear(q);
    return 0;
}
