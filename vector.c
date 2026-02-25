#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    int32_t *data;
    size_t lenght;
    size_t capacity;
} Vector;

void append(Vector *vector, int32_t value)
{
    if (vector->lenght >= vector->capacity)
    {
        if (vector->capacity == 0)
            vector->capacity = 2;
        else
            vector->capacity *= 2;
        vector->data = realloc(vector->data, vector->capacity * sizeof(*vector->data));
    }

    vector->data[vector->lenght++] = value;
}

void pop(Vector *vector)
{
    assert(vector->lenght > 0 && "Vector should have a lenght > 0 to pop");
    vector->data[vector->lenght] = 0;
    vector->lenght--;
}

int main()
{
    Vector vector = {0};

    for (int i = 0; i < 10; i++)
    {
        append(&vector, i);
    }

    pop(&vector);
    pop(&vector);

    for (int i = 0; i < vector.lenght; i++)
    {
        printf("%d \n", vector.data[i]);
    }
}