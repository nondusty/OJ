/*SPFA算法————负边权情况  时间复杂度  一般O(m) 最坏O(m * n)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 150010
#define inf 0x3f3f3f3f

int n, m;                         // 输入参数  →  全局变量
int h[N], w[N], e[N], ne[N], idx; // head  →  起点链表, weight  →  边权重, e  →  终点链表, next  →  结点链表
int dist[N];                      // 最短距离  →  初始化 INF
int st[N];                        // 是否访问
int q[N];
int hh = 1, tt = 0, ss = 0; // heap, tail, size

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
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0, st[1] = 1;                 // 起始点 距离赋值 0, 访问标记 1
    tt += 1, q[tt] = 1, ss += 1;            // 数组模拟队列  入尾操作 
    
    while (ss)
    {
        int t;
        t = q[hh], hh += 1, ss -= 1;                     // 数组模拟队列  取头操作  
        st[t] = 0;                                       // 当前点 访问标记 1
        for (int i = h[t]; i != -1; i = ne[i])           // 遍历  t结点  所有彼边
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])                // 距离较小  &&  未访问过  →  队列入尾
            {
                dist[j] = dist[t] + w[i];
                if (st[j] == 0)
                {
                    tt += 1, q[tt] = j, ss += 1;
                    st[j] = 1;
                }
            }
        }
    }
    return dist[n];
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
    int t = spfa();
    if (t == 0x3f3f3f3f)
        puts("impossible");
    else
        printf("%d\n", t);
}
/**
 * 题目描述
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。
请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 impossible。
数据保证不存在负权回路。

输入格式
第一行包含整数 n 和 m。
接下来 m 行每行包含三个整数 x,y,z,表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。
如果路径不存在，则输出 impossible。

数据范围
1≤n,m≤10^5,
图中涉及边长绝对值均不超过 1000010000。

输入样例：
3 3
1 2 5
2 3 -3
1 3 4

输出样例：
2
*/