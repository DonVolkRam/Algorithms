//1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя
//рекурсию.
//2. Реализовать функцию возведения числа a в степень b:
//a. Без рекурсии.
//b. Рекурсивно.
//c. *Рекурсивно, используя свойство чётности степени.
//3. **Исполнитель «Калькулятор» преобразует целое число, записанное на экране. У
//исполнителя две команды, каждой присвоен номер:
//1. Прибавь 1.
//2. Умножь на 2.
//Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза. Сколько
//существует программ, которые число 3 преобразуют в число 20:
//а. С использованием массива.
//b. *С использованием рекурсии.

//автор Волков Кирилл Александрович
#include <stdio.h>
#include <math.h>

//функция перевода числа из 10ой системы счисления в 2ую
int get2from10(int num)
{
  if(num>0)
    return num%2+10*get2from10(num/2);
}

//функция возведения в степень с иcпользование цикла
int powerA(int source, int grade)
{
  int result=source;
  for (grade; grade>1; grade--)
    result*=source;
  return result;
}

//функция возведения в степень с импользование рекурсии
int powerB(int source, int grade)
{
  int result=source;
  grade--;
  if(grade>0)
    return result*=powerB(source, grade);
}

//функция возведения в степень с импользование цикла
int powerC(int source, int grade)
{
  int result=source;
  grade--;
  if(grade%2==0)
    return result=powerC(source, grade)<<1;
  else
    return result*=powerB(source, grade);
}

//функция пожсчета программ, которые преобразуют num1 в num2 если есть 2 кнопки +1 и *2
// используя массив
int countCalcNumA(int num1, int num2)
{
int a[num2+1];
 for(int i=0; i<num2+1; i++)
 {
    if(i<=num1)
       a[i]=1;
    else if(i<num1*2)
      a[i]=2;
    else
      {
        if(i%2==0)
          a[i]=a[i/2]+a[i-1];
        else
          a[i]=a[i-1];
      }
 }
return a[num2];
}

//функция пожсчета программ, которые преобразуют num1 в num2 если есть 2 кнопки +1 и *2
// используя рекурсию
int countCalcNumB(int num1, int num2)
{
if(num2==num1)
  return 1;
if(num2-num1<num1)
  return 2;
if (num2%2==0)
  return countCalcNumB( num1, num2/2) + countCalcNumB(num1, num2-1); //если была нажата *2
else
  return countCalcNumB(num1, num2-1); // если была нажата +1
}

//функция очистки экрана
void clrscr()
{
    system("@cls||clear");
}

int main(/*int argc, char *argv[]*/)
{
  int a, b;
  int input=1, choise=0;

      printf("Hello World!\n");
      printf("Chose the task\n"
             "1) Get binary number from decimal \n"
             "2) Get Number in power of (A)(without recursion)\n"
             "3) Get Number in power of (B)(with recursion)\n"
             "4) Get Number in power of (C)(with binary recursion)\n"
             "5) Get Number of program from 3 to 20 (array)\n"
             "6) Get Number of program from 3 to 20 (recursion)\n"
             "7) Exit\n");

      scanf("%d", &choise);
      clrscr();
  switch (choise) {

    case 1:
      printf("Input number: ");
      scanf("%d", &a);
      printf("a(10) = %d\n",a);

      printf("a(2)= %d\n",get2from10(a));
      break;

    case 2:;
      printf("Input number and grade: ");
      scanf("%d %d", &a, &b);
      printf("a = %d\npower(%d,%d) = %d\n",a,a,b, powerA(a,b) );
      break;

    case 3:
      printf("Input number and grade: ");
      scanf("%d %d", &a, &b);
      printf("a = %d\npower(%d,%d) = %d\n",a,a,b, powerB(a,b) );
      break;

    case 4:
      printf("Input number and grade: ");
      scanf("%d %d", &a, &b);
      printf("a = %d\npower(%d,%d) = %d\n",a,a,b, powerC(a,b) );
      break;

    case 5:
      printf("Input start number and end: ");
      scanf("%d %d", &a, &b);
      printf("start = %d\nend = %d\ncount = %d",a,b, countCalcNumA(a,b) );
      break;

    case 6:
      printf("Input start number and end: ");
      scanf("%d %d", &a, &b);
      printf("start = %d\nend = %d\ncount = %d",a,b, countCalcNumB(a,b) );
      break;

    default:
      input=0;
      break;
    }
  return 0;
}
