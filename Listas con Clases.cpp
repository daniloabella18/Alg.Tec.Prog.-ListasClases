/// Danilo Abella
/// Codeblocks 13.12
/// S.O : Win 8.0 64bits
/// 26/09/2014

# include <iostream>

using namespace std;

/// TDA ///
struct nodo
{   char info;
    nodo* sig;
};

/// Clase ///
class lista{
private:
    nodo* p;
public:
    lista();
    ~lista();
    void ingreso(char x);
    void elimina(char x);
    void mostrar();
};

/// Destructor ///
lista::lista()
{
     p= NULL;
}

/// Constructor ///
lista::~lista(){
nodo *q;
while (p)
{   q=p;
    p = p->sig;
    delete q;
}
}


/// Programa principal ///--------------------------------------------------------------------------------------///

int main()
{   lista L;
    char n;
    int j,h;
    do{
        cout <<"\nIngrese un caracter ( 0 para terminar): ";
        cin>> n;
        if(n!='0')
        {
            L.ingreso(n);
        }
       }while(n!='0');
L.mostrar();

cout<<"\tIngrese cantidad de caratcteres a eliminar: ";
cin>>j;
cout<<""<<endl;

for ( h=0; h < j ; h++ )
{
    cout<<"Ingrese elemento a eliminar: ";
    cin>>n;
    cout<<""<<endl;
    L.elimina(n);
}

L.mostrar();
return 0;
}

/// Funciones ///-----------------------------------------------------------------------------------------------------///

/// Ingreso Lista ///
void lista::ingreso( char n ){
nodo *q, *r;

q=new nodo;
q->info = n;
q->sig = p;
if ( !p || q->info <= p->info )
{
    p=q;
}
else
{
    r=p->sig;
    while ( r && r->info < q->info )
    {
        q->sig = r;
        r = r->sig;
    }
    q->sig->sig = q;
    q->sig = r;
}
}


/// Eliminar Lista ///

void lista::elimina( char n ){
nodo *r, *q;
if ( p == NULL ) /// if (!p)
{
    cout<<"\n\tLista Vacia"<<endl;
}
else
{   q = p;
    if ( p->info == n )
    {
        p = p->sig;
        delete q ;
    }
    else
    {
        do{
            r = q;
            q = q->sig;
           } while ( q && q->info != n );
        if ( q )
        {   r -> sig = q -> sig;
            delete q;
        }
        else
        {
            cout<<"\nEl caracter "<< n <<" No esta en la lista.\n"<<endl;
        }
    }
}
}


/// Mostrar ///

void lista::mostrar()
{   nodo *q;
    q=p;
    cout<<""<<endl;
    while(q)
    {   cout<<"\t"<< q->info ;
        q=q->sig;
    }
    cout<<"\n"<<endl;
}


