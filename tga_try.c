#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>




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
} Pixel;

Pixel* load_pixels(TGAHeader header, FILE* file) {
    int width = 0;
    int height = 0;
    
    memcpy(&width, header.width, 2);
    memcpy(&height, header.height, 2);

    Pixel* pixels = (Pixel*) malloc(sizeof(Pixel) * width * height);
    assert(fread(pixels, sizeof(Pixel) * width * height, 1, file) == 1);
    return pixels;
}

int main (){
    FILE* file = fopen("aw.tga", "rb");


    TGAHeader header = {};
    assert(fread(&header, sizeof(TGAHeader), 1, file) == 1);

    Pixel* pixels = load_pixels(header, file);

    int width = 0;
    int height = 0;
    
    memcpy(&width, header.width, 2);
    memcpy(&height, header.height, 2);


    printf("%d %d Image width:  %d , pixel height: %d,  %d\n",header.image_type, header.depth, width, height, header.descriptor);
    //printf("pixels %d \n", (pixels[6]).blue ); 

    //for h in 0 .. header.heigh
    for(int h=0; h<width; ++h) { // w in 0 .. header.width
        for(int w=0; w<width; ++w) { // w in 0 .. header.width
            Pixel* current = &pixels[w + h*width];
            printf("%d,%d,%d, %d : ",
                current->blue,
                current->red,
                current->green,
                current->alpha);

        }
        printf("\n");
    }
}
