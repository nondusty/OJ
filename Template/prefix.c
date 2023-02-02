#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAX = 1001;
int **arr2(int row, int col, int val){
    int** a = (int **)malloc(sizeof(int *) * row);
    for(int i = 0; i < row; i++)
        a[i] = (int *)malloc(sizeof(int) * col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            a[i][j] = val;
    return a;
}

void prefixOne(){
    int* a = (int *)malloc(sizeof(int) * MAX);
    int* s = (int *)malloc(sizeof(int) * MAX);
    memset(a, 0, sizeof(int) * MAX);
    memset(s, 0, sizeof(int) * MAX);

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    while(m--){
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
}

void prefixTwo(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    int** a = arr2(MAX, MAX, 6);
    int** s = arr2(MAX, MAX, 0);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    
    while(q--){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
    }
}

int main(){
    prefixTwo();
}