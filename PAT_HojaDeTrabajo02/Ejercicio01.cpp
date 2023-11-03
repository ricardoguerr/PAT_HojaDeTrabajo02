#include "Ejercicio01.h"

Node<char>* Ejercicio01::rotateRight(Node<char>* head, int k)
{
    if (!head || k == 0) {
        return head;
    }

    int length = 1;
    Node<char>* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    k = k % length;

    if (k == 0) {
        return head;
    }

    Node<char>* newHead = head;
    Node<char>* newTail = head;
    for (int i = 0; i < length - k - 1; i++) {
        newTail = newTail->next;
    }

    newHead = newTail->next;

    newTail->next = nullptr;
    tail->next = head;

    return newHead;
}
