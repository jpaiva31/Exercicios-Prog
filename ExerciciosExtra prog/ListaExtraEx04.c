/*Fa�a um programa que leia dois valores inteiros nas vari�veis x e y e troque o conte�do
das vari�veis. Refa�a este problema sem o uso de outras vari�veis que n�o x e y.*/

#include <stdio.h>

int main(){
int x,y;

scanf("%d %d", &x,&y);

x= x + y;
y= x - y;
x= x - y;

printf("%d %d", x,y);
return 0;
}
