// src/structures/vectors.c
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../../include/structures/vectors.h"

struct Vector2D;

float vector_length2(struct Vector2D *v) 
{
    return v->x * v->x + v->y * v->y;
};

float vector_length(struct Vector2D *v)
{
    return sqrtf(vector_length2(v));
};

struct Vector2D vector_normalized(struct Vector2D *v)
{
    struct Vector2D n = *v;
    vector_normalize(&n);
    return n;
}

void vector_normalize(struct Vector2D *v)
{
    float l = vector_length(v);
    v->x /= l;
    v->y /= l;
    return;
}
