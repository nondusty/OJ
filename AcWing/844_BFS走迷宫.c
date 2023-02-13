#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 110 
typedef struct node{
    int fir;
    int sec;
} PII;
int n, m;            // 存储 input
int **g, **d;        // 存储地图, 存储距离
PII q[N*N];          // 模拟队列
PII Prev[N][N];      // 前驱结点

int** arr2(int row, int col, int v){
    int** f = (int **)malloc(sizeof(int *) * row);
    for(int i = 0; i < row; i++)
        f[i] = (int *)malloc(sizeof(int) * col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            f[i][j] = v;
    return f;
}
int bfs()
{
    int hh = 0, tt = 0;
    q[0].fir = 0, q[0].sec = 0, d[0][0] = 0;            //表示起点走过了
 
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};   //x 方向的向量和 y 方向的向量组成的上、右、下、左
 
    while(hh <= tt)                   //队列不空
    {
        PII t = q[hh++];              //取队头元素
        for(int i = 0; i < 4; i++)    //枚举4个方向
        {
            int x = t.fir + dx[i], y = t.sec + dy[i];                                   //x表示沿着此方向走会走到哪个点
            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)     //在边界内 并且是空地可以走 且之前没有走过
            {
                d[x][y] = d[t.fir][t.sec] + 1;                                          //到起点的距离
                Prev[x][y] = t;
                tt += 1;
                q[tt].fir = x, q[tt].sec = y;                                           //新坐标入队
            }
        }
    }
    // 输出路径
    int x = n - 1, y = m - 1;
    while(x || y) //有一个不d等于0 
    {
        printf("%d %d\n", x, y);
        PII t = Prev[x][y];
        x = t.fir, y = t.sec;
    }
    return d[n-1][m-1]; //输出右下角点距起点的距离即可
}
int main() 
{
    g = arr2(N, N, 0);
    d = arr2(N, N, -1);//距离初始化为- 1表示没有走过
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d", &g[i][j]);
    printf("%d", bfs());
}

/**
 * 题目描述
给定一个 n×m 的二维整数数组，用来表示一个迷宫，数组中只包含 0 或 1，其中 0 表示可以走的路，1 表示不可通过的墙壁。
最初，有一个人位于左上角 (1,1) 处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。
请问，该人从左上角移动至右下角 (n,m) 处，至少需要移动多少次。
数据保证 (1,1) 处和 (n,m) 处的数字为 0，且一定至少存在一条通路。

输入格式
第一行包含两个整数 n 和 m。
接下来 n 行，每行包含 m 个整数（0 或 1），表示完整的二维数组迷宫。

输出格式
输出一个整数，表示从左上角移动至右下角的最少移动次数。

数据范围
1 ≤ n,m ≤ 100

输入样例：
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

输出样例：
8
*/