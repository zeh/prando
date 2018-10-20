#include<stdio.h>
#include<math.h>


int main (){
    int Number;
    bool Prime = true ;

    scanf("%d",&Number);
    for(int i = 2; i <= sqrt(Number); i++ ){
        if( Number % i == 0)
            Prime = false;
    }
    if(Number > 1 and Prime == true)
        printf("Prime");
    else
        printf("Not Prime");
}
