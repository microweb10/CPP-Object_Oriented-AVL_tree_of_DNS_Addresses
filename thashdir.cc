#include"thashdir.h"


// METODOS DE LA CLASE THASHDIR


// Constructor por defecto
THashDir::THashDir(){
	tamanyo=0;
	tabla=NULL;
}


// Constructor a partir de un tamanyo
THashDir::THashDir(int a){
	if(a>0){
		tamanyo=a;
		tabla=new TListaDir[a];
	}
	else{
		tamanyo=0;
		tabla=NULL;
	}
}


// Constructor de Copia
THashDir::THashDir(THashDir &a){
	int i;
	tamanyo=a.tamanyo;
    	if(tamanyo!=0){
    		tabla=new TListaDir[tamanyo];
		for(i=0;i<tamanyo;i++)
		tabla[i]=a.tabla[i];
    	}
}


// Destructor
THashDir::~THashDir(){
	int i;
	if(tamanyo!=0){
		for(i=0;i<tamanyo;i++){
			tabla[i].~TListaDir();
		}
		tabla=NULL;
		tamanyo=0;
	}
}


// Sobrecarga del operador asignacion
THashDir &
THashDir::operator=(THashDir & a){
	int i;
	if(tamanyo!=0) (*this).~THashDir();
	else{
		tamanyo=a.tamanyo;
		if(tamanyo!=0){
			tabla=new TListaDir[tamanyo];
			for(i=0;i<tamanyo;i++)
				tabla[i]=a.tabla[i];
		}
	}
return(*this);
}


// Sobrecarga del operador igualdad
bool
THashDir::operator==(THashDir & a){
	int i=0;
	bool res=false;
	if(tamanyo==a.tamanyo){
		if(tamanyo!=0){
			while((i<tamanyo)&&(tabla[i]==a.tabla[i])){
				i++;
			}
			if(i==tamanyo) res=true;
		}
		else res=true;
	}
return(res);
}


// Funcion EsVacia
bool
THashDir::EsVacia(){
	bool res=false;
	int i=0;
	if(tamanyo==0) res=true;
	else{
		while((i<tamanyo)&&(tabla[i].EsVacia())){
			i++;
		}
		if(i==tamanyo) res=true;

	}
return(res);
}


// Funcion Insertar
bool
THashDir::Insertar(TDir & a){
	int i,x=0;
	bool res=false;
	if(tamanyo!=0){
		if(a.Nombre()!=NULL) {
			for(i=0;i<strlen(a.Nombre());i++){
				x=x+((int)(a.Nombre()[i])*(i+1));
			}
		x=x%tamanyo;
		}
		res=tabla[x].Insertar(a);
	}
return(res);
}


// Funcion Borrar
bool
THashDir::Borrar(TDir & a){
	bool res=false;
	int i,x=0;
	if(Buscar(a)){
		if(a.Nombre()!=NULL) {
			for(i=0;i<strlen(a.Nombre());i++){
				x=x+((int)(a.Nombre()[i])*(i+1));
			}
		x=x%tamanyo;
		}
		res=tabla[x].Borrar(a);
	}
return(res);
}


// Funcion Buscar
bool
THashDir::Buscar(TDir & a){
 	bool res=false;
	int i, x=0;
	if(tamanyo!=0){
		if(a.Nombre()!=NULL) {
				for(i=0;i<strlen(a.Nombre());i++){
					x=x+((int)(a.Nombre()[i])*(i+1));
				}
			x=x%tamanyo;
		}
		res=tabla[x].Buscar(a);
	}
return(res);
}


// Funcion Tamanyo
int
THashDir::Tamanyo(){
	return tamanyo;
}


// Funcion NElementos
int
THashDir::NElementos(){
	int i, res=0;
	if(tamanyo!=0)
		for(i=0;i<tamanyo;i++) res=res+tabla[i].Longitud();
return (res);
}


// Funcion Lista
TListaDir
THashDir::Lista(){
	int i;
	TListaDir res;
	if (tamanyo!=0){
		for(i=0;i<tamanyo;i++)
			res=res+tabla[i];
	}
return(res);
}


// Sobrecarga operador<<
ostream &
operator<<(ostream & o, THashDir & a){
	int i=0;
	if(a.Tamanyo()==0)
		o<<"##";
	else{
		o<<"#";
		for(i=0;i<a.Tamanyo()-1;i++){
			o<<i<<" ";
			if(!a.tabla[i].EsVacia()) o<<a.tabla[i]<<" ";
			else o<<"{} ";

		}
		if(a.Tamanyo()!=1){
			o<<i<<" ";
			if(!a.tabla[i].EsVacia()) o<<a.tabla[i];
			else o<<"{}";
		}
		else{
			o<<i<<" ";
			if(!a.tabla[i].EsVacia()) o<<a.tabla[i];
			else o<<"{}";
		}
		o<<"#";
	}
	



return(o);
}
