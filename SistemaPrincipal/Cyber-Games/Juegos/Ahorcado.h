//Learnprogramo-programming made simple
#include<stdio.h>
#include<conio.h>
#include<string.h>



void menuahorcado(tDatosUsuario*);


void menuahorcado(tDatosUsuario*Userahorcado) {

int i,j,c,count=0,ans=0,flag=0,*ptr;
char a[1][10]={"dogodo"};
char b[10],alpha;
char d='_';
c=strlen(&a[0][0]);
//printf("\n\t\t**************\n\n\t\t\t");
printf("\n\n\t\t\t ** AHORCADO** \n");
	printf("\n\t\t\t**************\t\t\t");
		printf("\n\t\t\t..............\n\n\t\t\t  ");
for(j=0;j<c;j++)
	  { printf("%c ",d);
	  b[j]=d;}
	  //printf("\n\n\t\t*****************");
	  printf("\n\n\t\t\t..............\t\t\t");
		printf("\n\n\t\t\t**************");
// for(j=0;j<c;j++) printf("\n %c",b[j]); //{	   ptr=&b[j];
	 //  printf("\n %c",*ptr); }

while (count<6)//||(ans<c))
 {

 flag=0;
	   printf("\n\n\n\n\n\n\t Ingresa un caracter");
		alpha=getche();
	  //	printf("%c",alpha);
		for(i=0;i<c;i++)
		{
			if (alpha==a[0][i])
		   {	b[i]=a[0][i];
		   flag=1;
			ans++; }
			//else if(b[i]!=d) b[i]=a[0][i];
			//else b[i]=d;
		   //	printf("\n u r correct");  }
		   //	if(ans==c) goto man; }
			//printf("\n ans=%d",ans);}

			//printf("\n count=%d",count);

		}

		printf("\n\n\t\t\t ** Ahorcado ** \n");
		printf("\n\t\t\t**************\t\t\t");
		printf("\n\t\t\t..............\n\n\t\t\t  ");
		for(i=0;i<c;i++)
		printf("%c ",b[i]);
		printf("\n\n\t\t\t..............\t\t\t");
		printf("\n\n\t\t\t**************");

		if(flag==0)
		{count++;
		printf("\n\n\n\n\t\t%c Es una entrada incorrecta",alpha);
		printf("\n\n\t\t (Tienes %d intentos mas)",6-count);}

		else{
		printf("\n\n\t\t Correcto!!");
	   printf("\n\t\t( Tienes %d caracteres por ingresar)",c-ans);}
	   //	printf("\n ans=%d",ans);
	   //	printf("\n count=%d",count);
		if(ans==c) break;
 }
 if(ans==c) {printf("\n\n\n\t Ganaste!\n");
			 printf("+3 Puntos\n");
			 Userahorcado->puntos+=3;}
	 
	 
 else {
		printf("\n\n\n\t\t Perdiste\n\n \t\t **Estas ahorcado**");
		Userahorcado->saldo-=1;
		if (Userahorcado->saldo == 0) {
			sleep(1);
			printf("\n\t\t No hay mas saldo!\n");
			sleep(1);
			printf("\n\t\t Volviendo al menu...");}
			


	  /*	if(output[i]!='_')
		output[i]=a[0][i];
		elseif(b[j]==a[0][i])
		output[i]==a[0][i];
		else
		output[i]='_';
		}
		for(i=0;i<c;i++)
		printf("%c",output[i])

 }      */


	}
}


