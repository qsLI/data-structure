#include "List.h"

//get element from list
Status GetElem(Sqlist L, int i, ElementType *e){
       if(L.length == 0 || i < 0 || L.length < i)
                   return ERROR;
       e = L.data[i-1];
       return OK;
} 
//insert element to the position of i in list 
Status ListInsert(Sqlist *L, int i, ElementType e){
       if(L->length == MAXSIZE)
                    printf("the list is full\n");
                    return ERROR;
       if(i < 1 || i > L->length + 1)
            return ERROR;
       if(i < L->length){
            for(int k = L->length - 1; k >= i - 1; --k)
                    L->data[k] = L->data[k+1];
            L->data[i-1] = e;
            }else{
                   //in the position length + 1
                   L->data[i] = e;                  
                   }
        L->lenght++;
        return OK;
}
//delete element at position i
Status ListDelete(Sqlist *L, int i, ElementType e){
       if(L->length == 0)
            return ERROR;
       if(i < 1 || i > L->length)
            return ERROR;
       if(i < L->length){
           for(int k = i - 1; k < L->length; ++k){
                   L->data[k] = L->data[k+1];
                   }
           }
       L->length--;
       return OK;
}
               
       
