#include <iomanip>
#include <chrono>

#include <iostream>

using namespace std;

class Solution {
public:
    // first attempt: time limit exceeded
/*     int mySqrt(int x) {
        if(x==1) return 1; // corner case;
        long long y{x/2};
        while(y*y>x) // all the other cases
            --y;
        return y;
    } */
    // second attemp with binary approach    
    int mySqrt(int x) {
        if(x==1) return 1; // corner case;
        long long y{x/2};
        while(y*y>x)
            y/=2;
        while((y+1)*(y+1)<=x)
            ++y;
        return y;
    }
    // LeetCode most performing solution
    int mySqrt2(int x) {    
        unsigned long int mid,s=0,e=x,ans;
        while(s<=e){
            mid=(s+e)/2;
            if(mid*mid>x){
                e=mid-1;
            }
            else{
                ans=mid;
                s=mid+1;
            }
        }
        return ans;
    }   
};

int main() {                                                                                
    Solution solution;
    int x;
    cin >> x;
    
    auto t1 = chrono::high_resolution_clock::now();   
    cout << solution.mySqrt(x) << '\n';
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = t2 - t1;
    cout << setprecision(17) << ms_double.count() << " ms\n";

    return 0;   
}