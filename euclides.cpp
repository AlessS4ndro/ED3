#include "funciones.h"
int euclides(int a,int b)
{
  if(b==0)
    return a;
  return euclides(b,module(a,b));
}
