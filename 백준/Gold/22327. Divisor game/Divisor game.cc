/*
   Sample solution using alice library.
   This solution is incorrect.
   It is provided only to demonstrate the library usage.
   */
#include<bits/stdc++.h>
#include "alice.h"
using namespace std;
long long k, m, n;
int p[1000005];
vector<long long> primes;
void init() {
    for(int i=2 ; i<=1000000 ; i++) {
        if(!p[i]) {
            primes.push_back(i);
            for(int j=i ; j<=1000000 ; j+=i) {
                p[j] = 1;
            }
        }
    }
}

void solve() {
    init();
	n = get_n();
	k = 1;
    for(auto x : primes) if(k * x <= n) {
        while(1) {
            if(k*x>n) break;
            if(is_divisible_by(k*x)) {
                k*=x;
            } else break;
        }
    }
	/* here k should be Alice's secret number */
	guess(k);
	return;
}

