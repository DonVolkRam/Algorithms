#include <stdio.h>

int hash(char *a)
{
  int i=0;
  int summ=0;
  while(a[i])
     {
       printf("\n%c\t->\t%d",a[i], (unsigned int)a[i]);
       summ+=(unsigned int)a[i];
       i++;
     }
  return summ;
}

int main(/*int argc, char *argv[]*/)
{
  unsigned char a[32];
  printf("Hello World!\n");
  gets(a);
  printf("\n summ = %x", hash(a));
  return 0;
}


