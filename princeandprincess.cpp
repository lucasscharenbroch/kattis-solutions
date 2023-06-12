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
 * Problem Name: Prince and Princess
 * Difficulty: 5.6 (Hard)
 * Categories: Dynamic Programming
 * Algorithms: LIS
 */

int main() {
    init_cin();

    int T;
    cin >> T;

    rep(t, 1, T + 1) {
        int N, P, Q;
        cin >> N >> P >> Q;
        P++, Q++;

        vi p(P), q(Q);

        rep(i, 0, P) cin >> p[i];
        rep(i, 0, Q) cin >> q[i];

        // remove all non-intersecting cells from p and q
        vi p_idx(N * N + 1, -1), q_idx(N * N + 1, -1);
        rep(i, 0, P) p_idx[p[i]] = i;
        rep(i, 0, Q) q_idx[q[i]] = i;

        vi new_p, new_q;
        rep(i, 0, P) if(q_idx[p[i]] != -1) {
            p_idx[p[i]] = sz(new_p);
            new_p.push_back(p[i]);
        }
        rep(i, 0, Q) if(p_idx[q[i]] != -1) {
            q_idx[q[i]] = sz(new_q);
            new_q.push_back(q[i]);
        }
        p = new_p, q = new_q;

        // create mapping m[i] = q_idx[p[i]]
        vi m(sz(p));
        rep(i, 0, sz(m)) m[i] = q_idx[p[i]];

        // find LIS of m
        int longest = 0;
        vi dp(sz(m) + 1); // dp[i] = minimal element ending a subsequence of size i
        dp[0] = -1;
        rep(i, 0, sz(m)) {
            // binary search for insertion point (largest index in m with smaller element)
            int l = 0, r = longest;
            while(l < r) {
                int mid = (l + r + 1) / 2;
                if(dp[mid] < m[i]) l = mid;
                else r = mid - 1;
            }

            l++;
            dp[l] = m[i];
            longest = max(longest, l);
        }

        cout << "Case " << t << ": " << longest << endl;
    }

    return 0;
}
