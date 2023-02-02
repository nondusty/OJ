/*
 * @lc app=leetcode.cn id=198 lang=c
 *
 * [198] 打家劫舍
 */

// @lc code=start
int max(int a, int b){
    return a > b ? a : b;
}

int rob(int* nums, int numsSize){
    const int MAX = 101;
    int* f = malloc(sizeof(int) * MAX);
    memset(f, 0, sizeof(int) * MAX);
    f[0] = nums[0];
    if(numsSize > 1)
        f[1] = max(nums[0], nums[1]);
    for(int i = 2; i < numsSize; i++)
        f[i] = max(f[i - 2] + nums[i], f[i - 1]);
    return f[numsSize - 1];
}
// @lc code=end

