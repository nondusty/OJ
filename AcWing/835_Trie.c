#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 10010;
int** son;
int * cnt;
char * str;
int idx = 0;        //记录结点总数 → 差异化 : 每个结点inx不同

int** arrTwo(int row, int col, int val){
    int** f = (int **)malloc(sizeof(int) * row);
    for(int i = 0; i < row; i++)
        f[i] = (int *)malloc(sizeof(int) * col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            f[i][j] = val;
    return f;
}

void insert(char str[])
{
    int node = 0;                       // Trie对应结点 初始0 → 根节点
    
    for (int i = 0; str[i]; i++)        // 遍历字符串，字符串末尾是/0多以可以用str[i]直接判断是不是结尾了
    {                        
        int cur = str[i] - 'a';         // 把26个字母映射到0-25
        if (!son[node][cur])
            son[node][cur] = ++idx;     // 新节点 → 创建 → 差异化idx
        node = son[node][cur];
    }
    cnt[node]++;                        // 以node这个节点结尾字符串数量加一
}
int query(char str[])
{
    int node = 0;
    for (int i = 0; str[i]; i++)
    {
        int cur = str[i] - 'a';
        if (!son[node][cur])
            return 0;                   // 到底了，查无此单词
        node = son[node][cur];
    }
    return cnt[node];                   // 返回查到的单词个数
}
int main()
{
    son = arrTwo(MAX, 26, 0);                                                         // 26指每个节点最多有26个子节点
    cnt = (int  *)malloc(sizeof(int) * MAX),   memset(cnt, 0, sizeof(int) * MAX);      // 以当前字符结尾的单词个数
    str = (char *)malloc(sizeof(char) * MAX), memset(str, 0, sizeof(char) * MAX);     // 记录字符串 
    idx = 0;                                                                          // 当前使用的下标 

    int n;
    scanf("%d", &n);
    while (n--)
    {
        char op[2];
        scanf("%s%s", op, str);
        if (op[0] == 'I')
            insert(str);
        else
            printf("%d\n", query(str));
    }
    return 0;
}

/**
 * 题目描述
维护一个字符串集合，支持两种操作：
I x 向集合中插入一个字符串 x；
Q x 询问一个字符串在集合中出现了多少次。
共有 N 个操作，输入的字符串总长度不超过 10^5 ，字符串仅包含小写英文字母。

输入格式
第一行包含整数 N，表示操作数。
接下来 N 行，每行包含一个操作指令，指令为 I x 或 Q x 中的一种。

输出格式
对于每个询问指令 Q x，都要输出一个整数作为结果，表示 x 在集合中出现的次数。
每个结果占一行。

输入样例
5
I   abc
Q abc
Q ab
I   ab
Q ab

输出样例
1
0
1
*/