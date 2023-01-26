/*
 * @lc app=leetcode.cn id=213 lang=c
 *
 * [213] 打家劫舍 II
 */

// @lc code=start

int max(int a, int b){
    return a > b ? a : b;
}

int **arr2(int row, int col, int val){
    int** a = (int **)malloc(sizeof(int *) * row);
    for(int i = 0; i < row; i++)
        a[i] = (int *)malloc(sizeof(int) * col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            a[i][j] = val;
    return a;
    
}

int rob(int* nums, int numsSize){
    const int MAX = 101;
    int** dp = arr2(MAX, 2, 0);
    if(numsSize == 1)
        return nums[0];
    else if(numsSize == 2)
        return max(nums[0], nums[1]);
    dp[0][0] = 0;
    dp[0][1] = nums[0];
    for(int i = 1; i < numsSize; i++)
        for(int j = 0; j < 2; j++){
            if(i == 1){
                if(j == 0)
                    dp[i][j] = nums[1];
                else if(j == 1)
                    dp[i][j] = nums[0];
            }
            else if (i < numsSize - 1){
                dp[i][j] = max(dp[i-1][j], dp[i - 2][j] + nums[i]);
            }
            else if(i == numsSize - 1){
                if(j == 0)
                    dp[i][j] = max(dp[i-1][j], dp[i - 2][j] + nums[i]);
                else if(j == 1)
                    dp[i][j] = dp[i - 1][j];
            }
        }
    return max(dp[numsSize - 1][0], dp[numsSize - 1][1]);
}
// @lc code=end

/**
 * 定义C语言二维数组创建函数 → 记得使用malloc
 * 
 * 首尾相联即考虑第一个是否选中 → 存在两个状态
 * 因此使用二维数组，用第二维存储两种状态
 * 再构建状态转移方程即可
*/