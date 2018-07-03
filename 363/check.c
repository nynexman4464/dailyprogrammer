#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* Return 1 if the given string follows the "I before E except after C"
*/
int check(char * str) {
	size_t len = strlen(str);
	char *lower = malloc(len+1);
	strncpy(lower, str, len+1);
	// simple case 
	if(strstr(lower, "cie")){
		free(lower);
		return 0;
	}
	char * ptr = lower;
	do{
		ptr = strstr(ptr, "ei");
		if(ptr != NULL && (ptr == lower || *(ptr-1) != 'c') ){
			free(lower);
			return 0;
		}else if(ptr != NULL && ptr+2<lower+len){
			// move pointer forward past the 'ei'
			ptr += 2;
		}else{
			//end of string
			break;
		}
	}while(ptr != NULL);
	free(lower);
	return 1;
}

int main(int argc, const char* argv[]){
    FILE * file = fopen("/Users/alexanderr/Downloads/enable1.txt", "r");
    if(file==NULL){
        return -1;
    }
    char * buf = malloc(1000);
    while(1){
        char *res = fgets(buf, 1000, file);
        if(res==NULL){
            break;
        }
        buf[strcspn(buf, "\r\n")] = 0;
        if(argc>1){
            printf("%s - %d\n", buf, check(buf));
        }else{
            printf("%d\n", check(buf));
        }
    }
    fclose(file);
    free(buf);
	return 0;
}
