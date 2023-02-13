/* BellmanFord算法  负权 + 自环 + 重边 + 限定K条边*/
#include <stdio.h.>
#include <string.h>
#include <stdlib.h>
#define N 510
#define M 10010

struct Edge
{
    int a, b, c;        // 源点, 汇点, 权值
} edges[M];
int n, m, k;            // 全局 输入变量
int dist[N];            // 距离 初始化最大值
int last[N];            // 存储备份  →  避免更新后 原数据丢失

int min(int a, int b)
{
    return a < b ? a : b;
}

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;                                                // 起始点 赋0
    for (int i = 0; i < k; i++)                                 // 要求至多 K条边 故遍历K次
    {
        memcpy(last, dist, sizeof dist);
        for (int j = 0; j < m; j++)
        {
            struct Edge e = edges[j];
            dist[e.b] = min(dist[e.b], last[e.a] + e.c);
        }
    }
}
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges[i].a = a;
        edges[i].b = b;
        edges[i].c = c; // 存边和权值
    }
    bellman_ford();
    if (dist[n] > 0x3f3f3f3f / 2)
        puts("impossible");
    else
        printf("%d\n", dist[n]);
}
/**
 * 题目描述
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。
请你求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法从 1 号点走到 n 号点，输出 impossible。
注意：图中可能 存在负权回路 。

输入格式
第一行包含三个整数 n,m,k。
接下来 m 行，每行包含三个整数 x,y,z,表示存在一条从点 x 到点 y 的有向边，边长为 z。
点的编号为 1∼n。

输出格式
输出一个整数，表示从 1 号点到 n 号点的最多经过 k 条边的最短距离。
如果不存在满足条件的路径，则输出 impossible。

数据范围
1≤n,k≤500,
1≤m≤10000,
1≤x,y≤n,
任意边长的绝对值不超过 10000。

输入样例：
3 3 1
1 2 1
2 3 1
1 3 3

输出样例：
3
*/