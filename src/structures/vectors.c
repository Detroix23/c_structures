// src/structures/vectors.c
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../../include/structures/vectors.h"

struct Vector2D;

void consume(struct Vector2D v)
{
    printf(
        "(?) %s:%d %s() Miam v(%f, %f).\n",
        __FILE__, __LINE__, __FUNCTION__, v.x, v.y
    );

    return;
}

float length2(struct Vector2D *v) 
{
    return v->x * v->x + v->y + v->y;
};

float length(struct Vector2D *v)
{
    return sqrtf(length2(v));
};

