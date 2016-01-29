//Programa menu

#include <iostream>
#include <cmath>
#define PI 3.141592653589793
using namespace std;

float Celsius2Fahrenheit(float);
float Celsius2Kelvin(float);
double factorial(double);
int suma(int);
void prog01();
void prog02();
void prog03();
void prog04();
void prog05();
void prog06();
void prog07();
void prog08();
void prog09();

int main(int argc, char const *argv[])
{
	int eleccion=99;
	char aux;
	while (true){
		cout << endl << "Menu de programas." << endl;
		cout <<"0) Salir " << endl;
		for (int i = 1; i < 10; ++i)
			{
			cout << i << ") prog " << i << endl;
			}
		cin >> eleccion;

		switch (eleccion) {
			case 0: cout << "Adios..." << endl << endl << "Desarrollado por: " << endl; 
			case 1: prog01(); break;
			case 2: prog02(); break;
			case 3: prog03(); break;
			case 4: prog04(); break;
			case 5: prog05(); break;
			case 6: prog06(); break;
			case 7: prog07(); break;
			case 8: prog08(); break;
			case 9: prog09(); break;
			default : cout << "No es una eleccion valida" << endl;		
			}
			aux = 'X';
			while(eleccion!=0 && aux!='S' && aux!='N'){
				//aux='S'; // valor por defecto para continuar con "enter"
				cout << "\n¿Quieres volver al menu? (S/N)" << endl;
				cin >> aux;
				cin.ignore(INT_MAX, '\n');
				}
			if (aux=='N' || eleccion==0) return 0;
		}

	return 0;
}

//PROGRAMA 11111111111111

void prog01()
{
	string alumno = "Jose Arturo Gamez Lugo";
	string curso = "Proteco - Cpp Basico";
	cout << "Alumno: " << alumno << endl << "Curso: " << curso << endl;
}

//PROGRAMA 2222222222222
void prog02()
{
	float celsius=0, fahrenheit=0, Kelvin=0;
	cout << "Programa para convertir grados celsius a Fahrenheit y Kelvin \n\n";

	cout << "Grados Celsius: ";
	cin >> celsius;

	cout << Celsius2Fahrenheit(celsius) << " grados Fahrenheit\n";
	cout << Celsius2Kelvin(celsius) << " Kelvin\n";
}

float Celsius2Fahrenheit(float x){
	return x*9/5.0+32;
}

float Celsius2Kelvin(float x){
	return x+273.15;
}

//PROGRAMA 3333333333333
void prog03()
{
	float grado;
	cout << "Programa para calcular: seno, coseno y tangente de un grado\n";

	cout.precision(17);
	cout << "Éste programa usa una aproximacion a PI = " << PI << endl << endl;
	cout << "Grado: ";
	cin >> grado;

	cout.precision(4);
	cout << "sen(" << grado << ") = " << sin(grado*PI/180) << endl; //revisar que los datos deben ser en radianes
	cout << "cos(" << grado << ") = " << cos(grado*PI/180) << endl; //revisar que los datos deben ser en radianes
	cout << "tan(" << grado << ") = " << tan(grado*PI/180) << endl; //revisar que los datos deben ser en radianes

}

//PROGRAMA 4444444444444

void prog04()
{
	int arreglo[20];
	int indiceMax=0, indiceMin=0;
	srand (time(NULL)); //para que la semilla de random cambie al momento de ejecucion

	for (int i = 0; i < 20; ++i)
	{
		arreglo[i]=rand() % 100; //numero aleatorio de 0 a 100
		cout << "arreglo[" << i << "] : " << arreglo[i] << endl;
	}

	for (int i = 0; i < 20-1; ++i)
	{
		if (arreglo[i]<arreglo[indiceMin]) indiceMin=i;
		if (arreglo[i]>arreglo[indiceMax]) indiceMax=i;
	}

	cout << endl << "Valor minimo: " << "arreglo[" << indiceMin << "] = " << arreglo[indiceMin] << endl;
	cout << endl << "Valor maximo: " << "arreglo[" << indiceMax << "] = " << arreglo[indiceMax] << endl << endl;

}

//PROGRAMA 55555555555


void prog05()
{
	int x = 0;
	cout << "Programa para calcular el factorial de un numero. \n";
	cout << "Introduce un numero entero: ";
	cin >> x;

	if (x<0) {
		cout << "ERROR. No existe factorial para numeros negativos" << endl;
		return ;
	}
	cout << endl << x << "! = " << factorial(x) << endl << endl;

}

double factorial(double x){

	if (x==0) return 1;
	for (int i = x-1; i > 1; --i) x*=i;
	return x;
}

//PROGRAMA 666666666666


void prog06()
{
	int a=0;
	cout << "Programa que raliza la suma de x desde 0 hasta i" << endl;
	cout << "i (entero) = ";
	cin >> a;
	cout << "Suma de x desde 0 hasta i : " << suma(a) << endl;
}

int suma(int a){
	if (a>=0) {for (int i = a; i > 1; --i) a += i-1;}
	else {cout << "ERROR. Solo se calcula de 0 hasta i (i debe ser positivo)"<< endl; return 0;}
	return a;
}

//PROGRAMA 77777777777

void prog07()
{	
	int numAlumnos=0, alumnosReprobados=0;
	float promedio=0;
	cout << "Ingresa el numero de alumnos: ";
	cin >> numAlumnos;

	int posCal[11]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int calAlumno[numAlumnos];
	for (int i = 0; i < numAlumnos; ++i)
	{	
		calAlumno[i]=-1;
		while(calAlumno[i]<0 || calAlumno[i]>10){
			cout << "Ingresa calificacion (valores enteros) del alumno " << i+1 << " : ";
			cin >> calAlumno[i];		
		}
		posCal[calAlumno[i]]++; // para calcular la moda.
		promedio += calAlumno[i];
		if (calAlumno[i]<6) alumnosReprobados++;
	}
	promedio/=numAlumnos;

	//calculando la moda
	int moda=0;
	for (int i = 1; i < 11; ++i) moda=(posCal[i]>=posCal[moda])?i:moda;
	//Solo calcula la moda cuando es un valor repetido mas veces (si dos o mas valores son los mas repetidos (mismo numero de veces cada uno) toma el mayor)
	
	cout.precision(2);
	cout << "promedio: " << promedio << endl;
	cout << "moda: " << moda << endl;
	cout << "alumnos reprobados: " <<  alumnosReprobados << endl;

}

//PROGRAMA 888888888888

void prog08()
{	
	bool salida = true;

	char aux;
	int edad=-1;
	int i=0; // contador total
	int hombres=0, mujeres=0;
	int sinEscolaridad=0, primaria=0, secundaria=0, bachillerato=0, universidad=0;
	int ninos=0, jovenes=0, adultos=0, adultosMayores=0;
	for (i = 0; salida; ++i)
	{
		aux='j';
		while (aux!='M' && aux!='F'){
			cout << "Sexo (M/F): "; 
			cin >> aux;
			cin.ignore(INT_MAX, '\n');
		}
		if (aux == 'M') hombres++;
		if (aux == 'F') mujeres++;

		aux='j';
		while (aux!='N' && aux!='P' && aux!='S' && aux!='B' && aux!='U'){
			cout << "Escolaridad (N/sin escolaridad, P/primaria, S/secundaria, B/bachillerato, U/universidad: ";
			cin >> aux;
			cin.ignore(INT_MAX, '\n');
		}
		if (aux == 'N') sinEscolaridad++;
		else if (aux == 'P') primaria++;
		else if (aux == 'S') secundaria++;
		else if (aux == 'B') bachillerato++;
		else universidad++;

		edad=-1;
		while (edad<0) {
			cout << "Edad (en anos): ";
			cin >> edad;
			cin.ignore(INT_MAX, '\n');
		}

		if (edad<13) ninos++;
		else if (edad < 31) jovenes++;
		else if (edad <= 60 ) adultos++;
		else adultosMayores++;

		aux='j';
		while(aux!='S' && aux!='N'){
			cout << "Hay otro habitante? (S/N)";
			cin >> aux;
			salida = !(aux=='N');
			cin.ignore(INT_MAX, '\n');
		}
	}

	cout << endl;
	cout << "El " << hombres*100.0/i << "% son hombres\n";
	cout << "El " << mujeres*100.0/i << "% son mujeres\n";
	cout << "El " << ninos*100.0/i << "% son ninos\n";
	cout << "El " << jovenes*100.0/i << "% son jovenes\n";
	cout << "El " << adultos*100.0/i << "% son adultos\n";
	cout << "El " << adultosMayores*100.0/i << "% son adultos mayores\n";
	cout << "El " << sinEscolaridad*100.0/i << "% no tiene escolaridad\n";
	cout << "El " << primaria*100.0/i << "% tiene grado maximo: primaria\n";
	cout << "El " << secundaria*100.0/i << "% tiene grado maximo: secundaria\n";
	cout << "El " << bachillerato*100.0/i << "% tiene grado maximo: bachillerato\n";
	cout << "El " << universidad*100.0/i << "% tiene grado maximo: universidad\n";
	
}

//PROGRAMA09


void prog09()
{
	/* code */
	const int tarifaNaranja = 100;
	const int tarifaLimon = 120;
	const int tarifaCola = 150;

	const int tarifaMayoreoNaranja = 90;
	const int tarifaMayoreoLimon = 110;
	const int tarifaMayoreoCola = 125;

	const int descuentoMayoreo = 5; // 5% de descuento adicional si se compran mas de 100 cajas.

	int Naranja=0, Limon=0, Cola=0;
	int aux=0;
	int total=0;

	cout << "Introduce la cantidad de cajas de refresco de Naranja: ";
	cin >> Naranja;
	cout << "Introduce la cantidad de cajas de refresco de Limon: ";
	cin >> Limon;
	cout << "Introduce la cantidad de cajas de refresco de Cola: ";
	cin >> Cola;

	cout << "\nCosto de los productos: " << endl;

	cout << Naranja << " cajas de refresco de Naranja:  \t$" << Naranja*tarifaNaranja << endl;
	cout << Limon << " cajas de refresco de Limon:    \t$" << Limon*tarifaLimon << endl;
	cout << Cola << " cajas de refresco de Cola:     \t$" << Cola*tarifaCola << endl;

	cout << "\nAplicando descuentos por mayoreo en cada tipo de refresco. (Si es que hay)\n\n";

	total=0;
	if (Naranja>10) {
		cout << "Refresco de Naranja con descuento:    \t$" << Naranja*tarifaMayoreoNaranja << endl;
		total+=Naranja*tarifaMayoreoNaranja;
	}else total+= Naranja*tarifaNaranja;

	if (Limon>20) {
		cout << "Refresco de Limon con descuento:    \t$" << Limon*tarifaMayoreoLimon << endl;
		total+=Limon*tarifaMayoreoLimon;
	}else total += Limon*tarifaLimon;

	if (Cola>50) {
		cout << "Refresco de Cola con descuento:    \t$" << Cola*tarifaMayoreoCola << endl;
		total+=Cola*tarifaMayoreoCola;
	}else total += Cola*tarifaCola;
	cout << "-------------------------------------------" << endl;
	cout << "Total: $" << total << ".00" << endl;

	if ((Naranja+Limon+Cola)>100){
		cout << "-----------------------------------------------------" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "Descuento especial por comprar mas de 100 cajas (5%)" << endl;
		cout.precision(2);
		int enteros =  (int)(total*(100-descuentoMayoreo)/100.0);
		int decimal = (int)((total*(100-descuentoMayoreo))-enteros*100);
		cout << "Total: $" << enteros << "." << decimal << endl;
		cout << "-----------------------------------------------------" << endl;

	}

}