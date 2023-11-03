#include "Ejercicio02.h"

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* l1, Node<int>* l2) {
    Node<int>* result = nullptr;
    Node<int>* current = nullptr;

    int carry = 0;

    while (l1 || l2 || carry) {
        int num1;
        if (l1) {
            num1 = l1->value;
        }
        else {
            num1 = 0;
        }

        int num2;
        if (l2) {
            num2 = l2->value;
        }
        else {
            num2 = 0;
        }

        int sum = num1 + num2 + carry;
        carry = sum / 10;

        if (!result) {
            result = new Node<int>(sum % 10);
            current = result;
        }
        else {
            current->next = new Node<int>(sum % 10);
            current = current->next;
        }

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return result;
}
