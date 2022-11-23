#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int nPr(int n, int r) {
    return factorial(n) / factorial(n - r);
}

int nCr(int n, int r) {
    return nPr(n, r) / factorial(r);
}

int main() {
    int n, r;
    printf("Enter n and r: ");
    scanf("%d %d", &n, &r);
    printf("nPr = %d and nCr = %d", nPr(n, r), nCr(n, r));
    return 0;
}

//write algorithm for above program:
//1. Start
//2. Declare variables n, r, nPr, nCr
//3. Read n and r
//4. nPr = n! / (n - r)!
//5. nCr = nPr / r!
//6. Print nPr and nCr
//7. Stop