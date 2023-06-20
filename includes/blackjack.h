/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-elliot.feuilllade
** File description:
** blackjack
*/

#pragma once

#include "../includes/my.h"

#define WIDTH 20
#define HEIGHT 10

typedef enum {
    MENU,
    GAME,
    RULES,
    QUIT
} state_e;

typedef enum {
    COEUR,
    PIQUE,
    CARREAU,
    TREFLE
} couleur_e;

typedef enum {
    AS,
    DEUX,
    TROIS,
    QUATRE,
    CINQ,
    SIX,
    SEPT,
    HUIT,
    NEUF,
    DIX,
    VALET,
    DAME,
    ROI
} valeur_e;

typedef struct carte_s{
    couleur_e couleur;
    valeur_e valeur;
    struct carte_s *next;
} carte_t;

typedef struct {
    char **label;
    int highlight;
    int choice;
} menu_t;

typedef struct {
    menu_t *menu;
    WINDOW *win;
    state_e state;
} global_t;

carte_t *create_deck(void);
void shuffle_deck(carte_t** deck);
carte_t* draw_card(carte_t** deck);
global_t *init(void);
menu_t *init_menu(global_t *global);
void print_menu(global_t *global);
void print_rules(global_t *global);
void menu(global_t *global);
void game_process(global_t *global, carte_t *player, carte_t *dealer);
void print_cards(carte_t *dealer, carte_t *player);
