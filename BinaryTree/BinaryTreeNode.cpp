#include <deque>

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

void release(BinaryTreeNode* rootNode) {

    
}


int main()
{
    BinaryTreeNode rootNode;
    rootNode.m_nValue = 2;

    BinaryTreeNode *pRootNode = &rootNode;

    init(pRootNode);
    printTop2Bottom(pRootNode);

    // release(pRootNode);
    return 0;
}
