/** SPFA 判断负环*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2010
#define M 10010
int n, m;
int h[N], w[M], e[M], ne[M], idx;
int dist[N], cnt[N], st[N];
int q[N];
int hh = 0, tt = 0;

void add(int a, int b, int c)
{
    e[idx] = b;     // idx  edge    指向    汇点b
    w[idx] = c;     // idx  weight  指向    权重w
    ne[idx] = h[a]; // idx  next    指向    旧头结点 head
    h[a] = idx;     // a    head    指向    新头结点 idx
    idx++;          // idx          更新    新结点
}

int spfa()
{
    for (int i = 1; i <= n; i++)
    {
        st[i] = 1;
        q[tt++] = i;
    }
    while (hh != tt)
    {
        int t = q[hh++];
        st[t] = 0;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n)
                    return 1;
                if (st[j] == 0)
                {
                    q[tt++] = j;
                    st[j] = 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
    }

    if (spfa())
        puts("Yes");
    else
        puts("No");
    return 0;
}
/**
 * 题目描述
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。
请你判断图中是否存在负权回路。

输入格式
第一行包含整数 n 和 m。
接下来 m 行每行包含三个整数 x,y,z,表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
如果图中存在负权回路，则输出 Yes，否则输出 No。

数据范围
1≤n≤2000,
1≤m≤10000,
图中涉及边长绝对值均不超过 10000。

输入样例：
3 3
1 2 -1
2 3 4
3 1 -4

输出样例：
Yes
*/