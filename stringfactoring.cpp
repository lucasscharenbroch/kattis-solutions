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
 * Problem Name: String Factoring
 * Difficulty: 4.9 (Medium)
 * Categories: Dynamic Programming
 * Algorithms: 
 */

vector<vi> memo;
vector<vi> num_rep; // num_rep[l][r] = number of subsequent repetitions of S[l...r]

int solve(int l, int r) {
    if(memo[l][r] != -1) return memo[l][r];

    int sub_sz = r - l + 1;

    // three cases:
    //  (1) no factoring
    //  (2) factor into two parts
    //  (3) factor entire string

    int& smallest = memo[l][r] = r - l + 1; // (1)

    rep(i, l, r) smallest = min(smallest, solve(l, i) + solve(i + 1, r)); // (2)

    // (3)
    rep(i, l, r) {
        int rep_sz = i - l + 1;
        if(sub_sz % rep_sz || sub_sz > rep_sz * num_rep[l][i]) continue;
        smallest = min(smallest, solve(l, i));
    }

    return smallest;
}

int main() {
    init_cin();

    string S;
    cin >> S;

    memo.assign(sz(S), vi(sz(S), -1));
    num_rep.assign(sz(S), vi(sz(S), 0));

    // calculate num_rep
    rep(l, 0, sz(S)) rep(r, l, sz(S)) {
        int sub_sz = r - l + 1;
        for(int i = 0; i + l < sz(S); i++) {
            if(S[i + l] != S[l + i % sub_sz]) break;
            if((i + 1) % sub_sz == 0) num_rep[l][r]++; // one rep completed
        }
    }

    cout << solve(0, sz(S) - 1) << endl;

    return 0;
}
