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
 * Problem Name: Divisible Subsequences
 * Difficulty: 3.5 (Medium)
 * Categories: DP
 * Algorithms: 
 */

int main() {
    init_cin();

    int C;
    cin >> C;

    while(C--) {
        ll D, N;
        cin >> D >> N;

        vector<ll> sums(D); // stores current sums of each "substring" that ends 
                            // with in the current number.
                            // instead of shifting elements in sums to check
                            // for divisibility, all sums are effectively
                            // shifted at once by changing the index (i) at which
                            // sums[i] = number of sums considered divisible by D

        ll i = 0; // i starts as 0
        ll result = 0;

        while(N--) {
            ll n;
            cin >> n;

            sums[i]++; // add "0" to the sums (which will be shifted up by n to
                       // represent the sum of the single element, n)

            i -= n; // "shift" all elements up by n
            while(i < 0) i += D; // adjust i if it fell off the array

            result += sums[i]; // add all divisible sums that end with n
        }

        cout << result << endl;
    }

    return 0;
}
