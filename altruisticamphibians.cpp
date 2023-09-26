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
 * Problem Name: Altruistic Amphibians
 * Difficulty: 5.4 (Medium)
 * Categories: Greedy, DP
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, D;
    cin >> N >> D;

    vector<pair<pii, int>> frogs;

    rep(i, 0, N) {
        int l, w, h;
        cin >> l >> w >> h;
        frogs.push_back(pair<pii, int>(pii(-w, h), l));
    }

    sort(all(frogs));

    vi dp(1e8); // dp[i] = height of highest tower with remaining capacity of i

    int result = 0;

    rep(i, 0, N) {
        int w = -frogs[i].first.first;
        int h = frogs[i].first.second;
        int l = frogs[i].second;

        if(dp[w] + l > D) result++;
        for(int k = 1; k < w && w + k < 1e8; k++) dp[k] = max(dp[k], h + dp[w + k]);
    }

    cout << result << endl;

    return 0;
}
