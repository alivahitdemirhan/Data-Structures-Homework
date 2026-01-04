#include <stdio.h>

#define MAX 10

int main() {
    int matrix[4][4] = {
        {0, 0, 3, 0},
        {0, 5, 0, 0},
        {0, 0, 0, 7},
        {9, 0, 0, 0}
    };

    int sparse[MAX][3];
    int k = 1;

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(matrix[i][j] != 0){
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    sparse[0][0] = 4;
    sparse[0][1] = 4;
    sparse[0][2] = k-1;

    printf("Row Col Val\n");
    for(int i=0;i<k;i++){
        printf("%d   %d   %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}
