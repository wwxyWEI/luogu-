#include<stdio.h>
int main()
{
   char cs1[14];
   int i;
   scanf("%s",cs1);

   int sum = 0,cnt = 1;
   for(i=0;i<12;i++)
   {
    if(cs1[i]>='0'&&cs1[i]<='9')
    {
        sum+=(cs1[i]-'0')*cnt;
        cnt++;
    }
   }
   int check = sum%11;
   char check_ch;
   if(check==10)
   {
    check_ch='X';
   }
   else
   {
    check_ch='0'+check;
   }
   /* printf("debug: check = %d\n", check);
    printf("debug: check_ch = '%c' (ASCII %d)\n", check_ch, check_ch);
    printf("debug: cs1[12] = '%c' (ASCII %d)\n", cs1[12], cs1[12]);
    printf("debug: 比较结果 = %d\n", cs1[12] == check_ch);*/
    printf("%d\n",sum);
   if(cs1[12]==check_ch)
   {printf("Right");}
   else{cs1[12]=check_ch;
    puts(cs1);}
    return 0;
}