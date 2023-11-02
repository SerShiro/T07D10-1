#include <stdio.h>
#include <stdlib.h>

#define LEN 100

int inputStatic(int buff[LEN][LEN], int row, int col);
void outputStatic(int buff[LEN][LEN], int row, int col);
int inputDynamic1(int row, int col);
int inputDynamic2(int row, int col);
int inputDynamic3(int row, int col);
void output(int** buff, int row, int col);

int main() {
    int buffStatic[LEN][LEN];
    float chooseMenu, fcol;
    int row, col;
    printf(
        "Menu:\n1 - Static\n2 - Dynamic method 1\n3 - Dynamic method 2\n4 - Dynamic method 3\nEnter method "
        "for array: ");
    if (scanf("%f", &chooseMenu) != 1 || chooseMenu != (float)((int)chooseMenu)) {
        printf("n/a");
        return 0;
    }
    if (chooseMenu < 1 || chooseMenu > 4) {
        printf("n/a");
        return 0;
    }
    if (scanf("%d%f", &row, &fcol) != 2 || fcol != (float)((int)fcol)) {
        printf("n/a");
        return 0;
    }
    col = (int)fcol;
    switch ((int)chooseMenu) {
        case 1:
            if (!inputStatic(buffStatic, row, col)) {
                printf("n/a");
                return 0;
            }
            break;
        case 2:
            if (!inputDynamic1(row, col)) {
                printf("n/a");
                return 0;
            }
            break;
        case 3:
            if (!inputDynamic2(row, col)) {
                printf("n/a");
                return 0;
            }
            break;
        case 4:
            if (!inputDynamic3(row, col)) {
                printf("n/a");
                return 0;
            }
            break;

        default:
            printf("n/a");
            break;
    }

    return 0;
}

int inputStatic(int buff[LEN][LEN], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (scanf("%d", &buff[i][j]) != 1) {
                return 0;
            }
        }
    }
    if (getchar() != '\n') {
        return 0;
    }
    outputStatic(buff, row, col);
    return 1;
}

void outputStatic(int buff[LEN][LEN], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                printf("%d", buff[i][j]);
            } else {
                printf("%d ", buff[i][j]);
            }
        }
        if (i != row - 1) {
            printf("\n");
        }
    }
}

int inputDynamic1(int row, int col) {
    int** buff = malloc(row * col * sizeof(int) + row * sizeof(int*));
    int* ptr = (int*)(buff + row);
    for (int i = 0; i < row; i++) {
        buff[i] = ptr + col * i;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (scanf("%d", &buff[i][j]) != 1) {
                return 0;
            }
        }
    }
    if (getchar() != '\n') {
        return 0;
    }
    output(buff, row, col);
    free(buff);
    return 1;
}

int inputDynamic2(int row, int col) {
    int** buff = malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        buff[i] = malloc(col * sizeof(int));
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (scanf("%d", &buff[i][j]) != 1) {
                return 0;
            }
        }
    }
    if (getchar() != '\n') {
        return 0;
    }
    output(buff, row, col);
    for (int i = 0; i < row; i++) {
        free(buff[i]);
    }
    free(buff);
    return 1;
}

int inputDynamic3(int row, int col) {
    int** buff = malloc(row * sizeof(int*));
    int* ptr = malloc(row * col * sizeof(int));
    for (int i = 0; i < row; i++) {
        buff[i] = ptr + col * i;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (scanf("%d", &buff[i][j]) != 1) {
                return 0;
            }
        }
    }
    if (getchar() != '\n') {
        return 0;
    }
    output(buff, row, col);
    free(ptr);
    free(buff);
    return 1;
}

void output(int** buff, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                printf("%d", buff[i][j]);
            } else {
                printf("%d ", buff[i][j]);
            }
        }
        if (i != row - 1) {
            printf("\n");
        }
    }
}