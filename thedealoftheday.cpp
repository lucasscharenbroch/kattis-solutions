#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

typedef __int128 ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void init_cin() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
}

/*
 * Problem Name: The Deal of the Day
 * Difficulty: 2.2 (Easy)
 * Categories: Dynamic Programming
 * Algorithms: 
 */

ostream& operator<<(ostream& os, ll value) {
    string s;

    if(value == 0) return os << 0;

    while(value) {
        s = to_string((int)(value % 10)) + s;
        value /= 10;
    }

    return os << s;
}

int main() {
    init_cin();

    int N = 10;
    vi a(N);
    rep(i, 0, N) cin >> a[i];

    int K;
    cin >> K;

    vector<vector<ll>> dp(N, vector<ll>(K + 1));

    dp[N - 1][1] = a[N - 1];
    for(int i = N - 2; i >= 0; i--) dp[i][1] = dp[i + 1][1] + a[i];

    for(int i = N - 2; i >= 0; i--) rep(k, 2, K + 1)
        dp[i][k] = a[i] * dp[i + 1][k - 1] + dp[i + 1][k];

    cout << dp[0][K] << endl;

    return 0;
}
