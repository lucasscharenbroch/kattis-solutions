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
 * Problem Name: Batmanacci
 * Difficulty: 3.1
 * Categories: Divide and Conquer
 * Algorithms: 
 */

int main() {
    init_cin();

    vector<ll> fib(2, 1);

    // fill fibonacci until ll overfows
    for(int i = 2; fib[i - 2] + fib[i - 1] > 0; i++) fib.push_back(fib[i - 2] + fib[i - 1]);

    ll N, K;
    cin >> N >> K;
    N--;

    // reduce N to 0 or 1 ('N' and 'A', respectively)
    while(N > 1) {
        if(N - 2 >= sz(fib)) { // K must be in first part of string
            N -= 2;
            continue;
        }

        if(K > fib[N - 2]) {
            K -= fib[N - 2];
            N--;
        } else {
            N -= 2;
        }
    }

    cout << (N ? 'A' : 'N') << endl;

    return 0;
}
