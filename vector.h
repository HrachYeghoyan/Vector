#include <stdlib.h>
#include <stddef.h>

typedef struct 
{
    size_t size;
    size_t capacity;
    int* ptr;
    
}vector;

void ctor(vector* this)
{
    this->size=0;
    this->capacity=10;
    this->ptr=(int*)malloc(this->capacity * sizeof(int));
    if(!(this->ptr))
    {
        perror("Malloc xndir");
        exit(1);
    }
}

void dtor(vector* this)
{
    this ->size=0;
    this ->capacity=0;
    free(this->ptr);
    this-> ptr=NULL;
}

void push_back(vector* this, int val)
{
    if(this->size==this->capacity)
    {
        this->capacity++;
        this->ptr=(int*)realloc(this->ptr,this->capacity *sizeof(int));
        if(!(this->ptr))
        {
            perror("Malloc xndir");
            exit(1);
        }
    }
    this->ptr[this->size++] = val;
}

void pop_back(vector* this)
{
    if(!(this->size))
    {
        perror("Segmentetion foult");
        return;
    }
    this->size--;

}

void clear(vector* this)
{
    this->size=0;
}

size_t size(vector* this)
{
    return this->size;
}

size_t capacity(vector* this)
{
    return this->capacity;
}

void insert(vector* this, size_t index, int val)
{
    if(this->size==this->capacity)
    {
        this->capacity++;;
    
        this->ptr=(int*)realloc(this->ptr, this->capacity *sizeof(int));
         if(!(this->ptr))
         {
             perror("Malloc xndir");
              exit(1);
         }
    }
    this->size++;
    for(int i=this->size;i>index;i-- )
    {
        this->ptr[i]= this->ptr[i-1];
    }
    this->ptr[index]=val;
}

void erase(vector* this, size_t index)
{
    if(index> this->size)
    {
        printf("chka tvyal indexn");
        return;
    }
    for(int i = index; i<this->size-1; ++i)
    {
        this->ptr[i]=this->ptr[i+1];
    }
    this->size--;

}

void insert_range(vector* this, size_t start, size_t end, int val)
{
    size_t tmp =( end - start) +1;
    this -> size +=tmp;
    if(this->size>this->capacity)
    {
        this ->capacity *= 2;
        this->ptr=(int*)realloc(this->ptr, this->capacity * sizeof(int));
    }
    if(!(this->ptr))
    {
        perror("Malloc xndir");
        exit(1);
    }
    for(int i = start; i<this-> size;++i)
    {
        this->ptr[i+tmp]=this->ptr[i];
        this->ptr[i]=val;
    }
}

void print(vector* this)
{
    for(int i =0; i<this ->size; ++i)
    {
        printf("%d", this -> ptr[i]);
    }
    putchar(10);
}






