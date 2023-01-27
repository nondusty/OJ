/*
 * @lc app=leetcode.cn id=70 lang=c
 *
 * [70] 爬楼梯
 */

// @lc code=start

int climbStairs(int n){
    int* f = malloc(sizeof(int) * 46);
    memset(f, 0, sizeof(int) * 46);
    f[0] = f[1] = 1;
    for(int i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    return f[n];
}
// @lc code=end

