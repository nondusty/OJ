/*未实现   Dijkstra求最短路 II（堆优化Dijkstra算法 时间复杂度 O(m logn)*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 150010
#define inf 0x3f3f3f3f
typedef struct node{
    int fir;
    int sec;
}PII;
int n, m;                           // 输入参数  →  全局变量
int h[N], w[N], e[N], ne[N], idx;   // head  →  起点链表, weight  →  边权重, e  →  终点链表, next  →  结点链表
int dist[N];                        // 最短距离  →  初始化 INF
int st[N];                          // 是否访问
PII heap[N];                        // 并非堆结构  仅是队列
int hh = 0, tt = -1, ss = 0;        // heap, tail, size

void add(int a,int b,int c){
    e[idx] = b;                     // idx  edge    指向    汇点b
    w[idx] = c;                     // idx  weight  指向    权重w
    ne[idx] = h[a];                 // idx  next    指向    旧头结点 head
    h[a] = idx;                     // a    head    指向    新头结点 idx
    idx++;                          // idx          更新    新结点
}

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;                                                    // 起始点  距离记0
    tt += 1, heap[tt].fir = 0, heap[tt].sec = 1, ss += 1;           // 起始点  入队
    while (ss){
        PII t = heap[hh++];                                         // 提取队首结点, head++
        ss -= 1;                                                    // 提取队首结点, size--

        int ver = t.sec, distance = t.fir;
        if (st[ver]) continue;                                      // 汇点  访问过  →  continue
        st[ver] = 1;                                                // 汇点  未访问  →  标记
        
        for (int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]){
                dist[j] = dist[ver] + w[i];
                heap[tt].fir = dist[j];
                heap[tt].sec = j;
                tt += 1;
                ss += 1;
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
int main(){
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof h);
    while(m --){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
    }
    printf("%d\n", dijkstra());
}
/**
 * 给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为非负值。
请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

输入格式
第一行包含整数 n 和 m。
接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。
如果路径不存在，则输出 −1。

数据范围
1≤n,m≤1.5×10^5,
图中涉及边长均不小于 0，且不超过 10000。
数据保证：如果最短路存在，则最短路的长度不超过 10^9。

输入样例：
3 3
1 2 2
2 3 1
1 3 4

输出样例：
3
*/