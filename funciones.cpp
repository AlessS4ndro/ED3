#include<iostream>
#include<stdlib.h>
#include<NTL/ZZ.h>
#include"funciones.h"
#include<fstream>
using namespace std;
using namespace NTL;

long a,b,d,x,y;

int euclides(int a,int b)
{
  if(b==0)
    return a;
  return euclides(b,modulo(a,b));
}
ZZ euclides_ZZ(ZZ a,ZZ b)
{
  if(b==0)
    return a;
  return euclides_ZZ(b,modulo_ZZ(a,b));
}
int modulo(int value,int modulo)
{
	int cociente=value/modulo;

	if(value>=0)
		return value-cociente*modulo;
	return modulo-(value*-1+cociente*modulo);
}
ZZ modulo_ZZ(ZZ value,ZZ modulo)
{
	ZZ cociente=value/modulo;

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
void euclides_extendido_ZZ(ZZ a,ZZ b,ZZ &d,ZZ &x,ZZ &y)
{
  ZZ x1,y1;

  if(b==0){
    d=a;
    x=1;
    y=0;
  }
  else{
    euclides_extendido_ZZ(b,modulo_ZZ(a,b),d,x,y);
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

 bool is_primo(ZZ number)
 {
   ZZ i,raizCuadrada;
   raizCuadrada=SqrRoot(number);
   for ( i=2;i<raizCuadrada+1;i++){

     if(modulo_ZZ(number,i)==0)
       return false;
   }
   if(number==0)
     return false;
   return true;
 }
 /*
 bool son_primo(ZZ * number)
 {
   ZZ i,raizCuadrada;
   raizCuadrada=SqrRoot(number);
   for( i=2;i<raizCuadrada+1;i++){

     if(modulo_ZZ(number,i)==0)
       return false;
   }
   if(number==0)
     return false;
   return true;
*/
ZZ exponenciacion_modular(ZZ e,ZZ n,ZZ m)

 {
   ZZ elevado1,elevado2,resultado,dos;
   dos=2;
   elevado1=m;
   elevado2=1;
   resultado=1;

   while(e!=0){
     elevado1=elevado2=modulo_ZZ((elevado1*elevado2),n);
     if(modulo_ZZ(e,dos)==1)
      resultado=modulo_ZZ((resultado*elevado1),n);
      e/=2;
   }
   return resultado;
 }

void generar_txt(ZZ *z)
{
  ofstream texto("cifradoRSA.txt");
  texto<<"\nP es: "<<z[0];
  texto<<"\nBits de P: "<<NumBits(z[0]);
  texto<<"\nQ es: "<<z[1];
  texto<<"\nBits de Q: "<<NumBits(z[1]);
  texto<<"\nN es: "<<z[2];
  texto<<"\nBits de N: "<<NumBits(z[2]);
  texto<<"\nfiN es: "<<z[3];
  texto<<"\nBits de fiN: "<<NumBits(z[3]);
  texto<<"\nE es: "<<z[4];
  texto<<"\nBits de E: "<<NumBits(z[4]);
  texto<<"\nla clave privada es: "<<z[5];
  texto<<"\nBits de la clave privada: "<<NumBits(z[5]);
  texto.close();
}
int ZZ_to_int(ZZ number)
{////////// un prerequisito es que number sea de 4 bytes o menos
  unsigned int sumador,crece;
  ZZ conejo,creciente,i;
  sumador=0;
  creciente=1;
  conejo=1;
  crece=1;

  for(i=1;i<NumBits(number)+1;i++){
    creciente=conejo & number;
    if(and_binari(creciente)){
      sumador+=crece;
    }
    else creciente=conejo;
    creciente<<=1;
    conejo=conejo<<1;
    crece<<=1;
  }

  return sumador;
}
bool and_binari(ZZ n)
{
  ZZ cero;
  cero=0;
  if(n==cero)
    return false;
  return true;
}

ZZ number_digits(ZZ n)
{
  ZZ contador;
  contador=0;

  while(n!=0){
    n/=10;
    contador++;
  }
  return contador;
}

string int_to_string(ZZ number)
{
  string palabra;
  char numeros[10]={'0','1','2','3','4','5','6','7','8','9'};
  char temp;
  int size;
  ZZ diez;
  diez=10;

  while(number!=0){
    palabra+=numeros[ZZ_to_int(modulo_ZZ(number,diez))];
    number/=10;
  }
  size=palabra.length();
  for (int i=0;i<size/2;i++){
    temp=palabra[i];
    palabra[i]=palabra[size-i-1];
    palabra[size-i-1]=temp;
  }
  return palabra;
}
