#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int idx = 0;
char palavra[200];

int pilha = 0;

void e0();
void e1();
void e2();
void e3();
void e4();
int isNumber(char);

void rejeita();
void aceita();

int main(){
  gets(palavra);
  e0();
}


int isNumber(char c){
  return ( (int)c >= 48 && (int)c <= 57 );
}


void e0(){
  if( isNumber(palavra[idx]) ){
      idx++;
      e1();
  }
  else if(palavra[idx] == '('){
      idx++;
      e2();
  }
  else{
      rejeita();
  }
}


void e1(){
    if(palavra[idx] == '+' || palavra[idx] == '-' || palavra[idx] == '*' || palavra[idx] == '/'){
        idx++;
        e0();
    }
    else if(palavra[idx] == '\0'){
        e4();
    }else{
        e3();
    }
}

void e2(){
    pilha ++;
    e0();
}

void e3(){

    if(palavra[idx] == ')' && pilha >0){
      pilha--;
    }else{
      rejeita();
    }
  idx++;
  e1();
}


void e4(){
  if(pilha == 0){
      aceita();
  }else{
      rejeita();
  }
}

void rejeita(){
    printf("\n Rejeita\n");
    system("pause");
    exit (0);
}
void aceita(){
    printf("\n Aceita\n");
    system("pause");
    exit (0);
}
