#include <stdio.h>
#include <stdlib.h>

unsigned short int swap(unsigned short int a);//Gönderilen tamsayının düşük ile yüksek sekizlisinin yerini değiştirilmişini verirr
unsigned short int max(unsigned short int a);//Gönderilen tamsayının düşük sekizlisi ile yüksek sekizlisinden büyüğünü verir.
int main()
{
    unsigned short int i, j;
    i = 0xAA11;
    printf("%x %x %x",i ,swap(i), max(i));


    return 0;
}
unsigned short int swap(unsigned short int a)
{
    return (a>>8) | (a<<8);

}
unsigned short int max(unsigned short int a)
{
    unsigned short int lo,hi,m;
    lo = a & 0x00FF;
    hi=a>>8;

    m=(lo>hi) ? lo:hi;//Karşılaştırma işlemi doğruysa lo yanlışsa hi döner.
    return m;

}
