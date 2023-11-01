#include <stdio.h>
#include <stdlib.h>

#define LEN 100

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
    return 1;
}

int main() {
    int buffStatic[LEN][LEN];
    float chooseMenu, fcol;
    int row, col;
    if (scanf("%f", &chooseMenu) != 1 || chooseMenu != (float)((int)chooseMenu)) {
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
            printf("%d\n", 2);

            break;
        case 3:
            printf("%d\n", 3);

            break;
        case 4:
            printf("%d\n", 4);

            break;

        default:
            break;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", buffStatic[i][j]);
        }
        printf("\n");
    }
    return 0;
}