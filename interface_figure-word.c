#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

GtkWidget *window, *number_entry, *result_entry, *enter_button, *clear_button, *vbox, *hbox, *hbox1, *hbox2, *label1, *label2, *label3, *label4, *label5, *label6, *label7;
static void print_func(GtkWidget *button, gpointer data);
static void clear_func(GtkWidget *button, gpointer data);
static void destroy (GtkWidget *window, gpointer data);

void unit(unsigned long long );
void tens(unsigned long long );
void hundred(unsigned long long);
void hthousand(unsigned long long);
void hmillion (unsigned long long);
void billion(unsigned long long);
void hbillion(unsigned long long);
unsigned long int k;
unsigned long long number,temp_number;
int i,j=0,p;

int main(int argc, char *argv[])
{
	gtk_init (&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "converts from figures to words");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
	gtk_window_present(GTK_WINDOW(window));
	
	label1 = gtk_label_new("figure");
	label2 = gtk_label_new("words");
	label3= gtk_label_new("    ");
    label4= gtk_label_new(" ");
    label5= gtk_label_new(" ");
    label6= gtk_label_new(" ");
    label7= gtk_label_new(" ");
	number_entry = gtk_entry_new();
	result_entry = gtk_entry_new();
	enter_button = gtk_button_new_with_label("show");
	clear_button = gtk_button_new_with_label("clear");
	gtk_widget_set_size_request(enter_button, 40,40);
	hbox = gtk_hbox_new(TRUE,5);
	hbox1 = gtk_hbox_new(TRUE,10);
	hbox2 = gtk_hbox_new(TRUE,7);
	vbox = gtk_vbox_new(FALSE,10);
	
	gtk_box_pack_start(GTK_BOX(hbox), label1, TRUE,TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox), number_entry, TRUE,TRUE,0);
	gtk_box_pack_start(GTK_BOX(hbox), label3, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE,TRUE,0);
	gtk_box_pack_start(GTK_BOX(hbox1), label2, TRUE,TRUE,0);
	gtk_box_pack_start(GTK_BOX(hbox1), result_entry, TRUE,TRUE,0);
	gtk_box_pack_start(GTK_BOX(hbox1), label4, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox1, TRUE,TRUE,0);
	gtk_box_pack_start(GTK_BOX(hbox2), label5, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox2), enter_button, TRUE ,TRUE,0);
	gtk_box_pack_start(GTK_BOX(hbox2), clear_button, TRUE ,TRUE,0);
	gtk_box_pack_start(GTK_BOX(hbox2), label6, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox2, TRUE ,TRUE,0);
	gtk_box_pack_start(GTK_BOX(vbox), label7, TRUE ,TRUE,0);
     
	g_signal_connect(GTK_OBJECT(window), "destroy",GTK_SIGNAL_FUNC(destroy),NULL);
	g_signal_connect(GTK_OBJECT(enter_button), "clicked", GTK_SIGNAL_FUNC(print_func),NULL);
	g_signal_connect(GTK_OBJECT(clear_button), "clicked", GTK_SIGNAL_FUNC(clear_func),NULL);
	
	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_widget_show_all(vbox);
    gtk_widget_show_all(hbox);
    gtk_widget_show_all(hbox1);
    gtk_widget_show_all(hbox2);
	gtk_widget_show_all(window);
	
	gtk_main();
	
	return 0;
}

void print_func(GtkWidget *button, gpointer data){
	
	gtk_entry_set_max_length(GTK_ENTRY(number_entry),13);
	number=atoll(gtk_entry_get_text(GTK_ENTRY(number_entry)));
	
	if(number==0){
        gtk_entry_append_text(GTK_ENTRY(result_entry),"zero");
       return EXIT_SUCCESS;
    }
    else if(number==1000000000000){
        gtk_entry_append_text(GTK_ENTRY(result_entry),"one trillion");
        return EXIT_SUCCESS;
    }
    temp_number=number;
    //determining the numbers of digit "the variable number" has
    j=0;
    while(temp_number!=0){
        temp_number=temp_number/10;
        j++;
    }
    p=j;

    switch(p){
        case 1:
            unit(number);
            break;
        case 2:
			tens(number);
            break;
        case 3:
            k=number/100;
            unit(k);
            if((number%100)==0){gtk_entry_append_text(GTK_ENTRY(result_entry)," hundred ");}
            else{
            gtk_entry_append_text(GTK_ENTRY(result_entry)," hundred and ");}
            number=number%100;
            if(number<10){
            unit(number);}
            else{tens(number);}
            break;
        case 4:
            k=number/1000;
            unit(k);
            gtk_entry_append_text(GTK_ENTRY(result_entry)," thousand ");
            if((number%1000)==0){break;}
            number=number%1000;
            hundred(number);
            break;
        case 5:
            k=number/1000;
            tens(k);
            gtk_entry_append_text(GTK_ENTRY(result_entry)," thousand ");
            if((number%1000)==0){break;}
            number=number%1000;
            hundred(number);
            break;

        case 6:
            k=number/1000;
            hundred(k);
            gtk_entry_append_text(GTK_ENTRY(result_entry)," thousand ");
            if((number%1000)==0){break;}
            number=number%1000;
            hundred(number);
            break;
        case 7:
            k=number/1000000;
            unit(k);
            gtk_entry_append_text(GTK_ENTRY(result_entry)," million ");
            if((number%1000000)==0){break;}
            number=number%1000000;
            hthousand(number);
            break;
        case 8:
            k=number/1000000;
            tens(k);
            gtk_entry_append_text(GTK_ENTRY(result_entry)," million ");
            if((number%1000000)==0){break;}
            number=number%1000000;
            hthousand(number);
            break;
        case 9:
            k=number/1000000;
            hundred(k);
            gtk_entry_append_text(GTK_ENTRY(result_entry)," million ");
            if((number%1000000)==0){break;}
            number=number%1000000;
            hthousand(number);
            break;
        case 10:
            k=number/1000000000;
            unit(k);
            gtk_entry_append_text(GTK_ENTRY(result_entry)," billion ");
            if((number%1000000000)==0){break;}
            number=number%1000000000;
            hmillion(number);
            break;
        case 11:
            k=number/1000000000;
            tens(k);
            gtk_entry_append_text(GTK_ENTRY(result_entry)," billion ");
            if((number%1000000000)==0){break;}
            number=number%1000000000;
            hmillion(number);
            break;
        case 12:
            k=number/1000000000;
            hundred(k);
            gtk_entry_append_text(GTK_ENTRY(result_entry)," billion ");
            if((number%1000000000)==0){break;}
            number=number%1000000000;
            hmillion(number);
            break;
        default:
            gtk_entry_set_text(GTK_ENTRY(result_entry),"ERROR!!!!!sorry this program supports number from zero to one trillion");
            return EXIT_SUCCESS;
			break;
        }
}

//function definition to print from one to nine
void unit(unsigned long long number){
       switch(number){
case 0:
    gtk_entry_append_text(GTK_ENTRY(result_entry),"");
    break;
case 1:
    gtk_entry_append_text(GTK_ENTRY(result_entry)," one ");
    break;
case 2:
    gtk_entry_append_text(GTK_ENTRY(result_entry)," two ");
    break;
case 3:
    gtk_entry_append_text(GTK_ENTRY(result_entry)," three ");
    break;
case 4:
    gtk_entry_append_text(GTK_ENTRY(result_entry)," four ");
    break;
case 5:
    gtk_entry_append_text(GTK_ENTRY(result_entry)," five ");
    break;
case 6:
    gtk_entry_append_text(GTK_ENTRY(result_entry)," six ");
    break;
case 7:
    gtk_entry_append_text(GTK_ENTRY(result_entry)," seven ");
    break;
case 8:
    gtk_entry_append_text(GTK_ENTRY(result_entry)," eight ");
    break;
case 9:
    gtk_entry_append_text(GTK_ENTRY(result_entry)," nine ");
    break;
    }
}
void tens(unsigned long long number){
    int k;
        k=number/10;
            switch(k){
                case 1:
                    if(number==10){gtk_entry_append_text(GTK_ENTRY(result_entry)," ten");}if(number==11){gtk_entry_append_text(GTK_ENTRY(result_entry)," eleven");}
                    if(number==12){gtk_entry_append_text(GTK_ENTRY(result_entry)," twelve");}if(number==13){gtk_entry_append_text(GTK_ENTRY(result_entry)," thirteen");}
                    if(number==14){gtk_entry_append_text(GTK_ENTRY(result_entry)," fourteen");}if(number==15){gtk_entry_append_text(GTK_ENTRY(result_entry)," fifteen");}
                    if(number==16){gtk_entry_append_text(GTK_ENTRY(result_entry)," sixteen");}if(number==17){gtk_entry_append_text(GTK_ENTRY(result_entry)," seventeen");}
                    if(number==18){gtk_entry_append_text(GTK_ENTRY(result_entry)," eighteen");}if(number==19){gtk_entry_append_text(GTK_ENTRY(result_entry)," nineteen");}
                    break;
                case 2:
                    gtk_entry_append_text(GTK_ENTRY(result_entry)," twenty ");
                    number=number%10;
                    unit(number);
                    break;
                case 3:
                    gtk_entry_append_text(GTK_ENTRY(result_entry)," thirty  ");
                    number=number%10;
                    unit(number);
                    break;
                case 4:
                    gtk_entry_append_text(GTK_ENTRY(result_entry)," forty ");
                    number=number%10;
                    unit(number);
                    break;
                case 5:
                    gtk_entry_append_text(GTK_ENTRY(result_entry)," fifty ");
                    number=number%10;
                    unit(number);
                    break;
                case 6:
                    gtk_entry_append_text(GTK_ENTRY(result_entry)," sixty ");
                    number=number%10;
                    unit(number);
                    break;
                case 7:
                    gtk_entry_append_text(GTK_ENTRY(result_entry)," seventy ");
                    number=number%10;
                    unit(number);
                    break;
                case 8:
                    gtk_entry_append_text(GTK_ENTRY(result_entry)," eighty ");
                    number=number%10;
                    unit(number);
                    break;
                case 9:
                    gtk_entry_append_text(GTK_ENTRY(result_entry)," ninety ");
                    number=number%10;
                    unit(number);
                    break;
        }
}
void hundred(unsigned long long number){
k=number/100;
            unit(k);
            gtk_entry_append_text(GTK_ENTRY(result_entry)," hundred and ");
            number=number%100;
            if(number<10){
            unit(number);}
            else{tens(number);}
}
void hthousand(unsigned long long number){
k=number/1000;
            hundred(k);
            gtk_entry_append_text(GTK_ENTRY(result_entry)," thousand ");
            number=number%1000;
            hundred(number);
}
void hmillion(unsigned long long number){
k=number/1000000;
            hundred(k);
            gtk_entry_append_text(GTK_ENTRY(result_entry)," million ");
            number=number%1000000;
            hthousand(number);
}

static void destroy (GtkWidget *window, gpointer data)
{
	gtk_main_quit();
}

static void clear_func(GtkWidget *button, gpointer data)
{
	gtk_entry_set_text(GTK_ENTRY(result_entry)," ");
	gtk_entry_set_text(GTK_ENTRY(number_entry)," ");
	
}
