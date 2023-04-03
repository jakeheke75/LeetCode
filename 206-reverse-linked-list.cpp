#include <iostream>
#include <cstddef>
#include <vector>
#include <algorithm>
// performance measure header
#include <iomanip>
#include <chrono>
using namespace std;

// https://leetcode.com/problems/reverse-linked-list/
class ListNode {
    public:
        int data;
        ListNode* next;

        ListNode(int d) 
        : data{d}, next{NULL} {}
};

class Solution {
    public:
        ListNode* insert(ListNode* head, int data) {
            if (head == NULL)
                head = new ListNode(data);
            else {
                ListNode* tail {head};
                while (tail && tail->next != NULL)
                    tail = tail->next;
                tail->next = new ListNode(data);
            }
            return head;
        }

        void display(ListNode* head) {
            ListNode* start = head;
            while (start) {
                cout << start->data << " ";
                start = start->next;
            }
        }
        // my proposed solution
/*         ListNode* reverseList(ListNode* head) {
            ListNode *start{NULL}, *next{NULL};
            vector<int> values;
            while (head) {
                values.push_back(head->data);
                head = head->next;
            }
            // this is for avoiding the LeetCode Clang compiler sanitizer error
            // Line 1034: Char 9: runtime error: reference binding to null pointer of type 'int' 
            // (stl_vector.h) SUMMARY: UndefinedBehaviorSanitizer:
            if (!values.empty()) {
                start = new ListNode(values[values.size()-1]);
                next = start;
                for (auto rit=values.rbegin()+1; rit<values.rend(); rit++) {
                    next->next = new ListNode(*rit);
                    next = next->next;
                }
            }
            return start;
        } */

        // another performing solution
        ListNode* reverseList(ListNode* head) {
            ListNode* next=NULL;
            ListNode* prev=NULL;
            while(head!=NULL)
            {
                next=head->next;
                head->next=prev;
                prev=head;
                head=next;
            }
            return prev;
        }
};

int main() {
	ListNode* head {NULL};
  	Solution mylist;
    int T, data;

    cout << "Insert nodes of the first list\n";
    cin >> T;
    while (T-- > 0) {
        cin >> data;
        head = mylist.insert(head, data);
    }

    // performance measure
    auto t1 {chrono::high_resolution_clock::now()};
    ListNode* headReversed {mylist.reverseList(head)};
    auto t2 {chrono::high_resolution_clock::now()};
    chrono::duration<double, milli> ms_double {t2 - t1};
    cout << setprecision(17) << ms_double.count() << " ms\n";    

 	mylist.display(headReversed);
    cout << '\n';
    return 0;	
}