#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    const int MAX = 100001;
    int* a = (int*)malloc(sizeof(int) * MAX);
    int* s = (int*)malloc(sizeof(int) * MAX);
    memset(a, 0, sizeof(int)*MAX);
    memset(s, 0, sizeof(int)*MAX);

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    int res = 0;
    for(int i = 0, j = 0; i < n; i++){
        s[a[i]]++;
        while(s[a[i]] > 1){
            s[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    printf("%d", res);
}

/**
 * 题目描述
给定一个长度为 n 的整数序列，请找出最长的不包含重复的数的连续区间，输出它的长度。

输入格式
第一行包含整数 n。
第二行包含 n 个整数（均在 0∼105范围内），表示整数序列。

输出格式
共一行，包含一个整数，表示最长的不包含重复的数的连续区间的长度

数据范围
1≤n≤105

输入样例：
5
1 2 2 3 5

输出样例：
3
*/