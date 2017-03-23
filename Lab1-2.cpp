#include <cstdlib>
#include <iostream>
#include <ctime>
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
    printf("\n");   
}
void SHIFT(int *p, int n, int m, int x){
int i,j,k,l;
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        if(*(p+i*m+j)==x){
            if(i!=(n-1)){
            for(k=i;k<(n-1);k++){
                for(l=0;l<m;l++){
                    *(p+k*m+l)=*(p+(k+1)*m+l);
                    *(p+(k+1)*m+l)=0;    
                }    
            }
            }
            else{
                for(l=0;l<m;l++){
                    *(p+k*m+l)=0;
                }
            }    
        }
    }    
}
}                     
int main()
{
int a[5][8],b[5][6];   
INPUT(&a[0][0],54);
INPUT(&b[0][0],42);
OUTPUT(&a[0][0],6,9);
OUTPUT(&b[0][0],6,7);
SHIFT(&a[0][0],6,9,1);
SHIFT(&b[0][0],6,7,0);
OUTPUT(&a[0][0],6,9);
OUTPUT(&b[0][0],6,7);   
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
