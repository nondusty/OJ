/*
 * @lc app=leetcode.cn id=1646 lang=c
 *
 * [1646] 获取生成数组中的最大值
 */

// @lc code=start


int getMaximumGenerated(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    const int MAX = n + 1;
    int *f = (int *)malloc(sizeof(int) * MAX);
    memset(f, 0, sizeof(int) * MAX);
    f[0] = 0;
    f[1] = 1;
    int max = 0;
    for(int i = 2; i <= n; i++){
        if(i % 2 == 1)
            f[i] = f[(i-1) / 2] + f[(i-1) / 2 + 1];
        else
            f[i] = f[i / 2];
        if(max < f[i])
            max = f[i];
    }
    return max;

}
// @lc code=end

