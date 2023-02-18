#include <stdio.h>

int main(){
	//opcion 1
	for (int i = 1; i<10; i=i+1)
	{
		if(i%3==0)
			printf("i = %d \n", i);
	}

  	//opcion 2
  	for (int i = 1; i<10; i++) //Igual a la primera opcion ya que i++ es igual a i=i+1
	{
		if(i%3==0)
			printf("i = %d \n", i);
	}

  	//opcion 3
  	for (int i = 1; i<10; ++i) //Igual a la primera opcion ya que no afecta en este caso ya que i no es utilizado en ninguna operacion anterior, simplemente se incrementa
	{
		if(i%3==0)
			printf("i = %d \n", i);
	}

  	//opcion 4
	for (int i = 1; i<10; i++) //Funciona inversamente a la opcion 1 ya que la operacion i%3 cuando sea igual a cero se tomara como falsa y no imprimira, en los demas casos si
	{
		if(i%3)
			printf("i = %d \n", i);
	}

  	//opcion 5
  	for (int i = 1; i<10; i++) //Funciona igual que la opcion 1
	{
		if(!(i%3))
			printf("i = %d \n", i);
	}

  return 0;
}