#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int * naalokuj_pamet(const int len) {
    int * arr_aloc = NULL;
    arr_aloc = (int *) malloc(len * sizeof(int));
    
    if (!arr_aloc) {fprintf(stderr, "out of memory"); exit(-1);}
    
    return arr_aloc; 
}
void * napln_pamet( int * array, int len) { 
    for (int i = 0; i < len; i += 1) {
        scanf("%d", &(array[i])); 
    }
    return 0;
}
void * rozlis_cisla( int * array, int len) { 
    for (int i = 0; i < len; i += 1) {
        if (array[i] % 2 == 0) {
            printf("%d even\n", array[i]); 
        } else if(array[i] % 2 == 1) {
            printf("%d odd\n", array[i]); 
        } else {printf("chyba"); }
    }
    return 0;
}
void * uvolni_pamet(int ** arr_aloc) {
    free(*arr_aloc);
    *arr_aloc = NULL;
    return 0;
}
int main(void) {
    int len = 0;
  
    scanf("%d", &len);
    int * arr = naalokuj_pamet(len);
    napln_pamet(arr, len);
    rozlis_cisla(arr, len);
    uvolni_pamet(&arr);
    return 0;
}
