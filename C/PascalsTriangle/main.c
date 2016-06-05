/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on January 26, 2015, 9:24 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/*
 * 
 */
unsigned int fact(int z) /*factorial function*/
{
    return (z == 1 || z == 0) ? 1 : fact(z-1)*z;
}

unsigned int comb(int x,int y)/*combination function*/
{
    return fact(x)/(fact(x-y)*fact(y));
}

int main()/*beginning of program*/
{
int n,t,y;
char input[50];
const char s[2]=" ";
int ans[100] = {-1};
int i,rownum,iRowNum;
char *token;
int itoken;
unsigned int sum=0;

scanf("%d",&n);  /*reading values*/
scanf("%d",&t);
/* answer array declaration*/

for(i=0;i<t;i++)/* for loop start*/
{
    fflush(stdin);
    gets(input);/*string input*/
    scanf(" %[^\n]s",input);
    token = strtok(input,s);/* process to make substring*/
    rownum = token;
    iRowNum = atoi(rownum);
    if(iRowNum <= n){
    token = strtok(NULL, " ");
    sum = 0;
    while(token != NULL)/*loop for finding whole values*/
    {
       itoken = atoi(token);   
     
        if(itoken <= iRowNum)
        {
        sum+=comb(iRowNum,itoken);
        }
        else
        {
        sum = -1;
        break;
        }
       token = strtok(NULL, " "); 
    }
    ans[i]= sum;
}
}
/* printing output*/
    for(y=0;y<t;y++)
    {
    printf("%d ",ans[y]);
    }

return 0;
}

