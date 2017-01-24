#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "timing.h"

//#define overflow

extern float timeuse_count(struct timeval start, struct timeval end);

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;

    return;
}

int traverse(int *coins, int size, int amount, int cnt) {

    int quotient = amount / coins[size];
    

    if(cnt < quotient) {
        return 0;
    }
    if(cnt == quotient && (amount - cnt*coins[size]) == 0) {
        return 1;
    }
    if(size == 0) {
        return 0;
    }

    for(int i = quotient; i >= 0; i--) {
        if(traverse(coins, size - 1, amount - coins[size]*i, cnt - i)){
            return 1;
        }
    }

    return 0;
}

int coinChange(int* coins, int coinsSize, int amount) {

    if(coins == NULL) return -1;

    for(int i = 0; i < coinsSize; i++){
        for(int j = i + 1; j < coinsSize; j++){
            if(coins[i] > coins[j]) swap(&coins[i], &coins[j]);
        }
        if(coins[i] <= 0){
            return -1;
        }
    }

    for(int i = 0; i<coinsSize; i++){
        printf("sorted coins[%d] = %d\n", i, coins[i]);
    }

    int min = amount / coins[coinsSize - 1];
    int max = amount / coins[0];
#if 1
    for(int i = min; i <= max; i++) {
        int ret = traverse(coins, coinsSize - 1, amount, i);
        if(ret == 1){
            return i;
        }
    }
#endif
    return -1;
}

int main() 
{
#ifdef overflow
    int coins[] = {1,2147483647};
    int coinSize = 2;
    int amount = 2;
#else
    int coins[] = {233,408,101,448,235,339,40,211};
    int coinSize = 8;
    int amount = 7392;
#endif
    struct timeval start, end;

    gettimeofday(&start, NULL);
    printf("min ret = %d\n", coinChange(coins, coinSize, amount));
    gettimeofday(&end, NULL);
    printf("total time = %f seconds\n", timeuse_count(start, end));

    return 0;
}
