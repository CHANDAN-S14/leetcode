#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int count;
    int capacity;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = malloc(sizeof(MyCircularDeque));

    obj->arr = malloc(k * sizeof(int));
    obj->front = 0;
    obj->rear = -1;
    obj->count = 0;
    obj->capacity = k;

    return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->count == obj->capacity)
        return false;

    if (obj->count == 0) {
        obj->front = 0;
        obj->rear = 0;
    } else {
        obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    }

    obj->arr[obj->front] = value;
    obj->count++;

    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->count == obj->capacity)
        return false;

    if (obj->count == 0) {
        obj->front = 0;
        obj->rear = 0;
    } else {
        obj->rear = (obj->rear + 1) % obj->capacity;
    }

    obj->arr[obj->rear] = value;
    obj->count++;

    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->count == 0)
        return false;

    if (obj->count == 1) {
        obj->count = 0;
        obj->front = 0;
        obj->rear = -1;
    } else {
        obj->front = (obj->front + 1) % obj->capacity;
        obj->count--;
    }

    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->count == 0)
        return false;

    if (obj->count == 1) {
        obj->count = 0;
        obj->front = 0;
        obj->rear = -1;
    } else {
        obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
        obj->count--;
    }

    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->count == 0)
        return -1;

    return obj->arr[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->count == 0)
        return -1;

    return obj->arr[obj->rear];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->count == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->count == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}