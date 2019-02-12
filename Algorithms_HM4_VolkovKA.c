//1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и
//нахождение количество маршрутов.
//Например, карта:
//3 3
//1 1 1
//0 1 0
//0 1 0
//2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.
//3. ***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по
//одному разу. Здесь алгоритм решения такой же как и в задаче о 8 ферзях. Разница только в проверке
//положения коня.

#include <stdio.h>
#include <math.h>

#define N 8
#define M 8
// Доска для ферзей.
// 0 - клетка пустая
// число - номер ферзя
int board [ N ][ M ];

typedef struct
{
  int x;
  int y;
}HourseArray;

HourseArray HA[N*M];

// начало 1 задачи
#define X 5
#define Y 5
int map[N][M];

void read ()
{
  FILE *r;
  r = fopen("C:\\Users\\volkov.GEFEST\\Documents\\HM4\\map.txt", "r");
  for(int i=0; i<X; i++)
    for(int j=0; j<Y; j++  )
      fscanf(r,"%d", &map[i][j]);
//  return *map;
}

void Print2 ( int n , int m , int a [ X ][ Y ])
{
  int i , j;
  for ( i = 0 ; i < n ; i ++)
  {
    for ( j = 0 ; j < m ; j ++)
      printf ( "%4d" , a [ i ][ j ]);
    printf ( "\n" );
  }
}

// конец первой задачи

// начало 3 задачи

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define move_types 8

int possible_moves[move_types][2]  = {
        {-1, -2}, {-2, -1}, {-2,  1}, { 1, -2},
        {-1,  2}, { 2, -1}, { 1,  2}, { 2,  1}
};

int **global;
int size_x, size_y;
int max_moves, back_ret;


/*Функция проверяет может ли быть сделан ход на клетку с координатами x,y*/
int move_possible(int x, int y)
{
        return x >= 0 && y >= 0 && x < size_x && y < size_y && global[x][y] == 0;
}


int find_path(int cur_x, int cur_y, int move_num)
{
        int next_x = 0, next_y = 0;
        global[cur_x][cur_y] = move_num;

        if(move_num > max_moves)
                return 1;

        for(int i = 0; i < move_types; i++)
        {       next_x = cur_x + possible_moves[i][0];
                next_y = cur_y + possible_moves[i][1];
                if(move_possible(next_x, next_y) && find_path(next_x, next_y, move_num + 1))
                return 1;
        }

        global[cur_x][cur_y] = 0;
        back_ret++;
        move_num++;
        return 0;
}

// конец 3 задачи
int main (/* int argc , char * argv []*/)
{
  int A [ X ][ Y ];
  int i , j;
  read();
  for ( j = 0 ; j < Y ; j ++)
    A [ 0 ][ j ] = 1 ; // Первая строка заполнена единицами
  for ( i = 1 ; i < X ; i ++)
  {
    A [ i ][ 0 ] = 1;
    for ( j = 1 ; j < Y ; j ++)
      if(map[i][j]==1)
        A [ i ][ j ] = A [ i ][ j - 1 ] + A [ i - 1 ][ j ];
      else
        A [ i ][ j ]=0;
  }
  Print2 ( X , Y , A );
//завершение первой задачи



  int nrows,ncols,sy,sx,**desc = NULL;
  time_t start,end;
  //вводим данные
  printf("\nInput dimentions (from 2 to 8):");
  printf("\non \"X\"\t");
  scanf("%d",&size_x);
  printf("\non \"Y\"\t");
  scanf("%d",&size_y);

  if(size_x>8||size_x<2||size_y>8||size_y<2)
  {
      printf("\nIncorect size");
      system("pause");return;
    }
  //проверяем размерность
  printf("\nInput start coordinates:");
  printf("\non \"X\"\t");
  scanf("%d",&sx);
  printf("\non \"Y\"\t");
  scanf("%d",&sy);
  //проверяем координаты


  start=time(NULL);//стартуем
  //инициализируем увзвтель и выделяем память
  desc = (int **)malloc(sizeof(int) * size_x);
  for(i = 0; i < size_x; ++i)
          desc[i] = (int *)malloc(sizeof(int) * size_y);

  //инициализируем другие переменные
  back_ret = 0;
  global = desc;
  max_moves = size_x * size_y - 1;

  //зануляем массив
  for(int i = 0; i < size_x; ++i) {
          for(int j = 0; j < size_y; ++j)
                  global[i][j] = 0;
  }

  //поиск решения
  if(find_path(sx, sy, 1))
  {
    printf("\n___________________________________________");
    printf("\n\t***solution***");
    printf("\n___________________________________________\n");
    for(int i = 0; i < size_x; ++i)
    {
      for(int j = 0; j < size_y; ++j)
        printf("%d ",global[i][j]);
      printf("\n");
      }
    printf("\n___________________________________________");
  }
  else
    printf("\nno solution");


  //освобождаем память
  for(i = 0; i < size_x; ++i)
          free(desc[i]);
  free(desc);
  end=time(NULL);//время конца цикла

  //время поиска решения
  printf("\nsolution time %f sec.", difftime(end, start));
  printf("\n___________________________________________");
  system("pause");

  return 0;
}
