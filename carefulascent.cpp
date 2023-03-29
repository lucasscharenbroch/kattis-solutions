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
 * Problem Name: Careful Ascent
 * Difficulty: 2.1 (Easy)
 * Categories: Math
 * Algorithms: 
 */

int main() {
    int FFX, FFY, N;
    cin >> FFX >> FFY >> N;

    double normal_height = FFY;
    double denominator = 0;

    rep(i, 0, N) {
        double l, u, f;
        cin >> l >> u >> f;

        double shield_height = u - l;
        normal_height -= shield_height;
        denominator += shield_height * f;
    }

    denominator += normal_height;

    printf("%.7f\n", (FFX / denominator));

    return 0;
}
