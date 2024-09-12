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
void sort(struct students s[], int *counter);
int main()
{   
    
    struct students s[100]= {
        {1,"chehboun","achraf","12-12-1998",17.22,"informatique"},
        {2,"lafhaili","younes","11-02-1999",12.02,"medcine"},
        {3,"bounour","ayoube","01-01-1993",16.23,"economie"},
        {4,"zahid","mehdi","12-06-2000",16,"Sciences juridiques"},
        {5,"ait","salah","12-12-1995",10,"Physique et chimie"},
        {6,"zaanan","oussama","03-12-1998",13.99,"informatique"},
        {7,"mohtadi","hiba","11-02-1999",8.02,"informatique"},
        {8,"ennouri","chaimae","01-01-1993",18.2,"economie"},
        {9,"choumani","amine","12-06-2000",16,"Sciences juridiques"},
        {10,"lwafi","noure zddine","12-12-1995",11,"Physique et chimie"},
        };
    int choice = -1;
    int counter = 10;
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
                getchar();
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
            case 8:
                sort(s,&counter);
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
        
        printf("## Veuillez entrer le numero unique de l'etudiant : ");
        scanf("%d",&s[*counter].id );
        for(int i = 0;i <*counter ; i++){
            while(s[i].id == s[*counter].id){
                printf("entrer un nv num : ");
                scanf("%d",&s[*counter].id );
                while (getchar() != '\n');
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
        printf("\nEntrez le numero de specialite e laquelle vous appartenez : \n");
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
        if (*counter == 0) {
        printf("\nIl n'y a aucun etudiant actuellement, veuillez d'abord saisir les informations sur l'etudiant.\n");
    } else {
        for (int i = 0; i < *counter; i++) {
            printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
            printf("| numero unique : %d || nom : %s || prenom : %s || date de naissance : %s || moyenne generale : %.2f || departement : %s |\n",
                   s[i].id, s[i].nom, s[i].prenom, s[i].ddn, s[i].note_general, s[i].departement);
        }
    }
}
void edit_info(struct students s[],int *counter){
    int id_to_edit;
    int dep_id;
    
    if (*counter == 0) {
        printf("\nIl n'y a aucun etudiant actuellement, veuillez d'abord saisir les informations sur l'etudiant.\n");
        return;
    }
    printf("\nVoici une liste de tous les etudiants inscrits chez nous : \n");
    for (int i = 0; i < *counter; i++) {
        printf("\n--------------------------------------------------------------------------\n");
        printf("| Le numero unique : %d \t|| Le nom : %s\t|| Le prenom : %s\t||\n", s[i].id, s[i].nom, s[i].prenom);
    }
    printf("\nEntrez le numero unique de l'etudiant dont vous souhaitez modifier : ");
    scanf("%d", &id_to_edit);
    buffer();
    int student_found = 0;
    for (int i = 0; i < *counter; i++) {
        if (s[i].id == id_to_edit) {
            student_found = 1;

            printf("## Veuillez entrer le numero unique de l'etudiant : ");
            scanf("%d", &s[i].id);
            buffer();

            printf("## Veuillez entrer le nom de l'etudiant : ");
            scanf("%99[^\n]", s[i].nom);
            buffer();

            printf("## Veuillez entrer le prenom de l'etudiant : ");
            scanf("%99[^\n]", s[i].prenom);
            buffer();

            printf("## Veuillez entrer la date de naissance (format JJ/MM/AAAA) : ");
            scanf("%10[^\n]", s[i].ddn);
            buffer();

            printf("## Veuillez entrer la note generale : ");
            scanf("%f", &s[i].note_general);
            buffer();

            printf("-------------------------------\n");
            printf("| 1 - Informatique            |\n");
            printf("| 2 - Medecine                 |\n");
            printf("| 3 - Physique et Chimie      |\n");
            printf("| 4 - economie                |\n");
            printf("| 5 - Sciences Juridiques     |\n");
            printf("-------------------------------\n");

            printf("\nEntrez le numero de specialite auquel vous appartenez : ");
            scanf("%d", &dep_id);
            buffer();

            switch (dep_id) {
                case 1:
                    strcpy(s[i].departement, "Informatique");
                    break;
                case 2:
                    strcpy(s[i].departement, "Medecine");
                    break;
                case 3:
                    strcpy(s[i].departement, "Physique et Chimie");
                    break;
                case 4:
                    strcpy(s[i].departement, "economie");
                    break;
                case 5:
                    strcpy(s[i].departement, "Sciences Juridiques");
                    break;
                default:
                    printf("\nVeuillez entrer un numero valide.\n");
                    return;
            }

            printf("L'etudiant a ete modifie avec succes.\n");
            return;
        }
    }

    if (!student_found) {
        printf("\nNous n'avons pas le numero unique que vous avez saisi. Veuillez verifier à nouveau le numero.\n");
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
        int found = 0;
        printf("\n-----------------------------------------------\n");
        printf("|         Supprimer les donnees des etudiant    |\n");
        printf("\n-----------------------------------------------\n");
    if (*counter == 0) {
        printf("\nIl n'y a aucun etudiant actuellement, veuillez d'abord saisir les informations sur l'etudiant.\n");
        return;
    }

    printf("\nVoici une liste de tous les etudiants inscrits chez nous : \n");
    for (int i = 0; i < *counter; i++) {
        printf("\n--------------------------------------------------------------------------\n");
        printf("\n| ID : %d \t|| Nom : %s\t|| Prenom : %s\t||\n", s[i].id, s[i].nom, s[i].prenom);
    }

    printf("Entrez l'ID de l'etudiant e supprimer : ");
    if (scanf("%d", &id_to_delete) != 1) {
        printf("\nID invalide. Veuillez entrer un nombre entier.\n");
        while (getchar() != '\n');  // Clear the input buffer
        return;
    }
    getchar();  // Clear the newline character

   
    for (int i = 0; i < *counter; i++) {
        if (s[i].id == id_to_delete) {
            for (int j = i; j < *counter - 1; j++) {
                s[j] = s[j + 1];
            }
            (*counter)--;  // Decrement the student counter
            found = 1;
            break;
        }
    }

    if (found) {
        printf("\nCeci est la nouvelle liste apres votre suppression :\n");
        for (int i = 0; i < *counter; i++) {
            printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
            printf("| ID : %d || Nom : %s || PrEenom : %s || Date de naissance : %s || Note generale : %.2f || Departement : %s |\n", s[i].id, s[i].nom, s[i].prenom, s[i].ddn, s[i].note_general, s[i].departement);
        }
    } else {
        printf("\nAucun etudiant avec l'ID %d n'a ete trouve.\n", id_to_delete);
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
        float note_to_fetch_data;
    int total_student;
    printf("\n-----------------------------------------------\n");
    printf("|                 statistique                   |\n");
    printf("\n-----------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------\n");
    printf("| 1 - Afficher le nombre total d'etudiants inscrits.                                      |\n");
    printf("| 2 - Afficher le nombre d'etudiants dans chaque departement                              |\n");
    printf("| 3 - Afficher les etudiants ayant une moyenne generale superieure e un certain seuil     |\n");
    printf("| 4 - Afficher les 3 etudiants ayant les meilleures notes.                                |\n");
    printf("| 5 - Afficher le nombre d'etudiants ayant reussi dans chaque departement                 |\n");
    printf("------------------------------------------------------------------------------------------\n");
    printf("\n----> ");
    scanf("%d", &st_choice);
    switch (st_choice)
    {
    case 1:
        printf("Le nombre d'etudiants inscrits est : %d " , *counter);
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
                printf("Entrez la note : ");
                scanf("%f", &note_to_fetch_data);

                // Sorting students by note_general in ascending order
                for (int i = 0; i < *counter - 1; i++) {
                    for (int j = 0; j < *counter - i - 1; j++) {
                        if (s[j].note_general > s[j + 1].note_general) {
                            // Swap the students
                            struct students temp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = temp;
                        }
                    }
                }
                printf("\netudiants avec une note >= %.2f :\n", note_to_fetch_data);
                for (int i = 0; i < *counter; i++) {
                    if (s[i].note_general >= note_to_fetch_data) {
                        printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                        printf("| numero unique : %d || nom : %s || prenom : %s || date de naissance : %s || moyenne generale : %.2f || departement : %s |\n",
                            s[i].id, s[i].nom, s[i].prenom, s[i].ddn, s[i].note_general, s[i].departement);
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
                return;
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
                return;
            }
        }
       }
    break;
    default:
        break;
    }
}
void sort(struct students s[], int *counter){
    int sub_menu;
    printf("\n-----------------------------------------------\n");
    printf("|             Classement des etudiants          |\n");
    printf("\n-----------------------------------------------\n");
    printf("\n 1 - Trier les eleves de A a Z. \n 2 - Trier les eleves de Z a A. \n 3 - Tri des etudiants par moyenne generale \n 4 - Tri des etudiants selon leur statut de reussite");
    printf("----> ");
    scanf("%d" ,&sub_menu);
    buffer();
    switch(sub_menu){
        case 1:
            for(int i = 0; i < *counter - 1; i++) {
                for (int j = 0; j < *counter - 1; j++) {
                    if (strcmp(s[j].nom, s[j + 1].nom) > 0) {
                        struct students temp = s[j];
                        s[j] = s[j + 1];
                        s[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < *counter; i++) {
                printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\n| le numero unique : %d || le nom : %s || le prenom : %s || la date de naissance : %s || le moyenne generale : %.2f || departement : %s |\n", s[i].id, s[i].nom, s[i].prenom, s[i].ddn, s[i].note_general, s[i].departement);
            }
        break;
        case 2:
            for(int i = 0; i < *counter - 1; i++) {
                for (int j = 0; j < *counter - 1; j++) {
                    if (strcmp(s[j].nom, s[j + 1].nom) < 0) {
                        struct students temp = s[j];
                        s[j] = s[j + 1];
                        s[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < *counter; i++) {
                printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\n| le numero unique : %d || le nom : %s || le prenom : %s || la date de naissance : %s || le moyenne generale : %.2f || departement : %s |\n", s[i].id, s[i].nom, s[i].prenom, s[i].ddn, s[i].note_general, s[i].departement);
            }
        break;
        case 3:
            for(int i = 0 ; i < *counter - 1 ; i++){
                for(int j = 0; j < *counter -1 ; j++){
                    if(s[j].note_general < s[j+1].note_general ){
                        int temp = s[j].note_general;
                        s[j].note_general = s[j+1].note_general;
                        s[j+1].note_general = temp;
                    }
                }
            }
            for (int i = 0; i < *counter; i++) {
                printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\n| le numero unique : %d || le nom : %s || le prenom : %s || la date de naissance : %s || le moyenne generale : %.2f || departement : %s |\n", s[i].id, s[i].nom, s[i].prenom, s[i].ddn, s[i].note_general, s[i].departement);
            }
        break;
        case 4:
                printf("\nLes etudiants qui sont reussis :\n");
                    for (int i = 0; i < *counter; i++) {
                        if (s[i].note_general >= 10) {
                            printf("\n| Numero unique : %d || Nom : %s || Prenom : %s || Date de naissance : %s || Moyenne generale : %.2f || departement : %s |\n",
                                s[i].id, s[i].nom, s[i].prenom, s[i].ddn, s[i].note_general, s[i].departement);
                        }
                    }

                    printf("\nLes etudiants qui ne sont pas reussis :\n");
                    for (int i = 0; i < *counter; i++) {
                        if (s[i].note_general < 10) {
                            printf("\n| Numero unique : %d || Nom : %s || Prenom : %s || Date de naissance : %s || Moyenne generale : %.2f || departement : %s |\n",
                                s[i].id, s[i].nom, s[i].prenom, s[i].ddn, s[i].note_general, s[i].departement);
                        }
                    }
        break;
    }

}
void buffer()
{
    getchar();
}
