#include "tvectordir.h"

// Constructor por defecto
TVectorDir::TVectorDir(){
	direccion=NULL;
	dim=0;
}


// Constructor sobrecargado (A partir de una dimension)
TVectorDir::TVectorDir(int dimension){
	if (dimension<0) {direccion=NULL,dim=0;}
	else{
		dim=dimension;
		direccion=new TDir[dim];
		if (!direccion) cerr<<"ERROR: Fallo en la creacion del vector de direcciones"<<endl;
	}
}


// Constructor de Copia
TVectorDir::TVectorDir(TVectorDir &vector){
	int i=0;
	if (vector.dim==0) {direccion=NULL;dim=0;}
	else{
		dim=vector.dim;
		direccion=new TDir[dim];
		if (!direccion) cerr<<"ERROR: Fallo en la creacion del vector de direcciones"<<endl;
		else for(i;i<dim;i++) direccion[i]=vector.direccion[i];
	}
}


// Destructor
TVectorDir::~TVectorDir() {
	if (direccion!=NULL){
		delete[]direccion;
		direccion=NULL;
		dim=0;
	}
}


// Sobrecarga del Operador =  (asignacion)
TVectorDir&
TVectorDir::operator=(const TVectorDir &vector){
	int i=0;
	if (direccion!=NULL) (*this).~TVectorDir();
	if (vector.dim==0) {direccion=NULL;dim=0;}
	else{
		dim=vector.dim;
		direccion=new TDir[dim];
		if (!direccion) cerr<<"ERROR: Fallo en la creacion del vector de direcciones"<<endl;
		else for(i;i<dim;i++) direccion[i]=vector.direccion[i];
	}
return *this;
}


// Sobrecarga del Operador ==  (igualdad)
bool
TVectorDir::operator==(TVectorDir &vector){
	bool res=true;
	int i=0;
	if (dim==vector.dim){
		for(i;((i<vector.dim)&&(res==true));i++){
			if (vector.direccion[i]==direccion[i]);
			else res=false;
		}
	}
	else res=false;
return res;
}


// Sobrecarga operador[] (Devuelve un objeto TDir correspondiente a la posicion indicada)
TDir&
TVectorDir::operator[](int pos){
	if ((pos>=1)&&(pos<=dim)) return (direccion[pos-1]);
	else return dirVacia;
}


// funcion Longitud (Devuelve la longitud del vector de direcciones)
int
TVectorDir::Longitud(){
	return(dim);
}


// Sobrecarga operador<<
ostream& operator<<(ostream &o,const TVectorDir &vector){
	if (vector.dim>0){
		int i=1;
		if (vector.direccion!=NULL){
			for(i;i<=vector.dim;i++) o<<i<<" "<<vector.direccion[i-1]<<" ";
		}
	}
return o;
}
