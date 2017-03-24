#include <cstdlib>
#include <iostream>
#include <cmath>
#define N 20

using namespace std;
float FUNC1(float x){
    return (2*x*(x*x+1));
}
float FUNC2(float x){
    return (sin(x)/(1+sin(x)));
}
float PARABOLIC(float(*f)(float x),float rs, float re){
float sum=f(rs)+f(re),dx=(re-rs)/N;
for(int i=1;i<N;i++)
    sum+=((i%2==0)?2:4)*f(rs+i*dx);
return dx*sum/3;
}   
int main(){
float rs,re;
printf("Input the range for f1:\n",&rs,&re);
scanf("%g %g",&rs,&re);
printf("f1=%g\n", PARABOLIC(FUNC1,rs,re));
printf("Input the range for f2:\n",&rs,&re);
scanf("%g %g",&rs,&re);
printf("f2=%g\n", PARABOLIC(FUNC2,rs,re));

    system("PAUSE");
    return EXIT_SUCCESS;
}
