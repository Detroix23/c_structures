// src/structures/vectors.c
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../../include/structures/vectors.h"

struct Vector2D;

float length2(struct Vector2D *v) 
{
    return v->x * v->x + v->y * v->y;
};

float length(struct Vector2D *v)
{
    return sqrtf(length2(v));
};

struct Vector2D normalized(struct Vector2D *v)
{
    struct Vector2D n = *v;
    normalize(&n);
    return n;
}

void normalize(struct Vector2D *v)
{
    float l = length(v);
    v->x /= l;
    v->y /= l;
    return;
}
