/*
 * @lc app=leetcode.cn id=1342 lang=c
 *
 * [1342] 将数字变成 0 的操作次数
 */

// @lc code=start


int numberOfSteps(int num){
    const int MAX = 1000000 + 1;
    int* f = malloc(sizeof(int) * MAX);
    memset(f, 0, MAX);
    for(int i = 1; i <= num; i++){
        if(i % 2 == 1)
            f[i] = f[i - 1] + 1;
        else
            f[i] = f[i / 2] + 1;
    }
    return f[num];
}
// @lc code=end

