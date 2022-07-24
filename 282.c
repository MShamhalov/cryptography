int multiple_god (int m, int *x) {
    size_t i;
    int g;
    if (m < 1) return 0;
    g = x[0];
    for (i = 1; i < m; ++i) {
        g = god(g, x[i]);
        /* Оптимизация, так как для случайного x[i], g == 1 в 60% случаев */
        if (g == 1) return 1;
    }
    return g;
}