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

    while (listNode != NULL)                                                                                                                                   
    {
        cout << "Node: " << listNode << "\n";
        cout << "value: " <<  listNode->m_nValue << " \n";
        cout << "listNode next: " << listNode->m_next << " \n";
        listNode = listNode->m_next;

        cout << "\n";
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

int main(int argc, char* argv[]) {
    ListNode firstNode;
    int listNodeLength;

    if (argc > 1)
    {
        cout << "\ninput argument: " << argv[1] << "\n";
        listNodeLength = argv[1][0] - '0';
        cout << "listNodeLength: " << listNodeLength << "\n";
        cout << "\n";
    }
    
    init(listNodeLength, firstNode);
    recursivePrint(firstNode);
    return 0;
}

