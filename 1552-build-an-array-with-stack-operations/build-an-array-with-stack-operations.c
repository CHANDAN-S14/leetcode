#include <stdlib.h>
#include <string.h>

char** buildArray(int* target, int targetSize, int n, int* returnSize) {

    char** result = (char**)malloc(2 * n * sizeof(char*));

    int k = 0;
    int j = 0;

    for (int i = 1; i <= n && j < targetSize; i++) {

        result[k] = (char*)malloc(5 * sizeof(char));
        strcpy(result[k++], "Push");

        if (i == target[j]) {
            j++;
        }
        else {
            result[k] = (char*)malloc(4 * sizeof(char));
            strcpy(result[k++], "Pop");
        }
    }

    *returnSize = k;

    return result;
}