#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[20];
    int alphabet[26]={0,};
    printf("Enter string :");
    scanf("%s",word);
    for(int i=0;i<strlen(word);i++)
    {
        if('a'<=word[i] && word[i]<='z')
        {
            alphabet[(int)word[i]-97]++;
        }
        else if('A'<=word[i] && word[i]<='Z')
        {
            alphabet[(int)word[i]-65]++;
        }
    }
    printf("run length :");
    for(int i=0;i<26;i++)
    {
        if(alphabet[i]!=0)
        {
            printf("%d",alphabet[i]);
            printf("%c",i+97);
        }
    }
    return 0;
}
