#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
// performance measure header
#include <iomanip>
#include <chrono>

using namespace std;

// first solution - wrong approach
/* class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> letters;
        int count{0}, max_odd{0};

        for (const char c : s)
            ++letters[c];

        for (const auto& c : letters)
            if (c.second % 2 == 0)
                count += c.second;
            else
                c.second > max_odd ? max_odd = c.second : max_odd = max_odd;
        return count + max_odd;
    }
}; */

// second solution - after checking the code of the master
/* class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> letters;
        int count{0};
        for (const char c : s)
            ++letters[c];
        for (const auto& c : letters)
            if (c.second % 2 == 0)
                count += c.second;
        return min(int(s.size()), count + 1);
    }
}; */

// solution from a master
/* class Solution {
public:
    int longestPalindrome(string s) {
        int odd{0};
        unordered_map<char, int>m;
        for(auto c : s)
            odd += m[c]++ % 2 ? -1 : 1;
        return min(s.size(), s.size() - odd + 1);
    }
}; */

// rewriting the master solution in order to understand all the steps
class Solution {
public:
    int longestPalindrome(string s) {
        int odd{0};
        unordered_map<char, int>m;
        sort(s.begin(), s.end());
        for (auto c : s)
            ++m[c];
        for (auto &val : m) {
            if (val.second % 2)
                odd += 1;
        }
        return min(s.size(), s.size() - odd + 1);
    }
};

int main() {                                                                                
    Solution solution;
    //string s{"civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"};
    string s;
    cout << "Insert a string: ";
    cin >> s;
    cout << s.size() << '\n';
    auto t1{chrono::high_resolution_clock::now()};
    cout << solution.longestPalindrome(s) << '\n';
    auto t2{chrono::high_resolution_clock::now()};
    chrono::duration<double, milli> ms_double{t2-t1};
    cout << setprecision(17) << ms_double.count() << " ms\n";
    sort(s.begin(), s.end());
    cout << s << '\n';
    return 0;   
}
