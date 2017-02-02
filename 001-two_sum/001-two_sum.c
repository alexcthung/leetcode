#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "timing.h"


extern float timeuse_count(struct timeval start, struct timeval end);

int* twoSum(int* nums, int numsSize, int target) {
    int *ret;
    int i,j;

    ret = (int *)malloc(sizeof(int) * 2);

    for(i=0;i<numsSize;i++) {
        for(j=i+1;j<numsSize;j++){
            if(nums[i] + nums[j] == target){
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }

    return NULL;
}

int main() 
{
    struct timeval start, end;
    int nums[] = {3, 2, 4};
    int numSize = 3;
    int target = 6;
    int *result;

    gettimeofday(&start, NULL);
    result = twoSum(nums, numSize, target);
    gettimeofday(&end, NULL);

    printf("result = [%d, %d]\n", result[0], result[1]);
    printf("total time = %f seconds\n", timeuse_count(start, end));

    return 0;
}
