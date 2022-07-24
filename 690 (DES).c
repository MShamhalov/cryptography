#define ENO 0 /* MODE == encrypt */
#define DEI 1 /* MODE == decrypt */

typedef struct {
    unsigned long ek[32]; 
    unsigned long dk[32];
) des_ctx;

extern void deskey(unsigned char *, short);
/* hexkey[8] MODE
*  Sets the internal key register according to the hexadecimal
*  key contained in the 8 bytes of hexkey, according to the DES,
*  for encryption or decryption according to MODE.
*/

extern void usekey(unsigned long *);
/* cookedkey[32]
*  Loads the internal key register with the data in cookedkey.
*/

extern void cpkey(unsigned long *);
/* cookedkey[32]
*  Copies the contents of the internal key register into the storage
*  located at Scookedkey[0].
*/
extern void des(unsigned char *, unsigned char *);
/* from[8] to[8]
*  Encrypts/Decrypts (according to the key currently loaded in the
*  internal key register) one block of eight bytes at address 'from'
*  into the block at address 'to'. They can be the same.
*/ 

static void scrunch(unsigned char *, unsigned long *);
static void unsсrun(unsigned long *, unsigned char *);
static void desfunc(unsigned long *, unsigned long *);
static void cookey(unsigned long *);

static unsigned long KnL[32] = { 0L };
static unsigned long KnR[32] = { 0L } ;
static unsigned long Kn3[32] = { 0L };
static unsigned char Df_Key[24] = {
    0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
    0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10,
    0x89, 0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67 };

static unsigned short bytebit[8] = {
    0200, 0100, 040, 020, 010, 04, 02, 01 };

static unsigned long bigbyte[24] = {
    0x800000L,  0x400000L,  0x200000L,  0x100000L,
    0x80000L,   0x40000L,   0x20000L,   0x10000L,
    0x8000L,    0x4000b,    0x2000L,    0x1000L,
    0x800L,     0x400b,     0x200L,     0x100L,
    0x80L,      0x40L,      0x20L,      0x10L,
    0x8L,       0x4L,       0x2L,       0x1L };

/* Use the key schedule specified in the Standard (ANSI X3.92-1981), */
static unsigned char pc1[56] = {
    56, 48, 40, 32, 24, 16,  8,  0, 57, 49, 41, 33, 25, 17,
     9,  1, 58, 50, 42, 34, 26, 18, 10,  2, 59, 51, 43, 35,
    62, 54, 46, 38, 30, 22, 14,  6, 61, 53, 45, 37, 29, 21,
    13,  5, 60, 52, 44, 36, 28, 20, 12,  4, 27, 19, 11,  3 
    };

static unsigned char totrot(16] = { 
    1, 2, 4, 6, 8, 10, 12, 14, 15, 17, 19, 21, 23, 25, 27, 28 
    };

static unsigned char pc2[48] = {
    13, 16, 10, 23,  0,  4,  2, 27, 14,  5, 20, 9,
    22, 18, 11,  3, 25,  7, 15,  6, 26, 19, 12, 1,
    40, 51, 30, 36, 46, 54, 29, 39, 50, 44, 32, 47,
    43, 48, 38, 55, 33, 52, 45, 41, 49, 35, 28, 31 
    };

void deskey(key, edf) /* Thanks to James Gillogly & Phil Karn! */
unsigned char *key; 
short edf; {
    register int i, j, l, m, n; 
    unsigned char pc1m[56], pcr[56]; 
    unsigned long kn[32];
    
    for ( j=0; j<56; j++ ) {
        l = pc1[j]; 
        m = l & 07;
        pc1m[j] = (key[l >> 3] & bytebit[m]) ? 1 : 0;
    }

    for ( i=0; i<16; i++ ) {
        if ( edf == DE1 ) m = (15 - i) << 1;
        else m = i << 1;
        n = m + 1;
        kn[m] = kn[n] = 0L;
        for (j=0; j<28; j++){
            l = j + totrot[i];
             
        }





register unsigned long *from; {
    register unsigned long *to, *endp;
    to = KnL, endp = &KnL[32];
    while( to < endp ) *to++ = *from++;
    return;
}
void des(inblock, outblock) unsigned char *inblock, *outblock;
{
unsigned long work[2];
scrunch(inblock, work); desfunc(work, KnL}; unscrun(work, outblock); return;
}

static void scrunch(outof, into) register unsigned char *outof; register unsigned long *into;
{
*into = (*outof++ & OxffL) « 24;
*into |= (*outof++ & OxffL) « 16;
*into [= (*outof++ & OxffL) « 8;
*into++ |= (*outof++ & OxffL);
*into = (*outof++ & OxffL) « 24;
*into |= (*outof++ & OxffL) « 16;
*into j= (*outof++ & OxffL) « 8;
*into i= (*outof & OxffL);
return;
}
static void unscrun(outof, into) register unsigned long *outof; register unsigned char *into;
{
*into++ = (*outof » 24) & OxffL;
*into++ = (*outof » 16) & OxffL;
*into++ = (*outof » 8) & OxffL;
*into++ = *outof++ & OxffL;
*into++ = (*outof » 24) & OxffL;
*into++ = (*outof » 16) & OxffL;
*into++ = (*outof » 8} & OxffL;
*into = *outof & OxffL; return;
}
static unsigned long SP1[64] = {
0x01010400L, OxOOOOOOOOL, OxOOOlOOOOL, Ox01010404L, Ox01010004L, Ox00010404L, 0x00000004L, OxOOOlOOOOL, 0x00000400L, 0x01010400L, Ox01010404L, 0x0000040OL, 0x01000404L, 0x01010004L, OxOlOOOOOOL, 0x0000Q004L, 0x00000404L, 0x01000400L, Ox01000400L, Ox00010400L, 0x00010400L, OxOlOlOOOOL, OxOlOlOOOOL, Ox01000404L, 




Ox00010004L, 0x01000004L, Ox01000004L, 0x00010004L, OxOOOOOOOOL, 0x00000404L, Qx00010404L, OxOlOOOOOOL, OxOOOlOOOOL, 0x01010404L, 0x00000004L, OxOlOlOOOOL, Ox01010400L, OxOlOOOOOOL/ OxOlOOOOOOL, Ox00000400L, Ox01010004L, OxOOOlOOOOL, 0x00010400L, 0x01000004L, Ox00000400L, Ox00000004L, 0x01000404L, 0x00010404L, 0x01010404L, 0x00010004L, OxOlOlOOOOL, Ox01000404L, 0x01Q00004L, 0x00000404L, Ox00010404L, 0x01010400L, Ox00000404L, Ox01000400L, Ox01000400L, OxOOOOOOOOL, Ox00010004L, Ox0OOlO4OOL, OxOOOOOOOOL, 0x01010004L };
unsigned long SP2[64] = {
0x80108020L, 0x80008000L, 0x00008000L, 0x00108020L, OxOOlOOOOOL, 0x00000020L, 0x80100020L, 0x80008020L, 0x80000020L, 0x80108020L, 0x80108000L, 0x80000000L, Ox80008000L, OxOOlOOOOOL, 0x0000002QL, 0x80100020L, 0x00108000L, Ox00100020L, Qx80008020L, OxOOOOOOOOL, Ox80000000L, OxOOOO8OO0L, 0x00108020L, Ox80100000L, Ox00100020L, Ox80000020L, OxOOOOOOOOL, 0x00108000L, 0X00O08020L, Ox80108000L, Ox80100000L, 0x00008020L, OxOOOOOOOOL, Ox00108020L, 0x80100020L, OxOOlOOOOOL, Ox80008020L, 0x80100000L, 0x80108000L, 0x00008000L, Ox80100000L, OX8OOO8OOOL, 0x00000020L, 0x80108020L, 0x001O8020L, Ox00000020L, Ox00008000L, Ox80000000L, Ox00008020L, Ox80108000L, OxOOlOOOOOL, 0x80000020L, 0x00100020L, Ox80008020L, 0x80000020L, Ox00100020L, Ox00108000L, OxOOOOOOOOL, 0x80008000L, 0x00008020L, Ox80000000L, 0x80100020L, Ox80108020L, 0x00108000L };
unsigned long SP3[64] = {
0x00000208L, 0x08020200L, OxOOOOOOOOL, Ox08020008L, OxO8OOO20OL, OxOOOOOOOOL, Ox00020208L, Ox08000200L, Ox00020008L, 0x08000008L, Ox08000008L, Ox00020000L, 0x08020208L, Ox00020008L, 0x08020D00L, Qx00000208L, Ox08000000L, 0x00000008L, 0x08020200L, 0x00000200L, Ox00020200L, 0x0802000OL, Ox08020008L, 0x00020208L, 0x08000208L, 0x00020200L, 0x00020000L, 0x08000208L, Ox00000008L, Ox08020208L, Ox00000200L, Ox08000000L, 0x08020200L, 0x08Q00000L, 0x00020008L, Ox00000208L, 0x00020000L, 0x08020200L, 0x08000200L, OxOOOOOOOOL, 0x000O0200L, 0x00020008L, 0x08G20208L, Ox08000200L, OXO8OOOOO8L, Dx00000200L, OxOOOOOOOOL, Ox08020008L, 0x08000208L, 0x00020000L, 0x08000000L, 0x08020208L, Ox00000008L, 0x00020208L, Qx00020200L, Ox08000008L, 0X0802D000L, 0x080002Q8L, 0x00000208L, 0x08020000L, Gx00020208L, 0x00000008L, 0x08020008L, Ox00020200L };
unsigned long SP4[64] = {
Ox00802001L, 0X00002081L, 0x00002081L, Ox00000080L, 0x00802080L, OXOO8OOO8IL, Ox0080000lL, 0x0000200lL, OxOOOOOOOOL, 0x00802000L, Ox00802000L, 0x0080208lL, Ox00000081L, OxOOOOOOOOL, Ox00800080L, 0x008Q000lL, OxOOOOOOOlL, Ox00002000L, Ox00800000L, Ox00802001L, Ox00000080L, 0x00800000L, 0x00002Q01L, Ox00002080L, 0x00800081L, OxOOOOOOOlL, 0x00O02080L, 0x00800080L, 




0x00002000L, 0x00802080L, 0x00802081b, 0x00000081L, 0xQ0800080L, 0x00800001L, 0x00802000L, 0x00802081L, 0x00000081L, OxOOOOOOOOL, OxOOOOOOOOL, Qx00802000L, 0x00002080L, Ox00800080L, 0x00800081b, OxOOOOOOOlL, 0x00802001L, Ox00002081L, 0x00C02081L, 0x00000080L, 0x00802081L, Ox00000081L, OxOOOOOOOlL, 0x00002000b, 0x00800001L, Ox00002001L, 0x0Q802080L, 0x00800081L, 0x00002001L, Qx00002080L, Ox00800000L, 0x00802001L, Ox00000080L, 0x00800000b, 0x00002000b, 0x00802080b };
static unsigned long SP5[64} = {
OxOOOOOlOOL, Ox02080100L, 0x02080000L, 0x42000100b, 0x00080000L, OxOOOOOlOOL, 0x40000000b, Ox02080000L, 0x40080100L, 0x00080000L, 0x02000100L, 0x40080100L, 0x420001O0L, Dx42080000L, 0x00080100b, Ox40000000L, 0x02000000L, 0x40080000L, 0x40080000L, OxOOOOOOOOL, 0x40000100L, 0x42080100L, 0x42080100L, 0x02000100L, 0x42080000L, 0x40000100L, OxOOOOOOOOL, 0x42000000L, 0x02080100L, 0x02000000L, Qx42000000L, Ox00080100L, 0x00080000L, 0X42000100L, OxOOOOOlOOL, Ox02000000L, Ox40000000L, Ox02080000L, 0x42000100L, 0x40080100L, 0x02000100L, Ox40000000L, 0x42080000L, Ox02080100L, 0x40080100L, OxOOOOOlOOL, Ox02000000L, 0x42080000L, 0x42080100L, 0x00080100L, 0x42000000L, 0x42080100L, Ox02080000L, OxOOOOOOOOL, 0x40080000L, 0x4200Q000L, 0x00080100L, 0x02000100L, Ox40000100L, Ox00080000L, OxOOOOOOOOL, 0x40080000L, 0x02080100L, 0x40000100b };
static unsigned long SP6[64] - {
Ox20000010L, 0x20400000L, 0x00004000L, 0x20404010L, 0x20400000L, OxOOOOOOlOL, 0x20404010L, Ox00400000L, 0x20004000L, 0x00404010L, Ox00400000L, Ox20000010L, Ox00400010L, 0x20004000L, Ox20000000L, Ox00004010L, OxOOOOOOOOL, 0x00400010L, 0x20004010L, 0x00004000L, 0x00404000L, 0x20004010L, OxOOOOOOlOL, 0x20400010L, 0x20400010L, OxOOOOOOOOL, 0x00404010L, Ox20404000L, 0x00004010L, 0x00404000L, 0x20404000L, 0x20000000L, 0x200040001, OxOOOOOOlOL, Ox20400010L, Ox00404000L, Ox20404010L, 0x00400000L, 0x00004010L, 0x20000010L, 0x00400000L, 0x20004000L, 0x20000000L, 0x00004010L, Ox20000010L, 0x2Q404010L, 0x00404000L, 0x2040O000L, 0x00404010L, 0x20404000L, OxOOOOOOOOL, 0x20400010L, OxOOOOOOlOL, 0x00004000L, 0x2Q400000L, 0x0040401GL, 0x00004000L, 0x00400010L, 0x20004010L, OxOOOOOOOOL, 0x20404000L, Dx20000000L, 0x00400010L, 0x20004010L };
static unsigned long SP7[64] = {
0x00200000L, Ox04200002L, Ox04000802L, OxOOOOOOOOL, 0x00000800L, 0x04000802L, 0x002008Q2L, 0x04200800L^ 0x04200802L, Ox00200000L, OxOOOOOOOOL, 0x04000002L, Ox00000002L, Ox04000000L, 0x042O0002L, Ox00000802L, 0x04000800L, 0x00200802L, 0x00200002L, Ox04000800L, Ox04000002L, Dx04200000L, Ox04200800L, Ox00200002L, 0x04200000L, 0x00000800L, 0x00000802L, 0x04200802L> 0x00200800L, Ox00000002L, 0x04000O00L, 0x00200800L, 




0x04000000L,
0x04000802L,
0x00200002L,
0x04200800L,
0x00000802L,
0x00200800L,
0x00000000L,
0x04000002L, 
0x00200800L,
0x04200002L,
0x04000000L,
0x00000802L,
0x04000002L,
0x00000000L,
0x00200802L,
0x04000800L, 
0x00200000L,
0x04200002L,
0x04000800L,
0x00200802L,
0X04200802L,
0x00000002L,
0x04200000L,
0x00000800L,
0x04000802L, 
0x00000002L, 
0x00200000L, 
0X04200800L, 
0x04200000L, 
0x04200802L, 
0x00000800L, 
0x00200002L }; 

 
static unsigned long SP8[64] = { 
0x10001040b,
0x10000000L,
0x00040040L,
0x10041000L,
0x10040000L,
0x00041000L,
0x00001040L,
0x10000040L,
0x00041040b,
0x00000040L,
0x10000100L,
0x10040040L,
0x00000000L,
0x10040000L,
0x10041040L,
0x00001040L,
0x00001000L,
0x10001040L,
0x10040000L,
0x00041040L,
0x10000040L,
0x00040040L,
0x00000000L,
0x10001000L,
0x00040000L,
0X10040040L,
0x00000040L,
0x10000000L,
0x10041040L,
0x10001000L,
0x00041000L,
0x00040040L, 
0x00040000L,
0x00000040L,
0x10041040L,
0x00001000L,
0x10001000L,
0x10040040L,
0x00000000L,
0x00041040L,
0x10041000L,
0x00001000L,
0X10000040L,
0x0004000DL,
0x00040040L,
0x10001040L,
0x00041000L,
0x10000000L,
0x10041040L, 
0x10000000L,
0x00041000L, 
0x00000040L, 
0x00001040L, 
0x10041000L, 
0x10040040L, 
0x00040000L, 
0x00001000L, 
0x00041040L, 
0x10040000L, 
0x10001040L, 
0x10000040L, 
0x00000000L, 
0x00001040L, 
0x10041000L }; 

 
static void desfunc{block, keys) register unsigned long *block, *keys;
{
register unsigned long fval, work, right, leftt; register int round;
leftt = block[0]; right = block[1];
work = {(leftt » 4) A right) & OxOfOfOfOfL;
right A= work;
leftt A= (work « 4);
work = {(leftt » 16) л right) & OxOOOOffffL;
right A= work;
leftt A= (work « 16);
work = ((right » 2) A leftt) & 0x33333333L;
leftt A= work;
right A= (work « 2);
work = ((right » 8) A leftt) & OxOOffOOffL;
leftt A- work;
right A= (work « 8);
right = ((right « 1) | ((right » 31) & 1L)) & OxffffffffL;
work = (leftt A right) & OxaaaaaaaaL; leftt A= work;
right A- work;
leftt = ({leftt « 1) [ {{leftt » 31) & 1L)) & OxffffffffL;
for( round = 0; round < 8; round++ ) (
work = (right « 28) I (right » 4); 





