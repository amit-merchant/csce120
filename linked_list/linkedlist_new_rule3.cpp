#include <iostream>
using namespace std;

class node {
    public:
        int value;
        node *next;
    public:
        node (int val, node *ptr) : value(val), next(ptr) {}    
        node (int val) : value(val), next(nullptr) {}    
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
            node *tmp = ref->next->next;
            delete ref->next;
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
        ~linkedlist() {
            node* currnode = head;
            while (currnode != nullptr) {
                node* tmp = currnode;
                currnode = currnode->next;
                delete tmp;
            }
            head = nullptr;
        } // destructor
        linkedlist(const linkedlist& other) : head(nullptr) {
            if (other.head != nullptr){
                head = new node(other.head->value);
                node* currnode = head;
                node* other_currnode = other.head->next;
                while (other_currnode != nullptr) {
                    currnode->next = new node(other_currnode->value);
                    currnode = currnode->next;
                    other_currnode = other_currnode->next;
                }
            }
        } // Copy Constructor
        linkedlist& operator=(const linkedlist& other) {
            if (this != &other) {
                this->~linkedlist(); // Delete current list
                if (other.head == nullptr) {
                    head = nullptr;
                    return *this;
                }
                head = new node(other.head->value);
                node* currnode = head;
                node* other_currnode = other.head->next;
                while (other_currnode != nullptr) {
                    currnode->next = new node(other_currnode->value);
                    currnode = currnode->next;
                    other_currnode = other_currnode->next;
                }
            }
            return *this;
        } // copy assignment operator
};

int main() {
    linkedlist ll;
    ll.head = new node(0,nullptr);
    ll.add(ll.head, 1);
    ll.add(ll.head->next, 2);
    ll.add(ll.head->next->next, 3);
    cout << "created original ll: ";
    ll.print();
    linkedlist copyofll(ll);
    cout << "created copy of ll: ";
    copyofll.print();

    cout << "making modifications..." << endl;
    node* currnode = ll.access(2);
    ll.remove(currnode);
    cout << "printing original ll again: ";
    ll.print();
    cout << "printing copy of ll again: ";
    copyofll.print();
    cout << "making modifications..." << endl;
    currnode = ll.access(1);
    ll.remove(currnode);
    ll.print();
    cout << "assigning original to copy of..." << endl;
    ll = copyofll;
    ll.print();
}
