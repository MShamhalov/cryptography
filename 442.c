#define ARR_SIZE (8192)
static unsigned char prngB(void);
long prngB(void);

void init_algM(void){
	long i;
	for(i=0; i<ARR_SIZE; i++)
		delay[i] = prngA();
}

unsigned char algM(void){
	long j,v;
	j = prngB() %ARR_SIZE;
	v = delay[j];
	delay[j] = prngA();
	return (v);
}