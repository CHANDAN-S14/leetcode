#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int stack1[105];
    int stack2[105];
    int top1, top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = malloc(sizeof(MyQueue));

    obj->top1 = -1;
    obj->top2 = -1;

    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++obj->top1] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++obj->top2] =
                obj->stack1[obj->top1--];
        }
    }

    return obj->stack2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++obj->top2] =
                obj->stack1[obj->top1--];
        }
    }

    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}