#ifndef CD_COLOR_H
#define CD_COLOR_H

struct CDColor {
    float r;
    float g;
    float b;
    float a;
};

void CDColor_print(struct CDColor *color);

#endif
