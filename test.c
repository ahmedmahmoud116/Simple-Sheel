#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int main()
{
 fork();
 printf("hello world!\n");
    return 0;
}*/

#include <stdio.h>
#include <string.h>

/*int main()
{
    char *string,*found;
    char *str1[100];
    string = strdup("ls -m");
    printf("Original string: '%s'\n",string);
    int i=0;
    while( (found = strsep(&string," ")) != NULL ){
        printf("%s\n",found);
        str1[i] = found;
        i++;
        }
        for(int x = 0;x<sizeof(str1);x++){
            if(str1[x] == NULL)
            break;
            printf("%s \n",str1[x]);
        }

    return(0);
}*/
