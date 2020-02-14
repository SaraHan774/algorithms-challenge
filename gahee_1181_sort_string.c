//
// Created by sarah on 2/14/2020.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_WORD_COUNT 20000


int comparator(const void * a, const void * b){

    const char * ia = *(const char **)a;
    const char * ib = *(const char **)b;

    if(strlen(ia) == strlen(ib)){
        return strcmp(ia, ib);
    }
    return strlen(ia) - strlen(ib);
}

int main(){

    int n;

    scanf("%d", &n); //number of strings
    if(n > MAX_WORD_COUNT){
        perror("exceeded max num of words.");
        return 0;
    }

    char * arr[n]; //문자열의 배열을 가리키는 포인터

    for(int i = 0; i < n; i++){
        arr[i] = malloc(MAX_WORD_LEN * sizeof(char));
        scanf("%s", arr[i]);
    }

    //sort by length while keeping alphabetical order
    qsort((void *)arr, n, sizeof(arr[0]), comparator);


    int i, j;
    char * sortedArr[n];
    int idx = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < i; j++){
            if(strcmp(arr[i], arr[j]) == 0){
                break;
            }
        }
        if(i == j){
            sortedArr[idx++] = arr[i];
        }
    }

    for(i = 0; i < idx; i++){
        printf("%s\n", sortedArr[i]);
    }

}