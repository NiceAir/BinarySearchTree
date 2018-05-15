������������

typedef int DataType; 
typedef struct BSTreeNode 
{
    struct BSTreeNode* _pLeft; 
    struct BSTreeNode* _pRight; 
    DataType _data;
}BSTNode; 


void InitBSTree(BSTNode** pRoot);  // ��ʼ������������ 
void InsertBSTree(BSTNode** pRoot, DataType data); // ����ֵΪdata��Ԫ�� 
void DeleteBSTree(BSTNode** pRoot, DataType data); // ɾ��ֵΪdata�Ľ�� 
BSTNode* FindBSTree(BSTNode* pRoot, DataType data);  // �ڶ����������в���ֵΪdata�Ľ�� 

BSTNode* FindBSTreeByRecursion(BSTNode* pRoot, DataType data); //�ݹ�ز���ֵΪdata�Ľ��
void InsertBSTreeByRecursion(BSTNode** pRoot, DataType data); //�ݹ�ز���ֵΪdata��Ԫ��
void PreOrderByRecursion(BSTNode* pRoot); //�ݹ������������������� 
void DestroyBSTreeByRecursion(BSTNode** pRoot); //�ݹ�����ٶ���������

void TestBSTree();   //���Զ���������