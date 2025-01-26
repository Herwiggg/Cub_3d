/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:27:31 by almichel          #+#    #+#             */
/*   Updated: 2025/01/27 00:39:08 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int is_delim(char c)
{
    return (c == ' ' || c == '\t' || c == ',' || c == '\n');
}

/* Libère correctement un tableau de char* (tab), 
 * qui a été alloué avec k "mots" déjà créés. */
char **ft_doublefree(char **tab, int k)
{
    int i;

    for (i = 0; i < k; i++)
        free(tab[i]);
    free(tab);
    return (NULL);
}

/*
 * Cette fonction compte le nombre de "mots" dans la chaîne "str".
 * Un "mot" est défini comme une séquence consécutive de caractères
 * qui NE sont PAS des délimiteurs (espaces, virgules, etc.).
 */
int ft_count(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i])
    {
        /* On saute d'abord tous les délimiteurs. */
        while (str[i] && is_delim(str[i]))
            i++;
        /* Si on n'est pas en fin de chaîne, on est au début d'un mot. */
        if (str[i] && !is_delim(str[i]))
        {
            count++;
            /* Avancer jusqu'à retomber sur un délimiteur (ou la fin). */
            while (str[i] && !is_delim(str[i]))
                i++;
        }
    }
    return (count);
}

/*
 * Alloue les sous-chaînes dans tab[k], en fonction des longueurs
 * calculées en parcourant la chaîne str.
 */
char **ft_split_modif2(char *str, char **tab)
{
    int i = 0;
    int k = 0;
    int nb_mots = ft_count(str);

    while (k < nb_mots)
    {
        int j = 0;

        /* Sauter les éventuels délimiteurs (espaces, virgules, etc.). */
        while (str[i] && is_delim(str[i]))
            i++;
        /* Compter la longueur du prochain "mot". */
        while (str[i + j] && !is_delim(str[i + j]))
            j++;
        /* Allouer la place pour ce mot + le '\0' final. */
        tab[k] = (char *)malloc(sizeof(char) * (j + 1));
        if (!tab[k])
            return (ft_doublefree(tab, k));
        /* Avancer i pour être prêt pour le mot suivant. */
        i += j;
        k++;
    }
    /* IMPORTANT : on retourne tab, pas NULL (sauf si échec d'allocation) */
    return (tab);
}

/*
 * Copie réellement les caractères des "mots" dans tab[k].
 */
char **ft_strcpy_modif(char **tab, char *str)
{
    int i = 0;
    int k = 0;
    int nb_mots = ft_count(str);

    while (k < nb_mots)
    {
        int j = 0;

        /* Sauter les délimiteurs. */
        while (str[i] && is_delim(str[i]))
            i++;
        /* Copier les caractères du mot dans tab[k]. */
        while (str[i] && !is_delim(str[i]))
        {
            tab[k][j] = str[i];
            j++;
            i++;
        }
        tab[k][j] = '\0'; /* fin de chaîne */
        k++;
    }
    tab[k] = NULL; /* le dernier pointeur doit être NULL */
    return (tab);
}

/*
 * Fonction principale de split. Elle :
 * 1) calcule le nb de mots
 * 2) alloue le tableau de pointeurs (tab)
 * 3) alloue l'espace pour chaque mot via ft_split_modif2
 * 4) copie les mots dans tab via ft_strcpy_modif
 */
char **ft_split_modif(char *str)
{
    char **tab;
    int nb_mots;

    if (!str)
        return (NULL);
    nb_mots = ft_count(str);
    tab = (char **)malloc(sizeof(char *) * (nb_mots + 1));
    if (!tab)
        return (NULL);
    /* On alloue les sous-chaînes. */
    if (!ft_split_modif2(str, tab))
        return (NULL); /* si échec d'allocation intermédiaire, c’est déjà free */
    /* On copie ensuite le contenu effectif. */
    ft_strcpy_modif(tab, str);
    return (tab);
}