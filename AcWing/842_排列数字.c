#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
int n;
int path[N] = {0}, st[N] = {0};
void dfs(int u){
    // 区间 : [0, n-1]
    if (u == n){
        for (int i = 0; i < n; i ++ )
            printf("%d ",path[i]);
        puts("");
        return;
    }
    for (int i = 1; i <= n; i ++ ){
        //如果没有使用过
        if (st[i] == 0){ 
            path[u] = i ;       // 填入没有被使用过的数字
            st[i] = 1;          // 标记为使用了
            dfs(u + 1);         // 进行下一个位置的计算
            path[u] = 0;        // 回溯复原
            st[i] = 0;          // 回溯复原
        }
    }
}
int main(){
    scanf("%d", &n);
    dfs(0);
}

/**
 * 题目描述
给定一个整数 n，将数字 1∼n 排成一排，将会有很多种排列方法。
现在，请你按照字典序将所有的排列方法输出。

输入格式
共一行，包含一个整数 n。

输出格式
按字典序输出所有排列方案，每个方案占一行。

数据范围
1 ≤ n ≤ 7

输入样例：
3

输出样例：
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/