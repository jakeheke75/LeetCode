#include <iomanip>
#include <chrono>
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode()
    : val(0), next(nullptr) {}
    ListNode(int x)
    : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next)
    : val(x), next(next) {}
};

class Solution {
    public:
      ListNode* insert(ListNode* head, int val) {
        if (head == nullptr)
            head = new ListNode(val);
        else {
            ListNode* tail = head;
            while (tail && tail->next != nullptr)
                tail = tail->next;
            tail->next = new ListNode(val);
        }
        return head;
      }

      void display(ListNode* head) {
        ListNode* start = head;
        while (start) {
            std::cout << start->val << " ";
            start = start->next;
        }
      }
      
      // first attempt
      ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* first = head;
        ListNode* temp = head;
        int pval = head->val;
        head = head->next;
        while (head) {
            if (head->val != pval) {
                pval = head->val;
                temp = head;
            }
            else {
                temp->next = head->next;
            }
            head = head->next;
        }
        return first;
      }
      // LeetCode best performing solution WRONG
      // with a linked list of 5 elements {1 1 2 3 3 }
      // the measured runtime is: 0.001289 ms
      // my solution is faster:   0.00092000000000000003 ms
      ListNode* deleteDuplicates2(ListNode* head) {
        ListNode *ans = new ListNode(0);
        ListNode *curr = ans;
        while(head) {
            while(head->next && head -> val == head -> next -> val)
            head =head -> next;
            curr -> next = head;
            curr = head;
            head = head -> next;
        }
        return ans->next;        
      }      
};

int main() {

	ListNode* head = nullptr;
  	Solution sol;
    int n, val;
    std::cin >> n;
    while (n-- > 0) {
        std::cin >> val;
        head = sol.insert(head, val);
    }	
	
    auto t1 = std::chrono::high_resolution_clock::now();   
    head = sol.deleteDuplicates(head);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << std::setprecision(17) << ms_double.count() << " ms\n";
    
    sol.display(head);
    return 0;

}