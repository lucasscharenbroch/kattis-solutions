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
 * Problem Name: Malfunctioning Robot
 * Difficulty: 3.2 (Medium)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int T;
    cin >> T;

    while(T--) {
        ll x0, y0, x, y;
        cin >> x0 >> y0 >> x >> y;

        x -= x0, y -= y0; // center x0 and y0 at zero
        x = abs(x), y = abs(y); // take abs of x and y (reflection has same distance)

        ll result = 2 * min(x, y);
        x -= result / 2, y -= result / 2; // subtract common term

        ll n = max(x, y); // distance in remaining direction
        result += 3 * (n / 2) + (n + 1) / 2; // zig-zag walk to target

        cout << result << endl;
    }

    return 0;
}
