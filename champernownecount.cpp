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
 * Problem Name: Champernowne Count
 * Difficulty: 3.1 (Medium)
 * Categories: Modular Arithmetic
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, K;
    cin >> N >> K;

    int count = 0;
    ll cmodk = 0; // current champernowne word, mod k
    ll mult = 10; // multipier (10^(1 + floor(log(i))))

    rep(i, 1, N + 1) {
        if(i % mult == 0) mult *= 10;

        cmodk *= mult % K;
        cmodk += i % K;
        cmodk %= K;

        if(cmodk == 0) count++;
    }

    cout << count << endl;

    return 0;
}
