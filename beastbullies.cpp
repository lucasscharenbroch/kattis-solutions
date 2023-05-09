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
 * Problem Name: Beast Bullies
 * Difficulty: 5.8 (Hard)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    vector<ll> strength(N);
    rep(i, 0, N) cin >> strength[i];

    sort(all(strength));

    vector<ll> suffix(N); // suffix sum
    suffix[N - 1] = strength[N - 1];
    for(int i = N - 2; i >= 0; i--) suffix[i] = suffix[i + 1] + strength[i];

    int result = 1;
    int i = N - 2;

    // assume all beasts in [i + 1, N - 1] will attack, and are safe from elimination
    while(i >= 0) {
        // find minimal group that beast i needs to protect
        ll att = suffix[i] - strength[i];
        ll def = strength[i];

        while(i > 0 && att > def) def += strength[--i];

        if(att > def) break; // no such group exists
        result = N - i;
        i--;
    }

    cout << result << endl;

    return 0;
}
