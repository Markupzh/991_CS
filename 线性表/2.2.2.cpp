#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
#define ElemType char

//����˳���Ľṹ��
typedef struct {
	ElemType data[MaxSize];
	int length;
} SqList; 

//2.2.2������� 
bool ListInsert(SqList &L, int i, ElemType e){
	if(i < 1 || i > L.length)
		return false;
	if(L.length >= MaxSize)
		return false;
	for(int j = L.length; j >= i; j--){
		L.data[j] = L.data[j - 1];
	}				 
	L.data[i-1] = e;
	L.length++;
	return true;
}
//2.2.2ɾ������
char ListDelete(SqList &L, int i, ElemType e)
{
	if (i < 1 || i > L.length)
		return false;
	e = L.data[i - 1];
	for(int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	
	return e;
 } 
 
//2.2.2��ֵ����
int LocateElem(SqList L, ElemType e){
	for(int i = 0; i < L.length; i++)
		if(L.data[i] == e)
			return i+1;
	return 0; 
} 

int main(void){
    SqList l;
    l.length = 4;
    l.data[0] = 'a';
    l.data[1] = 'b';
    l.data[2] = 'c';
    l.data[3] = 'd';
//    int value = -1;

	//��ӡ����֮ǰ������ 
    for (int i = 0; i < l.length; ++i) {
        printf("%c", l.data[i]);
    }
    printf("\n");
    
    //���ú����������� 
    ListInsert(l, 2, 'z');
    printf("--------------\n");
    for (int i = 0; i < l.length; ++i) {
        printf("%c", l.data[i]);
    }
    printf("\nnow length is %d\n", l.length);

	printf("----------------\n");	
	
	char elem = ListDelete(l, 2, 'x');
	for (int i = 0; i < l.length; ++i) {
		printf("%c",l.data[i]);
	}
	printf("\ndelete elem is %c\n", elem);
    printf("\nnow length is %d\n", l.length);
	
	printf("----------------\n");	
	int num = LocateElem(l, 'c');	
	printf("get num is %d\n", num);
	
	return 0;
}
