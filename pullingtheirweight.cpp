#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void init_cin() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
}

/*
 * Problem Name: Pulling Their Weight
 * Difficulty: 4.4 (Medium)
 * Categories: 
 * Algorithms: Binary Search
 */

int main() {
    init_cin();

    int M;
    cin >> M;

    vi a(M);
    rep(i, 0, M) cin >> a[i];
    sort(all(a));

    // take prefix and suffix sum
    vi pre(M), suf(M);
    pre[0] = a[0], suf[M - 1] = a[M - 1];
    rep(i, 1, M) pre[i] = pre[i - 1] + a[i];
    for(int i = M - 2; i >= 0; i--) suf[i] = suf[i + 1] + a[i];

    // binary search to find the index where prefix and suffix sum are closest
    int l = 0, r = M - 1;
    while(l < r) {
        int m = (l + r + 1) / 2;

        if(pre[m] <= suf[m]) l = m;
        else r = m - 1;
    }

    if(l == M - 1 || a[l] == a[l + 1] || pre[l] == suf[l]) cout << a[l] << endl;
    else cout << (a[l] + 1) << endl;

    return 0;
}
