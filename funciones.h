#include<iostream>
#include<string>
#include<NTL/ZZ.h>

using namespace NTL;
using namespace std;
int modulo(int,int);
string ballas_encriptar(string,int);
string ballas_desencriptar(string,int);
int euclides(int,int);
ZZ euclides_ZZ(ZZ,ZZ);
void euclides_extendido(long,long,long &,long &,long &);
ZZ exponenciacion_modular(ZZ,ZZ,ZZ);
ZZ modulo_ZZ(ZZ,ZZ);
bool is_primo(ZZ);
void euclides_extendido_ZZ(ZZ,ZZ,ZZ &,ZZ &,ZZ&);
void generar_txt(ZZ *);
int ZZ_to_int(ZZ);
bool and_binari(ZZ);
ZZ number_digits(ZZ);
string int_to_string(ZZ);
