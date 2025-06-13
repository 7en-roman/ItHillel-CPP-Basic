// ДЗ 8. Бінарне дерево

#include <iostream>
#include <set>
#include <map>
#include <utility>

class SearchTree
{
private:
    struct Node
    {
        int iValue;
        Node* pLeft = nullptr;
        Node* pRight = nullptr;
    };

    unsigned int m_uiSize = 0;
    Node* m_pRoot = nullptr;

    Node* FindPlace(int value) const;
    void PrintNode(const Node* const& node) const;
    Node* FindParent(int value) const;
    void InsertExistedNode(Node* const& insertedNode, Node* const parentNode);

    void ClearAll(Node* node);

public:
    SearchTree() {};
    ~SearchTree();

    unsigned int Size() const;
    void ShowAllTree() const;
    void Add(int value);
    bool Find(int value) const;
    bool Delete(int value);
};

int main()
{
    SearchTree tree;

    for (size_t i = 0; i < 5; ++i)
        tree.Add(rand() % 10 + 1);

    tree.ShowAllTree();
    std::cout << "\n-----------------------------------------------\n\n";
    tree.Delete(5);
    tree.Delete(8);

    tree.ShowAllTree();
}

unsigned int SearchTree::Size() const
{
    return m_uiSize;
}

void SearchTree::Add(int value)
{
    if (m_pRoot == nullptr)
    {
        Node* pNewNode = new Node;
        pNewNode->iValue = value;

        m_pRoot = pNewNode;
        ++m_uiSize;
        return;
    }

    Node* searched = FindPlace(value);

    if (searched == nullptr)
        return;

    Node* pNewNode = new Node;
    pNewNode->iValue = value;

    if (value > searched->iValue)
    {
        searched->pRight = pNewNode;
        ++m_uiSize;
    }
    else if (value < searched->iValue)
    {
        searched->pLeft = pNewNode;
        ++m_uiSize;
    }
    else
        delete pNewNode;
}

SearchTree::Node* SearchTree::FindPlace(int value) const
{
    Node* searched = nullptr;

    if (m_pRoot == nullptr)
        return searched;

    Node* tmp = m_pRoot;

    while (true)
    {
        if (value > tmp->iValue)
        {
            if (tmp->pRight == nullptr)
            {
                searched = tmp;
                break;
            }
            else
                tmp = tmp->pRight;
        }
        else if (value < tmp->iValue)
        {
            if (tmp->pLeft == nullptr)
            {
                searched = tmp;
                break;
            }
            else
                tmp = tmp->pLeft;
        }
        else
            break;
    }

    return searched;
}

void SearchTree::PrintNode(const Node* const& node) const
{
    if (node == nullptr)
        return;

    PrintNode(node->pLeft);
    std::cout << "node: " << node->iValue << "\n";
    PrintNode(node->pRight);
}

void SearchTree::ShowAllTree() const
{
    PrintNode(m_pRoot);
}

bool SearchTree::Find(int value) const
{
    if (m_pRoot == nullptr)
        return false;

    Node* searched = FindPlace(value);

    if (searched == nullptr)
        return true;
    else
        return false;
}

bool SearchTree::Delete(int value)
{
    if (m_pRoot == nullptr)
        return false;

    Node* pParent = FindParent(value);

    if (pParent == nullptr && m_pRoot->iValue != value)
        return false;
    else if (pParent == nullptr && m_pRoot->iValue == value)
    {
        Node* tmpForDelete = m_pRoot;

        if (tmpForDelete->pRight != nullptr)
        {
            m_pRoot = tmpForDelete->pRight;

            if (tmpForDelete->pLeft != nullptr)
                InsertExistedNode(tmpForDelete->pLeft, m_pRoot);
        }
        else if (tmpForDelete->pLeft != nullptr)
            m_pRoot = tmpForDelete->pLeft;
        else
            m_pRoot = nullptr;

        delete tmpForDelete;

        --m_uiSize;
        return true;
    }

    if (value > pParent->iValue)
    {
        Node* tmpForDelete = pParent->pRight;

        if (tmpForDelete->pRight != nullptr)
        {
            pParent->pRight = tmpForDelete->pRight;

            if (tmpForDelete->pLeft != nullptr)
                InsertExistedNode(tmpForDelete->pLeft, pParent->pRight);

            delete tmpForDelete;
        }
        else if (tmpForDelete->pLeft != nullptr)
        {
            pParent->pRight = tmpForDelete->pLeft;

            delete tmpForDelete;
        }
        else
        {
            pParent->pRight = nullptr;
            delete tmpForDelete;
        }
    }
    else if (value < pParent->iValue)
    {
        Node* tmpForDelete = pParent->pLeft;

        if (tmpForDelete->pRight != nullptr)
        {
            pParent->pLeft = tmpForDelete->pRight;

            if (tmpForDelete->pLeft != nullptr)
                InsertExistedNode(tmpForDelete->pLeft, pParent->pLeft);
        }
        else if (tmpForDelete->pLeft != nullptr)
            pParent->pLeft = tmpForDelete->pLeft;
        else
            pParent->pLeft = nullptr;

        delete tmpForDelete;
    }
    else
        return false;

    --m_uiSize;
    return true;
}

void SearchTree::InsertExistedNode(Node* const& insertedNode, Node* const parentNode)
{
    int value = insertedNode->iValue;

    if (value > parentNode->iValue)
    {
        if (parentNode->pRight != nullptr)
            InsertExistedNode(insertedNode, parentNode->pRight);
        else
            parentNode->pRight = insertedNode;
    }
    else if (value < parentNode->iValue)
    {
        if (parentNode->pLeft != nullptr)
            InsertExistedNode(insertedNode, parentNode->pLeft);
        else
            parentNode->pLeft = insertedNode;
    }
    else
        return;
}

SearchTree::Node* SearchTree::FindParent(int value) const
{
    Node* searched = nullptr;

    if (m_pRoot == nullptr)
        return searched;

    Node* tmp = m_pRoot;
    Node* prevTmp = nullptr;

    while (true)
    {
        if (value > tmp->iValue)
        {
            if (tmp->pRight == nullptr)
                break;
            else
            {
                prevTmp = tmp;
                tmp = tmp->pRight;
            }
        }
        else if (value < tmp->iValue)
        {
            if (tmp->pLeft == nullptr)
                break;
            else
            {
                prevTmp = tmp;
                tmp = tmp->pLeft;
            }
        }
        else
        {
            searched = prevTmp;
            break;
        }
    }

    return searched;
}

void SearchTree::ClearAll(Node* node)
{
    if (node == nullptr)
        return;

    ClearAll(node->pLeft);
    ClearAll(node->pRight);

    delete node;
}

SearchTree::~SearchTree()
{
    ClearAll(m_pRoot);
    m_pRoot = nullptr;
    m_uiSize = 0;
}