#include <iostream>
#include <cstddef>
#include <vector>
#include <algorithm>
// performance measure header
#include <iomanip>
#include <chrono>

// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

class Node {
  public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) 
    : val{_val} {}
    Node(int _val, vector<Node*> _children)
    : val{_val}, children{_children} {}
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
    Node* create
        
    vector<int> preorder(Node* root) {
    }
};

int main() {

    int levels, first_val, val, children;
    std::cout << "Insert the number of levels of the tree: ";
    std::cin >> levels;
    std::cout << "Insert the value of the first node of the tree: ";
    std::cin >> first_val;
    std::cout << "Insert the number of children: ";
    std::cin >> children;
    while (--levels > 1) {

        
    }




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