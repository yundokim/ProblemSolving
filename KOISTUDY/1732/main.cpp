// 05/23/2023

#include <cstdio>

int a[105][105];
int n, m, cnt = 0;

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void push(int i, int j) {
    if (0 <= i && i < n && 0 <= j && j < m) a[i][j] = ++cnt;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n + m; i++) {
        for (int j = 0; j < n + m; j++) {
            push(n - i + j - 1, j);
        }
    }

    print();
    return 0;
}