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
 * Problem Name: Yoda
 * Difficulty: 2.1 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    ll N, M;
    cin >> N >> M;

    ll new_N = 0, new_M = 0;
    ll mult_N = 1, mult_M = 1;
    int num_digits = 0;
    int num_digits_knocked_N = 0;
    int num_digits_knocked_M = 0;
    
    while(N != 0 || M != 0) {
        if(N % 10 > M % 10) {
            num_digits_knocked_M++;
            new_N += mult_N * (N % 10);
            mult_N *= 10;
        } else if(M % 10 > N % 10) {
            num_digits_knocked_N++;
            new_M += mult_M * (M % 10);
            mult_M *= 10;
        } else {
            new_N += mult_N * (N % 10);
            new_M += mult_M * (M % 10);
            mult_N *= 10, mult_M *= 10;
        }

        N /= 10, M /= 10;
        num_digits++;
    }

    if(num_digits_knocked_N == num_digits) cout << "YODA" << endl;
    else cout << new_N << endl;

    if(num_digits_knocked_M == num_digits) cout << "YODA" << endl;
    else cout << new_M << endl;

    return 0;
}
