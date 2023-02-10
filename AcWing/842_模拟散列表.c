#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int N = 100003;
int *val, *nex, *head;  // val:idx结点具体值、nex:idx下一个值、head: 对应Key的拉链头
int idx = 0;            // idx是结点的索引

void insert(int x){
    int k = (x % N + N) % N;
    val[idx] = x;
    nex[idx] = head[k];
    head[k] = idx;
    idx ++ ;
}

// 在哈希表中查询某个数是否存在
int find(int x){
    int k = (x % N + N) % N;
    for (int i = head[k]; i != -1; i = nex[i]) //循环遍历从头节点向下遍历，遍历ne数组的存储的指向地址
        if (val[i] == x)
            return 1;
    return 0;
}

int main(){
    val = (int*)malloc(sizeof(int) * N), memset(val, 0, sizeof(int) * N);
    nex = (int*)malloc(sizeof(int) * N), memset(nex, 0, sizeof(int) * N);
    head = (int*)malloc(sizeof(int) * N), memset(head, -1, sizeof(int) * N);

    int n;
    scanf("%d", &n);

    while (n -- ){
        // puts("Hello");
        char *op = (char *)malloc(sizeof(char) * 2);
        int x = 0;
        scanf("%s %d", op, &x);

        if (op[0] == 'I')
            insert(x);
        if (op[0] == 'Q'){
            printf("%d\n", x);
            if (find(x))
                puts("Yes");
            else
                puts("No");
        }
    }
}
/**
 * 题目描述
维护一个集合，支持如下几种操作：
I x，插入一个数 x；
Q x，询问数 x 是否在集合中出现过；
现在要进行 N 次操作，对于每个询问操作输出对应的结果。

输入格式
第一行包含整数 N，表示操作数量。
接下来 N 行，每行包含一个操作指令，操作指令为 I x，Q x 中的一种。

输出格式
对于每个询问指令 Q x，输出一个询问结果，如果 x 在集合中出现过，则输出 Yes，否则输出 No。
每个结果占一行。

数据范围
1 ≤ N ≤ 10^5
−10^9 ≤ x ≤ 109

输入样例
5
I 1
I 2
I 3
Q 2
Q 5

输出样例
Yes
No
*/