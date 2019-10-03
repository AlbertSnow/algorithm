#include <iostream>
#include <stdexcept>
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

int  stringToNumber(char chars[]) {
    int result = 0;
    if (chars == NULL || chars[0] == '\n' || chars[0] == '-') {
        cout << "input invalid, Support only number";

        return 0;
    } 

    int digit = chars[0] - '0';                                                                                                                                                                                                                                                             
    int i = 1;
    while (chars[i] != '\0') {
        digit = (chars[i] - '0') + (digit * 10);
        cout << "digit " << digit << '\n';
        i++;

        if(i > 9) {
            throw invalid_argument("input argument length big than 9");
        }
    }

    return digit;
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
    deleteNode(deleteValue, firstNode);
    recursivePrint(firstNode);

    cout << '\n';
    return 0;
}

