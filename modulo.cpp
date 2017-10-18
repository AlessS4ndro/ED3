int module(int value,int modulo)
{
	int cociente=value/modulo;

	if(value>0)
		return value-cociente*modulo;
	return modulo-(value*-1+cociente*modulo);
}
