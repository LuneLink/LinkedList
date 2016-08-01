#include "LinkedList.hpp"

LinkedList *LinkedList::pHead = 0;
int LinkedList::size = 0;

LinkedList::LinkedList() {
    this->pHead = nullptr;
    this->size = 0;
}

LinkedList::LinkedList(int data) {
    this->data = data;
}

LinkedList::LinkedList(const LinkedList& orig) {
}

LinkedList::~LinkedList() {
}

void LinkedList::add(int nData) {
    LinkedList* pCurrentPos = LinkedList::pHead;

    LinkedList* pNewData = new LinkedList(nData);
    pNewData->pNext = 0;

    if (pHead == 0) {
        pHead = pNewData;
    } else {
        while (pCurrentPos->pNext) {
            pCurrentPos = pCurrentPos->pNext;
        }

        pCurrentPos->pNext = pNewData;
    }
    LinkedList::size++;
}

void LinkedList::remove(int nId) {
    LinkedList* pCurrentPos = pHead;

    if (nId > size - 1) {
        return;
    }

    if (nId == size - 1) {

        if (size == 1) {
            removeNode(pCurrentPos);
            pHead = nullptr;
            return;
        }

        for (int i = 0;; i++) {
            if (i == nId - 1) {
                LinkedList *pPrevPos = pCurrentPos;
                pCurrentPos = pCurrentPos->pNext;
                removeNode(pCurrentPos);
                pPrevPos->pNext = 0;
                return;
            }
            pCurrentPos = pCurrentPos->pNext;
        }
    }

    if (nId == 0) {
        pHead = pCurrentPos->pNext;
        removeNode(pCurrentPos);
        return;
    }

    for (int i = 0;; i++) {

        if (i == nId - 1) {
            LinkedList *pDeadNode = pCurrentPos;
            pCurrentPos->pNext = pCurrentPos->pNext->pNext;
            return;
        }
        pCurrentPos = pCurrentPos->pNext;
    }
    removeNode(pCurrentPos);
}

void LinkedList::removeNode(LinkedList *node) {
    delete node;
    LinkedList::size--;
}

void LinkedList::out() {
    if (LinkedList::pHead == nullptr)
        return;
    LinkedList* pCurrentPos = LinkedList::pHead;
    while (pCurrentPos->pNext) {
        std::cout << pCurrentPos->data << " ";
        pCurrentPos = pCurrentPos->pNext;
    }
    std::cout << pCurrentPos->data << std::endl;
}

void LinkedList::clear() {
    if (pHead != nullptr)
        for (int i = size; i != 0; i--) {
            remove(0);
        }
}
