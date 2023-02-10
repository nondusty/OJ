#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long ULL;
const int P = 131;                        // 这里P取131 / 13331 为经验值，可以使得不用考虑冲突的情况
#define N 100010
char str[N];                              // str这里是输入的字符串，同时使用ASCII值
ULL hash[N], pM[N];                       // hash为前n个字母的哈希值，pM为p的n次幂
// 求l-r区间内的哈希值
ULL get(int l,int r){
    return hash[r] - hash[l-1] * pM[r-l+1];
}

int main(){
    int n, m;
    scanf("%d %d %s", &n, &m, str + 1);
    pM[0] = 1;
    //求P的n次幂和前n个字符的哈希值
    for(int i = 1; i <= n; i++){
        pM[i] = pM[i-1] * P;
        hash[i] = hash[i-1] * P + str[i]; 
    }
    while(m--){
        int l1,r1,l2,r2;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        if(get(l1,r1) == get(l2,r2))
            puts("Yes");
        else
            puts("No");
    }
}
/**
 * 题目描述
给定一个长度为 n 的字符串，再给定 m 个询问，每个询问包含四个整数 l1,r1,l2,r2，请你判断 [l1,r1][l1,r1] 和 [l2,r2][l2,r2] 这两个区间所包含的字符串子串是否完全相同。
字符串中只包含大小写英文字母和数字。

输入格式
第一行包含整数 n 和 m，表示字符串长度和询问次数。
第二行包含一个长度为 n 的字符串，字符串中只包含大小写英文字母和数字。
接下来 m 行，每行包含四个整数 l1,r1,l2,r2 表示一次询问所涉及的两个区间。
注意，字符串的位置从 1 开始编号。

输出格式
对于每个询问输出一个结果，如果两个字符串子串完全相同则输出 Yes，否则输出 No。
每个结果占一行。

数据范围
1≤n,m≤1051≤n,m≤105

输入样例：
8 3
aabbaabb
1 3 5 7
1 3 6 8
1 2 1 2

输出样例
Yes
No
Yes
*/