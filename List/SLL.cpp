#include "SLL.h"

//��ʼ����̬����
Status InitList(StaticLinkList space){
	for (int i = 0; i < MAXSIZE - 1; ++i){
		space[i].data = 0;
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
	return OK;
}
//��̬����ĳ���
int	ListLength(StaticLinkList L){
	int i = 0;
	int k = L[MAXSIZE - 1].cur;
	while (k){
		i++;
		k = L[k].cur;
	}
	return i;
}
//��̬�����е�i��Ԫ��֮ǰ����Ԫ��
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

//��ȡԪ��
Status GetElem(StaticLinkList L, int i, ElementType *e){
	if (i < 1 || (i > ListLength(L)))
		return ERROR;
	int k = MAXSIZE - 1;
	for (int l = 0; l < i; ++l)
		k = L[k].cur;
	*e = L[k].data;
	return OK;
}
//ɾ����̬�����е�i��Ԫ��
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
//�ڱ����������ó�һ���ڵ����
int Malloc_SLL(StaticLinkList space){
	int ret;
	ret = space[0].cur;
	if (ret)//�жϷǿ�
		space[0].cur = space[ret].cur;
	return ret;

}
//���սڵ㵽��������
void Free_SLL(StaticLinkList space, int pos){
	space[pos].cur = space[0].cur;
	space[0].cur = pos;
}