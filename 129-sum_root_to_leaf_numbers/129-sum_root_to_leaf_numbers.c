#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "timing.h"
#include "tree.h"


extern float timeuse_count(struct timeval start, struct timeval end);

int iter(struct TreeNode *root, int val) 
{
    int total = 0;
    int sum = 0;

    sum = (val * 10) + root->val;

    if(root->left == NULL && root->right == NULL){
        return sum;
    }
    if(root->left != NULL){
        total += iter(root->left, sum);
    }
    if(root->right != NULL){
        total += iter(root->right, sum);
    }

    return total;
}

int sumNumbers(struct TreeNode* root) 
{
    if(root == NULL){
        return 0;
    }

    return iter(root, 0);
}

int main() 
{
    struct timeval start, end;
    char *input[] = {"1","2","3",NULL,"4","5","7"};
    int input_num = 7;
    struct TreeNode **root = NULL;
    int result;

    root = (struct TreeNode **)calloc(input_num, sizeof(struct TreeNode *));
    if(!tree_create(root, input, input_num)){
        printf("create tree fail\n");
        return 0;
    }

    gettimeofday(&start, NULL);
    //run the target function here
    result = sumNumbers(root[0]);
    gettimeofday(&end, NULL);
    printf("result = %d\n", result);
    printf("total time = %f seconds\n", timeuse_count(start, end));

    tree_destroy(root, input_num);
    free(root);

    return 0;
}
