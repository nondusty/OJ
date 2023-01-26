/*
 * @lc app=leetcode.cn id=91 lang=c
 *
 * [91] 解码方法
 */

// @lc code=start


int numDecodings(char * s){
    const int MAX = 101;
    int *f = (int *)malloc(sizeof(int) * MAX);
    memset(f, 0, MAX);
    int len = strlen(s);
    printf("%d\n", len);
    printf("%d",sizeof(int));
    for(int i = 0; i < len; i++){
        if(i == 0){
            if(s[i] == '0')
                f[i] = 0;
            else
                f[i] = 1;
        }
        else{
            if(s[i] != '0')
                f[i] += f[i - 1];
            if(s[i - 1] == '1' || s[i - 1] == '2'){
                int val = (s[i - 1] - '0') * 10 + s[i] - '0';
                if(val <= 26){
                    if(i == 1)
                        f[i]++;
                    else
                        f[i] += f[i - 2];
                }
            }
        }
    }
    return f[len - 1];
}
// @lc code=end

/**
 * 起始字符(i == 0)
 *  s[i] == 0 → 0
 *  s[i] != 0 → 1
 * 
 * 其余字符
 *  s[i] != 0 → f[i] = f[i - 1]  (可能性不变)
 *  s[i] == 0 → 与前一个字符(s[i - 1])有关
 *       s[i - 1] == 1 || s[i - 1] == 2
 *          不是 → f[i] = f[i - 1] (可能性不变)
 *          是  → 
 *              判断两者是否[1, 26]
 *                  不是 → f[i] = f[i - 1] (可能性不变)
 *                  是  
 *                      → s[i - 1] == 1
 *                       f[i] = f[i - 1] + 1 (可能性加一)
 * 
 *                      → s[i - 1] == 2
 *                       f[i] = f[i - 1] + f[i - 2]
 *                          113
 *                          123
*/
