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
 * Problem Name: Metronome
 * Difficulty: 1.3 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    double x;
    cin >> x;
    cout << (x / 4) << endl;

    return 0;
}
