
#ifndef _TLISTADir_
#define _TLISTADir_
#include "tdir.h"
using namespace std;


class TNodoDir;

class TListaDir{
	friend class TNodoDir;
	friend ostream& operator<<(ostream&,const TListaDir&);
	private:
		TNodoDir *primera;
	public:
		TListaDir();
		TListaDir(TListaDir&);
		~TListaDir();
		TListaDir& operator=(const TListaDir&);
		bool operator==(TListaDir&);
		TListaDir operator+(TListaDir&);
		bool EsVacia()const;
		bool Insertar(TDir&);
		bool Borrar(TDir&);
		bool Buscar(TDir&);
		int Longitud()const;
		TNodoDir* Primera()const{return primera;};
};

class TNodoDir{
	friend class TListaDir;
	private:
		TDir dir;
		TNodoDir *sig;
	public:
		TNodoDir(){sig=NULL;};
		TNodoDir(TNodoDir &nodo){dir=nodo.dir;sig=nodo.sig;};
		~TNodoDir(){dir.~TDir();sig=NULL;};
		TNodoDir& operator=(TNodoDir &nodo){dir=nodo.dir;sig=nodo.sig;};
		TDir& GetDir(){return dir;};
		TNodoDir* GetSig(){return sig;};
};
#endif


