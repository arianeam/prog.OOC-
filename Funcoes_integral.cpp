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

using namespace std;

class Funcao {
public:

	Funcao(){};
	Funcao(Funcao* f){}
	virtual double operator()(double x)=0;

   static double integrar(Funcao* f, double x0, double x1, double step)
	{
	   //Integral = (step/2).(f(x0) + 2.soma(f(xi)) + f(xn)) , sendo i=1 até i=n-1

       double n, soma, fx0, fxn;
	   double k = x0 + step;
       n= (x1 - x0)/step;
       cout<<endl;
       cout<<"Numero de segmentos: "<< n << endl;
       cout<< "Passo: "<< step<< endl;
       cout<<"Intervalo: [" << x0 << "," << x1 << "]" << endl;
       cout<<endl;



       while (k < x1)
       {

           soma += f->operator()(k);
           cout<<"soma = " << soma << endl;
           k = k+step;
       }

       fx0 = f->operator()(x0);
       fxn = f->operator()(x1);

       i = (step/2.0)*(fx0 + 2*soma + fxn);
       cout<< "integral = "<< i << endl;

		return i;
	}

	virtual ~Funcao() {
	}

private:
	static double i;

};

 double Funcao :: i;

//----------------------------------------------------
typedef vector<Funcao*> FuncaoVector;


class FuncaoAgregada: public Funcao {
public:

	FuncaoAgregada(){}

	void agrega(Funcao *f) {
		fv.push_back(f);

	}

	double operator()(double x) {
		fx = 0;
		for (FuncaoVector::iterator it = fv.begin(); it != fv.end(); it++) {

		    static_cast<Funcao*>(*it)->operator()(x);
			cout << "f(x) agregada: " << static_cast<Funcao*>(*it)->operator()(x)<< endl;
			fx += static_cast<Funcao*>(*it)->operator()(x);
		}

		cout << "f("<<x<<")= " << fx << endl;
		return fx;
	}


private:
	FuncaoVector fv;
	double fx;
	double x;
};

//---------------------------------------------------

class Constante: public Funcao {
public:

	Constante(){}
	Constante(double v) :
			value(v) {
	}

	double operator()(double x) {
		cout << "Constante" << endl;
		cout << "f(x) = " << value << endl;
		cout << endl;
		return value;
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



	double operator()(double x) {
		cout<< "Escalar"<<endl;
		cout<<"f(x) =" << a <<"x"<<endl;
		cout<< endl;
		fx = a*x;
		cout<<"x = "<<x<<endl;
		cout<<a<<".x="<<fx<<endl;
		return fx;
	}


private:
	double a;
	Funcao *fe;
	double fx;
	//double xvalue;
};
//------------------------------------------------------
class Seno: public Funcao{
public:
	Seno(){}
	Seno(double v): value(v){}
	Seno(Funcao* f){}
	Seno(double v, Funcao* f){}

	double operator()(double x)
		{
		cout<< "f("<<x<<")= sen("<<x<<")"<<endl;
		value = sin(x);
		cout<< "f("<<x<<")= "<< value <<endl;
		return value;
		}

private:
	double value;

};

//------------------------------------------------------

class Cosseno: public Funcao{
public:
	Cosseno(){}
	Cosseno(double v): value(v){}
	Cosseno(Funcao* f){}
	Cosseno(double v, Funcao* f){}

	double operator()(double x)
		{
		cout<< "f("<<x<<")= cos("<<x<<")"<<endl;
		value = cos(x);
		cout<< "f("<<x<<")= "<< value <<endl;
		return value;
		}

private:
	double value;

};

//-----------------------------------------------------

int main() {

	double x0, x1, step;

	/*Constante i(5.15);
	//i(5.15);
	Constante j(10.50);
	//j(10.50);
	Escalar e(20.50);
	//e(20.50);
	FuncaoAgregada fa;
	fa.agrega(&i);
	fa.agrega(&j);
	fa.agrega(&e);
   // fa(2);
	x0 = 0;
	x1 = 0.5;
	step = 0.1;*/
	Cosseno c;
	c(0);

  // Funcao::integrar(&fa,x0,x1,step);

	return 0;
}
