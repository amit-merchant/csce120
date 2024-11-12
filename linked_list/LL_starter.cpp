#include <iostream>
#include <sstream>
#include <limits>
using std::cout, std::cin, std::endl, std::exception, std::invalid_argument; 
using std::getline, std::string;

class node {
    private:
        int value = 0;
        node *ptr = nullptr;
    public:
        // constructor for node
        node (int arg_val, node *ptr = nullptr) {
            this->value = arg_val;
            this->ptr = ptr;    
        }
        // getters, gets value, gets ptr
        int getvalue () {return this->value;}
        node *getptr () {return this->ptr;}
        // setter
        void setptr (node *ptr) {this->ptr = ptr;}
        void setvalue (int value) {this->value = value;}
        // copy constructor
        node(const node& object) {
        // TO DO
        }
        // copy assigntment constructor
        node& operator=(const node& object) {
        // TO DO
        return *this;
        }
};

class LinkedList {
    private:
        node *headptr;
    public:
        // constructor
        LinkedList () {
            this->headptr = nullptr;
        }
        // destructor
        ~LinkedList () {
            while(this->headptr != nullptr) {
        // TO DO. HINT: pop existing nodes
            }
        }
        // add a node
        void push (int value) {
        // TO DO. HINT: add a new node at the head using new.
        }
        // remove node
        int pop () {
            int value_to_remove;
            if (this->headptr != nullptr) {
            // TO DO. HINT: delete node at the head unless empty.
            }
            else {
                    try { throw invalid_argument("Cannot remove elements from empty link list"); } 
                    catch (std::invalid_argument const& e) { cout << e.what() << endl; } 
            }
            return value_to_remove;
        }
        // print linked list
        void printLinkedList () {
            node *curNode = headptr;
            int reference;
            cout << "          ";
            while (curNode != nullptr) {
                reference = curNode->getvalue();
                cout << reference << " -> ";
                curNode = curNode->getptr();
            }
            cout << endl;
            curNode = headptr;
            cout << "          headptr: " << curNode << endl;
            cout << "          ";
            while (curNode != nullptr) {
                cout << curNode->getptr() << " -> ";
                // cout << curNode->getptr() << " ";
                curNode = curNode->getptr();
            }
            cout << endl;
        }
        // insert node based on reference value
        void insertNode(int value, int reference_value) {
            // TO DO. 
            // HINT: create a new node using "value" parameter. Can set nextptr as nullptr for now.
            // HINT: initialize current node to be headpointer.
            // HINT: Cycle through the existing linked list until you come across reference value
            // HINT: Set new node pointer to be pointer from 'searched' node
            // HINT: Set pointer for searched node to be pointer to new node.
            // HINT: Use the following code to throw an error if you cannot find the node with reference value.
            // if (!reference_value_found) {
            //         try { throw invalid_argument("Trying to add a node at a loctaion that does not exist"); } 
            //         catch (std::invalid_argument const& e) { cout << e.what() << endl; }                 
            // }
        } // end insertNode
        void deleteNode(int reference_value) {
            // TO DO.
            // HINT: create two new nodes - one to store next pointer temporarily. 
            // another to store the pointer where the previous node was. 
            // HINT: cycle through nodes in the LL until reference value is found
            // HINT: save next pointer, delete current node.
            // HINT: always keep track of previous node as you cycle.
            // HINT: if you are removing the first node, update headpointer
            // HINT: but no need to update previous node.
            // if (curNode->getptr() == nullptr) {
            //     try { throw invalid_argument("Cannot remove elements from empty link list"); } 
            //     catch (std::invalid_argument const& e) { cout << e.what() << endl; } 
            //     break;
            // }
            // if (!reference_value_found) {
            //     try { throw invalid_argument("Trying to delete a node at a location that does not exist"); } 
            //     catch (std::invalid_argument const& e) { cout << e.what() << endl; }                 
            // }
        } // end deleteNode
        bool link_list_empty() {
            if (this->headptr == nullptr) {return true;}
            else {return false;}
        }
}; // end LL

void get_op(const string& line, string* operation, int* num, int* location) {
    // turn the string into an input stream
    std::istringstream sin(line);
    *num = 100;
    *location = 100;
    sin >> *operation;
    if (*operation == "add" || *operation == "insert") {
        sin >> *num >> *location;
    }
    else if (*operation == "remove" || *operation == "delete") {
        sin >> *location;
    }
    else if (*operation == "push") {
        sin >> *num;
    }
    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // indicate that the line was invalid
        *operation = "ignore";
    }
}

int main () {
    LinkedList list;
    string line;
    string operation;
    int num;
    int location;
    getline (cin, line);    
    while (!line.empty()) {
        get_op (line, &operation, &num, &location);
        if (operation == "insert" || operation == "add"){
            list.insertNode(num, location);
        }
        else if (operation == "delete" || operation == "remove"){
            list.deleteNode(location);
        }
        else if (operation == "push") {
            list.push(num);
        }
        else if (operation == "pop"){
            list.pop();
        }
        else if (operation == "clear"){
            list.~LinkedList();            
        }
        else if (operation == "print"){
            list.printLinkedList();
        }
        else if (operation == "q" || operation == "quit") {
            break;
        }
        else {
            cout << "operation type undefined, re-enter please" << endl;
        }    
        getline (cin, line);
    }

    // code for testing out copy constructor and copy assignment constructor
    // node *sample = new node(99);
    // node *another = new node(100);
    // node *copyOfNode = new node(*sample);
    // cout << sample->getvalue() << " " << another->getvalue() << " " << copyOfNode->getvalue() << endl;
    // copyOfNode = another;
    // cout << copyOfNode->getvalue() << endl;

    return 0;
}
