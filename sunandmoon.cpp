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
 * Problem Name: Sun and Moon
 * Difficulty: 1.8 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int ds, ys, dm, ym;
    cin >> ds >> ys >> dm >> ym;

    ds = -ds; dm = -dm;

    while(ds < 0) ds += ys;
    while(dm < 0) dm += ym;

    while(ds != dm) {
        if(ds < dm) ds += ys;
        else dm += ym;
    }

    cout << ds << endl;

    return 0;
}
