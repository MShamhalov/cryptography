static int s1 = 1; /* "int" должно быть 16-битовым целым. */
static int s2 = 1;
static int s3 = 1;
#define MODMULT (a, b, c, m, s) q = s/a; s = b*(s-a*q) - c*q;
if (s < 0) s += m;
/* MODMULT (a, b, c, m, s) вычисляет s*b mod m при условии, что m=a*b+c и 0 <= c < m  */
/* */
double combinedLCG (void) {
    int q;
    int z;
    MODULT (206, 157, 21, 32363, s1);
    MODULT (217, 146, 45, 31727, s2);
    MODULT (222, 142, 133, 31657, s3);
    z = s1 - s2;
    if (z < 706)
        z -= 32362;
    z += s3;
    if (z < 1)
        z += 32362;
    return z * 3.0899e-5;
}
    /* В общем случае перед использованием  функции combinedLCG вызывайте функцию initLCG */
void initLCG (int InitS1, int InitS2, int InitS3) {
    s1 = InitS1;
    s2 = InitS2;
    s3 = InitS3;
}

