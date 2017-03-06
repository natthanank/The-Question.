#include <gtk/gtk.h>
#include <string.h>
#include <time.h>

clock_t t0, t1;

int score = 0, score_level_1 = 0, score_level_2 = 0, score_level_3 = 0;

static void menu(GtkWidget *menu_item, gpointer data);
static void close_window(GtkWidget *widget, gpointer data);
static void home(GtkWidget *widget, gpointer data);
static void level_1(GtkWidget *widget, gpointer data);
static void level_2(GtkWidget *widget, gpointer data);
static void level_3(GtkWidget *widget, gpointer data);
static void quest_1(GtkWidget *widget, gpointer data);
static void quest_2(GtkWidget *widget, gpointer data);
static void quest_3(GtkWidget *widget, gpointer data);
static void quest_4(GtkWidget *widget, gpointer data);
static void quest_5(GtkWidget *widget, gpointer data);
static void quest_6(GtkWidget *widget, gpointer data);
static void quest_7(GtkWidget *widget, gpointer data);
static void quest_8(GtkWidget *widget, gpointer data);
static void quest_9(GtkWidget *widget, gpointer data);
static void quest_10(GtkWidget *widget, gpointer data);
static void quest_11(GtkWidget *widget, gpointer data);
static void quest_12(GtkWidget *widget, gpointer data);
static void quest_13(GtkWidget *widget, gpointer data);
static void quest_14(GtkWidget *widget, gpointer data);
static void quest_15(GtkWidget *widget, gpointer data);
static void quest_16(GtkWidget *widget, gpointer data);
static void quest_17(GtkWidget *widget, gpointer data);
static void quest_18(GtkWidget *widget, gpointer data);
static void quest_19(GtkWidget *widget, gpointer data);
static void quest_20(GtkWidget *widget, gpointer data);
static void quest_21(GtkWidget *widget, gpointer data);
static void quest_22(GtkWidget *widget, gpointer data);
static void quest_23(GtkWidget *widget, gpointer data);
static void quest_24(GtkWidget *widget, gpointer data);
static void quest_25(GtkWidget *widget, gpointer data);
static void quest_26(GtkWidget *widget, gpointer data);
static void quest_27(GtkWidget *widget, gpointer data);
static void quest_28(GtkWidget *widget, gpointer data);
static void quest_29(GtkWidget *widget, gpointer data);
static void quest_30(GtkWidget *widget, gpointer data);
static void last(GtkWidget *widget, gpointer data);
static void count_score();
static void count_score_level_1();
static void count_score_level_2();

static void menu(GtkWidget *menu_item, gpointer data)
{
	GtkWidget *window, *box, *button;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)));
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	if (strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "Help") == 0)
	{
		printf("Help\n");
	}
	if (strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "About This Program") == 0)
	{
		printf("About This Program\n");
	}
	if (strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "Creator") == 0)
	{
		printf("Creator\n");
	}
	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	button = gtk_button_new_with_label("OK");
	g_signal_connect(button, "clicked", G_CALLBACK(close_window), window);
	gtk_box_pack_start(GTK_BOX(box), button, TRUE, FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), box);
	gtk_widget_show_all(window);
}

static void close_window(GtkWidget *widget, gpointer data)
{
	gtk_widget_destroy(data);
}

static void home(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION.");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	image = gtk_image_new_from_file("rules.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	button = gtk_button_new_with_label("START");
	g_signal_connect(button, "clicked", G_CALLBACK(level_1), window);
	gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, FALSE, 0);

	gtk_widget_show_all(window);
}

static void level_1(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	score = 0;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	image = gtk_image_new_from_file("level 1.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	
	button = gtk_button_new_with_label("Go");
	g_signal_connect(button, "clicked", G_CALLBACK(quest_1), window);
	gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, FALSE, 0);

	gtk_widget_show_all(window);

}

static void quest_1(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/1.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);

	g_signal_connect(a, "clicked", G_CALLBACK(quest_2), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_2), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_2), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_2), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	t0 = clock();

	while(1)
	{
		t1 = clock();
		if((double)(t1-t0)/CLOCKS_PER_SEC >= 3)
		{
			G_CALLBACK(level_2);
		}
	}

	gtk_widget_show_all(window);
}

static void quest_2(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/2.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_3), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_3), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_3), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_3), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_3(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/3.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_4), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_4), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_4), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_4), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_4(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/4.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_5), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_5), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_5), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_5), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_5(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/5.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_6), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_6), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_6), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_6), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_6(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/6.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_7), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_7), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_7), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_7), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_7(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/7.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_8), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_8), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_8), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_8), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_8(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/8.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_9), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_9), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_9), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_9), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_9(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/9.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_10), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_10), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_10), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_10), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_10(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/10.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_11), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_11), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_11), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_11), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_11(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/11.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_12), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_12), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_12), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_12), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_12(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/12.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_13), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_13), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_13), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_13), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_13(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/13.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_14), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_14), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_14), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_14), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_14(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/14.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_15), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_15), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_15), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_15), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_15(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/15.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_1), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(level_2), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(level_2), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(level_2), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(level_2), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}


static void level_2(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 2");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	if (score >= 10)
	{
		
		image = gtk_image_new_from_file("level 2.png");
		gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

		hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

		button = gtk_button_new_with_label("Go");
		g_signal_connect(button, "clicked", G_CALLBACK(quest_16), window);
		gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, FALSE, 0);
	}

	else 
	{
		image = gtk_image_new_from_file("lose.png");
		gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);


		switch (score_level_1)
	{
		case 1:
			image = gtk_image_new_from_file("score_1.png");
			break;
		case 2:
			image = gtk_image_new_from_file("score_2.png");
			break;
		case 3:
			image = gtk_image_new_from_file("score_3.png");
			break;
		case 4:
			image = gtk_image_new_from_file("score_4.png");
			break;
		case 5:
			image = gtk_image_new_from_file("score_5.png");
			break;
		case 6:
			image = gtk_image_new_from_file("score_6.png");
			break;
		case 7:
			image = gtk_image_new_from_file("score_7.png");
			break;
		case 8:
			image = gtk_image_new_from_file("score_8.png");
			break;
		case 9:
			image = gtk_image_new_from_file("score_9.png");
			break;
		case 10:
			image = gtk_image_new_from_file("score_10.png");
			break;
		case 11:
			image = gtk_image_new_from_file("score_11.png");
			break;
		case 12:
			image = gtk_image_new_from_file("score_12.png");
			break;
		case 13:
			image = gtk_image_new_from_file("score_13.png");
			break;
		case 14:
			image = gtk_image_new_from_file("score_14.png");
			break;
		case 15:
			image = gtk_image_new_from_file("score_15.png");
			break;
		default:
			image = gtk_image_new_from_file("score_0.png");
	}
		gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, FALSE, 0);

		hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

		button = gtk_button_new_with_label("Play Again?");
		g_signal_connect(button, "clicked", G_CALLBACK(level_1), window);
		gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, FALSE, 0);


	}
	

	gtk_widget_show_all(window);

}

static void quest_16(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 2");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/16.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_2), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_17), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_17), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_17), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_17), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_17(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 2");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/17.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_2), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_18), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_18), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_18), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_18), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_18(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 2");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/18.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_2), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_19), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_19), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_19), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_19), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_19(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 2");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/19.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_2), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_20), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_20), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_20), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_20), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_20(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 2");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/20.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_2), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_21), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_21), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_21), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_21), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_21(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 2");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/21.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_2), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_22), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_22), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_22), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_22), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_22(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 2");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/22.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_2), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_23), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_23), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_23), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_23), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_23(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 2");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/23.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_2), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_24), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_24), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_24), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_24), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_24(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 2");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/24.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_2), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(quest_25), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_25), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_25), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_25), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_25(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 2");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/25.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score
	g_signal_connect(a, "clicked", G_CALLBACK(count_score_level_2), NULL);
	g_signal_connect(a, "clicked", G_CALLBACK(level_3), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(level_3), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(level_3), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(level_3), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void level_3(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 3");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	if (score_level_2 >= 7)
	{
		
		image = gtk_image_new_from_file("level 3.png");
		gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

		hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

		button = gtk_button_new_with_label("Go");
		g_signal_connect(button, "clicked", G_CALLBACK(quest_26), window);
		gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, FALSE, 0);
	}

	else 
	{
		image = gtk_image_new_from_file("lose.png");
		gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

		switch (score_level_2)
	{
		case 1:
			image = gtk_image_new_from_file("score_1.png");
			break;
		case 2:
			image = gtk_image_new_from_file("score_2.png");
			break;
		case 3:
			image = gtk_image_new_from_file("score_3.png");
			break;
		case 4:
			image = gtk_image_new_from_file("score_4.png");
			break;
		case 5:
			image = gtk_image_new_from_file("score_5.png");
			break;
		case 6:
			image = gtk_image_new_from_file("score_6.png");
			break;
		case 7:
			image = gtk_image_new_from_file("score_7.png");
			break;
		default:
			image = gtk_image_new_from_file("score_0.png");

	}
		gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, FALSE, 0);
		hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

		button = gtk_button_new_with_label("Play Again?");
		g_signal_connect(button, "clicked", G_CALLBACK(level_1), window);
		gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, FALSE, 0);
	}
	

	gtk_widget_show_all(window);

}

static void quest_26(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 3");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/26.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score

	g_signal_connect(a, "clicked", G_CALLBACK(quest_27), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_27), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_27), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_27), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_27(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 3");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/27.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score

	g_signal_connect(a, "clicked", G_CALLBACK(quest_28), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_28), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_28), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_28), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_28(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 3");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/28.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score

	g_signal_connect(a, "clicked", G_CALLBACK(quest_29), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_29), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_29), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_29), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_29(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 3");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/29.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score

	g_signal_connect(a, "clicked", G_CALLBACK(quest_30), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(quest_30), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(quest_30), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(quest_30), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void quest_30(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button, *choice_1, *choice_2, *choice_3, *choice_4;
	GtkWidget *a, *b, *c, *d;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION. : LEVEL 3");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 50);

	image = gtk_image_new_from_file("QuestPic/30.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_1 = gtk_image_new_from_file("start.png");

	a = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(a), choice_1);
	g_signal_connect(a, "clicked", G_CALLBACK(count_score), NULL); // Count Score

	g_signal_connect(a, "clicked", G_CALLBACK(last), window);


	gtk_box_pack_start(GTK_BOX(hbox), a, TRUE, FALSE, 0);

	choice_2 = gtk_image_new_from_file("start.png");

	b = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(b), choice_2);
	g_signal_connect(b, "clicked", G_CALLBACK(last), window);
	gtk_box_pack_start(GTK_BOX(hbox), b, TRUE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	choice_3 = gtk_image_new_from_file("start.png");

	c = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(c), choice_3);
	g_signal_connect(c, "clicked", G_CALLBACK(last), window);
	gtk_box_pack_start(GTK_BOX(hbox), c, TRUE, FALSE, 0);

	choice_4 = gtk_image_new_from_file("start.png");

	d = gtk_button_new_with_label(NULL);
	gtk_button_set_image(GTK_BUTTON(d), choice_4);
	g_signal_connect(d, "clicked", G_CALLBACK(last), window);
	gtk_box_pack_start(GTK_BOX(hbox), d, TRUE, FALSE, 0);

	

	gtk_widget_show_all(window);
}

static void last(GtkWidget *widget, gpointer data)
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;

	gtk_widget_hide(data);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION.");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	if (score == 30)
	{
		hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

		image = gtk_image_new_from_file("win.png");
		gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	}

	else 
	{
		hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

		image = gtk_image_new_from_file("lose.png");
		gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	}
	
	switch (score)
	{
		case 17:
			image = gtk_image_new_from_file("score_17.png");
			break;
		case 18:
			image = gtk_image_new_from_file("score_18.png");
			break;
		case 19:
			image = gtk_image_new_from_file("score_19.png");
			break;
		case 20:
			image = gtk_image_new_from_file("score_20.png");
			break;
		case 21:
			image = gtk_image_new_from_file("score_21.png");
			break;
		case 22:
			image = gtk_image_new_from_file("score_22.png");
			break;
		case 23:
			image = gtk_image_new_from_file("score_23.png");
			break;
		case 24:
			image = gtk_image_new_from_file("score_24.png");
			break;
		case 25:
			image = gtk_image_new_from_file("score_25.png");
			break;
		case 26:
			image = gtk_image_new_from_file("score_26.png");
			break;
		case 27:
			image = gtk_image_new_from_file("score_27.png");
			break;
		case 28:
			image = gtk_image_new_from_file("score_28.png");
			break;
		case 29:
			image = gtk_image_new_from_file("score_29.png");
			break;
		case 30:
			image = gtk_image_new_from_file("score_30.png");
			break;
		default:
			image = gtk_image_new_from_file("score_0.png");
	}
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, FALSE, 0);
	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	button = gtk_button_new_with_label("Play Again?");
	g_signal_connect(button, "clicked", G_CALLBACK(level_1), window);
	gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, FALSE, 0);

	gtk_widget_show_all(window);

}


static void count_score()
{
	score += 1;
	printf("%d\n", score);
}

static void count_score_level_1()
{
	score_level_1 += 1;
}

static void count_score_level_2()
{
	score_level_2 += 1;
}

static void count_score_level_3()
{
	score_level_3 += 1;
}

int main(int argc, char *argv[])
{
	GtkWidget *window, *helpmenu, *help, *how_to_play, *vbox, *hbox, *menubar, *aboutmenu, *about, *about_program, *creator, *image, *button;
	GdkColor bg_color;
	bg_color.red = 0x0000;
	bg_color.green = 0x0000;
	bg_color.blue = 0x0000;


	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "THE QUESTION.");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &bg_color);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	aboutmenu = gtk_menu_new();
	about = gtk_menu_item_new_with_label("About");
	about_program = gtk_menu_item_new_with_label("About This Program");
	g_signal_connect(about_program, "activate", G_CALLBACK(menu), NULL);
	creator = gtk_menu_item_new_with_label("Creator");
	g_signal_connect(creator, "activate", G_CALLBACK(menu), NULL);
	helpmenu = gtk_menu_new();
	help = gtk_menu_item_new_with_label("Help");
	how_to_play = gtk_menu_item_new_with_label("Help");
	g_signal_connect(how_to_play, "activate", G_CALLBACK(menu), NULL);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), aboutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), about_program);
	gtk_menu_shell_append(GTK_MENU_SHELL(aboutmenu), creator);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), about);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), how_to_play);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	image = gtk_image_new_from_file("rules.png");
	gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	button = gtk_button_new_with_label(NULL);
	image = gtk_image_new_from_file("start.png");
	gtk_button_set_image(GTK_BUTTON(button), image);
	gtk_button_set_relief(GTK_BUTTON(button), GTK_RELIEF_NORMAL);
	g_signal_connect(button, "clicked", G_CALLBACK(level_1), window);
	gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, FALSE, 0);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;	
	
}