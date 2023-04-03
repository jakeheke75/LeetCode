#include <iostream>
#include <cstddef>
#include <vector>
using namespace std;

// https://leetcode.com/problems/middle-of-the-linked-list/
class Node {
    public:
        int data;
        Node* next;

        Node(int d) {
            data = d;
            next = NULL;
        }
};

class Solution {
    public:
      Node* insert(Node* head, int data) {
          if (head == NULL)
              head = new Node(data);
          else {
              Node* tail {head};
              while (tail && tail->next != NULL)
                  tail = tail->next;
              tail->next = new Node(data);
          }
          return head;
      }

      void display(Node* head) {
          Node* start = head;
          while (start) {
              cout << start->data << " ";
              start = start->next;
          }
      }

      // LeetCode method
      // ListNode* middleNode(ListNode* head)
      Node* middleNode(Node* head) {
          vector<Node*> nodes;
          Node* start {head};
          while (start) {
              nodes.push_back(start);
              start = start->next;
          }
          size_t elements {nodes.size()};
          return elements % 2 == 0 ? nodes[elements / 2] : nodes[(elements - 1) / 2];
      }
};

int main() {
	Node* head = NULL;
  	Solution mylist;
    int T, data;
    cin >> T;
    while (T-- > 0) {
        cin >> data;
        head = mylist.insert(head, data);
    }	
	mylist.display(head);
    cout << '\n';
    // middle node return
    Node* head2 {mylist.middleNode(head)};
    mylist.display(head2);
    cout << '\n';
    return 0;	
}