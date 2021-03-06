//BSD License

#include <fstream>
#include <cmath>
#include <iostream>

double f(const double x)
{
  return sin(x);
}

double rettangoli(double a, double b, int N) //integra f in [a,b] con N rettangoli
{
  double sum = 0.0;
  double dx = (b - a) / N;

  for (int i = 0; i < N; i++)
  {
	  sum+=f(a+i*dx)*dx;
  }

  return sum;
}

double trapezi(double a, double b, int N)
{
  double sum = 0.0;
  double dx = (b - a) / N;

  for (int i = 0; i < N; i++)
  {
	  sum+=(f(a+i*dx)+f(a+(i+1)*dx))*dx/2.0;
  }

  return sum;
}

double simpson(double a, double b, int N)
{
	if(N%2!=0)
		return 0;	//Il metodo di Cavalieri-Simpson non funziona se n è dispari
	else
	{
		double sum=0.0;
		double dx = (b - a) / N;
		for (int i = 1; i < N; i++)
		{
			if(i%2==0)
				sum+=2*f(a+i*dx)*dx/3;
			else
				sum+=4*f(a+i*dx)*dx/3;
		}
		sum+=(f(a)+f(b))*dx/3;
		return sum;
	}
}

int main(void)
{
  std::ofstream f("out.txt", std::ios::out);

  double truth = 1.0 - cos(1.0);

  for (int n = 1; n < 100; n++) //calcolo degli integrali con varie discretizzazioni(segmenti)
  {
    int N = n*n; //numero di segmenti
    f << N << " " << rettangoli(0.0, 1.0, N) - truth /*errore con il metodo dei rettangoli*/ << " " << trapezi(0.0, 1.0, N) - truth << " " << simpson(0.0, 1.0, N) - truth << std::endl;
  }


  f.close();
}
