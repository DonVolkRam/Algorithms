//3. �������� ��������� ������ ���������� ���� ������������� ����������:
//*��� ������������� ������� ����������.
//13. * �������� �������, ������������ ��������� ����� �� 1 �� 100.
//14. *����������� �����. ����������� ����� ���������� �����������,
//���� ��� ����� ��������� ������ ������ ��������. ��������, 252 = 625
//�������� ���������, ������� ������ ����������� ����� N � �������
//�� ����� ��� ����������� �����, �� ������������� N.

//����� ������ ������ �������������
#include <stdio.h>
#include <math.h>
#include <time.h>

float a = 1.5;
float b = 1.2;

//������� ������������ ��������� ��������
int my_rand ( int min , int max)
{
  time_t timer;
  a = a + 1.1;
  b = b + 0.05;
  timer = time(NULL);
  int x = abs(a * timer + b) % (max-min+1);
  return x;
}

//������� ������ ���������� ����� �����������
void change(int *a, int *b)
{
  *a=*a-*b;
  *b=*a+*b;
  *a=*b-*a;
}

//������� ������ ����������� ����� �� ����������� Num
void automorph(int Num)
{
  for (long long i=0; i<Num; i++)
  {
    int rank=1; //���������� ���������� �������� = 1
    int temp=i;
    for(;;)
    {
      if((temp/=10)>0)
        rank++; //���������� ������� ��������� � �����
      else
        break;
      }
    if ((i*i-i)%labs(pow(10,rank))==0) // ���� �� �������� ����� ������� ��� ����� � �� ����� ���� ����� ���� �� ����� ��������
      printf("%lli -> %lli\n", i, i*i);
  }
}

//������� ������� ������
void clrscr()
{
    system("@cls||clear");
}

int main(/*int argc, char *argv[]*/)
{
  int a=11, b=3;
  int input=1, choise=0;

      printf("Hello World!\n");
      printf("Chose the task\n"
             "1) Change two numbers\n"
             "2) Get random number (without using function rand())\n"
             "3) Automorphing numbers\n"
             "4) Exit\n");

      scanf("%d", &choise);
      clrscr();
  switch (choise) {

    case 1:
      printf("Input 2 numbers: ");
      scanf("%d %d", &a, &b);
      printf("a = %d\tb = %d\n",a,b);
      change(&a,&b);
      printf("a = %d\tb = %d\n",a,b);
      break;

    case 2:;
      for(;;)
      {
          printf("Generate between 1 and 100");
          printf ( "%d\n" , my_rand( 1 , 100) );
          printf("Generate again? 11-exit");
          scanf("%d", &input);
          if(input==11)
            break;
      }
      break;

    case 3:
      printf("Input number and I show you all automorph number before input number");
      scanf("%d", &input);
      automorph(input);
      break;
    default:
      input=0;
      break;
    }
  return 0;
}


