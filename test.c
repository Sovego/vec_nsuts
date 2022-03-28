//
// Created by egors on 3/27/2022.
//
#include <stdio.h>
#include "sample.h"
#include <assert.h>
#define TYPE double
#define NAME vector
#include "array_def.h"
#define TYPE int
#define NAME indices
#include "array_def.h"


int main()
{
    vector val;
    vector_init(&val);
    vector_push(&val,1);
    vector_push(&val,1);
    vector_push(&val,1);
    vector_push(&val,1);
    vector_push(&val,1);
    vector_push(&val,1);
    double arr[4]={3,5,6,7};
    vector_insert(&val,val.n,arr,4);
    for(int i=0;i<val.n;i++)
    {
        printf("%lf\n",val.arr[i]);
    }
    printf("\n");
    vector_erase(&val,0,4);
    for(int i=0;i<val.n;i++)
    {
        printf("%lf\n",val.arr[i]);
    }
    vector_push(&val,1);
    vector_push(&val,1);
    vector_push(&val,1);
    vector_push(&val,1);
    printf("\n");
    for(int i=0;i<val.n;i++)
    {
        printf("%lf\n",val.arr[i]);
    }
    vector_destroy(&val);
    vector_destroy(&val);
    vector_destroy(&val);
    vector_destroy(&val);
    vector_destroy(&val);
    vector_push(&val,1);
    vector_push(&val,1);
    vector_push(&val,1);
    vector_push(&val,1);
    printf("\n");
    for(int i=0;i<val.n;i++)
    {
        printf("%lf\n",val.arr[i]);
    }
    vector_destroy(&val);
    vector_insert(&val,val.n,arr,4);
    printf("\n");
    for(int i=0;i<val.n;i++)
    {
        printf("%lf\n",val.arr[i]);
    }
    vector_insert(&val,0,arr,4);
    printf("\n");
    for(int i=0;i<val.n;i++)
    {
        printf("%lf\n",val.arr[i]);
    }
    vector_resize(&val,3,1);
    printf("\n");
    for(int i=0;i<val.n;i++)
    {
        printf("%lf\n",val.arr[i]);
    }
    vector_resize(&val,0,1);
    printf("\n");
    for(int i=0;i<val.n;i++)
    {
        printf("%lf\n",val.arr[i]);
    }
    vector_destroy(&val);
    vector_resize(&val,10,1);
    printf("\n");
    for(int i=0;i<val.n;i++)
    {
        printf("%lf\n",val.arr[i]);
    }
    vector_erase(&val,0,10);
    for(int i=0;i<val.n;i++)
    {
        printf("%lf\n",val.arr[i]);
    }
    vector_resize(&val,10,2);
    printf("\n");
    for(int i=0;i<val.n;i++)
    {
        printf("%lf\n",val.arr[i]);
    }
    vector_erase(&val,0,9);
    printf("\n");
    for(int i=0;i<val.n;i++)
    {
        printf("%lf\n",val.arr[i]);
    }
}
