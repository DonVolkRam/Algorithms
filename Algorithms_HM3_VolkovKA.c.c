#include <stdio.h>
// Определяем максимальный размер массива
#define MaxN 100

int count_equal=0;
int count_compare=0;

void swap ( int * a , int * b )
{
  int t = * a;
  * a = * b;
  * b = t;
  count_equal+=3;
}

// Распечатываем массив
void print ( int N , int * a)
{
  int i;
  for ( i = 0 ; i < N ; i ++)
    printf ( "%6i" ,  i );
    printf ( "\n" );
  for ( i = 0 ; i < N ; i ++)
    printf ( "%6i" , a [ i ]);
  printf ( "\n" );
}

int find ( int N , int * a, int value)
{
  int i, m, L, R;
  L=0;
  R=N-1;
  m=L+(R-L)/2;
  for ( i = 0  ; i < N ; i++)
  {
    if(L<=R && a[m]!=value)
    {
      if(a[m]<value)
        L=m+1;
      else
        R=m-1;
      m=L+(R-L)/2;
    }
    else
    {
      if(a[m]==value)
        return m;
      else
        return -1;
    }
  }
  return -1;
}

int main (/* int argc , char * argv []*/)
{
  int a [ MaxN ]; // создаём массив максимального размера
  int N;
  FILE * in;
  in = fopen ( "d:\\data.txt" , "r" );
  fscanf ( in , "%i" , & N );
  int i;
  for ( i = 0 ; i < N ; i ++)
    {
      fscanf ( in , "%i" , & a [ i ]);
    }
  fclose ( in );
  puts ( "Array before sort" );
  print ( N , a );
  int j = 0;
  for ( i = 0 ; i < N ; i ++)
  {
      count_compare++;
    for ( j = 0 ; j < N - 1 ; j ++)
    {
      count_compare++;
      if ( a [ j ] > a [ j + 1 ])
      {
        count_compare++;
          swap (& a [ j ], & a [ j + 1 ]);
      }
    }
  }

  puts ( "Array after sort" );
  print ( N , a );
  printf("Quantity = %d\ncompare = %d\nequal = %d\n", N, count_compare, count_equal);
  puts ( "Find number" );
  int choise;
  scanf("%d",&choise);

  printf("Your number is %d" , find(N, a, choise));
  return 0;
}
