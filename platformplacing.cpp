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
 * Problem Name: Platform Placing
 * Difficulty: 4.9 (Medium)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, S, K;
    cin >> N >> S >> K;
    S *= 2, K *= 2;

    vector<ll> pts(N);

    rep(i, 0, N) {
        cin >> pts[i];
        pts[i] *= 2;
    }

    sort(all(pts));

    ll result = 0;
    ll last_size = 0;

    rep(i, 0, N) {
        ll dist_last = (i == 0) ? LLONG_MAX : pts[i] - pts[i - 1] - last_size / 2;
        ll dist_next = (i == N - 1) ? LLONG_MAX : pts[i + 1] - (S / 2) - pts[i];
        ll max_sz = K / 2;
        ll size = 2 * min(min(dist_last, dist_next), max_sz);

        if(size < S) { // impossible to place this platform
            cout << -1 << endl;
            return 0;
        }

        result += size;
        last_size = size;
    }

    cout << (result / 2) << endl;

    return 0;
}
