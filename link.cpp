#include <iostream>
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
        cout << "this node: " << node << "\n";
        node->m_nValue = i;

        ListNode *nextOne;
        if (i == length - 1) {
            nextOne = NULL;
        } else {
            ListNode newOne;
            nextOne = &newOne;
        }        
        node->m_next = nextOne;
        cout << "node value : " << node->m_nValue << "\n";
        cout << "node next : " << node->m_next << "\n";
        node = nextOne;
    }
}

void recursivePrint(ListNode& node) {
    ListNode *listNode = &node;

    cout << "\n First print node. " << &node;
    while (listNode != NULL)                                                                                                                                   
    {
        cout << "\n value: " <<  listNode->m_nValue << " \n";
        cout << "listNode next: " << listNode->m_next;
        listNode = listNode->m_next;
    }
}



void deleteNode(int value, ListNode *srcListNode) {
    if (srcListNode == NULL || 
    (srcListNode->m_next == NULL && value == srcListNode->m_nValue))
    {
        srcListNode = NULL;
        return;
    }

       while (srcListNode->m_next != NULL) {
        ListNode *next = srcListNode->m_next;
        if (next->m_nValue == value)
        {
            srcListNode = next->m_next;
            return;
        }
    }
}

int main() {
    ListNode firstNode;
    init(1, firstNode);
    recursivePrint(firstNode);
    return 0;
}

