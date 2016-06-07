# listas-enlasadas
#include <iostream>

using namespace std;
template<<class T>>
class nodo
{
    public:
        T dato;
        nodo* sig;
        nodo(T);
        virtual ~nodo();
    protected:
    private:
};
template<<class T>>
nodo::nodo(T a)
{
    dato=a;
    sig=NULL;
}
template<<class T>>
nodo::~nodo()
{
}
template<<class T>>
class lista
{
    public:
        nodo* primero;
        nodo* ultimo;
        lista();
        void add(int el);
        void invertir();
        void sumar();
        void insertar(int pos, int val);
        void eliminar(int pos);
        void ordenar();
        void unir(lista a);
        void print();
        virtual ~lista();
    protected:
    private:
};
template<<class T>>
lista::lista()
{
    primero=ultimo=NULL;
    //ctor
}
template<<class T>>
void lista<<T>>::add(T el){
    if (!primero){
        primero=new nodo(el);
        ultimo=primero;
    }
    else{

        ultimo->sig=new nodo(el);
        ultimo=ultimo->sig;

    }
}
template<<class T>>
void lista<<T>>::invertir()
{
    nodo* temp;
    nodo* temp3;
    temp3=primero;
    temp=primero;
    while (temp) {
        nodo* temp2;
        temp2=temp;
        temp=temp->sig;
        if (temp==primero){
            temp2->sig=NULL;
        }
        else{
            temp2->sig=primero;
            primero=temp2;

        }
    }
    ultimo=temp3;
}
template<<class T>>
void lista<<T>>::sumar()
{
    T x;
    T suma=0;
    nodo* temp;
    temp=primero;
    while(temp!=ultimo->sig){
        x=temp->dato;
        suma=suma+x;
        temp=temp->sig;
    }
    cout<<suma<<endl;
}
template<<class T>>
void lista<<T>>::ordenar()
{
    int cont=0;
    nodo* temp=primero;
    nodo* temp2;
    T numero;
    T numero2;
    while(temp!=ultimo->sig){
        cont++;
        temp=temp->sig;
    }
    temp=primero;
    for(int i=0;i<cont-1;i++){
        for(int j=0;j<cont-1;j++){
            numero=temp->dato;
            temp2=temp->sig;
            numero2=temp2->dato;
            if (numero2<numero){
                temp->dato=numero2;
                temp2->dato=numero;
            }
            temp=temp->sig;
        }
        temp=primero;
    }

}
template<<class T>>
void lista<<T>>::unir(lista h)
{
    ultimo->sig=h.primero;
    ultimo=ultimo->sig;
}
template<<class T>>
void lista<<T>>::eliminar(int pos)
{
    nodo* temp=primero;
    nodo* temp2;
    int posi=1;
    if (pos>1){
        while(posi<=pos+1)
        {
            if (posi==pos-1){
                temp2=temp;
                posi++;
            }
            else if (temp==ultimo){
                temp2->sig=NULL;
                ultimo=temp2;
                posi=posi+2;
            }
            else if (posi==pos+1){
                temp2->sig=temp;
                posi++;
            }
            else{
                posi++;
            }
            temp=temp->sig;

        }
    }
    if (pos==1){
        temp=primero;
        temp2=temp->sig;
        primero=temp2;
    }
}
template<<class T>>
void lista<<T>>::insertar(int pos, T val)
{
    nodo* temp;
    int posi=0;
    T tempo;
    T tempo2;
    ultimo->sig=new nodo(val);
    ultimo=ultimo->sig;
    temp=primero;
    while(temp!=ultimo->sig)
    {
        if (posi==pos-1){
            tempo=temp->dato;
            temp->dato=val;
            posi++;
        }
        if (posi>pos){
            tempo2=temp->dato;
            temp->dato=tempo;
            tempo=tempo2;
            posi++;
        }
        else
            posi++;
        temp=temp->sig;
    }

}
template<<class T>>
void lista<<T>>:: print()
{
    nodo* temp;
    temp=primero;
    while(temp!=NULL){
        cout <<temp->dato<<endl;
        temp=temp->sig;
    }

}
template<<class T>>
lista<<T>>::~lista()
{
}

int main()
{
  lista<int> a;
    lista<int> b;
    a.add(8);
    a.add(6);
    a.add(7);
    a.add(4);
    cout<<"lista uno: "<<endl;
    a.print();
    b.add(1);
    b.add(2);
    b.add(3);
    cout<<"lista dos: "<<endl;
    b.print();
    a.unir(b);
    cout<<"listas unidas: "<<endl;
    a.print();
  return 0;
}
