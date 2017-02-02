#include <stdlib.h>
#include "tree.h"

struct TreeNode *treeNode_alloc(int val) {
    struct TreeNode *node = NULL;

    node = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
    if(node != NULL){
        node->val   = val;
        node->left  = NULL;
        node->right = NULL;
    }

    return node;
}

bool tree_create(struct TreeNode **root, char **num, int size){

    if(NULL == num[0]){
        return false;
    }
    if(NULL == root){
        return false;
    }

    root[0] = treeNode_alloc(atoi((const char *)num[0]));

    for(int i=0; i<(size+1)/2; i++){
        if(NULL == root[i]){
            continue;
        }
        //left child
        int left = (2*i)+1;
        if(NULL != num[left]){
            root[left] = treeNode_alloc(atoi((const char *)num[left]));
            root[i]->left = root[left];
        }else{
            root[i]->left = NULL;
        }
        //right child
        int right = (2*i)+2;
        if(NULL != num[right]){
            root[right] = treeNode_alloc(atoi((const char *)num[right]));
            root[i]->right = root[right];
        }else{
            root[i]->right = NULL;
        }
    }

    return true;
}

void tree_destroy(struct TreeNode **root, int size)
{
    if(NULL == root){
        return;
    }
    for(int i=0; i<size; i++){
        if(NULL != root[i]){
            free(root[i]);
        }
    }
}
