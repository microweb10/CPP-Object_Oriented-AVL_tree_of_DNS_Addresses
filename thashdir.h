#ifndef _THashDir_
#define _THashDir_
#include "tlistadir.h"
using namespace std;

class THashDir{
	friend ostream& operator<<(ostream &,THashDir &);
	private:
		int tamanyo;
		TListaDir *tabla;
	public:
		THashDir();
		THashDir(int);
		THashDir(THashDir &);
		~THashDir();
		THashDir &operator=(THashDir &);
		bool operator==(THashDir &);
		bool EsVacia();
		bool Insertar(TDir &);
		bool Borrar (TDir &);
		bool Buscar (TDir &);
		int Tamanyo();
		int NElementos();
		TListaDir Lista();
};
#endif


