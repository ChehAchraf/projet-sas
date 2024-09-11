#include <stdio.h>
#include <string.h>
struct students{
    int id;
    char nom[50];
    char prenom[50];
    char ddn[20];
    float note_general;
    char departement[60];
};
void buffer();
void display_menu();
void add_student(struct students s[],int *counter);
void show_students(struct students s[],int *counter);
void edit_info(struct students s[],int *counter);
void calculate_general_average(struct students s[],int *counter);
void delete_student(struct students s[],int *counter);
void statistique(struct students s[],int *counter);
void search_for_student(struct students s[],int *counter);
int main()
{   
    
    struct students s[100];
    int choice = -1;
    int counter = 0;
    while(choice != 0)
    {
        display_menu();
        if(scanf("%d" , &choice ) != 1 ){
            printf("\nVeuillez entrer un numero valide\n");
            getchar();
        }
        getchar();
        switch (choice)
        {
            case 1 : 
                add_student(s,&counter);
            break;
            case 2 : 
                show_students(s,&counter);
            break;
            case 3: 
                edit_info(s,&counter);
            break;
            case 4:
                calculate_general_average(s,&counter);
            break;
            case 5:
                delete_student(s,&counter);
            break;
            case 6:
                statistique(s,&counter);
            break;
            case 7:
                search_for_student(s,&counter);
            break;
        }
    }
    return 0;
}
void display_menu()
{
    printf("\n--------------------------------------------------------\n");
    printf("| 1 - Ajouter un nouvel eleve                            |\n");
    printf("---------------------------------------------------------\n");
    printf("| 2 - Afficher les informations de tous les etudiants    |\n");
    printf("---------------------------------------------------------\n");
    printf("| 3 - Modifier les donnees des etudian                   |\n");
    printf("---------------------------------------------------------\n");
    printf("| 4 - Calculer la moyenne generale                       |\n");
    printf("---------------------------------------------------------\n");
    printf("| 5 - supprimer un etudiant                              |\n");
    printf("---------------------------------------------------------\n");
    printf("| 6 - Statistiques                                       |\n");
    printf("---------------------------------------------------------\n");
    printf("| 7 - chercher un etudiant                               |\n");
    printf("---------------------------------------------------------\n");
    printf("| 8 - Trier les informations sur les etudiants           |\n");
    printf("---------------------------------------------------------\n");
    printf("| 9 - Entrez 0 pour quitter le programme                 |\n");
    printf("---------------------------------------------------------\n");

    printf("----> ");
}
void add_student(struct students s[],int *counter )
{  
        int dep_id;
        int temp_id;
        int id_exists;
        while (1) {
        id_exists = 0; 
        printf("## Veuillez entrer le numero unique de l'etudiant : ");
        scanf("%d", &temp_id);
        for (int i = 0; i < *counter; i++) {
            if (s[i].id == temp_id) {
                id_exists = 1; 
                break;
            }
        }
        if (id_exists) {
            printf("Ce numero unique existe deja, veuillez entrer un autre numero.\n");
        } else {
            s[*counter].id = temp_id;
            (*counter)++; 
            break; 
        }
        }
        buffer();
        printf("## Veuillez entrer le nom de l'etudiant : ");
        scanf("%[^\n]",s[*counter].nom );
        getchar();
        printf("## Veuillez entrer le prenom de l'etudiant : ");
        scanf("%[^\n]",s[*counter].prenom );
        getchar();
        printf("## Veuillez entrer la Date de naissance : ");
        scanf("%[^\n]",s[*counter].ddn );
        getchar();
        printf("## Veuillez entrer la note generale : ");
        scanf("%f",&s[*counter].note_general );
        getchar();
        printf("-------------------------------\n");
        printf("| 1 - informatique            |\n");
        printf("| 2 - medcine                 |\n");
        printf("| 3 - Physique et chimie      |\n");
        printf("| 4 - economie                |\n");
        printf("| 5 - Sciences juridiques     |\n");
        printf("-------------------------------\n");
        printf("\nEntrez le numéro de spécialité à laquelle vous appartenez : \n");
        scanf("%d" , &dep_id);
        buffer();
        switch (dep_id)
        {
        case 1:
            strcpy(s[*counter].departement , "informatique");
            printf("L'etudiant a ete ajoute avec succes");
            break;
        case 2:
            strcpy(s[*counter].departement , "medcine");
            printf("L'etudiant a ete ajoute avec succes");
            break;
        case 3:
            strcpy(s[*counter].departement , "Physique et chimie");
            printf("L'etudiant a ete ajoute avec succes");
            break;
        case 4: 
            strcpy(s[*counter].departement , "economie");
            printf("L'etudiant a ete ajoute avec succes");
            break;
        case 5:
            strcpy(s[*counter].departement , "Sciences juridiques");
            printf("L'etudiant a ete ajoute avec succes");
            break;
        default:
            printf("\n Veuillez entrer un numثro valide");
            break;
        }
        (*counter)++;
        s[*counter].id++;
}
void show_students(struct students s[],int *counter)
{
    printf("\n--------------------------------------------------------\n");
    printf("||   Ceci est une liste de tous nos etudiants inscrits   ||\n");
    printf("----------------------------------------------------------\n");
    if(*counter == 0){
        printf("\nIl n'y a aucun etudiant actuellement, veuillez d'abord saisir les informations sur l'etudiant.\n");
    }else{
        for( int i = 0 ; i < *counter ; i++ ){
        printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n| le numero unique : %d || le nom : %s || le prenom : %s || la date de naissance : %s || le moyenne generale : %.2f || departement : %s |\n",s[i].id, s[i].nom,s[i].prenom , s[i].ddn,s[i].note_general,s[i].departement);
        }
    }
    
}
void edit_info(struct students s[],int *counter){
    int id_to_edit;
    if(*counter == 0 ){
        printf("\nIl n'y a aucun etudiant actuellement, veuillez d'abord saisir les informations sur l'etudiant.\n");
    }else{
        printf("\nVoici une liste de tous les etudiants inscrits chez nous : \n");
        for (int i = 0 ; i < *counter ; i++){
            printf("\n--------------------------------------------------------------------------\n");
            printf("\n| le numero unique : %d \t|| le nom : %s\t||  le prenom : %s\t||\n", i, s[i].nom , s[i].prenom);
            
        }
            printf("Entrez le nom de l'etudiant dont vous souhaitez consulter les informations");
            scanf("%d", &id_to_edit);
            buffer();
            for(int i = 0 ; i < *counter ; i++){
                if(s[i].id == id_to_edit){
                    printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("\n| le numero unique : %d \t|| le nom : %s\t||  le prenom : %s\t||  la date de naissance : %s\t|| le moyenne generale : %.2f\t||  departement : %s |\n",i, s[i].nom,s[i].prenom , s[i].ddn,s[i].note_general,s[i].departement);
                }else{
                    printf("\n Nous n'avons pas le numero unique que vous avez saisi. Veuillez verifier a nouveau le numero.\n");
                }
            }
    }
}
void calculate_general_average(struct students s[],int *counter)
{
    float moyenne_general = 0.0;
    printf("\n-----------------------------------------------\n");
    printf("|                la moyenne generale             |\n");
    printf("\n-----------------------------------------------\n");
    for (int i = 0; i < *counter; i++) {
        moyenne_general += s[i].note_general;
    }
    float total = moyenne_general;
    if(total / *counter >= 0){
        printf("Moyenne Generale: %.2f\n", total / *counter);
    }else{
        printf("\nIl n'y a aucun etudiant actuellement, veuillez d'abord saisir les informations sur l'etudiant.\n");
    }
}
void delete_student(struct students s[],int *counter){
        int id_to_delete;
        printf("\n-----------------------------------------------\n");
        printf("|         Supprimer les données des étudiant    |\n");
        printf("\n-----------------------------------------------\n");
            if(*counter == 0 ){
                printf("\nIl n'y a aucun etudiant actuellement, veuillez d'abord saisir les informations sur l'etudiant.\n");
            }else{
                printf("\nVoici une liste de tous les etudiants inscrits chez nous : \n");
                for (int i = 0 ; i < *counter ; i++){
                    printf("\n--------------------------------------------------------------------------\n");
                    printf("\n| le numero unique : %d \t|| le nom : %s\t||  le prenom : %s\t||\n", i, s[i].nom , s[i].prenom);
                }
                printf("entrer un numero unique pour supprimer un etudiant : ");
                scanf("%d" , &id_to_delete );
                for(int i = 0 ; i < *counter ; i++){
                    if(s[i].id == id_to_delete){
                        for(int i = 0 ; i < *counter - 1 ; i++){
                           s[i] = s[i+1];
                        }
                    }
                    (*counter)--;
                    printf("\n Ceci est la nouvelle liste aprثs votre suppression");
                    for( int i = 0 ; i < *counter ; i++ ){
                        printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                        printf("\n| le numero unique : %d || le nom : %s || le prenom : %s || la date de naissance : %s || le moyenne generale : %.2f || departement : %s |\n",s[i].id, s[i].nom,s[i].prenom , s[i].ddn,s[i].note_general,s[i].departement);
                    }
                }
}
}
void statistique(struct students s[],int *counter)
{
    if (*counter == 0){
        printf("makaynch ");
    }else{
        int st_choice;
        int dep_choice;
        int total = 0 ;
        int note_to_fetch_data;
    int total_student;
    printf("\n-----------------------------------------------\n");
    printf("|                 statistique                   |\n");
    printf("\n-----------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------\n");
    printf("| 1 - Afficher le nombre total d'étudiants inscrits.                                      |\n");
    printf("| 2 - Afficher le nombre d'étudiants dans chaque département                              |\n");
    printf("| 3 - Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil     |\n");
    printf("| 4 - Afficher les 3 étudiants ayant les meilleures notes.                                |\n");
    printf("| 5 - Afficher le nombre d'étudiants ayant réussi dans chaque département                 |\n");
    printf("------------------------------------------------------------------------------------------\n");
    printf("\n----> ");
    scanf("%d", &st_choice);
    switch (st_choice)
    {
    case 1:
        printf("Le nombre d'étudiants inscrits est : %d " , *counter);
        break;
    case 2:
        printf("Quelle departement.");
        printf("-------------------------------\n");
        printf("| 1 - informatique            |\n");
        printf("| 2 - medcine                 |\n");
        printf("| 3 - Physique et chimie      |\n");
        printf("| 4 - economie                |\n");
        printf("| 5 - Sciences juridiques     |\n");
        printf("-------------------------------\n");
        printf("----> ");
        scanf("%d" , &dep_choice);
        switch(dep_choice)
        {
            case 1:
                for(int i = 0 ; i < *counter ; i++)
                {
                    if(strcmp(s[i].departement , "informatique" ) == 0 ){
                       total++;
                    }
                }
                printf("Le nombre d'etudiants inscrits dans cette departement(informatique) est de : %d" , total);
            break;
            case 2:
                for(int i = 0 ; i < *counter ; i++)
                {
                    if(strcmp(s[i].departement , "medcine" ) == 0 ){
                       total++;
                    }
                }
                printf("Le nombre d'etudiants inscrits dans cette departement(medcine) est de : %d" , total);
            break;
            case 3:
                for(int i = 0 ; i < *counter ; i++)
                {
                    if(strcmp(s[i].departement , "Physique et chimie" ) == 0 ){
                       total++;
                    }
                }
                printf("Le nombre d'etudiants inscrits dans cette departement(Physique et chimie) est de : %d" , total);
            break;
            case 4:
                for(int i = 0 ; i < *counter ; i++)
                {
                    if(strcmp(s[i].departement , "economie" ) == 0 ){
                       total++;
                    }
                }
                printf("Le nombre d'etudiants inscrits dans cette departement(economie) est de : %d" , total);
            break;
            case 5:
                for(int i = 0 ; i < *counter ; i++)
                {
                    if(strcmp(s[i].departement , "Sciences juridiques" ) == 0 ){
                       total++;
                    }
                }
                printf("Le nombre d'etudiants inscrits dans cette departement(Sciences juridiques) est de : %d" , total);
            break;
        }
        break;
        case 3:
            printf("Entret la note : ");
            scanf("%d" , &note_to_fetch_data);
            // loop for sorting data
            for(int i = 0 ; i < *counter - 1 ; i++){
                for ( int j = 0 ; j < *counter - 1 ; j++ ){
                    int temp = s[i].note_general;
                    s[i].note_general = s[i+1].note_general;
                    s[i+1].note_general = temp;
                }
            }
            // Loop for fetching the data that already sorted
            for(int i = 0 ; i < *counter ; i++){
                while (s[i].note_general > note_to_fetch_data)
                {
                printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\n| le numero unique : %d || le nom : %s || le prenom : %s || la date de naissance : %s || le moyenne generale : %.2f || departement : %s |\n",s[i].id, s[i].nom,s[i].prenom , s[i].ddn,s[i].note_general,s[i].departement);
                break;
                if ( i == 4 ){
                    return;
                }
                }
            } 
        break;
        case 4:
            for(int i = 0 ; i < *counter - 1 ; i++){
                for ( int j = 0 ; j < *counter - 1 ; j++ ){
                    if ( s[j].note_general < s[j+1].note_general ){
                        int temp = s[j].note_general;
                        s[j].note_general = s[j+1].note_general;
                        s[j+1].note_general = temp;
                    }
                }
            }
            for(int i = 0 ; i < 3 ; i++){
                    printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("\n| le numero unique : %d || le nom : %s || le prenom : %s || la date de naissance : %s || le moyenne generale : %.2f || departement : %s |\n",s[i].id, s[i].nom,s[i].prenom , s[i].ddn,s[i].note_general,s[i].departement);
                
            }
        break;
        case 5 :
            printf("Quelle departement.");
            printf("-------------------------------\n");
            printf("| 1 - informatique            |\n");
            printf("| 2 - medcine                 |\n");
            printf("| 3 - Physique et chimie      |\n");
            printf("| 4 - economie                |\n");
            printf("| 5 - Sciences juridiques     |\n");
            printf("-------------------------------\n");
            printf("----> ");
            scanf("%d" , &dep_choice);
            switch(dep_choice){
                case 1:
                    for(int i = 0 ; i < *counter - 1 ; i++){
                        for ( int j = 0 ; j < *counter - 1 ; j++ ){
                            if ( s[j].note_general < s[j+1].note_general ){
                            int temp = s[j].note_general;
                            s[j].note_general = s[j+1].note_general;
                            s[j+1].note_general = temp;
                            }
                        }
                    }
                    for (int i = 0 ; i < *counter ; i++){
                        if(strcmp(s[i].departement , "informatique" ) == 0){
                            if(s[i].note_general >=10){
                                printf("\netudiants qui reussissent dans cette departement\n");
                                printf("le numero unique : %d  || le nom : %s || le prenom : %s || la note : %.2f", s[i].id,s[i].nom,s[i].prenom,s[i].note_general);
                            }
                        }
                    }
                break;
                case 2:
                    for(int i = 0 ; i < *counter - 1 ; i++){
                        for ( int j = 0 ; j < *counter - 1 ; j++ ){
                            if ( s[j].note_general < s[j+1].note_general ){
                            int temp = s[j].note_general;
                            s[j].note_general = s[j+1].note_general;
                            s[j+1].note_general = temp;
                            }
                        }
                    }
                    for (int i = 0 ; i < *counter ; i++){
                        if(strcmp(s[i].departement , "medcine" ) == 0){
                            if(s[i].note_general >=10){
                                printf("\netudiants qui reussissent dans cette departement\n");
                                printf("le numero unique : %d  || le nom : %s || le prenom : %s || la note : %.2f", s[i].id,s[i].nom,s[i].prenom,s[i].note_general);
                            }
                        }
                    }
                break;
                case 3:
                    for(int i = 0 ; i < *counter - 1 ; i++){
                        for ( int j = 0 ; j < *counter - 1 ; j++ ){
                            if ( s[j].note_general < s[j+1].note_general ){
                            int temp = s[j].note_general;
                            s[j].note_general = s[j+1].note_general;
                            s[j+1].note_general = temp;
                            }
                        }
                    }
                    for (int i = 0 ; i < *counter ; i++){
                        if(strcmp(s[i].departement , "Physique et chimie" ) == 0){
                            if(s[i].note_general >=10){
                                printf("\netudiants qui reussissent dans cette departement\n");
                                printf("le numero unique : %d  || le nom : %s || le prenom : %s || la note : %.2f", s[i].id,s[i].nom,s[i].prenom,s[i].note_general);
                            }
                        }
                    }
                break;
                case 4:
                    for(int i = 0 ; i < *counter - 1 ; i++){
                        for ( int j = 0 ; j < *counter - 1 ; j++ ){
                            if ( s[j].note_general < s[j+1].note_general ){
                            int temp = s[j].note_general;
                            s[j].note_general = s[j+1].note_general;
                            s[j+1].note_general = temp;
                            }
                        }
                    }
                    for (int i = 0 ; i < *counter ; i++){
                        if(strcmp(s[i].departement , "economie" ) == 0){
                            if(s[i].note_general >=10){
                                printf("\netudiants qui reussissent dans cette departement\n");
                                printf("le numero unique : %d  || le nom : %s || le prenom : %s || la note : %.2f", s[i].id,s[i].nom,s[i].prenom,s[i].note_general);
                            }
                        }
                    }
                break;
                case 5:
                    for(int i = 0 ; i < *counter - 1 ; i++){
                        for ( int j = 0 ; j < *counter - 1 ; j++ ){
                            if ( s[j].note_general < s[j+1].note_general ){
                            int temp = s[j].note_general;
                            s[j].note_general = s[j+1].note_general;
                            s[j+1].note_general = temp;
                            }
                        }
                    }
                    for (int i = 0 ; i < *counter ; i++){
                        if(strcmp(s[i].departement , "Sciences juridiques" ) == 0){
                            if(s[i].note_general >=10){
                                printf("\netudiants qui reussissent dans cette departement\n");
                                printf("le numero unique : %d  || le nom : %s || le prenom : %s || la note :%.2f", s[i].id,s[i].nom,s[i].prenom,s[i].note_general);
                            }
                        }
                    }
                break;
            }
        break;
    default:
        printf("\nsvp entrer un nombre valid\n");
        break;
    }
    }
}
void search_for_student(struct students s[],int *counter){
    char name_to_look[50];
    int choice_for_search;
    int id_to_search;
    printf("\n-----------------------------------------------\n");
    printf("|                 recherche                     |\n");
    printf("\n-----------------------------------------------\n");
    printf("\n 1 - Rechercher un etudiant par son nom. \n 2 - Rechercher un etudiant par son numero unique. \n");
    printf("---->");
    scanf("%d",&choice_for_search);
    buffer();
    switch (choice_for_search)
    {
    case 1:
        if(*counter == 0){
        printf("\nIl n'y a aucun etudiant actuellement, veuillez d'abord saisir les informations sur l'etudiant.\n");
        }else{
        printf("\n Mais avant toute chose, voici une liste des ثtudiants qui sont inscrits chez nous");
        for( int i = 0 ; i < *counter ; i++ ){
        printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n| le numero unique : %d || le nom : %s || le prenom : %s || la date de naissance : %s || le moyenne generale : %.2f || departement : %s |\n",s[i].id, s[i].nom,s[i].prenom , s[i].ddn,s[i].note_general,s[i].departement);
        }
        printf("---->");
        scanf("%[^\n]",name_to_look);
        buffer();
        for(int i = 0;i<*counter;i++){
            if(strcmp(s[i].nom , name_to_look) == 0 ){
                printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\n| le numero unique : %d || le nom : %s || le prenom : %s || la date de naissance : %s || le moyenne generale : %.2f || departement : %s |\n",s[i].id, s[i].nom,s[i].prenom , s[i].ddn,s[i].note_general,s[i].departement);
            }else{
                printf("\n Il n'y aucun élève portant ce nom, veuillez essayer un autre nom\n");
            }
        }
    }
        break;
    case 2:
       if(*counter == 0 ){
        printf("\nIl n'y a aucun etudiant actuellement, veuillez d'abord saisir les informations sur l'etudiant.\n");
       }else{
         printf("\n Mais avant toute chose, voici une liste des ثtudiants qui sont inscrits chez nous");
        for( int i = 0 ; i < *counter ; i++ ){
        printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n| le numero unique : %d || le nom : %s || le prenom : %s || la date de naissance : %s || le moyenne generale : %.2f || departement : %s |\n",s[i].id, s[i].nom,s[i].prenom , s[i].ddn,s[i].note_general,s[i].departement);
        }
        printf("---->");
        scanf("%d",&id_to_search);
        buffer();
        for(int i = 0;i<*counter;i++){
            if(s[i].id == id_to_search ){
                printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\n| le numero unique : %d || le nom : %s || le prenom : %s || la date de naissance : %s || le moyenne generale : %.2f || departement : %s |\n",s[i].id, s[i].nom,s[i].prenom , s[i].ddn,s[i].note_general,s[i].departement);
            }else{
                printf("\n Il n'y aucun élève portant ce nom, veuillez essayer un autre nom\n");
            }
        }
       }
    break;
    
    default:
        break;
    }

}
void buffer()
{
    getchar();
}
