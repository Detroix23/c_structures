// src/structures/vectors.c
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../../include/structures/vectors.h"

struct Vector2D;

/** Returns the length squared. */
float vector_length2(struct Vector2D *v) 
{
    return v->x * v->x + v->y * v->y;
}

/** Returns the length using a square root. */
float vector_length(struct Vector2D *v)
{
    return sqrtf(vector_length2(v));
}

/** Returns a normalized **copy** of `v`. */
struct Vector2D vector_normalized(struct Vector2D *v)
{
    struct Vector2D n = *v;
    vector_normalize(&n);
    return n;
}

/** Update `v` to normalize it */
void vector_normalize(struct Vector2D *v)
{
    float l = vector_length(v);
    v->x /= l;
    v->y /= l;
    return;
}

