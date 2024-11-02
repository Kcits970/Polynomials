#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUFF 20

struct Poly{
    int *a; // ��� ���� �迭
};
typedef struct Poly Poly;

void AUX(Poly a, Poly b, Poly* res, int s){
    for(int i=0; i<MAX_BUFF; i++){
        res->a[i] = a.a[i]+b.a[i]*s;
    }
}

void printPoly(Poly a){
    for(int i=MAX_BUFF-1; i>=0; i--){
        if(a.a[i]!=0){
            printf("  %dX^%d",a.a[i],i);
        }
    }
}
int YN(){
    int s;
    if(rand()%2!=0)
        s=-1;
    else
        s=1;
    
    return s;
}


void PolyMake(Poly* a, int n){
    int size;

    if(n != 0){
        size = n;
    } else {
        size = MAX_BUFF;
    }
    
    a->a = (int*)malloc(sizeof(int)*MAX_BUFF);

    // �迭 �ʱ�ȭ
    for (int i = 0; i < MAX_BUFF; i++) {
        a->a[i] = 0; // �������� 0���� �ʱ�ȭ
    }

    // ���� �� �Ҵ�
    for (int i = 0; i < size; i++) {
        int index;
        do {
            index = rand() % MAX_BUFF; // 0���� size-1������ ���� �ε���
        } while (a->a[index] != 0); // �̹� ���� �Ҵ�� �ε����� ����

        a->a[index] = (rand() % 10 + 1)*YN(); // 1���� 10������ ���� ��
    }
}

void freePoly(Poly* a){
    free(a->a);
}

int main(){
    Poly a;
    Poly b;
    Poly c;

    srand(time(NULL));

    PolyMake(&a,5);
    printf("f(X) = ");
    printPoly(a);

    printf("\n");

    PolyMake(&b,5);
    printf("g(X) = ");
    printPoly(b);

    PolyMake(&c,0);

    printf("\n\nADD");
    AUX(a,b,&c,1);
    printPoly(c);

    printf("\nSUB");
    AUX(a,b,&c,-1);
    printPoly(c);

    freePoly(&a);
    freePoly(&b);
    freePoly(&c);

    return 0;
}