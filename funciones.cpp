#include<iostream>
#include<stdlib.h>
#include<NTL,ZZ.h>
#include"funciones.h"
using namespace std;

long a,b,d,x,y;

int euclides(int a,int b)
{
  if(b==0)
    return a;
  return euclides(b,modulo(a,b));
}
int modulo(int value,int modulo)
{
	int cociente=value/modulo;

	if(value>=0)
		return value-cociente*modulo;
	return modulo-(value*-1+cociente*modulo);
}

void euclides_extendido(long a,long b,long &d,long &x,long &y)
{
  long x1,y1;

  if(b==0){
    d=a;
    x=1;
    y=0;
  }
  else{
    euclides_extendido(b,modulo(a,b),d,x,y);
    x1= x;
    y1=y;
    x=y1;
    y=x1-(a/b)*y1;
  }
}

string ballas_encriptar(string mensaje,int key)
{
  int n=2*(key-2)+1+1;   ///////
  string palabraNueva="";
  int posicion;
  int puntoTrivial=n;

  for(int i=0;i<key;i++){
    posicion=i;
    while(posicion<mensaje.length()){
      palabraNueva+=mensaje[posicion];
      if(puntoTrivial!=0 && n!=puntoTrivial && posicion+puntoTrivial<mensaje.length())
        palabraNueva+=mensaje[posicion+puntoTrivial];
      posicion+=n;
    }
    puntoTrivial-=2;
  }
  return palabraNueva;
}

string ballas_desencriptar(string mensaje,int key)
{
  int posicion=0;
  int valor =2*(key-2)+2;
  int contravalor=0;
  int temporal;
  string mensajeDecifrado=mensaje;

  for (int i=0;i<key;i++){
    temporal=i;
    while(temporal<mensaje.length()){
      mensajeDecifrado[temporal]=mensaje[posicion++];
      temporal+=valor;
      if(valor==0)temporal+=contravalor;
      if(contravalor!=0 && temporal<mensaje.length() && i!=0){
        mensajeDecifrado[temporal]=mensaje[posicion++];
        temporal+=contravalor;
      }
    }
    valor-=2;
    contravalor+=2;
  }
  return mensajeDecifrado;
}
long divisores(long number)
{
  int contador=0;
  for(int i=1;i<number/2;i++){
    if(modulo(number,i)==0)
      contador++;
  }
  return contador;
}

bool is_primo(long number)
 long cifrado_rsa(long e,long n)
 {
   long m=572; ////////////////7 implementar la funcion rand
   long elevado1=m;
   long elevado2=1;
   long resultado=1;

   while(e!=0){
     elevado1=elevado2=modulo((elevado1*elevado2),n);
     if(modulo(e,2)==1)
      resultado=modulo((resultado*elevado1),n);
      e/=2;
   }
   return resultado;
 }
