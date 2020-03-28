#include<iostream>
#include<conio.h>
using namespace std;

struct Nodo{
    float dato;
    Nodo *siguiente;
};

// PROTOTIPO DE FUNCIONES
void menu();
void insertarLista(Nodo *&, float);
void mostrarLista(Nodo *);
void buscarLista(Nodo *, int);
void eliminarNodo(Nodo *&,int);
void eliminarLista(Nodo *&, int &);

Nodo *lista = NULL;

// MAIN
int main(){

    menu();

    getch();
    return 0;
}

// FUNCIONES
void menu(){

    int dato;
    int respuesta;

    while (true) {
        cout<<"\t MENU\n";;
        cout<<"1. Insertar elementos a la lista"<<endl;
        cout<<"2. Mostrar los elementos de la lista"<<endl;
        cout<<"3. Buscar un elemento en la lista"<<endl;
        cout<<"4. Eliminar un nodo de la lista"<<endl;
        cout<<"5. Borrar lista"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>respuesta;

        switch (respuesta) {

        case 1:
            cout<<"\nIntroduce un numero: ";
            cin>>dato;

            insertarLista(lista,dato);
            cout<<"\n";
            system("cls");
            break;

        case 2:
            mostrarLista(lista);
            cout<<"\n";
            system("pause");
            system("cls");
            break;

        case 3:
            cout<<"\nIntroduce un numero: ";
            cin>>dato;

            buscarLista(lista,dato);
            cout<<"\n";
            system("pause");
            system("cls");
            break;

        case 4:
            cout<<"\nIntroduce un numero: ";
            cin>>dato;

            eliminarNodo(lista,dato);
            cout<<"Nodo eliminado"<<endl;
            system("pause");
            system("cls");
            break;

        case 5:
            while (lista != NULL) {
                eliminarLista(lista,dato);
            }
            cout<<"Lista borrada"<<endl;
            system("pause");
            system("cls");

        case 6:
            exit(1);

        }
    }
}

void insertarLista(Nodo *&lista,float n){
    Nodo *nuevo_nodo = new Nodo();                         // Creamos el nuevo nodo y lo rellenamos
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    Nodo *aux1 = lista;                                    // Creamos las variables auxiliares
    Nodo *aux2;

    while ((aux1 != NULL) && (aux1 -> dato < n)) {
        aux2 = aux1;
        aux1 = aux1 -> siguiente;
    }

    if(lista == aux1){                      // Lista vacia
        lista = nuevo_nodo;
    }
    else{
        aux2 -> siguiente = nuevo_nodo;
    }

    nuevo_nodo -> siguiente = aux1;
}

void mostrarLista(Nodo *lista){
    while(lista != NULL){                 // mientras no sea el final de la lista
        cout<<lista -> dato<<" -> ";      // mostramos el dato
        lista = lista -> siguiente;       // avanzamos una posicion mas en la lista
    }
}

void buscarLista(Nodo *lista, int n){
    bool flag;

    Nodo *actual = new Nodo();
    actual = lista;

    while((actual != NULL) && (actual -> dato <= n)){
        if(actual -> dato == n){
            flag = true;
        }
        actual = actual -> siguiente;
    }

    if (flag == true){
        cout<<"Elemento "<<n<<" encontrado en la lista"<<endl;
    }
    else{
        cout<<"Elemento "<<n<<" no encontrado en la lista"<<endl;
    }
}

void eliminarNodo(Nodo *&lista,int n){
    if (lista != NULL){
        Nodo *aux_borrar;
        Nodo *anterior = NULL;
        aux_borrar = lista;

        while ((aux_borrar != NULL) && (aux_borrar -> dato != n)) {         // Recorremos la lista
            anterior = aux_borrar;
            aux_borrar = aux_borrar -> siguiente;
        }

        if (aux_borrar == NULL){                            // Esto es si llegamos al final de la lista y no hemos encontrado el elemento
            cout<<"El elemento no ha sido encontrado";

        }
        else if (anterior == NULL){         // Esto sucede si el elemento a borrar es el primero
            lista = lista -> siguiente;
            delete aux_borrar;
        }
        else {                              // Esto es si queremos eliminar un numero que no es el primero
            anterior -> siguiente = aux_borrar -> siguiente;
            delete aux_borrar;
        }
    }

}

void eliminarLista(Nodo *&, int &n){
    Nodo *aux = lista;
    n = lista -> dato;

    lista = lista -> siguiente;
    delete aux;
}
