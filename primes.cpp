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
 * Problem Name: Peculiar Primes
 * Difficulty: 6.2 (Hard)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    while(true) {
        int N;
        cin >> N;
        if(N == 0) return 0;

        vector<ll> a = {1};
        vi primes(N);
        vi mul_indices(N, 0); // next index in a that each prime should be multiplied by
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q; // {amount, index-of-prime-in-primes-vector}

        rep(i, 0, N) {
            cin >> primes[i];
            q.push(pair<ll, ll>(primes[i], i));
        }

        ll X, Y;
        cin >> X >> Y;

        pair<ll, ll> curr;
        while((curr = q.top()).first <= Y) { // generate products up to Y
            ll prod = curr.first, prime_idx = curr.second; q.pop();

            if(a.back() != prod) a.push_back(prod);

            q.push(pair<ll, ll>(primes[prime_idx] * a[++mul_indices[prime_idx]], prime_idx));
        }

        int num_printed = 0;

        for(auto it = upper_bound(a.begin(), a.end(), X - 1); it != a.end(); it++) {
            if(num_printed) cout << ",";
            num_printed++;
            cout << *it;
        }

        if(num_printed) cout << endl;
        else cout << "none" << endl;
    }

}
