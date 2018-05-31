#include <stdio.h>
#include <stdlib.h>


typedef struct maillon
{
    int donnee;
    struct maillon * suivant;

}Maillon;


Maillon * supprime(Maillon * deb, int cle);

int main()
{

    //Rappel pointeurs

    //Un entier
        int m_ni=0;

         printf("valeur de m_ni : %i\n\n\n",m_ni);

    //Un pointeur d'entier
        int *m_ptni=&m_ni;

        *m_ptni=10;

         printf("valeur de m_ni : %i\n\n\n",m_ni);



    //-----------------------------------------------------------------------------------------------------------------------------------//

    printf("Sturucture Maillon\n");

   /* Maillon maille;

    maille.donnee=20;
    maille.suivant=NULL;

    Maillon maille2;

    maille2.donnee=30;
    maille.suivant=maille2;//Erreur incompatible types when assigning to type 'struct maillon *' from type Maillon

    */

    //Pour creer un maillon il faut faire une allocation dynamique


     Maillon *maille=malloc(sizeof(Maillon));//  Creation Maille 1 et attribution de la taille pour une maille d'un entier et pointeur sur maille

     maille->donnee=10;  //Set 1ere maille donnee a 10

     maille->suivant=NULL; //Set pointeur sur maille suivante a NULL


     Maillon *maille2=malloc(sizeof(Maillon)); //Creation Maille 2 et attribution de la taille pour une maille d'un entier et pointeur sur maille

     maille2->donnee=2;//Set 2eme maille donnee a 10

     maille->suivant=maille2; //Pointeur de maille de maille 1 pointe sur maille2

     maille2->suivant=NULL; //Set pointeur de Maille 2 a NULL

    //Idem maille 3

     Maillon *maille3=malloc(sizeof(Maillon));

     maille3->donnee=20;

     maille2->suivant=maille3;

     maille3->suivant=NULL;

    // Creation Maille fin

     Maillon *finMaille=malloc(sizeof(Maillon));

     finMaille->donnee=-1;

     maille3->suivant=finMaille;

     finMaille->suivant=NULL;





     printf("%d\n",maille->donnee);
     printf("%d\n",maille->suivant->donnee);
     printf("%d\n",maille->suivant->suivant->donnee);
     printf("%d\n",maille->suivant->suivant->suivant->donnee);



    supprime(maille,20); //Supprime prend en parametres la 1ere maille et naviguera de maille en maille pour supprimer
    //le maillon correspondant a la cle


     printf("%d\n",maille->donnee);
     printf("%d\n",maille->suivant->donnee);
     printf("%d\n",maille->suivant->suivant->donnee);



    //on libere toutes les mailles
     free(maille);
     free(maille2);
     free(maille3);
     free(finMaille);




    return 0;
}




Maillon * supprime(Maillon * deb, int cle){



    while(deb->suivant!=NULL){


        if(deb->donnee==cle){ //lorsque la cle = 20 alors le maillon correspondant doit etre supprime

            deb->donnee=deb->suivant->donnee; //deb->donnee est remplacee par la valeur de la maille suivante
            deb->suivant=deb->suivant->suivant; //deb->suivant est = au pointeur de la maille suivante ici NULL


        }

        else{

            deb=deb->suivant;


        }


    }


   return deb;
}
