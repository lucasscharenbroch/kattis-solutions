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
 * Problem Name: Logland
 * Difficulty: 5.4 (Medium)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    int K;
    cin >> K;

    vector<ll> counts(K);
    rep(i, 0, K) cin >> counts[i];

    // always add the maximal amount to the next denomination in order to make
    // the next denomination have an even amount.
    rep(i, 0, K) {
        if(i == K - 1) {
            counts[i] %= 2;
            break;
        }

        int an = counts[i] / 2; // amount in next denomination
        counts[i] %= 2; // amount that has to be wasted

        counts[i + 1] += an;
        if(an) counts[i + 1] &= (-1 << 1); // don't upgrade next denomination to an odd number -
                                           // keep the coins instead
    }

    // counts is now filled with 1s and 0s - use modular arithmetic to compute
    // total amount wasted % m

    ll m = 1000000007;
    ll mod_mult = 1;
    ll result = 0;

    rep(i, 0, K) {
        result += (counts[i] * mod_mult) % m;
        result %= m;
        mod_mult *= 2;
        mod_mult %= m;
    }

    cout << result << endl;

    return 0;
}
