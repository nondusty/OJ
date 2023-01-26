/*
 * @lc app=leetcode.cn id=746 lang=c
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
int min(int a, int b){
    return a < b ? a : b;
}

int minCostClimbingStairs(int* cost, int costSize){
    const int MAX = 1001;
    int*m = malloc(sizeof(int) * MAX);
    memset(m, 0, MAX);
    m[0] = m[1] = 0;
    for(int i = 2; i <= costSize; i++)
        m[i] = min(m[i - 1] + cost[i - 1], m[i - 2] + cost[i - 2]);
    return m[costSize];
}
// @lc code=end

