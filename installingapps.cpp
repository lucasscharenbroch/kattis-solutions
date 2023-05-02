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
 * Problem Name: Installing Apps
 * Difficulty: 7.3 (Hard)
 * Categories: Greedy, Dynamic Programming
 * Algorithms: Knapsack
 */

struct app {
    int d, s, i;

    app() { }

    friend bool operator<(app a, app b) { // compare by (s - d) == -(d - s)
        return (a.s - a.d) < (b.s - b.d);
    }
};

int main() {
    init_cin();

    int N, C;
    cin >> N >> C;

    vector<app> apps(N);

    rep(i, 0, N) {
        cin >> apps[i].d >> apps[i].s;
        apps[i].i = i;
    }

    // greedily order by (d - s) before knapsack to ensure that selection is
    // always valid, regaurdless of order
    sort(all(apps));

    vector<vi> dp(C + 1, vi(N + 1));

    for(int j = N; j --> 0;) for(int i = C + 1; i --> 0;) {
        if(max(apps[j].d, apps[j].s) > i) dp[i][j] = dp[i][j + 1];
        else dp[i][j] = max(dp[i][j + 1], 1 + dp[i - apps[j].s][j + 1]);
    }

    vi result;
    int i = C;

    rep(j, 0, N) {
        if(dp[i][j] != dp[i][j + 1]) {
            result.push_back(apps[j].i + 1); // original index of used app
            i -= apps[j].s;
        }
    }

    cout << sz(result) << endl;
    rep(i, 0, sz(result)) cout << result[i] << (i == sz(result) - 1 ? "\n" : " ");

    return 0;
}
