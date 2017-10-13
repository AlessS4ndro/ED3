#include<iostream>
#include<string>

using namespace std;

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
