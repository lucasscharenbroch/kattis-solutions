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
 * Problem Name: Class Field Trip
 * Difficulty: 1.4 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    string a, b;
    cin >> a >> b;

    a += 'z' + 1; // sentinal value
    b += 'z' + 1; // sentinal value

    int i = 0, j = 0;
    string result;

    while(i != sz(a) - 1 || j != sz(b) - 1) {
        result += min(a[i], b[j]);
        if(a[i] < b[j]) i++;
        else j++;
    }

    cout << result << endl;

    return 0;
}
