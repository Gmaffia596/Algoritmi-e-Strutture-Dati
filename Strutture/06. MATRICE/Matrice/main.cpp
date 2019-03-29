#include "matrice.cpp"

int main(){
	matrice A(3,2), T(2,3);
	A.rand2();
	A.stampa();
	T = A.trasposta();
	T.stampa();

	matrice B(4000,4000);
	B.stampa();
	B = T;
	B.stampa();
	return 0;
}
