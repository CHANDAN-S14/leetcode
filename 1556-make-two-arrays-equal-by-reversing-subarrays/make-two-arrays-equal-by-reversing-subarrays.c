#include <stdbool.h>

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {

    int freq[1001] = {0};

    // Count elements in target
    for (int i = 0; i < targetSize; i++) {
        freq[target[i]]++;
    }

    // Subtract elements in arr
    for (int i = 0; i < arrSize; i++) {
        freq[arr[i]]--;
    }

    // Check whether frequencies match
    for (int i = 1; i <= 1000; i++) {
        if (freq[i] != 0) {
            return false;
        }
    }

    return true;
}