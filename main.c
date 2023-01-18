/*
    Toky Sandratra(SweetyBlade) code Tic Tac toe (console)
*/


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

//declarations globales
char Table[3][3];//table de jeu, tableau 2 dimensions
char Player='X';//pion du joueur
char Computer='O';//pion de l'IA
//fonctions
void ResetTable();//initialise la table de jeu
void PrintTable();//affichage de ce table de jeu
void ActionPlayer();//mouvement du joueur
void ActionComputer();//mouvement de l'ordinateur
void Transition();//alternance des actions
int FindFreePlace();//test si il existe une cellule encore vide
int GameOver();// test si jeu prend fin
int Diagonal();//test s'il y a combinaison de 3 pions egaux sur le diagonal
int Vertical();//test s'il y a combinaison de 3 pions egaux sur le vertical
int Horizontal();//test s'il y a combinaison de 3 pions egaux sur le horizontal

/*
    **fonction principale
*/
void main()
{
    char choix="";
    /*jeu en boucle tant que le joueur choisi Yes(Y)*/
    do{
        ResetTable();
        Transition();
        printf("Rejouer??(Y/N):");
        scanf("%s",&choix);
    }while(toupper(choix)=='Y');
    return 0;
}
void ResetTable()
{
    /*
        initialiser chaque cellule avec espace vide

    */
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            Table[i][j]=' ';
        }
    }
}
void PrintTable()
{
        for(int i=0;i<2*3;i++)
        {
            printf(" _");
        }
        printf("\n");
        for(int i=0;i<3;i++){
            printf("|");
            for(int j=0;j<3;j++)
            {
                 printf("_%c_|",Table[i][j]);
            }
            printf("\n");
        }

}
void ActionPlayer()
{
    int x,y;
    /*
        choisir ligne entre 1 et 3
        choisir colonne entre 1 et 3
    */
    do{
        printf("Ligne(1-3):");
        scanf("%d",&x);
        printf("Colonne(1-3):");
        scanf("%d",&y);
    }while(0<x>3 || 0<y>3);
    Table[x-1][y-1]=Player;//mettre le pion du joueur (ici player(X)) dans le cellule choisi
}
void ActionComputer()
{
    /*
        l'ordinateur choisi deux nombre aleatoire entre 0 et 3
        telle que la cellule choisi par ce nombre est vide
    */
    srand(time(0));
    int x,y;
    do{
        x=rand()%3;
        y=rand()%3;
    }while(Table[x][y]!=' '&& FindFreePlace());
    Table[x][y]=Computer;//mettre le pion de l'ordinateur (ici ))) dans le cellule choisi
}
void Transition()
{
    PrintTable();
    do{
        if(!GameOver())
            ActionPlayer();
        else
            printf("GAME OVER!!\n");
        if(!GameOver())
            ActionComputer();
        else
             printf("GAME OVER!!\n");
        PrintTable();
    }while(!GameOver());
}
int FindFreePlace()
{
    int find=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            find=Table[i][j]==' '?1:0;
            if (find) break;
        }
        if (find) break;
    }
    if (find) return 1;
    else return 0;
}
int Diagonal()
{
    if(((Table[0][0]==Table[1][1]&&Table[0][0]==Table[2][2])||(Table[0][2]==Table[1][1]&&Table[0][2]==Table[2][0]))&&(Table[1][1]!=' '))
        return 1;
    else
        return 0;
}
int Horizontal()
{
    int find;
    for(int i=0;i<3;i++)
    {
        find=0;
        for(int j=0;j<3;j++)
        {
            if(Table[i][j]!=' ' || Table[i][j+1]!=' ')
            {
                if((Table[i][j]==Table[i][j+1]))
                  find++;
                else break;
            }
            else break;
        }
        if( find>=2) return 1;
    }
    return 0;
}
int Vertical()
{
    int find=0;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(Table[j][i]!=' ' || Table[j+1][i]!=' ')
            {
                if((Table[j][i]==Table[j+1][i]))
                  find++;
                else
                    break;
            }
            else break;
        }
        if( find>=2) return 1;
    }
    return 0;
}
int GameOver()
{
    if(Diagonal()|| Horizontal()|| Vertical()|| !FindFreePlace())
        return 1;
    else
        return 0;
}
