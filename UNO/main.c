#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>


void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

bool carteValide(char ch[3],char carteTable[3])
{
    bool test=false;
    if(strcmp(ch,"+4")==0 || strcmp(ch,"Jo")==0)
        test=true;
    else if(ch[0]==carteTable[0] || ch[1]==carteTable[1])
        test=true;
    return test;
}
void melangeDeck(char ch[108][3])
{
    int x;
    char aux[3];
    for(int i=0; i<108; i++)
    {
        srand(time(NULL));
        x=rand()%108;

        strcpy(aux,ch[i]);
        strcpy(ch[i],ch[x]);
        strcpy(ch[x],aux);
    }
}

void removeCarte(char ch[3],char deckjoueur[108][3],int n)
{
    char aux[3];
    int i=0;
    bool b=false;
    while(i<n && !b)
    {
        if(strcmp(ch,deckjoueur[i])==0)
        {
            b=true;
            strcpy(deckjoueur[i],"**");
            strcpy(aux,deckjoueur[n-1]);
            strcpy(deckjoueur[n-1],deckjoueur[i]);
            strcpy(deckjoueur[i],aux);

        }
        i++;
    }
}
bool carteExiste(char ch[3],char deckjoueur[108][3],int n)
{
    int i=0;
    bool test=false;

    while(i<n && !test)
    {
        if(strcmp(ch,"+4")==0 || strcmp(ch,"Jo")==0)
            test=true;
        else if(ch[0]==deckjoueur[i][0] && ch[1]==deckjoueur[i][1])
            test=true;
        i++;
    }
    return test;
}
int main()
{
    int manche=0;
    bool testpasse1=true,testpasse2=true;
    int scoreJ1=0;
    int scoreJ2=0;
    int tour=1;
    char ch1[3];
    char ch2[3];
    int i,x,choix;
    int TailleDeck1=7,TailleDeck2=7;
    char NomJoueur1[30], NomJoueur2[30];
    char DeckJ1[108][3];
    char DeckJ2[108][3];
    char couleur1,couleur2;
    char Uno[108][3]= {"9v","5b","2r","9b","6b","+4","+4","Ir","Bj","5r","pr","3j","Ij","Bb","pj","Iv","8b","7j","0j","7v","Bv","3j","Bb","2j","4r","9j","4j","4v","3r","4v","8j","9r","1b","pv","Ib","2v","8b","5v","1r","7b","3b","8v","5r","8r","1j","7b","7r","Jo","4b","9v","0r","Jo","9r","6b","pr","4b","7v","2j","Ij","5v","Jo","8j","1r","7j","0b","5j","1b","Ib","+4","8r","7r","2b","pb","Jo","0v","pv","3v","9b","Iv","5j","3r","3v","1v","8v","+4","6j","4r","Br","2r","6r","1j","6v","pj","5b","2b","2v","Ir","6v","Bj","pb","3b","6j","4j","6r","Br","1v","Bv","9j"};
    clock_t t1;
    printf(" ************************************************************************ \n");
    printf(" ************************************************************************ \n");
    printf(" ************************************************************************ \n");
    printf("\n");
    printf(" ************************** Bienvenue au Jeu UNO ************************ \n");
    printf("\n");
    printf(" ************************************************************************ \n");
    printf(" ************************************************************************ \n");
    printf(" ************************************************************************ \n");
    printf("\n");
    printf("-------------------- Veuillez choisir le mode de jeu : -------------------\n");
    printf("\n");
    printf("                   Tapez 1 pour jouer contre la machine\n\n");
    printf("                   Tapez 2 pour jouer contre un joueur \n\n");
    printf("                          Tapez 3 pour Quitter\n");
    scanf("%d",&choix);
    system("cls");
    do
    {
        if (choix==1)
        {
            printf(" ************************************************************************ \n\n");
            printf(" ************************************************************************ \n\n");
            printf("                  Vous avez choisi de jouer contre la machine\n\n");
            printf("                           Tapez votre nom :\n\n");
            scanf("%s",NomJoueur1);
            printf(" ************************************************************************ \n\n");
            printf("                              Bienvenue %s\n\n",NomJoueur1);
            printf(" ************************************************************************ \n\n");
        }
        if  (choix==2)
        {
            printf(" ************************************************************************ \n\n");
            printf(" ************************************************************************ \n\n");
            printf("                   Vous avez choisi de jouer contre un joueur\n\n");
            printf("                        Joueur 1 Tapez votre nom :\n\n");
            scanf("%s", NomJoueur1);
            printf("\n");
            printf("                        Joueur 2 Tapez votre nom :\n");
            scanf("%s", NomJoueur2);
            printf("                               GET READY\n");
            sleep(1);
            printf("                                 SET\n");
            sleep(1);
            printf("                                GO!!!!!\n\n");
            sleep(1);
            printf(" ************************************************************************ \n");
            printf(" ************************************************************************ \n\n");
            printf("                               %s VS %s\n\n",NomJoueur1,NomJoueur2);
            printf(" ************************************************************************ \n");
            printf(" ************************************************************************ \n\n");
        }

    }
    while ((choix!=1)&&(choix!=2)&&(choix!=3)) ;

    switch(choix)
    {
    case 1:
    {
        manche=0;
        char reponse;
        do
        {
            manche++;
            if(manche>=2)
            {
                do
                {
                    printf("Voulez vous rejouer? si Oui tapez (O) sinon tapez (N)\n");
                    scanf("%c",&reponse);
                    fflush(stdin);
                }
                while(tolower(reponse)!='o'&&tolower(reponse)!='n');
            }
            melangeDeck(Uno);
            printf("\n");
            //joueur 1 remplicage de deck et remplzcer les carte utuliser par *
            printf("Le deck de %s:\n\n",NomJoueur1);
            for (i=0; i<TailleDeck1; i++)
            {
                do
                {
                    srand(time(NULL));
                    x=(rand()%108);
                }
                while(strcmp(Uno[x],"**")==0);
                strcpy(DeckJ1[i],Uno[x]);
                strcpy(Uno[x],"**");
            }
            //printf(" __ __ __ __ __ __ __");
            printf(" -- -- -- -- -- -- --");
            printf("\n|");
            for(i=0; i<TailleDeck1; i++)
            {
                switch (DeckJ1[i][1])
                {
                case 'r':
                {
                    Color(0,12);
                    break;
                }
                case 'v':
                {
                    Color(0,10);
                    break;
                }
                case 'b':
                {
                    Color(0,11);
                    break;
                }
                case 'j':
                {
                    Color(0,14);
                    break;
                }
                default:
                {
                    Color(0,7);
                    break;
                }
                }
                printf("%s",DeckJ1[i]);
                printf("|");
            }
            Color(15,0);
            printf("\n -- -- -- -- -- -- --\n");
            printf("\n");
            //joueur 2 remplissage de deck et remplacer les cartes utulisees par *
            //printf("Le deck de la machine :\n\n");
            for (i=0; i<TailleDeck2; i++)
            {
                do
                {
                    srand(time(NULL));
                    x=(rand()%108);
                }
                while(strcmp(Uno[x],"**")==0);
                strcpy(DeckJ2[i],Uno[x]);
                strcpy(Uno[x],"**");
            }
            /*printf(" -- -- -- -- -- -- --");
            printf("\n|");
            for(i=0; i<TailleDeck2; i++)
            {
                switch (DeckJ2[i][1])
                {
                case 'r':
                {
                    Color(0,12);
                    break;
                }
                case 'v':
                {
                    Color(0,10);
                    break;
                }
                case 'b':
                {
                    Color(0,11);
                    break;
                }
                case 'j':
                {
                    Color(0,14);
                    break;
                }
                default:
                {
                    Color(0,7);
                    break;
                }
                }
                printf("%s",DeckJ2[i]);
                printf("|");
            }
            Color(15,0);*/
            //printf("\n -- -- -- -- -- -- --\n\n");
            //carte sur table (carte simple)
            do
            {
                srand(time(NULL));
                x=(rand()%108);
            }
            while((strcmp(Uno[x],"**")==0)||(strcmp(Uno[x],"+4")==0)||(strcmp(Uno[x],"Jo")==0)||(Uno[x][0]=='I')||(Uno[x][0]=='B')||(Uno[x][0]=='p'));
            char carte[3];
            strcpy(carte,Uno[x]);
            strcpy(Uno[x],"**");
            printf("La carte sur table : ");
            switch (carte[1])
            {
            case 'r':
            {
                Color(0,12);
                break;
            }
            case 'v':
            {
                Color(0,10);
                break;
            }
            case 'b':
            {
                Color(0,11);
                break;
            }
            case 'j':
            {
                Color(0,14);
                break;
            }
            default:
            {
                Color(0,7);
                break;
            }
            }
            printf("%s",carte);
            Color(15,0);
            printf("\n\n");
            do
            {
                //tour de joueur 1
                do
                {

                    if(!testpasse1)
                        tour=2;
                    testpasse2=true;
                    do
                    {
                        printf("%s place une carte :\n",NomJoueur1);
                        scanf("%s",ch1);
                    }
                    while((!carteExiste(ch1,DeckJ1,TailleDeck1) || !carteValide(ch1,carte)) && strcmp(ch1,"0")!=0);
                    ch1[1]=tolower(ch1[1]);
                    i=0;
                    if(strcmp(ch1,"0")==0 && testpasse1)
                    {
                        do
                        {
                            srand(time(NULL));
                            x=(rand()%108);
                        }
                        while(strcmp(Uno[x],"**")==0);
                        strcpy(DeckJ1[TailleDeck1],Uno[x]);
                        TailleDeck1++;
                        testpasse1=false;
                    }
                    else if(strcmp(ch1,"+4")==0)
                    {
                        scoreJ1+=50;
                        removeCarte(ch1,DeckJ1,TailleDeck1);
                        TailleDeck1--;
                        strcpy(carte,ch1);
                        for(i=0; i<4; i++)
                        {
                            do
                            {
                                srand(time(NULL));
                                x=(rand()%108);
                            }
                            while(strcmp(Uno[x],"**")==0);
                            strcpy(DeckJ2[TailleDeck2],Uno[x]);
                            TailleDeck2++;
                            melangeDeck(Uno);
                        }
                        printf("Veuillez choisir une couleur (r) pour rouge (v) pour vert (b) pour bleu (j) pour jaune\n");
                        fflush(stdin);
                        scanf("%c",&couleur1);
                        carte[1]=tolower(couleur1);
                        //printf("Le nouveau deck de %s apres +4\n",NomJoueur2);
                        /*printf(" -- -- -- -- -- -- --");
                        printf("\n|");
                        for(i=0; i<TailleDeck2; i++)
                        {
                            switch (DeckJ2[i][1])
                            {
                            case 'r':
                            {
                                Color(0,12);
                                break;
                            }
                            case 'v':
                            {
                                Color(0,10);
                                break;
                            }
                            case 'b':
                            {
                                Color(0,11);
                                break;
                            }
                            case 'j':
                            {
                                Color(0,14);
                                break;
                            }
                            default:
                            {
                                Color(0,7);
                                break;
                            }
                            }
                            printf("%s",DeckJ2[i]);
                            printf("|");
                        }
                        Color(15,0);
                        printf("\n -- -- -- -- -- -- --\n\n");*/
                    }
                    else if(strcmp(ch1,"Jo")==0)
                    {
                        scoreJ1+=50;
                        removeCarte(ch1,DeckJ1,TailleDeck1);
                        TailleDeck1--;
                        strcpy(carte,ch1);
                        tour=2;
                        printf("Veuillez choisir une couleur (r) pour rouge (v) pour vert (b) pour bleu (j) pour jaune\n");
                        fflush(stdin);
                        scanf("%c",&couleur1);
                        carte[1]=tolower(couleur1);
                    }
                    else if(toupper(ch1[0])=='B')
                    {
                        scoreJ1+=20;
                        removeCarte(ch1,DeckJ1,TailleDeck1);
                        TailleDeck1--;
                        strcpy(carte,ch1);
                    }
                    else if(toupper(ch1[0])=='I')
                    {
                        scoreJ1+=20;
                        removeCarte(ch1,DeckJ1,TailleDeck1);
                        TailleDeck1--;
                        strcpy(carte,ch1);
                    }
                    else if(tolower(ch1[0])=='p')
                    {
                        scoreJ1+=20;
                        removeCarte(ch1,DeckJ1,TailleDeck1);
                        TailleDeck1--;
                        strcpy(carte,ch1);
                        for(i=0; i<2; i++)
                        {
                            do
                            {
                                srand(time(NULL));
                                x=(rand()%108);
                            }
                            while(strcmp(Uno[x],"**")==0);
                            strcpy(DeckJ2[TailleDeck2],Uno[x]);
                            TailleDeck2++;
                            melangeDeck(Uno);
                        }
                        //printf("Le nouveau deck de %s apres +2\n",NomJoueur2);
                        //for(i=0; i<TailleDeck2; i++)
                        //printf("%s\n",DeckJ2[i]);
                    }
                    else
                    {
                        scoreJ1+=(ch1[0]-48);
                        removeCarte(ch1,DeckJ1,TailleDeck1);
                        TailleDeck1--;
                        strcpy(carte,ch1);
                        tour=2;
                    }
                    printf("Nouveau deck de %s :\n",NomJoueur1);
                    printf(" -- -- -- -- -- -- --");
                    printf("\n|");
                    for(i=0; i<TailleDeck1; i++)
                    {
                        switch (DeckJ1[i][1])
                        {
                        case 'r':
                        {
                            Color(0,12);
                            break;
                        }
                        case 'v':
                        {
                            Color(0,10);
                            break;
                        }
                        case 'b':
                        {
                            Color(0,11);
                            break;
                        }
                        case 'j':
                        {
                            Color(0,14);
                            break;
                        }
                        default:
                        {
                            Color(0,7);
                            break;
                        }
                        }
                        printf("%s",DeckJ1[i]);
                        printf("|");
                    }
                    Color(15,0);
                    printf("\n -- -- -- -- -- -- --\n");
                    printf("La carte sur la table : ");
                    switch (carte[1])
                    {
                    case 'r':
                    {
                        Color(0,12);
                        break;
                    }
                    case 'v':
                    {
                        Color(0,10);
                        break;
                    }
                    case 'b':
                    {
                        Color(0,11);
                        break;
                    }
                    case 'j':
                    {
                        Color(0,14);
                        break;
                    }
                    default:
                    {
                        Color(0,7);
                        break;
                    }
                    }
                    printf("%s",carte);
                    Color(15,0);
                    printf("\n\n");
                    char u;
                    if(TailleDeck1==1)
                    {
                        srand(time(NULL));
                        printf("Tapez (U) pour dire UNO\n");
                        scanf("%c",&u);
                        fflush(stdin);
                        if (t1>3)
                            tour==2;
                    }
                }
                while(tour==1);
                //tour de machine
                do
                {
                    if(!testpasse2)
                        tour=1;
                    testpasse1=true;
                    bool testpiocher=false;
                    for(int f=0; f<TailleDeck2; f++)
                    {
                        i=0;
                        if(strcmp(DeckJ2[f],"+4")==0 && carteValide(DeckJ2[f],carte))
                        {
                            testpiocher=true;
                            scoreJ2+=50;
                            removeCarte(DeckJ2[f],DeckJ2,TailleDeck2);
                            TailleDeck2--;
                            strcpy(carte,DeckJ2[f]);
                            for(i=0; i<4; i++)
                            {
                                do
                                {
                                    srand(time(NULL));
                                    x=(rand()%108);
                                }
                                while(strcmp(Uno[x],"**")==0);
                                strcpy(DeckJ1[TailleDeck1],Uno[x]);
                                TailleDeck1++;
                                melangeDeck(Uno);
                            }
                            printf("Veuillez choisir une couleur (r) pour rouge (v) pour vert (b) pour bleu (j) pour jaune\n");
                            fflush(stdin);
                            scanf("%c",&couleur2);
                            carte[1]=tolower(couleur2);
                            printf("Le nouveau deck de %s apres +4\n",NomJoueur1);
                            printf(" -- -- -- -- -- -- --");
                            printf("\n|");
                            for(i=0; i<TailleDeck1; i++)
                            {
                                switch (DeckJ1[i][1])
                                {
                                case 'r':
                                {
                                    Color(0,12);
                                    break;
                                }
                                case 'v':
                                {
                                    Color(0,10);
                                    break;
                                }
                                case 'b':
                                {
                                    Color(0,11);
                                    break;
                                }
                                case 'j':
                                {
                                    Color(0,14);
                                    break;
                                }
                                default:
                                {
                                    Color(0,7);
                                    break;
                                }
                                }
                                printf("%s",DeckJ1[i]);
                                printf("|");
                            }
                            Color(15,0);
                            printf("\n -- -- -- -- -- -- --\n");
                            printf("\n");
                            break;
                        }
                        else if(strcmp(DeckJ2[f],"Jo")==0 && carteValide(DeckJ2[f],carte))
                        {
                            testpiocher=true;
                            scoreJ2+=50;
                            removeCarte(DeckJ2[f],DeckJ2,TailleDeck2);
                            TailleDeck2--;
                            strcpy(carte,DeckJ2[f]);
                            tour=1;
                            printf("Veuillez choisir une couleur (r) pour rouge (v) pour vert (b) pour bleu (j) pour jaune\n");
                            fflush(stdin);
                            scanf("%c",&couleur2);
                            carte[1]=tolower(couleur2);
                            break;
                        }
                        else if(DeckJ2[f][0]=='B' && carteValide(DeckJ2[f],carte))
                        {
                            testpiocher=true;
                            scoreJ2+=20;
                            removeCarte(DeckJ2[f],DeckJ2,TailleDeck2);
                            TailleDeck2--;
                            strcpy(carte,DeckJ2[f]);
                            break;
                        }
                        else if(DeckJ2[f][0]=='I' && carteValide(DeckJ2[f],carte))
                        {
                            testpiocher=true;
                            scoreJ2+=20;
                            removeCarte(DeckJ2[f],DeckJ2,TailleDeck2);
                            TailleDeck2--;
                            strcpy(carte,DeckJ2[f]);
                            break;
                        }
                        else if(DeckJ2[f][0]=='p' && carteValide(DeckJ2[f],carte))
                        {
                            testpiocher=true;
                            scoreJ2+=20;
                            removeCarte(DeckJ2[f],DeckJ2,TailleDeck2);
                            TailleDeck2--;
                            strcpy(carte,DeckJ2[f]);
                            for(i=0; i<2; i++)
                            {
                                do
                                {
                                    srand(time(NULL));
                                    x=(rand()%108);
                                }
                                while(strcmp(Uno[x],"**")==0);
                                strcpy(DeckJ1[TailleDeck1],Uno[x]);
                                TailleDeck1++;
                                melangeDeck(Uno);
                            }
                            printf("Le nouveau deck de %s apres +2\n",NomJoueur1);
                            printf(" -- -- -- -- -- -- --");
            printf("\n|");
            for(i=0; i<TailleDeck1; i++)
            {
                switch (DeckJ1[i][1])
                {
                case 'r':
                {
                    Color(0,12);
                    break;
                }
                case 'v':
                {
                    Color(0,10);
                    break;
                }
                case 'b':
                {
                    Color(0,11);
                    break;
                }
                case 'j':
                {
                    Color(0,14);
                    break;
                }
                default:
                {
                    Color(0,7);
                    break;
                }
                }
                printf("%s",DeckJ1[i]);
                printf("|");
            }
            Color(15,0);
            printf("\n -- -- -- -- -- -- --\n");
            printf("\n");
                            break;
                        }
                        else if(carteValide(DeckJ2[f],carte))
                        {
                            testpiocher=true;
                            scoreJ2+=(DeckJ2[f][0]-48);
                            removeCarte(DeckJ2[f],DeckJ2,TailleDeck2);
                            TailleDeck2--;
                            strcpy(carte,DeckJ2[f]);
                            tour=1;
                            break;
                        }

                    }
                    if(!testpiocher && testpasse2)
                    {
                        do
                        {
                            srand(time(NULL));
                            x=(rand()%108);
                        }
                        while(strcmp(Uno[x],"**")==0);
                        strcpy(DeckJ2[TailleDeck2],Uno[x]);
                        TailleDeck2++;
                        printf("La machine a pioch%c une carte\n",130);
                        testpasse2=false;
                    }
                    /*printf("Nouveau deck de la machine \n");
                    printf(" -- -- -- -- -- -- --");
                    printf("\n|");
                    for(i=0; i<TailleDeck2; i++)
                    {
                        switch (DeckJ2[i][1])
                        {
                        case 'r':
                        {
                            Color(0,12);
                            break;
                        }
                        case 'v':
                        {
                            Color(0,10);
                            break;
                        }
                        case 'b':
                        {
                            Color(0,11);
                            break;
                        }
                        case 'j':
                        {
                            Color(0,14);
                            break;
                        }
                        default:
                        {
                            Color(0,7);
                            break;
                        }
                        }
                        printf("%s",DeckJ2[i]);
                        printf("|");
                    }
                    Color(15,0);
                    printf("\n -- -- -- -- -- -- --\n\n");*/
                    printf("\nLa carte sur la table : ");
                    switch (carte[1])
                    {
                    case 'r':
                    {
                        Color(0,12);
                        break;
                    }
                    case 'v':
                    {
                        Color(0,10);
                        break;
                    }
                    case 'b':
                    {
                        Color(0,11);
                        break;
                    }
                    case 'j':
                    {
                        Color(0,14);
                        break;
                    }
                    default:
                    {
                        Color(0,7);
                        break;
                    }
                    }
                    printf("%s",carte);
                    Color(15,0);
                    printf("\n\n");
                    if(TailleDeck2==1)
                    {
                        printf("UNO\n");
                    }
                }
                while(tour==2);
            }
            while(TailleDeck1!=0 && TailleDeck2!=0);
            break;
            break;
        }
        while(manche<2 || reponse=='O');
    }
    case 2:
    {
        manche=0;
        char reponse;
        do
        {
            manche++;
            if(manche>=2)
            {
                do
                {
                    printf("Voulez vous rejouer? Si oui tapez (O) sinon tapez (N)");
                    scanf("%c",&reponse);
                    fflush(stdin);
                }
                while(tolower(reponse)!='o'&&tolower(reponse)!='n');
            }
            melangeDeck(Uno);
            printf("\n");
            //joueur 1 remplissage de deck et remplacer les carte utulisees par *
            printf("Le deck de %s:\n",NomJoueur1);
            for (i=0; i<TailleDeck1; i++)
            {
                do
                {
                    srand(time(NULL));
                    x=(rand()%108);
                }
                while(strcmp(Uno[x],"**")==0);
                strcpy(DeckJ1[i],Uno[x]);
                strcpy(Uno[x],"**");
            }
            printf(" -- -- -- -- -- -- --");
            printf("\n|");
            for(i=0; i<TailleDeck1; i++)
            {
                switch (DeckJ1[i][1])
                {
                case 'r':
                {
                    Color(0,12);
                    break;
                }
                case 'v':
                {
                    Color(0,10);
                    break;
                }
                case 'b':
                {
                    Color(0,11);
                    break;
                }
                case 'j':
                {
                    Color(0,14);
                    break;
                }
                default:
                {
                    Color(0,7);
                    break;
                }
                }
                printf("%s",DeckJ1[i]);
                printf("|");
            }
            Color(15,0);
            printf("\n -- -- -- -- -- -- --\n\n");
            //affDeck(DeckJ1);
            printf("\n");
            //joueur 2 remplissage de deck et remplacer les cartes utulisees par *
            printf("Le deck de %s :\n",NomJoueur2);
            for (i=0; i<TailleDeck2; i++)
            {
                do
                {
                    srand(time(NULL));
                    x=(rand()%108);
                }
                while(strcmp(Uno[x],"**")==0);
                strcpy(DeckJ2[i],Uno[x]);
                strcpy(Uno[x],"**");
            }
            printf(" -- -- -- -- -- -- --");
            printf("\n|");
            for(i=0; i<TailleDeck2; i++)
            {
                switch (DeckJ2[i][1])
                {
                case 'r':
                {
                    Color(0,12);
                    break;
                }
                case 'v':
                {
                    Color(0,10);
                    break;
                }
                case 'b':
                {
                    Color(0,11);
                    break;
                }
                case 'j':
                {
                    Color(0,14);
                    break;
                }
                default:
                {
                    Color(0,7);
                    break;
                }
                }
                printf("%s",DeckJ2[i]);
                printf("|");
            }
            Color(15,0);
            printf("\n -- -- -- -- -- -- --\n\n");
            //carte sur table (carte simple)
            do
            {
                srand(time(NULL));
                x=(rand()%108);
            }
            while((strcmp(Uno[x],"**")==0)||(strcmp(Uno[x],"+4")==0)||(strcmp(Uno[x],"Jo")==0)||(Uno[x][0]=='I')||(Uno[x][0]=='B')||(Uno[x][0]=='p'));
            char carte[3];
            strcpy(carte,Uno[x]);
            strcpy(Uno[x],"**");
            printf("La carte sur table : ");
            switch (carte[1])
            {
            case 'r':
            {
                Color(0,12);
                break;
            }
            case 'v':
            {
                Color(0,10);
                break;
            }
            case 'b':
            {
                Color(0,11);
                break;
            }
            case 'j':
            {
                Color(0,14);
                break;
            }
            default:
            {
                Color(0,7);
                break;
            }
            }
            printf("%s",carte);
            Color(15,0);
            printf("\n\n");
            printf("\n");
            do
            {
                //tour de joueur 1
                do
                {
                    do
                    {
                        printf("%s place une carte (tapez 0 pour piocher):\n",NomJoueur1);
                        scanf("%s",ch1);
                    }
                    while((!carteExiste(ch1,DeckJ1,TailleDeck1) || !carteValide(ch1,carte)) && strcmp(ch1,"0")!=0 );
                    ch1[1]=tolower(ch1[1]);
                    i=0;
                    //
                    if(strcmp(ch1,"0")==0)
                    {
                        do
                        {
                            srand(time(NULL));
                            x=(rand()%108);
                        }
                        while(strcmp(Uno[x],"**")==0);
                        strcpy(DeckJ1[TailleDeck1],Uno[x]);
                        TailleDeck1++;
                    }
                    else if(strcmp(ch1,"+4")==0)
                    {
                        scoreJ1+=50;
                        removeCarte(ch1,DeckJ1,TailleDeck1);
                        TailleDeck1--;
                        strcpy(carte,ch1);
                        for(i=0; i<4; i++)
                        {
                            do
                            {
                                srand(time(NULL));
                                x=(rand()%108);
                            }
                            while(strcmp(Uno[x],"**")==0);
                            strcpy(DeckJ2[TailleDeck2],Uno[x]);
                            TailleDeck2++;
                            melangeDeck(Uno);
                        }
                        printf("Veuillez choisir une couleur (r) pour rouge (v) pour vert (b) pour bleu (j) pour jaune\n");
                        fflush(stdin);
                        scanf("%c",&couleur1);
                        carte[1]=tolower(couleur1);
                        printf("Le nouveau deck de %s apres +4\n",NomJoueur2);
                        printf(" -- -- -- -- -- -- --");
                        printf("\n|");
                        for(i=0; i<TailleDeck2; i++)
                        {
                            switch (DeckJ2[i][1])
                            {
                            case 'r':
                            {
                                Color(0,12);
                                break;
                            }
                            case 'v':
                            {
                                Color(0,10);
                                break;
                            }
                            case 'b':
                            {
                                Color(0,11);
                                break;
                            }
                            case 'j':
                            {
                                Color(0,14);
                                break;
                            }
                            default:
                            {
                                Color(0,7);
                                break;
                            }
                            }
                            printf("%s",DeckJ2[i]);
                            printf("|");
                        }
                        Color(15,0);
                        printf("\n -- -- -- -- -- -- --\n\n");
                    }
                    else if(strcmp(ch1,"Jo")==0)
                    {
                        scoreJ1+=50;
                        removeCarte(ch1,DeckJ1,TailleDeck1);
                        TailleDeck1--;
                        strcpy(carte,ch1);
                        tour=2;
                        printf("Veuillez choisir une couleur (r) pour rouge (v) pour vert (b) pour bleu (j) pour jaune\n");
                        fflush(stdin);
                        scanf("%c",&couleur1);
                        carte[1]=tolower(couleur1);
                    }
                    else if(toupper(ch1[0])=='B')
                    {
                        scoreJ1+=20;
                        removeCarte(ch1,DeckJ1,TailleDeck1);
                        TailleDeck1--;
                        strcpy(carte,ch1);
                    }
                    else if(toupper(ch1[0])=='I')
                    {
                        scoreJ1+=20;
                        removeCarte(ch1,DeckJ1,TailleDeck1);
                        TailleDeck1--;
                        strcpy(carte,ch1);
                    }
                    else if(tolower(ch1[0])=='p')
                    {
                        scoreJ1+=20;
                        removeCarte(ch1,DeckJ1,TailleDeck1);
                        TailleDeck1--;
                        strcpy(carte,ch1);
                        for(i=0; i<2; i++)
                        {
                            do
                            {
                                srand(time(NULL));
                                x=(rand()%108);
                            }
                            while(strcmp(Uno[x],"**")==0);
                            strcpy(DeckJ2[TailleDeck2],Uno[x]);
                            TailleDeck2++;
                            melangeDeck(Uno);
                        }
                        printf("le nouveau deck de %s apres +2\n",NomJoueur2);
                        printf(" -- -- -- -- -- -- --");
                        printf("\n|");
                        for(i=0; i<TailleDeck2; i++)
                        {
                            switch (DeckJ2[i][1])
                            {
                            case 'r':
                            {
                                Color(0,12);
                                break;
                            }
                            case 'v':
                            {
                                Color(0,10);
                                break;
                            }
                            case 'b':
                            {
                                Color(0,11);
                                break;
                            }
                            case 'j':
                            {
                                Color(0,14);
                                break;
                            }
                            default:
                            {
                                Color(0,7);
                                break;
                            }
                            }
                            printf("%s",DeckJ2[i]);
                            printf("|");
                        }
                        Color(15,0);
                        printf("\n -- -- -- -- -- -- --\n\n");
                    }
                    else
                    {
                        scoreJ1+=(ch1[0]-48);
                        removeCarte(ch1,DeckJ1,TailleDeck1);
                        TailleDeck1--;
                        strcpy(carte,ch1);
                        tour=2;
                    }
                    printf("Nouveau deck de %s :\n",NomJoueur1);
                    printf(" -- -- -- -- -- -- --");
                    printf("\n|");
                    for(i=0; i<TailleDeck1; i++)
                    {
                        switch (DeckJ1[i][1])
                        {
                        case 'r':
                        {
                            Color(0,12);
                            break;
                        }
                        case 'v':
                        {
                            Color(0,10);
                            break;
                        }
                        case 'b':
                        {
                            Color(0,11);
                            break;
                        }
                        case 'j':
                        {
                            Color(0,14);
                            break;
                        }
                        default:
                        {
                            Color(0,7);
                            break;
                        }
                        }
                        printf("%s",DeckJ1[i]);
                        printf("|");
                    }
                    Color(15,0);
                    printf("\n -- -- -- -- -- -- --\n\n");
                    printf("La carte sur table : ");
                    switch (carte[1])
                    {
                    case 'r':
                    {
                        Color(0,12);
                        break;
                    }
                    case 'v':
                    {
                        Color(0,10);
                        break;
                    }
                    case 'b':
                    {
                        Color(0,11);
                        break;
                    }
                    case 'j':
                    {
                        Color(0,14);
                        break;
                    }
                    default:
                    {
                        Color(0,7);
                        break;
                    }
                    }
                    printf("%s",carte);
                    Color(15,0);
                    printf("\n\n");
                    char u;
                    if(TailleDeck1==1)
                    {
                        srand(time(NULL));
                        printf("Tapez (U) pour dire UNO\n");
                        scanf("%c",&u);
                        fflush(stdin);
                        if (t1>3)
                            tour==2;


                    }
                }
                while(tour==1);
                //tour de joueur 2
                do
                {
                    do
                    {
                        printf("%s place une carte(tapez (0) pour piocher) :\n",NomJoueur2);
                        scanf("%s",ch2);
                    }
                    while((!carteExiste(ch2,DeckJ2,TailleDeck2) || !carteValide(ch2,carte)) && strcmp(ch2,"0")!=0);
                    ch2[1]=tolower(ch2[1]);
                    i=0;
                    if(strcmp(ch2,"0")==0)
                    {
                        do
                        {
                            srand(time(NULL));
                            x=(rand()%108);
                        }
                        while(strcmp(Uno[x],"**")==0);
                        strcpy(DeckJ2[TailleDeck2],Uno[x]);
                        TailleDeck2++;
                    }
                    else if(strcmp(ch2,"+4")==0)
                    {
                        scoreJ2+=50;
                        removeCarte(ch2,DeckJ2,TailleDeck2);
                        TailleDeck2--;
                        strcpy(carte,ch2);
                        for(i=0; i<4; i++)
                        {
                            do
                            {
                                srand(time(NULL));
                                x=(rand()%108);
                            }
                            while(strcmp(Uno[x],"**")==0);
                            strcpy(DeckJ1[TailleDeck1],Uno[x]);
                            TailleDeck1++;
                            melangeDeck(Uno);
                        }
                        printf("Veuillez choisir une couleur (r) pour rouge (v) pour vert (b) pour bleu (j) pour jaune\n");
                        fflush(stdin);
                        scanf("%c",&couleur2);
                        carte[1]=tolower(couleur2);
                        printf("Le nouveau deck de %s apres +4\n",NomJoueur1);
                        printf(" -- -- -- -- -- -- --");
                        printf("\n|");
                        for(i=0; i<TailleDeck1; i++)
                        {
                            switch (DeckJ1[i][1])
                            {
                            case 'r':
                            {
                                Color(0,12);
                                break;
                            }
                            case 'v':
                            {
                                Color(0,10);
                                break;
                            }
                            case 'b':
                            {
                                Color(0,11);
                                break;
                            }
                            case 'j':
                            {
                                Color(0,14);
                                break;
                            }
                            default:
                            {
                                Color(0,7);
                                break;
                            }
                            }
                            printf("%s",DeckJ1[i]);
                            printf("|");
                        }
                        Color(15,0);
                        printf("\n -- -- -- -- -- -- --\n");
                    }
                    else if(strcmp(ch2,"Jo")==0)
                    {
                        scoreJ2+=50;
                        removeCarte(ch2,DeckJ2,TailleDeck2);
                        TailleDeck2--;
                        strcpy(carte,ch2);
                        tour=1;
                        printf("Veuillez choisir une couleur (r) pour rouge (v) pour vert (b) pour bleu (j) pour jaune\n");
                        fflush(stdin);
                        scanf("%c",&couleur2);
                        carte[1]=tolower(couleur2);
                    }
                    else if(toupper(ch2[0])=='B')
                    {
                        scoreJ2+=20;
                        removeCarte(ch2,DeckJ2,TailleDeck2);
                        TailleDeck2--;
                        strcpy(carte,ch2);
                    }
                    else if(toupper(ch2[0])=='I')
                    {
                        scoreJ2+=20;
                        removeCarte(ch2,DeckJ2,TailleDeck2);
                        TailleDeck2--;
                        strcpy(carte,ch2);
                    }
                    else if(tolower(ch2[0])=='p')
                    {
                        scoreJ2+=20;
                        removeCarte(ch2,DeckJ2,TailleDeck2);
                        TailleDeck2--;
                        strcpy(carte,ch2);
                        for(i=0; i<2; i++)
                        {
                            do
                            {
                                srand(time(NULL));
                                x=(rand()%108);
                            }
                            while(strcmp(Uno[x],"**")==0);
                            strcpy(DeckJ1[TailleDeck1],Uno[x]);
                            TailleDeck1++;
                            melangeDeck(Uno);
                        }
                        printf("Le nouveau deck de %s apres +2\n",NomJoueur1);
                        printf(" -- -- -- -- -- -- --");
                        printf("\n|");
                        for(i=0; i<TailleDeck1; i++)
                        {
                            switch (DeckJ1[i][1])
                            {
                            case 'r':
                            {
                                Color(0,12);
                                break;
                            }
                            case 'v':
                            {
                                Color(0,10);
                                break;
                            }
                            case 'b':
                            {
                                Color(0,11);
                                break;
                            }
                            case 'j':
                            {
                                Color(0,14);
                                break;
                            }
                            default:
                            {
                                Color(0,7);
                                break;
                            }
                            }
                            printf("%s",DeckJ1[i]);
                            printf("|");
                        }
                        Color(15,0);
                        printf("\n -- -- -- -- -- -- --\n");
                    }
                    else
                    {
                        scoreJ2+=(ch2[0]-48);
                        removeCarte(ch2,DeckJ2,TailleDeck2);
                        TailleDeck2--;
                        strcpy(carte,ch2);
                        tour=1;
                    }
                    printf("Nouveau deck de %s \n",NomJoueur2);
                    printf(" -- -- -- -- -- -- --");
                    printf("\n|");
                    for(i=0; i<TailleDeck2; i++)
                    {
                        switch (DeckJ2[i][1])
                        {
                        case 'r':
                        {
                            Color(0,12);
                            break;
                        }
                        case 'v':
                        {
                            Color(0,10);
                            break;
                        }
                        case 'b':
                        {
                            Color(0,11);
                            break;
                        }
                        case 'j':
                        {
                            Color(0,14);
                            break;
                        }
                        default:
                        {
                            Color(0,7);
                            break;
                        }
                        }
                        printf("%s",DeckJ2[i]);
                        printf("|");
                    }
                    Color(15,0);
                    printf("\n -- -- -- -- -- -- --\n\n");

                    char u;
                    if(TailleDeck2==1)
                    {
                        srand(time(NULL));
                        printf("\n Tapez (U) pour dire UNO\n");
                        scanf("%c",&u);
                        fflush(stdin);
                        if (t1>3)
                            tour==1;
                    }
                }
                while(tour==2);
            }
            while(TailleDeck1!=0 && TailleDeck2!=0);
            break;
        }
        while(manche<2 || reponse=='O');
    }
    case 3:
    {
        printf("Au Revoir!!\n");
        break;
    }
    }
    return 0;
}
