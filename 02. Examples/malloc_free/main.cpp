// malloc calloc resize free
// malloc - stands for memory allocation
// calloc - stands for cleared memory allocation

// malloc:--> pointer_name = (cast-type*) malloc(size);
// malloc is used to dynamically allocate a single large block of memory with the specified size. It returns a pointer of type void which can be cast into a pointer of any form.

// calloc:--> pointer_name = (cast-type*) calloc(num_elems, size_elems);
// calloc is used to dynamically allocate the specified number of blocks of memory of the specified type. It initializes each block with a default value '0'.

//Both functions return a pointer of type void which can be cast into a pointer of any form. If the space for the allocation is insufficient, a NULL pointer is returned.

#include <stdio.h>
#include <stdlib.h>


int main()
{
    printf("\nmalloc\n");
    int *p = (int*)malloc(sizeof(int));
    printf("address = %p, value = %d\n", p, *p);

    int *p1 = (int*)malloc(3*sizeof(int)); // Memory for 3 integers
    printf("address = %p, value = %d\n", p1, *p1);

    //Memory allocation for primitive data type - int array
    int *p2 = (int*)malloc(3*sizeof(int));
    p2[0] = 1;
    p2[1] = 2;
    p2[2] = 3;
    printf("address of value= %p, value = %d\n", p2, p2[1]);

    printf("\ncalloc\n");
    struct myStruct
    {
        int i;
        double d;
        char a[5];
    };

    myStruct *p3 = (myStruct*)calloc(4, sizeof(myStruct));
    p3[0].i = 1;
    p3[0].d = 1.3145;
    p3[0].a[0] = 'a';
    printf("address = %p, value = %d\n", p3[0], p3[0].i);

    //realloc - The size of the memory area reserved with malloc or calloc can be increased or decreased with the realloc function.

    printf("\nrealloc\n");
    p = (int*)realloc(p, 2*sizeof(int));
    p[1] = 3;
    printf("address = %p, value = %d\n", p+0, *(p+0));
    printf("address = %p, value = %d\n", p+1, *(p+1));
    printf("address = %p, value = %d\n", p+2, *(p+2)); //still can access eventhough we defined only 2 blocks of int. DONT USE LIKE THIS --> Undefined behaviour

    //free allocated memory
    free(p);
    free(p1);
    free(p2);
    free(p3);

}

// At compile time, only the space for the pointer is reserved (on the stack). When the pointer is initialized, a block of memory of sizeof(int) bytes is allocated (on the heap) at program runtime. 
// The pointer on the stack then points to this memory location on the heap.

// Dangling Pointer: Memory allocated with malloc or calloc is not subject to the familiar rules of variables in their respective scopes. 
// This means that they exist independently of block limits until they are released again or the program is terminated. 
// However, the pointers which refer to such heap-allocated memory are created on the stack and thus only exist within a limited scope. 
// As soon as the scope is left, the pointer variable will be lost - but not the heap memory it refers to.