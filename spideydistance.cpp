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
 * Problem Name: Spidey Distance
 * Difficulty: 6.4 (Hard)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    ll dt, ds;
    cin >> dt >> ds;

    ll s_diag = (2 * ds) / 3;
    ll t_diag = dt / 2;

    if(t_diag > s_diag) {
        cout << 1 << endl;
        return 0;
    }

    ll t_inner = 0, s_inner = 0;

    rep(i, 1, s_diag + 1) {
        ll s = ds - (3 * i + 1) / 2;
        ll t = max(0LL, min(s, dt - 2 * i));

        s_inner += s;
        t_inner += t;
    }

    ll num = 1 + 4 * t_diag + 4 * min(dt, ds) + 8 * t_inner;
    ll denom = 1 + 4 * s_diag + 4 * ds + 8 * s_inner;

    // reduce (num / denom) fraction
    while(num && gcd(num, denom) > 1) {
        ll cd = gcd(num, denom);

        num /= cd;
        denom /= cd;
    }

    if(num == denom) cout << 1 << endl;
    else cout << num << "/" << denom << endl;

    return 0;
}
