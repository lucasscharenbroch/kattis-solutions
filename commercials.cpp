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
 * Problem Name: Radio Commercials
 * Difficulty: 1.8 (Easy)
 * Categories: 
 * Algorithms: Maximal Subarray (Kadane's)
 */

int main() {
    init_cin();

    int N, P;
    cin >> N >> P;
    vi prof(N);

    rep(i, 0, N) {
        cin >> prof[i];
        prof[i] -= P;
    }

    int curr = 0;
    int mx = 0;

    rep(i, 0, N) {
        if(curr < 0) curr = prof[i];
        else curr += prof[i];
        mx = max(mx, curr);
    }

    cout << mx << endl;

    return 0;
}
