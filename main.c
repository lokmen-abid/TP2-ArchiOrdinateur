/*
    Lokmen Abid CODE PERMANENT UQTR : ABIL1933****
    Haithem Sissaoui CODE PERMANENT UQTR : SISH2735****
    Ahmed derouiche CODE PERMANENT UQTR : DERA6431****

*/

#include <stdio.h>


/*
 * Cette fonction effectue une division non sign�e en utilisant une m�thode par soustraction r�p�t�e.
 * Cette fonction prend deux nombres non sign�s en entr�e et retourne le r�sultat de la division.
 * INPUT :
 * dividende de type unsigned int.
 * diviseur de type unsigned int.
 * OUTPUT :
 * Le r�sultat de la division de type unsigned int.
 */
unsigned int divison (unsigned int dividende , unsigned int diviseur){

        diviseur = diviseur<<16; // D�calage de 16 bits vers la gauche pour le diviseur
        for(int i=0; i<16 ; i++){ // boucle pour repeter la soustraction sur tous les bits
            dividende=dividende<<1; // D�calage de 1 bit vers la gauche pour le dividende
            if(dividende>=diviseur){
                dividende-=diviseur;// Soustraction du diviseur si le dividende est sup�rieur ou �gal
                dividende+=1;
            }
        }
       return dividende;
}

/*
 * La fonction principale du programme.Elle permet � l'utilisateur d'entrer des paires de nombres
 * pour effectuer des divisions et �crit les r�sultats dans un fichier.
 */

int main()
{
    // declaration des variables n�cissaires pour le programme :
    unsigned short  c;
    unsigned int dividend, divisor ,res ;
    int num_div;

    /* Cette partie de code ouvre un fichier nomm� "resultats_divisions.txt" en mode �criture.
     * Si l'ouverture du fichier �choue un message d'erreur est affich� et le programme retourne 1 pour indiquer une erreur.
     */
    FILE *output_file = fopen("resultats_divisions.txt", "w");
    if (output_file == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sortie.\n");
        return 1;
    }

    // L'utilisateur doit choisir le nombre de divisions � effectuer.
    printf("Entrez le nombre de divisions a effectuer : ");
    scanf("%d", &num_div);

    for (int i = 0; i < num_div; i++) { // boucle pour r�peter la division selon le nombre choisi par utilisateur
        printf("\nDivision %d\n", i + 1);
        printf("Entrez le dividende : ");
        scanf("%u", &dividend);

        printf("Entrez le diviseur  : ");
        scanf("%u", &divisor);

        if (divisor == 0) {
            printf("On ne peut pas fair Division par z�ro.\n");
            continue;
        }

        res=divison(dividend,divisor);
        c= (unsigned short)res; // Conversion du r�sultat en unsigned short
        res=(res>>16);// D�calage de 16 bits vers la droite pour obtenir le reste
        fprintf(output_file,"Division %d : %i / %i = %d reste %i \n",i+1,dividend,divisor,c,res); // �criture des r�sultats dans le fichier

    }


    fclose(output_file); // pour fermer le ficher ouvert


    return 0;
}
