/*************************************************************************
	> File Name: 2.LinkList.cpp
	> Author: Mendy
	> Mail: dolai_c@163.com
	> Course: 链表操作
	> Created Time: 二  4/ 9 20:55:06 2019
 ************************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
//结点结构定义
typedef struct LinkListNode{
    int data;
    struct LinkListNode *next;
} LinklistNode;
//链表结构定义
typedef struct LinkList{
    LinkListNode head;//虚拟头结点
    int length;
} LinkList;

LinkListNode *getNewNode(int val){
    LinkListNode *p = (LinkListNode *)malloc(sizeof(LinkListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkList *getNewList(){
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(LinkList *l, int ind, int val){
    if(ind < 0 || ind > l->length) return 0;
    LinkListNode *p = &(l->head), *new_node = getNewNode(val);
    while(ind--) p = p->next;
    new_node->next = p->next;
    p->next = new_node;
    l->length += 1;
    return 1;
}


void clear(LinkList *l){
    LinkListNode *p = l->head.next, *q;
    while(p){
        q = p;
        p = p->next;
        free(q);
    }
    free(l);
    return ;
}

void output(LinkList *l){
    printf("head -> ");
    LinkListNode *p = l->head.next;
    while(p){
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
    return ;
}

int search(LinkList *l, int val){
    int ind = 0;
    LinkListNode *p = l->head.next;
    while(p && p->data != val) p = p->next, ind +=1;
    if(ind == l->length) return -1;
    return ind;
}

/*void output_search(LinkList *l, int ind){
    printf("   ");
    for(int i = 0; i <= ind; i++){
        printf("     ");
    }
    printf("^\n");
}
*/

void output_search(LinkList *l, int ind){
    LinkListNode *p = l->head.next;
    char buff[100] = {0};
    strcpy(buff, "head");
    char temp[10] = {0};
    while(p && (ind + 1)){
        sprintf(temp, "%d", p->data);
        strcat(buff, temp);
        p = p->next;
        ind--;
        strcat(buff, " -> ");
   }
    int len = strlen(buff);
    for(int i = 1; i < len; i++){
        printf(" ");
    }
    printf("\033[32m^\033[0m\n");
    for(int i = 1; i < len; i++){
        printf(" ");
    }
    printf("\033[32m|\033[0m\n");
    return ;
}

int main(){
    LinkList *l = getNewList();
    int ind, val;
    printf("Insert function:\nPlease input the location and the number:");
    while(scanf("%d %d", &ind, &val) != EOF){
        //~scanf();//~按位取反
        printf("insert %d to LinkList at %d = %d\n", val, ind, insert(l, ind, val));
        output(l);
        ind = search(l, val);
        output_search(l, ind);
        printf("Please input the location and the number:");
    }
    return 0;
}
