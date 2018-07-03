#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    while(1){
        int dies, faces;
        int res = scanf("%dd%d", &dies, &faces);
        if(res==2){
            int roll = rand() % (dies*faces);
            printf("%d\n", roll);
        }else{
            printf("bad input! Use format ##d##\n");
            // eat input until we clear the "buffer"
            char c;
            while ((c = getchar()) != EOF && c != '\n');
        }
    }
    
    return 0;
}
