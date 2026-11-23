
#include <stdlib.h>
#include <stdbool.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int* result = malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));

    int count = 0;

    for (int i = 0; i < nums1Size; i++) {

        bool found = false;

        // Check whether element exists in nums2
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                found = true;
                break;
            }
        }

        // Avoid duplicates in result
        if (found) {
            bool duplicate = false;

            for (int k = 0; k < count; k++) {
                if (result[k] == nums1[i]) {
                    duplicate = true;
                    break;
                }
            }

            if (!duplicate) {
                result[count++] = nums1[i];
            }
        }
    }

    *returnSize = count;

    return result;
}
