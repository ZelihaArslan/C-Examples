#include <stdio.h>

int main ()
{
    int i = 0, kelime = 0;
    char cumle[200];
    printf("Bir cumle giriniz.\n");
    gets(cumle);

    for( i = 0; cumle[i]!='\0' ; i++)
    {

        if (cumle[i] == ' ' && cumle[i+1] != ' ') /*Boşlukları kontrol ettik. Boşlukların bir fazlası kelime sayısını verir.
                                                    Ayrıca birden fazla boşluk konulma ihtimalini de göz önünde bulundurduk.*/
            kelime++;
    }

    printf("Girilen Kelime Sayisi: %d", (kelime+1));

    return 0;
}
