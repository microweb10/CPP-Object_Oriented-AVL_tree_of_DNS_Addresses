
#ifndef _TDir_
#define _TDir_
#include <iostream>
#include <string>
using namespace std;

class TDir{
	friend ostream& operator<<(ostream &,const TDir &);
	private:
		char *nombre, *ip;
	public:
		TDir();
		TDir(char *,char *);
		TDir(TDir &);
		~TDir();
		bool EsVacia();
		void Nombre(char *);
		void IP(char *);
		char* Nombre();
		char* IP();
		bool EsNombre(char *);
		bool EsIP(char *);
		bool EsDir(char *,char *);
		TDir&operator=(TDir &);
		bool operator==(TDir &);
		bool operator!=(TDir &);
		bool operator<(TDir &);
		bool operator>(TDir &);
		bool operator<=(TDir &);
		bool operator>=(TDir &);
};
#endif


