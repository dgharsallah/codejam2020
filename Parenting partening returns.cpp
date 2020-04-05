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

struct interval {
    int s, e, idx;
    bool operator<(const interval& other) const {
        if (s == other.s)
            return e < other.e;
        return s > other.s;
    }
};
void solve(int t) {
    cout << "Case #" << t << ": ";
    int n;
    cin >> n;
    string ans(n, 'J');
    int jEndsAt = 0, cEndsAt = 0;
    vector<pair<int, int> > v(n);
    priority_queue<interval> q;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        q.push(interval{v[i].first, v[i].second, i});
    }
    while(!q.empty()) {
        interval cur = q.top();
        q.pop();
        if (jEndsAt <= cur.s) {
            ans[cur.idx] = 'J';
            jEndsAt = cur.e;
        } else if(cEndsAt <= cur.s) {
            ans[cur.idx] = 'C';
            cEndsAt = cur.e;
        } else {
            cout << "IMPOSSIBLE\n";
            return;
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
