#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "timing.h"


extern float timeuse_count(struct timeval start, struct timeval end);

char result[100];
char *fractionAddition(char * expression)
{
    int sum[10] = {0};
    int num = 0, deno = 0;
    int sign = 1;
    size_t i = 0;
    while(expression[i] != '\0'){
        if(expression[i] == '+'){
            i++;
            sign = 1;
        }
        else if(expression[i] == '-'){
            i++;
            sign = -1;
        }
        num = atoi(&expression[i]);
        while(expression[i] != '/'){
            i++;
        }
        deno = atoi(&expression[++i]);
        while(expression[i]>='0' && expression[i]<='9'){
            i++;
        }
        sum[deno-1] += num * sign;
        num = 0;
        deno = 0;
    };
    num = 0;
    deno = 1;
    for(int i=0;i<10;i++){
		printf("sum[%d]= %d\n", i, sum[i]);
        if(sum[i] != 0){
            num = num*(i+1) + deno*sum[i];
            deno *= (i+1);
        }
    }
    printf("result: %d/%d\n", num, deno);
    if(num == 0){
        return "0/1";
    }
    int a, b;
    sign = 1;
    if(num < 0){
        sign = -1;
        num *= sign;
    }
    if(num > deno){
        a = num;
        b = deno;
    }
    else{
        a = deno;
        b = num;
    }
    while(1){
        if(a % b == 0){
            break;
        }
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    num /= b*sign;
    deno /= b;

    sprintf(result, "%d/%d", num, deno);
    return result;
}

int main()
{
    struct timeval start, end;

    char *expr = "7/3+5/2-3/10";

    gettimeofday(&start, NULL);
    //run the target function here
    printf("%s\n", fractionAddition(expr));
    gettimeofday(&end, NULL);
    printf("total time = %f seconds\n", timeuse_count(start, end));

    return 0;
}
