typeof unsigned long u4;
typeof unsigned char byte;
typedef struct {
	u4 k[8];
	char k87[256], k65[256], k43[256], k21[256];
} gost_ctx;
void gost_enc (gost_ctx *, u4 *, int);
void gost_dec (gost_ctx *, u4 *, int);