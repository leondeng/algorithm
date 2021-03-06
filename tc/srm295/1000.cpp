#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


const int MAXN = 60;
const int MAXT = 1050;
int dp[MAXN][MAXT];
const int INF = 999999999;
int min_time[MAXN][MAXN];

class JimmyLightning {
    public:
        int robTheBank(vector <int> doors, vector <string> diamonds) {
            vector<int> d_value;
            vector<int> d_time;
            vector<int> d_room;
            for(int i=0; i<diamonds.size(); i++){
                istringstream is(diamonds[i]);
                int t;
                is>>t;
                d_value.push_back(t);
                is>>t;
                d_time.push_back(t);
                is>>t;
                d_room.push_back(t);
            }
            doors.insert(doors.begin(), INF);
            int n_room = doors.size();
            memset(dp, -1, sizeof(dp));

            for(int i=0; i<n_room; i++){
                min_time[i][i] = INF;
                for(int j=i+1; j<n_room; j++){
                    int t = INF; 
                    cout<<"i is "<<i<<" j is "<<j<<endl;
                    for(int k=i; k<=j; k++){
                        t = min(t, doors[k]);
                    }
                    min_time[i][j] = t;
                    min_time[j][i] = t;
                }
            }
            for(int i=0; i<n_room; i++){
                for(int j=0; j<n_room; j++){
                    cout<<min_time[i][j]<<"\t";
                }cout<<endl;
            }

            dp[0][0] = 0;
            int n_diamond = diamonds.size();
            int ans = -INF;
            for(int t=0; t<MAXT; t++){
                for(int i=0; i<n_room; i++){
                    if(dp[i][t]==-1)continue;
                    cout<<"in"<<" dp["<<i<<"]["<<t<<"]"<<endl;
                    for(int j=0; j<n_diamond; j++){
                        int to_room = d_room[j];
                        int t_min = min_time[i][to_room];
                        cout<<"t is "<<t<<" t_min is "<<t_min<<endl;
                        if( t_min <= t ){
                            continue;
                        }else{
                            cout<<"whoot"<<endl;
                            dp[to_room][t+d_time[j]] = max( dp[to_room][t+d_time[j]], dp[i][t]+d_value[j]);
                            cout<<"dp["<<to_room<<"]["<<t+d_time[j]<<"] = "<<dp[to_room][t+d_time[j]]<<endl;
                        }
                    }
                    //jump back to 0
                    if( min_time[i][0]>t  ){
                        ans = max(ans, dp[i][t]);
                    }
                }
            }
            return ans;
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <string> p1, bool hasAnswer, int p2) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p1[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    JimmyLightning *obj;
    int answer;
    obj = new JimmyLightning();
    clock_t startTime = clock();
    answer = obj->robTheBank(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p2 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p2;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    vector <int> p0;
    vector <string> p1;
    int p2;

    {
        // ----- test 0 -----
        int t0[] = {6};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"2 1 1"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 10;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }
    //return 0;
    {
        // ----- test 1 -----
        int t0[] = {1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"999 1 1"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 0;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {10,5,2};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"1 1 1","2 1 2","3 1 3"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 14;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
