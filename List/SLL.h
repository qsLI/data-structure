#ifndef __STATIC_LINK_LIST__
#define __STATIC__LINK_LIST__

#define		OK		1
#define		ERROR		0
#define		Status		int
#define		ElementType	int
#define		MAXSIZE		50
typedef struct 
{
	ElementType data;
	int cur;
}Component,StaticLinkList[MAXSIZE];

//初始化静态链表
Status InitList(StaticLinkList space);
//求静态链表的长度
int	ListLength(StaticLinkList L);
//向静态链表中第i个元素之前插入元素
Status ListInsert(StaticLinkList L, int i, ElementType e);
//获取元素
Status GetElem(StaticLinkList L, int i, ElementType *e);
//删除静态链表中第i个元素
Status	ListDelete(StaticLinkList L, int i);
//在备份链表中拿出一个节点分配
int Malloc_SLL(StaticLinkList space);
//回收节点到备份链表
void Free_SLL(StaticLinkList space, int pos);
#endif // !__STATIC_LINK_LIST__
