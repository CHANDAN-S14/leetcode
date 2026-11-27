#include <string.h>
#include <stdbool.h>

char* removeDuplicateLetters(char* s) {
    int count[26] = {0};
    bool visited[26] = {false};

    int len = strlen(s);
    char stack[10005];
    int top = -1;

    // Count frequency of each character
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    // Process each character
    for (int i = 0; i < len; i++) {
        char ch = s[i];
        int index = ch - 'a';

        count[index]--;

        if (visited[index]) {
            continue;
        }

        // Remove larger characters if they appear again later
        while (top >= 0 &&
               stack[top] > ch &&
               count[stack[top] - 'a'] > 0) {

            visited[stack[top] - 'a'] = false;
            top--;
        }

        stack[++top] = ch;
        visited[index] = true;
    }

    stack[top + 1] = '\0';

    return strdup(stack);
}