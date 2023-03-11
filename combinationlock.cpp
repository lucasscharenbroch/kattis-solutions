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
 * Problem Name: Combination Lock
 * Difficulty: 3.0 (Medium)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N1, N2, N3, N4;

    while(true) {
        cin >> N1 >> N2 >> N3 >> N4;
        if(N1 == 0 && N2 == 0 && N3 == 0 && N4 == 0) break;

        int num_marks = 40 * 3; // number of marks crossed

        num_marks += (N1 - N2 + 40) % 40;
        num_marks += (N3 - N2 + 40) % 40;
        num_marks += (N3 - N4 + 40) % 40;

        cout << num_marks * 360 / 40 << endl;
    }

    return 0;
}
