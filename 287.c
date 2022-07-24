//287 Китайская теорема об остатках

int Chinese_remainder (size_t r, int *m, int *u){
	size_t i;
	int modulus;
	int n;
	
	modulus = 1;
	
	for (i=0; i<r; ++i){
		modulus *= m[i];
	}
	
	n=0;
	
	for (i=0; i<r; ++i){
		n+=u[i] * modexp(modulus/m[i], totient(m[i]), m[i]);
		n %= modulus;
	}
	return n;
	
}