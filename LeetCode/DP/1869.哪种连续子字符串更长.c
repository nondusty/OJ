/*
 * @lc app=leetcode.cn id=1869 lang=c
 *
 * [1869] 哪种连续子字符串更长
 */

// @lc code=start
#include<stdbool.h>

int max(int a, int b){
    return a > b ? a : b;
}

int** arr2(int row, int col, int v){
    int** f = (int **)malloc(sizeof(int *) * row);
    for(int i = 0; i < row; i++)
        f[i] = (int *)malloc(sizeof(int) * col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            f[i][j] = v;
    return f;
}

bool checkZeroOnes(char * s){
    int len = strlen(s);
    int **dp = arr2(len, 2, 0);
    int *maxV = (int *)malloc(sizeof(int) * 2);
    memset(maxV, 0, sizeof(int) * 2);
    dp[0][s[0] - '0'] = maxV[s[0] - '0'] = 1;
    for(int i = 1; i < len; i++){
        if(s[i] == s[i - 1])
            dp[i][s[i] - '0'] = dp[i - 1][s[i] - '0'] + 1;
        else
            dp[i][s[i] - '0'] = 1;
        maxV[0] = max(maxV[0], dp[i][0]);
        maxV[1] = max(maxV[1], dp[i][1]);
    }
    return (maxV[1] > maxV[0]);
}
// @lc code=end

