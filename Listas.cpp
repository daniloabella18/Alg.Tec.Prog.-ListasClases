# include <iostream>

/// Danilo Abella
/// Codeblocks 13.12
/// LCC USACH
/// 26/09/2014
/// S.O: Win 8.0 64bits

using namespace std;

///TDA
struct lista
{   char caracter;
    lista* prox;
};

///Funciones

lista *IngresoLista(char n, lista *p);
lista *EliminaLista(char n, lista *p);
void mostrar(lista *p);


/// Funcion Principal ///---------------------------------------------------------------------------------------------------///

int main(){
lista *p;
char n;
short h,j;
p = NULL;

cout<<"\n\t\tIngrese caracteres, presione 0 para terminar.\n";

do{ cout<<"\n\tIngrese un caracter: ";
    cin>>n;
    if(n!='0')
    {
        p=IngresoLista(n,p);
    }
   }while(n!='0');

mostrar(p);
cout<<"\tIngrese cantidad de caratcteres a eliminar:";
cin>>j;
for ( h=0; h < j ; h++ )
{
    cout<<"\n\tIngrese un caracter que desee eliminar: ";
    cin>>n;
    p = EliminaLista(n,p);
}

mostrar(p);
while (p)
    p = EliminaLista(p->caracter,p);
return 0;
}



/// Funciones ///-------------------------------------------------------------------------------------------------------------------///

/// Ingreso Lista ///

lista *IngresoLista(char n, lista *p){
lista *q,*r;
q=new lista;
if (!q)
{   cout <<"NO HAY Espacio de Memoria suficiente";
    return p;
}
q->caracter=n;
q->prox=p;
if((!p)||(q->caracter <= p->caracter))
{
   p=q;
}
else
{   r=p->prox;
    while(r && r->caracter < q->caracter )
    {   q->prox=r;
        r=r->prox;
    }
    q-> prox -> prox=q;
    q-> prox=r;
}
return p;
}

/// Mostrar ///

void mostrar(lista *p)
{   lista *q;
    q=p;
    cout<<""<<endl;
    while(q)
    {   cout<<"\t"<< q->caracter;
        q=q->prox;
    }
    cout<<"\n"<<endl;
}

/// Eliminar Lista ///

lista *EliminaLista(char n, lista *p){
lista *r,*q;
if(p == NULL)
cout<<"\n\t Lista Vacía.";
else
{   q=p;
    if(p->caracter == n)
    { p=p->prox;
    delete q;
    }
    else
    {   do{ r=q;
            q=q->prox;
        }while( q && q->caracter!= n);
        if(q)
        {   r->prox=q->prox;
            delete q;
        }
        else
            cout<<"\n\tEl caracter "<< n <<" no se encuentra en la Lista.";
    }
}
return p;
}



