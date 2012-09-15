
#include "tdir.h"

// Constructor por defecto
TDir::TDir(){
	nombre=NULL;
	ip=NULL;
}


// Constructor sobrecargado (Nombre de dominio y direccion ip)
TDir::TDir(char *n,char *i){
	if(n!=NULL){
	nombre = new char[strlen(n)+1];
	if(!nombre) cerr<<"ERROR: Fallo en la creacion del nombre de dominio"<<endl;
	else strcpy(nombre,n);
	}
	else nombre=NULL;
	if(i!=NULL){
		ip = new char[strlen(i)+1];
		if(!ip) cerr<<"ERROR: Fallo en la creacion de la direccion ip"<<endl;
		else strcpy(ip,i);
	}
	else ip=NULL;
}


// Constructor de Copia
TDir::TDir(TDir &d){
	if(d.Nombre()!=NULL){
		nombre = new char[strlen(d.Nombre())+1];
		if(!nombre) cerr<<"ERROR: Fallo en la creacion del nombre de dominio"<<endl;
		else strcpy(nombre,d.Nombre());
	}
	else nombre=NULL;
	if(d.IP()!=NULL){
		ip = new char[strlen(d.IP())+1];
		if(!ip) cerr<<"ERROR: Fallo en la creacion de la direccion ip"<<endl;
		else strcpy(ip,d.IP());
	}
	else ip=NULL;
}


// Destructor
TDir::~TDir(){
	if (nombre!=NULL) {delete[] nombre; nombre=NULL;}
	if (ip!=NULL) {delete[] ip; ip=NULL;}
}


// funcion EsVacia
bool
TDir::EsVacia(){
	bool res=false;
	if ((nombre==NULL)&&(ip==NULL)) res=true;
return res;
}


// funcion Nombre (modifica el nombre de dominio)
void
TDir::Nombre(char *n){
	if (nombre!=NULL) delete[]nombre;
	nombre = new char[strlen(n)+1];
	if(!nombre) cerr<<"ERROR: Fallo en la creacion del nombre de dominio"<<endl;
	else strcpy(nombre,n);
}


// funcion IP (modifica la direccion ip)
void
TDir::IP(char *i){
	if (ip!=NULL) delete[]ip;
	ip = new char[strlen(i)+1];
	if(!ip) cerr<<"ERROR: Fallo en la creacion de la direccion ip"<<endl;
	else strcpy(ip,i);
}


// funcion Nombre (devuelve el nombre de dominio)
char*
TDir::Nombre(){
return nombre;
}


// funcion IP (devuelve la direccion ip)
char*
TDir::IP(){
return ip;
}


// funcion EsNombre (comprueba si un nombre es igual al almacenado en el campo nombre de la direccion que invoca)
bool
TDir::EsNombre(char *n){
	bool res=false;
	if ((nombre!=NULL)&&(n!=NULL)){
		if (strcmp(nombre,n)==0) res=true;
	}
	else{
		if((nombre==NULL)&&(n==NULL)) res=true;
	}
return res;
}


// funcion EsIP (comprueba si una ip es igual a la almacenada en el campo ip de la direccion que invoca)
bool
TDir::EsIP(char *i){
	bool res=false;
	if ((ip!=NULL)&&(i!=NULL)){
		if (strcmp(ip,i)==0) res=true;
	}
	else{
		if((ip==NULL)&&(i==NULL)) res=true;
	}
return res;
}


// funcion EsDir (comprueba si una direccion entera (nombre e ip) es igual a la almacenada por el objeto que invoca)
bool
TDir::EsDir(char *n,char *i){
	bool res=false;
	if ((nombre!=NULL)&&(ip!=NULL)&&(n!=NULL)&&(i!=NULL)){
		if (((strcmp(nombre,n))==0)&&((strcmp(ip,i))==0)) res=true;
	}
	else{
		if((nombre==NULL)&&(ip==NULL)&&(n==NULL)&&(i==NULL)) res=true;
	}
return res;
}

// Sobrecarga del Operador =  (asignacion)
TDir&
TDir::operator=(TDir &d){
	if(d.Nombre()!=NULL){
		if(nombre!=NULL){
			if(strcmp(nombre,d.Nombre())!=0){
				delete[]nombre;
				nombre = new char[strlen(d.Nombre())+1];
				if(!nombre) cerr<<"ERROR: Fallo en la creacion del nombre de dominio"<<endl;
				else strcpy(nombre,d.Nombre());
			}
		}
		else{
			nombre = new char[strlen(d.Nombre())+1];
			if(!nombre) cerr<<"ERROR: Fallo en la creacion del nombre de dominio"<<endl;
			else strcpy(nombre,d.Nombre());
		}
	}
	else {
		if(nombre!=NULL){
			delete[]nombre;
			nombre=NULL;
		}
	}
	if(d.IP()!=NULL){
  		if(ip!=NULL){
			if(strcmp(ip,d.IP())!=0){
				delete[]ip;
				ip = new char[strlen(d.IP())+1];
				if(!ip) cerr<<"ERROR: Fallo en la creacion de la direccion ip"<<endl;
				else strcpy(ip,d.IP());
			}
		}
		else{
			ip = new char[strlen(d.IP())+1];
			if(!ip) cerr<<"ERROR: Fallo en la creacion de la direccion ip"<<endl;
			else strcpy(ip,d.IP());
		}
	}
	else {
		if(ip!=NULL){
			delete[]ip;
			ip=NULL;
		}
	}
return *this;
}


// Sobrecarga del Operador ==  (igualdad)
bool
TDir::operator==(TDir &d){
	bool res=false;
	if((nombre==NULL)&&(d.Nombre()==NULL)){
		if((ip==NULL)&&(d.IP()==NULL)) res=true;
		else
			if((ip!=NULL)&&(d.IP()!=NULL))
			 	if((strcmp(d.IP(),ip))==0) res=true;
	}
	else{
		if((nombre!=NULL)&&(d.Nombre()!=NULL))
			if((strcmp(d.Nombre(),nombre))==0){
				if((ip==NULL)&&(d.IP()==NULL)) res=true;
				else
					if((ip!=NULL)&&(d.IP()!=NULL))
						if((strcmp(d.IP(),ip))==0) res=true;
			}
	}
return res;
}


// Sobrecarga del Operador !=
bool
TDir::operator!=(TDir &d){
	bool res=true;
	if (*this==d) res=false;
return res;
}


// Sobrecarga del Operador <
bool
TDir::operator<(TDir &d){
	bool res=false;
	if ((nombre==NULL)&&(d.Nombre()!=NULL)) res=true;
	else{
		if((nombre!=NULL)&&(d.Nombre()!=NULL)){
			if (strcmp(nombre,d.Nombre())<0) res=true;
			else{
				if(strcmp(nombre,d.Nombre())==0){
					if ((ip==NULL)&&(d.IP()!=NULL)) res=true;
					else {
						if((ip!=NULL)&&(d.IP()!=NULL))
							if (strcmp(ip,d.IP())<0) res=true;
					}
				}
			}
		}
	}
	if((nombre==NULL)&&(d.Nombre()==NULL)){
		if ((ip==NULL)&&(d.IP()!=NULL)) res=true;
		else {
			if((ip!=NULL)&&(d.IP()!=NULL))
				if (strcmp(ip,d.IP())<0) res=true;
		}
	}
return res;
}


// Sobrecarga del Operador >
bool
TDir::operator>(TDir &d){
	bool res=true;
	if(*this==d) res=false;
	else
		if (*this<d) res=false;
return res;
}


// Sobrecarga del Operador <=
bool
TDir::operator<=(TDir &d){
bool res=false;
	if((*this<d)||(*this==d)) res=true;
return res;
}


// Sobrecarga del Operador >=
bool
TDir::operator>=(TDir &d){
bool res=false;
	if((*this>d)||(*this==d)) res=true;
return res;
}


// Sobrecarga operador<<
ostream& operator<<(ostream &o,const TDir &d){
	if (d.nombre==NULL) o<<"- ";
	else o<<d.nombre<<" ";
	if (d.ip==NULL) o<<"-";
	else o<<d.ip;
return o;
}
