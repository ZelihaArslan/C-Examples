/*1 ile 1000 arasındaki asal sayılar*/

#include <stdio.h>
#include <stdlib.h>
int main()
{

    int sayi = 1, i = 1 , toplam = 0, k = 0;
    
    for(sayi = 2; sayi < 1000; sayi++)
    {
        toplam =0;/*Burada toplamı sıfırladık çünkü farklı bir sayıya geçtik. */
        for(i = 1; i <= sayi; i++)
        {
            if(sayi % i == 0)/* sayi değişkeni i değişkenine tam bölünüyorsa toplam değişkenini arttırdık.*/
                toplam++;
        }

        if(toplam == 2)/*Eğer toplam değişkeni 2 ise o asal sayıdır.
                        Burada şunu yaptık sayıyı önce aldık ve i 
                        değerini sürekli arttırdık i tam 
                        bölündüğünde toplam değişkenini arttırdık.
                        Sayımız 2 kez sıfıra tam bölünüyorsa o asal sayıdır dedik. */
        {
            k++;  /*k değişkenini kaç asal sayı var onu bulmak için kullandık.*/
            printf("%3d. Asal sayi %d\n",k,  sayi);
        }
   }
    return 0;
}
