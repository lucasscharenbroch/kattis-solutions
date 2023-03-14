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
 * Problem Name: Pawn Shop
 * Difficulty: 3.6 (Medium)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    vi a(N), b(N);

    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N) cin >> b[i];

    unordered_map<int, int> diff; // diff[x] = y => a[...i] contains y more of x than b[...i]
    int num_diff = 0; // total number of mismatched elements between a and b

    rep(i, 0, N) {
        cout << b[i];
        if(i == N - 1) break;
        cout << " ";

        if(a[i] != b[i]) {
            if(++diff[a[i]] > 0) num_diff++;
            else num_diff --;
            if(--diff[b[i]] < 0) num_diff++;
            else num_diff--;
        }

        if(num_diff == 0) cout << "# ";
    }

    cout << endl;

    return 0;
}
