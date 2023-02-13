#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10010
int n, m;                         // 输入参数  →  全局变量
int h[N], d[N], e[N], ne[N], idx; // head  →  起点链表, d  →  距离, e  →  终点链表, next  →  结点链表
int q[N];

int hh = 1, tt = 0, ss = 0; // heap, tail, size
void add(int a, int b)
{
    e[idx] = b;     // idx  edge    指向    汇点b
    ne[idx] = h[a]; // idx  next    指向    旧头结点 head
    h[a] = idx;     // a    head    指向    新头结点 idx
    idx++;          // idx          更新    新结点
}

int bfs()
{
    tt += 1, q[tt] = 1, ss += 1;        // 数组模拟队列  入尾操作
    d[1] = 0;                           // 起始点 距离赋值 0

    while (ss)
    {
        int t;
        t = q[hh], hh += 1, ss -= 1;                     // 数组模拟队列  取头操作

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1)                              // 未遍历过
            {
                d[j] = d[t] + 1;                        // d[j] = d[t] + 1
                tt += 1, q[tt] = j, ss += 1;            // j加入队列
            }
        }
    }
    return d[n];
}

int bfs()
{
    int hh = 0, tt = 0;
    q[tt++] = 1;
    d[1] = 0;

    while (hh != tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q[tt++] = j;
            }
        }
    }
    return d[n];
}

int main()
{
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof(int) * N); // 初始化h数组 -1表示空
    memset(d, -1, sizeof(int) * N); // 初始化d数组 -1表示空
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
    }
    printf("%d\n", bfs());
}
/**
 * 题目描述
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环。
所有边的长度都是 1，点的编号为 1∼n。
请你求出 1 号点到 n 号点的最短距离，如果从 1 号点无法走到 n 号点，输出 −1。

输入格式
第一行包含两个整数 n 和 m。
接下来 m 行，每行包含两个整数 a 和 b，表示存在一条从 a 走到 b 的长度为 1 的边。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

数据范围
1 ≤ n,m ≤ 10^5

输入样例：
4 5
1 2
2 3
3 4
1 3
1 4

输出样例：
1
*/