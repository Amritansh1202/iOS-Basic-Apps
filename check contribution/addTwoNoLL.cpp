#include <iostream>
#include<vector>
using namespace std;

class Node{
    public: 

    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    // detructor
    ~Node() {
        int value = this -> data;

        // memory free
        if (this -> next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
        
    }

};

void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &head, Node* &tail, int d) {

    Node * temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else {
    tail -> next = temp; 
    tail = tail -> next; 
    }
}

void print(Node* &head) {

    Node* temp = head;
    
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }cout << endl;
    
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d) {

    //insert at head
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    
    Node* temp = head;
    int count = 1;

    if (temp -> next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }
    
    while (count < position - 1)
    {
        temp = temp -> next;
        count++;
    }

    // insert tail ka pointer in the end
    
    
    // create a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* &head) {

    // deleting first node
    if (position == 1)
    {
        Node* temp = head;
        head = head -> next;
        // memory free of start node
        // call destructor
        temp -> next = NULL;
        delete temp;
    }
    // deleting and middle node or last node
    else {

        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        
        
        prev -> next = curr -> next;

        curr -> next = NULL;
        delete curr;
    }
    
}

Node* reverse(Node* &head) {

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// method 1 to write add function - 4 loops
Node* add(Node* first, Node* second) {

    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while (first != NULL && second != NULL)
    {
        int sum = carry + first -> data + second -> data;
        int digit = sum % 10;
        Node* temp = new Node(digit);

        // create node and add in answer LL
        insertAtTail(ansHead, ansTail, digit);
        
        carry = sum/10;
        first = first -> next;
        second = second -> next;
    }
    
    while (first != NULL)
    {
        int sum = carry + first -> data;
        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
        first = first -> next;
    }

    while (second != NULL)
    {
        int sum = carry + second -> data;
        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10; 
        second = second -> next;
    }
    
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
    }
    return ansHead;
}

// method 2 to write add function - single loop

Node* add2(Node* first, Node* second) {

    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while (first != NULL || second != NULL || carry != NULL)
    {   
        int val1;
        if (first != NULL)
        {
            val1 = first -> data;
        }
        
        int val2;
        if (second != NULL)
        {
            val2 = second -> data;
        }
        
        int sum = carry + val1 + val2;
        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;

        if (first != NULL)
        {
            first = first -> next;
        }
        if (second != NULL)
        {
            second = second -> next;
        }
        
    }
    return ansHead;
}

Node* addTwoNumbers(Node* first, Node* second) {

    // step 1 - reverse input LL
    first = reverse(first);
    second = reverse(second);

    // step 2 - add two LL

    Node* ans = add(first, second);

    // step 3 - reverse answer

    ans = reverse(ans);

    return ans;
}

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
