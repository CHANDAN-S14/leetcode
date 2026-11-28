#include <stdlib.h>

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {

    if (numsSize == 0)
        return NULL;

    // Find maximum element
    int maxIndex = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
    }

    // Create root node
    struct TreeNode* root = malloc(sizeof(struct TreeNode));

    root->val = nums[maxIndex];

    // Construct left subtree
    root->left = constructMaximumBinaryTree(nums, maxIndex);

    // Construct right subtree
    root->right = constructMaximumBinaryTree(
        nums + maxIndex + 1,
        numsSize - maxIndex - 1
    );

    return root;
}