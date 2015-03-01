#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cumle[100];
    int harfSay[100]={0};
    int i,k,m,s=0,a=0;

    printf("Bir cumle giriniz\n"),
    gets(cumle);
    while(cumle[s] != '\0')
    {
        s++;
        a++;
    }

    for(i=0; i < s; i++)
    {
       if(harfSay[i] == 0)
       {
            for(k = i+1; k < s; k++)
            {
                if(cumle[k] != ' ' && cumle[i] == cumle[k])
                {
                    harfSay[i]++;
                    harfSay[k]++;
                }
            }
            if(cumle[i] != ' ')
                printf("%c harfinden %d tane var\n", cumle[i], harfSay[i]+1);
       }
    }

    return 0;
}

