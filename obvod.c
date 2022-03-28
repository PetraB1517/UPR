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

float circle_circumference (const Circle * self ) {
  return 2 * M_PI * self->radius;
}

int main() {

  Circle kruh;  

  scanf("%f %f %d", &kruh.center.x, &kruh.center.y, &kruh.radius);
  
  float obvod = circle_circumference( &kruh );
  printf("%.2f", obvod);
    return 0;
}
