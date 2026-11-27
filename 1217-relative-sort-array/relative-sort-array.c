#include <stdlib.h>

int* relativeSortArray(int* arr1, int arr1Size,
                       int* arr2, int arr2Size,
                       int* returnSize) {

    int freq[1001] = {0};

    int* result = (int*)malloc(arr1Size * sizeof(int));
    int k = 0;

    // Count frequency of each element
    for (int i = 0; i < arr1Size; i++) {
        freq[arr1[i]]++;
    }

    // Add elements in arr2 order
    for (int i = 0; i < arr2Size; i++) {
        int num = arr2[i];

        while (freq[num] > 0) {
            result[k++] = num;
            freq[num]--;
        }
    }

    // Add remaining elements in ascending order
    for (int i = 0; i <= 1000; i++) {
        while (freq[i] > 0) {
            result[k++] = i;
            freq[i]--;
        }
    }

    *returnSize = k;

    return result;
}