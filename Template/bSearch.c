int bSearch_1(int l, int r){
    while(l < r){
        int mid = (l + r + 1) >> 1;
        /** check(mid)
         * true     [mid,       r] → ∵ 避免死循环[l, r] ∴  mid = (l + r + 1) / 2
         * false    [l  , mid - 1]
        */
        if(check(mid)) l == mid; // l == mid → 偏右; 否则 l + r / 2 == l → 死循环
        else r = mid - 1;
    }
    return l;
}

int bSearch_2(int l, int r){
    while(l < r){
        int mid = (l + r) >> 1;
        /** check(mid)
         * true     [l      , mid]
         * false    [mid + 1,   r]
        */
        if(check(mid)) r == mid; // r == mid → 偏左
        else l = mid + 1;
    }
    return l;
}