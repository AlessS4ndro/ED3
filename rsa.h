#include<NTL/ZZ.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>

using namespace NTL;

class RSA
{
  string alfabeto;
  ZZ private_key;
  ZZ n;
  ZZ e;
public:
  RSA();
  RSA(ZZ n,ZZ e){this->n=n;this->e=e;alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";}
  string cifrar(string);
  string decifrar(string);
};

RSA::RSA()
{
  alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ZZ p,q,fiN,d,x,y;
  ZZ c[6];

  do{
    p=RandomLen_ZZ(8);cout<<p<<endl;
    q=RandomLen_ZZ(8);cout<<q<<endl;
  }while(!is_primo(p) || !is_primo(q));

  n=p*q;
  fiN=(p-1)*(q-1);

  do{
    e=RandomLen_ZZ(16);  /// escogemos un numero e
    e=modulo_ZZ(e,fiN);   //// q sea coprimo con fiN
  }while(euclides_ZZ(fiN,e)!=1);

  euclides_extendido_ZZ(fiN,e,d,x,y); /////// hallamos la inversa de fiN
  if(x<0){
    if(fiN>e)x+=fiN;
    else x+=e;
  }
  private_key=x;
  c[0]=p;c[1]=q;c[2]=n;c[3]=fiN;c[4]=e;c[5]=private_key;
  generar_txt(c);
}

string RSA::cifrar(string tp)
{/*
  ofstream texto("cifradoRSA.txt");
  string mensajecifrado="";
  ZZ m,size,digitosAlfabeto,pos;
  int t;
  size=alfabeto.length();

  digitosAlfabeto=number_digits(size-1); //numero maximo de digitos del alfabeto '2' en caso de 26 letras

  for(int i=0;i<tp.length();i++){ // recorremos el mensaje
    pos=tp.find(tp[i]);  // almacenamos la posicion del caracter
    if(number_digits(pos)!=digitosAlfabeto){
      mensajecifrado+='0'; // completamos el mensaje con ceros
      mensajecifrado+=int_to_string(pos);
    }
    else{
      mensajecifrado+=int_to_string(pos);
    }
  }

  for (int i=0;i<tp.length();i++){
    m=tp.find(tp[i]);
    t=ZZ_to_int(modulo_ZZ(exponenciacion_modular(e,n,m),size));
    mensajecifrado+=alfabeto[t];
  }
  texto<<mensajecifrado;
  texto.close();
  return mensajecifrado;

  //ZZ m;
  //m=alfabeto.find(tp);
  //cout<<"m es: "<<m;
//  cout<<exponenciacion_modular(m,e,n);
*/

}
