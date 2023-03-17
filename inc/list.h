#pragma once

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

t_list *mx_create_node(void *data);

void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);

void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
void mx_pop_index(t_list **list, int index);
void mx_pop_node(t_list **head, t_list *node);

void mx_clear_list(t_list **list);

int mx_list_size(t_list *list);
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));

t_list *mx_get_by_index(t_list *head, int index);

void mx_reverse_list(t_list *head);
