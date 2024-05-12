#include<stdio.h>
int p[3];
int w[3];
float pw[3];
float m;
float np=0.0;
void sort()
{
int i, j, temp;
for(i=0;i<3;i++){
for(j=i+1;j<3;j++){
if(pw[i]< pw[j]){
temp=pw[i];
pw[i]=pw[j];
pw[j]=temp;
temp=p[i];
p[i]=p[j];
p[j]=temp;
temp=w[i];
w[i]=w[j];
w[j]=temp;
}
}
}
}
float knap()
{
 int i;
 float frac;
 for(i=0;i<3;i++)
 {
 pw[i]=(float)p[i]/w[i];
 }
 sort();
 for(i=0;i<3&&m!=0;i++)
 {
 if(w[i]<=m)
 {
 np+=(float)p[i];
 m-=w[i];
 }
 else
 {
 frac=m/w[i];
 m=0;
 np=np+(frac*(float)p[i]);
 }
 }
 return np;
}
void main()
{
 printf("Unnati Hassanandani 60004220134 C167\n");
 printf("Enter profit of items:");
 scanf("%d %d %d",&p[0],&p[1],&p[2]);
 printf("Enter weight of items:");
 scanf("%d %d %d",&w[0],&w[1],&w[2]);
 printf("Enter knapsack capacity:");
 scanf("%f",&m);
 float f=knap();
 printf("net profit=%f",f);
}
