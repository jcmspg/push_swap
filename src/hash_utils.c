/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:03:34 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/10 19:42:14 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// hash functions



// hash function
unsigned int ft_hash(char *str)
{
    unsigned long hash;
    int c;

    hash = 5381;
    c = *str;
    while (c)
    {
        hash = ((hash << 5) + hash) + c;
        str++;
        c = *str;
    }
    return (hash % HASH_SIZE);
}

// create the hashset
t_hashset *ft_create_hash()
{
    t_hashset *hashset;
    int i;

    hashset = (t_hashset *)malloc(sizeof(t_hashset));
    if (!hashset)
        return (NULL);
   
    hashset->array = (t_hashnode **)malloc(HASH_SIZE * sizeof(t_hashnode *));

    i = 0;
    while (i < HASH_SIZE)
    {
        hashset->array[i] = NULL;
        i++;
    }
    return (hashset);
}

// insert strings into the hashset
// 1 hash the string
// 2 check if the string is already in the hashset
// 3 if not, create a new node and insert it in the hashset
int ft_insert_hash(t_hashset *hashset, char *key)
{
    unsigned int index;
    t_hashnode *new_node;
    t_hashnode *tmp;

    index = ft_hash(key);
    tmp = hashset->array[index];
    while (tmp)
    {
        if (ft_strcmp(tmp->key, key) == 0)
            return (0); // string already in hashset. duplicate found
        tmp = tmp->next;
    }
    new_node = (t_hashnode *)malloc(sizeof(t_hashnode)); // create new node
    if (!new_node)
        return (0);
    new_node->key = ft_strdup(key); // copy the string
    new_node->next = hashset->array[index]; // insert the node in the hashset
    hashset->array[index] = new_node; // update the hashset
    return (1); // string inserted
}

//check if string exists in the hashset
int ft_duplicate(t_hashset *hashset, char *key)
{
    unsigned int index;
    t_hashnode *tmp;

    index = ft_hash(key); // get the index of the string
    tmp = hashset->array[index]; // get the linked list at that index
    while(tmp)
    {
        if (ft_strcmp(tmp->key, key) == 0)
            return (1); // string found
        tmp = tmp->next; // go to the next node
    }
    return (0); // string not found, no duplicates
}

void ft_free_hash(t_hashset *hashset)
{
    t_hashnode *tmp;
    t_hashnode *next;
    int i;

    i = 0;
    while(i < HASH_SIZE)
    {
        tmp = hashset->array[i];
        while (tmp)
        {
            next = tmp;
            tmp = tmp->next;
            free(next->key);
            free(next);
        }
        hashset->array[i] = NULL;
        i++;
    }
    free(hashset->array);
    free(hashset);
}

