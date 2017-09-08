#ifndef NODO_H
#define NODO_H

using namespace std;

template <class T>
class nodo
{
    public:
        T dato;
        nodo <T> *sig;
        nodo(){sig=NULL;}
        nodo(T d){dato=d;sig=NULL;}
};

#endif // NODO_H
