#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAX=100010;
int* heap, temp, len;

void down(int curNode){
    int minNode = curNode;
    if(curNode * 2 <= len && heap[curNode * 2] < heap[minNode])     
        minNode = curNode * 2;
    if(curNode * 2 + 1 <= len && heap[curNode * 2 + 1] < heap[minNode])     //该minNode 不一定等于curNode
        minNode = curNode * 2 + 1; 

    if(curNode != minNode){
        temp = heap[minNode];
        heap[minNode] = heap[curNode];
        heap[curNode] = temp;
        down(minNode);
    }
    // printf("%d Down: ", curNode);
    // for(int i = 1; i <= len; i++)
    //     printf("%d ",heap[i]);
    // printf("\n");
}

void up(int curNode){
    while(curNode / 2 && heap[curNode / 2] > heap[curNode]){
        temp = heap[curNode / 2];
        heap[curNode / 2] = heap[curNode];
        heap[curNode] = temp;
        curNode /= 2;
    }
}
int main(){
    temp = 0;
    int n, m;
    scanf("%d %d", &n, &m);
    len = n;
    
    heap = (int*)malloc(sizeof(int) * MAX), memset(heap, 0, sizeof(int) * MAX);
    for(int i = 1; i <= n; i++)
        scanf("%d", &heap[i]);
    
    // 自最后一个非根结点Down
    for(int i = n / 2; i; i--)
        down(i);

    while(m--){
        printf("%d ", heap[1]);         // 每次小顶堆Root
        heap[1] = heap[len];            // 最后一个元素覆盖堆顶元素 
        len--;                          // 总长度减一 操作数组尾效率高
        down(1);                        // 从上向下维护堆
    }
}

/**
 * 题目内容
输入一个长度为n的整数数列，从小到大输出前m小的数。 输入格式
第一行包含整数n和m。
第二行包含n个整数，表示整数数列。

输出格式
共一行，包含m个整数，表示整数数列中前m小的数。

数据范围
1≤m≤n≤10^5 ， 1≤数列中元素≤10^9

输入样例：
5 3
4 5 1 3 2

输出样例：
1 2 3
*/