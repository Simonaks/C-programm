#includ <sys/types.h>
#includ <sys/stat.h>
#includ <fcntl.h>
#includ <unistd.h>
#includ <stdio.h>
#includ <stdlib.h>

//fonction pour calculer le md5 des deux fichiers
EVP_MD_CTX * getFileMD5( const char * path )
{
    EVP_MD_CTX * ctx;
    //Initialisations du contexte ctx
    FILE * f = fopen( path , "rb" );
    size_t bs = 0;
    char buffer[2048]="";

    if( !f ) return NULL;

    while( (bs=fread(buffer, 1 , sizeof buffer,f)) )
    {
        EVP_DigestUpdate(ctx, buffer, bs);
    }

    fclose( f );
    return ctx;
}
int main(int argc, char **argv)
{
int fd1, fd2, rc;
char buf;
if(argc != 3) {
fprintf(stderr, "Syntaxe: %s f1 f2\n", argv[0]);
exit(1);
}
fd1 = open(argv[1], O_RDONLY);
if(fd1 < 0) {
perror("open(fd1)");
exit(1);
}
fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
if(fd2 < 0) {
perror("open(fd2)");
exit(1);
}
while(1) {
rc = read(fd1, &buf, 1);
if(rc < 0) {
perror("read");
exit(1);
}
if(rc == 0)
break;
rc = write(fd2, &buf, 1);
if(rc < 0) {
perror("write");
exit(1);
}
if(rc != 1) {
fprintf(stderr, "Écriture interrompue");
exit(1);
}
}
// Vérifier si la coipie est bien faite
//comparaison des md5 des fihiers
 if (MD5File(fd1, &buffer)==MD5File(fd2, &buffer))
    //envoi d'un message de confirmation du bon déroulement de la copie
 {
     printf(" Copie effectuée avec succès")
 }

close(fd1);
close(fd2);
return 0;
}
