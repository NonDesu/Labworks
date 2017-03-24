#include <cstdlib>
#include <iostream>
#include <ctime>
#define K 10
#define N 4
#define M 4
using namespace std;
void INPUT(int *p, int n){
    int i;
    srand(time(0));
    for(i=0;i<n;i++)
        *(p+i)=rand()%10;
        //scanf("%d",(p+i));
}
void OUTPUT(int *p, int n, int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            printf("%4d ",*(p+i*m+j));
    printf("\n"); 
    }   
}
int* MINDX(int *p, int n){
    int i,*d=p,v=*p;
    for(i=0;i<n;i++)
        if(*(p+i)<v){
            v=*(p+i);
            d=p+i;
        }
    return d;    
}
void CHECK(int *p, int n){
    int i,m=*p;
    for(i=0;i<n;i++)
        if(*(p+i)<m)m=*(p+i);
    for(i=0;i<n;i++)
        if(*(p+i)==m)throw std::exception();
            
}
int main(){
int a[K],b[N][M],i,temp,*ai,*bi;

printf("A:\n");
INPUT(&a[0],K);
OUTPUT(&a[0],K,1);
printf("B:\n");
INPUT(&b[0][0],N*M);
OUTPUT(&b[0][0],N,M);
CHECK(&a[0],K);
CHECK(&b[0][0],N*M);
ai=MINDX(&a[0],K);
bi=MINDX(&b[0][0],N*M);

temp=*ai;
*ai=*bi;
*bi=temp;

OUTPUT(&a[0],K,1);
OUTPUT(&b[0][0],N,M);    
    system("PAUSE");
    return EXIT_SUCCESS;
}
