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
 * Problem Name: Tetration
 * Difficulty: 1.6 (Easy)
 * Categories: Math
 * Algorithms: 
 */

int main() {
    double N;
    cin >> N;

    printf("%.6f\n", pow(N, 1 / N));

    return 0;
}
