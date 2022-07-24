long Randcnt;
void genrand (char *buf, unsigned int buflen) {
    MD5_CTX md5;
    char tmp[16];
    unsigned int n;
    while (buflen != 0){
        /* Хеширование пула с помощью счетчика */
        MD5Init (&md5);
        MD5Update (&md5, Randpool, sizeof(Randpool));
        MD5Update (&md5, (unsigned char *) &Randcnt, sizeof(Randcnt));
        MD5Final(tmp, &md5);
        Randcnt++;
        /* Копируем 16 или число запрошенных байтов, если ономеньше 16, в буфер пользователя */
        n = (buffer < 16 ) ? buflen : 16;
        memcpy (buf, tmp, n);
        buf += n;
        buflen -= n;
    }
}