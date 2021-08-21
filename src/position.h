#ifndef CD_POSITION_H
#define CD_POSITION_H


struct CDPosition {
    float x;
    float y;
    float z;
};

void CDPosition_print(struct CDPosition *p);

#endif
