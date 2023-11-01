#include <stdio.h>
#include <stdlib.h>

int readLen(int* len) {
    float k;
    if (scanf("%f", &k) == 1 && k == (float)((int)k)) {
        *len = (int)k;
    } else {
        return 0;
    }
    return 1;
}

int readArr(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 0;
        }
    }
    if (getchar() != '\n') {
        return 0;
    }
    return 1;
}

void bubbleSort(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArr(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        if (i == len - 1) {
            printf("%d", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }
}

int main() {
    int *arr, length;
    if (readLen(&length)) {
        arr = (int*)malloc(length * sizeof(int));
    }
    if (readArr(arr, length)) {
        bubbleSort(arr, length);
        printArr(arr, length);
        free(arr);
    } else {
        printf("n/a");
    }
    return 0;
}
