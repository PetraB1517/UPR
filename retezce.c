#include <stdio.h>
#include <stdlib.h>   
#include <string.h>
#include <stdbool.h>   

const int LEN = 101;

char * naalokuj_pamet(int len) {
    char * arr_aloc = NULL;
    arr_aloc = (char *) malloc(len * sizeof(char));
    
    if (!arr_aloc) {fprintf(stderr, "out of memory"); exit(-1);}
    
    return arr_aloc; 
}

void * uvolni_pamet(char ** arr_aloc) {
    free(*arr_aloc);
    *arr_aloc = NULL;
    return 0;
}

bool is_char(char vstup) {
    for (char i = 65; i < 91; i++){
        if (vstup == i) return true;    
    }
    for (char k = 97; k < 123; k++){
        if (vstup == k) return true;
    } 
    return false;
}


int main(void) {

    char vstup[LEN];

    while ( fgets(vstup, LEN, stdin) ) { 
        int justStringLen = 0;
        int rLen = strlen(vstup);
        for (int j = 0; j < rLen; j++) {
            if (is_char(vstup[j]) == true) justStringLen +=1;    
        }
        
        if (justStringLen > 0) {
            char * justString = naalokuj_pamet(justStringLen);
            int index = 0;
            for (int j = 0; j < rLen; j++) {
            
                if (is_char(vstup[j]) == true){
                    justString[index] = vstup[j];
                    index +=1;
                    if (index > justStringLen) {printf("Chyba v programu"); exit(-1);}
                }
            }
            for (int i = 0; i < justStringLen; i++) {
                printf("%c", justString[i]);
            }
            printf("\n");
            uvolni_pamet(&justString);
        }
    }  

  return 0;
}
