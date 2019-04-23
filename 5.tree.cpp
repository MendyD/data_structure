/*************************************************************************
	> File Name: 5.tree.cpp
	> Author: Mendy
	> Mail: dolai_c@163.com
	> Course: 
	> Created Time: 六  4/20 12:18:41 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} Node;


Node *init(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = node->rchild = NULL;
    return node;
}
/*先序遍历*/
void preorder(Node *root){
    printf("%d ", root->data);
    if(root->lchild){
        preorder(root->lchild);
    }
    if(root->rchild){
        preorder(root->rchild);
    }
}
/*中序遍历*/
void inorder(Node *root){
    if(root->lchild){
        inorder(root->lchild);
    }
    printf("%d ", root->data);
    if(root->rchild){
        inorder(root->rchild);
    }
}
/*后序遍历*/
void postorder(Node *root){
    if(root->lchild){
        postorder(root->lchild);
    }
    if(root->rchild){
        postorder(root->rchild);
    }
    printf("%d ", root->data);
}
/*已知先序遍历中序遍历，构造二叉树*/
Node *BuildPostorderTree(char PreOrderStr[], char InOrderStr[], int len){
    Node *p = init(PreOrderStr[0] - '0');
    int pos = strchr(InOrderStr, PreOrderStr[0]) - InOrderStr;
    if(pos > 0){
        p->lchild = BuildPostorderTree(PreOrderStr + 1, InOrderStr, pos);
    }
    if(pos + 1 < len){
        p->rchild = BuildPostorderTree(PreOrderStr + pos + 1, InOrderStr + pos + 1, len - pos - 1);
    }
    return p;

}
/*已知中序遍历后序遍历，构造二叉树*/
Node *BuildPreorderTree(char PostOrderStr[], char InOrderStr[], int len){
    Node *p = init(PostOrderStr[len - 1] - '0');
    int pos = strchr(InOrderStr, PostOrderStr[len - 1]) - InOrderStr;
    if(pos > 0){
        p->lchild = BuildPreorderTree(PostOrderStr, InOrderStr, pos);
    }
    if(pos + 1 < len){
        p->rchild = BuildPreorderTree(PostOrderStr + pos, InOrderStr + pos + 1, len - pos - 1);
    }
    return p;
}


void clear(Node *node){
    if(node->lchild){
        clear(node->lchild);
    }
    if(node->rchild){
        clear(node->rchild);
    }
    free(node);
}


int main(){
    Node *node = init(1);
    node->lchild = init(2);
    node->rchild = init(3);
    preorder(node);
    printf("\n");
    inorder(node);
    printf("\n");
    postorder(node);
    printf("\n");
    clear(node);
    char pre[] = "136945827";
    char in[] = "963548127";
    char post[] = "965843721";
    
    node = BuildPostorderTree(pre, in, strlen(pre));
    postorder(node);
    printf("\n");
    node = BuildPreorderTree(post, in, strlen(post));
    preorder(node);
    printf("\n");
    return 0;

}
