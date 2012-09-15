#include "tlistadir.h"

// Constructor por defecto
TListaDir::TListaDir(){
	primera=NULL;
}


// Constructor de Copia
TListaDir::TListaDir(TListaDir &lista){
	if(lista.primera==NULL) primera=NULL;
	else{
		TNodoDir *nodo1=lista.primera;
		TNodoDir *nodo2, *nodo3;
		nodo2=new TNodoDir;
		nodo2->dir=nodo1->dir;
		primera=nodo2;
		while(nodo1->sig!=NULL){
			nodo3=new TNodoDir;
			nodo2->sig=nodo3;
			nodo1=nodo1->sig;
			nodo3->dir=nodo1->dir;
			nodo2=nodo3;
		}
	}
}


// Destructor
TListaDir::~TListaDir(){
	if(primera!=NULL){
		TNodoDir *nodo1,*nodo2;
		nodo1=primera;
		if(nodo1->sig!=NULL){
			nodo2=nodo1->sig;
			delete nodo1;	
			while(nodo2->sig!=NULL){
				nodo1=nodo2;
				nodo2=nodo2->sig;
				delete nodo1;
			}
			delete nodo2;
		}
		else delete nodo1;
		primera=NULL;
	}
}


// Sobrecarga del Operador =  (asignacion)
TListaDir&
TListaDir::operator=(const TListaDir &lista){
	if(primera!=NULL) (*this).~TListaDir();
	if(lista.primera!=NULL){
		TNodoDir *nodo1=lista.primera;
		TNodoDir *nodo2, *nodo3;
		nodo2=new TNodoDir;
		nodo2->dir=nodo1->dir;
		primera=nodo2;
		while(nodo1->sig!=NULL){
			nodo3=new TNodoDir;
			nodo2->sig=nodo3;
			nodo1=nodo1->sig;
			nodo3->dir=nodo1->dir;
			nodo2=nodo3;
		}
	}
return *this;
}


// Sobrecarga del Operador ==  (igualdad)
bool
TListaDir::operator==(TListaDir &lista){
	bool res=false;
	if(Longitud()==lista.Longitud()){
		if(Longitud()==0) res=true;
		else{
			TNodoDir *nodo1,*nodo2;
			nodo1=primera;
			nodo2=lista.primera;
			while((nodo2->sig!=NULL)&&(nodo1->dir==nodo2->dir)){
				nodo1=nodo1->sig;
				nodo2=nodo2->sig;
			}
			if(nodo1->sig==NULL) res=true;
		}
	}
return res;
}


// Sobrecarga operador+ (Crea una nueva lista que contiene los elementos de las dos)
TListaDir
TListaDir::operator+(TListaDir &lista){
	TListaDir listaFinal(*this);
	TNodoDir *nodo1;
	nodo1=lista.primera;
	while(nodo1!=NULL){
		listaFinal.Insertar(nodo1->dir);
		nodo1=nodo1->sig;
	}
return listaFinal;
}


// funcion EsVacia
bool
TListaDir::EsVacia()const{
	bool res=false;
	if(primera==NULL) res=true;
return res;
}


// funcion Insertar
bool
TListaDir::Insertar(TDir &dir){
	bool res;
	if(Buscar(dir)) res=false;
	else{
		res=true;
		TNodoDir *nodo1,*nodonuevo;
		nodo1=primera;
		nodonuevo=new TNodoDir;
		nodonuevo->dir=dir;
		if(!EsVacia()){
			while((dir>nodo1->dir)&&(nodo1->sig!=NULL)&&(dir>nodo1->sig->dir))
					nodo1=nodo1->sig;
			if (dir<nodo1->dir){
				nodonuevo->sig=nodo1;
				primera=nodonuevo;
			}
			else{
				nodonuevo->sig=nodo1->sig;
				nodo1->sig=nodonuevo;
			}
		}
		else{
			primera=nodonuevo;
		}
	}
return res;
}


// funcion Borrar
bool
TListaDir::Borrar(TDir &dir){
	bool res=false;
	if(Buscar(dir)){
		res=true;
		TNodoDir *nodo1,*aux;
		nodo1=primera;
		if(dir==nodo1->dir){
			primera=nodo1->sig;
			delete nodo1;
		}	
		else{
			aux=nodo1->sig;
			while((nodo1->sig!=NULL)&&(aux->dir!=dir)){
			 	nodo1=nodo1->sig;
				aux=aux->sig;
			} 
			if(aux->sig!=NULL){
				nodo1->sig=aux->sig;
			}
			else
				nodo1->sig=NULL;
		delete aux;
		}
		
	}
return res;
}


// funcion Buscar
bool
TListaDir::Buscar(TDir &dir){
	bool res=false;
	if(!EsVacia()){
		TNodoDir *nodo1;
		nodo1=primera;
		while((nodo1->sig!=NULL)&&(nodo1->dir!=dir)) nodo1=nodo1->sig;
		if(nodo1->dir==dir) res=true;
	}
return res;
}


// funcion Longitud
int
TListaDir::Longitud()const{
	int longitud=0;
	if(!EsVacia()){
		TNodoDir *nodo1;
		nodo1=primera;
		while(nodo1!=NULL){
			nodo1=nodo1->sig;
			longitud++;
		}
	}
return longitud;
}


// Sobrecarga operador<<
ostream& operator<<(ostream &o,const TListaDir &lista){
	if (lista.Longitud()==0) o<<"{}";
	else{
		if(lista.Longitud()==1) o<<"{"<<lista.Primera()->GetDir()<<"}";
		else{
			TNodoDir *nodo1;
			nodo1=lista.Primera();
			o<<"{";
			while(nodo1->GetSig()!=NULL){
				o<<nodo1->GetDir()<<" ";
				nodo1=nodo1->GetSig();
			}
			o<<nodo1->GetDir()<<"}";
		}
	}
return o;
}

