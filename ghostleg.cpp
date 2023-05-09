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
 * Problem Name: Ghost Leg
 * Difficulty: 1.4 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, M;
    cin >> N >> M;

    vi a(M);

    rep(i, 0, M) cin >> a[i];

    vi result(N);

    rep(i, 0, N) {
        int r = i; // current vertical rung

        rep(j, 0, M) {
            if(r == a[j]) r--;
            else if(r == a[j] - 1) r++;
        }

        result[r] = i;
    }

    rep(i, 0, N) cout << (result[i] + 1) << endl;

    return 0;
}
