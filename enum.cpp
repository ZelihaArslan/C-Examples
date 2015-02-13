# enum: Değişkenin alabileceği değerlerin belli(sabit) olduğu
durumlarda programı daha okunabilir hale getirmek için kullanılır.
#include <stdio.h>
#include <stdlib.h>

int tek (int);

int main()
{
  enum boolean
  {
      false = 0,
      true = 1
  };

  enum boolean sonuc;
  int x;

  printf("Bir sayi giriniz\n");
  scanf("%d", &x);

  sonuc = tek(x);

  if(sonuc == true)

        printf("\nGirilen sayi tektir.");

    else

        printf("\nGirilen sayi cifttir");
        
    return 0;
}
int tek (int n)
{
    return ( n % 2);
}
