/*
 * @lc app=leetcode.cn id=91 lang=c
 *
 * [91] 解码方法
 */

// @lc code=start


int numDecodings(char* s) {
    int len = strlen(s);
    const int MAX = len + 1;
    int *f = (int *)malloc(sizeof(int) * MAX);
    memset(f, 0, sizeof(int) * MAX);
    f[0] = 1;
    for(int i = 1; i <= len; i++){
        // if(s[i - 1] >='1' && s[i - 1] <= '9')
        //         f[i] += f[i - 1];
        // if(i > 1){
        //     int val = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
        //     if(val >= 10 && val <= 26)
        //         f[i] += f[i - 2];
        // }
        if(i == 1){
            if(s[i - 1] == '0')
                f[i] = 0;
            else
                f[i] = 1;
        }
        else{
            if(s[i - 1] >='1' && s[i - 1] <= '9')
                f[i] = f[i - 1];
            int val = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if(val == 10 || val == 20)
                f[i] = f[i - 2];
            else if(val >= 10 && val <= 26)
                f[i] = f[i - 1] + f[i - 2];
        }
    }
    return f[len];
}

// @lc code=end