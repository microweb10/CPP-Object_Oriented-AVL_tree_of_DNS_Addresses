
#ifndef _TAVL_
#define _TAVL_
#include "tvectordir.h"
using namespace std;

class TNodoAVLDir;

class TAVLDir{
	friend class TNodoAVLDir;
	private:
		TNodoAVLDir *nodo;
		void InordenAux(TVectorDir&,int&);
		void PreordenAux(TVectorDir&,int&);
		void PostordenAux(TVectorDir&,int&);
	public:
		void Mostrar();
		TAVLDir();
		TAVLDir(TAVLDir&);
		~TAVLDir();
		TAVLDir&operator=(TAVLDir&);
		bool operator==(TAVLDir&);
		bool EsVacio();
		bool Insertar(TDir&);
		bool Buscar(TDir&);
		int Altura();
		int Nodos();
		int NodosHoja();
		TVectorDir Inorden();
		TVectorDir const Preorden();
		TVectorDir Postorden();
};

class TNodoAVLDir{
	friend class TAVLDir;
	private:

	public:
		TDir item; // etiqueta del nodo
		TAVLDir iz,de; // arboles hijo (izquierdo y derecho)
		int fe;// factor de equilibrio
		
		TNodoAVLDir();
		TNodoAVLDir(TNodoAVLDir&);
		~TNodoAVLDir();
		TNodoAVLDir& operator=(TNodoAVLDir&);
};
#endif


