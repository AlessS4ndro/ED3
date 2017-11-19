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
  int numeroBits;
  string divide_bloque(string,int);
  string complete_bloque(string , int);
  void generate_keys(ZZ &,ZZ &,ZZ &,int );
public:
  RSA(int );
  RSA(ZZ n,ZZ e){this->n=n;this->e=e;alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";}
  string cifrar(string);
  string decifrar(string);
  ZZ ** resto_chino(ZZ **,ZZ );
};

RSA::RSA(int nbits)
{
  alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  nbits=numeroBits;
  ZZ p,q,fiN,d,x,y;
  ZZ c[6];

  generate_keys(p,q,e,nbits);

  n=p*q;
  fiN=(p-1)*(q-1);


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
{
  string mensajeCifrado;
  ZZ posicion;

  for(int i=0;i<tp.length();i++){
    posicion=tp.find(i);
    mensajeCifrado+=int_to_string(exponenciacion_modular(posicion,e,n));
  }

  return mensajeCifrado;
}
string RSA::decifrar(string tc)
{
  string mensajeDecifrado;
  ZZ posicion;

  for(int i=0;i<tc.length();i++){
    posicion=tc.find(i);
    mensajeDecifrado+=int_to_string(exponenciacion_modular(posicion,e,n));
  }
  return mensajeDecifrado;
}
/*
string RSA::cifrar(string tp)
{
  ofstream texto("cifradoRSA.txt");
  string mensajecifrado;
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
}
*/
void RSA::generate_keys(ZZ &p,ZZ &q,ZZ &e,int nbits)
{
  do{
    p=RandomLen_ZZ(nbits/2);cout<<p<<endl;
    q=RandomLen_ZZ(nbits/2);cout<<q<<endl;
  }while(!is_primo(p) || !is_primo(q));

  do{
    e=RandomLen_ZZ(nbits);  /// escogemos un numero e menor que fiN
    e=modulo_ZZ(e,(p-1)*(q-1));   ////  y q sea coprimo con fiN
  }while(euclides_ZZ((p-1)*(q-1),e)!=1);

}
/*
ZZ ** resto_chino(ZZ ** sistema,ZZ nfilas)
{
  ZZ *ps;ps=new ZZ[nfilas];
  ZZ p;p=1;
  ZZ * result[2];
  ZZ *as,*ps,*qs;
  qs=new ZZ[nfilas];
  ZZ psprima;xo;
  xo=0;
  ps=new ZZ[nfilas];
  as=new ZZ[nfilas];
  for(int i=0;i<nfilas;i++){
    ps[i]=sistema[i][1] /// creamos ps
    p*=ps[i] // step 2
  }
  if(!son_primos(ps))  // step 1
    return NULL;
  for(int i=0;i<nfilas ;i++){  // step 3
    ps[i]=p/ps[i];
    psprima=ps[i];
    if(ps[i]>ps[i]){
      psprima=modulo_ZZ(ps[i],ps[i]);
      ZZ mcd,inversaX,inversaY;
      euclides_extendido_ZZ(psprima,ps[i],mcd,inversaX,inversaY);
      qs[i]=inversaX; // step 4
      xo+=sistema[i][0]*ps[i]*qs[i];
    }

  }
  xo=modulo_ZZ(xo,p) /// step 5
  result[0]=xo;
  result[1]=p;   // step 6
}
*/
