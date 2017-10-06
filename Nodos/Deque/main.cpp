/**
 * Naomi Macias Honti a01282098
 * 3 de octubre 2017
 * Tiempo no estimado.
 * Utiliza la clase nodos y Deque, donde los nodos tiene un apuntador al nodo anterior y siguiente. La clase deque, crea una lista de nodos y hace varias funciones.
 */
#include <iostream>

using namespace std;

class Nodo
{	public:
    Nodo *pSig, *pAnt;
    int iInfo;
    Nodo( ) { pSig = NULL; pAnt=NULL; }
    Nodo (int iDato) { iInfo = iDato;  pSig = NULL; pAnt=NULL; }
    Nodo (int iDato, Nodo *pSiguiente, Nodo *pAnterior)
    { iInfo = iDato; pSig = pSiguiente;  pAnt=pAnterior;}
};
class Deque
{
friend ostream& operator << (ostream & os, const Deque &D)
    {
        Nodo *pP = D.pInicio;
        while (pP != NULL)
        {
            os << pP->iInfo << " ";
            pP = pP->pSig;
        }
        os << endl;
        return os;
    }
 private:
    Nodo *pInicio, *pFinal;
public:
    //Inicializando la lista como lista vacía
    Deque() { pInicio = NULL; pFinal=NULL; }
    //Copy constructor
    Deque (const Deque &D)
    {
        pInicio=pFinal=NULL;
        Nodo *pP;
        pP= D.pInicio;
        while (pP!= NULL)
        {
            push_back(pP->iInfo);
            pP=pP->pSig;
        }
    }
    //Sobrecarga del =
    Deque& operator = (const Deque& D)
    {
        if (this != &D)
        {
            //Borrar todos los nodos del this (destructor)
            while ( pInicio != NULL)
                pop_back();
            //Copiar la fila (copy constructor)
            Nodo *pAnterior, *pNuevo;
            Nodo *pP = D.pInicio;
            pInicio = NULL;
            if ( D.pInicio != NULL)
            {   //Crear el primer nodo del this
                pAnterior = new Nodo(pP->iInfo);
                pP = pP->pSig;
                pInicio = pAnterior;
                //Crear los demás nodos del this
                while ( pP != NULL )
                {   //Crea el nodo
                    pNuevo = new Nodo(pP->iInfo);
                    //Enlaza el nuevo con los anteriores
                    pAnterior->pSig = pNuevo;
                    pNuevo->pAnt=pAnterior;
                    //Avanza para crear los siguientes
                    pP = pP->pSig;
                    pAnterior = pAnterior->pSig;
                }
            }
        }
        return *this;
    }

    //Borra todos los nodos que queden en la lista
    ~Deque()
    {
        while (!pInicio!=NULL)
            pop_back();
    }

    //La lista está vacía cuando pInicio es NULL
    bool empty() { return (pInicio == NULL); }

    //Agregar un nodo al inicio de la lista
    void push_front(int iValor)
    {
        //Crear un nodo
        Nodo *pNuevo = new Nodo(iValor);// pInicio);
        if (pInicio!=NULL)
        {
           pNuevo->pSig = pInicio;
           pInicio->pAnt=pNuevo;
           pInicio=pNuevo;
        }
        else
            pInicio=pFinal=pNuevo;

    }
    // push back
    void push_back(int iValor)
    {
        Nodo *pNuevo=new Nodo(iValor);
        if (pFinal !=NULL)
        {
          pFinal->pSig=pNuevo;
          pNuevo->pAnt=pFinal;
          pFinal=pNuevo;
        }
        else
            pInicio=pFinal=pNuevo;
    }

    //Quita el nodo que está al final pop back
    void pop_back()
    {
        Nodo *pP = pFinal;
        pFinal=pFinal->pAnt;
        if (pFinal ==NULL)
            pInicio=NULL;
        delete pP;
    }
    //Borrar al frente de la lista
    //Precondición: Que la lista no esté vacia
    void pop_front()
    {
        Nodo *pP;
        pP=pInicio;
        pInicio=pInicio->pSig;
        if (pInicio == NULL)
            pFinal=NULL;
        delete(pP);
    }

    //Regresa el contenido del nodo apuntado por inicio
    int top_front() { return pInicio->iInfo; }


    //Regresa el contenido del nodo apuntado por Final
    int top_back() { return pFinal->iInfo; }

    ///Método insert que recibe el info y la posición a insertar
    int insertar(int dato, int posicion)
    {
        if(posicion<=cantidad() && posicion>0){
            int cont=1;
            Nodo *p;
            p=pInicio;
            while(cont!=posicion){
                p=p->pSig;
                cont++;
            }
            Nodo *q= new Nodo(dato);
            if(p->pSig!=NULL){
                q->pSig=p->pSig;
                q->pAnt=p;
                p->pSig=q;
                p=q->pSig;
                p->pAnt=q;
            }else{
                q->pAnt=p;
                p->pSig=q;
                q->pSig=NULL;
            }
        }else
            cout << "Posicion fuera de rango." << endl;
    }


    //Método que regresa la cantidad de nodos
    int cantidad()
    {
        Nodo *p;
        p=pInicio;
        int cont=0;
        while(p!=NULL){
            cont++;
            p=p->pSig;
        }
        return cont;
    }

    ///Metodo que encuentra y regresa el elemento mas chico
    int menor()
    {
        if(pInicio!=NULL){
            Nodo *p;
            p=pInicio;
            int num=pInicio->iInfo;
            while(p->pSig!=NULL){
                p=p->pSig;
                if(num>p->iInfo){
                    num=p->iInfo;
                }
            }
            return num;
        }
        return -1;
    }

    ///Metodo que elimina duplicados
    void limpiar()
    {
        if(pInicio!=NULL){
            Nodo *p;
            p=pInicio;
            Nodo *q;
            int cont,cont2;
            while(p!=NULL){
                q=p->pSig;
                cont=p->iInfo;
                while(q!=NULL){
                    cont2=q->iInfo;
                    if(cont==cont2){
                        Nodo *n;
                        if(q->pSig!=NULL){
                            n=q->pSig;
                            n->pAnt=q->pAnt;
                            n=q->pAnt;
                            n->pSig=q->pSig;
                        }else{
                            n=q->pAnt;
                            n->pSig=NULL;
                        }
                        delete q;
                        q=NULL;
                    }else
                        q=q->pSig;
                }
                p=p->pSig;
            }
        }
    }
};
//////////////////////
int main()
{
    Deque D;
    D.push_back(5);
    D.push_back(3);
    D.push_front(1);
    D.push_back(1);
    D.insertar(2,1);
    cout<<D<<endl;
    cout<<"elementos: "<<D.cantidad()<<endl;
    cout<<"\neliminando duplicados"<<endl;
    D.limpiar();
    cout<<D<<endl;
    cout<<"elementos: "<<D.cantidad()<<endl;
    cout << D.menor()<<endl;
    D.insertar(8,4);
    cout<<D<<endl;
    D.insertar(9,9);
    cout<<D<<endl;
    return 0;
}
