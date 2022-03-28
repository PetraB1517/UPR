#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float * softmax( const float * array, const int len ) {
    float*  softedArray;

    return softedArray;
}

int argmax( const float * array, const int len ) {
    int number;
    
    return number;
        
}

float * naalokuj_pamet(const int len) {
    float * arr_aloc = NULL;
    arr_aloc = (float *) malloc(len * sizeof(float));
    
    if (!arr_aloc) {fprintf(stderr, "out of memory"); exit(-1);}
    
    return arr_aloc; 
}

void * uvolni_pamet(float * arr_aloc) {
    free(arr_aloc);
    arr_aloc = NULL;
}

int main() {
    int numOfEl = 0;

    const int len = 10;
    
    scanf("%d", &numOfEl);
    float * arr_aloc = naalokuj_pamet(len);
    
    for (int i = 0; i < numOfEl; i += 1){
        for (int j = 0; j < len; j += 1){
            scanf("%f", &(arr_aloc[j]));
        }
        float * softedArray = softmax (arr_aloc, len);
        int number = argmax (softedArray, len);
        printf("%d %f4", number );
        
    }
    
    uvolni_pamet(arr_aloc);


    return 0;
}
