
#includesysstat.h
#includefcntl.h
#include systypes.h
#include stdlib.h
#include stdio.h
#include unistd.h
#include signal.h
#include stdlib.h
#include stdio.h
#include syswait.h   
#include ctype.h      
#include string.h
#include errno.h      
#include dirent.h
#include pwd.h
#define ARGVMAX 50
 char argv[ARGVMAX];
 int argc;
 char   ligne_de_cmd[800];

	void affiche_invite_de_commande()
	{
	  printf( MiniShell_LASRI MSL $$ );
        fflush(stdout);
	}

	void lecture_de_la_ligne()
	{
	  if (!fgets(ligne_de_cmd,sizeof(ligne_de_cmd)-1,stdin)) {
	    printf(n);
	    exit(0);
	  }
	}

	void decouper_Saisie()
	{
	  char buffer = ligne_de_cmd;
	  int index;
	  argc=0;
	  for (index=0; indexARGVMAX-1; index++) {

	    
	    while (buffer && isspace(buffer)) 
		buffer++;
	    if (!buffer) 
		break;

	    argv[index] = buffer;

	    while (buffer && !isspace(buffer)) 
		buffer++; 

	    if (buffer)
		 { 
			buffer = 0;
			buffer++; 
		 }
	   argc++;
	  }

	  argv[index] = NULL;
	}

void usage(char av)
{
        printf(Usage %s [options ] [files] ...n, av[0]);
}
cat -n -E -b -T 
void cat (int ac, char av)
{
        int i, fd,truen=0,truedol=0,trueb=0,truet=0,k,j;
        ssize_t byte_lu;
        char buffer[4096],buffern[4096]=0,buffer3[4096]=0;
        if (ac  2)
                usage(av);
        for (i=1; iac; i++)
        {  if(!strcmp(av[i],-n)) {truen=1;continue;}
           if(!strcmp(av[i],-E)) {truedol=1;continue;}
           if(!strcmp(av[i],-b)) {trueb=1;continue;}
           if(!strcmp(av[i],-T)) {truet=1;continue;}
                fd = open(av[i],O_RDONLY);
                if (fd == -1)
                        perror(open );
                else
                {  j=1;
                      while((byte_lu=read(fd,buffer,sizeof(buffer)))0)
                         {
                          sans option  
                         if(!truen && !truedol && !trueb && !truet)
                                     {write(STDOUT_FILENO, buffer, byte_lu);}
                          option -T  
                         if (truet!=0) {
                                      k=0;
                                     for(i=0;ibyte_lu;i++)
                                       { if(buffer[i]!='n')
                                            { if(buffer[i]=='t')
                                               {buffern[k]='^';k++;buffern[k]='I';}
                                              else
                                                strcpy(buffern+k,buffer+i);
                                              k++;
                                            }
                                          else{  buffern[k]='0';
                                                fusion de -T et -n 
                                               if(truen!=0 ) {sprintf(buffer3, t%d %s,j,buffern);
                                                          write(STDOUT_FILENO,buffer3,strlen(buffer3));
                                                          strcpy(buffer3,0); truen++;
                                                         }
                                               else write(STDOUT_FILENO,buffern,strlen(buffern));
                                               strcpy(buffern,0);strcpy(buffer3,0);
                                               j++;
                                               k=0;
                                               puts();
                                             }

                                       }
                                 truet++;  }

                          option -E 
                         if (truedol){
                                     for(i=0;ibyte_lu;i++)
                                       { if(buffer[i]=='n')
                                           { strcpy(buffern,$);
                                             strcat(buffern,buffer+i);
                                            write(STDOUT_FILENO,buffern,1);
                                             puts();}
                                         else write(STDOUT_FILENO, buffer+i,1);
                                    }}
                         option -n  
                         if (truen==1) {

                                      k=0;
                                     for(i=0;ibyte_lu;i++)
                                       { if(buffer[i]!='n')
                                            { strcpy(buffern+k,buffer+i);
                                              k++;
                                            }
                                        else{  buffern[k]='0';
                                               sprintf(buffer3, t%d %s,j,buffern);
                                               write(STDOUT_FILENO,buffer3,strlen(buffer3));
                                               strcpy(buffern,0);strcpy(buffer3,0);
                                               j++;
                                               k=0;
                                               puts();
                                             }

                                       }
                                   }
                            option -b  
                            if (trueb) {
                                      k=0;
                                     for(i=0;ibyte_lu;i++)
                                       { if(buffer[i]!='n')
                                            { strcpy(buffern+k,buffer+i);
                                              k++;
                                            }
                                        else{  buffern[k]='0';
                                               if(strcmp(buffern,0)!=0)
                                               {sprintf(buffer3, t%d %s,j,buffern);
                                               write(STDOUT_FILENO,buffer3,strlen(buffer3));j++;}
                                               if(strcmp(buffern,0)==0) write(STDOUT_FILENO,buffern,strlen(buffern));
                                               strcpy(buffern,0);strcpy(buffer3,0);
                                               j++;
                                               k=0;
                                               puts();
                                             }

                                    }

                        strcpy(buffer,0);
                     }fin de while
                        close(fd);}  fin de else fd!=0
                }fin de for des fichiers
       }

}
 more +num -num -d -f -p 
void more (int ac, char av)
{       struct stat e;
        int i,m,fd,k,j=0,nl,l,perc,f=0;
        int num=48,nump=0,nn,q,flg=0,trued=0,truef=0,truep=0;
        ssize_t byte_lu;
        char buffer[4096]=0,buffern[5000]=0,buffer3[4096]=0,c,d;
        
        if (ac  2)
                usage(av);
   for(l=1;lac;l++)
          { stat(av[l],&e);
            if(S_ISDIR(e.st_mode)) { printf( Error %s est un catalogue n,av[l]); exit(0);}
             option -f  
            if(strcmp(av[l],-f)==0) { if(ac3) usage(av); else {truef=1;}
                                       continue;}
            option -p  
            if(strcmp(av[l],-p)==0) {if(ac3) usage(av); else truep=1;
                                       continue;}
           option -num  
            if(av[l][0]=='-' && av[l][1]!='p' && av[l][1]!='d') {if(ac3) usage(av); else {num=-atoi(av[l]);flg=1;} continue;}
            option +num    
            if(av[l][0]=='+') {if(ac3) usage(av); else{nump=atoi(av[l]);}continue;}
            option -d  
            if(strcmp(av[l],-d)==0) {if(ac3) usage(av); else trued=1; continue;}
            if(truef) { 
                       if(f!=0)
                        {
                        printf(--More--(Next file %s)n,av[l]);
                        d=getchar();
                        if(d=='n'){
                        printf(  n);
                        printf( t %s n,av[l]);
                        printf(  n);}
                        if(d=='q') exit(0);}
                       if(f==0) {
                        printf(  n);
                        printf( t %s n,av[l]);
                        printf(  n);}
                      }
            if(truep) { 
                       if(f!=0) 
                        { 
                        printf(--More--(Next file %s)n,av[l]);
                        d=getchar();
                        system(clear);
                        if(d=='n'){
                        printf(  n);
                        printf( t %s n,av[l]);
                        printf(  n);}
                        if(d=='q') exit(0);}
                       if(f==0) {
                        system(clear);
                        printf(  n);
                        printf( t %s n,av[l]);
                        printf(  n);}
                      }
            if(l1 && f!=0 && !truep && !truef)  printf( --Next file--%sn,av[l]);
            fd = open(av[l],O_RDONLY);
            if (fd == -1)
            perror(open );
            else
                {   nl=0;j=0;f++;
                   while(read(fd,buffer,1)0) { if (buffer[0]=='n') nl++;}
                   perc=(num100)nl;
                   strcpy(buffer,0);
                   lseek(fd,0,SEEK_SET);
                   m=1;nn=1;
                   while((byte_lu=read(fd,buffer,sizeof(buffer)))0)
                         {
                                      k=0;q=0;
                                     for(i=0;ibyte_lu;i++)
                                       { if(buffer[i]!='n')
                                            { strcpy(buffern+k,buffer+i);
                                              k++;
                                              if (nn=nump){buffer3[q]=buffer[i];q++;}
                                            }

                                         else{
                                              nn++;
                                               buffern[k]='n';
                                               buffern[k+1]='0';
                                                if(nn=nump) {buffer3[q]='n';buffer3[q+1]='0';}
                                           if((j)%(num)==0 && j!=0&& (!numpnn=nump))
                                                {
                                                 more -d  
                                                 if(trued){ 
                                               if (percm100)  printf(--More(%d %%)-- entrer  Quitter q,100-((percm)%100));
                                               else printf(--More(%d %%)-- entrer  Quitter q,(percm)%100);
                                                          }
                                                 if(!trued) {
                                               if (percm100)  printf(--More(%d %%)-- ,100-((percm)%100));
                                               else printf(--More(%d %%)-- ,(percm)%100);
                                                        }
                                                   c=getchar();
                                                   if(c=='q') exit(0);
                                                   if(c=='n') j=0;m++;
                                                 }
                                              more +num  
                                             if (nn=nump &&!flg) { write(1,buffer3,strlen(buffer3));}
                                               more -num  
                                             if(!nump && flg)
                                               {write(1,buffern,strlen(buffern));}

                                               strcpy(buffern,0);strcpy(buffer3,0);

                                               j++;
                                               k=0;
                                               q=0;
                                           }
                                     }
                        strcpy(buffer,0);
                        }
             close(fd);
             } fin du else de l'ouverture du fichier
       flg=0;
       }
}

chowns -v -R 
void chowns(int ac, char av[])
{
    uid_t uid;gid_t gid;
    struct passwd pwd,pwd1;
    DIR d;
    struct dirent dp;
    struct stat s,e;
    int i,truev=0,truer=0,tr=0,k,no=0,cher=''; char pat1[30],pat2[60],pro[30],grp[30];
    if(ac2)
    { printf( Usage %s [new_name_utilisateur] [fichier....],av[0]);

            exit(0);}
   if(strchr(av[1],cher)) { tr=1;strcpy(pro,0);strcpy(grp,0);
                              k=0;
                              for(i=0;istrlen(av[1]);i++)
                                       { if(av[1][i]!='')
                                            { strcpy(pro+k,av[1]+i);
                                              k++;
                                            }
                                        if(av[1][i]=='') { pro[k]='0'; break;}
                                       }
                              k=0;
                              i++;pour ne pas prendre les 
                              while(istrlen(av[1])){strcpy(grp+k,av[1]+i);
                                              k++;
                                             i++;}
                              }
 if(tr) {
        pwd=getpwnam(pro);    Essayer de récupérer l'UID de l'utilisateur 
        if (pwd == NULL) {
            perror(Error getpwnam uid );
            exit(0);
        }
    uid = pwd-pw_uid;
       pwd1=getpwnam(grp);
        if (pwd1 == NULL) {
            perror(Error getpwnam gid );
            exit(0);
        }
    gid=pwd1-pw_gid;
     }
if(!tr)
   { pwd = getpwnam(av[1]);    Essayer de récupérer l'UID de l'utilisateur 
        if (pwd == NULL) {
            perror(Error getpwnam);
            exit(0);
        }
    uid = pwd-pw_uid;
    gid=-1;
  }
for(i=2;iac;i++)
{ strcpy(pat1,0); strcpy(pat2,0);
  no=0;
  if(!strcmp(av[i],-R)) {truer=1;continue;}
  if(!strcmp(av[i],-v)) {truev=1;continue;}
  if(truer)
  { stat(av[i],&e);
    if(S_ISDIR(e.st_mode))
    { strcpy(pat1,av[i]); strcat(pat1,);
      if((d=opendir(av[i]))==NULL) {perror( Error de opendir());}
       while((dp=readdir(d))!=NULL)
       {
        stat(dp-d_name,&s);
        if (dp-d_name[0]!='.')
         {
          strcpy(pat2,pat1); strcat(pat2,dp-d_name);
         if(chown(pat2, uid, gid) == -1)
          { printf(chown  changement du propriétaire de ' %s ' opération interdite n,pat2);
            no=1;
          }
         else { if(truev)
                    { if(!tr) {printf(Propriétaire de '%s' est %s  n,pat2,av[1]);}
                      else {printf(Propriétairegroupe  de '%s' est %s%s  n,pat2,pro,grp);}
                    }
              }
         }
        }fin de while
        closedir(d);

        if(no){ printf(chown  changement du propriétaire de ' %s ' opération interditen,av[i]);
                printf( Veuiller sortir (exit) et lancer le shell en mode privilégié sudo -su n);
                exit(0);
              }
         else { if (truev)
                  { if(!tr) printf(Propriétaire de '%s' est %s n,av[i],av[1]);
                     if(tr)  printf(Propriétaire de '%s' est %s %s n,av[i],pro,grp);
                 }
              }
    }  Finn  de if (ISDIR)

    else { printf ( Error ' %s ' is not a directory n,av[i]);exit(0);}

  }fin de option -R

 if(!truer)
     {
      if(chown(av[i], uid,gid) == -1)
       {printf(chown  changement du propriétaire de '%s'  opération interdite (sauf au root),av[i]);
        puts( Entrer en mode Root pour cette opération);
        exit(0);
       }

       else {  if(truev)
                      { if(!tr) printf(Propriétaire de '%s' est %s n,av[i],av[1]);
                         if(tr) printf( chown Success  proprietaire %s et groupe %sn,pro,grp);
                       }
            }
    puts();

    }fin de chown sans option

}
}
sort -norm -n -r -o -c 

struct ligne{
   char MOT[400];
   int in;    };

void tri_select(struct ligne L [600],int n)
{
  Déclarations 
struct ligne AIDE;   chaîne d'aide pour la permutation 
 int I;     rang à partir duquel MOT n'est pas trié 
 int J;     indice courant 
 int PMOT;  indique la position du prochain mot 
            dans la suite lexicographique.        

  Tri du tableau par sélection directe du     
  prochain mot dans la suite lexicographique. 
 for (I=0; In-1; I++)
    {
      Recherche du prochain mot à droite de A[I] 
     PMOT=I;
     for (J=I+1; Jn; J++)
        if (strcasecmp(L[J].MOT,L[PMOT].MOT)  0)
            PMOT=J;
    
       else if(strcasecmp(L[J].MOT,L[PMOT].MOT)==0)
           if (strcmp(L[J].MOT,L[PMOT].MOT)0)
                   PMOT=J;

 Echange des mots 
   AIDE=L[I]; L[I]=L[PMOT];L[PMOT]=AIDE;
              }
 
}


void tri_at(struct ligne L [600],int n)char MOT
{
  Déclarations 
struct ligne AIDE;   chaîne d'aide pour la permutation 
 int I;     rang à partir duquel MOT n'est pas trié 
 int J;     indice courant 
 int PMOT;  indique la position du prochain mot 
            dans la suite lexicographique.        

  Tri du tableau par sélection directe du     
  prochain mot dans la suite lexicographique. 
 for (I=0; In-1; I++)
    {
      Recherche du prochain mot à droite de A[I] 
     PMOT=I;
     for (J=I+1; Jn; J++)
       {  if (atoi(L[J].MOT)  atoi(L[PMOT].MOT) )
           { PMOT=J;}
       }
        AIDE=L[I]; L[I]=L[PMOT];L[PMOT]=AIDE;
    }


}
void aff_b(int ind,struct ligne L[600],int taille)
{ int i;

 for (i=0;itaille;i++)
  if ( L[i].in==ind)
   printf(%s,L[i].MOT);
}

void sort(int n,char av[])
{ char c;
  int s=0,d,J;
  int i = 0,j=0,k,truer=0,truen=0,norm=1,truec=0,trueo=0;
  struct ligne L[600] ; char chaine[4096];
  struct ligne Ln [600],La [600],Ls [600], Lo [600],Lr[600];
  FILE fp;
  
  if( n2 ) { 
     printf( Usage %s [file] [option  -n -r -c -o ] [if -o file],av[0]);
          exit(0);  }
  for (k=1;kn;k++)
  { if (strcmp(av[k],-r)==0) {truer=1; norm=0;}
    if (strcmp(av[k],-o)==0) {trueo=1;        }
    if (strcmp(av[k],-c)==0) {truec=1;         }
    if (strcmp(av[k],-n)==0) {truen=1; norm=0;}
  }
  
    fp = fopen(av[1], r);
 
    if (fp == NULL)
    {
        printf(Impossible to open the filen);
        exit(-1);
    }
  
   
   
        while(( fgets(chaine, sizeof(chaine)-1, fp))!=NULL)
       { 
        chaine[strlen(chaine)-1]='0';
        strcpy(L[i].MOT,chaine);
        L[i].in=i;
        i++;
        }
   fclose (fp);
trie normal (-b -f)
if(norm==1)
{
for(J=0;Ji;J++)

 { 
  c=L[J].MOT[0];
  s=0;
if ( c!=' ' && c!='%' && c!=''&& c!='#' && c!='+' && c!='^' && c!='.' && c!='@' && c!='' && c!='' && c!='!') 
{  Ls[J]=L[J]; continue;} 
if ( c!=' ' c!='%' c!=''  c!='#'  c!='+'  c!='^'  c!='.'  c!='@'  c!=''  c!=''  c!='!') 
  { while((L[J].MOT[s]==' ' L[J].MOT[s]=='%'  L[J].MOT[s]==''L[J].MOT[s]=='#' L[J].MOT[s]=='+'  L[J].MOT[s]=='^' L[J].MOT[s]=='.' L[J].MOT[s]=='@'  L[J].MOT[s]==''  L[J].MOT[s]=='' L[J].MOT[s]=='!' ) ) s++; 
      
       if(sstrlen(L[J].MOT)) 
          {  
               Ls[J].in=L[J].in; 
               for(d=0;dstrlen(L[J].MOT);d++)
                {Ls[J].MOT[d]=L[J].MOT[s];
                     s++; if (s==strlen(L[J].MOT)) break;
                 }
             
          }
      } 
}

tri_select(Ls,i);
if (!truec && trueo==0)
 {
   for(J=0;Ji;J++)
     { aff_b(Ls[J].in,L,i);}
  }
}fin norm
 option  -n ou -r -n 
if (truen)
{
int m=0,num=0,fln=0,fla=0;
for(k=0;ki;k++) 
{ if (!isalpha(L[k].MOT[0]))
   {Ln[num]=L[k]; num++; fln=1;}
  else
   {La[m]=L[k];m++;fla=1;}
}

   
if(fla) 
{ tri_select ( La,m);
  if(fln)
  {
    tri_at(Ln,num);
    for(k=0;knum;k++) { La[m]=Ln[k];m++; }
  }
if(truer==0 && truec==0 && trueo==0) 
  {   
      for (J=0; Jm; J++)
       { printf(%s,La[J].MOT);}
}
}

} fin truen
 option  -r  
if (truer)
{ 
 if(truen==0) 
  {  
    tri_select(L,i);   
   
    for(j=i-1;j=0;j--) 
    {if(trueo==0)printf(%s,L[j].MOT); Lr[i-1-j]=L[j];}
    }
  if (truen==1 )
  { 
    for(j=i-1;j=0;j--)
    { if (trueo==0) printf(%s,La[j].MOT); Lr[i-1-j]=La[j];}
   }
}
 option  -c  
if(truec)
{ for(k=0;ki;k++)
  { if(norm) { if (L[k].in != Ls[k].in) {printf(sort %s%ddisorder %sn,argv[1],L[k].in+1,L[k].MOT); exit(1);}}
   if(truen) { if (L[k].in != La[k].in) {printf(non trié  %sn,L[k].MOT); exit(1);}}
  }

}

 option  -o  
if(trueo==1)
{ int fd1;
  if(norm)  for (k=0;ki;k++) Lo[k] = Ls[k];
  if(truen ) for(k=0;ki;k++) Lo[k] = La[k];
  if(truer && truen==1) for(k=0;ki;k++) Lo[k] = Lr[k];
  if(truer && truen==0)  for (k=0;ki;k++) Lo[k] = Lr[k];
  if( (fd1=open(av[n-1],O_CREATO_TRUNCO_RDWR,0666))==-1)
   {
        printf(Can't open the filen);
        exit(-1);
    }
   for (k=0;ki;k++)
  write(fd1,Lo[k].MOT,strlen(Lo[k].MOT)); 
  close(fd1);
}

}
MAIN  
   int main ()
{               system( clear);puts();
                printf( System programming project Creation of a Minishell  n);
                printf( By  LASRI WAFAE n);
                printf (t   Welcome  n);
                printf( t   The commands accepted in this miniShell are n n);
                printf( t t      cat [options  -n or -E or -b or -T or  (-n -T) ou NAN=by default ] [files]n);
                printf( t t      more [options  -d or -p or -f or -num or +num or (-d et (-p ou -f) with -num or +num) or NAN ]  [file]n);
                printf( t t      chowns [ownergroup] [options  -R or NAN] [fichiers]n);
                printf( t t      sort [file] [options  -n or -r or -c or -o(all options)  or (-n -r)] [if -o file]n);
                printf( t    Warning Please enter ROOT mode sudo su and execute the shell for the chowns command.  n);
                printf( t    Tape 'exit' to exit. nn);
              while (1) {
		    affiche_invite_de_commande();
		    lecture_de_la_ligne();
		    decouper_Saisie();
		    int x=fork();
		    Processus Pére
		    if(x0)
			{
				printf(Error fork);
			   	exit(0);
			}
		    Processus Fils
		    else if(x==0){ 
                               
                                                      
		            if(strcmp(argv[0],cat)==0)
				          cat(argc,argv);
                           else if(strcmp(argv[0],more)==0)
                                          more(argc,argv);
			       else if(strcmp(argv[0],chowns)==0)
		                          chowns(argc,argv);
			       else if(strcmp(argv[0],sort)==0)
				          sort(argc,argv);
				else if(strcmp(argv[0],exit)==0)
				       {
					  kill(x,9);
					}
				else    {
         printf(--------- The command does not existe  Please try again n );
         printf( t  The existing commands in this Mini-Shell are   n );
         printf( t t      cat [options  -n or -E or -b or -T or  (-n -T) or NAN=default ] [files]n);
         printf( t t      more [options  -d or -p or -f or -num or +num or (-d and (-p or -f) with -num or +num) or NAN ]  [files]n);
         printf( t t      chowns [Owner group ] [options  -R or NAN] [files]n);
         printf( t t      sort [file] [options  -n or -r ou -c or -o(all options)  or (-n -r)] [if -o new file]n);
         printf( t    Warning Please enter ROOT mode sudo su and execute the shell for the chowns command n );
         printf( t    Tape 'exit' to exit. nn);

                                        }
			
			}
		  wait(NULL);
		}
	 return 0;
	}
