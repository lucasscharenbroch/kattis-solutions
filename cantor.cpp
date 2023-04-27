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
 * Problem Name: Cantor
 * Difficulty: 2.9 (Medium)
 * Categories: Math
 * Algorithms: 
 */

int main() {
    init_cin();

    while(true) {
        string s;
        cin >> s;
        if(s == "END") break;
        double d = stod(s);
        int num = d * 1e6, denom = 1e6;

        unordered_map<int, bool> seen; // seen numerators
        int num_ones = 0;
        int last = -1; // last digit in representation

        while(num && !seen[num]) {
            seen[num] = true;
            if((last = num / denom) == 1) num_ones++;
            num = (num % denom) * 3;
        }

        if(num_ones > (last == 1 && num_ones == 1 && num == 0)) cout << "NON-MEMBER" << endl;
        else cout << "MEMBER" << endl;
    }

    return 0;
}
