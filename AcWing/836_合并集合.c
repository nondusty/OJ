#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int find(int *f, int x)
{
    if (f[x] != x)
        f[x] = find(f, f[x]);
    return f[x];
}

int main(){
    const int MAX = 1001;
    int* p;
    p = (int*)malloc(sizeof(int)*MAX), memset(p, 0, sizeof(int) * MAX);
    
    int n, m;
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++)
        p[i] = i;

    while(m--){
        char* op;
        op = (char*)malloc(sizeof(char) * 2), memset(op, 0, sizeof(char) * 2);
        int x, y;
        scanf("%s %d%d", op, &x, &y);

        if(op[0] == 'M'){
            p[find(p, x)] = find(p, y);//x的祖宗结点的祖宗 为y的祖宗结点。
        }
        else{
            if(find(p, x) == find(p, y))
                printf("Yes\n");
            else
                puts("No");
        }
    }
    return 0;
}

/**
 * 题目描述
一共有n个数，编号是1~n，最开始每个数各自在一个集合中。
现在要进行m个操作，操作共有两种：
“M a b”，将编号为a和b的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
“Q a b”，询问编号为a和b的两个数是否在同一个集合中

输入格式
第一行输入整数n和m。
接下来m行，每行包含一个操作指令，指令为“M a b”或“Q a b”中的一种。

输出格式
对于每个询问指令”Q a b”，都要输出一个结果，如果a和b在同一集合内，则输出“Yes”，否则输出“No”。
每个结果占一行。

数据范围
1≤n,m≤10^5 1≤n,m≤10^5

输入样例
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4

输出样例
Yes
No
Yes
*/