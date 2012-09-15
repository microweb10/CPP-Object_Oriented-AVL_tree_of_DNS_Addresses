
#include "tavldir.h"


// METODOS DE LA CLASE TAVLDIR


// Constructor por defecto
TAVLDir::TAVLDir(){
	nodo=NULL;
}


// Constructor de Copia
TAVLDir::TAVLDir(TAVLDir &a){
    if(!a.EsVacio()){  // si el arbol no es vacio
	TNodoAVLDir *aux=new TNodoAVLDir;
	aux->fe=a.nodo->fe;
	aux->item=a.nodo->item;
	nodo=aux;
	nodo->iz=a.nodo->iz;
	nodo->de=a.nodo->de;
    }
}


// Destructor
TAVLDir::~TAVLDir(){
	if(nodo!=NULL){
		delete nodo;
		nodo=NULL;
	}
}


// funcion EsVacio
bool
TAVLDir::EsVacio(){
	bool res=false;
	if(nodo==NULL) res=true;
return res;
}


// funcion  Insertar
bool
TAVLDir::Insertar(TDir &d){
    TAVLDir a,c,e,g;
    TNodoAVLDir nodoaux;
    TDir aux;
    if(EsVacio()){                      // Si el nodo esta vacio se coloca el elemento
        nodo=new TNodoAVLDir;
        nodo->item=d;
        return true;
    }
    else{
        if(d==nodo->item) return false; // si el elemento ya existe no hace nada
        else{                           // si no existe...
            if(d>nodo->item){           // vemos si va a la derecha (es mayor)
                if (nodo->de.Insertar(d)){     //llamada recursiva
                    nodo->fe=nodo->de.Altura()-nodo->iz.Altura();  // se actualiza el factor de equilibrio
                    if(nodo->fe==2){   // si el fe es mayor que uno hay que hacer alguna rotacion
                        if(nodo->de.nodo->fe==1){  //rotacion DD
                            a=nodo->iz;
                            c=nodo->de.nodo->iz;
                            e=nodo->de.nodo->de;
                            aux=nodo->item;
                            nodo->item=nodo->de.nodo->item;
			    if(nodo->iz.EsVacio())
                                nodo->iz.Insertar(aux);
			    else
                            	nodo->iz.nodo->item=aux;
                            nodo->de=e;
                            nodo->iz.nodo->iz=a;
                            nodo->iz.nodo->de=c;
			    nodo->iz.nodo->fe=nodo->iz.nodo->de.Altura()-nodo->iz.nodo->iz.Altura();
			    nodo->fe=nodo->de.Altura()-nodo->iz.Altura();
                        }
                        if(nodo->de.nodo->fe==-1){  //rotacion DI
                            a=nodo->iz;
                            c=nodo->de.nodo->iz.nodo->iz;
                            e=nodo->de.nodo->iz.nodo->de;
                            g=nodo->de.nodo->de;
                            aux=nodo->item;
                            nodo->item=nodo->de.nodo->iz.nodo->item;
                            if(nodo->iz.EsVacio())
                                nodo->iz.Insertar(aux);
			    else
                            	nodo->iz.nodo->item=aux;
                            nodo->iz.nodo->iz=a;
                            nodo->iz.nodo->de=c;
                            nodo->de.nodo->iz=e;
                            nodo->de.nodo->de=g;
			    nodo->iz.nodo->fe=nodo->iz.nodo->de.Altura()-nodo->iz.nodo->iz.Altura();
			    nodo->de.nodo->fe=nodo->de.nodo->de.Altura()-nodo->de.nodo->iz.Altura();
			    nodo->fe=nodo->de.Altura()-nodo->iz.Altura();
                        }
                    }
                return true;
                }
                else return false;
			}
            else{                       // vemos si va a la izquierda (es menor)
                if (nodo->iz.Insertar(d)){     //llamada recursiva
                    nodo->fe=nodo->de.Altura()-nodo->iz.Altura();  // se actualiza el factor de equilibrio
                    if (nodo->fe==-2){ // hay que hacer alguna rotacion
                        if(nodo->iz.nodo->fe==-1){  //rotacion II
                            a=nodo->iz.nodo->iz;
                            c=nodo->iz.nodo->de;
                            e=nodo->de;
                            aux=nodo->item;
                            nodo->item=nodo->iz.nodo->item;
			    if(nodo->de.EsVacio())
                                nodo->de.Insertar(aux);
			    else
                            	nodo->de.nodo->item=aux;
                            nodo->iz=a;
                            nodo->de.nodo->iz=c;
                            nodo->de.nodo->de=e;
			    nodo->de.nodo->fe=nodo->de.nodo->de.Altura()-nodo->de.nodo->iz.Altura();
			    nodo->fe=nodo->de.Altura()-nodo->iz.Altura();
                        }
                        if(nodo->iz.nodo->fe==1){  //rotacion ID
                            a=nodo->iz.nodo->iz;
                            c=nodo->iz.nodo->de.nodo->iz;
                            e=nodo->iz.nodo->de.nodo->de;
                            g=nodo->de;
                            aux=nodo->item;
                            nodo->item=nodo->iz.nodo->de.nodo->item;
			    if(nodo->de.EsVacio())
                                nodo->de.Insertar(aux);
			    else
                            	nodo->de.nodo->item=aux;
                            nodo->iz.nodo->iz=a;
                            nodo->iz.nodo->de=c;
                            nodo->de.nodo->iz=e;
                            nodo->de.nodo->de=g;
			    nodo->iz.nodo->fe=nodo->iz.nodo->de.Altura()-nodo->iz.nodo->iz.Altura();
			    nodo->de.nodo->fe=nodo->de.nodo->de.Altura()-nodo->de.nodo->iz.Altura();
			    nodo->fe=nodo->de.Altura()-nodo->iz.Altura();
                        }
                    }
                return true;
                }
                else return false;
            }
        }
    }
}


// funcion  Buscar
bool
TAVLDir::Buscar(TDir &d){
	if(EsVacio()) return false;
	else{
		if(d==nodo->item) return true;
		else{
			if(d>nodo->item) return(nodo->de.Buscar(d));
			else return(nodo->iz.Buscar(d));
		}
	}
}


// funcion  Altura
int
TAVLDir::Altura(){
	int alturade, alturaiz;
	if (EsVacio()) return 0;
	else{
	    alturade=1+nodo->de.Altura();
	    alturaiz=1+nodo->iz.Altura();
	    if(alturade>alturaiz) return alturade;
	    else return alturaiz;
    }
}


// funcion  Nodos
int
TAVLDir::Nodos(){
	int nodos=0;
	if(EsVacio()) return nodos;
	else{
		nodos=1+nodo->iz.Nodos()+nodo->de.Nodos();
	}
return nodos;
}


// funcion  NodosHoja
int
TAVLDir::NodosHoja(){
	if(EsVacio()) return 0;
	else{
		if((nodo->iz.EsVacio())&&(nodo->de.EsVacio())) return 1;
		else {
			if(nodo->iz.EsVacio()) return (nodo->de.NodosHoja());
			else{
				if(nodo->de.EsVacio()) return (nodo->iz.NodosHoja());
				else
					return (nodo->iz.NodosHoja()+nodo->de.NodosHoja());
			}
		}
	}
}


// funcion  Inorden
TVectorDir
TAVLDir::Inorden(){
	int posicion=1;
	TVectorDir inorden(Nodos());
	InordenAux(inorden,posicion);
return inorden;
}

// funcion PreordenAux (DEVUELVE EL RECORRIDO PREORDEN
void
TAVLDir::InordenAux(TVectorDir &vector,int &posicion){
	if(!EsVacio()){
		nodo->iz.InordenAux(vector,posicion);
		vector[posicion++]=nodo->item;
		nodo->de.InordenAux(vector,posicion);
	}
}


// funcion  Preorden
TVectorDir const
TAVLDir::Preorden(){
	int posicion=1;
	TVectorDir preorden(Nodos());
	PreordenAux(preorden,posicion);
return preorden;
}

// funcion PreordenAux (DEVUELVE EL RECORRIDO PREORDEN
void
TAVLDir::PreordenAux(TVectorDir &vector,int &posicion){
	if(!EsVacio()){
		vector[posicion++]=nodo->item;
		nodo->iz.PreordenAux(vector,posicion);
		nodo->de.PreordenAux(vector,posicion);
	}
}


// funcion  Postorden
TVectorDir
TAVLDir::Postorden(){
	int posicion=1;
	TVectorDir postorden(Nodos());
	PostordenAux(postorden,posicion);
return postorden;
}

// funcion PreordenAux (DEVUELVE EL RECORRIDO PREORDEN
void
TAVLDir::PostordenAux(TVectorDir &vector,int &posicion){
	if(!EsVacio()){
		nodo->iz.PostordenAux(vector,posicion);
		nodo->de.PostordenAux(vector,posicion);
		vector[posicion++]=nodo->item;
	}
}


// Sobrecarga del Operador =  (asignacion)
TAVLDir&
TAVLDir::operator=(TAVLDir &a){
    if(!a.EsVacio()){  // si el arbol no es vacio
         if(!EsVacio()){
	     delete nodo;
	     nodo=NULL;
	 }
	 TNodoAVLDir *aux=new TNodoAVLDir;
	 aux->fe=a.nodo->fe;
	 aux->item=a.nodo->item;
	 nodo=aux;
	 nodo->iz=a.nodo->iz;
	 nodo->de=a.nodo->de;
    }
    else{
        if(!EsVacio()){
	    delete nodo;
	    nodo=NULL;
	}
    }
return *this;
}


// Sobrecarga del Operador ==  (igualdad)
bool
TAVLDir::operator==(TAVLDir &a){
	if((nodo==NULL)&&(a.nodo==NULL)) return true;
	else{
		if((nodo->item==a.nodo->item)&&(nodo->fe==a.nodo->fe)){
			if(nodo->iz==a.nodo->iz)
				return nodo->de==a.nodo->de;
			else return false;
		}
		else return false;
	}
}



// METODOS DE LA CLASE TNODOAVLDIR


// Constructor por defecto
TNodoAVLDir::TNodoAVLDir(){
	fe=0;
}


// Constructor de Copia
TNodoAVLDir::TNodoAVLDir(TNodoAVLDir &nodo){
	fe=nodo.fe;
	item=nodo.item;
	iz=nodo.iz;
	de=nodo.de;
}


// Destructor por defecto
TNodoAVLDir::~TNodoAVLDir(){
	fe=0;
	item.~TDir();
	if(!iz.EsVacio())
		iz.~TAVLDir();
	if(!de.EsVacio())
		de.~TAVLDir();
}


// Sobrecarga del Operador =  (asignacion)
TNodoAVLDir&
TNodoAVLDir::operator=(TNodoAVLDir &nodo){
	fe=nodo.fe;
	item=nodo.item;
	iz=nodo.iz;
	de=nodo.de;
return *this;
}

