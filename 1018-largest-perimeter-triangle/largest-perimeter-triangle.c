#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}

int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = numsSize - 1; i >= 2; i--) {
        int a = nums[i - 2];
        int b = nums[i - 1];
        int c = nums[i];

        if (a + b > c) {
            return a + b + c;
        }
    }

    return 0;
}