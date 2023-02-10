#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20

int n;
char g[N][N];
int col[N] = {0}, dg[N] = {0}, udg[N] = {0};
void dfs(int u){
    // 区间 : [0, n-1]
    if (u == n){
        for (int i = 0; i < n; i ++ )
            printf("%s\n", g[i]);
        puts("");
        return;
    }

    for (int i = 0; i < n; i ++ ) //按行遍历
        /**
        X >= 0 && Y >= 0    y = x + b  || y = -x + b
        →  b1 = x + y || b2 = -x + y
        ∵ b2 = y - x 可能小于 0 → +n
        ∴ b1 = x + y, b2 = y - x + n

        */
        if (!col[i] && !dg[u + i] && !udg[n - u + i]){
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = 1;        // 标记
            dfs(u + 1);                                     // 递归下一层
            col[i] = dg[u + i] = udg[n - u + i] = 0;        // 恢复
            g[u][i] = '.';
        }
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            g[i][j] = '.';
    dfs(0);
}

/**
 * 题目描述
现在给定整数 n，请你输出所有的满足条件的棋子摆法。
输入格式
共一行，包含整数 n。

输出格式
每个解决方案占 n 行，每行输出一个长度为 n 的字符串，用来表示完整的棋盘状态。
其中 . 表示某一个位置的方格状态为空，Q 表示某一个位置的方格上摆着皇后。
每个方案输出完成后，输出一个空行。
注意：行末不能有多余空格。
输出方案的顺序任意，只要不重复且没有遗漏即可。

数据范围
1 ≤ n ≤ 9

输入样例：
4

输出样例：
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..
*/