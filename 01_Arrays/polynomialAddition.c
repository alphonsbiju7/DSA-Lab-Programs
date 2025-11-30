#include <stdio.h>

struct poly {
    int coeff;
    int exp;
} poly1[10], poly2[10], poly3[20];	

int main() {
    int i, j, k, t1, t2;

    printf("Enter number of terms in 1st polynomial: ");
    scanf("%d", &t1);
    printf("Enter number of terms in 2nd polynomial: ");
    scanf("%d", &t2);

    for (i = 0; i < t1; i++) {
        printf("Coeff and exp for term %d in 1st polynomial: ", i + 1);
        scanf("%d%d", &poly1[i].coeff, &poly1[i].exp);
    }

    for (i = 0; i < t2; i++) {
        printf("Coeff and exp for term %d in 2nd polynomial: ", i + 1);
        scanf("%d%d", &poly2[i].coeff, &poly2[i].exp);
    }

    i = j = k = 0;

    while (i < t1 && j < t2) {
        if (poly1[i].exp == poly2[j].exp) {
            poly3[k].coeff = poly1[i].coeff + poly2[j].coeff;
            poly3[k].exp = poly1[i].exp;
            i++; j++;
        } else if (poly1[i].exp > poly2[j].exp) {
            poly3[k] = poly1[i];
            i++;
        } else {
            poly3[k] = poly2[j];
            j++;
        }
        k++;
    }

    while (i < t1) poly3[k++] = poly1[i++];
    while (j < t2) poly3[k++] = poly2[j++];

    printf("\nResultant Polynomial:");

    printf("\nResultant Polynomial:\n");

    for (i = 0; i < k; i++) {
        printf("%d x^%d", poly3[i].coeff, poly3[i].exp);

        if (i < k - 1)   // add + between terms
            printf(" + ");
    }

    printf("\n");
    return 0;
}
