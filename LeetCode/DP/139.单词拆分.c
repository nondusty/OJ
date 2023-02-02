/*
 * @lc app=leetcode.cn id=139 lang=c
 *
 * [139] 单词拆分
 */

// @lc code=start
#include<stdbool.h>

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    const int MAX = strlen(s);
    int* f = (int *)malloc(sizeof(int) * MAX);
    memset(f, 0, sizeof(int) * MAX);
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < wordDictSize; j++){
            int len = strlen(wordDict[j]);
            if(i - len + 1 < 0)
                continue;
            if(i - len + 1 != 0 && f[i - len] == 0)
                continue;
            for(int k = 0; k <= len; k++){
                if(k == len){
                    f[i] = 1;
                    break;
                }
                if(s[i - len + 1 + k] != wordDict[j][k])
                    break;
            }
        }
    }
    return f[MAX - 1];
}
// @lc code=end

