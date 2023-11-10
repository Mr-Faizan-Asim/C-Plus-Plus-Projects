#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <fstream>
#include <string>
using namespace std;
int rows_of_screen, columns_of_screen;
int rows_to_fit, columns_to_fit;
int screen_size();
void home_page();
void title(string content_inside_title);
void first_page_title();
void home_page();
void graph(int item_quantity[5], string show_instruments[5], double item_price[5]);
string take_username();
string take_password();
int to_show_five_persons_result(int marks[5][6], string batch_id[5], int total[5], int columns);
int to_add_data_in_array(int marks[5][6], int rows, int columns);
int to_show_report(string address);
void print_start_box(int rows, int columns);
void print_line(int start_point,int row,int end_point);
int user_id();
int to_get_inputs(int name[5]);
void to_print_in_title(string content_inside_title);
int to_show_six_menu(string menu_names[6]);
int selected_field();
string id_take_to_fetch();
int to_show_soldiers_under_officers(string batch_id);
int to_add_retire_and_single(string address);
string fetcher(string address);
double calculate_instruments_price(int item_quantity[5], double item_price[5]);
int to_show_three_menu(string menu_name[3]);
int to_show_six_personal_details(string menu_name[6]);
int fetch_and_check_id_from_txt(string personal_details_options[6], string batch_id, string batch_id_address, string name_address, string f_name_address, string provience_address, string rank_address, string age_address);
int yes_or_no(int perior_option);
int to_show_data(string address);
int to_add_data_in_txt(string personal_details_options[6], string batch_id_address, string name_address, string f_name_address, string provience_address, string rank_address, string age_address);
int to_view_matryed(string address);
int to_show_eight_menu(string menu_name[8]);
int fetch_and_check_provience_from_txt(string personal_details_options[6], string provience, string batch_id_address, string name_address, string f_name_address, string provience_address, string rank_address, string age_address);
int army_management_team_system(int checker_of_user_domain);		 // 1
int navy_management_team_system(int checker_of_user_domain);		 // 2
int air_force_management_team_system(int checker_of_user_domain);	 // 3
int army_officer_management_system(int checker_of_user_domain);		 // 4
int navy_officer_management_system(int checker_of_user_domain);		 // 5
int air_force_officer_management_system(int checker_of_user_domain); // 6
int soldiers_management_system(int checker_of_user_domain);			 // 7
void gotoxy(int x, int y);
int fetch_and_check_crops(string province, string batch_id_address, string name_address, string provience_address);
char getCharAtxy(short int x, short int y);
int main()
{
	// Domain ams afms afms aoms noms foms sms
	int checker_of_user_domain;
// move thier and also check the screen size facility
user_login:
	screen_size();
	checker_of_user_domain = user_id();
	// AMS RETURN 1 BY USER ID FOR TRUE
	if (checker_of_user_domain == 1)
	{
		army_management_team_system(checker_of_user_domain);
		goto user_login;
	}
	// NMS RETURN 2 BY USER ID FOR TRUE
	if (checker_of_user_domain == 2)
	{
		navy_management_team_system(checker_of_user_domain);
		goto user_login;
	}
	// AFMS
	if (checker_of_user_domain == 3)
	{
		air_force_management_team_system(checker_of_user_domain);
		goto user_login;
	}
	// AOMS
	if (checker_of_user_domain == 4)
	{
		army_officer_management_system(checker_of_user_domain);
		goto user_login;
	}
	if (checker_of_user_domain == 5)
	{
		navy_officer_management_system(checker_of_user_domain);
		goto user_login;
	}

	if (checker_of_user_domain == 6)
	{
		air_force_officer_management_system(checker_of_user_domain);
		goto user_login;
	}
	if (checker_of_user_domain == 7)
	{
		soldiers_management_system(checker_of_user_domain);
		goto user_login;
	}
}
// 1. ARMY MANAGEMENT SYSTEM
int army_management_team_system(int checker_of_user_domain)
{
	int sub_selected_instruments;
	string batch_id, personal_details_fetcher[5];
	string main_menu_names_ams[6] = {"1. ARMY SOLDIERS", "2. ARMY OFFICERS", "3. INSTRUMENTS", "4. CROPS", "5. REPORT OF ARMY WORK", "6. BACK"};
	string sub_menu_army_soldiers[6] = {"1. PERSONAL DETAILS", "2. ADD NEW SOLDIER", "3. EDIT SOLDIER DETAIL", "4. RETIRED GENERIALS", "5. MARTYRED", "6. BACK"};
	string sub_menu_instruments[6] = {"1. DETAILS OF INSTRUMENT", "2. ADD NEW INSTRUMENTS", "3. EDIT INSTRUMENT DETAIL", "4. GRAPH OF INSTRUMENTS(RESULT OF BUDGET)", "5. BUDGET OF INSTRUMENT", "6. BACK"};
	string personal_details_options[6] = {"SOLDIER NAME      : ", "SOLDIER FATHER    : ", "SOLDIER BATCH ID  : ", "SOLDIER PROVIENCE : ", "SOLDIER RANK : ", "SOLDIER AGE : "};
	string retired_options[3] = {"1. VIEW RETIRED ", "2. ADD NEW RETIRED MEN", "3. BACK"};
	string personal_details_options_officers[6] = {"OFFICERS NAME      : ", "OFFICERS FATHER    : ", "OFFICERS BATCH ID  : ", "OFFICERS PROVIENCE : ", "OFFICERS RANK : ", "OFFICERS AGE : "};
	string sub_menu_army_officers[8] = {"1. PERSONAL DETAILS", "2. ADD NEW OFFICERS", "3. EDIT OFFICER DETAILS", "4. RETIRED GENERIALS", "5. MARTYRED", "6. OFFICERS IN PROVIENCE", "7. SOLDIERS UNDER OFFICERS", "8. BACK"};
	string sub_of_sub_menu_instruments[6] = {"1. CARRIERS", "2. WEAPONS", "3. MISSILES", "4. TANKS", "5. ATOMIC BOMBS", "6. BACK"};
	string show_instruments[6] = {"1. CARRIERS", "2. WEAPONS", "3. MISSILES", "4. TANKS", "5. ATOMIC BOMBS", "6. BACK"};
	string show_instruments_graph[5] = {"CARRIERS", "WEAPONS", "MISSILES", "TANKS", "ATOMIC BOMBS"};

	int main_selected_option_of_ams;
	int sub_select_of_army_instruments_ams, sub_select_of_army_soldier_ams, sub_select_of_army_officer_ams;
	int item_quantity[5];
// Main Menu of ARMY TEAM MANAGEMENT SYSTEM
ams_top_menu:
	title("ARMY TEAM MANAGEMENT SYSTEM");
	to_show_six_menu(main_menu_names_ams);
	main_selected_option_of_ams = selected_field();
	// army soldiers in ams // MISSING 3 ALL
	while (main_selected_option_of_ams == 1)
	{
	army_soldiers_menu:
		title("ARMY TEAM MANAGEMENT SYSTEM");
		to_show_six_menu(sub_menu_army_soldiers);
		sub_select_of_army_soldier_ams = selected_field();
		// View Personal details of Soldiers
		while (sub_select_of_army_soldier_ams == 1)
		{
			int check_batch_id;
			title("PERSONAL DETAILS OF ARMY SOLDIER");
			batch_id = id_take_to_fetch();
			check_batch_id = fetch_and_check_id_from_txt(personal_details_options, batch_id, "ams_army_soldiers_batch_id.txt", "ams_army_soldiers_name.txt", "ams_army_soldiers_father_name.txt", "ams_army_soldiers_provience.txt", "ams_army_soldiers_rank.txt", "ams_army_soldiers_age.txt");
			if (check_batch_id == 1)
			{
				sub_select_of_army_soldier_ams = yes_or_no(sub_select_of_army_soldier_ams);
				if (sub_select_of_army_soldier_ams == 0)
				{
					goto army_soldiers_menu;
				}
			}
			else
			{
				gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 10);
				cout << "INVALID !";
				Sleep(2000);
			}
		}
		// ADD NEW RECORD
		while (sub_select_of_army_soldier_ams == 2)
		{
			title("ADD DETAILS OF ARMY OFFICER");
			to_add_data_in_txt(personal_details_options, "ams_army_soldiers_batch_id.txt", "ams_army_soldiers_name.txt", "ams_army_soldiers_father_name.txt", "ams_army_soldiers_provience.txt", "ams_army_soldiers_rank.txt", "ams_army_soldiers_age.txt");
			sub_select_of_army_soldier_ams = yes_or_no(sub_select_of_army_soldier_ams);
			if (sub_select_of_army_soldier_ams == 0)
			{
				goto army_soldiers_menu;
			}
		}
		// RETIRED OFFICERS
		while (sub_select_of_army_soldier_ams == 4)
		{
			int sub_option_of_retired_officers;
			title("RETIRED OFFICERS MANAGEMENT");
			to_show_three_menu(retired_options);
			sub_option_of_retired_officers = selected_field();
			if (sub_option_of_retired_officers == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("RETIRED OFFICERS AND SOLDIERS");
				to_show_data("ams_army_soldiers_retired.txt");
				sub_option_of_retired_officers = yes_or_no(sub_option_of_retired_officers);
			}
			else if (sub_option_of_retired_officers == 2)
			{
				title("RETIRED ADDING SYSTEM");
				to_add_retire_and_single("ams_army_soldiers_retired.txt");
				sub_option_of_retired_officers = yes_or_no(sub_option_of_retired_officers);
			}
			else if (sub_option_of_retired_officers == 3)
			{
				goto army_soldiers_menu;
			}
		}
		// MATRYED
		while (sub_select_of_army_soldier_ams == 5)
		{
			system("cls");
			int sub_option_of_matryed_officers;
			string matryed_option[3] = {"1. VIEW HEROES OF NATION", "2. ADD NEW MATRYED", "3.BACK"};
			title("HEROES OF OUR NATION");
			to_show_three_menu(matryed_option);
			sub_option_of_matryed_officers = selected_field();
			if (sub_option_of_matryed_officers == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("HEROES OF OUR NATION");
				to_view_matryed("amu_army_soldiers_martyred.txt");
				gotoxy(columns_of_screen / 2 - 15, 7);
				cout << "PRESS 3 KEY TO GO BACK .....";
				gotoxy(columns_of_screen / 2 + 17, 7);
				cin >> sub_option_of_matryed_officers;
			}
			else if (sub_option_of_matryed_officers == 2)
			{
				title("HEROES OF OUR NATION");
				to_add_retire_and_single("amu_army_soldiers_martyred.txt");
				sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
			}
			else if (sub_option_of_matryed_officers == 3)
			{
				goto army_soldiers_menu;
			}
		}
		// GO TO AGAIN LOG IN
		while (sub_select_of_army_soldier_ams == 6)
		{
			goto ams_top_menu;
		}
	}
	// ARMY OFFICERS IN AMS // NOT WORKING 7
	while (main_selected_option_of_ams == 2)
	{
		string address_batch_id = "army_officers_ams/ams_army_officers_batch_id.txt", address_name = "army_officers_ams/ams_army_officers_name.txt", address_father_name = "army_officers_ams/ams_army_officers_father_name.txt", address_provience = "army_officers_ams/ams_army_officers_provience.txt", address_rank = "army_officers_ams/ams_army_officers_rank.txt", address_age = "army_officers_ams/ams_army_officers_age.txt";
	army_officers_menu:
		title("ARMY TEAM MANAGEMENT SYSTEM");
		to_show_eight_menu(sub_menu_army_officers);
		sub_select_of_army_officer_ams = selected_field();
		// View Personal details of Soldiers
		while (sub_select_of_army_officer_ams == 1)
		{
			int check_batch_id;
			title("PERSONAL DETAILS OF ARMY OFFICER");
			batch_id = id_take_to_fetch();
			check_batch_id = fetch_and_check_id_from_txt(personal_details_options_officers, batch_id, address_batch_id, address_name, address_father_name, address_provience, address_rank, address_age);
			if (check_batch_id == 1)
			{
				sub_select_of_army_officer_ams = yes_or_no(sub_select_of_army_officer_ams);
				if (sub_select_of_army_officer_ams == 0)
				{
					goto army_officers_menu;
				}
			}
			else
			{
				gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 10);
				cout << "INVALID !";
				Sleep(2000);
			}
		}
		// ADD NEW RECORD
		while (sub_select_of_army_officer_ams == 2)
		{
			title("ADD DETAILS OF ARMY OFFICER");
			to_add_data_in_txt(personal_details_options_officers, address_batch_id, address_name, address_father_name, address_provience, address_rank, address_age);
			sub_select_of_army_officer_ams = yes_or_no(sub_select_of_army_officer_ams);
			if (sub_select_of_army_officer_ams == 0)
			{
				goto army_officers_menu;
			}
		}
		// RETIRED OFFICERS
		while (sub_select_of_army_officer_ams == 4)
		{
			int sub_option_of_retired_officers;
			title("RETIRED OFFICERS MANAGEMENT");
			to_show_three_menu(retired_options);
			sub_option_of_retired_officers = selected_field();
			if (sub_option_of_retired_officers == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("RETIRED OFFICERS AND SOLDIERS");
				to_show_data("ams_army_soldiers_retired.txt");
				sub_option_of_retired_officers = yes_or_no(sub_option_of_retired_officers);
			}
			else if (sub_option_of_retired_officers == 2)
			{
				title("RETIRED ADDING SYSTEM");
				to_add_retire_and_single("ams_army_soldiers_retired.txt");
				sub_option_of_retired_officers = yes_or_no(sub_option_of_retired_officers);
			}
			else if (sub_option_of_retired_officers == 3)
			{
				goto army_officers_menu;
			}
		}
		// MATRYED
		while (sub_select_of_army_officer_ams == 5)
		{
			system("cls");
			int sub_option_of_matryed_officers;
			string matryed_option[3] = {"1. VIEW HEROES OF NATION", "2. ADD NEW MATRYED", "3.BACK"};
			title("HEROES OF OUR NATION");
			to_show_three_menu(matryed_option);
			sub_option_of_matryed_officers = selected_field();
			if (sub_option_of_matryed_officers == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("HEROES OF OUR NATION");
				to_view_matryed("amu_army_soldiers_martyred.txt");
				gotoxy(columns_of_screen / 2 - 15, 7);
				cout << "PRESS 3 KEY TO GO BACK .....";
				gotoxy(columns_of_screen / 2 + 17, 7);
				cin >> sub_option_of_matryed_officers;
			}
			else if (sub_option_of_matryed_officers == 2)
			{
				title("HEROES OF OUR NATION");
				to_add_retire_and_single("amu_army_soldiers_martyred.txt");
				sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
			}
			else if (sub_option_of_matryed_officers == 3)
			{
				goto army_officers_menu;
			}
		}
		// Officers in Provience
		while (sub_select_of_army_officer_ams == 6)
		{
			string provience;
			int count_officers;
			system("cls");
			print_start_box(5, columns_of_screen);
			to_print_in_title("OFFICERS IN PROVIENCES");
			gotoxy(columns_of_screen / 2 - 10, 9);
			cout << "PROVIENCE: ";
			gotoxy(columns_of_screen / 2 + 2, 9);
			cin >> provience;
			count_officers = fetch_and_check_provience_from_txt(personal_details_options_officers, provience, address_batch_id, address_name, address_father_name, address_provience, address_rank, address_age);
			gotoxy(columns_of_screen / 10, 10);
			cout << "\033[32m"
				 << "COUNTED OFFICERS: " << count_officers;
			gotoxy(columns_of_screen / 2 - 15, 7);
			cout << "PRESS ANY KEY TO GO BACK .....";
			getch();
			goto army_officers_menu;
		}
		// Soldiers under Officers
		//  NOT WORKING PROPERLY
		while (sub_select_of_army_officer_ams == 7)
		{
			string check_batch_id;
			title("SOLDIERS UNDER THE OFFICER");
			check_batch_id = id_take_to_fetch();
			/*
			to_show_soldiers_under_officers(check_batch_id);
			*/
		}
		// GO TO AGAIN LOG IN
		while (sub_select_of_army_officer_ams == 8)
		{
			goto ams_top_menu;
		}
	}
	// ARMY INSTRUMENTS // MISSING 3
	while (main_selected_option_of_ams == 3)
	{
	sub_menu_instruments:
		double instruments_price[5] = {20000, 12000, 50000, 80000, 100000};
		string address_carriers = "instruments_ams/ams_carriers.txt", address_weapons = "instruments_ams/ams_weapons.txt", address_missiles = "instruments_ams/ams_missiles.txt", address_tanks = "instruments_ams/ams_tanks.txt", address_atomic_bombs = "instruments_ams/ams_atomic_bombs.txt";
		int sub_of_sub_selected_instruments;
		title("ARMY TEAM MANAGEMENT SYSTEM");
		to_show_six_menu(sub_menu_instruments);
		sub_select_of_army_instruments_ams = selected_field();
		// VIEW INSTRUMENTS
		while (sub_select_of_army_instruments_ams == 1)
		{
			title("ARMY TEAM MANAGEMENT SYSTEM");
			to_show_six_menu(sub_of_sub_menu_instruments);
			sub_of_sub_selected_instruments = selected_field();

			// Carriers
			while (sub_of_sub_selected_instruments == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data("instruments_ams/ams_carriers.txt");
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// Weapons
			while (sub_of_sub_selected_instruments == 2)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data(address_weapons);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// missiles
			while (sub_of_sub_selected_instruments == 3)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data(address_missiles);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// tanks
			while (sub_of_sub_selected_instruments == 4)
			{

				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data(address_tanks);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// atomic Bomb
			while (sub_of_sub_selected_instruments == 5)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data(address_atomic_bombs);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// back
			while (sub_of_sub_selected_instruments == 6)
			{
				goto sub_menu_instruments;
			}
		}
		// Add INSTRUMENTS
		while (sub_select_of_army_instruments_ams == 2)
		{

			title("ARMY TEAM MANAGEMENT SYSTEM");
			to_show_six_menu(sub_of_sub_menu_instruments);
			sub_of_sub_selected_instruments = selected_field();
			while (sub_of_sub_selected_instruments == 1)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_carriers);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			while (sub_of_sub_selected_instruments == 2)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_weapons);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			while (sub_of_sub_selected_instruments == 3)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_missiles);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			while (sub_of_sub_selected_instruments == 4)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_tanks);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			while (sub_of_sub_selected_instruments == 5)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_atomic_bombs);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			if (sub_of_sub_selected_instruments == 6)
			{
				goto sub_menu_instruments;
			}
		}
		// graph
		while (sub_select_of_army_instruments_ams == 4)
		{
			system("cls");
			print_start_box(5, columns_of_screen);
			to_print_in_title("GRAPHING THE BUDGET");

			graph(item_quantity, show_instruments_graph, instruments_price);
			Sleep(5000);
			sub_select_of_army_instruments_ams = yes_or_no(sub_select_of_army_instruments_ams);
		}
		// Budget Calculate
		while (sub_select_of_army_instruments_ams == 5)
		{
			float total;
			title("CALCULATE THE ARMY BUDGET");
			to_show_six_menu(show_instruments);
			to_get_inputs(item_quantity);
			total = calculate_instruments_price(item_quantity, instruments_price);
			gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 2);
			cout << "TOTAL BUDGET:" << total;
			sub_select_of_army_instruments_ams = yes_or_no(sub_select_of_army_instruments_ams);
		}
		// Back
		while (sub_selected_instruments == 6 || sub_select_of_army_instruments_ams == 6)
		{
			goto ams_top_menu;
		}
	}
	// CROPS
	while (main_selected_option_of_ams == 4)
	{
		int sub_select_of_crops_ams;
		string crops[3] = {"1. XXX-KHOR", "2. SOC-KHOR", "3. BACK"};
	menu_crops:
		title("CROPS MANAGEMENT SYSTEM");
		to_show_three_menu(crops);
		sub_select_of_crops_ams = selected_field();
		while (sub_select_of_crops_ams == 1)
		{
			system("cls");
			print_start_box(5, columns_of_screen);
			to_print_in_title("CROPS MANAGEMENT SYSTEM");
			fetch_and_check_crops("PUNJAB", "ams_army_soldiers_batch_id.txt", "ams_army_soldiers_name.txt", "ams_army_soldiers_provience.txt");
			fetch_and_check_crops("KPK", "ams_army_soldiers_batch_id.txt", "ams_army_soldiers_name.txt", "ams_army_soldiers_provience.txt");
			fetch_and_check_crops("PUNJAB", "army_officers_ams/ams_army_officers_batch_id.txt", "army_officers_ams/ams_army_officers_name.txt", "army_officers_ams/ams_army_officers_provience.txt");
			fetch_and_check_crops("KPK", "army_officers_ams/ams_army_officers_batch_id.txt", "army_officers_ams/ams_army_officers_name.txt", "army_officers_ams/ams_army_officers_provience.txt");

			gotoxy(columns_of_screen / 2 - 15, 7);
			cout << "PRESS 3 KEY TO GO BACK .....";
			gotoxy(columns_of_screen / 2 + 17, 7);
			cin >> sub_select_of_crops_ams;
			if (sub_select_of_crops_ams == 0)
			{
				goto menu_crops;
			}
		}
		while (sub_select_of_crops_ams == 2)
		{
			system("cls");
			print_start_box(5, columns_of_screen);
			to_print_in_title("CROPS MANAGEMENT SYSTEM");
			fetch_and_check_crops("SINDH", "ams_army_soldiers_batch_id.txt", "ams_army_soldiers_name.txt", "ams_army_soldiers_provience.txt");
			fetch_and_check_crops("BALOCHISTAN", "ams_army_soldiers_batch_id.txt", "ams_army_soldiers_name.txt", "ams_army_soldiers_provience.txt");
			fetch_and_check_crops("SINDH", "army_officers_ams/ams_army_officers_batch_id.txt", "army_officers_ams/ams_army_officers_name.txt", "army_officers_ams/ams_army_officers_provience.txt");
			fetch_and_check_crops("BALOCHISTAN", "army_officers_ams/ams_army_officers_batch_id.txt", "army_officers_ams/ams_army_officers_name.txt", "army_officers_ams/ams_army_officers_provience.txt");

			gotoxy(columns_of_screen / 2 - 15, 7);
			cout << "PRESS 3 KEY TO GO BACK .....";
			gotoxy(columns_of_screen / 2 + 17, 7);
			cin >> sub_select_of_crops_ams;
			if (sub_select_of_crops_ams == 0)
			{
				goto menu_crops;
			}
		}

		if (sub_select_of_crops_ams == 3)
		{
			goto ams_top_menu;
		}
	}
	// Report of work
	while (main_selected_option_of_ams == 5)
	{
		system("cls");
		print_start_box(5, columns_of_screen);
		to_print_in_title("REPORT OF ARMY WORK");
		to_show_report("Report/army_report.txt");
		gotoxy(columns_of_screen / 2 - 15, 7);
		cout << "PRESS 3 KEY TO GO BACK .....";
		gotoxy(columns_of_screen / 2 + 17, 7);
		cin >> main_selected_option_of_ams;
		if (main_selected_option_of_ams == 0)
		{
			goto ams_top_menu;
		}
	}
}
// 1. ARMY MANAGEMENT SYSTEM ENDED

// 2. NAVY MANAGEMENT SYSTEM
int navy_management_team_system(int checker_of_user_domain)
{

	int sub_selected_instruments;
	string batch_id, personal_details_fetcher[5];
	string main_menu_names_nms[6] = {"1. NAVY SOLDIERS", "2. NAVY OFFICERS", "3. INSTRUMENTS", "4. CROPS", "5. REPORT OF NAVY WORK", "6. BACK"};
	string sub_menu_navy_soldiers[6] = {"1. PERSONAL DETAILS", "2. ADD NEW SOLDIER", "3. EDIT SOLDIER DETAIL", "4. RETIRED NAVY OFFICERS", "5. MARTYRED", "6. BACK"};
	string sub_menu_instruments[6] = {"1. DETAILS OF INSTRUMENT", "2. ADD NEW INSTRUMENTS", "3. EDIT INSTRUMENT DETAIL", "4. GRAPH OF INSTRUMENTS(RESULT OF BUDGET)", "5. BUDGET OF INSTRUMENT", "6. BACK"};
	string personal_details_options[6] = {"SOLDIER NAME      : ", "SOLDIER FATHER    : ", "SOLDIER BATCH ID  : ", "SOLDIER PROVIENCE : ", "SOLDIER RANK : ", "SOLDIER AGE : "};
	string retired_options[3] = {"1. VIEW RETIRED ", "2. ADD NEW RETIRED MEN", "3. BACK"};
	string personal_details_options_officers[6] = {"OFFICERS NAME      : ", "OFFICERS FATHER    : ", "OFFICERS BATCH ID  : ", "OFFICERS PROVIENCE : ", "OFFICERS RANK : ", "OFFICERS AGE : "};
	string sub_menu_navy_officers[8] = {"1. PERSONAL DETAILS", "2. ADD NEW OFFICERS", "3. EDIT OFFICER DETAILS", "4. RETIRED NAVY OFFICERS", "5. MARTYRED", "6. OFFICERS IN PROVIENCE", "7. SOLDIERS UNDER OFFICERS", "8. BACK"};
	string sub_of_sub_menu_instruments[6] = {"1. AIR CRAFTS", "2. WEAPONS", "3. MISSILES", "4. SUBARINE", "5. SURFACE SHIPS", "6. BACK"};
	string show_instruments[6] = {"1. AIR CRAFT", "2. WEAPONS", "3. MISSILES", "4. SUBMARINE", "5. SURFACE SHIPS", "6. BACK"};
	string show_instruments_graph[5] = {"AIR CRAFT", "WEAPONS", "MISSILES", "SUBMARINE", "SURFACE SHIPS"};

	int main_selected_option_of_nms;
	int sub_select_of_navy_instruments_nms, sub_select_of_navy_soldier_nms, sub_select_of_navy_officer_nms;
	int item_quantity[5];
// Main Menu of NAVY TEAM MANAGEMENT SYSTEM
nms_top_menu:
	title("NAVY TEAM MANAGEMENT SYSTEM");
	to_show_six_menu(main_menu_names_nms);
	main_selected_option_of_nms = selected_field();
	// army soldiers in ams // MISSING 3 ALL
	while (main_selected_option_of_nms == 1)
	{
	navy_soldiers_menu:
		title("NAVY TEAM MANAGEMENT SYSTEM");
		to_show_six_menu(sub_menu_navy_soldiers);
		sub_select_of_navy_soldier_nms = selected_field();
		// View Personal details of Soldiers
		while (sub_select_of_navy_soldier_nms == 1)
		{
			int check_batch_id;
			title("PERSONAL DETAILS OF NAVY SOLDIER");
			batch_id = id_take_to_fetch();

			check_batch_id = fetch_and_check_id_from_txt(personal_details_options, batch_id, "navy_soldiers_nms/nms_army_soldiers_batch_id.txt", "navy_soldiers_nms/nms_army_soldiers_name.txt", "navy_soldiers_nms/nms_army_soldiers_father_name.txt", "navy_soldiers_nms/nms_army_soldiers_provience.txt", "navy_soldiers_nms/nms_army_soldiers_rank.txt", "navy_soldiers_nms/nms_army_soldiers_age.txt");
			if (check_batch_id == 1)
			{
				sub_select_of_navy_soldier_nms = yes_or_no(sub_select_of_navy_soldier_nms);
				if (sub_select_of_navy_soldier_nms == 0)
				{
					goto navy_soldiers_menu;
				}
			}
			else
			{
				gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 10);
				cout << "INVALID !";
				Sleep(2000);
			}
		}
		// ADD NEW RECORD
		while (sub_select_of_navy_soldier_nms == 2)
		{
			title("ADD DETAILS OF ARMY OFFICER");
			to_add_data_in_txt(personal_details_options, "navy_soldiers_nms/nms_army_soldiers_batch_id.txt", "navy_soldiers_nms/nms_army_soldiers_name.txt", "navy_soldiers_nms/nms_army_soldiers_father_name.txt", "navy_soldiers_nms/nms_army_soldiers_provience.txt", "navy_soldiers_nms/nms_army_soldiers_rank.txt", "navy_soldiers_nms/nms_army_soldiers_age.txt");
			sub_select_of_navy_soldier_nms = yes_or_no(sub_select_of_navy_soldier_nms);
			if (sub_select_of_navy_soldier_nms == 0)
			{
				goto navy_soldiers_menu;
			}
		}
		// RETIRED Soldiers
		while (sub_select_of_navy_soldier_nms == 4)
		{
			int sub_option_of_retired_officers;
			title("RETIRED OFFICERS MANAGEMENT");
			to_show_three_menu(retired_options);
			sub_option_of_retired_officers = selected_field();
			if (sub_option_of_retired_officers == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("RETIRED OFFICERS AND SOLDIERS");
				to_show_data("navy_soldiers_nms/nms_army_soldiers_retired.txt");
				sub_option_of_retired_officers = yes_or_no(sub_option_of_retired_officers);
			}
			else if (sub_option_of_retired_officers == 2)
			{
				title("RETIRED ADDING SYSTEM");
				to_add_retire_and_single("navy_soldiers_nms/nms_army_soldiers_retired.txt");
				sub_option_of_retired_officers = yes_or_no(sub_option_of_retired_officers);
			}
			else if (sub_option_of_retired_officers == 3)
			{
				goto navy_soldiers_menu;
			}
		}
		// MATRYED
		while (sub_select_of_navy_soldier_nms == 5)
		{
			system("cls");
			int sub_option_of_matryed_officers;
			string matryed_option[3] = {"1. VIEW HEROES OF NATION", "2. ADD NEW MATRYED", "3.BACK"};
			title("HEROES OF OUR NATION");
			to_show_three_menu(matryed_option);
			sub_option_of_matryed_officers = selected_field();
			if (sub_option_of_matryed_officers == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("HEROES OF OUR NATION");
				to_view_matryed("navy_soldiers_nms/nmu_army_soldiers_martyred.txt");
				gotoxy(columns_of_screen / 2 - 15, 7);
				cout << "PRESS 3 KEY TO GO BACK .....";
				gotoxy(columns_of_screen / 2 + 17, 7);
				cin >> sub_option_of_matryed_officers;
			}
			else if (sub_option_of_matryed_officers == 2)
			{
				title("HEROES OF OUR NATION");
				to_add_retire_and_single("navy_soldiers_nms/nmu_army_soldiers_martyred.txt");
				sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
			}
			else if (sub_option_of_matryed_officers == 3)
			{
				goto navy_soldiers_menu;
			}
		}
		// GO TO AGAIN LOG IN
		while (sub_select_of_navy_soldier_nms == 6)
		{
			goto nms_top_menu;
		}
	}
	// ARMY OFFICERS IN AMS // NOT WORKING 7
	while (main_selected_option_of_nms == 2)
	{
		string address_batch_id = "navy_officers_nms/nms_army_officers_batch_id.txt", address_name = "navy_officers_nms/nms_army_officers_name.txt", address_father_name = "navy_officers_nms/nms_army_officers_father_name.txt", address_provience = "navy_officers_nms/nms_army_officers_provience.txt", address_rank = "navy_officers_nms/nms_army_officers_rank.txt", address_age = "navy_officers_nms/nms_army_officers_age.txt";
	navy_officers_menu:
		title("NAVY TEAM MANAGEMENT SYSTEM");
		to_show_eight_menu(sub_menu_navy_officers);
		sub_select_of_navy_officer_nms = selected_field();
		// View Personal details of officers
		while (sub_select_of_navy_officer_nms == 1)
		{
			int check_batch_id;
			title("PERSONAL DETAILS OF NAVY OFFICER");
			batch_id = id_take_to_fetch();
			check_batch_id = fetch_and_check_id_from_txt(personal_details_options_officers, batch_id, address_batch_id, address_name, address_father_name, address_provience, address_rank, address_age);
			if (check_batch_id == 1)
			{
				sub_select_of_navy_officer_nms = yes_or_no(sub_select_of_navy_officer_nms);
				if (sub_select_of_navy_officer_nms == 0)
				{
					goto navy_officers_menu;
				}
			}
			else
			{
				gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 10);
				cout << "INVALID !";
				Sleep(2000);
			}
		}
		// ADD NEW RECORD
		while (sub_select_of_navy_officer_nms == 2)
		{
			title("ADD DETAILS OF ARMY OFFICER");
			to_add_data_in_txt(personal_details_options_officers, address_batch_id, address_name, address_father_name, address_provience, address_rank, address_age);
			sub_select_of_navy_officer_nms = yes_or_no(sub_select_of_navy_officer_nms);
			if (sub_select_of_navy_officer_nms == 0)
			{
				goto navy_officers_menu;
			}
		}
		// RETIRED OFFICERS
		while (sub_select_of_navy_officer_nms == 4)
		{
			int sub_option_of_retired_officers;
			title("RETIRED OFFICERS MANAGEMENT");
			to_show_three_menu(retired_options);
			sub_option_of_retired_officers = selected_field();
			if (sub_option_of_retired_officers == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("RETIRED OFFICERS AND SOLDIERS");
				to_show_data("navy_soldiers_nms/nms_army_soldiers_retired.txt");
				sub_option_of_retired_officers = yes_or_no(sub_option_of_retired_officers);
			}
			else if (sub_option_of_retired_officers == 2)
			{
				title("RETIRED ADDING SYSTEM");
				to_add_retire_and_single("navy_soldiers_nms/nms_army_soldiers_retired.txt");
				sub_option_of_retired_officers = yes_or_no(sub_option_of_retired_officers);
			}
			else if (sub_option_of_retired_officers == 3)
			{
				goto navy_officers_menu;
			}
		}
		// MATRYED
		while (sub_select_of_navy_officer_nms == 5)
		{
			system("cls");
			int sub_option_of_matryed_officers;
			string matryed_option[3] = {"1. VIEW HEROES OF NATION", "2. ADD NEW MATRYED", "3.BACK"};
			title("HEROES OF OUR NATION");
			to_show_three_menu(matryed_option);
			sub_option_of_matryed_officers = selected_field();
			if (sub_option_of_matryed_officers == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("HEROES OF OUR NATION");
				to_view_matryed("navy_soldiers_nms/nmu_army_soldiers_martyred.txt");
				gotoxy(columns_of_screen / 2 - 15, 7);
				cout << "PRESS 3 KEY TO GO BACK .....";
				gotoxy(columns_of_screen / 2 + 17, 7);
				cin >> sub_option_of_matryed_officers;
			}
			else if (sub_option_of_matryed_officers == 2)
			{
				title("HEROES OF OUR NATION");
				to_add_retire_and_single("navy_soldiers_nms/nmu_army_soldiers_martyred.txt");
				sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
			}
			else if (sub_option_of_matryed_officers == 3)
			{
				goto navy_officers_menu;
			}
		}
		// Officers in Provience
		while (sub_select_of_navy_officer_nms == 6)
		{
			string provience;
			int count_officers;
			system("cls");
			print_start_box(5, columns_of_screen);
			to_print_in_title("OFFICERS IN PROVIENCES");
			gotoxy(columns_of_screen / 2 - 10, 9);
			cout << "PROVIENCE: ";
			gotoxy(columns_of_screen / 2 + 2, 9);
			cin >> provience;
			count_officers = fetch_and_check_provience_from_txt(personal_details_options_officers, provience, address_batch_id, address_name, address_father_name, address_provience, address_rank, address_age);
			gotoxy(columns_of_screen / 10, 10);
			cout << "\033[32m"
				 << "COUNTED OFFICERS: " << count_officers;
			gotoxy(columns_of_screen / 2 - 15, 7);
			cout << "PRESS ANY KEY TO GO BACK .....";
			getch();
			goto navy_officers_menu;
		}
		// Soldiers under Officers
		//  NOT WORKING PROPERLY
		while (sub_select_of_navy_officer_nms == 7)
		{
			string check_batch_id;
			title("SOLDIERS UNDER THE OFFICER");
			check_batch_id = id_take_to_fetch();
			/*
			to_show_soldiers_under_officers(check_batch_id);
			*/
		}
		// GO TO AGAIN LOG IN
		while (sub_select_of_navy_officer_nms == 8)
		{
			goto nms_top_menu;
		}
	}
	// ARMY INSTRUMENTS // MISSING 3
	while (main_selected_option_of_nms == 3)
	{
	sub_menu_instruments:
		double instruments_price[5] = {40000, 12000, 50000, 80000, 1000};
		string address_air_craft = "instruments_nms/nms_air_craft.txt", address_weapons = "instruments_nms/nms_gun_weapons.txt", address_missiles = "instruments_nms/nms_missiles.txt", address_sub = "instruments_nms/nms_submarine.txt", address_surface_ship = "instruments_nms/nms_surface_shipS.txt";
		int sub_of_sub_selected_instruments;
		title("NAVY TEAM MANAGEMENT SYSTEM");
		to_show_six_menu(sub_menu_instruments);
		sub_select_of_navy_instruments_nms = selected_field();
		// VIEW INSTRUMENTS
		while (sub_select_of_navy_instruments_nms == 1)
		{
			title("NAVY TEAM MANAGEMENT SYSTEM");
			to_show_six_menu(sub_of_sub_menu_instruments);
			sub_of_sub_selected_instruments = selected_field();

			// Air craft
			while (sub_of_sub_selected_instruments == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data(address_air_craft);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// Weapons
			while (sub_of_sub_selected_instruments == 2)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data(address_weapons);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// missiles
			while (sub_of_sub_selected_instruments == 3)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data(address_missiles);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// Submariene
			while (sub_of_sub_selected_instruments == 4)
			{

				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data(address_sub);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// surface ship
			while (sub_of_sub_selected_instruments == 5)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data(address_surface_ship);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// back
			while (sub_of_sub_selected_instruments == 6)
			{
				goto sub_menu_instruments;
			}
		}
		// Add INSTRUMENTS
		while (sub_select_of_navy_instruments_nms == 2)
		{

			title("NAVY TEAM MANAGEMENT SYSTEM");
			to_show_six_menu(sub_of_sub_menu_instruments);
			sub_of_sub_selected_instruments = selected_field();
			while (sub_of_sub_selected_instruments == 1)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_air_craft);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			while (sub_of_sub_selected_instruments == 2)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_weapons);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			while (sub_of_sub_selected_instruments == 3)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_missiles);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			while (sub_of_sub_selected_instruments == 4)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_sub);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			while (sub_of_sub_selected_instruments == 5)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_surface_ship);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			if (sub_of_sub_selected_instruments == 6)
			{
				goto sub_menu_instruments;
			}
		}
		// graph
		while (sub_select_of_navy_instruments_nms == 4)
		{
			system("cls");
			print_start_box(5, columns_of_screen);
			graph(item_quantity, show_instruments_graph, instruments_price);
			Sleep(5000);
			sub_select_of_navy_instruments_nms = yes_or_no(sub_select_of_navy_instruments_nms);
		}
		// Budget Calculate
		while (sub_select_of_navy_instruments_nms == 5)
		{
			float total;
			title("CALCULATE THE ARMY BUDGET");
			to_show_six_menu(show_instruments);
			to_get_inputs(item_quantity);
			total = calculate_instruments_price(item_quantity, instruments_price);
			gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 2);
			cout << "TOTAL BUDGET:" << total;
			sub_select_of_navy_instruments_nms = yes_or_no(sub_select_of_navy_instruments_nms);
		}
		// Back
		while (sub_selected_instruments == 6 || sub_select_of_navy_instruments_nms == 6)
		{
			goto nms_top_menu;
		}
	}
	// CROPS
	while (main_selected_option_of_nms == 4)
	{
		int sub_select_of_crops_ams;
		string crops[3] = {"1. NAVAL-KHOR", "2. NAIZI-KHOR", "3. BACK"};
	menu_crops:
		title("CROPS MANAGEMENT SYSTEM");
		to_show_three_menu(crops);
		sub_select_of_crops_ams = selected_field();
		while (sub_select_of_crops_ams == 1)
		{
			system("cls");
			print_start_box(5, columns_of_screen);
			to_print_in_title("CROPS MANAGEMENT SYSTEM");
			fetch_and_check_crops("PUNJAB", "navy_soldiers_nms/nms_army_soldiers_batch_id.txt", "navy_soldiers_nms/nms_army_soldiers_name.txt", "navy_soldiers_nms/nms_army_soldiers_provience.txt");
			fetch_and_check_crops("KPK", "navy_soldiers_nms/nms_army_soldiers_batch_id.txt", "navy_soldiers_nms/nms_army_soldiers_name.txt", "navy_soldiers_nms/nms_army_soldiers_provience.txt");
			fetch_and_check_crops("PUNJAB", "navy_officers_nms/nms_army_officers_batch_id.txt", "navy_officers_nms/nms_army_officers_name.txt", "navy_officers_nms/nms_army_officers_provience.txt");
			fetch_and_check_crops("KPK", "navy_officers_nms/nms_army_officers_batch_id.txt", "navy_officers_nms/nms_army_officers_name.txt", "navy_officers_nms/nms_army_officers_provience.txt");

			gotoxy(columns_of_screen / 2 - 15, 7);
			cout << "PRESS 3 KEY TO GO BACK .....";
			gotoxy(columns_of_screen / 2 + 17, 7);
			cin >> sub_select_of_crops_ams;
			if (sub_select_of_crops_ams == 0)
			{
				goto menu_crops;
			}
		}
		while (sub_select_of_crops_ams == 2)
		{
			system("cls");
			print_start_box(5, columns_of_screen);
			to_print_in_title("CROPS MANAGEMENT SYSTEM");
			fetch_and_check_crops("SINDH", "navy_soldiers_nms/nms_army_soldiers_batch_id.txt", "navy_soldiers_nms/nms_army_soldiers_name.txt", "navy_soldiers_nms/nms_army_soldiers_provience.txt");
			fetch_and_check_crops("BALOCHISTAN", "navy_soldiers_nms/nms_army_soldiers_batch_id.txt", "navy_soldiers_nms/nms_army_soldiers_name.txt", "navy_soldiers_nms/nms_army_soldiers_provience.txt");
			fetch_and_check_crops("SINDH", "navy_officers_nms/nms_army_officers_batch_id.txt", "navy_officers_nms/nms_army_officers_name.txt", "navy_officers_nms/nms_army_officers_provience.txt");
			fetch_and_check_crops("BALOCHISTAN", "navy_officers_nms/nms_army_officers_batch_id.txt", "navy_officers_nms/nms_army_officers_name.txt", "navy_officers_nms/nms_army_officers_provience.txt");

			gotoxy(columns_of_screen / 2 - 15, 7);
			cout << "PRESS 3 KEY TO GO BACK .....";
			gotoxy(columns_of_screen / 2 + 17, 7);
			cin >> sub_select_of_crops_ams;
			if (sub_select_of_crops_ams == 0)
			{
				goto menu_crops;
			}
		}

		if (sub_select_of_crops_ams == 3)
		{
			goto nms_top_menu;
		}
	}
	// Report of work
	while (main_selected_option_of_nms == 5)
	{
		system("cls");
		print_start_box(5, columns_of_screen);
		to_print_in_title("REPORT OF NAVY WORK");
		to_show_report("Report/navy_report.txt");
		gotoxy(columns_of_screen / 2 - 15, 7);
		cout << "PRESS 3 KEY TO GO BACK .....";
		gotoxy(columns_of_screen / 2 + 17, 7);
		cin >> main_selected_option_of_nms;
		if (main_selected_option_of_nms == 0)
		{
			goto nms_top_menu;
		}
	}
}
// 2 NAVY MS ENDED

// 3. AIR Force MANAGEMENT SYSTEM
int air_force_management_team_system(int checker_of_user_domain)
{

	int sub_selected_instruments;
	string batch_id, personal_details_fetcher[5];
	string main_menu_names_afms[6] = {"1. AIR FORCE SOLDIERS", "2. AIR FORCE OFFICERS", "3. INSTRUMENTS", "4. CROPS", "5. REPORT OF AIR FORCE WORK", "6. BACK"};
	string sub_menu_air_force_soldiers[6] = {"1. PERSONAL DETAILS", "2. ADD NEW SOLDIER", "3. EDIT SOLDIER DETAIL", "4. RETIRED NAVY OFFICERS", "5. MARTYRED", "6. BACK"};
	string sub_menu_instruments[6] = {"1. DETAILS OF INSTRUMENT", "2. ADD NEW INSTRUMENTS", "3. EDIT INSTRUMENT DETAIL", "4. GRAPH OF INSTRUMENTS(RESULT OF BUDGET)", "5. BUDGET OF INSTRUMENT", "6. BACK"};
	string personal_details_options[6] = {"SOLDIER NAME      : ", "SOLDIER FATHER    : ", "SOLDIER BATCH ID  : ", "SOLDIER PROVIENCE : ", "SOLDIER RANK : ", "SOLDIER AGE : "};
	string retired_options[3] = {"1. VIEW RETIRED ", "2. ADD NEW RETIRED MEN", "3. BACK"};
	string personal_details_options_officers[6] = {"OFFICERS NAME      : ", "OFFICERS FATHER    : ", "OFFICERS BATCH ID  : ", "OFFICERS PROVIENCE : ", "OFFICERS RANK : ", "OFFICERS AGE : "};
	string sub_menu_air_force_officers[8] = {"1. PERSONAL DETAILS", "2. ADD NEW OFFICERS", "3. EDIT OFFICER DETAILS", "4. RETIRED NAVY OFFICERS", "5. MARTYRED", "6. OFFICERS IN PROVIENCE", "7. SOLDIERS UNDER OFFICERS", "8. BACK"};
	string sub_of_sub_menu_instruments[6] = {"1. AIR CRAFTS", "2. WEAPONS", "3. MISSILES", "4. PLANES", "5. TRACKERS", "6. BACK"};
	string show_instruments[6] = {"1. AIR CRAFT", "2. WEAPONS", "3. MISSILES", "4. PLANES", "5. TRACKERS", "6. BACK"};
	string show_instruments_graph[5] = {"AIR CRAFT", "WEAPONS", "MISSILES", "PLANES", "TRACKERS"};

	int main_selected_option_of_afms;
	int sub_select_of_air_force_instruments_afms, sub_select_of_air_force_soldier_afms, sub_select_of_air_force_officer_afms;
	int item_quantity[5];
// Main Menu of NAVY TEAM MANAGEMENT SYSTEM
afms_top_menu:
	title("AIR FORCE TEAM MANAGEMENT SYSTEM");
	to_show_six_menu(main_menu_names_afms);
	main_selected_option_of_afms = selected_field();
	// army soldiers in ams // MISSING 3 ALL
	while (main_selected_option_of_afms == 1)
	{
	air_force_soldiers_menu:
		title("AIR FORCE TEAM MANAGEMENT SYSTEM");
		to_show_six_menu(sub_menu_air_force_soldiers);
		sub_select_of_air_force_soldier_afms = selected_field();
		// View Personal details of Soldiers
		while (sub_select_of_air_force_soldier_afms == 1)
		{
			int check_batch_id;
			title("PERSONAL DETAILS OF AIR FORCE SOLDIER");
			batch_id = id_take_to_fetch();

			check_batch_id = fetch_and_check_id_from_txt(personal_details_options, batch_id, "air_force_soldiers_afms/afms_army_soldiers_batch_id.txt", "air_force_soldiers_afms/afms_army_soldiers_name.txt", "air_force_soldiers_afms/afms_army_soldiers_father_name.txt", "air_force_soldiers_afms/afms_army_soldiers_provience.txt", "air_force_soldiers_afms/afms_army_soldiers_rank.txt", "air_force_soldiers_afms/afms_army_soldiers_age.txt");
			if (check_batch_id == 1)
			{
				sub_select_of_air_force_soldier_afms = yes_or_no(sub_select_of_air_force_soldier_afms);
				if (sub_select_of_air_force_soldier_afms == 0)
				{
					goto air_force_soldiers_menu;
				}
			}
			else
			{
				gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 10);
				cout << "INVALID !";
				Sleep(2000);
			}
		}
		// ADD NEW RECORD
		while (sub_select_of_air_force_soldier_afms == 2)
		{
			title("ADD DETAILS OF AIR FORCE OFFICER");
			to_add_data_in_txt(personal_details_options, "air_force_soldiers_afms/afms_army_soldiers_batch_id.txt", "air_force_soldiers_afms/afms_army_soldiers_name.txt", "air_force_soldiers_afms/afms_army_soldiers_father_name.txt", "air_force_soldiers_afms/afms_army_soldiers_provience.txt", "air_force_soldiers_afms/afms_army_soldiers_rank.txt", "air_force_soldiers_afms/afms_army_soldiers_age.txt");
			sub_select_of_air_force_soldier_afms = yes_or_no(sub_select_of_air_force_soldier_afms);
			if (sub_select_of_air_force_soldier_afms == 0)
			{
				goto air_force_soldiers_menu;
			}
		}
		// RETIRED Soldiers
		while (sub_select_of_air_force_soldier_afms == 4)
		{
			int sub_option_of_retired_officers;
			title("RETIRED OFFICERS MANAGEMENT");
			to_show_three_menu(retired_options);
			sub_option_of_retired_officers = selected_field();
			if (sub_option_of_retired_officers == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("RETIRED OFFICERS AND SOLDIERS");
				to_show_data("air_force_soldiers_afms/afms_army_soldiers_retired.txt");
				sub_option_of_retired_officers = yes_or_no(sub_option_of_retired_officers);
			}
			else if (sub_option_of_retired_officers == 2)
			{
				title("RETIRED ADDING SYSTEM");
				to_add_retire_and_single("air_force_soldiers_afms/afms_army_soldiers_retired.txt");
				sub_option_of_retired_officers = yes_or_no(sub_option_of_retired_officers);
			}
			else if (sub_option_of_retired_officers == 3)
			{
				goto air_force_soldiers_menu;
			}
		}
		// MATRYED
		while (sub_select_of_air_force_soldier_afms == 5)
		{
			system("cls");
			int sub_option_of_matryed_officers;
			string matryed_option[3] = {"1. VIEW HEROES OF NATION", "2. ADD NEW MATRYED", "3.BACK"};
			title("HEROES OF OUR NATION");
			to_show_three_menu(matryed_option);
			sub_option_of_matryed_officers = selected_field();
			if (sub_option_of_matryed_officers == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("HEROES OF OUR NATION");
				to_view_matryed("air_force_soldiers_afms/afms_army_soldiers_martyred.txt");
				gotoxy(columns_of_screen / 2 - 15, 7);
				cout << "PRESS 3 KEY TO GO BACK .....";
				gotoxy(columns_of_screen / 2 + 17, 7);
				cin >> sub_option_of_matryed_officers;
			}
			else if (sub_option_of_matryed_officers == 2)
			{
				title("HEROES OF OUR NATION");
				to_add_retire_and_single("air_force_soldiers_afms/afms_army_soldiers_martyred.txt");
				sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
			}
			else if (sub_option_of_matryed_officers == 3)
			{
				goto air_force_soldiers_menu;
			}
		}
		// GO TO AGAIN LOG IN
		while (sub_select_of_air_force_soldier_afms == 6)
		{
			goto afms_top_menu;
		}
	}
	// ARMY OFFICERS IN AMS // NOT WORKING 7
	while (main_selected_option_of_afms == 2)
	{
		string address_batch_id = "air_force_officers_afms/afms_army_officers_batch_id.txt", address_name = "air_force_officers_afms/afms_army_officers_name.txt", address_father_name = "air_force_officers_afms/afms_army_officers_father_name.txt", address_provience = "air_force_officers_afms/afms_army_officers_provience.txt", address_rank = "air_force_officers_afms/afms_army_officers_rank.txt", address_age = "air_force_officers_afms/afms_army_officers_age.txt";
	air_force_officers_menu:
		title("AIR FORCE TEAM MANAGEMENT SYSTEM");
		to_show_eight_menu(sub_menu_air_force_officers);
		sub_select_of_air_force_officer_afms = selected_field();
		// View Personal details of officers
		while (sub_select_of_air_force_officer_afms == 1)
		{
			int check_batch_id;
			title("PERSONAL DETAILS OF AIR FORCE OFFICER");
			batch_id = id_take_to_fetch();
			check_batch_id = fetch_and_check_id_from_txt(personal_details_options_officers, batch_id, address_batch_id, address_name, address_father_name, address_provience, address_rank, address_age);
			if (check_batch_id == 1)
			{
				sub_select_of_air_force_officer_afms = yes_or_no(sub_select_of_air_force_officer_afms);
				if (sub_select_of_air_force_officer_afms == 0)
				{
					goto air_force_officers_menu;
				}
			}
			else
			{
				gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 10);
				cout << "INVALID !";
				Sleep(2000);
			}
		}
		// ADD NEW RECORD
		while (sub_select_of_air_force_officer_afms == 2)
		{
			title("ADD DETAILS OF ARMY OFFICER");
			to_add_data_in_txt(personal_details_options_officers, address_batch_id, address_name, address_father_name, address_provience, address_rank, address_age);
			sub_select_of_air_force_officer_afms = yes_or_no(sub_select_of_air_force_officer_afms);
			if (sub_select_of_air_force_officer_afms == 0)
			{
				goto air_force_officers_menu;
			}
		}
		// RETIRED OFFICERS
		while (sub_select_of_air_force_officer_afms == 4)
		{
			int sub_option_of_retired_officers;
			title("RETIRED OFFICERS MANAGEMENT");
			to_show_three_menu(retired_options);
			sub_option_of_retired_officers = selected_field();
			if (sub_option_of_retired_officers == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("RETIRED OFFICERS AND SOLDIERS");
				to_show_data("air_force_soldiers_afms/afms_army_soldiers_retired.txt");
				sub_option_of_retired_officers = yes_or_no(sub_option_of_retired_officers);
			}
			else if (sub_option_of_retired_officers == 2)
			{
				title("RETIRED ADDING SYSTEM");
				to_add_retire_and_single("air_force_soldiers_afms/afms_army_soldiers_retired.txt");
				sub_option_of_retired_officers = yes_or_no(sub_option_of_retired_officers);
			}
			else if (sub_option_of_retired_officers == 3)
			{
				goto air_force_officers_menu;
			}
		}
		// MATRYED
		while (sub_select_of_air_force_officer_afms == 5)
		{
			system("cls");
			int sub_option_of_matryed_officers;
			string matryed_option[3] = {"1. VIEW EAGLES OF NATION", "2. ADD NEW MATRYED", "3.BACK"};
			title("EAGLES OF OUR NATION");
			to_show_three_menu(matryed_option);
			sub_option_of_matryed_officers = selected_field();
			if (sub_option_of_matryed_officers == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("EAGLES OF OUR NATION");
				to_view_matryed("air_force_soldiers_afms/afms_army_soldiers_martyred.txt");
				gotoxy(columns_of_screen / 2 - 15, 7);
				cout << "PRESS 3 KEY TO GO BACK .....";
				gotoxy(columns_of_screen / 2 + 17, 7);
				cin >> sub_option_of_matryed_officers;
			}
			else if (sub_option_of_matryed_officers == 2)
			{
				title("EAGLES OF OUR NATION");
				to_add_retire_and_single("air_force_soldiers_afms/afms_army_soldiers_martyred.txt");
				sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
			}
			else if (sub_option_of_matryed_officers == 3)
			{
				goto air_force_officers_menu;
			}
		}
		// Officers in Provience
		while (sub_select_of_air_force_officer_afms == 6)
		{
			string provience;
			int count_officers;
			system("cls");
			print_start_box(5, columns_of_screen);
			to_print_in_title("OFFICERS IN PROVIENCES");
			gotoxy(columns_of_screen / 2 - 10, 9);
			cout << "PROVIENCE: ";
			gotoxy(columns_of_screen / 2 + 2, 9);
			cin >> provience;
			count_officers = fetch_and_check_provience_from_txt(personal_details_options_officers, provience, address_batch_id, address_name, address_father_name, address_provience, address_rank, address_age);
			gotoxy(columns_of_screen / 10, 10);
			cout << "\033[32m"
				 << "COUNTED OFFICERS: " << count_officers;
			gotoxy(columns_of_screen / 2 - 15, 7);
			cout << "PRESS ANY KEY TO GO BACK .....";
			getch();
			goto air_force_officers_menu;
		}
		// Soldiers under Officers
		//  NOT WORKING PROPERLY
		while (sub_select_of_air_force_officer_afms == 7)
		{
			string check_batch_id;
			title("SOLDIERS UNDER THE OFFICER");
			check_batch_id = id_take_to_fetch();
			/*
			to_show_soldiers_under_officers(check_batch_id);
			*/
		}
		// GO TO AGAIN LOG IN
		while (sub_select_of_air_force_officer_afms == 8)
		{
			goto afms_top_menu;
		}
	}
	// ARMY INSTRUMENTS // MISSING 3
	while (main_selected_option_of_afms == 3)
	{
	sub_menu_instruments:
		double instruments_price[5] = {40000, 12000, 50000, 80000, 1000};
		string address_air_craft = "instruments_afms/afms_air_craft.txt", address_weapons = "instruments_afms/afms_gun_weapons.txt", address_missiles = "instruments_afms/afms_missiles.txt", address_planes = "instruments_afms/afms_planes.txt", address_trackers = "instruments_afms/afms_trackers.txt";
		int sub_of_sub_selected_instruments;
		title("AIR TEAM MANAGEMENT SYSTEM");
		to_show_six_menu(sub_menu_instruments);
		sub_select_of_air_force_instruments_afms = selected_field();
		// VIEW INSTRUMENTS
		while (sub_select_of_air_force_instruments_afms == 1)
		{
			title("NAVY TEAM MANAGEMENT SYSTEM");
			to_show_six_menu(sub_of_sub_menu_instruments);
			sub_of_sub_selected_instruments = selected_field();

			// Air craft
			while (sub_of_sub_selected_instruments == 1)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data(address_air_craft);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// Weapons
			while (sub_of_sub_selected_instruments == 2)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data(address_weapons);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// missiles
			while (sub_of_sub_selected_instruments == 3)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data(address_missiles);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// PLANE
			while (sub_of_sub_selected_instruments == 4)
			{

				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data(address_planes);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// trackers
			while (sub_of_sub_selected_instruments == 5)
			{
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("DETAILS OF CARRIERS");
				to_show_data(address_trackers);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			// back
			while (sub_of_sub_selected_instruments == 6)
			{
				goto sub_menu_instruments;
			}
		}
		// Add INSTRUMENTS
		while (sub_select_of_air_force_instruments_afms == 2)
		{

			title("EAGLES TEAM MANAGEMENT SYSTEM");
			to_show_six_menu(sub_of_sub_menu_instruments);
			sub_of_sub_selected_instruments = selected_field();
			while (sub_of_sub_selected_instruments == 1)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_air_craft);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			while (sub_of_sub_selected_instruments == 2)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_weapons);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			while (sub_of_sub_selected_instruments == 3)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_missiles);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			while (sub_of_sub_selected_instruments == 4)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_planes);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			while (sub_of_sub_selected_instruments == 5)
			{
				title("INSTRUMENTS HANDLING");
				to_add_retire_and_single(address_trackers);
				sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
			}
			if (sub_of_sub_selected_instruments == 6)
			{
				goto sub_menu_instruments;
			}
		}
		// graph
		while (sub_select_of_air_force_instruments_afms == 4)
		{
			system("cls");
			print_start_box(5, columns_of_screen);
			graph(item_quantity, show_instruments_graph, instruments_price);
			Sleep(5000);
			sub_select_of_air_force_instruments_afms = yes_or_no(sub_select_of_air_force_instruments_afms);
		}
		// Budget Calculate
		while (sub_select_of_air_force_instruments_afms == 5)
		{
			float total;
			title("CALCULATE THE ARMY BUDGET");
			to_show_six_menu(show_instruments);
			to_get_inputs(item_quantity);
			total = calculate_instruments_price(item_quantity, instruments_price);
			gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 2);
			cout << "TOTAL BUDGET:" << total;
			sub_select_of_air_force_instruments_afms = yes_or_no(sub_select_of_air_force_instruments_afms);
		}
		// Back
		while (sub_selected_instruments == 6 || sub_select_of_air_force_instruments_afms == 6)
		{
			goto afms_top_menu;
		}
	}
	// CROPS
	while (main_selected_option_of_afms == 4)
	{
		int sub_select_of_crops_ams;
		string crops[3] = {"1. NAVAL-KHOR", "2. HIM-KHOR", "3. BACK"};
	menu_crops:
		title("CROPS MANAGEMENT SYSTEM");
		to_show_three_menu(crops);
		sub_select_of_crops_ams = selected_field();
		while (sub_select_of_crops_ams == 1)
		{
			system("cls");
			print_start_box(5, columns_of_screen);
			to_print_in_title("CROPS MANAGEMENT SYSTEM");
			fetch_and_check_crops("PUNJAB", "air_force_soldiers_afms/afms_army_soldiers_batch_id.txt", "air_force_soldiers_afms/afms_army_soldiers_name.txt", "air_force_soldiers_afms/afms_army_soldiers_provience.txt");
			fetch_and_check_crops("KPK", "air_force_soldiers_afms/afms_army_soldiers_batch_id.txt", "air_force_soldiers_afms/afms_army_soldiers_name.txt", "air_force_soldiers_afms/afms_army_soldiers_provience.txt");
			fetch_and_check_crops("PUNJAB", "air_force_officers_afms/afms_army_officers_batch_id.txt", "air_force_officers_afms/afms_army_officers_name.txt", "air_force_officers_afms/afms_army_officers_provience.txt");
			fetch_and_check_crops("KPK", "air_force_officers_afms/afms_army_officers_batch_id.txt", "air_force_officers_afms/afms_army_officers_name.txt", "air_force_officers_afms/afms_army_officers_provience.txt");

			gotoxy(columns_of_screen / 2 - 15, 7);
			cout << "PRESS 3 KEY TO GO BACK .....";
			gotoxy(columns_of_screen / 2 + 17, 7);
			cin >> sub_select_of_crops_ams;
			if (sub_select_of_crops_ams == 0)
			{
				goto menu_crops;
			}
		}
		while (sub_select_of_crops_ams == 2)
		{
			system("cls");
			print_start_box(5, columns_of_screen);
			to_print_in_title("CROPS MANAGEMENT SYSTEM");
			fetch_and_check_crops("SINDH", "air_force_soldiers_afms/afms_army_soldiers_batch_id.txt", "air_force_soldiers_afms/afms_army_soldiers_name.txt", "air_force_soldiers_afms/afms_army_soldiers_provience.txt");
			fetch_and_check_crops("BALOCHISTAN", "air_force_soldiers_afms/afms_army_soldiers_batch_id.txt", "air_force_soldiers_afms/afms_army_soldiers_name.txt", "air_force_soldiers_afms/afms_army_soldiers_provience.txt");
			fetch_and_check_crops("SINDH", "air_force_officers_afms/afms_army_officers_batch_id.txt", "air_force_officers_afms/afms_army_officers_name.txt", "air_force_officers_afms/afms_army_officers_provience.txt");
			fetch_and_check_crops("BALOCHISTAN", "air_force_officers_afms/afms_army_officers_batch_id.txt", "air_force_officers_afms/afms_army_officers_name.txt", "air_force_officers_afms/afms_army_officers_provience.txt");

			gotoxy(columns_of_screen / 2 - 15, 7);
			cout << "PRESS 3 KEY TO GO BACK .....";
			gotoxy(columns_of_screen / 2 + 17, 7);
			cin >> sub_select_of_crops_ams;
			if (sub_select_of_crops_ams == 0)
			{
				goto menu_crops;
			}
		}

		if (sub_select_of_crops_ams == 3)
		{
			goto afms_top_menu;
		}
	}
	// Report of work
	while (main_selected_option_of_afms == 5)
	{
		system("cls");
		print_start_box(5, columns_of_screen);
		to_print_in_title("REPORT OF AIR FORCE WORK");
		to_show_report("Report/air_force_report.txt");
		gotoxy(columns_of_screen / 2 - 15, 7);
		cout << "PRESS 3 KEY TO GO BACK .....";
		gotoxy(columns_of_screen / 2 + 17, 7);
		cin >> main_selected_option_of_afms;
		if (main_selected_option_of_afms == 0)
		{
			goto afms_top_menu;
		}
	}
}
// 3 air_force MS ENDED

// 4. ARMY OFFICERS MANAGEMENT SYSTEM
int army_officer_management_system(int checker_of_user_domain)
{
	int main_selector, sub_select_of_army_officer_aoms;
	string address_batch_id = "army_officers_ams/ams_army_officers_batch_id.txt", address_name = "army_officers_ams/ams_army_officers_name.txt", address_father_name = "army_officers_ams/ams_army_officers_father_name.txt", address_provience = "army_officers_ams/ams_army_officers_provience.txt", address_rank = "army_officers_ams/ams_army_officers_rank.txt", address_age = "army_officers_ams/ams_army_officers_age.txt";
	string aoms_main_menus[6] = {"1. PERSONAL DETAILS", "2. VIEW SOLDIERS", "3. CANDIDATES SELECTOR", "4. WAR IDEA", "5. CODE BY CROPS", "6. BACK"};
	string personal_details_options[6] = {"NAME      : ", "FATHER    : ", "BATCH ID  : ", "PROVIENCE : ", "RANK : ", "AGE : "};
	string soldiers_sub_menu[3] = {"1. FETCH BY PROVIENCE", "2. FETCH BY BATCH ID", "3. BACK"};
	string issb_selector_option[3] = {"1. GTO", "2. PSYCHOLOGYIST", "3. BACK"};
aoms_main_menu:
	title("ARMY OFFICER MANAGEMENT");
	to_show_six_menu(aoms_main_menus);
	main_selector = selected_field();
	if (main_selector == 1 || main_selector == 2 || main_selector == 3 || main_selector == 4 || main_selector == 5 || main_selector == 6)
	{
		// PERSONAL DETAILS
		while (main_selector == 1)
		{
			int check_batch_id;
			string batch_id;
			title("PERSONAL DETAILS OF ARMY OFFICER");
			batch_id = id_take_to_fetch();
			check_batch_id = fetch_and_check_id_from_txt(personal_details_options, batch_id, address_batch_id, address_name, address_father_name, address_provience, address_rank, address_age);
			if (check_batch_id == 1)
			{
				main_selector = yes_or_no(main_selector);
				if (main_selector == 0)
				{
					goto aoms_main_menu;
				}
			}
			else
			{
				gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 10);
				cout << "INVALID !";
				Sleep(2000);
			}
		}
		// SOLDIERS DETAILS
		while (main_selector == 2)
		{
		aoms_soldier_menu:
			title("TO SEE SOLDIERS DETAILS");
			to_show_three_menu(soldiers_sub_menu);
			sub_select_of_army_officer_aoms = selected_field();
			while (sub_select_of_army_officer_aoms == 1)
			{
				string provience;
				int count_officers;
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("OFFICERS IN PROVIENCES");
				gotoxy(columns_of_screen / 2 - 10, 9);
				cout << "PROVIENCE: ";
				gotoxy(columns_of_screen / 2 + 2, 9);
				cin >> provience;
				count_officers = fetch_and_check_provience_from_txt(personal_details_options, provience, "ams_army_soldiers_batch_id.txt", "ams_army_soldiers_name.txt", "ams_army_soldiers_father_name.txt", "ams_army_soldiers_provience.txt", "ams_army_soldiers_rank.txt", "ams_army_soldiers_age.txt");
				gotoxy(columns_of_screen / 10, 10);
				cout << "\033[32m"
					 << "COUNTED OFFICERS: " << count_officers;
				gotoxy(columns_of_screen / 2 - 15, 7);
				cout << "PRESS ANY KEY TO GO BACK .....";
				getch();
				goto aoms_soldier_menu;
			}
			while (sub_select_of_army_officer_aoms == 2)
			{
				int check_batch_id;
				string batch_id;
				title("PERSONAL DETAILS OF ARMY SOLDIER");
				batch_id = id_take_to_fetch();
				check_batch_id = fetch_and_check_id_from_txt(personal_details_options, batch_id, "ams_army_soldiers_batch_id.txt", "ams_army_soldiers_name.txt", "ams_army_soldiers_father_name.txt", "ams_army_soldiers_provience.txt", "ams_army_soldiers_rank.txt", "ams_army_soldiers_age.txt");
				if (check_batch_id == 1)
				{
					sub_select_of_army_officer_aoms = yes_or_no(sub_select_of_army_officer_aoms);
					if (sub_select_of_army_officer_aoms == 0)
					{
						goto aoms_soldier_menu;
					}
				}
				else
				{
					gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 10);
					cout << "INVALID !";
					Sleep(2000);
				}
			}

			if (sub_select_of_army_officer_aoms == 3)
			{
				goto aoms_main_menu;
			}
		}
		// Candidates Select
		while (main_selector == 3)
		{
			string gto_menu[6] = {"MILTARY PLANING", "GROUP DISCUSSION", "OUTDOOR TASK", "OBSTACLES", "LECTURE", "TEAM WORK"};
			int marks[5][6];
			string batch_id[5];
			int total_marks[5] = {0, 0, 0, 0, 0};
			title("ISSB SELECTOR");
			to_show_three_menu(issb_selector_option);
			sub_select_of_army_officer_aoms = selected_field();
			while (sub_select_of_army_officer_aoms == 1)
			{
				int candidates = 5;
				for (int i = 0; i < candidates; i++)
				{
					title("GTO GROUP TAKS");
					to_show_six_menu(gto_menu);
					batch_id[i] = id_take_to_fetch();
					to_add_data_in_array(marks, i, 6);
				}
				for (int i = 0; i < candidates; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						total_marks[i] = total_marks[i] + marks[i][j];
					}
				}
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("RESULT OF CANDIDATIES");
				to_show_five_persons_result(marks, batch_id, total_marks, 6);
				sub_select_of_army_officer_aoms = yes_or_no(sub_select_of_army_officer_aoms);
			}
			while (sub_select_of_army_officer_aoms == 2)
			{
				int candidates = 5;
				for (int i = 0; i < candidates; i++)
				{
					string pys_tasks[6] = {"WORDS TESTS", "ALGORITHM TEST", "INTERVIEW", "ATITUDE", "SCREEN TEST", "NON VERBAL TEST"};
					title("PSYCOLOGYIST TASKS OF GROUP");
					to_show_six_menu(pys_tasks);
					batch_id[i] = id_take_to_fetch();
					to_add_data_in_array(marks, i, 6);
				}
				for (int i = 0; i < candidates; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						total_marks[i] = total_marks[i] + marks[i][j];
					}
				}
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("RESULT OF CANDIDATIES");
				to_show_five_persons_result(marks, batch_id, total_marks, 6);
				sub_select_of_army_officer_aoms = yes_or_no(sub_select_of_army_officer_aoms);
			}
			if (sub_select_of_army_officer_aoms == 3)
			{
				goto aoms_main_menu;
			}
		}
		// WAR IDEA
		while (main_selector == 4)
		{
			string ideas[6] = {"PLACE 1: ", "PLACE 2: ", "PLACE 3: ", "PLACE 4: ", "PLACE 5: ", "PLACE 6: "};
			int war_planes[5][6];
			int total_marks[5];
			for (int i = 0; i < 5; i++)
			{
				system("cls");
				title("WAR CHANGING IDEAS");
				to_show_six_menu(ideas);
				to_add_data_in_array(war_planes, i, 6);
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					total_marks[i] = total_marks[i] + war_planes[i][j];
				}
			}
			int highest, index;
			for (int i = 0; i < 5; i++)
			{
				for (int j = i; j < 5; j++)
				{
					if (total_marks[i] > total_marks[j])
					{
						highest = total_marks[i];
						index = i;
					}
					else if (total_marks[i] < total_marks[j])
					{
						highest = total_marks[j];
						index = i;
					}
				}
			}
			gotoxy(5, 18);
			cout << "BEST PLAN NO IS: " << index + 1;
			main_selector = yes_or_no(main_selector);
			if (main_selector == 0)
			{
				goto aoms_main_menu;
			}
		}
		// CODE BY CROPS
		while (main_selector == 5)
		{
			title("CODE BY CROPS");
			string moves[9] = {"ATTACK-ON-POINT-9", "ATTACK-ON-POINT-F", "ATTACK-ON-POINT-C", "ATTACK-ON-POINT-A", "ATTACK-ON-POINT-S", "ATTACK-ON-POINT-J", "ATTACK-ON-POINT-Q", "ATTACK-ON-POINT-R", "ATTACK-ON-POINT-G"};
			int number[4], checker[4], printer;
			int x = 18;
			for (int i = 0; i < 4; i++)
			{
				gotoxy(columns_of_screen / 4 + 26, x);
				cout << "Number: ";
				gotoxy(columns_of_screen / 4 + 46, x);
				cin >> number[i];
				x++;
			}
			for (int i = 0; i < 4; i++)
			{
				checker[i] = number[i] + i;
				if (checker[i] > 9)
				{
					checker[i] = checker[i] - 10;
				}
			}
			title("CODE BY CROPS");
			int y = -10;
			for (int i = 0; i < 4; i++)
			{

				printer = checker[i];
				gotoxy(columns_of_screen / 4 + y, 9);
				cout << moves[printer] << ", ";
				y = y + 21;
			}
			main_selector = yes_or_no(main_selector);
			if (main_selector == 0)
			{
				goto aoms_main_menu;
			}
		}
	}
	else
	{
		system("cls");
		gotoxy(columns_to_fit + 5, rows_of_screen / 2);
		cout << "INVALID! OFFICER YOU DESIRVE PUNISHMENT";
		Sleep(3000);
		goto aoms_main_menu;
	}
}
// 4. ARMY OFFICERS MANAGEMENT SYSTEM END

// 5 . NAVY OFFICERS MANAGEMENT SYSTEM
int navy_officer_management_system(int checker_of_user_domain)
{
	int main_selector, sub_select_of_navy_officer_noms;
	string address_batch_id = "navy_officers_nms/nms_army_officers_batch_id.txt", address_name = "navy_officers_nms/nms_army_officers_name.txt", address_father_name = "navy_officers_nms/nms_army_officers_father_name.txt", address_provience = "navy_officers_nms/nms_army_officers_provience.txt", address_rank = "navy_officers_nms/nms_army_officers_rank.txt", address_age = "navy_officers_nms/nms_army_officers_age.txt";
	string noms_main_menus[6] = {"1. PERSONAL DETAILS", "2. VIEW SOLDIERS", "3. CANDIDATES SELECTOR", "4. WAR IDEA", "5. CODE BY CROPS", "6. BACK"};
	string personal_details_options[6] = {"NAME      : ", "FATHER    : ", "BATCH ID  : ", "PROVIENCE : ", "RANK : ", "AGE : "};
	string soldiers_sub_menu[3] = {"1. FETCH BY PROVIENCE", "2. FETCH BY BATCH ID", "3. BACK"};
	string issb_selector_option[3] = {"1. NAVY TASKER ", "2. PSYCHOLOGYIST", "3. BACK"};
noms_main_menu:
	title("NAVY OFFICER MANAGEMENT");
	to_show_six_menu(noms_main_menus);
	main_selector = selected_field();
	if (main_selector == 1 || main_selector == 2 || main_selector == 3 || main_selector == 4 || main_selector == 5 || main_selector == 6)
	{
		// PERSONAL DETAILS
		while (main_selector == 1)
		{
			int check_batch_id;
			string batch_id;
			title("PERSONAL DETAILS OF NAVY OFFICER");
			batch_id = id_take_to_fetch();
			check_batch_id = fetch_and_check_id_from_txt(personal_details_options, batch_id, address_batch_id, address_name, address_father_name, address_provience, address_rank, address_age);
			if (check_batch_id == 1)
			{
				main_selector = yes_or_no(main_selector);
				if (main_selector == 0)
				{
					goto noms_main_menu;
				}
			}
			else
			{
				gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 10);
				cout << "INVALID !";
				Sleep(2000);
			}
		}
		// SOLDIERS DETAILS
		while (main_selector == 2)
		{
		aoms_soldier_menu:
			title("TO SEE SOLDIERS DETAILS");
			to_show_three_menu(soldiers_sub_menu);
			sub_select_of_navy_officer_noms = selected_field();
			while (sub_select_of_navy_officer_noms == 1)
			{
				string provience;
				int count_officers;
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("OFFICERS IN PROVIENCES");
				gotoxy(columns_of_screen / 2 - 10, 9);
				cout << "PROVIENCE: ";
				gotoxy(columns_of_screen / 2 + 2, 9);
				cin >> provience;
				count_officers = fetch_and_check_provience_from_txt(personal_details_options, provience, "navy_soldiers_nms/nms_army_soldiers_batch_id.txt", "navy_soldiers_nms/nms_army_soldiers_name.txt", "navy_soldiers_nms/nms_army_soldiers_father_name.txt", "navy_soldiers_nms/nms_army_soldiers_provience.txt", "navy_soldiers_nms/nms_army_soldiers_rank.txt", "navy_soldiers_nms/nms_army_soldiers_age.txt");
				gotoxy(columns_of_screen / 10, 10);
				cout << "\033[32m"
					 << "COUNTED OFFICERS: " << count_officers;
				gotoxy(columns_of_screen / 2 - 15, 7);
				cout << "PRESS ANY KEY TO GO BACK .....";
				getch();
				goto aoms_soldier_menu;
			}
			while (sub_select_of_navy_officer_noms == 2)
			{
				int check_batch_id;
				string batch_id;
				title("PERSONAL DETAILS OF NAVY SOLDIER");
				batch_id = id_take_to_fetch();
				check_batch_id = fetch_and_check_id_from_txt(personal_details_options, batch_id, "navy_soldiers_nms/nms_army_soldiers_batch_id.txt", "navy_soldiers_nms/nms_army_soldiers_name.txt", "navy_soldiers_nms/nms_army_soldiers_father_name.txt", "navy_soldiers_nms/nms_army_soldiers_provience.txt", "navy_soldiers_nms/nms_army_soldiers_rank.txt", "navy_soldiers_nms/nms_army_soldiers_age.txt");
				if (check_batch_id == 1)
				{
					sub_select_of_navy_officer_noms = yes_or_no(sub_select_of_navy_officer_noms);
					if (sub_select_of_navy_officer_noms == 0)
					{
						goto aoms_soldier_menu;
					}
				}
				else
				{
					gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 10);
					cout << "INVALID !";
					Sleep(2000);
				}
			}

			if (sub_select_of_navy_officer_noms == 3)
			{
				goto noms_main_menu;
			}
		}
		// Candidates Select
		while (main_selector == 3)
		{
			string gto_menu[6] = {"MILTARY PLANING", "GROUP DISCUSSION", "OUTDOOR TASK", "OBSTACLES", "LECTURE", "TEAM WORK"};
			int marks[5][6];
			string batch_id[5];
			int total_marks[5] = {0, 0, 0, 0, 0};
			title("ISSB SELECTOR");
			to_show_three_menu(issb_selector_option);
			sub_select_of_navy_officer_noms = selected_field();
			while (sub_select_of_navy_officer_noms == 1)
			{
				int candidates = 5;
				for (int i = 0; i < candidates; i++)
				{
					title("GTO GROUP TAKS");
					to_show_six_menu(gto_menu);
					batch_id[i] = id_take_to_fetch();
					to_add_data_in_array(marks, i, 6);
				}
				for (int i = 0; i < candidates; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						total_marks[i] = total_marks[i] + marks[i][j];
					}
				}
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("RESULT OF CANDIDATIES");
				to_show_five_persons_result(marks, batch_id, total_marks, 6);
				sub_select_of_navy_officer_noms = yes_or_no(sub_select_of_navy_officer_noms);
			}
			while (sub_select_of_navy_officer_noms == 2)
			{
				int candidates = 5;
				for (int i = 0; i < candidates; i++)
				{
					string pys_tasks[6] = {"WORDS TESTS", "ALGORITHM TEST", "INTERVIEW", "ATITUDE", "SCREEN TEST", "NON VERBAL TEST"};
					title("PSYCOLOGYIST TASKS OF GROUP");
					to_show_six_menu(pys_tasks);
					batch_id[i] = id_take_to_fetch();
					to_add_data_in_array(marks, i, 6);
				}
				for (int i = 0; i < candidates; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						total_marks[i] = total_marks[i] + marks[i][j];
					}
				}
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("RESULT OF CANDIDATIES");
				to_show_five_persons_result(marks, batch_id, total_marks, 6);
				sub_select_of_navy_officer_noms = yes_or_no(sub_select_of_navy_officer_noms);
			}
			if (sub_select_of_navy_officer_noms == 3)
			{
				goto noms_main_menu;
			}
		}
		// WAR IDEA
		while (main_selector == 4)
		{
			string ideas[6] = {"PLACE 1: ", "PLACE 2: ", "PLACE 3: ", "PLACE 4: ", "PLACE 5: ", "PLACE 6: "};
			int war_planes[5][6];
			int total_marks[5];
			for (int i = 0; i < 5; i++)
			{
				system("cls");
				title("WAR CHANGING IDEAS");
				to_show_six_menu(ideas);
				to_add_data_in_array(war_planes, i, 6);
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					total_marks[i] = total_marks[i] + war_planes[i][j];
				}
			}
			int highest, index;
			for (int i = 0; i < 5; i++)
			{
				for (int j = i; j < 5; j++)
				{
					if (total_marks[i] > total_marks[j])
					{
						highest = total_marks[i];
						index = i;
					}
					else if (total_marks[i] < total_marks[j])
					{
						highest = total_marks[j];
						index = i;
					}
				}
			}
			gotoxy(5, 18);
			cout << "BEST PLAN NO IS: " << index + 1;
			main_selector = yes_or_no(main_selector);
			if (main_selector == 0)
			{
				goto noms_main_menu;
			}
		}
		// CODE BY CROPS
		while (main_selector == 5)
		{
			title("CODE BY CROPS");
			string moves[9] = {"ATTACK-ON-POINT-9", "ATTACK-ON-POINT-F", "ATTACK-ON-POINT-C", "ATTACK-ON-POINT-A", "ATTACK-ON-POINT-S", "ATTACK-ON-POINT-J", "ATTACK-ON-POINT-Q", "ATTACK-ON-POINT-R", "ATTACK-ON-POINT-G"};
			int number[4], checker[4], printer;
			int x = 18;
			for (int i = 0; i < 4; i++)
			{
				gotoxy(columns_of_screen / 4 + 26, x);
				cout << "Number: ";
				gotoxy(columns_of_screen / 4 + 46, x);
				cin >> number[i];
				x++;
			}
			for (int i = 0; i < 4; i++)
			{
				checker[i] = number[i] + i;
				if (checker[i] > 9)
				{
					checker[i] = checker[i] - 10;
				}
			}
			title("CODE BY CROPS");
			int y = -10;
			for (int i = 0; i < 4; i++)
			{

				printer = checker[i];
				gotoxy(columns_of_screen / 4 + y, 9);
				cout << moves[printer] << ", ";
				y = y + 20;
			}
			main_selector = yes_or_no(main_selector);
			if (main_selector == 0)
			{
				goto noms_main_menu;
			}
		}
	}
	else
	{
		system("cls");
		gotoxy(columns_to_fit + 5, rows_of_screen / 2);
		cout << "INVALID! OFFICER YOU DESIRVE PUNISHMENT";
		Sleep(3000);
		goto noms_main_menu;
	}
}
// 5. NOMS ENDED

// 6. AIR FORCE OFFICERS MANAGEMENT SYSTEM
int air_force_officer_management_system(int checker_of_user_domain)
{
	int main_selector, sub_select_of_air_officer_foms;
	string address_batch_id = "air_force_officers_afms/afms_army_officers_batch_id.txt", address_name = "air_force_officers_afms/afms_army_officers_name.txt", address_father_name = "air_force_officers_afms/afms_army_officers_father_name.txt", address_provience = "air_force_officers_afms/afms_army_officers_provience.txt", address_rank = "air_force_officers_afms/afms_army_officers_rank.txt", address_age = "air_force_officers_afms/afms_army_officers_age.txt";
	string fms_main_menus[6] = {"1. PERSONAL DETAILS", "2. VIEW SOLDIERS", "3. CANDIDATES SELECTOR", "4. WAR IDEA", "5. CODE BY CROPS", "6. BACK"};
	string personal_details_options[6] = {"NAME      : ", "FATHER    : ", "BATCH ID  : ", "PROVIENCE : ", "RANK : ", "AGE : "};
	string soldiers_sub_menu[3] = {"1. FETCH BY PROVIENCE", "2. FETCH BY BATCH ID", "3. BACK"};
	string issb_selector_option[3] = {"1. AIR TASKER ", "2. PSYCHOLOGYIST", "3. BACK"};
fms_main_menu:
	title("AIR FORCE OFFICER MANAGEMENT");
	to_show_six_menu(fms_main_menus);
	main_selector = selected_field();
	if (main_selector == 1 || main_selector == 2 || main_selector == 3 || main_selector == 4 || main_selector == 5 || main_selector == 6)
	{
		// PERSONAL DETAILS
		while (main_selector == 1)
		{
			int check_batch_id;
			string batch_id;
			title("PERSONAL DETAILS OF EAGLES OFFICER");
			batch_id = id_take_to_fetch();
			check_batch_id = fetch_and_check_id_from_txt(personal_details_options, batch_id, address_batch_id, address_name, address_father_name, address_provience, address_rank, address_age);
			if (check_batch_id == 1)
			{
				main_selector = yes_or_no(main_selector);
				if (main_selector == 0)
				{
					goto fms_main_menu;
				}
			}
			else
			{
				gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 10);
				cout << "INVALID !";
				Sleep(2000);
			}
		}
		// SOLDIERS DETAILS
		while (main_selector == 2)
		{
		aoms_soldier_menu:
			title("TO SEE SOLDIERS DETAILS");
			to_show_three_menu(soldiers_sub_menu);
			sub_select_of_air_officer_foms = selected_field();
			while (sub_select_of_air_officer_foms == 1)
			{
				string provience;
				int count_officers;
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("OFFICERS IN PROVIENCES");
				gotoxy(columns_of_screen / 2 - 10, 9);
				cout << "PROVIENCE: ";
				gotoxy(columns_of_screen / 2 + 2, 9);
				cin >> provience;
				count_officers = fetch_and_check_provience_from_txt(personal_details_options, provience, "air_force_soldiers_afms/afms_army_soldiers_batch_id.txt", "air_force_soldiers_afms/afms_army_soldiers_name.txt", "air_force_soldiers_afms/afms_army_soldiers_father_name.txt", "air_force_soldiers_afms/afms_army_soldiers_provience.txt", "air_force_soldiers_afms/afms_army_soldiers_rank.txt", "air_force_soldiers_afms/afms_army_soldiers_age.txt");
				gotoxy(columns_of_screen / 10, 10);
				cout << "\033[32m"
					 << "COUNTED OFFICERS: " << count_officers;
				gotoxy(columns_of_screen / 2 - 15, 7);
				cout << "PRESS ANY KEY TO GO BACK .....";
				getch();
				goto aoms_soldier_menu;
			}
			while (sub_select_of_air_officer_foms == 2)
			{
				int check_batch_id;
				string batch_id;
				title("PERSONAL DETAILS OF EAGLE SOLDIER");
				batch_id = id_take_to_fetch();
				check_batch_id = fetch_and_check_id_from_txt(personal_details_options, batch_id, "air_force_soldiers_afms/afms_army_soldiers_batch_id.txt", "air_force_soldiers_afms/afms_army_soldiers_name.txt", "air_force_soldiers_afms/afms_army_soldiers_father_name.txt", "air_force_soldiers_afms/afms_army_soldiers_provience.txt", "air_force_soldiers_afms/afms_army_soldiers_rank.txt", "air_force_soldiers_afms/afms_army_soldiers_age.txt");
				if (check_batch_id == 1)
				{
					sub_select_of_air_officer_foms = yes_or_no(sub_select_of_air_officer_foms);
					if (sub_select_of_air_officer_foms == 0)
					{
						goto aoms_soldier_menu;
					}
				}
				else
				{
					gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 10);
					cout << "INVALID !";
					Sleep(2000);
				}
			}

			if (sub_select_of_air_officer_foms == 3)
			{
				goto fms_main_menu;
			}
		}
		// Candidates Select
		while (main_selector == 3)
		{
			string gto_menu[6] = {"MILTARY PLANING", "GROUP DISCUSSION", "OUTDOOR TASK", "OBSTACLES", "LECTURE", "TEAM WORK"};
			int marks[5][6];
			string batch_id[5];
			int total_marks[5] = {0, 0, 0, 0, 0};
			title("ISSB SELECTOR");
			to_show_three_menu(issb_selector_option);
			sub_select_of_air_officer_foms = selected_field();
			while (sub_select_of_air_officer_foms == 1)
			{
				int candidates = 5;
				for (int i = 0; i < candidates; i++)
				{
					title("AIR TASKER GROUP TAKS");
					to_show_six_menu(gto_menu);
					batch_id[i] = id_take_to_fetch();
					to_add_data_in_array(marks, i, 6);
				}
				for (int i = 0; i < candidates; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						total_marks[i] = total_marks[i] + marks[i][j];
					}
				}
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("RESULT OF CANDIDATIES");
				to_show_five_persons_result(marks, batch_id, total_marks, 6);
				sub_select_of_air_officer_foms = yes_or_no(sub_select_of_air_officer_foms);
			}
			while (sub_select_of_air_officer_foms == 2)
			{
				int candidates = 5;
				for (int i = 0; i < candidates; i++)
				{
					string pys_tasks[6] = {"WORDS TESTS", "ALGORITHM TEST", "INTERVIEW", "ATITUDE", "SCREEN TEST", "NON VERBAL TEST"};
					title("PSYCOLOGYIST TASKS OF GROUP");
					to_show_six_menu(pys_tasks);
					batch_id[i] = id_take_to_fetch();
					to_add_data_in_array(marks, i, 6);
				}
				for (int i = 0; i < candidates; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						total_marks[i] = total_marks[i] + marks[i][j];
					}
				}
				system("cls");
				print_start_box(5, columns_of_screen);
				to_print_in_title("RESULT OF CANDIDATIES");
				to_show_five_persons_result(marks, batch_id, total_marks, 6);
				sub_select_of_air_officer_foms = yes_or_no(sub_select_of_air_officer_foms);
			}
			if (sub_select_of_air_officer_foms == 3)
			{
				goto fms_main_menu;
			}
		}
		// WAR IDEA
		while (main_selector == 4)
		{
			string ideas[6] = {"PLACE 1: ", "PLACE 2: ", "PLACE 3: ", "PLACE 4: ", "PLACE 5: ", "PLACE 6: "};
			int war_planes[5][6];
			int total_marks[5];
			for (int i = 0; i < 5; i++)
			{
				system("cls");
				title("WAR CHANGING IDEAS");
				to_show_six_menu(ideas);
				to_add_data_in_array(war_planes, i, 6);
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					total_marks[i] = total_marks[i] + war_planes[i][j];
				}
			}
			int highest, index;
			for (int i = 0; i < 5; i++)
			{
				for (int j = i; j < 5; j++)
				{
					if (total_marks[i] > total_marks[j])
					{
						highest = total_marks[i];
						index = i;
					}
					else if (total_marks[i] < total_marks[j])
					{
						highest = total_marks[j];
						index = i;
					}
				}
			}
			gotoxy(5, 18);
			cout << "BEST PLAN NO IS: " << index + 1;
			main_selector = yes_or_no(main_selector);
			if (main_selector == 0)
			{
				goto fms_main_menu;
			}
		}
		// CODE BY CROPS
		while (main_selector == 5)
		{
			title("CODE BY CROPS");
			string moves[9] = {"ATTACK-ON-POINT-9", "ATTACK-ON-POINT-F", "ATTACK-ON-POINT-C", "ATTACK-ON-POINT-A", "ATTACK-ON-POINT-S", "ATTACK-ON-POINT-J", "ATTACK-ON-POINT-Q", "ATTACK-ON-POINT-R", "ATTACK-ON-POINT-G"};
			int number[4], checker[4], printer;
			int x = 18;
			for (int i = 0; i < 4; i++)
			{
				gotoxy(columns_of_screen / 4 + 26, x);
				cout << "Number: ";
				gotoxy(columns_of_screen / 4 + 46, x);
				cin >> number[i];
				x++;
			}
			for (int i = 0; i < 4; i++)
			{
				checker[i] = number[i] + i;
				if (checker[i] > 9)
				{
					checker[i] = checker[i] - 10;
				}
			}
			title("CODE BY CROPS");
			int y = -10;
			for (int i = 0; i < 4; i++)
			{

				printer = checker[i];
				gotoxy(columns_of_screen / 4 + y, 9);
				cout << moves[printer] << ", ";
				y = y + 21;
			}
			main_selector = yes_or_no(main_selector);
			if (main_selector == 0)
			{
				goto fms_main_menu;
			}
		}
	}
	else
	{
		system("cls");
		gotoxy(columns_to_fit + 5, rows_of_screen / 2);
		cout << "INVALID! OFFICER YOU DESIRVE PUNISHMENT";
		Sleep(3000);
		goto fms_main_menu;
	}
}
// 6. FOMS ENDED

// 7. SOLDIERS MANAGEMENT SYSTEM
int soldiers_management_system(int checker_of_user_domain)
{
army_soldiers_menu:
	int main_menu_taker;
	string soldiers[3] = {"1. VIEW PERSONAL DETAILS", "2. CALCULATE SALARY", "3. BACK"};
	string personal_details_options[6] = {"SOLDIER NAME      : ", "SOLDIER FATHER    : ", "SOLDIER BATCH ID  : ", "SOLDIER PROVIENCE : ", "SOLDIER RANK : ", "SOLDIER AGE : "};
	title("SOLDIERS MANAGEMENT SYSTEM");
	to_show_three_menu(soldiers);
	main_menu_taker = selected_field();
	while (main_menu_taker == 1)
	{

		int check_batch_id;
		string batch_id;
		title("PERSONAL DETAILS OF ARMY SOLDIER");
		batch_id = id_take_to_fetch();
		check_batch_id = fetch_and_check_id_from_txt(personal_details_options, batch_id, "ams_army_soldiers_batch_id.txt", "ams_army_soldiers_name.txt", "ams_army_soldiers_father_name.txt", "ams_army_soldiers_provience.txt", "ams_army_soldiers_rank.txt", "ams_army_soldiers_age.txt");
		if (check_batch_id == 1)
		{
			main_menu_taker = yes_or_no(main_menu_taker);
			if (main_menu_taker == 0)
			{
				goto army_soldiers_menu;
			}
		}
		else
		{
			gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 10);
			cout << "INVALID !";
			Sleep(2000);
		}
	}
	while (main_menu_taker == 2)
	{
	salary:
		int salary[3] = {50000, 60000, 70000};
		int bonus[3] = {1000, 5000, 4000};
		int catagory;
		float e_day, special_day, total, days_amount;
		system("cls");
		print_start_box(5, columns_of_screen);
		to_print_in_title("SALARY CALCULATOR");
		gotoxy(columns_to_fit + 10, 16);
		cout << "ENTER CATAGORY(1.DRIVER , 2.BOARDER , 3.CHEFF): ";
		gotoxy(columns_to_fit + 60, 16);
		cin >> catagory;
		gotoxy(columns_to_fit + 10, 18);
		cout << "ENTER EXTRA WORKING DAYS: ";
		gotoxy(columns_to_fit + 50, 18);
		cin >> e_day;
		gotoxy(columns_to_fit + 10, 20);
		cout << "ENTER MOVEMENT(EID, NATIONAL etc): ";
		gotoxy(columns_to_fit + 50, 20);
		cin >> special_day;
		if (catagory == 1)
		{
			total = salary[0] + (bonus[0] * special_day) + ((salary[0] / 30) * (e_day));
		}
		else if (catagory == 2)
		{
			total = salary[1] + (bonus[1] * special_day) + ((salary[1] / 30) * (e_day));
		}
		else if (catagory == 3)
		{
			total = salary[2] + (bonus[2] * special_day) + ((salary[2] / 30) * (e_day));
		}
		else
		{
			goto salary;
		}
		gotoxy(columns_of_screen / 2 - columns_to_fit / 2, 9);
		cout << "TOTAL SALARY: " << total;
		main_menu_taker = yes_or_no(main_menu_taker);
		if (main_menu_taker == 0)
		{
			goto army_soldiers_menu;
		}
	}
	if (main_menu_taker == 3)
	{
		return 0;
	}
}
// 7 . SMS

// to show result of candidaties
int to_show_five_persons_result(int marks[5][6], string batch_id[5], int total[5], int columns)
{
	int x = 4;
	for (int i = 0; i < 5; i++)
	{
		int numbering = 1, y = 12;
		gotoxy(x, 10);
		cout << "BATCH ID: " << batch_id[i];
		for (int j = 0; j < columns; j++)
		{
			gotoxy(x, y);
			cout << numbering << ". " << marks[i][j];
			numbering++;
			y++;
		}
		if (total[i] > 500)
		{
			gotoxy(x, 20);
			cout << "PASS";
		}
		else
		{
			gotoxy(x, 20);
			cout << "FAIL";
		}
		x = x + columns_of_screen / 5;
	}
}

// TO GET STUDENTS DATA IN DOUBLE ARRAY
int to_add_data_in_array(int marks[5][6], int rows, int columns)
{
	int x = 18;
	for (int j = 0; j < columns; j++)
	{
		gotoxy(columns_to_fit + 58, x);
		cin >> marks[rows][j];
		x++;
	}
	return marks[2][2];
}
// to show report
int to_show_report(string address)
{
	string retired;
	ifstream recordfile;
	recordfile.open(address);
	while (getline(recordfile, retired))
	{
		cout << "\33[33m";
		gotoxy(columns_to_fit, 10);
		cout << retired;
	}

	recordfile.close();
}
// calculate Instrument Price
double calculate_instruments_price(int item_quantity[5], double item_price[5])
{
	double total = 0;
	for (int i = 0; i < 5; i++)
	{
		total = total + (item_quantity[i] * item_price[i]);
	}
	return total;
}
/*
// ERROR IN IT
//TO SHOW SOLDIERS UNDER OFFICERS
int to_show_soldiers_under_officers(string batch_id)
{
	int result = 0;
	int i = 5,j = 0,arr_size;
	int a = 5,b = 0;
	arr_size = batch_id.length();
	int key_valueo_taker[arr_size - 5];
	string after_batch_id[arr_size - 5],taker;
	while (batch_id[a] != '\0')
	{
		after_batch_id[b] = batch_id[a];
		a++;
		b++;
	}

	while(after_batch_id[i] != '\0')
	{	taker = after_batch_id[i];
		key_valueo_taker[j] = stoi(taker);
		cout<<key_valueo_taker[j];
		i++;
		j++;
		cout<<key_valueo_taker[j];
	}
	int y = 1;
	for(int x = j ; x >= 0 ; x--)
	{
		result = result + key_valueo_taker[x]*y;
		y = y*10;
	}
	cout<<result;
	return 0;
}
// ERROR IN IT
*/
// CROPS CHECK
int fetch_and_check_crops(string province, string batch_id_address, string name_address, string provience_address)
{
	int x = 15;
	string batch, name, f_name, age, province_fetch, rank;
	string personal_data[6];
	int count_persons = 0;
	ifstream batch_id_personal_detailsfile;
	ifstream name_personal_detailsfile;
	ifstream province_personal_detailsfile;
	batch_id_personal_detailsfile.open(batch_id_address);
	name_personal_detailsfile.open(name_address);
	province_personal_detailsfile.open(provience_address);

	for (int i = 1; i <= 9999; i++)
	{
		batch_id_personal_detailsfile >> batch;
		name_personal_detailsfile >> name;
		province_personal_detailsfile >> province_fetch;
		// check batch id and stored id
		if (province == province_fetch && !province_personal_detailsfile.eof())
		{
			personal_data[0] = name;
			personal_data[1] = batch;
			gotoxy(columns_to_fit + 24, x);
			cout << name;
			gotoxy(columns_to_fit + 24, x + 1);
			cout << batch;
			gotoxy(columns_to_fit + 24, x + 2);
			cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
			x = x + 4;
			count_persons++;
		}
	}
	batch_id_personal_detailsfile.close();
	name_personal_detailsfile.close();
	province_personal_detailsfile.close();
	return count_persons;
}
// print graph of items
void graph(int item_quantity[5], string show_instruments[5], double item_price[5])
{
	int j = 0;
	for (int i = columns_of_screen / 8; i < columns_of_screen - 1; i++)
	{
		gotoxy(i, rows_of_screen - 4);
		cout << "*";
	}
	for (int i = rows_of_screen - 4; i > 8; i--)
	{
		gotoxy(columns_of_screen / 8, i);
		cout << "*";
	}
	for (int i = 0; i < 20; i = i + 4)
	{

		gotoxy(2, rows_of_screen / 3 + i);
		cout << show_instruments[j];
		j++;
	}
	int x = 0;
	int screen = columns_of_screen / 8 + 1;
	for (int i = 0; i < 20; i = i + 4)
	{
		for (j = 0; j < item_quantity[x] / 3; j++)
		{
			gotoxy(screen + j, rows_of_screen / 3 + i);
			cout << "#";
		}
		gotoxy(screen + j, rows_of_screen / 3 + i);
		cout << " " << item_quantity[i] * item_price[i];
		x++;
	}
}
// to get five inputs
int to_get_inputs(int name[5])
{
	int j = 0;
	for (int i = 18; i <= 22; i++)
	{
		gotoxy(columns_to_fit + 58, i);
		cin >> name[j];
		j++;
	}
	return name[1];
}
// To fetch using Provience
int fetch_and_check_provience_from_txt(string personal_details_options[6], string province, string batch_id_address, string name_address, string f_name_address, string provience_address, string rank_address, string age_address)
{
	int x = 15;
	string batch, name, f_name, age, province_fetch, rank;
	string personal_data[6];
	int count_persons = 0;
	ifstream batch_id_personal_detailsfile;
	ifstream name_personal_detailsfile;
	ifstream father_name_personal_detailsfile;
	ifstream province_personal_detailsfile;
	ifstream age_personal_detailsfile;
	ifstream rank_personal_detailsfile;

	batch_id_personal_detailsfile.open(batch_id_address);
	name_personal_detailsfile.open(name_address);
	father_name_personal_detailsfile.open(f_name_address);
	province_personal_detailsfile.open(provience_address);
	age_personal_detailsfile.open(age_address);
	rank_personal_detailsfile.open(rank_address);

	for (int i = 1; i <= 9999; i++)
	{
		batch_id_personal_detailsfile >> batch;
		name_personal_detailsfile >> name;
		province_personal_detailsfile >> province_fetch;
		father_name_personal_detailsfile >> f_name;
		age_personal_detailsfile >> age;
		rank_personal_detailsfile >> rank;
		// check batch id and stored id
		if (province == province_fetch && !province_personal_detailsfile.eof())
		{
			personal_data[0] = name;
			personal_data[1] = f_name;
			personal_data[2] = batch;
			gotoxy(columns_to_fit + 24, x);
			cout << name;
			gotoxy(columns_to_fit + 24, x + 1);
			cout << f_name;
			gotoxy(columns_to_fit + 24, x + 2);
			cout << batch;
			gotoxy(columns_to_fit + 24, x + 3);
			cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
			x = x + 4;
			count_persons++;
		}
	}
	batch_id_personal_detailsfile.close();
	name_personal_detailsfile.close();
	father_name_personal_detailsfile.close();
	province_personal_detailsfile.close();
	age_personal_detailsfile.close();
	rank_personal_detailsfile.close();
	return count_persons;
}
// TO VIEW OUR MATRYED
int to_view_matryed(string address)
{
	int i = 10;
	string matryed;
	ifstream view_matryedfile;
	view_matryedfile.open(address);
	while (!view_matryedfile.eof())
	{
		view_matryedfile >> matryed;
		cout << "\33[33m";
		gotoxy(columns_of_screen / 3, i);
		cout << matryed;
		i++;
	}
}
// to ADD Retired Officers and Matryed
int to_add_retire_and_single(string address)
{
	string retired;
	fstream recordfile;
	recordfile.open(address, ios::app);
	gotoxy(columns_of_screen / 3 - 2, 18);
	cout << "ENTER RECORDS";
	gotoxy(columns_to_fit + 10, 20);
	cin >> retired;
	recordfile << endl
			   << retired;
	recordfile.close();
}
// TO SHOW RETIRED
int to_show_data(string address)
{
	int line_mover = 8;
	string retired;
	ifstream recordfile;
	recordfile.open(address);
	while (!recordfile.eof())
	{
		cout << "\33[33m";
		recordfile >> retired;
		gotoxy(columns_to_fit + 15, line_mover);
		cout << retired;
		line_mover++;
	}

	recordfile.close();
}
// to show three menu
int to_show_three_menu(string menu_name[3])
{
	int j = 0;
	for (int i = 18; i <= 22; i = i + 2)
	{
		gotoxy(columns_to_fit + 24, i);
		cout << menu_name[j];
		j++;
	}
	return 0;
}
// To Add Personal Details
int to_add_data_in_txt(string personal_details_options[6], string batch_id_address, string name_address, string f_name_address, string provience_address, string rank_address, string age_address)
{
	string personal_data[6];
	fstream batch_id_personal_detailsfile;
	fstream name_personal_detailsfile;
	fstream father_name_personal_detailsfile;
	fstream province_personal_detailsfile;
	fstream age_personal_detailsfile;
	fstream rank_personal_detailsfile;

	batch_id_personal_detailsfile.open(batch_id_address, ios::app);
	name_personal_detailsfile.open(name_address, ios::app);
	father_name_personal_detailsfile.open(f_name_address, ios::app);
	province_personal_detailsfile.open(provience_address, ios::app);
	age_personal_detailsfile.open(age_address, ios::app);
	rank_personal_detailsfile.open(rank_address, ios::app);
	to_show_six_menu(personal_details_options);
	int j = 0;
	for (int i = 18; i <= 23; i++)
	{
		gotoxy(columns_to_fit + 48, i);
		cin >> personal_data[j];
		j++;
	}
	name_personal_detailsfile << personal_data[0] << endl;
	father_name_personal_detailsfile << personal_data[1] << endl;
	batch_id_personal_detailsfile << personal_data[2] << endl;
	province_personal_detailsfile << personal_data[3] << endl;
	rank_personal_detailsfile << personal_data[4] << endl;
	age_personal_detailsfile << personal_data[5] << endl;

	batch_id_personal_detailsfile.close();
	name_personal_detailsfile.close();
	father_name_personal_detailsfile.close();
	province_personal_detailsfile.close();
	age_personal_detailsfile.close();
	rank_personal_detailsfile.close();

	return 0;
}
// add new or move back function
int yes_or_no(int perior_option)
{
	int select_option;
	gotoxy(columns_to_fit + 15, 26);
	cout << "IS YOU WANT TO REPEAT THAT TASK (" << perior_option << " / 0): ";
	gotoxy(columns_to_fit + 56, 26);
	cin >> select_option;
	return select_option;
}
// to fetch data for system using single array and check batch id
int fetch_and_check_id_from_txt(string personal_details_options[6], string batch_id, string batch_id_address, string name_address, string f_name_address, string provience_address, string rank_address, string age_address)
{
	string batch, name, f_name, age, province, rank;
	string personal_data[6];

	ifstream batch_id_personal_detailsfile;
	ifstream name_personal_detailsfile;
	ifstream father_name_personal_detailsfile;
	ifstream province_personal_detailsfile;
	ifstream age_personal_detailsfile;
	ifstream rank_personal_detailsfile;

	batch_id_personal_detailsfile.open(batch_id_address);
	name_personal_detailsfile.open(name_address);
	father_name_personal_detailsfile.open(f_name_address);
	province_personal_detailsfile.open(provience_address);
	age_personal_detailsfile.open(age_address);
	rank_personal_detailsfile.open(rank_address);

	for (int i = 1; i <= 9999; i++)
	{
		batch_id_personal_detailsfile >> batch;
		name_personal_detailsfile >> name;
		province_personal_detailsfile >> province;
		father_name_personal_detailsfile >> f_name;
		age_personal_detailsfile >> age;
		rank_personal_detailsfile >> rank;
		// check batch id and stored id
		if (batch == batch_id)
		{
			to_show_six_menu(personal_details_options);
			personal_data[0] = name;
			personal_data[1] = f_name;
			personal_data[2] = batch_id;
			personal_data[3] = province;
			personal_data[4] = rank;
			personal_data[5] = age;

			to_show_six_personal_details(personal_data);
			batch_id_personal_detailsfile.close();
			name_personal_detailsfile.close();
			father_name_personal_detailsfile.close();
			province_personal_detailsfile.close();
			age_personal_detailsfile.close();
			rank_personal_detailsfile.close();

			return 1;
		}
	}
	batch_id_personal_detailsfile.close();
	name_personal_detailsfile.close();
	father_name_personal_detailsfile.close();
	province_personal_detailsfile.close();
	age_personal_detailsfile.close();
	rank_personal_detailsfile.close();
	return 0;
}
// to show eight menu
int to_show_eight_menu(string menu_name[8])
{
	int j = 0;
	for (int i = 17; i <= 24; i++)
	{
		gotoxy(columns_to_fit + 24, i);
		cout << menu_name[j];
		j++;
	}
	return 0;
}
// to show six menu
int to_show_six_personal_details(string menu_name[6])
{
	int j = 0;
	for (int i = 18; i <= 23; i++)
	{
		gotoxy(columns_to_fit + 48, i);
		cout << menu_name[j];
		j++;
	}
	return 0;
}
// Enter Your Field Getter
int selected_field()
{
	int select_field;
	gotoxy(columns_to_fit + 52, 26);
	cin >> select_field;
	return select_field;
}
// To take batch id or anything like that
string id_take_to_fetch()
{
	string batch_id;
	gotoxy(columns_to_fit + 20, 26);
	cout << "                             ";
	gotoxy(columns_of_screen / 2 - 10, 9);
	cout << "BATCH ID: ";
	gotoxy(columns_of_screen / 2, 9);
	cin >> batch_id;
	return batch_id;
}
// To Show 6 Menu
int to_show_six_menu(string menu_name[6])
{
	int j = 0;
	for (int i = 18; i <= 23; i++)
	{
		gotoxy(columns_to_fit + 24, i);
		cout << menu_name[j];
		j++;
	}
	return 0;
}
// print content_inside_title
void to_print_in_title(string content_inside_title)
{
	gotoxy(columns_of_screen / 2 - 17, 2);
	cout << content_inside_title;
}
// measure screen size
int screen_size()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns_of_screen = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows_of_screen = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	rows_to_fit = rows_of_screen / 4;
	columns_to_fit = columns_of_screen / 4;
	return 0;
}
// TAKE USER ID FROM DIFFERENT FUNCTINS THEN CHECK IT AND RETURN NUMBER
int user_id()
{
	int to_count_user_word;
	string user, pass;
in_case_wrong:
	system("cls");
	first_page_title();
	home_page();
	user = take_username();
	pass = take_password();
	to_count_user_word = user.length();
	if ((user[to_count_user_word - 1] == 's' && user[to_count_user_word - 2] == 'm' && user[to_count_user_word - 3] == 'a') && (pass == "AMS18082"))
	{
		return 1;
	}
	else if ((user[to_count_user_word - 1] == 's' && user[to_count_user_word - 2] == 'm' && user[to_count_user_word - 3] == 'n') && (pass == "NMS18082"))
	{
		return 2;
	}
	else if ((user[to_count_user_word - 1] == 's' && user[to_count_user_word - 2] == 'm' && user[to_count_user_word - 3] == 'f' && user[to_count_user_word - 4] == 'a') && (pass == "AFMS18082"))
	{
		return 3;
	}
	else if ((user[to_count_user_word - 1] == 's' && user[to_count_user_word - 2] == 'm' && user[to_count_user_word - 3] == 'o' && user[to_count_user_word - 4] == 'a') && (pass == "AOMS18082"))
	{
		return 4;
	}
	else if ((user[to_count_user_word - 1] == 's' && user[to_count_user_word - 2] == 'm' && user[to_count_user_word - 3] == 'o' && user[to_count_user_word - 4] == 'n') && (pass == "NOMS18082"))
	{
		return 5;
	}
	else if ((user[to_count_user_word - 1] == 's' && user[to_count_user_word - 2] == 'm' && user[to_count_user_word - 3] == 'o' && user[to_count_user_word - 4] == 'f') && (pass == "FOMS18082"))
	{
		return 6;
	}
	else if ((user[to_count_user_word - 1] == 's' && user[to_count_user_word - 2] == 'm' && user[to_count_user_word - 3] == 's') && (pass == "SMS18082"))
	{
		return 7;
	}
	else
	{
		gotoxy(columns_of_screen / 2, rows_of_screen - 3);
		cout << "INVALID !";
		Sleep(3000);
		goto in_case_wrong;
	}
}
// take user id
string take_username()
{
	string user;
	gotoxy(columns_to_fit + 15, 17);
	cin >> user;
	return user;
}
// take password
string take_password()
{
	string pass;
	gotoxy(columns_to_fit + 15, 23);
	cin >> pass;
	return pass;
}
void home_page()
{
	print_line(columns_to_fit, 14, columns_of_screen - columns_to_fit);
	print_line(columns_to_fit, 20, columns_of_screen - columns_to_fit);
	print_line(columns_to_fit, 26, columns_of_screen - columns_to_fit);
	gotoxy(columns_to_fit, 17);
	cout << "\33[34m"
		 << "USERNAME: ";
	gotoxy(columns_to_fit, 23);
	cout << "\33[34m"
		 << "PASSWORD: ";
}
// first page title
void first_page_title()
{
	int columns;
	print_start_box(5, columns_of_screen);
	to_print_in_title("PAKISTAN FORCES MANAGEMENT SYSTEM");
	columns = columns_to_fit / 7;
	gotoxy(columns, 6);
	cout << "\033[32m"
		 << "..../\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\")=======||||||D		              DIE IN THE PATH OF SUCCESS                       (|||||=======/\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\")..." << endl;
	gotoxy(columns, 7);
	cout << "\033[32m"
		 << "/\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\\                                                                                           /\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\\" << endl;
	gotoxy(columns, 8);
	cout << "\033[32m"
		 << "\\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/                                                                                           \\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/" << endl
		 << endl
		 << endl;
}
// PRINT START BOX
void print_start_box(int rows, int columns)
{
	for (int i = 1; i <= rows; ++i)
	{
		for (int j = 1; j <= columns; ++j)
		{
			if (i == 1 || i == rows || j == 1 || j == columns)
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}
// TITLE ON EVERY PAGE AND USE TO PRINT TITLE FUNCTION IN IT
void title(string content_inside_title)
{
	system("cls");
	print_start_box(5, columns_of_screen - 2);
	gotoxy((columns_of_screen / 3) + 5, 6);
	cout << "\033[31m"
		 << "Allah loveth not those who are aggressors"
		 << "\033[37m" << endl;
	gotoxy((columns_of_screen / 3) + 5, 7);
	cout << "_________________________________________ " << endl
		 << endl
		 << endl
		 << endl;
	gotoxy((columns_to_fit), 11);
	cout << "#########################################################################" << endl;
	gotoxy((columns_to_fit), 12);
	cout << "#                                                                       #" << endl;
	gotoxy((columns_to_fit), 13);
	cout << "#                                                                       #" << endl;
	gotoxy((columns_to_fit), 14);
	cout << "#                       CHOSE ONE OF THE OPTION                         #" << endl;
	gotoxy((columns_to_fit), 15);
	cout << "#                       _______________________                         #" << endl;
	gotoxy((columns_to_fit), 16);
	cout << "#                       #######################                         #" << endl;
	gotoxy((columns_to_fit), 17);
	cout << "#                                                                       #" << endl;
	gotoxy((columns_to_fit), 18);
	cout << "#                                                                       #" << endl;
	gotoxy((columns_to_fit), 19);
	cout << "#                                                                       #" << endl;
	gotoxy((columns_to_fit), 20);
	cout << "#                                                                       #" << endl;
	gotoxy((columns_to_fit), 21);
	cout << "#                                                                       #" << endl;
	gotoxy((columns_to_fit), 22);
	cout << "#                                                                       #" << endl;
	gotoxy((columns_to_fit), 23);
	cout << "#                                                                       #" << endl;
	gotoxy((columns_to_fit), 24);
	cout << "#                                                                       #" << endl;
	gotoxy((columns_to_fit), 25);
	cout << "#                                                                       #" << endl;
	gotoxy((columns_to_fit), 26);
	cout << "#                        Enter Your Field Number:                       #" << endl;
	gotoxy((columns_to_fit), 27);
	cout << "#########################################################################" << endl
		 << endl
		 << endl
		 << endl
		 << endl
		 << endl
		 << endl
		 << endl;
	gotoxy((columns_of_screen / 3) - 10, 32);
	cout << "And when you judge between people, judge with justice. (Al Quran)" << endl;
	gotoxy((columns_of_screen / 3) - 10, 33);
	cout << "_________________________________________________________________" << endl;
	to_print_in_title(content_inside_title);
}
// GOTOXY
void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
// GETCHAR
char getCharAtxy(short int x, short int y)
{
	CHAR_INFO ci;
	COORD xy = {0, 0};
	SMALL_RECT rect = {x, y, x, y};
	COORD coordBufsize;
	coordBufsize.X = 1;
	coordBufsize.Y = 1;
	return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufsize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void print_line(int start_point,int row,int end_point)
{
	for(int i = start_point ; i <= end_point ; i++)
	{
		gotoxy(i,row);
		cout<<"*";
	}
}