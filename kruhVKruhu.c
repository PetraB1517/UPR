#include <stdbool.h>
#include <stdio.h>
#include <math.h>
typedef struct {
    float x;
    float y;
} Point2;
typedef struct {
    Point2 center;
    int radius;
} Circle;
float square(float b)
{
    float z;
    z = b*b;
    return(z);
}
bool circle_contains_circle( const Circle * self, const Circle * other ){
    float vzdalenostS1S2 = sqrtf(square(other-> center.x - self-> center.x) + square(other-> center.y - self-> center.y) );
    if (vzdalenostS1S2 + other->radius < self->radius) return true;
    else return false;
}
int main() {
  Circle kruh1;  
  Circle kruh2;  
  
  scanf("%f %f %d \n", &kruh1.center.x, &kruh1.center.y, &kruh1.radius);
  scanf("%f %f %d \n", &kruh2.center.x, &kruh2.center.y, &kruh2.radius);
  
  bool vysledek = circle_contains_circle( &kruh1, &kruh2 );
  printf(vysledek ? "True" : "False");
    return 0;
}
