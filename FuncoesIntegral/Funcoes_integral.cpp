//============================================================================
// Name        : Funcoes_integral.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

void teste();

class Funcao {
public:

	Funcao() {}

	Funcao(Funcao *f) {}

	virtual double operator()(double x)=0;

	static double integrar(Funcao *f, double x0, double x1, double step) {

		/*Integral = (step/2).(f(x0) + 2.soma(f(xi)) + f(xn)) , sendo i=1 até i=n-1*/

		double soma, fx0, fxn, x = x0;
		double k = x0 + step;

		cout << endl;
		cout << "Passo: " << step << endl;
		cout << "Intervalo de integração : [" << x0 << "," << x1 << "]" << endl;
		cout << endl;

		while (x <= x1)
		{
			cout << "f(" << x << ")= " << f->operator()(x) << endl;
			x += step;
		}

		while (k < x1)
		{

			soma += f->operator()(k);
			k = k + step;
		}

		fx0 = f->operator()(x0);
		fxn = f->operator()(x1);

		i = (step / 2.0) * (fx0 + 2 * soma + fxn);

		return i;
	}

	virtual ~Funcao() {}

private:
	static double i;

};

double Funcao::i;

//----------------------------------------------------

typedef vector<Funcao*> FuncaoVector;

class FuncaoAgregada: public Funcao {
public:

	FuncaoAgregada() {}

	void agrega(Funcao *f)
	{
		fv.push_back(f);
	}

	double operator()(double x)
	{

		double fx = 0;

		for (FuncaoVector::iterator it = fv.begin(); it != fv.end(); it++)
		{
			fx += static_cast<Funcao*>(*it)->operator()(x);
		}

		return fx;
	}


private:
	FuncaoVector fv;
};

//---------------------------------------------------

class Constante: public Funcao {
public:

	Constante() : value(0) {}
	Constante(double v) : value(v) {}

	double operator()(double x)
	{
		return value;
	}

private:
	double value;
};

//------------------------------------------------------
class Escalar: public Funcao {
public:

	Escalar() : a(1), f(0) {}
	Escalar(double v) : a(v), f(0) {}
	Escalar(Funcao *func) : a(1), f(func) {}
	Escalar(Funcao *func, double v) : a(v), f(func) {}

	double operator()(double x)
	{

		double fx = 0;

		if (f != NULL)
		{
			x = f->operator()(x);
		}

		fx = a * x;

		return fx;
	}

private:
	double a;
	Funcao *f;
};
//------------------------------------------------------
class Seno: public Funcao {
public:
	Seno() : value(1), f(0) {}
	Seno(double v) : value(v), f(0) {}
	Seno(Funcao *func) : value(1), f(func) {}
	Seno(double v, Funcao *func) : value(v), f(func) {}

	double operator()(double x)
	{

		double fx = 0;

		if (f != NULL)
		{
			x = f->operator()(x);
		}

		fx = value * sin(x);

		return fx;
	}

private:
	double value;
	Funcao *f;

};

//------------------------------------------------------

class Cosseno: public Funcao {
public:
	Cosseno() : value(1), f(0) {}
	Cosseno(double v) : value(v), f(0) {}
	Cosseno(Funcao *func) :	value(1), f(func) {}
	Cosseno(double v, Funcao *func) : value(v), f(func) {}

	double operator()(double x)
	{

		double fx = 0;

		if (f != NULL)
		{
			x = f->operator()(x);
		}

		fx = value * cos(x);

		return fx;
	}

private:
	double value;
	Funcao *f;
};

//-----------------------------------------------------

class Potencial: public Funcao {
public:

	Potencial() : a(1), f(0) {}
	Potencial(double v) : a(v), f(0) {}
	Potencial(Funcao *func) : a(1), f(func) {}
	Potencial(double v, Funcao *func) :	a(v), f(func) {}

	double operator()(double x)
	{

		double fx = 0;

		if (f != NULL)
		{
			x = f->operator()(x);
		}

		fx = pow(x, a);

		return fx;
	}

private:

	double a;
	Funcao *f;

};

//----------------------------------------------------

class Exponencial: public Funcao {
public:

	Exponencial() {}
	Exponencial(double v) :	a(v), f(0) {}
	Exponencial(Funcao *func) :	a(1), f(func) {}
	Exponencial(double v, Funcao *func) : a(v), f(func) {}

	double operator()(double x)
	{

		double fx = 0;

		if (f != NULL)
		{
			x = f->operator()(x);
		}

		fx = pow(a, x);

		return fx;
	}

private:

	double a;
	Funcao *f;

};

//-----------------------------------------------------------------

int main() {

	teste();

	return 0;
}

void teste() {

	double step = 0.01, x0 = 0.0, x1 = 5.0;
	/* Com um step maior a precisão da integral aumenta
	 Para a seguinte funcao um step de 0.001 já alcança o valor da integral calculada
	 de forma manual */

	Potencial a(2); //x^2

	Escalar b(2);   //2x
	Constante c(-1);
	FuncaoAgregada d;
	d.agrega(&b);
	d.agrega(&c);
	Seno e(&d); //Seno(2x - 1)
	Escalar f(&e, 5); //5.Seno(2x - 1)

	Constante g(5);

	FuncaoAgregada h; //x^2 + 5.Seno(2x - 1) + 5
	h.agrega(&a);
	h.agrega(&f);
	h.agrega(&g);

	cout << "Intregal= " << Funcao::integrar(&h, x0, x1, step) << endl;

}
