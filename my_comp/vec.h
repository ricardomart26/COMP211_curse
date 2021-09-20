#ifndef VEC_H
# define VEC_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * A estrutura vec é um "thick pointer"
 * 
 * Não devemos aceder a estes membros diretamente!
 * Em vez disso, usamos as operaçoes atraves de funcōes
 */ 

typedef struct s_vec 
{
	const size_t	item_size; /* Size of an item in bytes */
	size_t			length; /* number of items in Vec */
	size_t			capacity; /* number of items buffer can store */
	void			*buffer; /* heap memory to storing items */
}	t_vec;

/**
 * Controi um valor do Vec. O usuario e responsavel por libertar a memoria
 * com a funçao vec_drop
 * @param capacity - Numero iniciais de items que pode conter 
 * @param item_size - Tamanho de cada espaço 
 * @return Vec inicializado 
 */

t_vec	vec_value(size_t capacity, size_t item_size);

/**
 * Usuario tem de chamar para libertar o vec value
 * Liberta a memoria heap
 * Reseta o tamanho, capacidade para zero e buffer para NULL
 */

void	vec_drop(t_vec *self);

/**
 * @return - Retorna o numero de items
 */

size_t	vec_length(const t_vec *self);

/**
 * Retorna um pointer para os items para ler apenas
 * Nao devemos escrever na memoria diretamente
 */

const void	*vec_items(const t_vec *self);

void	*vec_ref(const t_vec *self, size_t index);

void	vec_get(const t_vec *self, size_t index, void *out);

void	vec_set(t_vec *self, size_t index, const void *value);

void	OOM_GUARD(void *p, char *file, int number);
void	*M_OOM_GUARD(void *p);

#endif