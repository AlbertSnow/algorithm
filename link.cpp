#include <iostream>
#include <stdexcept>
#include "charUtils.h"
using namespace std;

struct ListNode 
{
    int m_nValue;
    ListNode* m_next;
};                                                   

void recursivePrint(ListNode & node);

void init(int length, ListNode &initNode) {
    if (length <= 0)
    {
        cout << "Invalid length: " << length << ", return null for that";
        return;
    }

    cout << "input length: " << length << "\n";
    cout << "first node address: " << &initNode << "\n";
    ListNode *node = &initNode;
    
    for (int i = 0; i < length; i++)
    {
        cout << "\nthis node: " << node << "\n";

        ListNode *nextOne;
        if (i == length - 1) {
            nextOne = NULL;
        } else {
            ListNode* newOne = new ListNode;
            nextOne = newOne;
            cout << "new one: " << newOne << "\n";
        }

        node->m_nValue = i;
        node->m_next = nextOne;
        cout << "node value : " << node->m_nValue << "\n";
        cout << "node next : " << node->m_next << "\n";
        node = nextOne;
    }
}

void recursivePrint(ListNode& node) {
    ListNode *listNode = &node;

    cout << "\n";

    int i = 10;

    while (listNode != NULL && i > 0)  
    {
        cout << "Node: " << listNode << "\n";
        cout << "value: " <<  listNode->m_nValue << " \n";
        cout << "listNode next: " << listNode->m_next << " \n";
        listNode = listNode->m_next;

        cout << "\n";
        i--;
    }
}

ListNode* revertLisNode(ListNode* preNode) {
    cout<< "+++++++++++ Start revertListNode +++++++++" << '\n';

    if (preNode == NULL)
    {
        cout << "input listNode is null";
        return NULL;
    }
    
    ListNode* centerNode = preNode->m_next;

    preNode->m_next = NULL;
    while (centerNode != NULL)
    {
        ListNode* lastNode = centerNode->m_next;
        centerNode->m_next = preNode;

        preNode = centerNode;
        centerNode = lastNode;

        cout<< "++++ revert one node +++ preNode " << preNode->m_nValue << '\n';
    }

    return preNode;
}

void deleteNode(int value, ListNode& srcListNode) {
    ListNode * listNode = &srcListNode;
    
    if (listNode->m_nValue == value)
    {
        cout << "----------------- find and delete list node -----------------";
        srcListNode = *listNode->m_next;
        return;
    }
    
    

    while (listNode->m_next != NULL)
    {
        if (listNode->m_next->m_nValue == value)
        {
            cout << "----------------- find and delete list node -----------------";
            listNode->m_next = listNode->m_next->m_next;
            return;
        }
        
        listNode = listNode->m_next;
    }
    


}

void testDynamicAllocate() {
        ListNode test1;
    cout << "\ntest: " << &test1;
    
    ListNode test2;
    cout << "\ntest: " << &test2;

    ListNode test3;
    cout << "\ntest: " << &test3;

    for(int i = 0; i<3; i++) {
        ListNode test4;
        cout << "\ntest4: " << &test4;
    }
}


// clang++ link.cpp  charUtils.cpp -o linkArray  && ./linkArray 19 17
int main(int argc, char* argv[]) {
    ListNode firstNode;
    int listNodeLength;
    int deleteValue = 0;

    if (argc > 1)
    {
        cout << "\ninput argument: " << argv[1] << "\n";
        listNodeLength = stringToNumber(argv[1]);
        cout << "\n";
    }
    cout << "listNodeLength: " << listNodeLength << '\n';

    if (argc > 2)
    {
        deleteValue = stringToNumber(argv[2]);
    }
    cout << "delete value: " << deleteValue << '\n';
    
    init(listNodeLength, firstNode);
    recursivePrint(firstNode);
    // deleteNode(deleteValue, firstNode);
    // recursivePrint(firstNode);

    ListNode revertNode = *revertLisNode(&firstNode);
    recursivePrint(revertNode);

    cout << '\n';
    return 0;
}