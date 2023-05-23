// 05/23/2023

#include <cstdio>

void p(int n) {
    if (n < 10) printf("%d", n);
    else printf("%c", n - 10 + 'A');
}

void c(int n, int k) {
    if (n <= 0) return;
    c(n / k, k);
    p(n % k);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    c(n, k);

    return 0;
}