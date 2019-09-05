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

int countNodes(struct TreeNode* root){
    if(!root) return 0;
    return (countNodes(root->left)+countNodes(root->right)+1);
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
