//============================================================================
// Name        : Funcoes_integral.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Funcao {
public:

	virtual double operator()(void)=0;
	virtual double getvalue(void)=0;
	virtual void setvalue(double x)=0;

	static double integrar(Funcao* f, double x0, double x1, double step)
	{

		return 0;
	}

	virtual ~Funcao() {
	}

private:
	double i;

};

//----------------------------------------------------
typedef vector<Funcao*> FuncaoVector;

class FuncaoAgregada: public Funcao {
public:

	void agrega(Funcao *f) {
		fv.push_back(f);

	}

	double operator()(void) {
		fx = 0;
		for (FuncaoVector::iterator it = fv.begin(); it != fv.end(); it++) {
			cout << "f(x) agregada: " << static_cast<Funcao*>(*it)->getvalue()
					<< endl;
			fx += static_cast<Funcao*>(*it)->getvalue();
		}

		cout << "f(x)= " << fx << endl;

		return fx;
	}

	double getvalue(void) {
		return fx;
	}

	void setvalue(double x)
	{

	}
private:
	FuncaoVector fv;
	double fx;
};

//---------------------------------------------------

class Constante: public Funcao {
public:

	Constante(double v) :
			value(v) {
	}

	double operator()(void) {
		cout << "Constante" << endl;
		cout << "f(x) = " << value << endl;
		cout << endl;
		return value;
	}
	double getvalue(void) {
		return value;
	}

	void setvalue(double x)
		{

		}
private:
	double value;
};

//------------------------------------------------------
class Escalar: public Funcao {
public:

	Escalar(){}
	Escalar(double v): a(v){}
	Escalar(Funcao* f): fe(f){}
	Escalar(Funcao* f, double v): a(v), fe(f){}



	double operator()(void) {

		cout<< "Escalar"<<endl;
		cout<<"f(x) =" << a <<"x"<<endl;
		cout<< endl;
		return a;
	}
	double getvalue(void) {
		return a;
	}

	void setvalue(double x)
	{
			xvalue = x;
			//a = a*xvalue; // para testar a função
	}

private:
	double a;
	Funcao *fe;
	double xvalue;
};
//------------------------------------------------------

int main() {

	Constante i(5.15);
	i();
	Constante j(10.50);
	j();
	Escalar e(20.50);
	e();
	e.setvalue(2);
	FuncaoAgregada fa;
	fa.agrega(&i);
	fa.agrega(&j);
	fa.agrega(&e);
	fa();

	return 0;
}
