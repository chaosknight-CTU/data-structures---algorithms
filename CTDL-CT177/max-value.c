#include <stdio.h>
  
/* khai bao ham */
int max(int num1, int num2);
  
int main () {
 
   /* dinh nghia bien local */
   int a = 100;
   int b = 20;
   int ret;
  
   /* goi mot ham de lay gia tri lon nhat */
   ret = max(a, b);
  
   printf( "Max value is : %d\n", ret );
  
   return 0;
}
  
/* ham tra ve gia tri lon nhat giua hai so */
int max(int num1, int num2) {
 
   /* dinh nghia bien local */
   int result;
  
   if (num1 > num2)
      result = num1;
   else
      result = num2;
  	return result;
  }
