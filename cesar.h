#include<iostream>
#include<string>

int module(int value,int modulo)
{
	int multiplo=modulo;
	bool positivo=true;

		if(value<0){value*=-1;positivo=false;}	////// volvemos positivo

		while(multiplo<value){
			multiplo+=modulo;
		}

		if(value==multiplo)
			return 0;
		if(positivo){
			multiplo-=modulo;
			cout<<"modulo retorna "<<value-multiplo<<endl;
			return value-multiplo;
		}

		cout<<"modulo retorna "<<multiplo-value<<endl;
		return multiplo-value;

}

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
