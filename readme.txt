二叉搜索树：

typedef int DataType; 
typedef struct BSTreeNode 
{
    struct BSTreeNode* _pLeft; 
    struct BSTreeNode* _pRight; 
    DataType _data;
}BSTNode; 


void InitBSTree(BSTNode** pRoot);  // 初始化二叉搜索树 
void InsertBSTree(BSTNode** pRoot, DataType data); // 插入值为data的元素 
void DeleteBSTree(BSTNode** pRoot, DataType data); // 删除值为data的结点 
BSTNode* FindBSTree(BSTNode* pRoot, DataType data);  // 在二叉搜索树中查找值为data的结点 

BSTNode* FindBSTreeByRecursion(BSTNode* pRoot, DataType data); //递归地查找值为data的结点
void InsertBSTreeByRecursion(BSTNode** pRoot, DataType data); //递归地插入值为data的元素
void PreOrderByRecursion(BSTNode* pRoot); //递归地中序遍历二叉搜索树 
void DestroyBSTreeByRecursion(BSTNode** pRoot); //递归地销毁二叉搜索树

void TestBSTree();   //测试二叉搜索树