#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    const int MAX = 100010;

    // f 数组记录符合条件的情况 → 单调数组
    //模拟栈: 在每次输入的数入栈前，将栈中比它大的数都删掉，使栈变成从栈底到栈顶单调递增的单调栈，此时的栈顶便是比它小且离它最近的数。
    int*f = (int*)malloc(sizeof(int) * MAX);
    memset(f, 0, sizeof(int)*MAX);
    int index = 0;

    int n;
    scanf("%d", &n);

    for(int  i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        
        //idnex = 1开始记录, index = 0为空
        while(index && f[index] >= x)
            index--;
        if(index)
            printf("%d ", f[index]);
        else
            printf("-1 ");
        
        f[++index] = x;
    }
    return 0;
}
/**
 * 题目描述
给定一个长度为N的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出-1。

输入格式
第一行包含整数N，表示数列长度。
第二行包含N个整数，表示整数数列。

输出格式
共一行，包含N个整数，其中第i个数表示第i个数的左边第一个比它小的数，如果不存在则输出-1。

数据范围
1≤N≤105
1≤数列中元素≤109

输入样例
5
3 4 2 7 5

输出样例
-1 3 -1 2 2
*/