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
 * Problem Name: 1's For All
 * Difficulty: 7.2 (Hard)
 * Categories: Dynamic Programming
 * Algorithms: 
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    vi dp(N + 1, INT_MAX);
    dp[1] = 1;

    rep(i, 2, N + 1) {
        rep(j, 1, i / 2 + 1) { // addition
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }

        rep(j, 2, (int) sqrt(i) + 1) { // multiplication
            if(i % j) continue;
            dp[i] = min(dp[i], dp[j] + dp[i / j]);
        }

        // concatenation
        int left = i / 10, right = i % 10, multiplier = 10;
        while(left) {
            if(right / (multiplier / 10)) { // only concatenate when right has no leading zeroes
                dp[i] = min(dp[i], dp[left] + dp[right]);
            }

            right += multiplier * (left % 10);
            left /= 10;
            multiplier *= 10;
        }
    }

    cout << dp[N] << endl;

    return 0;
}
