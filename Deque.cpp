#include "Deque.h"


/* 152120211042 Sezai Enes YILDIZHAN
 * 152120211053 Mehmet Ayberk GÜNEŞ
 *
 * https://github.com/sezaienesyildizhan/datastructures_lab04*/


/// Default constructor
Deque::Deque() {
    // Initialize the head and tail pointers to nullptr
    head = nullptr;
    tail = nullptr;
    // Initialize the number of items in the deque to 0
    noOfItems = 0;
} //end-Deque

/// Destructor
Deque::~Deque() {
    // Destructor to free memory allocated for nodes
    // Traverse the deque and delete each node
    while (head != nullptr) {
        DequeNode* temp = head;
        head = head->next;
        delete temp;
    }
    // Set tail pointer to nullptr and update the count of items to 0
    tail = nullptr;
    noOfItems = 0;
} //end-~Deque

/// Adds a new item to the front of the Deque
void Deque::AddFront(int item) {
    // Create a new node
    DequeNode* newNode = new DequeNode(item);
    // If the deque is empty, set the new node as both head and tail
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        // Otherwise, adjust pointers to add the new node at the front
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    // Increment the count of items
    noOfItems++;
} //end-AddFront

/// Adds a new item to the end of the Deque
void Deque::AddRear(int item) {
    // Create a new node
    DequeNode* newNode = new DequeNode(item);
    // If the deque is empty, set the new node as both head and tail
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        // Otherwise, adjust pointers to add the new node at the rear
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    // Increment the count of items
    noOfItems++;
} //end-AddRear

/// Remove and return the item at the front of the Deque
int Deque::RemoveFront() {
    // If the deque is empty, throw an exception
    if (head == nullptr) {
        throw "Deque is empty!";
    }
    // Store the value to be returned
    int value = head->item;
    // Store the head node temporarily
    DequeNode* temp = head;
    // Move the head pointer to the next node
    head = head->next;
    // If the new head exists, update its previous pointer to nullptr
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        // If the deque becomes empty after removal, update tail to nullptr
        tail = nullptr;
    }
    // Delete the original head node
    delete temp;
    // Decrement the count of items
    noOfItems--;
    // Return the removed value
    return value;
} //end-RemoveFront

/// Remove and return the item at the rear of the Deque
int Deque::RemoveRear() {
    // If the deque is empty, throw an exception
    if (tail == nullptr) {
        throw "Deque is empty!";
    }
    // Store the value to be returned
    int value = tail->item;
    // Store the tail node temporarily
    DequeNode* temp = tail;
    // Move the tail pointer to the previous node
    tail = tail->prev;
    // If the new tail exists, update its next pointer to nullptr
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        // If the deque becomes empty after removal, update head to nullptr
        head = nullptr;
    }
    // Delete the original tail node
    delete temp;
    // Decrement the count of items
    noOfItems--;
    // Return the removed value
    return value;
} //end-RemoveRear

/// Return the item at the front of the Deque (do not remove the item)
int Deque::Front() {
    // If the deque is empty, throw an exception
    if (head == nullptr) {
        throw "Deque is empty!";
    }
    // Return the value at the front
    return head->item;
} //end-Front

/// Return the item at the rear of the Deque (do not remove the item)
int Deque::Rear() {
    // If the deque is empty, throw an exception
    if (tail == nullptr) {
        throw "Deque is empty!";
    }
    // Return the value at the rear
    return tail->item;
} //end-Rear
