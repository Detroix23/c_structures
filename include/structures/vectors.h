// include/structures/vectors.h
#ifndef STRUCTURES_VECTORS_H
#define STRUCTURES_VECTORS_H

/**
 * # A `Vector2D` of 2 `float`s.
 * See `structures/vectors` for methods.
 */
struct Vector2D {
    float x;
    float y;
};

void consume(struct Vector2D v);

/**
 * Compute the length **squared** of vector `v`.
 */
float length2(struct Vector2D *v);

/**
 * Compute the length of vector `v`.
 */
float length(struct Vector2D *v);

/**
 * Returns a normalized **copy** of vector `v`.
 */
struct Vector2D normalized(struct Vector2D *v);

/**
 * Normalize `v` and returns the updated vector. 
 */
void normalize(struct Vector2D *v);

# endif
