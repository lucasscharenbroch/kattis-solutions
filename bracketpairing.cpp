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
 * Problem Name: Bracket Pairing
 * Difficulty: 6.3 (Hard)
 * Categories: Dynamic Programming
 * Algorithms: 
 */

char closer(char b) {
    switch(b) {
        case '(': return ')';
        case '[': return ']';
        case '{': return '}';
        case '<': return '>';
        default: return 0;
    }
}

ll num_matches(char a, char b) {
    if(a == '?' && b == '?') return 4;
    return ((a == '(' || a == '[' || a == '{' || a == '<') && (b == '?' || b == closer(a))) ||
           ((b == ')' || b == ']' || b == '}' || b == '>') && (a == '?' || closer(a) == b));
}

int main() {
    init_cin();

    string S;
    cin >> S;
    int N = sz(S);

    vector<vector<ll>> dp(N, vector<ll>(N)); // dp[i][j] = number of valid sequences S[i..=j]

    for(int n = 2; n <= N; n += 2) rep(i, 0, N - n + 1) {
        int j = i + n - 1;

        if(n == 2) { // base-case 2-length sequence
            dp[i][j] = num_matches(S[i], S[j]);
            continue;
        }

        // add sequences formed by both recursive rules
        dp[i][j] += num_matches(S[i], S[j]) * dp[i + 1][j - 1]; // match S[i] with S[j]
        dp[i][j] += num_matches(S[i], S[i + 1]) * dp[i + 2][j]; // match S[i] with S[i + 1]
        for(int k = i + 3; k <= j - 2; k += 2) { // match S[i] with S[k]
            dp[i][j] += num_matches(S[i], S[k]) * dp[i + 1][k - 1] * dp[k + 1][j];
        }
    }

    cout << dp[0][N - 1] << endl;

    return 0;
}
