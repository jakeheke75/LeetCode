#include <vector>
#include <iostream>
using namespace std;

// another genius
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int temp = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
        }

        for(int j=0 ; j < nums.size() ; j++){
            sum -= nums[j];
            if(sum == temp){return j;
            break;
            }
            temp += nums[j];
        }
        return -1;
    }
};

// the wonderful winner!!!!
/* class Solution {
public:
    int sum(vector<int> &nums){
        int sum  =0;
        for(int i =1;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum;
    }
    int pivotIndex(vector<int>& nums) {
        int ls = 0;
        int rs = sum(nums);
        for(int i=0;i<nums.size();i++){
            if(i==0){
                ls+=0;
                rs-=0;
            }
            else{
                ls+=nums[i-1];
                rs-=nums[i];
            }
            if(ls==rs){
                return i;
            }
        }
        return -1;
    }
}; */

// 4 call functions
/* class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        for (size_t pivot = 0; pivot < nums.size(); pivot++) {   
            int leftSum {0};
            int rightSum {0};
            if (pivot == 0) {
                for (size_t index = pivot; index < nums.size()-1; index++)
                    rightSum += nums[index+1];
            } else {
                for (size_t index = pivot; index > 0; index--)
                    leftSum += nums[index-1];
                for (size_t index = pivot; index < nums.size()-1; index++)
                    rightSum += nums[index+1];                
            }
            if (leftSum == rightSum)
                return pivot;
        }
        return -1;
    }
}; */

// 1 call function and 2 operations
/* class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        size_t size {nums.size()};
        if (size == 1)
            return 0;
        for (size_t pivot = 0; pivot < size; pivot++) {    
            int leftSum {0};
            int rightSum {0};
            if (pivot == 0) {
                for (size_t index = pivot; index < size-1; index++)
                    rightSum += nums[index+1];
            } else {
                for (size_t index = pivot; index > 0; index--)
                    leftSum += nums[index-1];
                for (size_t index = pivot; index < size-1; index++)
                    rightSum += nums[index+1];                
            }
            if (leftSum == rightSum)
                return pivot;
        }
        return -1;
    }
}; */

// 1 call function and 1 operation
/* class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        size_t size {nums.size()};
        size_t end {size-1};
        if (size == 1)
            return 0;
        for (size_t pivot = 0; pivot < size; pivot++) {    
            int leftSum {0};
            int rightSum {0};
            if (pivot == 0) {
                for (size_t index = pivot; index < end; index++)
                    rightSum += nums[index+1];
            } else {
                for (size_t index = pivot; index > 0; index--)
                    leftSum += nums[index-1];
                for (size_t index = pivot; index < end; index++)
                    rightSum += nums[index+1];                
            }
            if (leftSum == rightSum)
                return pivot;
        }
        return -1;
    }
}; */

int main() {                                                                                
    Solution solution;
/*     int n;
    cin >> n;
    vector<int> nums;
    int counter {n};    
    while (counter-- > 0) {
        cin >> n;
        nums.push_back(n);
    } */
    vector<int> nums {1,7,3,6,5,6};
    //vector<int> nums {1,2,3};
    //vector<int> nums {2,1,-1};
    //vector<int> nums {1,1,2,1,1};
    //vector<int> nums {1};
    //vector<int> nums {0};
    //vector<int> nums {-1,-1,-1,3,1};    
    cout << solution.pivotIndex(nums) << '\n';
    return 0;   
}

/* [1,7,3,6,5,6]
[1,2,3]
[2,1,-1]
[1,1,2,1,1]
[1]
[0]
[-1,-1,-1,3,1] */