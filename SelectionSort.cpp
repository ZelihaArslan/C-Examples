//5 tane öğrencinin No ve Puan bilgilerini klavyeden alır//
//ve bunları puanlarını küçükten büyüğe selection sort kullanarak sıralar//

#include <stdio.h>
#include <stdlib.h>

void sirala(int [5][2]);
int i, j;
int main()
{
   int bilgiler[5][2]={0};
   int i, j;
   printf("5 Adet ogrencinin bilgilerini giriniz.\n");
   for(i=0; i<5; i++)
   {
       for(j=0; j<1; j++)
       {
           printf("%d. Ogrenci\n",i+1);
           printf("No: ");
           scanf("%d", &bilgiler[i][j]);
           printf("Puan: ");
           scanf("%d", &bilgiler[i][j+1]);
        }
        printf("\n");
   }

   sirala(bilgiler);
   printf("\n\nKucukten buyuge siralanmis hali\n\n");
   for(i=0; i<5; i++)
   {
       for(j=0; j<1; j++)
       {
           printf("\n%d. Ogrenci\n",i+1);
           printf("No: ");
           printf("%d", bilgiler[i][j]);
           printf("\n");
           printf("Puan: ");
           printf("%d", bilgiler[i][j+1]);
       }
       printf("\n");
   }
    return 0;
}
void sirala(int bilgiler[5][2])
{
    int gecici[1][2];
    for(i=0; i<5; i++)
    {
       for(j=i; j<5; j++)
       {
           if(bilgiler[i][1] > bilgiler[j][1])
           {
                gecici[0][0] = bilgiler[i][0];    //Dizinin herbir boyutunu teker teker atmamız gerekiyor.//
                gecici[0][1] = bilgiler[i][1];
                bilgiler[i][0] = bilgiler[j][0];
                bilgiler[i][1] = bilgiler[j][1];
                bilgiler[j][0] = gecici[0][0];
                bilgiler[j][1] = gecici[0][1];
           }
       }
    }
}
