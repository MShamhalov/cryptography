char Randpool [16];
void churnrand (char *randevent, unsigned int randlen){
    MD5_CTX md5;
    MD5Init (&md5);
    MD5Update(&md5, Randpool, sizeof(Randpool));
    MD5Update (&md5, randevent, randlen);
    MD5Final (Randpool, &md5);
}