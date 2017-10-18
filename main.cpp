#include<iostream>
#include<string>

using namespace std;
#include"funciones.h"
//#include"cesar.h"
#include"afin.h"




int main(int argc,char ** argv)
{
  /*
  string mensajeCifrado;
  mensajeCifrado=ballas_encriptar("simionomatasimio",5);
  cout<<mensajeCifrado<<endl;

  Cesar sesion(atoi(argv[2]));
  string mensajeCifrado;

  mensajeCifrado=sesion.cifrar(argv[1]);
  cout<<"mensa cifrado es: "<<mensajeCifrado<<endl;
  cout<<"el mensaje original es: "<<sesion.descifrar(mensajeCifrado)<<endl;
  return 0;
  cout<<"euclides es:"<<euclides(atoi(argv[1]),atoi(argv[2]))<<endl;

  cout<<"encriptando mensaje "<<argv[1]<<" con la llave "<<atoi(argv[2])<<endl;
  cout<<"result......."<<ballas_encriptar(argv[1],atoi(argv[2]))<<endl;
  cout<<"ejecutando el descifrado del mensaje......."<<endl;
  cout<<"result.........."<<ballas_desencriptar(ballas_encriptar(argv[1],atoi(argv[2])),atoi(argv[2]))<<endl;

  long d,x,y;

  cout<<">ejecutando euclides extendido ..."<<endl;
  euclides_extendido(atoi(argv[1]),atoi(argv[2]),d,x,y);
  cout<<"la ecuacionlineal es : "<<atoi(argv[1])<<"*"<<x<<"+"<<atoi(argv[2])<<"*"<<y<<" = "<<d<<endl;
  */

//  cout<<"el modulo es: "<<module(atoi(argv[1]),atoi(argv[2]))<<endl;

  Afin emisor;
  string message=emisor.cifrar(argv[1]);
  cout<<message<<endl;
  Afin receptor(11,17);
  cout<<receptor.descifrar(message)<<endl;
}
