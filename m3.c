#include <stdio.h>
#include <ctype.h>

int main()
{
    int n;
    scanf("%d", &n);
    
     getchar();// after scanf statement tp remove the extra space and read the next line we use getchar

    char s[n]; 

    for(int i = 0; i < n; i++)
    {
     scanf("%c", &s[i]); 
      s[i]=toupper(s[i]);
    }
    
    int c=0;
    for(int i=0;i<n;i++)
    {
        c++;
        s[i]=s[i]-c;
    }
    for(int i=0;i<n;i++)
    {
        
        printf("%c", s[i]);
    }
}