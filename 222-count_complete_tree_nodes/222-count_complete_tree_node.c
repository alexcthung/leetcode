#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "timing.h"


extern float timeuse_count(struct timeval start, struct timeval end);

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countLen(struct TreeNode* root)
{
    if(!root)
        return 0;
    if(root->left){
        return 1 + countLen(root->left);
    }
    return 1;
}

int countNodes(struct TreeNode* root){
    int n = 0;
    if(!root)
        return n;
    else
        n++;
    struct TreeNode *cur = root;
    while(1){
        int left = countLen(cur->left);
        int right = countLen(cur->right);
        if(left==0 && right==0)
            return n;
        if(left > right){
            n = 2 * n;
            cur = cur->left;
            continue;
        }
        else{
            n = 2 * n + 1;
            cur = cur->right;
            continue;
        }
    }
}

int main()
{
    struct timeval start, end;

    gettimeofday(&start, NULL);
    //run the target function here
    gettimeofday(&end, NULL);
    printf("total time = %f seconds\n", timeuse_count(start, end));

    return 0;
}
