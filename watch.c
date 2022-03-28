#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

const int WIDTH = 368;
const int HEIGHT = 448;
const int mezera = 15; 
const int tloustka = 30;
const int tloustka_stred = 35;
const int sirka_num = WIDTH/2 - 2*mezera;
const int delka_num = tloustka + tloustka_stred + 50;



const int digit_part [10][7]= {
    {1,1,1,0,1,1,1}, //cislo 0
    {0,0,1,0,0,1,0}, //1
    {1,0,1,1,1,0,1}, //2
    {1,0,1,1,0,1,1}, //3
    {0,1,1,1,0,1,0}, //4
    {1,1,0,1,0,1,1}, //5
    {1,1,0,1,1,1,1}, //6
    {1,0,1,0,0,1,0}, //7
    {1,1,1,1,1,1,1}, //8
    {1,1,1,1,0,1,1}, //9
};


typedef FILE TGAImage;

typedef unsigned char byte;

typedef struct {
    byte id_length;
    byte color_map_type;
    byte image_type;
    byte color_map[5];
    byte x_origin[2];
    byte y_origin[2];
    byte width[2];
    byte height[2];
    byte depth;
    byte descriptor;
} TGAHeader;


typedef struct {
    byte blue;
    byte green;
    byte red;
    byte alpha;
} RGBA;

bool is_Number_Pixel( int x, int y, const int * array){ // hodnota na souradnicich x,y hledana v souradnicih digit parts 
    if (array[0]==1 && x>=mezera && x < (mezera + sirka_num) && y >= mezera && y < (mezera+tloustka)) return true;
    else if (array[1]==1 && x>=mezera && x < (mezera + tloustka) && y >= mezera && y < (mezera+delka_num)) return true;
    else if (array[2]==1 && x>=(sirka_num+mezera-tloustka) && x < (sirka_num+mezera) && y >= mezera && y < (mezera+delka_num)) return true;
    else if (array[3]==1 && x>=mezera && x < (mezera + sirka_num) && y >= (mezera+delka_num-tloustka_stred) && y < (mezera+delka_num)) return true;
    else if (array[4]==1 && x>=mezera && x < (mezera + tloustka) && y >= (mezera+delka_num-tloustka_stred) && y < (HEIGHT/2 - mezera)) return true;
    else if (array[5]==1 && x>=(sirka_num+mezera-tloustka) && x < (sirka_num+mezera) && y >= (mezera+delka_num-tloustka_stred) && y < (HEIGHT/2 - mezera)) return true;
    else if (array[6]==1 && x>=mezera && x < (mezera + sirka_num) && y >= (HEIGHT/2-mezera-tloustka) && y < (HEIGHT/2 - mezera)) return true;
    else return false;
}


void watch_draw_time(TGAImage* self, const int hours, const int minutes) {
    
    div_t divide;

    divide = div(hours, 10);
    int hours1 = divide.quot;
    int hours2 = divide.rem;

    divide = div(minutes, 10);
    int minutes1 = divide.quot;
    int minutes2 = divide.rem;  
    
    //printf("hod %d %d minuty %d %d\n", hours1, hours2, minutes1, minutes2);


    RGBA pozadi = {};  
    pozadi.blue = 255;
    pozadi.green = 204;
    pozadi.red = 153;
    pozadi.alpha = 255;

    RGBA numbers = {};
    numbers.blue = 94;
    numbers.green = 81;
    numbers.red = 89;
    numbers.alpha = 255;
    
    RGBA* pixels = (RGBA*) malloc(sizeof(RGBA) * WIDTH * HEIGHT);
    for(int h = 0; h < HEIGHT/2; ++h) { 
        for(int w=0; w<WIDTH/2; ++w) { 
            if (is_Number_Pixel(w,h,digit_part[hours1])){
                pixels[w + h*WIDTH] = numbers;
                //printf("pixels %d \n", pixels[w + h*width].blue );
                //printf("pixels %d \n", pixels[w + h*width].green );
                //printf("pixels %d \n", pixels[w + h*width].red);
                //printf("pixels %d \n", pixels[w + h*width].alpha);
            } else pixels[w + h*WIDTH] = pozadi;
        }
     
        for(int w = WIDTH/2; w < WIDTH; ++w) { 
            int korekce_x = w-WIDTH/2;
            if (is_Number_Pixel(korekce_x,h,digit_part[hours2])){
                pixels[w + h*WIDTH] = numbers;
            } else pixels[w + h*WIDTH] = pozadi;
        }
    } 
    
    for(int h = HEIGHT/2; h < HEIGHT; ++h) { 
        for(int w=0; w < WIDTH/2; ++w) { 
            int korekce_y = h-HEIGHT/2;
            if (is_Number_Pixel(w,korekce_y,digit_part[minutes1])){
                pixels[w + h*WIDTH] = numbers;
            } else pixels[w + h*WIDTH] = pozadi;
        }

        for(int w = WIDTH/2; w < WIDTH; ++w) { 
            int korekce_x = w-WIDTH/2;
            int korekce_y = h-HEIGHT/2;           
            if (is_Number_Pixel(korekce_x,korekce_y,digit_part[minutes2])){
                pixels[w + h*WIDTH] = numbers;
            } else pixels[w + h*WIDTH] = pozadi;
        }
    }
    fwrite(pixels, 1, sizeof(RGBA) * WIDTH * HEIGHT, self);  
          //  printf("size - pixels %d \n", sizeof(*pixels));
    free(pixels);

    
}

void watch_draw_time_color(TGAImage* self, const int hours, const int minutes, const RGBA* fg_color, const RGBA* bg_color){  

    div_t divide;

    divide = div(hours, 10);
    int hours1 = divide.quot;
    int hours2 = divide.rem;

    divide = div(minutes, 10);
    int minutes1 = divide.quot;
    int minutes2 = divide.rem;  
    
    
    RGBA* pixels = (RGBA*) malloc(sizeof(RGBA) * WIDTH * HEIGHT);
    for(int h = 0; h < HEIGHT/2; ++h) { 
        for(int w=0; w<WIDTH/2; ++w) { 
            if (is_Number_Pixel(w,h,digit_part[hours1])){
                pixels[w + h*WIDTH] = *fg_color;
            } else pixels[w + h*WIDTH] = *bg_color;
        }
     
        for(int w = WIDTH/2; w < WIDTH; ++w) { 
            int korekce_x = w-WIDTH/2;
            if (is_Number_Pixel(korekce_x,h,digit_part[hours2])){
                pixels[w + h*WIDTH] = *fg_color;
            } else pixels[w + h*WIDTH] = *bg_color;
        }
    } 
    
    for(int h = HEIGHT/2; h < HEIGHT; ++h) { 
        for(int w=0; w < WIDTH/2; ++w) { 
            int korekce_y = h-HEIGHT/2;
            if (is_Number_Pixel(w,korekce_y,digit_part[minutes1])){
                pixels[w + h*WIDTH] = *fg_color;
            } else pixels[w + h*WIDTH] = *bg_color; 
            
        }
        for(int w = WIDTH/2; w < WIDTH; ++w) { 
            int korekce_x = w-WIDTH/2;
            int korekce_y = h-HEIGHT/2;           
            if (is_Number_Pixel(korekce_x,korekce_y,digit_part[minutes2])){
                pixels[w + h*WIDTH] = *fg_color;
            } else pixels[w + h*WIDTH] = *bg_color;
        }
    }
    fwrite(pixels, 1, sizeof(RGBA) * WIDTH * HEIGHT, self);  
          //  printf("size - pixels %d \n", sizeof(*pixels));
    free(pixels);
}



int main (int argc, char **argv){

    assert(argc == 3);

    //HOURS and MINUTES 

    const int hours = atoi(argv[1]);
    const int minutes = atoi(argv[2]);
    assert( hours >= 0);
    assert( hours <24);
    assert( minutes >= 0);
    assert( minutes < 60);

    // IMAGE
    
    TGAImage* Image = fopen("aw.tga", "wb");
    assert(Image);

    //HEADER PART

    TGAHeader header;

    //memset(&header, 0, sizeof(TGAHeader));

    header.id_length = 0;
    header.color_map_type = 0;
    header.image_type = 2;

    byte nula[5] = {0,0,0,0,0};
    memcpy(&header.color_map, nula, 5);
    memcpy(&header.x_origin, nula, 2);
    memcpy(&header.y_origin, nula, 2);
    memcpy(&header.width, &WIDTH, 2);
    memcpy(&header.height, &HEIGHT, 2);
    header.depth = 32; 
    header.descriptor = 40;
     
    fwrite(&header, 1, sizeof(TGAHeader), Image);

//TIME DRAW

    //watch_draw_time(Image, hours, minutes);

    //COLOR DEFINITION

    RGBA fg_color; 
    fg_color.red = 255;
    fg_color.green = 0;
    fg_color.blue = 0;
    fg_color.alpha = 255; 

    RGBA bg_color;
    bg_color.red = 255;
    bg_color.green = 255;
    bg_color.blue = 0;
    bg_color.alpha = 255; 

// COLOR TIME DRAW
    watch_draw_time_color(Image, hours, minutes, &fg_color, &bg_color);

     
    assert(!fclose(Image));
}
