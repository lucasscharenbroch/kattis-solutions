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
 * Problem Name: Ultimate Binary Watch
 * Difficulty: 1.7 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    int N;
    cin >> N;

    for(int i = 3; i >= 0; i--) {
        char hr_tens = (((N / 1000 % 10) >> i) & 1) ? '*' : '.';
        char hr_ones = (((N / 100 % 10) >> i) & 1) ? '*' : '.';
        char min_tens = (((N / 10 % 10) >> i) & 1) ? '*' : '.';
        char min_ones = (((N % 10) >> i) & 1) ? '*' : '.';

        printf("%c %c   %c %c\n", hr_tens, hr_ones, min_tens, min_ones);
    }

    return 0;
}
