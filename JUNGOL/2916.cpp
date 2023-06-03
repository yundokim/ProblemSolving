#include <stdio.h>
#include <set>
#define MAX_N 100005

int N;
int p[MAX_N] = {-1};
int co[MAX_N];
std::set<int> coco;

int depth(int n, int r, int i)
{
    if (i >= 1000)
        return n;
    if (n == 0)
        return 0;
    return depth(p[n], r, i + 1) + 1;
}

void paint(int a, int b, int c)
{
    int r;
    int d_a = depth(a, 0, 0);
    if (d_a >= 1000)
    {
        r = d_a - 1000;
    }

    d_a = depth(a, r, 0);
    int d_b = depth(b, r, 0);

    while (d_a > d_b)
    {
        co[a] = c;
        a = p[a];
        d_a--;
    }

    while (d_a < d_b)
    {
        co[b] = c;
        b = p[b];
        d_b--;
    }

    while (a != b)
    {
        co[a] = c;
        co[b] = c;
        a = p[a];
        b = p[b];
    }
}

void move(int a, int b)
{
    p[a] = b;
}

void count(int a, int b)
{
    int r;
    int d_a = depth(a, 0, 0);
    if (d_a >= 1000)
    {
        r = d_a - 1000;
    }

    d_a = depth(a, r, 0);
    int d_b = depth(b, r, 0);

    while (d_a > d_b)
    {
        coco.insert(co[a]);
        a = p[a];
        d_a--;
    }

    while (d_a < d_b)
    {
        coco.insert(co[b]);
        b = p[b];
        d_b--;
    }

    while (a != b)
    {
        coco.insert(co[a]);
        coco.insert(co[b]);
        a = p[a];
        b = p[b];
    }
}

int main()
{
    int K;

    scanf("%d %d", &N, &K);

    for (int t_i = 0; t_i < K; t_i++)
    {
        int r;
        int a, b, c;

        scanf("%d", &r);

        if (r == 1)
        {
            scanf("%d %d %d", &a, &b, &c);
            paint(a, b, c);
        }
        else if (r == 2)
        {
            scanf("%d %d", &a, &b);
            move(a, b);
        }
        else
        {
            scanf("%d %d", &a, &b);
            coco.clear();
            count(a, b);
            printf("%lu\n", coco.size());
        }
    }

    return 0;
}
