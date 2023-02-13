#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100010
int n, m;
int h[N], e[N], ne[N], idx;//邻接矩阵存储图
int d[N]; //保存各个点的入度
int q[N]; //保存入度为0，也就是能够输出的点
void add(int a, int b){ 
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
int topsort(){
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++ )
        if (d[i] == 0)
            q[ ++ tt] = i; //找到入度为0的点，即为起点
    while (hh <= tt){
        int t = q[hh ++ ];
        for (int i = h[t]; i != -1; i = ne[i]){//如果下一个节点非空， 那么就指向下一个节点
            int j = e[i];
            // 去掉改变度为0  → 加入队列
            if (-- d[j] == 0)
                q[ ++ tt] = j;
        }
    }
    return tt == n - 1;
}
int main(){
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof(int) * N);//初始化h数组 -1表示尾节点
    for (int i = 0; i < m; i ++ ){
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
        d[b] ++ ;
    }
    if (!topsort())
        puts("-1");
    else
        for (int i = 0; i < n; i ++ )
            printf("%d ", q[i]);
}
/**
 * 题目描述
给定一个 n 个点 m 条边的有向图，点的编号是 1 到 n，图中可能存在重边和自环。
请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 −1。
若一个由图中所有点构成的序列 A 满足：对于图中的每条边 (x,y)，x 在 A 中都出现在 y 之前，则称 A 是该图的一个拓扑序列。

输入格式
第一行包含两个整数 n 和 m。
接下来 m 行，每行包含两个整数 x 和 y，表示存在一条从点 x 到点 y 的有向边 (x,y)。

输出格式
共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。
否则输出 −1。

数据范围
1 ≤ n,m ≤ 10^5

输入样例：
3 3
1 2
2 3
1 3

输出样例：
1 2 3
*/