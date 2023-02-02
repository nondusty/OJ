#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int N = 1001;

int** arr2(int row, int col, int val){
    int** arr = (int **)malloc(sizeof(int *) * row);
    for(int i = 0; i < row; i++)
        arr[i] = (int *)malloc(sizeof(int) * col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            arr[i][j] = val;
    return arr;
}

void insert(int **arr, int x1, int y1, int x2, int y2, int c){
    arr[x1][y1] += c;
    arr[x2 + 1][y1] -= c;
    arr[x1][y2 + 1] -= c;
    arr[x2 + 1][y2 + 1] += c;
}

int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    int** tmp = arr2(N, N, 0);
    int** tar = arr2(N, N, 0);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &tmp[i][j]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            insert(tar, i, j, i, j, tmp[i][j]);

    while(q--){
        int x1, y1, x2, y2, c;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        insert(tar, x1, y1, x2, y2, c);
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            tar[i][j] += tar[i - 1][j] + tar[i][j - 1] - tar[i - 1][j - 1];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("%d ", tar[i][j]);
        }
        printf("\n");
    }
}

/**
 * 差分矩阵
输入一个n行m列的整数矩阵，再输入q个操作，每个操作包含五个整数x1, y1, x2, y2, c，其中(x1, y1)和(x2, y2)表示一个子矩阵的左上角坐标和右下角坐标。
每个操作都要将选中的子矩阵中的每个元素的值加上c。
请你将进行完所有操作后的矩阵输出。

输入格式
第一行包含整数n,m,q。
接下来n行，每行包含m个整数，表示整数矩阵。
接下来q行，每行包含5个整数x1, y1, x2, y2, c，表示一个操作。

输出格式
共 n 行，每行 m 个整数，表示所有操作进行完毕后的最终矩阵。

数据范围
1≤n,m≤10001≤n,m≤1000,
1≤q≤1000001≤q≤100000,
1≤x1≤x2≤n1≤x1≤x2≤n,
1≤y1≤y2≤m1≤y1≤y2≤m,
−1000≤c≤1000−1000≤c≤1000,
−1000≤矩阵内元素的值≤1000−1000≤矩阵内元素的值≤1000

输入样例
3 4 3
1 2 2 1
3 2 2 1
1 1 1 1
1 1 2 2 1
1 3 2 3 2
3 1 3 4 1

输出样例
2 3 4 1
4 3 4 1
2 2 2 2
*/