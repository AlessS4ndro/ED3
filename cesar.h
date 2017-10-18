#include<iostream>
#include<string>
#include"funciones.h"

class Cesar
{
	int key;
public:
	string alfabeto;

	Cesar(int key){this->key=module(key,27);alfabeto="abcdefghijklmnñopqrstuvwxyz ";}
	string cifrar(string);
	string descifrar(string);

};

string Cesar::cifrar(string mensaje)
{
	int posicion;
	int espacio;
	int temp;
	for (int i=0;i<mensaje.length();i++){
		posicion=alfabeto.find(mensaje[i]);
		espacio=28-posicion;
		if(espacio>=key)
			mensaje[i]=alfabeto[key+posicion];
		else{
			temp=key-(28-posicion);
			mensaje[i]=alfabeto[temp-1];
		}
	}
	return mensaje;
}
string Cesar::descifrar(string mensaje)
{
	int posicion;
	int espacio;
	int temp;
	for (int i=0;i<mensaje.length();i++){
		posicion=alfabeto.find(mensaje[i]);
		espacio=posicion-0;
		if(espacio>=key)
			mensaje[i]=alfabeto[posicion-key];
		else{
			temp=key-(posicion-0);
			mensaje[i]=alfabeto[29-temp];
		}
	}
	return mensaje;
}
