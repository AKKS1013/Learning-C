#include <glib-object.h>
#include <glib.h>
#include <gtk/gtk.h>
#include <gtk/gtkshortcut.h>
#include <stdio.h>
#include <time.h>
#include <wchar.h>

char ops[] = {0, 0, 0};
char *ni = "9";
char *ei = "8";
char *se = "7";
char *si = "6";
char *fi = "5";
char *fo = "4";
char *th = "3";
char *tw = "2";
char *on = "1";
char *pl = "+";
char *mi = "-";
char *mu = "*";
char *di = "/";
int *ans = &(int){0};
char lab[32] = {0};
char ans2[32] = {0};
bool first = false;
bool second = false;

GtkWidget *anslabel;

static void add_char(GtkWidget *widget, gpointer user_data) {
  char *pn = user_data;
  if (*pn == '+') {
    ops[1] = *pn;
  } else if (*pn == '-') {
    ops[1] = *pn;
  } else if (*pn == '*') {
    ops[1] = *pn;
  } else if (*pn == '/') {
    ops[1] = *pn;
  } else {
    if (first == true && second == true) {
      ops[0] = *pn;
    } else if (first == true) {
      ops[2] = *pn;
      second = true;
    } else {
      ops[0] = *pn;
      first = true;
    }
  }
}

static void equals(GtkWidget *widget, gpointer user_data) {
  g_print(ops);

  if (ops[1] == '+') {
    *ans = ops[0] + ops[2];
    g_snprintf(ans2, sizeof ans, "\n%f", *ans);
    g_print(ans2);
  } else if (ops[1] == '-') {
    *ans = ops[0] - ops[2];
  } else if (ops[1] == '*') {
    *ans = ops[0] * ops[2];
  } else if (ops[1] == '/') {
    *ans = (float)ops[0] / ops[2];
  }

  g_snprintf(lab, sizeof lab, "%f", ans);
  gtk_label_set_text(GTK_LABEL(anslabel), lab);
  g_print("\n");
  g_print(lab);
}

static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button9;
  GtkWidget *button8;
  GtkWidget *button7;
  GtkWidget *button6;
  GtkWidget *button5;
  GtkWidget *button4;
  GtkWidget *button3;
  GtkWidget *button2;
  GtkWidget *button1;
  GtkWidget *plusbutton;
  GtkWidget *minusbutton;
  GtkWidget *multibutton;
  GtkWidget *divbutton;
  GtkWidget *eqbutton;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Calculator");
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

  grid = gtk_grid_new();
  gtk_grid_set_row_spacing(GTK_GRID(grid), 6);
  gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
  gtk_window_set_child(GTK_WINDOW(window), grid);

  button9 = gtk_button_new_with_label("9");
  g_signal_connect(button9, "clicked", G_CALLBACK(add_char), ni);

  button8 = gtk_button_new_with_label("8");
  g_signal_connect(button8, "clicked", G_CALLBACK(add_char), ei);

  button7 = gtk_button_new_with_label("7");
  g_signal_connect(button7, "clicked", G_CALLBACK(add_char), se);

  button6 = gtk_button_new_with_label("6");
  g_signal_connect(button6, "clicked", G_CALLBACK(add_char), si);

  button5 = gtk_button_new_with_label("5");
  g_signal_connect(button5, "clicked", G_CALLBACK(add_char), fi);

  button4 = gtk_button_new_with_label("4");
  g_signal_connect(button4, "clicked", G_CALLBACK(add_char), fo);

  button3 = gtk_button_new_with_label("3");
  g_signal_connect(button3, "clicked", G_CALLBACK(add_char), th);

  button2 = gtk_button_new_with_label("2");
  g_signal_connect(button2, "clicked", G_CALLBACK(add_char), tw);

  button1 = gtk_button_new_with_label("1");
  g_signal_connect(button1, "clicked", G_CALLBACK(add_char), on);

  plusbutton = gtk_button_new_with_label("+");
  g_signal_connect(plusbutton, "clicked", G_CALLBACK(add_char), pl);

  minusbutton = gtk_button_new_with_label("-");
  g_signal_connect(minusbutton, "clicked", G_CALLBACK(add_char), mi);

  multibutton = gtk_button_new_with_label("x");
  g_signal_connect(multibutton, "clicked", G_CALLBACK(add_char), mu);

  divbutton = gtk_button_new_with_label("/");
  g_signal_connect(multibutton, "clicked", G_CALLBACK(add_char), di);

  eqbutton = gtk_button_new_with_label("=");
  g_signal_connect(eqbutton, "clicked", G_CALLBACK(equals), NULL);

  g_snprintf(lab, sizeof lab, "%f", ans);
  anslabel = gtk_label_new(lab);

  gtk_grid_attach(GTK_GRID(grid), button1, 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button2, 1, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button3, 2, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button4, 0, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button5, 1, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button6, 2, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button7, 0, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button8, 1, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button9, 2, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), plusbutton, 3, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), minusbutton, 3, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), multibutton, 3, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), divbutton, 3, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), eqbutton, 2, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), anslabel, 0, 4, 2, 1);

  gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  printf("\n %c", ops[0]);
  printf("\n %c", ops[1]);
  printf("\n %c", ops[2]);

  return status;
}
