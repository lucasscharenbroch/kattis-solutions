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
 * Problem Name: Astrological Sign
 * Difficulty: 2.2 (Easy)
 * Categories: 
 * Algorithms: 
 */

int JAN = 0;
int FEB = JAN + 31;
int MAR = FEB + 29;
int APR = MAR + 31;
int MAY = APR + 30;
int JUN = MAY + 31;
int JUL = JUN + 30;
int AUG = JUL + 31;
int SEP = AUG + 31;
int OCT = SEP + 30;
int NOV = OCT + 31;
int DEC = NOV + 30;

int month_str_to_int(string m) {
    if(m == "Jan") return JAN;
    if(m == "Feb") return FEB;
    if(m == "Mar") return MAR;
    if(m == "Apr") return APR;
    if(m == "May") return MAY;
    if(m == "Jun") return JUN;
    if(m == "Jul") return JUL;
    if(m == "Aug") return AUG;
    if(m == "Sep") return SEP;
    if(m == "Oct") return OCT;
    if(m == "Nov") return NOV;
    if(m == "Dec") return DEC;
    assert(false);
}

int main() {
    init_cin();

    int T;
    cin >> T;

    while(T--) {
        int D;
        string M;

        cin >> D >> M;
        D += month_str_to_int(M);
        D --; // shift day to 0-indexing

        string result;

        if(D < 20) result = "Capricorn";
        else if(D < FEB + 19) result = "Aquarius";
        else if(D < MAR + 20) result = "Pisces";
        else if(D < APR + 20) result = "Aries";
        else if(D < MAY + 20) result = "Taurus";
        else if(D < JUN + 21) result = "Gemini";
        else if(D < JUL + 22) result = "Cancer";
        else if(D < AUG + 22) result = "Leo";
        else if(D < SEP + 21) result = "Virgo";
        else if(D < OCT + 22) result = "Libra";
        else if(D < NOV + 22) result = "Scorpio";
        else if(D < DEC + 21) result = "Sagittarius";
        else result = "Capricorn";

        cout << result << endl;
    }

    return 0;
}
