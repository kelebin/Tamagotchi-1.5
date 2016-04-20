//Programa que simula o Tomagotchi

#include <stdlib.h>
#include <stdio.h>
void mostratoma();
void brincar();
void menu();
void rip();


typedef struct toma {

   char nome[15];
   int saude;
   int fome;
   int felicidade;
   int xp;
}to;


int main ()
{
to toma;
int op;
toma.saude = 100;
toma.fome = 10;
toma.felicidade = 50;
toma.xp = 0;
printf("Bem vindo ao seu Tamagotchi");
printf("\n\n");
printf("\nInforme o nome do seu Tamagotchi\n");
   fgets(toma.nome,50,stdin);
   system("cls");
   
   
   printf("seu tamagotchi esta vivo =D\n");
      while (op!=6){
    
	   mostratoma();

                    printf("\n1 - Mostar status\n");
                    printf("2 - Dar comida\n");
					printf("3 - Brincar\n");
					printf("4 - Dar remedio\n");
					printf("5 - Evoluir\n");
					printf("6 - Sair\n");

          scanf("%d",&op);
          fflush(stdin);
     
     
     
     if(toma.saude==0){
	 rip();
	 
	 }


       switch (op){
	   case 1 : {
	   	   system("cls");
		   printf("Status\n  Nome : %s\n  Saude : %d\n  Fome : %d\n  Felicidade : %d\n",toma.nome,toma.saude,toma.fome,toma.felicidade);
	   	
	   	
		break;
	   } 
	   case 2 :{
		   system("cls");
		   printf("voce alimentou seu tamagotchi");
	
		   toma.fome+=10;
		   if(toma.fome==50){
		   	system("cls");
		   printf("CUIDADO, Seu tamagotchi esta cheio!!!\n");
		   printf("Ele podera ficar doente...");
		   }
		   if(toma.fome==100){
		       printf("seu tamagotchi esta Doente!!!\n");
		       printf("RAPIDO de o remedio ao seu tamagotchi...");
		   toma.saude-=50;
		   }
		   if(toma.fome==110){
		   toma.saude-=50;  
		  
		   }	
		break;
}
	   case 3:{
		
		brincar();
		toma.felicidade+=10;
		
		break;
		
	   }
	   	case 4:{
	   		system("cls");
	   		printf("Voce deu remedio ao seu tamagotchi, ele nao esta mais doente");
	   		toma.saude+=50;
	   		toma.fome=0;
			break;
		   }
		case 5:{ 
		       system("cls");
			   if(toma.xp <50){
               printf("Seu tamagotchi ainda nao esta pronto para evoluir :(\n");			
 		}
			break;
		}   
		   
		   
		     
	   default:{return 0;
		break;
	   }
	  	   
	   }

}

return 0;
}

void mostratoma(){
printf("\n\n");

printf(" |   |\n");
printf("( -.- )\n");
printf("o__(')(')\n");
printf("\n\n");



}


void brincar(){
to toma;
int num,i;

system("cls");

printf("\nPedra Papel ou Tesoura\n");
printf("1-Pedra\n2-Papel\n3-Tesoura\n4-Sair\n"); 
scanf("%d",&num);
switch (num){
case 1:{
	system("cls");
	i=1+(rand() %2);
	printf("Voce jogou Pedra\n");
    
    if (i==1){
	printf("O tamagotchi jogou Pedra\nEMPATE!!!");
	}
	if (i==2){
	printf("O tamagotchi jogou Papel\nVoce Perdeu!!!");
	}
	if(i==3){
	printf("O tamagotchi jogou Tesoura\nVoce Venceu!!!");	
	}
	break;
}
case 2:{
		system("cls");
		i=1+(rand() %2);
	printf("Voce jogou Papel\n");
    
    if (i==1){
	printf("O tamagotchi jogou Pedra\nVoce Venceu!!!");
	}
	if (i==2){
	printf("O tamagotchi jogou Papel\nEmpate");
	}
	if(i==3){
	printf("O tamagotchi jogou Tesoura\nVoce Perdeu!!!");	
	}
	break;
}

case 3:{
	    system("cls");
		i=1+(rand() %2);
	printf("Voce jogou Tesoura\n");
    
    if (i==1){
	printf("O tamagotchi jogou Pedra\nVoce Perdeu!!!");
	}
	if (i==2){
	printf("O tamagotchi jogou Papel\nVoce Venceu!!!");
	}
	if(i==3){
	printf("O tamagotchi jogou Tesoura\nEMPATE!!!");	
	}
	break;
}
case 4:{
	break;
}
}
}

void rip (){
system("cls");
printf("Seu tamagotchi MORREU!!!\n");
printf("RIP\n");
printf("GAME OVER");
exit(0);
}

