#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define ll long long
using namespace std;

void solve(int t) {
    cout << "Case #" << t << ": ";
    string s, ans = "";
    cin >> s;
    int n = s.size();
    s = "0" + s + "0";
    int prev = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = s[i];
        while(s[i - 1] < cur) {
            ans += "(";
            --cur;
        }
        ans += s[i];
        cur = s[i];
        while(cur > s[i + 1]) {
            ans += ")";
            --cur;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}
