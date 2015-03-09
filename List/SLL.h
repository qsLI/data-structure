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

//��ʼ����̬����
Status InitList(StaticLinkList space);
//��̬����ĳ���
int	ListLength(StaticLinkList L);
//��̬�����е�i��Ԫ��֮ǰ����Ԫ��
Status ListInsert(StaticLinkList L, int i, ElementType e);
//��ȡԪ��
Status GetElem(StaticLinkList L, int i, ElementType *e);
//ɾ����̬�����е�i��Ԫ��
Status	ListDelete(StaticLinkList L, int i);
//�ڱ����������ó�һ���ڵ����
int Malloc_SLL(StaticLinkList space);
//���սڵ㵽��������
void Free_SLL(StaticLinkList space, int pos);
#endif // !__STATIC_LINK_LIST__
