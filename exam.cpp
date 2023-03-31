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
 * Problem Name: Exam
 * Difficulty: 1.8 (Easy)
 * Categories: DP
 * Algorithms: 
 */

int main() {
    init_cin();

    int matched, mismatched;
    string S1, S2;
    cin >> matched >> S1 >> S2;
    mismatched = sz(S1) - matched;

    int result = 0;

    rep(i, 0, sz(S1)) {
        if(S1[i] == S2[i]) {
            if(!matched) continue;
            matched--, result++;
        } else {
            if(!mismatched) continue;
            mismatched--, result++;
        }
    }

    cout << result << endl;

    return 0;
}
