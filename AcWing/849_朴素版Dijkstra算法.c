/*Dijkstra求最短路 I（朴素版Dijkstra算法 时间复杂度 O(n ^ 2)*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 510
#define inf 0x3f3f3f3f
int n, m;
int g[N][N];            // 存储稠密图,用邻接矩阵
int dist[N];            // 表示起点到每一个点当前距离是多少
int st[N];              // 用于在更新最短距离时 判断当前的点的最短距离是否确定 是否需要更新

int min(int a, int b){
    return a < b ? a : b;
}

int dijkstra() {
    memset(dist, inf, sizeof dist);     // 初始化距离  0x3f 代表无限大
    dist[1] = 0;                        // 第一个点到自身的距离为 0
    /*
        t 存储当前迭代目标结点
        遍历所有结点  →  [1, n]
        选取边距离最小节点加入, 并将该结点标记为已访问
    */
    for(int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            // t == -1 → 初始情况
            // dist[j] < dist[t]  →  更新短边
            if(st[j] == 0 && (t == -1 || dist[j] < dist[t]))
                t = j;                  //将t更新为j
        }
        st[t] = 1;                      // 标记该点已访问

        /*
            添加结点t, 并更新边距离信息
            j [1, n]  dist(j) = min(j, min(t) + g[t][j])
            到结点 j 距离 → min(未加入t结点时距离, 到t结点距离 + t → j距离)
        */
        for(int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    //如果第n个点路径为无穷大即不存在最低路径
    if(dist[n] == inf)
        return -1;
    return dist[n];
}
int main()
{
    scanf("%d %d", &n, &m);
    memset(g, inf, sizeof g);                // 初始化结点边为最大值
    
    while (m--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x][y] = min(g[x][y], z);          // 出现重边 → 保留短边
    }
    printf("%d\n", dijkstra());
}

/**
 * 题目描述
给定一个n个点m条边的有向图，图中可能存在重边和自环，所有边权均为正值。请你求出1号点到n号点的最短距离，如果无法从1号点走到n号点，则输出-1

输入格式
第一行包含整数n和m。
接下来 m 行每行包含三个整数 a,y,z，表示存在一条从点  到点y 的有向边，边长为2

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离
如果路径不存在，则输出 -1。

数据范围
1 < n < 500.1 < m < 105
图中涉及边长均不超过10000。

输入样例:
3 3
1 2 2
2 3 1
1 3 4

输出样例：
3
*/