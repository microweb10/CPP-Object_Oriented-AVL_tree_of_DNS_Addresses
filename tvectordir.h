
#ifndef _TVECTDir_
#define _TVECTDir_
#include "tdir.h"
using namespace std;

class TVectorDir{
	friend ostream& operator<<(ostream &,const TVectorDir &);
	private:
		TDir *direccion;
		TDir dirVacia;
		int dim;
	public:
		TVectorDir();
		TVectorDir(int);
		TVectorDir(TVectorDir &);
		~TVectorDir();
		TVectorDir &operator=(const TVectorDir &);
		bool operator==(TVectorDir &);
		TDir& operator[](int);
		int Longitud();
};
#endif


