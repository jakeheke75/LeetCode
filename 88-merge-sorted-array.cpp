#include <iomanip>
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        // my submitted solution
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            size_t j = 0;
            for (size_t i = m+n-n; i < nums1.size(); ++i) {
                nums1[i] = nums2[j];
                ++j;
            }            
            sort(nums1.begin(), nums1.end());
        }

        // LeetCode "best performing" 0ms solution
        // again, the "best code performance check" of LeetCode is completely
        // flawed and misleading. With the same input vectors
        // my solution has a runtime of        0.003356 ms
        // LeetCode solution below has a rt of 0.0066470000000000001 ms
        // it can be already seen at naked eye that it is not optimized:
        // not taking advantage of standard c++ library functions and also
        // doing several not essential elaborations
        void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            vector<int> nums3=nums1;
            int i=0;int j=0;
            int k=0;
            while(i<m && j<n){
                if(nums3[i]<nums2[j]){
                    nums1[k]=nums3[i++];
                }
                else{
                    nums1[k]=nums2[j++];
                }
                k++;
            }
            while(i<m){
                nums1[k]=nums3[i++];
                  k++;
            }  
            while(j<n){
                nums1[k]=nums2[j++];
                k++;
            }
            // k++;
            }         
};

int main() {

    Solution sol;
    vector<int> nums1 {1,2,3,0,0,0};
    vector<int> nums2 {2,5,6};
    int m = 3;
    int n = 3;

/*     vector<int> nums1 {1};
    vector<int> nums2 {};
    int m = 1;
    int n = 0; */

/*     vector<int> nums1 {0};
    vector<int> nums2 {1};
    int m = 0;
    int n = 1; */

    auto t1 = std::chrono::high_resolution_clock::now();   
    sol.merge(nums1, m, nums2, n);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << std::setprecision(17) << ms_double.count() << " ms\n";
    
    for (int i : nums1)
        cout << i << " ";
    cout << '\n';

    return 0;

}