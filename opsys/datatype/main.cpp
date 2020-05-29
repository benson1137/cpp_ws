#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer p, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%.2x ", *(p + i));
    }
    printf("\n");
}

void test()
{
    float a = 1.5;
    float b = 2.5;
    float c = -1.5;
    float d = -2.5;
    int ia = a;
    int ib = b;
    int ic = c;
    int id = d;
    printf("%d\n", ia);
    printf("%d\n", ib);
    printf("%d\n", ic);
    printf("%d\n", id);
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
