int x0 (int p, int q, int n, int t, int xt){
    int a, b, u, v, w, z;
    /* мы уже знаем, что НОД (p, q) == 1  */
    (void) extended_euclidian (p, q, &a, &b);
    u = modexp ((p+1)/4, t, p-1);
    v = modexp ((q+1)/4, t, q-1);
    w = modexp (xt%p, u, p);
    z = modexp (xt%q, v, q);
    return (b*q*w + a*p*z) % n;
}