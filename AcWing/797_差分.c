#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int N = 10001;
void insert(int *arr, int l, int r, int c){
    arr[l] += c;
    arr[r + 1] -= c;
}

int main(){    
    int n, m;
    scanf("%d %d", &n, &m);
    int *tmp = (int *)malloc(sizeof(int) * N);
    int *tar = (int *)malloc(sizeof(int) * N);
    memset(tmp, 0, sizeof(int) * N);
    memset(tar, 0, sizeof(int) * N);
    for(int i = 1; i <= n; i++) scanf("%d", &tmp[i]);
    for(int i = 1; i <= n; i++) insert(tar, i, i, tmp[i]);
    while(m--){
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        insert(tar, l, r, c);
    }
    for(int i = 1; i <= n; i++) tar[i] += tar[i - 1];   //最后一次统一改变 → 降低时间复杂度
    for(int i = 1; i <= n; i++) printf("%d ", tar[i]);
}
/**
 * 题目描述
输入一个长度为 n 的整数序列。
接下来输入 m 个操作，每个操作包含三个整数 l,r,c，表示将序列中 [l,r] 之间的每个数加上 c。
请你输出进行完所有操作后的序列。

输入格式
第一行包含两个整数 n 和 m。
第二行包含 n 个整数，表示整数序列。
接下来 m 行，每行包含三个整数 l，r，c，表示一个操作。

输出格式
共一行，包含 n 个整数，表示最终序列。

数据范围
1≤n,m≤100000,
1≤l≤r≤n,
−1000≤c≤1000,
−1000≤整数序列中元素的值≤1000

输入样例
6 3
1 2 2 1 2 1
1 3 1      → 2 3 3 1 2 1
3 5 1      → 2 3 4 2 3 1
1 6 1      → 3 4 5 3 4 2

输出样例
3 4 5 3 4 2
*/