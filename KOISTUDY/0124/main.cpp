// 05/23/2023

#include <cstdio>
using namespace std;

int d_c(int y, int m) {
    int m_d[15] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m != 2) return m_d[m];

    if (y % 400 == 0) return 29;
    if (y % 100 == 0) return 28;
    if (y % 4 == 0) return 29;
    return 28;
}

void timePass(int y, int m, int d) {
    int _m = m;

    while (_m < m + 2) {
        d += 7;
        if (d_c(y + ((_m - 1) / 12), ((_m - 1) % 12) + 1) < d) {
            d -= d_c(y + ((_m - 1) / 12), ((_m - 1) % 12) + 1);
            _m++;
        }
    }

    y += _m / 12;
    m = _m % 12;

    printf("%d %d %d\n", y, m, d);
}

int main() {
    int y, m, d;

    scanf("%d %d %d", &y, &m, &d);

    timePass(y, m, d);

    return 0;
}