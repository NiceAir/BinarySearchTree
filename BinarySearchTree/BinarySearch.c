#include "BinarySearchTree.h"

void InitBSTree(BSTNode** pRoot)  // 初始化二叉搜索树 
{
    assert(pRoot);
    (*pRoot) = NULL;
}

static BSTNode * CreateNode(DataType data)    //创建结点
{
    BSTNode *cache = (BSTNode *)malloc(sizeof(BSTNode));
    if (cache != NULL)
    {
        cache->_data = data;
        cache->_pLeft = NULL;
        cache->_pRight = NULL;
        return cache;
    }
    return NULL;
}

void InsertBSTree(BSTNode** pRoot, DataType data) // 插入值为data的元素
{
    assert(pRoot);
    if (*pRoot == NULL)
    {
        *pRoot = CreateNode(data);
    }
    else
    {
        BSTNode *pChild = *pRoot;
        BSTNode *pParent = NULL;
        while(pChild)
        {
            if (data < pChild->_data)
            {
                pParent = pChild;
                pChild = pChild->_pLeft;
            }
            else if (data > pChild->_data)
            {
                pParent = pChild;
                pChild = pChild->_pRight;
            }
            else
                return;
        }
        if (data < pParent->_data)
        {
            pParent->_pLeft = CreateNode(data);
        }
        else
            pParent->_pRight =  CreateNode(data);
    }
}

void DeleteBSTree(BSTNode** pRoot, DataType data) // 删除值为data的结点 
{
    BSTNode *pParent = NULL;
    BSTNode *pChild = *pRoot;
    assert(pRoot);

    while(pChild)
    {
        if (pChild->_data == data)
        {
            break;
        }
        if (data < pChild->_data)
        {
            pParent = pChild;
            pChild = pChild->_pLeft;
        }
        else if (data > pChild->_data)
        {
            pParent = pChild;
            pChild = pChild->_pRight;
        }
    }
    if (pChild == NULL)
    {
        printf("删除失败，没找到值为%d的结点\n", data);
        return;
    }
    if (pChild->_pLeft == NULL && pChild->_pRight == NULL)  //待删除结点没有孩子
    {
        if (pParent == NULL)    //若待删除结点为根节点，则将根置空
            *pRoot = NULL;
        else 
        {
            if (pParent->_pLeft == pChild)  //若待删除结点为父亲节点的左孩子，则让父亲的左孩子为空
                pParent->_pLeft = NULL;
            else
                pParent->_pRight = NULL;    //若待删除结点为父亲节点的右孩子，则让父亲的右孩子为空
        }
    }
    else if (pChild->_pLeft == NULL && pChild->_pRight != NULL)    //待删除结点只有右孩子
    {
        if (pParent == NULL)            //若待删除结点为根节点，则将根节点移到它的右孩子
            *pRoot = pChild->_pRight;
        else
        {
            if (pParent->_pLeft == pChild)      //若待删除结点是父亲的左孩子，则让父亲的左孩子指向待删除结点的孩子
                pParent->_pLeft = pChild->_pRight;
            else
                pParent->_pRight = pChild->_pRight; ////若待删除结点是父亲的右孩子，则让父亲的右孩子指向待删除结点的孩子
        }

    }
    else if (pChild->_pRight == NULL && pChild->_pLeft != NULL) //待删除结点只有左孩子
    {
        if (pParent == NULL)
            *pRoot = pChild->_pLeft;
        else
        {
            if (pParent->_pLeft == pChild)      //若待删除结点是父亲的左孩子，则让父亲的左孩子指向待删除结点的孩子
                pParent->_pLeft = pChild->_pRight;
            else
                pParent->_pRight = pChild->_pRight; ////若待删除结点是父亲的右孩子，则让父亲的右孩子指向待删除结点的孩子
        }
    }
    else    //若待删除结点既有左孩子又有右孩子
    {                                           //则找待删除结点的左孩子节点的最右结点作为替代结点
        BSTNode *cur = pChild->_pLeft;  //替代结点
        BSTNode *curParent = NULL;      //替代结点的父亲
        
        while(cur->_pRight != NULL)
        {
            curParent = cur;
            cur = cur->_pRight;
        }
                                    //用替代结点的值覆盖待删除结点的值
        pChild->_data = cur->_data;

        if (curParent->_pLeft == cur)       //改变替代结点父亲的孩子节点指向
        {
            curParent->_pLeft = cur->_pRight;
        }
        else
            curParent->_pLeft = cur->_pRight;
        
        pChild = cur;           //待删除结点变成了替代结点
        
    }
    free(pChild);
}

BSTNode* FindBSTree(BSTNode* pRoot, DataType data)  // 在二叉搜索树中查找值为data的结点 
{
    BSTNode *p = pRoot;
    while(p)
    {
        if (p->_data == data)
        {
            return p;
        }
        else if (data < p->_data)
        {
            p = p->_pRight;
        }
        else
        {
            p = p->_pRight;
        }
    }
    return NULL;
}


BSTNode* FindBSTreeByRecursion(BSTNode* pRoot, DataType data) //递归地查找值为data的结点
{
    if (pRoot != NULL)
    {
        if (pRoot->_data == data)
        {
            return pRoot;
        }
        if (data < pRoot->_data)
            FindBSTreeByRecursion(pRoot->_pLeft, data);
        else    
            FindBSTreeByRecursion(pRoot->_pRight, data);
    }
}

void InsertBSTreeByRecursion(BSTNode** pRoot, DataType data) //递归地插入值为data的元素
{
    assert(pRoot);
    if (*pRoot == NULL)
    {
        (*pRoot) = CreateNode(data);
    }
    else
    {
        if (data < ((*pRoot)->_data))
        {
            InsertBSTreeByRecursion(&((*pRoot)->_pLeft), data);
        }
        else if (data > (*pRoot->_data))
        {
            InsertBSTreeByRecursion(&((*pRoot)->_pRight), data);
        }
        else
            return;
    }
}


void PreOrderByRecursion(BSTNode* pRoot) //递归地中序遍历二叉搜索树 
{
    if (pRoot != NULL)
    {
        PreOrderByRecursion(pRoot->_pLeft);
        printf("%d ", pRoot->_data);
        PreOrderByRecursion(pRoot->_pRight);
    }
}
void DestroyBSTreeByRecursion(BSTNode** pRoot) //递归地销毁二叉搜索树
{
    assert(pRoot)
    if ((*pRoot)->_pLeft == NULL && (*pRoot)->_pRight == NULL)
    {
        free(*pRoot);
        *pRoot = NULL;
    }
    DestroyBSTreeByRecursion(&((*pRoot)->_pLeft));
    DestroyBSTreeByRecursion(&((*pRoot)->_pRight));
}

void TestBSTree()   //测试二叉搜索树
{
    BSTNode *pRoot;
    int a[] = {5,3,4,1,7,8,2,6,0,9};
    int i = 0;
    InitBSTree(&pRoot);
    for (i = 0; i<sizeof(a)/sizeof(int); i++)
    {
        InsertBSTree(&pRoot, a[i]);
    }
    

}