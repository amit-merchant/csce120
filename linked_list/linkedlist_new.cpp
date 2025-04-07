#include <iostream>
using namespace std;

class node {
    public:
        int value;
        node *next;
    public:
        node (int val, node *ptr) : value(val), next(ptr) {}    
    };

class linkedlist {
    public:
        node *head;
    public:
        linkedlist () : head(nullptr){}
        void add(node *ref, int val) {
            node *newnode = new node(val, ref->next);
            ref->next = newnode;
        } // adds a new node with val after the node ref
        void remove(node *ref) {
            // holds the pointer of the node after the one targeted for deletion
            node *tmp = ref->next->next; 
            // deletes the target node, which is after the reference node
            delete ref->next;
            // restores the linked list
            ref->next = tmp;    
        } // removes the node after ref
        node* access(int val) {
            node* currnode = head;
            while (currnode != nullptr && currnode->value != val) {
                currnode = currnode->next;
            }
            return currnode;
        }
        void print() {
            node* currnode = head;
            while (currnode != nullptr) {
                cout << currnode->value << " ";
                currnode = currnode->next;
            }
            cout << endl;
        }
};

int main() {
    linkedlist ll;
    ll.head = new node(0,nullptr);
    ll.add(ll.head, 1);
    ll.add(ll.head->next, 2);
    ll.add(ll.head->next->next, 3);
    ll.add(ll.head->next->next->next, 4);
    ll.print();
    ll.remove(ll.head->next->next->next);
    ll.print();
    ll.add(ll.head->next->next->next, 5);
    ll.print();
    node* currnode = ll.access(3);
    ll.remove(currnode);
    ll.print();
}
