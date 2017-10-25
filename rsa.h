#include<NTL,ZZ.h>

using namespace ZZ;

class RSA
{
  string alfabeto;
  ZZ private_key;
  ZZ n;
  ZZ e;
public:
  RSA();
  RSA(ZZ ,ZZ);
  string cifrar();
  string decifrar();

};

RSA::RSA()
{
  ZZ p,q,fiN;

  do{
    p=rand();
    q=rand();
  }while(is_primo(p) && is_primo(q));

  n=p*q;

}
