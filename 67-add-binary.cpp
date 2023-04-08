#include <iomanip>
#include <chrono>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // first approach
    string addBinary(string a,string b) {
        int carry{0},sum{0};
        string s;
        if(a.size()>=b.size()) {
            while(!a.empty()) {
                int na{0},nb{0};
                na=a.back()-'0';
                if(!b.empty()) {
                    nb=b.back()-'0';
                    b.pop_back();
                }
                sum=na+nb+carry;
                if(sum==2) {
                    sum=48; // is 0
                    carry=1;
                } else if(sum==1) {
                    sum=49; // is 1
                    carry=0;
                } else if(sum==3) {
                    sum=49; // is 1
                    carry=1;
                } else {
                    sum=48; // is 0
                    carry=0;
                }
                a.pop_back();
                s.insert(0,1,static_cast<char>(sum));
            }
        } else {
            while(!b.empty()) {
                int na{0},nb{0};
                if(!a.empty()) {
                    na=a.back()-'0';
                    a.pop_back();
                }
                nb=b.back()-'0';            
                sum=na+nb+carry;
                if(sum==2) {
                    sum=48; // is 0
                    carry=1;
                } else if(sum==1) {
                    sum=49; // is 1
                    carry=0;
                } else if(sum==3) {
                    sum=49; // is 1
                    carry=1;
                } else {
                    sum=48; // is 0
                    carry=0;
                }
                b.pop_back();
                s.insert(0,1,static_cast<char>(sum));
            }            
        }
        if(carry) s.insert(0,1,static_cast<char>(49));
        return s;
    }

    // LeetCode performing solution
    string addBinary2(string a, string b) {
        string ans;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            ans += carry % 2 + '0';
            carry /= 2;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};

int main() {                                                                                
    Solution solution;
    string 
    a{"1111"},
    b{"1111"};
    
    auto t1 = chrono::high_resolution_clock::now();   
    cout << solution.addBinary(a, b) << '\n';
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = t2 - t1;
    cout << setprecision(17) << ms_double.count() << " ms\n";

    return 0;   
}