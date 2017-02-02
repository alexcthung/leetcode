#ifndef __TREE_H__
#define __TREE_H__

#include <stdbool.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *treeNode_alloc(int val); 
bool tree_create(struct TreeNode **root, char **num, int size);
void tree_destroy(struct TreeNode **root, int size);

#endif
