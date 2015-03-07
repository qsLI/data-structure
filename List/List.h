#ifndef __DATA_STRUCTURE__
#define __DATA_STRUCTURE__

#define OK 1
#define ERROR 0
#define TRUE 1
#define  FALSE 0

typedef int Status;
//Max length
#define MAXSIZE 20 
typedef int ElementType;

typedef struct{
	ElementType data[MAXSIZE];
	int length;
}Sqlist;

//get element from list
Status GetElem(Sqlist L, int i, ElementType *e);
//insert element to the position of i in list 
Status ListInsert(Sqlist *L, int i, ElementType e);
//delete element at position i
Status ListDelete(Sqlist *L, int i, ElementType e);

#endif 
