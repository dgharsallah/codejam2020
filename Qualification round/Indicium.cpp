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

vector<set<int>> R, C;
vector<vector<int>> buf;
set<vector<vector<int>>> all;
int n;
int k;

/*
This solution passes only the first set of testcases
*/

bool gen(int r, int c) {
    if (r == n - 1 && c >= n) {
//        all.insert(buf);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += buf[i][i];
        }
        if (sum == k)
            return true;
        return false;
    }
    if (c >= n) {
        c = 0;
        r++;
    }
    for (int i = 1; i <= n; ++i) {
        auto posr = R[r].find(i);
        auto posc = C[c].find(i);
        if (posr != R[r].end() && posc != C[c].end()) {
            R[r].erase(posr);
            C[c].erase(posc);
            buf[r][c] = i;
            if (gen(r, c + 1))
                return true;
            R[r].insert(i);
            C[c].insert(i);
        }
    }
    return false;
}

void solve(int t) {
    cin >> n >> k;
    buf.resize(n);
    R.resize(n);
    C.resize(n);
    for (int i = 0; i < n; ++i) {
        buf[i].resize(n);
        for (int j = 0; j < n; ++j) {
            C[j].insert(i + 1);
            R[j].insert(i + 1);
        }
    }
    cout << "Case #" << t << ": ";
    if (gen(0, 0)) {
        cout << "POSSIBLE\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << buf[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }
//    cout << all.size() << endl;
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
