#include<bits/stdc++.h>
using namespace std;

class punto2D{
	public:
		float x,y;
		punto2D(float x,float y) : x(x),y(y){}
		void mostrar(){
			cout<<"x = "<<x<<" y = "<<y<<endl;
		}
			
};
class triangulo2D{
	private:
		punto2D *p1,*p2,*p3;
	public:
		triangulo2D(punto2D *p1,punto2D *p2,punto2D *p3) : p1(p1),p2(p2),p3(p3){} 
		float longitudLado(punto2D *p1,punto2D *p2){
			return sqrt(pow(p2->x - p1->x,2) + pow(p2->y - p1->y,2));
		}
		float area(){
			if(p1->x == p2->x && p1->y != p2->y){
				return (longitudLado(p2,p1)*longitudLado(p2,p3))/2;
			}else if(p1->x != p2->x && p1->y == p2->y){
				return (longitudLado(p1,p2)*longitudLado(p1,p3))/2;
			}else if(p1->x != p2->x && p1->y != p2->y){
				return (longitudLado(p3,p1)*longitudLado(p3,p2))/2;
			}
			return 0;
		}
		float perimetro(){
			return longitudLado(p1,p2) + longitudLado(p1,p3) + longitudLado(p2,p3);
		}
		void mostrar(){
			cout<<"Punto 1: ";
			p1->mostrar();
			cout<<"Punto 2: ";
			p2->mostrar();
			cout<<"Punto 3: ";
			p3->mostrar();
		}
};

int main(){
	int x1,y1,x2,y2;
	
	cout<<"Introduce el punto x1: ";
	cin>>x1;
	cout<<"Introduce el punto y1: ";
	cin>>y1;
	cout<<"Introduce el punto x2: ";
	cin>>x2;
	cout<<"Introduce el punto y2: ";
	cin>>y2;
	cout<<endl;
	punto2D *punto1 = new punto2D(x1,y1);
	punto2D *punto2 = new punto2D(x2,y2);
	int sumx=0,sumy=0;
	bool f=true;
	
	//Se suma porque los puntos ingresados forman uno de los catetos y son iguales en x o y.
	//También se comprueba que no se halla ingresado los mismos puntos.
	if(x1==x2 && y1!=y2){
		sumx=2; 
	}else if(x1!=x2 && y1==y2){
		sumy=2; 
	}else if(x1==x2 && y1==y2) {
		cout<<"Acabas de introducir 2 puntos iguales, no se puede calcular el triangulo rectangulo.";
		f=false;
	}
	
	if(f){
		//Si Sumx y sumy son 0, se hallará el punto que forma el angulo de 90 grados
		//Si sumx o sumy no son cero, se está hallando uno de los catetos
		punto2D *punto3 = new punto2D(punto1->x+sumx,punto2->y+sumy); 

		triangulo2D *triangulo = new triangulo2D(punto1,punto2,punto3);
		triangulo->mostrar(); //Mostrar puntos
		cout<<endl<<"Perimetro: "<<triangulo->perimetro()<<endl; //Es la suma de sus 3 lados.
		cout<<endl<<"Área: "<<triangulo->area()<<endl; // (OPUESTO*ADYACENTE)/2
		delete punto3;
		delete triangulo;
	}
	delete punto1;
	delete punto2;
	return 0;
}