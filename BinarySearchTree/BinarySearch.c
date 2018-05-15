#include "BinarySearchTree.h"

void InitBSTree(BSTNode** pRoot)  // ��ʼ������������ 
{
    assert(pRoot);
    (*pRoot) = NULL;
}

static BSTNode * CreateNode(DataType data)    //�������
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

void InsertBSTree(BSTNode** pRoot, DataType data) // ����ֵΪdata��Ԫ��
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

void DeleteBSTree(BSTNode** pRoot, DataType data) // ɾ��ֵΪdata�Ľ�� 
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
        printf("ɾ��ʧ�ܣ�û�ҵ�ֵΪ%d�Ľ��\n", data);
        return;
    }
    if (pChild->_pLeft == NULL && pChild->_pRight == NULL)  //��ɾ�����û�к���
    {
        if (pParent == NULL)    //����ɾ�����Ϊ���ڵ㣬�򽫸��ÿ�
            *pRoot = NULL;
        else 
        {
            if (pParent->_pLeft == pChild)  //����ɾ�����Ϊ���׽ڵ�����ӣ����ø��׵�����Ϊ��
                pParent->_pLeft = NULL;
            else
                pParent->_pRight = NULL;    //����ɾ�����Ϊ���׽ڵ���Һ��ӣ����ø��׵��Һ���Ϊ��
        }
    }
    else if (pChild->_pLeft == NULL && pChild->_pRight != NULL)    //��ɾ�����ֻ���Һ���
    {
        if (pParent == NULL)            //����ɾ�����Ϊ���ڵ㣬�򽫸��ڵ��Ƶ������Һ���
            *pRoot = pChild->_pRight;
        else
        {
            if (pParent->_pLeft == pChild)      //����ɾ������Ǹ��׵����ӣ����ø��׵�����ָ���ɾ�����ĺ���
                pParent->_pLeft = pChild->_pRight;
            else
                pParent->_pRight = pChild->_pRight; ////����ɾ������Ǹ��׵��Һ��ӣ����ø��׵��Һ���ָ���ɾ�����ĺ���
        }

    }
    else if (pChild->_pRight == NULL && pChild->_pLeft != NULL) //��ɾ�����ֻ������
    {
        if (pParent == NULL)
            *pRoot = pChild->_pLeft;
        else
        {
            if (pParent->_pLeft == pChild)      //����ɾ������Ǹ��׵����ӣ����ø��׵�����ָ���ɾ�����ĺ���
                pParent->_pLeft = pChild->_pRight;
            else
                pParent->_pRight = pChild->_pRight; ////����ɾ������Ǹ��׵��Һ��ӣ����ø��׵��Һ���ָ���ɾ�����ĺ���
        }
    }
    else    //����ɾ�����������������Һ���
    {                                           //���Ҵ�ɾ���������ӽڵ�����ҽ����Ϊ������
        BSTNode *cur = pChild->_pLeft;  //������
        BSTNode *curParent = NULL;      //������ĸ���
        
        while(cur->_pRight != NULL)
        {
            curParent = cur;
            cur = cur->_pRight;
        }
                                    //���������ֵ���Ǵ�ɾ������ֵ
        pChild->_data = cur->_data;

        if (curParent->_pLeft == cur)       //�ı������㸸�׵ĺ��ӽڵ�ָ��
        {
            curParent->_pLeft = cur->_pRight;
        }
        else
            curParent->_pLeft = cur->_pRight;
        
        pChild = cur;           //��ɾ���������������
        
    }
    free(pChild);
}

BSTNode* FindBSTree(BSTNode* pRoot, DataType data)  // �ڶ����������в���ֵΪdata�Ľ�� 
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


BSTNode* FindBSTreeByRecursion(BSTNode* pRoot, DataType data) //�ݹ�ز���ֵΪdata�Ľ��
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

void InsertBSTreeByRecursion(BSTNode** pRoot, DataType data) //�ݹ�ز���ֵΪdata��Ԫ��
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


void PreOrderByRecursion(BSTNode* pRoot) //�ݹ������������������� 
{
    if (pRoot != NULL)
    {
        PreOrderByRecursion(pRoot->_pLeft);
        printf("%d ", pRoot->_data);
        PreOrderByRecursion(pRoot->_pRight);
    }
}
void DestroyBSTreeByRecursion(BSTNode** pRoot) //�ݹ�����ٶ���������
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

void TestBSTree()   //���Զ���������
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