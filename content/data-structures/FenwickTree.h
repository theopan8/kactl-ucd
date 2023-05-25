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
