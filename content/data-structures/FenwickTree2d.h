#pragma once

const int MAXN = 1010;
int bit[MAXN][MAXN];
int query(int idx1, int idx2){
    int sum = 0;
    int x = idx1;
    while(x > 0){
	int y = idx2;
	while(y > 0) {
	    sum += bit[x][y];
            y -= (y & -y);
	}
	x -= (x & -x);
    }
    return sum;
}
void update(int idx1, int idx2, int val){
    int x = idx1;
    while(x < MAXN){
	int y = idx2;
	while(y < MAXN){
	    bit[x][y] += val;
	    y += (y & -y);
	}
	x += (x & -x);
    }
}
