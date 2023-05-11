#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <dos.h>
#define N 10
#define row 10
#define column 10;


//raccolta statistiche in fase di estrazione

void color(int x);

void color(int x){

    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, x);

  /*color(1);  BLU SCURO
    color(2);  VERDE SCURO
    color(3);  AZZURRO
    color(4);  ROSSO SCURO
    color(5);  VIOLA
    color(6);  ORO
    color(7);  BIANCO
    color(8);  GRIGIO
    color(9);  BLU
    color(10); VERDE
    color(11); CIANO
    color(12); ROSSO
    color(13); ROSA
    color(14); GIALLO
    color(15); BIANCO */

}

int main(){
       COORD d;
       COORD c;
    c.X = 35;
    c.Y = 12;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
    color(15);printf("10 e Lotto");
    sleep(4);(system("cls"));
    color(4);printf("Premere qualsiasi tasto per iniziare\n");
    getch();
    system("cls");

    int vet[N], num;
    int punt;
    int risposta;
    int continua;



    do{
        do{
            color(14);printf("Selezione modalita':\n");
            color(15);printf("1)Esegui il programma\n2)Esci dal programma\n\n(Qualsiasi altro input sara' ritenuto non valido)\n");
            scanf("%d",&risposta);

            if(risposta!=1 && risposta!=2){
                color(4);printf("\nInput non valido\n");
            }
        }while(risposta!=1 && risposta!=2);

        switch(risposta){
            case 1:
                do{
                    color(3); printf("Inserire la puntata-->");
                    color(15);scanf("%d",&punt);
                    if(punt<=0 || punt>200){
                        color(4); printf("Da un minimo di 1 euro ad un massimo di 200\n");
                    }
                }while(punt<=0 || punt>200);

                printf("\n");

                do{
                    color(3); printf("Quanti numeri vuoi giocare?\n");
                    color(15);scanf("%d", &num);
                    if(num<=0 || num>10){
                        color(4);printf("\a(Da un minimo di 1 ad un massimo di 10)\n");
                    }
                }while(num<=0 || num>10);

                    // INSERIMENTO NUMERI DA GIOCARE SENZA DUPLICATI
                    for(int i=0; i<num; i++){
                        int isDuplicato = 0;
                        int input;
                        color(3);  printf("Inserisci il numero da giocare: \n ");
                        color(15); scanf("%d", &input);
                        for(int j=0;j<i && isDuplicato==0;j++){
                            if(input==vet[j]){
                                isDuplicato=1;
                            }
                        }

                        if(input<1 || input>90){
                            color(4);printf("\a(da un minimo di 1 a un massimo di 90)\n");
                            i--;
                        }else if(isDuplicato==1){
                            color(4);printf("\aNumero gia' inserito! Inserisci un numero diverso\n");
                            i--;
                        }else{
                            vet[i]=input;
                        }
                    }

                    color(14);printf("\nI numeri giocati sono quindi:\n");
                    for(int i=0;i<num;i++){
                        color(15);printf("%d\n",vet[i]);
                    }


                int tmp;
                int flag;
                int esito[20];
                int num_estratti=0;
                int ritry=1;
                int del=1;
                int colore=15;
                printf("\n\n");
                srand(time(NULL));
                    for(int i=1;i<90;i+=10){
                        for(int j=0;j<10;j++){
                            printf("%4d ",i+j);
                        }
                    printf("\n");
                    }
                    printf("\n\n");

                color(4); printf("I numeri estratti sono:\n");


                //GENERAZIONE NUMERI USCITI
                for(int i=0;i<20;i++){
                    do{
                        flag=0;
                        tmp=1+rand()%90;
                        if(i==0){
                            esito[i]=tmp;
                        }else{
                            for(int j=0;j<i;j++){
                                if(tmp==esito[j]){
                                    flag=1;
                                }
                                if(flag==0){
                                    esito[i]=tmp;
                                }
                            }
                        }
                    }while(flag==1);
                    colore=15;
                }

                for(int i=0;i<20;i++){
                    ritry=1;
                    for(int j=0;j<num && ritry==1;j++){
                        //Permette la stampa verde se il numero estratto è uguale a quello giocato altrimenti stampa bianco
                        if(vet[j]==esito[i]){
                            colore=10;
                            ritry=0;
                        }else{
                            colore=15;
                        }
                    }
                    if(colore==10){
                        sleep(del);
                        color(colore);
                        num_estratti++;
                        printf("%d  ",esito[i]);

                    }else{
                        sleep(del);
                        color(colore);
                        printf("%d  ",esito[i]);
                    }
                }

                d.X=35;
                d.Y=15;
                sleep(4);system("cls");
                SetConsoleCursorPosition(
                GetStdHandle(STD_OUTPUT_HANDLE), d);
                color(15);printf("...");
                sleep(4);system("cls");

                //CALCOLO DELLA VINCITA
                if(num==1){
                    if(num_estratti==1){
                        color(10);printf("Ha vinto %d euro,ritirare il premo nella tabaccheria più vicina.\n",punt+2);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci");
                    }else{
                        color(15);printf("Grazie per aver giocato,buona giornata!");
                    }
                }
                if(num==2){
                    if(num_estratti==2){
                        color(10); printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicinina.\n",punt+13);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci");
                    }else{
                        color(15);printf("Grazie per aver giocato,buona giornata!");
                    }
                }
                if(num==3){
                    if(num_estratti==2){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+1);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");

                    }else if(num_estratti==3){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+43);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");

                    }else{
                        color(15);printf("Grazie per aver giocato,buona giornata!");
                    }

                }
                if(num==4){
                    if(num_estratti==2){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==3){
                        color(10); printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+9);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==4){
                        color(10); printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+89);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else{
                        color(15);printf("Grazie per aver giocato,buona giornata!");
                    }
                }
                if(num==5){
                    if(num_estratti==2){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==3){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+3);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==4){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nela tabaccheira piu' vicina.\n",punt+14);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==5){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+139);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci1");
                    }
                    else{
                        printf("Grazie per aver giocato,buona giornata!");
                    }
                }
                if(num==6){
                    if(num_estratti==3){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+1);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==4){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+9);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");

                    }
                    else if(num_estratti==5){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+99);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==6){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+999);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else{
                        color(15);printf("Grazie per aver giocato,buona giornata!");
                    }
                }
                if(num==7){
                    if(num_estratti==0){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==4){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+3);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==5){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+39);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                            }
                    else if(num_estratti==6){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+399);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==7){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+1599);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else{
                        color(15);printf("Grazie per aver giocato,buona giornata!");
                    }
                }
                if(num==8){
                    if(num_estratti==0){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==5){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+19);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==6){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina",punt+199);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==7){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+799);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==8){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+9999);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else{
                        color(15);printf("Grazie per aver giocato,buona giornata!");
                    }
                }
                if(num==9){
                    if(num_estratti==0){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+1);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci");
                    }
                    else if(num_estratti==5){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+9);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==6){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+39);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==7){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+399);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==8){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+1999);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==9){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+99999);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else{
                        color(15);printf("Grazie per aver giocato,buona giornata!");
                    }
                }
                if(num==10){
                    if(num_estratti==0){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+1);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==5){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+4);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==6){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+14);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==7){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+149);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==8){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+999);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==9){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+19999);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else if(num_estratti==10){
                        color(10);printf("Ha vinto %d euro.Ritirare la vincita nella tabaccheria piu' vicina.\n",punt+999999);
                        sleep(2);system("cls");
                        sleep(2);printf("Arrivederci!");
                    }
                    else{
                        color(15);printf("Grazie per aver giocato,buona giornata!");
                    }
                }
                break;
            case 2:
                break;
        }

        if(risposta!=2){
            color(14);printf("\n\nVuoi continuare?\n");
            color(15);printf("1)Continua\n2)Esci dal programma\n\n(Qualsiasi altro input sara' ritenuto non valido)\n");
            scanf("%d",&continua);
        }

    }while(continua==1);

    //CALCOLO MODA MEDIA E MEDIANA BASANDOSI SU



    return 0;
    }
