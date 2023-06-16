#include <iomanip>
#include <chrono>
#include <iostream>
#include <string>

class Solution {
    // LeetCode best performing solution
    private: 
    char tolowerCase(char ch){
        if(ch >= 'a' && ch <= 'z'){
            return ch;
        }
        else {
            return ch-'A'+'a';
        }
    }

    bool valid(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            return 1;
        }
        else {
            return 0;
        }
    }    
    public:
    // my solution without using c++ STD library <cctype>
    bool isPalindrome(std::string s) {
        std::string t, r;
        for (auto itr = s.begin(); itr < s.end(); ++itr) {
            if ((static_cast<int>(*itr) >= 48 && static_cast<int>(*itr) <= 57) ||
                (static_cast<int>(*itr) >= 97 && static_cast<int>(*itr) <= 122)) {
                t.push_back(*itr);
                r.insert(0, 1, *itr);
            }
            else if (static_cast<int>(*itr) >= 65 && static_cast<int>(*itr) <= 90) {
                t.push_back(static_cast<int>(*itr)+32);
                r.insert(0, 1, static_cast<int>(*itr)+32);
            }   
        }
        return r == t ? true : false;
    }  
    // LeetCode best performing solution 
    bool isPalindrome2(std::string s) {
        int i=0;
        int j=s.size()-1;

        while(i<=j){
            if(valid(s[i])){
                if(valid(s[j])){
                    if(tolowerCase(s[i]) != tolowerCase(s[j])){
                        return false;
                    }
                    else{
                        i++;
                        j--;
                    }
                }
                // if j has to be ignored
                else{
                    j--;
                }
            } 
            //  if i has to be ignored
            else {
                i++;
            }
        }
        return true;
    }    
};

int main() {

    std::string s {"A man, a plan, a canal: Panama"};
    //std::cin >> s;
    Solution sol;

    auto t1 = std::chrono::high_resolution_clock::now();   
    bool ispal = sol.isPalindrome(s);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << std::setprecision(17) << ms_double.count() << " ms\n";
    
    std::cout << ispal << '\n';
    return 0;

}