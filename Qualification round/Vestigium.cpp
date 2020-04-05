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
    int n;
    cin >> n;
    int trace = 0;
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<set<int>> rr(n), cc(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
            rr[i].insert(m[i][j]);
            cc[j].insert(m[i][j]);
            trace += (i == j) * m[i][j];
        }
    }
    int r = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        r += rr[i].size() != n;
        c += cc[i].size() != n;
    }
    cout << "Case #" << t << ": " << trace << " " << r << " " << c << endl;
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
