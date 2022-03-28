#include <assert.h>
#include <stdlib.h>
#include <string.h>
//initializes members of [vec] structure for empty array
void CAT(NAME, init)(NAME* vec)
{
	vec->n = 0;
	vec->cap = 2;
	vec->arr = calloc(vec->cap,sizeof(TYPE));
}
//makes array [vec] empty and frees its array buffer [vec->arr]
//note: this function can be called many times
void CAT(NAME, destroy)(NAME* vec)
{
	vec->n = 0;
	vec->cap = 0;
	if (vec->arr)
	{
		free(vec->arr);
		vec->arr = NULL;
	}
}
//adds element [value] to the end of array [vec]
//returns index of the added element
int CAT(NAME, push)(NAME* vec, TYPE value)
{
    if (vec->cap==0)
    {
        CAT(NAME, init)(vec);
    }
	if (vec->n + 1 > vec->cap)
	{
		CAT(NAME, reserve)(vec, vec->cap *2);
	}
	vec->arr[vec->n] = value;
    int tmp = vec->n;
	vec->n += 1;
    return tmp;
}
//removes the last element from array [vec]
//returns removed element
TYPE CAT(NAME, pop)(NAME* vec)
{
    TYPE tmp = vec->arr[vec->n];
	vec->n -= 1;
	return tmp;
}
//ensures that array [vec] has enough storage for [capacity] elements
//note: address of elements surely won�t change before [vec->n] exceeds capacity
void CAT(NAME, reserve)(NAME* vec, int capacity)
{
	if (capacity == 0)
	{
		capacity = 1;
	}
    if(vec->cap==0)
    {
        vec->arr=calloc(capacity, sizeof(TYPE));
        vec->cap = capacity;
        return;
    }
    if(capacity==vec->cap)
    {
        return;
    } else{
	vec->arr = realloc(vec->arr, capacity * sizeof(TYPE)+1);
	vec->cap = capacity;
}
}
//changes number of elements in array [vec] to [newCnt]
//if the number increases, new elements get value [fill]
//if the number decreases, some elements at the end are removed
void CAT(NAME, resize)(NAME* vec, int newCnt, TYPE fill)
{
	CAT(NAME, reserve)(vec, newCnt);
	for (int i  = vec->n; i < newCnt; i++)
	{
		vec->arr[i] = fill;
	}
	vec->n = newCnt;
}
//inserts elements [arr[0]], [arr[1]], [arr[2]], ..., [arr[num-1]]
//in-between elements [vec->arr[where-1]] and [vec->arr[where]]
//note: the whole array [arr] cannot be part of array [vec] // PSHLNH
//[where] may vary from 0 to [vec->n], [num] can also be zero
void CAT(NAME, insert)(NAME* vec, int where, TYPE* arr, int num) {
    if(num==0)
    {
        return;
    }
    if (vec->cap <= vec->n+num) {
        CAT(NAME, reserve)(vec, (vec->cap + vec->n+num)*2);
    }
    if(vec->n==0)
    {
        memmove(vec->arr+where,arr,sizeof(TYPE)*num);
    } else {
        memmove(vec->arr + where + num, vec->arr + where, sizeof(TYPE) * (num + vec->n));
        memmove(vec->arr + where, arr, sizeof(TYPE) * num);
    }
    vec->n += num;
}
//removes elements [vec->arr[k]] for k = [where], [where+1], ..., [where+num-1]
//all the elements starting from [where+num]-th are shifted left by [num] positions
void CAT(NAME, erase)(NAME* vec, int where, int num)
{

	if (num <= 0)
	{
		return;
	}
	if (where < 0)
	{
		return;
	}
    memmove(vec->arr+where,vec->arr+where+num,sizeof(TYPE)*vec->n-num);
	vec->n -= num;
}
#undef TYPE
#undef NAME
#undef NAME
