#include <stdio.h>
#include <stdlib.h>

// Node structure for a term in the polynomial
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial in decreasing order of exponents
void insertTerm(struct Node** poly, int coeff, int exp) {
    if (coeff == 0) return;

    struct Node* newNode = createNode(coeff, exp);

    // If list is empty or new term has higher exponent than head
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        struct Node* prev = NULL;

        // Traverse to correct position
        while (temp != NULL && temp->exp > exp) {
            prev = temp;
            temp = temp->next;
        }

        // If term with same exponent exists, add coefficients
        if (temp != NULL && temp->exp == exp) {
            temp->coeff += coeff;
            free(newNode);
            if (temp->coeff == 0) {
                // Remove term if coefficient becomes zero
                if (prev == NULL) {
                    *poly = temp->next;
                } else {
                    prev->next = temp->next;
                }
                free(temp);
            }
        } else {
            newNode->next = temp;
            if (prev != NULL)
                prev->next = newNode;
        }
    }
}

// Function to input a polynomial
void inputPolynomial(struct Node** poly, int numTerms, int polyNumber) {
    int coeff, exp;
    for (int i = 0; i < numTerms; i++) {
        printf("Enter coeff and exp for term %d in polynomial %d: ", i + 1, polyNumber);
        scanf("%d%d", &coeff, &exp);
        insertTerm(poly, coeff, exp);
    }
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }

    int first = 1;

    while (poly != NULL) {
        if (poly->coeff > 0 && !first)
            printf("+");

        if (poly->exp == 0)
            printf("%d", poly->coeff);
        else if (poly->coeff == 1)
            printf("x^%d", poly->exp);
        else if (poly->coeff == -1)
            printf("-x^%d", poly->exp);
        else
            printf("%dx^%d", poly->coeff, poly->exp);

        poly = poly->next;
        first = 0;
    }

    printf("\n");
}

// Main function
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;
    int t1, t2;

    printf("Enter number of terms in 1st polynomial: ");
    scanf("%d", &t1);
    inputPolynomial(&poly1, t1, 1);

    printf("Enter number of terms in 2nd polynomial: ");
    scanf("%d", &t2);
    inputPolynomial(&poly2, t2, 2);

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}
