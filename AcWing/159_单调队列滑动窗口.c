#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    const int MAX = 1000010;
    int *value = (int *)malloc(sizeof(int) * MAX);
    int *newArray = (int *)malloc(sizeof(int) * MAX);
    memset(value, 0, sizeof(int) * MAX);
    memset(newArray, 0, sizeof(int) * MAX);

    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &value[i]);

    // 定义队头、队尾，end = 0 开始记录, index = -1为空
    int start, end;

    // 最小值
    start = 0, end = -1; 
    for (int i = 0; i < n; i++)
    {
        // 最大窗口区间是[i - k + 1, i]

        // 条件: 队列非空 && 区间左端点 > 窗口左索引 → 后移: start++
        if (start <= end && i - k + 1 > newArray[start])
            start++;

        // 条件: 队列非空 && 区间右端点对应值 > 当前索引对应值 → 舍弃: end--
        while (start <= end && value[newArray[end]] >= value[i])
            end--;

        newArray[++end] = i;

        if (i - k + 1>= 0)
            printf("%d ", value[newArray[start]]);
    }
    puts("");

    // 最大值
    start = 0, end = -1;
    for (int i = 0; i < n; i++)
    {
        // 最大窗口区间是[i - k + 1, i]
        if (start <= end && newArray[start] < i - k + 1)
            start++;

        while (start <= end && value[newArray[end]] <= value[i])
            end--;

        newArray[++end] = i;

        if (i - k + 1>= 0)
            printf("%d ", value[newArray[start]]);
    }
}

// 该代码引用AcWing网站的代码
/**
 * 题目描述
给定一个大小为 n ≤ 1 0 6 n≤10^6n≤10^6的数组。
有一个大小为 k kk 的滑动窗口，它从数组的最左边移动到最右边。
你只能在窗口中看到 k kk 个数字。
每次滑动窗口向右移动一个位置。
以下是一个例子：
该数组为 [1 3 -1 -3 5 3 6 7]，k kk 为 3 33。

窗口位置	                    最小值	        最大值
[1 3 -1] -3 5 3 6 7	            -1	            3
1 [3 -1 -3] 5 3 6 7	            -3	            3
1 3 [-1 -3 5] 3 6 7	            -3	            5
1 3 -1 [-3 5 3] 6 7	            -3	            5
1 3 -1 -3 [5 3 6] 7	             3	            6
1 3 -1 -3 5 [3 6 7]	             3	            7
你的任务是确定滑动窗口位于每个位置时，窗口中的最大值和最小值。

输入格式
输入包含两行。
第一行包含两个整数 n nn 和 k kk，分别代表数组长度和滑动窗口的长度。
第二行有 n nn 个整数，代表数组的具体数值。
同行数据之间用空格隔开。

输出格式
输出包含两个。
第一行输出，从左至右，每个位置滑动窗口中的最小值。
第二行输出，从左至右，每个位置滑动窗口中的最大值。

输入样例：
8 3
1 3 -1 -3 5 3 6 7

输出样例：
-1 -3 -3 -3 3 3
3 3 5 5 6 7
*/