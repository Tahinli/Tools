//Include
    #include <stdio.h>
    #include <stdlib.h>
    #include <gtk/gtk.h>
    #include <glib.h>
    #include <time.h>
    #include <string.h>
gboolean timeRefresh(gpointer data);
time_t now;
char* ourTime;
char* clockStr;
GtkWidget *clockE;
int main(int argc, char **argv)
    {
        printf("Hello World\n");

        gtk_init(&argc,&argv);
        //

        //Declerations------------
        GtkWidget *window;
        GtkWidget *pane;
        PangoFontDescription *fontSettings;
        //Definitions-------------
        window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
        pane = gtk_fixed_new();
        clockE = gtk_label_new(NULL);

    //Customization----------
        //Location
        gtk_fixed_put(GTK_FIXED(pane), clockE, 15, 30);

        //Font
        fontSettings = pango_font_description_from_string("Arial");
        pango_font_description_set_size(fontSettings, 50*PANGO_SCALE);
        gtk_widget_override_font(GTK_WIDGET(clockE), fontSettings);
        
            //Window
        gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);
        gtk_window_set_title(GTK_WINDOW(window), "Tahinli's Clock");
        gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
        gtk_window_set_keep_above(GTK_WINDOW(window), TRUE);
        
        //Time Based Refresh
            g_timeout_add_seconds(1, timeRefresh, NULL);
        //Epilogue----------------
        g_signal_connect(window, "destroy",G_CALLBACK(gtk_main_quit), NULL);
        gtk_container_add(GTK_CONTAINER(window), pane);
        gtk_widget_show_all(window);
        gtk_main();


        return 0;
    }

gboolean timeRefresh(gpointer data)
    {
        now = time(NULL);
        ourTime = ctime(&now);
        gtk_label_set_text(GTK_LABEL(clockE), ourTime);
        return 1;
    }