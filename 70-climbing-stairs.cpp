#include <iomanip>
#include <chrono>

#include <iostream>

using namespace std;

class Solution {
public:
    // first attempt
    int climbStairs(int n) {
        int res;
        if(n==1)
            res=1;
        else if(n==2)
            res=2;
        else {
            int i=2, n2=1, n1=2;
            while(++i<=n) {
                res=n1+n2;
                n2=n1;
                n1=res;
            }
        }
        return res;
    }        
};

int main() {                                                                                
    Solution solution;
    int x;
    cin >> x;
    
    auto t1 = chrono::high_resolution_clock::now();   
    cout << solution.climbStairs(x) << '\n';
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = t2 - t1;
    cout << setprecision(17) << ms_double.count() << " ms\n";

    return 0;   
}