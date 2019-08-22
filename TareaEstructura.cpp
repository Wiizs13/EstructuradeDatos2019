/*
Este programa fue hecho por: Wilbert Alexander Arana Diaz
Carnet: AD18005
Carrera: Ingenieria de Sistemas Informaticos.
Materia: Estructura de Datos
*/
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class Nodo{ //se crea una clase llamada Nodo
     public:
         int nro;
         Nodo *izq, *der;
};

typedef Nodo *ABB;
int cont = 0;
int sum = 0;

class ArbolBinarioBusqueda {

    public:
        ABB crearNodo(int x)
        {
             ABB nuevoNodo = new Nodo();
             nuevoNodo->nro = x;
             nuevoNodo->izq = NULL;
             nuevoNodo->der = NULL;
			cont++;
			sum = sum + x;
             return nuevoNodo;
        }
        void insertar(ABB &arbol, int x)
        {
             if(arbol==NULL)
             {
                   arbol = crearNodo(x);
             }
             else if(x < arbol->nro)
                  insertar(arbol->izq, x);
             else if(x > arbol->nro)
                  insertar(arbol->der, x);
        }
	
    	 int alturaAB(ABB arbol)
		{
    	int AltIzq, AltDer;

	    if(arbol==NULL)
        return -1;
 	   else
   	 {
        AltIzq = alturaAB(arbol->izq);
        AltDer = alturaAB(arbol->der);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}

	   
		
        void preOrden(ABB arbol)
        {
             if(arbol!=NULL)
             {
                  cout << arbol->nro <<" ";
                  preOrden(arbol->izq);
                  preOrden(arbol->der);
             }
        }

        void enOrden(ABB arbol)
        {
             if(arbol!=NULL)
             {
                  enOrden(arbol->izq);
                  cout << arbol->nro << " ";
                  enOrden(arbol->der);
             }
        }

        void postOrden(ABB arbol)
        {
             if(arbol!=NULL)
             {
                  postOrden(arbol->izq);
                  postOrden(arbol->der);
                  cout << arbol->nro << " ";
             }
        }
        

        void verArbol(ABB arbol, int n)
        {
             if(arbol==NULL)
                  return;
             verArbol(arbol->der, n+1);

             for(int i=0; i<n; i++)
                 cout<<"   ";

             cout<< arbol->nro <<endl;

             verArbol(arbol->izq, n+1);
        }
        

};

void menu (){
	system("cls");
		cout << "\n\t\t  .. ARBOL BINARIO DE BUSQUEDA .. "<<endl;
		cout<<"\t\t\t      NODOS: "<<cont;
		cout<<"\n\n\n\t[1] Insertar Nodos"<<endl; 
		cout<<"\t[2] Recorridos del Arbol"<<endl;
		cout<<"\t[3] Mostrar Arbol"<<endl;
		cout<<"\t[4] Altura del Arbol"<<endl;
		cout<<"\t[5] Sumar los Nodos del Arbol"<<endl;
		cout<<"\t[6] Salir\n\n"<<endl;
		cout<<"\t Digite una Opcion: ";
}
void menu2()
{   
     cout << endl;
     cout << "\t [1] En Orden     \n";
     cout << "\t [2] Pre Orden    \n";
     cout << "\t [3] Post Orden   \n";
     cout << "\t [4] Todos los Recorridos   \n";
     cout << "\n\t     Opcion :  ";
     
}

void swit(){
	ArbolBinarioBusqueda *avl = new ArbolBinarioBusqueda();
		  
    ABB arbol = NULL; 

    int x; 
    int op, op2; 
    int n; 
	do{
		menu(); cin>> op;

	switch(op){
	
	case 1:
	cout << " \tCuantos Nodos Desea Agregar? "<< ": ";
	cin>> n;
    for(int i=0; i<n; i++)
    {
        cout << " \tNumero del nodo " << i+1 << ": ";
        cin >> x;
        avl->insertar( arbol, x);
    }
    break;
	case 2: 
	menu2();  cin>> op2;

                    if(arbol!=NULL)
                    {
                         switch(op2)
                         {
                             case 1:
                                  cout << "\n\n\t En orden   :  ";   avl->enOrden(arbol);
									 break;
                             case 2:
                                   cout << "\n\n\t Pre Orden  :  ";   avl->preOrden(arbol);
								    break;
                             case 3:
                                  cout << "\n\n \tPost Orden :  ";   avl->postOrden(arbol);
                                  break;
                            case 4:
								    cout << "\n\n\t En orden   :  ";   avl->enOrden(arbol);
  								    cout << "\n\n\t Pre Orden  :  ";   avl->preOrden(arbol);
    								cout << "\n\n\t Post Orden :  ";   avl->postOrden(arbol);
                         	      break;
                         }
                    }
                    else
                        cout << "\n\t Arbol vacio..!";
                        getch();
	break;
	case 3:
    cout << "\n \tMostrando Arbol \n\n";
    avl->verArbol( arbol, 0);
    getch();
	break;
	case 4:
			int h;
			h= avl->alturaAB(arbol);
                    cout << "\tLa altura del Arbol es : "<< h << endl;
                    getch();
	break;
	case 5:
				cout << "\tLa Suma de los Nodos Es: "<< sum << endl;	
				 getch();
	break;
	
	case 6:
		exit(0);
	break;
	}
}while(op!=6);
}




//Inicio de Main

int main()
{
	
	swit(); //llama a la funcion swit
	
     getch(); //detiene el programa
    return 0;
}
