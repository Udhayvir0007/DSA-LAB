#include <stdio.h>

void sparse_matrix(int n, int m, int mat[n][m], int val) {
    int sp_mat[val][3];
    int sp_row = 0;  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] != 0) {
                sp_mat[sp_row][0] = i;
                sp_mat[sp_row][1] = j;
                sp_mat[sp_row][2] = mat[i][j];
                sp_row++;
            }
        }
    }

    
    for (int i = 0; i < val; i++) {
        printf("%d %d %d\n", sp_mat[i][0], sp_mat[i][1], sp_mat[i][2]);
    }
}

int main() {
    int mat[3][4] = {
        {0, 0, 3, 0},
        {0, 0, 0, 0},
        {0, 7, 0, 9}
    };

    int val = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            if (mat[i][j] != 0) val++;

    sparse_matrix(3, 4, mat, val);

    return 0;
}