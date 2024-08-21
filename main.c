#include <glib.h>
#include <gtk/gtk.h>

char ops[] = {0, 0, 0};
char ni = '9';
char ei = '8';
char se = '7';
char si = '6';
char fi = '5';
char fo = '4';
char th = '3';
char tw = '2';
char on = '1';

static void add_char(GtkWidget *widget, gpointer data) {
  char *pn = data;
  ops[0] = *pn;
  g_print(&ops[0]);
}

static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *button9;
  GtkWidget *button8;
  GtkWidget *button7;
  GtkWidget *button6;
  GtkWidget *button5;
  GtkWidget *button4;
  GtkWidget *button3;
  GtkWidget *button2;
  GtkWidget *button1;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Calculator");
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

  button9 = gtk_button_new_with_label("9");
  g_signal_connect(button9, "clicked", G_CALLBACK(add_char), &ni);
  gtk_window_set_child(GTK_WINDOW(window), button9);

  button8 = gtk_button_new_with_label("8");
  g_signal_connect(button8, "clicked", G_CALLBACK(add_char), &ei);
  gtk_window_set_child(GTK_WINDOW(window), button8);

  button7 = gtk_button_new_with_label("7");
  g_signal_connect(button7, "clicked", G_CALLBACK(add_char), &se);
  gtk_window_set_child(GTK_WINDOW(window), button7);

  button6 = gtk_button_new_with_label("6");
  g_signal_connect(button6, "clicked", G_CALLBACK(add_char), &si);
  gtk_window_set_child(GTK_WINDOW(window), button6);

  button5 = gtk_button_new_with_label("5");
  g_signal_connect(button5, "clicked", G_CALLBACK(add_char), &fi);
  gtk_window_set_child(GTK_WINDOW(window), button5);

  button4 = gtk_button_new_with_label("4");
  g_signal_connect(button4, "clicked", G_CALLBACK(add_char), &fo);
  gtk_window_set_child(GTK_WINDOW(window), button4);

  button3 = gtk_button_new_with_label("3");
  g_signal_connect(button3, "clicked", G_CALLBACK(add_char), &th);
  gtk_window_set_child(GTK_WINDOW(window), button3);

  button2 = gtk_button_new_with_label("2");
  g_signal_connect(button2, "clicked", G_CALLBACK(add_char), &tw);
  gtk_window_set_child(GTK_WINDOW(window), button2);

  button1 = gtk_button_new_with_label("1");
  g_signal_connect(button1, "clicked", G_CALLBACK(add_char), &on);
  gtk_window_set_child(GTK_WINDOW(window), button1);

  gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
