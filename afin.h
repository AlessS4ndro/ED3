#include<stdlib.h>

class Afin
{
  string alfabeto;
  int key_a;
  int key_b;
public:
  Afin():alfabeto("abcdefghijklmnopqrstuvwxyz"){}
  Afin(int a,int b):key_a(a),key_b(b),alfabeto("abcdefghijklmnopqrstuvwxyz"){}
  string cifrar(string);
  string descifrar(string);
};


string Afin::cifrar(string mensaje)
{
  string mensajeNuevo="";
  int x;
  int size=alfabeto.length();cout<<"el size es: "<<size<<endl;

  do{
    key_a=rand();                //////////////completar con la funcion del p okemon
    key_a=modulo(key_a,size);
  }while(euclides(size,key_a) != 1);cout<<"el key_a es: "<<key_a<<endl;
  do{
    key_b=rand();              ////////    completar con la funcion del pokemon
    key_b=modulo(key_b,size);
  }while(key_b<0);cout<<"el key_b es<: "<<key_b<<endl;
  
  for (int i=0;i<mensaje.length();i++){
    x=alfabeto.find(mensaje[i]);cout<<" primer valor de x : "<<x<<endl;
    x=x*key_a;cout<<"x antes del primer modulo 26"<<x<<endl;
    x=modulo(x,size);

    x=x+key_b;cout<<"x antes del segundo modulo 26 "<<x<<endl;
    x=modulo(x,size);
    mensajeNuevo+=alfabeto[x];
  }
  return mensajeNuevo;
}

string Afin::descifrar(string mensaje)
{
  string mensajeNuevo="";
  int y;
  int size=alfabeto.length();cout<<"el size es: "<<size<<endl;
  long c,inversa_a,inversa_b;

  for (int i=0;i<mensaje.length();i++){
    y=alfabeto.find(mensaje[i]);cout<<" primer valor de y: "<<y<<endl;
    y=y-key_b;cout<<"y antes del primer modulo 26 "<<y<<endl;
    y=modulo(y,size);
    euclides_extendido(key_a,size,c,inversa_a,inversa_b);cout<<"key_a es: "<<key_a<<" inversa a es :"<<inversa_a<<" inversa_b es : "<<inversa_b<<endl;
    y=inversa_a*y;cout<<"y antes del segundo moudlo 26 "<<y<<endl;
    y=modulo(y,size);
    mensajeNuevo+=alfabeto[y];
  }
  return mensajeNuevo;
}
