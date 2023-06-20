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
 * Problem Name: Creative Accounting
 * Difficulty: 5.5 (Hard)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, L, H;
    cin >> N >> L >> H;

    vi a(N);
    rep(i, 0, N) cin >> a[i];

    int res_min = INT_MAX, res_max = INT_MIN;

    // brute-force each segment size ss
    rep(ss, L, H + 1) {
        vi prof_counts(ss);

        ll sum = 0; // sum from (i - ss + 1) to i
        rep(i, 0, N + ss - 1) {
            if(i < N) sum += a[i];
            if(i >= ss) sum -= a[i - ss];

            if(sum > 0) prof_counts[(i + 1) % ss]++;
        }

        // set res_min and res_max to min and max of prof_counts
        rep(i, 0, ss) {
            res_min = min(res_min, prof_counts[i]);
            res_max = max(res_max, prof_counts[i]);
        }
    }

    cout << res_min << " " << res_max << endl;

    return 0;
}
