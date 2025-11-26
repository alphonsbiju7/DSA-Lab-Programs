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

    int firstTerm = 1;
    for (i = 0; i < k; i++) {
        if (poly3[i].coeff == 0) continue;

     
        if (!firstTerm) {
            if (poly3[i].coeff > 0) printf("+");
            else printf("-");
        } else {
            if (poly3[i].coeff < 0) printf("-");
            firstTerm = 0;
        }

        int absCoeff = (poly3[i].coeff < 0) ? -poly3[i].coeff : poly3[i].coeff;

        if (absCoeff != 1 || poly3[i].exp == 0)
            printf("%d", absCoeff);

        if (poly3[i].exp != 0) {
            printf("x");
            if (poly3[i].exp != 1)
                printf("^%d", poly3[i].exp);
        }
    }

    printf("\n");
    return 0;
}
