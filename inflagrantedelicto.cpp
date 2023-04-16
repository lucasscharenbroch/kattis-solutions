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
 * Problem Name: In Flagrange Delicto
 * Difficulty: 4.7 (Medium)
 * Categories: Dynamic Programming
 * Algorithms: Longest Increasing Subsequence
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    vi p(N), d(N);

    rep(i, 0, N) cin >> p[i];
    rep(i, 0, N) cin >> d[i];

    // let a be the array where a[i] is the index of p[i] in d.
    // the length of the LCS of p and d is equivalent to the length of
    // the LIS in a.

    // fill a
    vi a(N);
    unordered_map<int, int> idx; // {elem-in-d : index-in-d}
    rep(i, 0, N) idx[d[i]] = i;
    rep(i, 0, N) a[i] = idx[p[i]];

    // LIS
    int longest = 0;
    vi last_idx(N);

    rep(i, 0, N) {
        // binary search for largest index with smaller elem
        int l = 0, r = longest;
        while(l < r) {
            int m = (l + r) / 2;
            if(a[last_idx[m]] < a[i]) l = m + 1;
            else r = m;
        }

        longest = max(longest, l + 1);
        last_idx[l] = i;
    }

    cout << "2 " << longest + 1 << endl;

    return 0;
}
