#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX = 1e5 + 10;
int *p , *len;
char* op;

//初始化并查集的函数
void init(int n) {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        len[i] = 1;
    }
}

//并查集函数,路径压缩法
int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

//合并操作
void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    p[x] = y;
    len[y] += len[x];
}

//查询操作
int check(int a, int b) {
    return find(a) == find(b);
}

int main() {
    p = (int*)malloc(sizeof(int) * MAX), memset(p, 0, sizeof(int)*MAX);
    len = (int*)malloc(sizeof(int) * MAX), memset(len, 0, sizeof(int)*MAX);
    op = (char*)malloc(sizeof(char) * 3), memset(len, 0, sizeof(char)*3);

    int n, m;
    scanf("%d %d", &n, &m);
    init(n);
    while (m--) {
        scanf("%s", op);
        int a, b;
        if (op[0] == 'C') {
            scanf("%d %d", &a, &b);
            if (!check(a, b))
                merge(a, b);
        }
        else if (op[0] == 'Q' && op[1] == '1') {    //查询是否在同一个集合
            scanf("%d %d", &a, &b);
            check(a, b) ? printf("Yes\n") : printf("No\n");
        }else if(op[0] == 'Q' && op[1] == '2') {                   //查询一个集合有多少个元素
            scanf("%d", &a);
            printf("%d\n", len[find(a)]);
        }
    }
    return 0;
}
/**
 * 题目描述
给定一个包含n个点（编号为1~n）的无向图，初始时图中没有边。
现在要进行m个操作，操作共有三种：
“C a b”，在点a和点b之间连一条边，a和b可能相等
“Q1 a b”，询问点a和点b是否在同一个连通块中，a和b可能相等
“Q2 a”，询问点a所在连通块中点的数量

输入格式
第一行输入整数n和m。
接下来m行，每行包含一个操作指令，指令为“C a b”，“Q1 a b”或“Q2 a”中的一种。

输出格式
对于每个询问指令”Q1 a b”，如果a和b在同一个连通块中，则输出“Yes”，否则输出“No”。
对于每个询问指令“Q2 a”，输出一个整数表示点a所在连通块中点的数量
每个结果占一行。

数据范围
1≤n,m≤10^5

输入样例：
5 5
C 1 2
Q1 1 2
Q2 1
C 2 5
Q2 5

输出样例：
Yes
2
3
*/