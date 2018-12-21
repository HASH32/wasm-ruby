#include <stdio.h> 
/* function to show bytes in memory, from location start to start+n*/
void show_mem_rep(char *start, int n)
{
    int i;
    for (i = 0; i < n; i++)
         printf(" %.2x", start[i]);
    printf("\n");
}


int main()  
{ 
   unsigned int i = 1; 
   char *c = (char*)&i; 
   if (*c)     
       printf("Little endian"); 
   else
       printf("Big endian"); 
   getchar(); 

   int y = 0x01234567;
   show_mem_rep((char *)&y, sizeof(y));
   getchar();
   return 0; 
} 

