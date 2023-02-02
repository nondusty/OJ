/*
 * @lc app=leetcode.cn id=1043 lang=c
 *
 * [1043] 分隔数组以得到最大和
 */

// @lc code=start
int max(int a, int b){
    return a > b ? a : b;
}

int maxSumAfterPartitioning(int* arr, int arrSize, int k){
    const int MAX = arrSize + 1;
    int*f = (int *)malloc(sizeof(int) * MAX);
    memset(f, 0, sizeof(int) * MAX);
    for(int i = 1; i <= arrSize; i++){
        for(int j = 1, maxV = 0; j <= k && j <= i; j++){
            maxV = max(maxV, arr[i - j + 1 - 1]);
            /**
                i - j + 1 → 后段边界索引
                ∵ i 自 1 开始计数
                ∴ i 索引值 → 实际值 - 1 
            */
            f[i] = max(f[i], f[i - j] + j * maxV);
        }
    }
    return f[arrSize];
}
// @lc code=end

