# listas-enlasadas
#include <iostream>

using namespace std;

class nodo
{
    public:
        int dato;
        nodo* sig;
        nodo(int a);
        virtual ~nodo();
    protected:
    private:
};
nodo::nodo(int a)
{
    dato=a;
    sig=NULL;
}

nodo::~nodo()
{
}
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
lista::lista()
{
    primero=ultimo=NULL;
    //ctor
}

void lista::add(int el){
    if (!primero){
        primero=new nodo(el);
        ultimo=primero;
    }
    else{

        ultimo->sig=new nodo(el);
        ultimo=ultimo->sig;

    }
}

void lista::invertir()
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

void lista::sumar()
{
    int x;
    int suma=0;
    nodo* temp;
    temp=primero;
    while(temp!=ultimo->sig){
        x=temp->dato;
        suma=suma+x;
        temp=temp->sig;
    }
    cout<<suma<<endl;
}

void lista::ordenar()
{
    int cont=0;
    nodo* temp=primero;
    nodo* temp2;
    int numero;
    int numero2;
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

void lista::unir(lista h)
{
    ultimo->sig=h.primero;
    ultimo=ultimo->sig;
}

void lista::eliminar(int pos)
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

void lista::insertar(int pos, int val)
{
    nodo* temp;
    int posi=0;
    int tempo;
    int tempo2;
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

void lista:: print()
{
    nodo* temp;
    temp=primero;
    while(temp!=NULL){
        cout <<temp->dato<<endl;
        temp=temp->sig;
    }

}

lista::~lista()
{
}

int main()
{
  lista a;
    lista b;
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
