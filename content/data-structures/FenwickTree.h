/**
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */
#pragma once

const int MAXN = 100010;
int bit[MAXN];
int query(int idx){
    int sum = 0;
    while(idx > 0){
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update(int idx, int val){
    while(idx < MAXN){
        bit[idx] += val;
        idx += (idx & -idx);
    }
}
