#define isEven(x) ((x & 0x01) == 0)
#define isOdd(x) (x & 0x01)
#define swap(x,y) (x^=y, y^=x, x^=y)
void ExtBinEclid(int *u, int *v, int *ul, int *u2, int *u3){
	//u и v будут переставлены, если u<va_arg
	int k, t1, t2, t3;
	for(k=0; isEven(*u) && isEven(*v); ++k){
		*u >>=1; *v >>=1;
	}
		*u1 = 1; *u2 = 0; *u3 = *u; t1 = *v; t2 = *u - 1; t3 = *v;
		do {
			do{
				if (isEven(*u3)){
					if (isOdd(*u1)) || isOdd(*u2)){
						*u1 += *v; *u2 += *u;
					}
					*u1 >>=1; *u2 >>=1; *u3 >>= 1;
				}
				if (isEven(t3) || *u3 < t3){
					swap(*u1,t2); swap(*u3, t3);
				}
			} while (isEven(*u3));
			while (*u1 < t1 || *u2 < t2){
				*u1 += *v; *u2 += *u;
			}
			*u1 -= t1; *u2 -= t2; *u -= t3;
			
		} while (t3 >0);
		while (*u1 >= *v && *u2 >= *u){
			*u1 -= *v; *u2 -= *u;
		}
		*u1 <<= k; *u2 <<= k; *u3 <<=k;
}

main (int argc, char **argv){
	int a, b, gcd;
	if (argc < 3){
		printf("use: xeuclid u v ");
		return -1;
	}
	int u = atoi(argv[1]);
	int v = atoi(argv[2]);
	if (u <= 0 || v <=0){
		printf("Arguments can be < 0");
		return	-2; 	
	}
	ExtBinEuclid(&u, &v, &a, &b, &gcd);
	printf(a);
	printf(" * ");
	printf(" u ");
	printf(" + (-"); 
	printf(b); 
	printf(") * "); 
	printf(v); 
	printf("="); 
	printf(gcd);
	if (gcd == 1){
		printf("Obratroe zn-e");
		printf(v);
		printf(" mod ");
		printf(u);
		printf("equal");
		printf(u-b);
	}
	return 0;
}