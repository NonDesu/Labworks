#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#define NA 6 
#define MA 9
#define NB 6
#define MB 7
using namespace std;
void INPUT(int **p, int n, int m){
    int i,j;
    srand(time(0));
    for(i=0;i<n;i++){for(j=0;j<m;j++)
        p[i][j]=rand()%10;}
        //scanf("%d",(p+i));
}
void OUTPUT(int **p, int n, int m){
    int i,j;
    for(i=0;i<n;i++){
        if(p[i]!=NULL){
        for(j=0;j<m;j++)
            printf("%4d ",p[i][j]);
        printf("\n");
        } 
    }
    printf("\n");   
}
void SHIFT(int **p, int n, int m, int x){
int i,j;
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        if(p[i][j]==x){
            free(p[i]);        
        }
    }    
}
}                     
int main(){
int **a,**b,i;
a=(int **)malloc(NA*sizeof(int *));
    for(i=0;i<NA;i++){
        a[i]=(int *)malloc(MA*sizeof(int));
    }
b=(int **)malloc(NB*sizeof(int *));
    for(i=0;i<NB;i++){
        b[i]=(int *)malloc(MB*sizeof(int));
    }

INPUT(a,NA,MA);
INPUT(b,NB,MB);
OUTPUT(a,NA,MA);
OUTPUT(b,NB,MB);
SHIFT(a,NA,MA,1);
SHIFT(b,NB,MB,0);
OUTPUT(a,NA,MA);
OUTPUT(b,NB,MB);
for(int i=0;i<NA;i++){
    if(a[i]!=NULL)
    free(a[i]);
}
free(a);
for(int i=0;i<NB;i++){
    if(b[i]!=NULL)
    free(b[i]);
}
free(b);   
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
