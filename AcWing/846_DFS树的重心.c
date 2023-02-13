#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10010      //数据范围是10的5次方
#define M 20020      //以有向图的格式存储无向图，所以每个节点至多对应2n-2条边
int h[N];            //存储头节点
int e[M], ne[M];     //存储元素值、及对应next值
int idx;             //单链表索引
int n;               //题目所给的输入，n个节点
int ans = N;         //表示重心的所有的子树中，最大的子树的结点数目
int st[N];           //记录节点是否被访问过，访问过则标记为true

int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
//返回以u为根的子树中节点的个数，包括u节点
int dfs(int u) {
    int res = 0;                     //删掉某个节点之后，最大的连通子图节点数
    st[u] = 1;                      //标记访问过u节点
    int sum = 1;                    //存储 以u为根的树 的节点数

    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (st[j] == 0) {
            int s = dfs(j);         // 以j为根的树     结点数量
            res = max(res, s);      // 记录 最大子树   结点数量
            sum += s;               // 以u为根的树     结点数量
        }
    }

    res = max(res, n - sum);    // res = max(所有子树 sum)
    ans = min(res, ans);        // ans = min(所有 res)
    return sum;
}
int main() {
    memset(h, -1, sizeof(int) * N);     //初始化h数组 -1表示空
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b), add(b, a);           //无向图
    }
    dfs(1);                             //可以任意选定一个节点开始 u<=n
    printf("%d\n", ans);
}
/**
 * 题目描述
给定一颗树，树中包含 n 个结点（编号 1∼n）和 n−1 条无向边。
请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。
重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

输入格式
第一行包含整数 n，表示树的结点数。
接下来 n−1 行，每行包含两个整数 a 和 b，表示点 a 和点 b 之间存在一条边。

输出格式
输出一个整数 m，表示将重心删除后，剩余各个连通块中点数的最大值。

数据范围
1 ≤ n ≤ 10^5

输入样例
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6

输出样例：
4
*/