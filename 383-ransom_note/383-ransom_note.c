#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "timing.h"


extern float timeuse_count(struct timeval start, struct timeval end);

bool canConstruct(char* ransomNote, char* magazine) {
    int total[26] = { 0 };
    int m_len = strlen(magazine);
    int r_len = strlen(ransomNote);
    if(r_len > m_len){
        return false;
    }
    for(int i=0;i<r_len;i++){
        total[magazine[i]-'a']++;
        total[ransomNote[i]-'a']--;
    }
    for(int i=r_len;i<m_len;i++){
        total[magazine[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(total[i] < 0){
            return false;
        }
    }
 
    return true;
}
int main() 
{
    struct timeval start, end;

    gettimeofday(&start, NULL);
    //run the target function here
    char * ransomNote = "aa";
    char * magazine = "aab";
	bool ret = canConstruct(ransomNote, magazine); 
    printf("%s\n", ret ? "true" : "false");
    gettimeofday(&end, NULL);
    printf("total time = %f seconds\n", timeuse_count(start, end));

    return 0;
}
