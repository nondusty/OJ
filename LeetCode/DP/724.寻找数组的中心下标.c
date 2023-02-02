/*
 * @lc app=leetcode.cn id=724 lang=c
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
int pivotIndex(int* nums, int numsSize){
    int len = numsSize;
    int* f = (int *)malloc(sizeof(int) * len);
    memset(f, 0, sizeof(int) * len);
    for(int i = 0; i < len; i++){
        if(i == 0)
            f[i] = nums[i];
        else
            f[i] = f[i - 1] + nums[i];
    }

    if(f[len - 1] - f[0] == 0)
        return 0;

    for(int i = 1; i < len; i++)
        if(f[i - 1] == f[len - 1] - f[i])
            return i;

    return -1;
}
// @lc code=end

