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
			return value-multiplo;
		}

		return multiplo-value;

}
