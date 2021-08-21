#include <stdio.h>
#include "color.h"


void CDColor_print(struct CDColor *color) {
    printf("color r: %0.3f, g: %0.3f, b: %0.3f, a: %0.3f\n",
            color->r, color->g, color->b, color->a);
}
