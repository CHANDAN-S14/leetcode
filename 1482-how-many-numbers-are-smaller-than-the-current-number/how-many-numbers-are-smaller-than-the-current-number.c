#include <stdlib.h>

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {

    *returnSize = numsSize;

    int freq[101] = {0};

    int* result = malloc(numsSize * sizeof(int));

    // Count frequency
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    // Calculate prefix sum
    for (int i = 1; i <= 100; i++) {
        freq[i] += freq[i - 1];
    }

    // Find count of smaller numbers
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            result[i] = 0;
        } else {
            result[i] = freq[nums[i] - 1];
        }
    }

    return result;
}