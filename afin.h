#include<stdlib.h>

class Afin
{
  string alfabeto;
  int key_a;
  int key_b;
public:
  Afin():alfabeto("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ,._-0123456789"){}
  Afin(int a,int b):key_a(a),key_b(b),alfabeto("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ,._-0123456789"){}
  string cifrar(string);
  string descifrar(string);
};


string Afin::cifrar(string mensaje)
{
  string mensajeNuevo="";
  int x;
  int size=alfabeto.length();
  do{
    key_a=rand();                //////////////completar con la funcion del p okemon
    key_a=modulo(key_a,size);
  }while(euclides(size,key_a) != 1);
  do{
    key_b=rand();              ////////    completar con la funcion del pokemon
    key_b=modulo(key_b,size);
  }while(key_b<0);

  for (int i=0;i<mensaje.length();i++){
    x=alfabeto.find(mensaje[i]);
    x=x*key_a;
    x=modulo(x,size);

    x=x+key_b;
    x=modulo(x,size);
    mensajeNuevo+=alfabeto[x];
  }
  cout<<"key_a es: "<<key_a<<endl;
  cout<<"key_b es: "<<key_b<<endl;
  return mensajeNuevo;
}

string Afin::descifrar(string mensaje)
{
  string mensajeNuevo="";
  int y;
  int size=alfabeto.length();
  long c,inversa_a,inversa_b;

  for (int i=0;i<mensaje.length();i++){
    y=alfabeto.find(mensaje[i]);
    y=y-key_b;
    y=modulo(y,size);
    euclides_extendido(key_a,size,c,inversa_a,inversa_b);
    y=inversa_a*y;
    y=modulo(y,size);
    mensajeNuevo+=alfabeto[y];
  }
  return mensajeNuevo;
}
