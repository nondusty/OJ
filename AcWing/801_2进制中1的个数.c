#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lowBit(int x){
    return x & (-x);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int x;
        scanf("%d", &x);
        int res;
        for(res = 0; x != 0; res++)
            x -= lowBit(x);
        printf("%d ", res);
    }
}

/**
 * 题目描述
给定一个长度为 n 的数列，请你求出数列中每个数的二进制表示中 1 的个数。

输入格式
第一行包含整数 n nn。
第二行包含 n nn 个整数，表示整个数列。

输出格式
共一行，包含 n nn 个整数，其中的第 i ii 个数表示数列中的第 i ii 个数的二进制表示中 1 11 的个数。

数据范围
1 ≤ n ≤ 100000,
0 ≤ 数列中元素的值 ≤ 10^9
 

输入样例：
5
1 2 3 4 5

输出样例：
1 1 2 1 2
*/