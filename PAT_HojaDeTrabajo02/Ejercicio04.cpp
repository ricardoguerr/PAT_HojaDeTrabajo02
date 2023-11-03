#include "Ejercicio04.h"

FrontMiddleBackQueue::FrontMiddleBackQueue() {
}

void FrontMiddleBackQueue::pushFront(int value) {
    data.push_front(value);
}

void FrontMiddleBackQueue::pushMiddle(int value) {
    auto it = data.begin();
    std::advance(it, data.size() / 2);
    data.insert(it, value);
}

void FrontMiddleBackQueue::pushBack(int value) {
    data.push_back(value);
}

int FrontMiddleBackQueue::popFront() {
    if (data.empty()) {
        return -1;
    }
    int front = data.front();
    data.pop_front();
    return front;
}

int FrontMiddleBackQueue::popMiddle() {
    if (data.empty()) {
        return -1;
    }
    auto it = data.begin();
    std::advance(it, (data.size() - 1) / 2);
    int middle = *it;
    data.erase(it);
    return middle;
}

int FrontMiddleBackQueue::popBack() {
    if (data.empty()) {
        return -1;
    }
    int back = data.back();
    data.pop_back();
    return back;
}
