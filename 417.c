static long s1 = 1; /* "long" должно быть 32-битовым целым. */
static long s2 = 1;
#define MODMULT (a, b, c, m, s) 
q = s/a; 
s = b*(s-a*q) - c*q;

if (s < 0) s += m;
/* MODMULT (a, b, c, m, s) вычисляет s*b mod m при условии, что m=a*b+c и 0 <= c < m  */
/* */
double combinedLCG (void) {
    long q;
    long z;
    MODULT (53668, 40014, 12211, 2147483563L, s1);
    MODULT (52774, 40692, 3791, 2147483399L, s2);
    z = s1 - s2;
    if (z < 1)
        z += 2147483562;
    return z * 4.656613e-10;
}
    /* В общем случае перед использованием  функции combinedLCG вызывайте функцию initLCG */
void initLCG (long InitS1, long InitS2) {
    s1 = InitS1;
    s2 = InitS2;
}

