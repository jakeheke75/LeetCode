#include <iostream>
#include <cstddef>
#include <vector>
#include <algorithm>
// performance measure header
#include <iomanip>
#include <chrono>
using namespace std;

// https://leetcode.com/problems/merge-two-sorted-lists/
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
               
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode *head{NULL}, *tail{NULL};
            vector<int> values;
            while (list1) {
                values.push_back(list1->data);
                list1 = list1->next;
            }
            while (list2) {
                values.push_back(list2->data);
                list2 = list2->next;
            }
            sort(values.begin(), values.end());
            head = new ListNode(values[0]);
            tail = head;
            for (size_t i = 1; i < values.size(); i++) {
                tail->next = new ListNode(values[i]);                
                tail = tail->next;
            }
            return head;
        }
};

int main() {
	ListNode* head1 {NULL};
	ListNode* head2 {NULL};
  	Solution mylist1, mylist2;
    int T, data;

    cout << "Insert nodes of the first list\n";
    cin >> T;
    while (T-- > 0) {
        cin >> data;
        head1 = mylist1.insert(head1, data);
    }
    cout << "Insert nodes of the second list\n";
    cin >> T;
    while (T-- > 0) {
        cin >> data;
        head2 = mylist2.insert(head2, data);
    }

    auto t1 {chrono::high_resolution_clock::now()};
    ListNode* headMerged {mylist1.mergeTwoLists(head1, head2)};
    auto t2 {chrono::high_resolution_clock::now()};
    chrono::duration<double, milli> ms_double {t2 - t1};
    cout << setprecision(17) << ms_double.count() << " ms\n";    

 	mylist1.display(headMerged);
    cout << '\n';
    return 0;	
}