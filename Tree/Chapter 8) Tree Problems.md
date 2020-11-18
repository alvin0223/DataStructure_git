### Chapter 8) Tree Problems

##### 18번) 숫자들이 들어있는 이진 탐색 트리를 중위 순회하면 정렬된(오름차순) 숫자가 얻어진다. 이를 이용해 다음 배열에 들어있는 숫자들을 정렬시키는 함수를 구현하라.(배열에 들어있는 숫자들을 이진 탐색 트리에 추가한 후에 트리를 중위 순회하면서 숫자들을 출력하면 된다.)

11 / 3 / 4 / 1 / 56 / 5 / 6 / 2 / 98 / 32 / 23

```c
/*header file*/
#include <stdio.h>
#include <stdlib.h>

typedef struct tagBSTNode
{
    struct tagBSTNode* left;
    struct tagBSTNode* right;
    int data;
}BSTNode;
/*function prototype*/
BSTNode* BST_CreateNode(int NewData);
void BST_DestroyNode(BSTNode* node);
void BST_DestroyTree(BSTNode* Tree);

BSTNode* BST_InsertNode(BSTNode* Tree, BSTNode* New);
BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, int target);
BSTNode* BST_InorderPrintTree(BSTNode* Tree);
```



```c
/*구현 파일*/
/*이진 탐색 트리에서의 노드 삽입*/
#include "BinarySearchTree.h"
void BST_InsertNode(BSTNode** Tree, BSTNode* New)
{
    if((*Tree)->data < New->data)
    {
        if((*Tree)->right==NULL)
            (*Tree)->right=NULL;
        else
            BST_InsertNode(&((*Tree)->right), New);
    }
    else
    {
        if((*Tree)->left==NULL)
            (*Tree)->left=NULL;
        else
            BST_InsertNode(&((*Tree)->left), New);
    }
}
/*중위 순회*/
void BST_InorderPrintTree(BSTNode* Node)
{
    if(Tree==NULL)
        return;
    BST_InorderPrintTree(Node->left);
    printf("%c -> ",Node->data);
    BST_InorderPrintTree(Node->right);
}
```

```c
//BinarySearchTree.c file(실행 파일)
#include "BinarySearchTree.h"

int main(void)
{
    /*트리 노드 생성*/
    BSTNode* Tree=BST_CreateNode(11);
    
    /*트리에 노드 추가*/
    int num_array[11]={11,3,4,1,56,5,6,2,98,32,23};
    for(int i=0;i<11;i++)
    {
        BST_InsertNode(&Tree,BST_CreateNode(num_array[i]));
    }
                  
    BST_InorderPrintTree(Tree);
    return 0;
}
```



##### 19번) 18번은 오름차순으로 정렬시키는 경우이다. 이진 탐색 트리를 활용하여 배열에 저장된 숫자들을 내림차순으로 정렬시키는 함수를 구현하라

오른쪽 하위트리 -> 루트 노드 -> 왼쪽 하위 트리 순으로 순회하면 된다. 즉, 순회 함수만 바꾸어주면된다.

```c
void BST_ReversePrintTree(BSTNode* Node)
{
    if(Tree==NULL)
        return;
    BST_InorderPrintTree(Node->right);
    printf("%c -> ",Node->data);
    BST_InorderPrintTree(Node->left);
}
```



##### 20번) 이진 탐색 트리의 모든 노드의 값을 1씩 증가시키는 함수를 구현하라

```

```

##### 22번) 이진 탐색 트리의 가장 큰 용도는 map(사전)이라는 자료구조를 구현하는 것이다. 이진탐색 트리를 이용하여 친구들의 연락처를 저장하고 탐색하는 프로그램을 작성해보자.

```

```

