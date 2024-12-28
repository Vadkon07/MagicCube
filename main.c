#include <gtk/gtk.h>
#include <stdlib.h>
#include <time.h>

void generate_response(GtkWidget *button, gpointer data) {
    GtkWidget **widgets = (GtkWidget **)data;
    GtkWidget *label = widgets[0];

    // Generate a random response
    char response[1024];
    int rnd = rand() % 12 + 1;  // Update + add more responses

    if (rnd == 1) {
        sprintf(response, "You definitely will get it");
    } else if (rnd == 2) {
        sprintf(response, "I'm not sure that it has a positive answer, try again!");
    } else if (rnd == 3) {
        sprintf(response, "No");
    } else if (rnd == 4) {
        sprintf(response, "Yes");
    } else if (rnd == 5) {
        sprintf(response, "I'm sure that the answer is 'yes'");
    } else if (rnd == 6) {
        sprintf(response, "Repeat your question, please");
    } else if (rnd == 7) {
        sprintf(response, "I would like to believe that it's true...");
    } else if (rnd == 8) {
        sprintf(response, "Hah, definitely NO");
    } else if (rnd == 9) {
        sprintf(response, "No, but you can continue to believe in it");
    } else if (rnd == 10) {
        sprintf(response, "Maybe, try again later");
    } else if (rnd == 11) {
        sprintf(response, "Absolutely yes!");
    } else if (rnd == 12) {
        sprintf(response, "Highly unlikely");
    }

    gtk_label_set_text(GTK_LABEL(label), response);

    // Apply fade-in animation
    gtk_widget_set_opacity(label, 0);
    gtk_widget_show(label);

    for (double opacity = 0; opacity <= 1.0; opacity += 0.1) {
        gtk_widget_set_opacity(label, opacity);
        while (gtk_events_pending()) gtk_main_iteration();
        g_usleep(50000);  // sleep for 50ms
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    srand(time(NULL));  // Initialize random seed

    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *generate_button;
    GtkWidget *label;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "MagicCube");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 300, 200);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    generate_button = gtk_button_new_with_label("Ask MagicCube");
    label = gtk_label_new(" ");
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 5);

    // Create an array to hold the widgets for passing to the callback
    GtkWidget *widgets[] = {label};
    g_signal_connect(generate_button, "clicked", G_CALLBACK(generate_response), widgets);
    gtk_box_pack_start(GTK_BOX(box), generate_button, FALSE, FALSE, 5);

    gtk_widget_show_all(window);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();

    return 0;
}

