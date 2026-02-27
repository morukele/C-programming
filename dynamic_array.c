#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    size_t count;
    size_t capacity;
} Header;

int *arr_init(const size_t init_capacity)
{
    // [header][numbers]
    //          ^
    //          data
    Header *header = malloc(sizeof(int) * init_capacity + sizeof(Header));
    header->count = 0;
    header->capacity = init_capacity;
    return (int *)header + 1;
}

void arr_push(int *arr, const int x)
{
    // cast pointer to the array to pointer to the header
    // this is to allow us to start at the header and fill the info from there
    Header *header = (Header *)arr - 1;
    assert(header->count >= header->capacity);
    arr[header->count++] = x;
}

#define arr_len(arr) ((Header*)(arr) -1)->count

int main()
{
    int *numbers = arr_init(256);
    arr_push(numbers, 69);
    arr_push(numbers, 420);
    arr_push(numbers, 1337);
    arr_push(numbers, 80085);

    for (size_t i = 0; i < arr_len(numbers); ++i )
    {
        printf("%d\n", numbers[i]);
    }

    return 0;
}