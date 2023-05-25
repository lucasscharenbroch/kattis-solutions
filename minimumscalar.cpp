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
 * Problem Name: Minimum Scalar Product
 * Difficulty: 2.4 (Easy)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    int T;
    cin >> T;

    rep(i, 0, T) {
        int N;
        cin >> N;

        vector<ll> a(N), b(N);
        rep(i, 0, N) cin >> a[i];
        rep(i, 0, N) cin >> b[i];

        sort(all(a));
        sort(all(b));

        ll result = 0;
        rep(i, 0, N) result += a[i] * b[N - 1 - i];

        cout << "Case #" << (i + 1) << ": " << result << endl;
    }

    return 0;
}
