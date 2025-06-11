#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <gtk/gtk.h>

typedef enum { PIERRE, FEUILLE, CISEAUX } Choix;

GtkWidget *window;
GtkCssProvider *provider;
GdkScreen *screen;
GtkWidget *box;

GtkWidget *maintitle;
GtkLabel *result;

GtkWidget *imageP;
GtkWidget *imageF;
GtkWidget *imageC;

GtkWidget *buttonP;
GtkWidget *buttonF;
GtkWidget *buttonC;
GtkWidget *play;

void Gagnant(Choix player, Choix bot) {
    if (player == bot){
        gtk_label_set_label (result,"Egalite");
    } else if (player == PIERRE && bot == FEUILLE || player == CISEAUX && bot == PIERRE || player == FEUILLE && bot == CISEAUX)
    {
        gtk_label_set_label (result,"Le Bot Gagne");
    }else
    {
        gtk_label_set_label (result,"Tu a gagner");
    }
    gtk_widget_show(GTK_WIDGET(result));
    gtk_widget_show(play);
    gtk_button_set_label(GTK_BUTTON(play), "Rejouer");
    
}


void Bot(GtkWidget *widget, gpointer data){
    
    srand(time(NULL));

    Choix bot = rand() % 3;

    Gagnant((Choix)GPOINTER_TO_INT(data), bot);
    gtk_widget_hide(maintitle);
    gtk_widget_hide(buttonP);
    gtk_widget_hide(buttonF);
    gtk_widget_hide(buttonC);
}




void Jeux(GtkWidget *widget, gpointer data) {

    gtk_label_set_text(GTK_LABEL(maintitle), "Faite votre Choix");
    gtk_widget_hide(play);

    gtk_widget_show(buttonP);
    gtk_widget_show(buttonF);
    gtk_widget_show(buttonC);
}


int main(int argc, char *argv[]){
    //initialisation GTK
    gtk_init(&argc, &argv);

    //Creation d'une nouvelle fenetre
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    //Set d'un ID pour CSS
    gtk_widget_set_name(window, "main_window");

    //Titre de la fenetre
    gtk_window_set_title(GTK_WINDOW(window), "Shifumi");

    //Set taille
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);
    gtk_window_set_resizable(GTK_WINDOW(window), TRUE);

    gtk_window_set_icon_from_file(GTK_WINDOW(window), "logo.png", NULL);

    //Fermeture de la fentre propre
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //Création de l'application du css
    provider = gtk_css_provider_new();

    //Chemin du Css qui vient d'un fichier
    gtk_css_provider_load_from_path(provider,"style.css", NULL);

    //Set de l'écran
    screen = gdk_screen_get_default();

    //Application du CSS
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    //création d'une boite verticale
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    maintitle = gtk_label_new("Bienvenue dans Shifumi !");
    gtk_box_pack_start(GTK_BOX(box), maintitle, TRUE, TRUE, 10);

    result = (GtkLabel *)gtk_label_new("");

    gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(result), TRUE, TRUE, 10);


    //Bouton choix
    imageP = gtk_image_new_from_file("Pierre.png");
    buttonP = gtk_button_new();
    gtk_button_set_image(GTK_BUTTON(buttonP), imageP);
    gtk_box_pack_start(GTK_BOX(box), buttonP, FALSE, FALSE, 10);

    imageF = gtk_image_new_from_file("Feuille.png");
    buttonF = gtk_button_new();
    gtk_button_set_image(GTK_BUTTON(buttonF), imageF);
    gtk_box_pack_start(GTK_BOX(box), buttonF, FALSE, FALSE, 10);

    imageC = gtk_image_new_from_file("Ciseaux.png");
    buttonC = gtk_button_new();
    gtk_button_set_image(GTK_BUTTON(buttonC), imageC);
    gtk_box_pack_start(GTK_BOX(box), buttonC, FALSE, FALSE, 10);

    
    g_signal_connect(G_OBJECT(buttonP), "clicked", G_CALLBACK(Bot), GINT_TO_POINTER(PIERRE));
    g_signal_connect(G_OBJECT(buttonC), "clicked", G_CALLBACK(Bot), GINT_TO_POINTER(CISEAUX));
    g_signal_connect(G_OBJECT(buttonF), "clicked", G_CALLBACK(Bot), GINT_TO_POINTER(FEUILLE));

    //Bouton play
    play = gtk_button_new_with_label("Jouer");
    gtk_box_pack_start(GTK_BOX(box), play, TRUE, TRUE, 10);
    g_signal_connect(G_OBJECT(play), "clicked", G_CALLBACK(Jeux),NULL);


    //Montre les elements
    gtk_widget_show_all(window);

    gtk_widget_hide(GTK_WIDGET(result));
    gtk_widget_hide(buttonP);
    gtk_widget_hide(buttonF);
    gtk_widget_hide(buttonC); 
    
    
    //Maintien la fenetre ouverte
    gtk_main();    
    return 0;
}