#include <deque>
#include <stack>
#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue = 0;
    BinaryTreeNode *m_pLeft = nullptr;
    BinaryTreeNode *m_pRight = nullptr;
};

void printTop2Bottom(BinaryTreeNode *pTreeRoot);

void init(BinaryTreeNode *rootNode)
{
    if (rootNode == nullptr)
    {
        return;
    }

    if (rootNode->m_nValue == 0)
    {
        rootNode->m_nValue = 1;
    }

    //----- 1layer
    BinaryTreeNode* treeNode1Left = new BinaryTreeNode();
    treeNode1Left->m_nValue = 11;
    rootNode->m_pLeft = treeNode1Left;

    BinaryTreeNode* treeNode1Right = new BinaryTreeNode();
    treeNode1Right->m_nValue = 12;
    rootNode->m_pRight = treeNode1Right;

    //----- 2layer
    BinaryTreeNode* treeNode21Left = new BinaryTreeNode();
    treeNode21Left->m_nValue = 211;
    treeNode1Left->m_pLeft = treeNode21Left;

    BinaryTreeNode* treeNode21Right = new BinaryTreeNode();
    treeNode21Right->m_nValue = 212;
    treeNode1Left->m_pRight = treeNode21Right;

    BinaryTreeNode* treeNode22Left = new BinaryTreeNode();
    treeNode22Left->m_nValue = 221;
    treeNode1Right->m_pLeft = treeNode22Left;

    BinaryTreeNode* treeNode22Right = new BinaryTreeNode();
    treeNode22Right->m_nValue = 222;
    treeNode1Right->m_pRight = treeNode22Right;

    // printTop2Bottom(rootNode);
}

void printTop2Bottom(BinaryTreeNode *pTreeRoot)
{
    if (!pTreeRoot)
    {
        return;
    }

    std::deque<BinaryTreeNode *> dequeTreeNode;

    dequeTreeNode.push_back(pTreeRoot);

    while (dequeTreeNode.size())
    {
        BinaryTreeNode *pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();
        printf("%d \n", pNode->m_nValue);

        if (pNode->m_pLeft)
        {
            dequeTreeNode.push_back(pNode->m_pLeft);
        }

        if (pNode->m_pRight)
        {
            dequeTreeNode.push_back(pNode->m_pRight);
        }
    }
}
void doPrintZOrder (stack<BinaryTreeNode*>* printStack, stack<BinaryTreeNode*>* saveStack, bool leftChildFirst);

void printZOrder(BinaryTreeNode* rootNode) {
    cout<< "printZOrder"<< endl;

    stack<BinaryTreeNode*>* printSack = new stack<BinaryTreeNode*>;
    stack<BinaryTreeNode*>* saveSack  = new stack<BinaryTreeNode*>;
    printSack->push(rootNode);

    doPrintZOrder(printSack, saveSack, true);
}

void doPrintZOrder (stack<BinaryTreeNode*>* printStack, stack<BinaryTreeNode*>* saveStack, bool leftChildFirst) {
    cout<< "doPrintZOrder"<< endl;

    BinaryTreeNode* topNode;

    while((topNode = printStack->top()) != nullptr) {
        printStack->pop();
        
        cout << "top : " << topNode->m_nValue;

        BinaryTreeNode* firstNode =  leftChildFirst ? topNode->m_pLeft : topNode->m_pRight;
        BinaryTreeNode* secondNode =  leftChildFirst ? topNode->m_pRight : topNode->m_pLeft;

        if (firstNode != nullptr)
        {
            saveStack->push(firstNode);
        }
        
        if (secondNode != nullptr)
        {
            saveStack->push(secondNode);
        }
    }
    
    cout << "break one layer " << endl;

    doPrintZOrder(saveStack, printStack, !leftChildFirst);
}


void release(BinaryTreeNode* rootNode) {

    
}


int main()
{
    BinaryTreeNode rootNode;
    rootNode.m_nValue = 2;

    BinaryTreeNode *pRootNode = &rootNode;

    init(pRootNode);
    // printTop2Bottom(pRootNode);
    printZOrder(pRootNode);

    // release(pRootNode);
    return 0;
}
