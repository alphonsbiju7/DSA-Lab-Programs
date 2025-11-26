#include <stdio.h>

int main() {
    int A[20][3], B[20][3], C[40][3];
    int m, n, i, j, k;

    printf("Enter number of rows and columns of matrices: ");
    scanf("%d %d", &m, &n);

    printf("\nEnter elements of Matrix A (%dx%d):\n", m, n);
    k = 1;
    A[0][0] = m;
    A[0][1] = n;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            if (val != 0) {
                A[k][0] = i;
                A[k][1] = j;
                A[k][2] = val;
                k++;
            }
        }
    }
    A[0][2] = k - 1;

    printf("\nEnter elements of Matrix B (%dx%d):\n", m, n);
    int t = 1;
    B[0][0] = m;
    B[0][1] = n;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            if (val != 0) {
                B[t][0] = i;
                B[t][1] = j;
                B[t][2] = val;
                t++;
            }
        }
    }
    B[0][2] = t - 1;

    printf("\nSparse Matrix A (Triplet form):\n");
    printf("Row\tCol\tVal\n");
    for (i = 0; i <= A[0][2]; i++)
        printf("%d\t%d\t%d\n", A[i][0], A[i][1], A[i][2]);

    printf("\nSparse Matrix B (Triplet form):\n");
    printf("Row\tCol\tVal\n");
    for (i = 0; i <= B[0][2]; i++)
        printf("%d\t%d\t%d\n", B[i][0], B[i][1], B[i][2]);

    i = j = k = 1;
    C[0][0] = m;
    C[0][1] = n;

    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
        else if (A[i][0] < B[j][0] ||
                (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
    }

    while (i <= A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }
    while (j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;

    printf("\nSum Matrix C (A + B in Triplet form):\n");
    printf("Row\tCol\tVal\n");
    for (i = 0; i <= C[0][2]; i++)
        printf("%d\t%d\t%d\n", C[i][0], C[i][1], C[i][2]);

    printf("\nTranspose of Sum Matrix (C^T):\n");
    printf("Row\tCol\tVal\n");
    for (i = 1; i <= C[0][2]; i++) {
        printf("%d\t%d\t%d\n", C[i][1], C[i][0], C[i][2]);
    }

    return 0;
}

