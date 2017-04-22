#include <stdio.h>
#include <assert.h>
#include <stddef.h>

struct Node
{
  struct Node * L;
  struct Node * R;
};

struct Vector
{
  float X;
  float Y;
};

struct Counter
{
  int N;
};


#define Include_Composite(Name) Name Composite_Part_ ## Name


struct Composite
{
  struct Node Part_Node [1];
  //struct Counter Composite_Part_Counter [1];
  struct Include_Composite (Counter) [1];
  struct Vector Part_Vector [1];
};


void Increament_Counter (struct Counter * Item)
{
  Item->N = Item->N + 1;
}

float Vector_Length2 (struct Vector * Item)
{
  return Item->X * Item->X + Item->Y * Item->Y;
}


struct Composite C [1];


#define Composite_Part_Address();

int main (void)
{

  C->Composite_Part_Counter->N = 2;
  C->Part_Vector->X = 2;
  C->Part_Vector->Y = 2;

  //printf ("%p\n", C);
  //printf ("%p\n", C->Part_Counter);
  //printf ("%i\n", offsetof (struct Composite, Part_Counter));
  //printf ("%p\n", (struct Counter *)((void *)C + offsetof (struct Composite, Part_Counter)));

  Increament_Counter ((struct Counter *)((void *)C + offsetof (struct Composite, Composite_Part_Counter)));
  float L = Vector_Length2 ((struct Vector *)((void *)C + offsetof (struct Composite, Part_Vector)));

  printf ("%i, %f", C->Composite_Part_Counter->N, L);
  printf ("\n");
  return 0;
}
