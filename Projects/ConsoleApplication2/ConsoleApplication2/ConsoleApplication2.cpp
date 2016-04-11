// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class calculadora{

  private:
	  float numero;
  public:
	  calculadora(){ numero = 0; }
	  calculadora(float _numero){ _numero; }
	  float getnumero()const{ return numero; }
	  void setnumero(float numero){ numero; }
      //metodo virtual y comportamientos
	  void Sumar(float x){ numero +=x; }
	  void Restar(float x){ numero -=x; }
	  void Multiplicar(float x){ numero*=x; }
	  void Dividir(float x){ numero /=x; }
	  void Potenciacion(){ numero*=numero*=numero*=numero; }
	  ~calculadora(){}
};

int main()
{
	
	calculadora a(2);
	
	
		
	bool flag = true;
	    float p;
		cout << "declare el numero de la variable p" << endl;
		cin >> p;
	
		cout << "1.Sumar" << endl;
		cout << "2.Restar" << endl;
		cout << "3.Multiplicacion" << endl;
		cout << "4.Division" << endl;
		cout << "5.Potenciacion" << endl;
		cout << "6.Salir" << endl;
	
		while (flag){
			cout << a.getnumero() << endl;
			char opcion;
			opcion = getchar();
			switch (opcion){

			case '1':{
				a.Sumar(p);
			    break;
				}
			case '2':{
				a.Restar(p);
			    break;
				}
			case '3':{
				a.Multiplicar(p);
				break;
				}
			case '4':{
				a.Dividir(p);
				break;
				}
			case '5':{
				a.Potenciacion();
				break;
				}
			case '6':{
					flag = false;
				break;
				}
				
}
}
system("pause");
return 0;
}

