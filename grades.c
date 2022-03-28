#include <stdio.h>

int compute_grade( int points ) {
    int grade = 4;

    if ( points > 85 ) {
        grade = 1;
    } else if ( points > 65 ) {
	grade = 2; 
    } else if ( points > 50 ) {
	grade = 3;
    } else {
        grade = 4;
    }

    return grade;
}

int main() {
    int points = 0;

    int grade = 0;
    
    while ( scanf("%d", &points ) ) {
	if (points < 0) break;

    	if ( points > 100 ) {
    		 printf("NA\n");
    	} else {
	    	grade = compute_grade ( points );
	    	printf("%d\n", grade );
    	}
    }

    return 0;
}
