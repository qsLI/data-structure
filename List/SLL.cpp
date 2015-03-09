#include "SLL.h"

//初始化静态链表
Status InitList(StaticLinkList space){
	for (int i = 0; i < MAXSIZE - 1; ++i){
		space[i].data = 0;
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
	return OK;
}
//求静态链表的长度
int	ListLength(StaticLinkList L){
	int i = 0;
	int k = L[MAXSIZE - 1].cur;
	while (k){
		i++;
		k = L[k].cur;
	}
	return i;
}
//向静态链表中第i个元素之前插入元素
Status ListInsert(StaticLinkList L, int i, ElementType e){
	if ((i > ListLength(L) + 1) || i < 1)
		return ERROR;

	int pos = Malloc_SLL(L);
	if (pos){
		L[pos].data = e;
		int j = MAXSIZE - 1;
		for (int l = 1; l < i; ++l)
			j = L[j].cur;

		L[pos].cur = L[j].cur;
		L[j].cur = pos;
		return OK;
	}

	return ERROR;

}

//获取元素
Status GetElem(StaticLinkList L, int i, ElementType *e){
	if (i < 1 || (i > ListLength(L)))
		return ERROR;
	int k = MAXSIZE - 1;
	for (int l = 0; l < i; ++l)
		k = L[k].cur;
	*e = L[k].data;
	return OK;
}
//删除静态链表中第i个元素
Status	ListDelete(StaticLinkList L, int i){
	if (i < 1 || (i > ListLength(L)))
		return ERROR;
	int k = MAXSIZE - 1;
	for (int l = 1; l < i; ++l)
		k = L[k].cur;
	int pos = L[k].cur;
	L[k].cur = L[pos].cur;
	Free_SLL(L, pos);
	return OK;

}
//在备份链表中拿出一个节点分配
int Malloc_SLL(StaticLinkList space){
	int ret;
	ret = space[0].cur;
	if (ret)//判断非空
		space[0].cur = space[ret].cur;
	return ret;

}
//回收节点到备份链表
void Free_SLL(StaticLinkList space, int pos){
	space[pos].cur = space[0].cur;
	space[0].cur = pos;
}