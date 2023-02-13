#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
#define inf 0x3f3f3f3f

int **arr2(int row, int col, int val){
    int** a = (int **)malloc(sizeof(int *) * row);
    for(int i = 0; i < row; i++)
        a[i] = (int *)malloc(sizeof(int) * col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            a[i][j] = val;
    return a;
}
int main(){
    int** f = arr2(MAX, MAX, 0);
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            printf("%d ", f[i][j]);
        puts("");
    }

    puts("");

    int g[MAX][MAX];
    memset(g, inf, sizeof g);
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            printf("%d ", g[i][j]);
        puts("");
    }
}