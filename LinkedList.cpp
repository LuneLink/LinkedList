#include "LinkedList.hpp"

LinkedList::LinkedList() {
    this->pHead = nullptr;
    this->size = 0;
}

LinkedList::LinkedList(const LinkedList& orig) {
}

LinkedList::~LinkedList() {
}

void LinkedList::add(int nData) {
    Node* pCurrentPos = pHead;

    Node* pNewData = new Node(nData);
    pNewData->pNext = 0;

    if (pHead == 0) {
        pHead = pNewData;
    } else {
        while (pCurrentPos->pNext) {
            pCurrentPos = pCurrentPos->pNext;
        }

        pCurrentPos->pNext = pNewData;
    }
    size++;
}

int LinkedList::get(int nId) {
    Node* pCurrentPos = pHead;

    for (int i = 0; i < nId; i++)
        pCurrentPos = pCurrentPos->pNext;

    return pCurrentPos->get();
}

void LinkedList::remove(int nId) {
    Node* pCurrentPos = pHead;

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
                Node *pPrevPos = pCurrentPos;
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
            Node *pDeadNode = pCurrentPos;
            pCurrentPos->pNext = pCurrentPos->pNext->pNext;
            return;
        }
        pCurrentPos = pCurrentPos->pNext;
    }
    removeNode(pCurrentPos);
}

void LinkedList::removeNode(Node *node) {
    delete node;
    size--;
}

void LinkedList::out() {
    if (pHead == nullptr)
        return;
    Node* pCurrentPos = pHead;
    while (pCurrentPos->pNext) {
        std::cout << pCurrentPos->get() << " ";
        pCurrentPos = pCurrentPos->pNext;
    }
    std::cout << pCurrentPos->get() << std::endl;
}

void LinkedList::clear() {
    if (pHead != nullptr)
        for (int i = size; i != 0; i--) {
            remove(0);
        }
}
