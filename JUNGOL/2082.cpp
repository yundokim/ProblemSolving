#include <cstdio>
#define MAXN 500010

int N;
int mh[MAXN];
int t = 0;

void push_heap(int n)
{
    int i;

    mh[++t] = n;

    i = t;

    while (i > 1 && mh[i] > mh[i / 2])
    {
        int tmp = mh[i];
        mh[i] = mh[i / 2];
        mh[i / 2] = tmp;
        i = i / 2;
    }
}

void pop_heap()
{
    int i;

    int tmp = mh[1];
    mh[1] = mh[t];
    mh[t] = tmp;

    t--;
    i = 1;

    while (2 * i <= t)
    {
        int c = i * 2;

        if (c + 1 <= t && mh[c + 1] > mh[c])
            c++;
        if (mh[i] > mh[c])
            break;

        tmp = mh[i];
        mh[i] = mh[c];
        mh[c] = tmp;

        i = c;
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int n;

        scanf("%d", &n);

        push_heap(n);
    }

    for (int i = 1; i <= N; i++)
    {
        printf("%d ", mh[i]);
    }
    printf("\n");

    for (int j = 1; j <= N; j++)
    {
        pop_heap();
    }
    for (int i = 1; i <= N; i++)
    {
        printf("%d ", mh[i]);
    }
    printf("\n");

    return 0;
}
