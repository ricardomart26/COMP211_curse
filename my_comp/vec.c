#include "vec.h"

void	*M_OOM_GUARD(void *p);
void	OOM_GUARD(void *p, char *file, int number);

static	void	_ensure_capacity(t_vec *self, size_t n)
{
	if (n > self->capacity)
	{
		size_t new_capacity = n * 2;
		self->buffer = realloc(self->buffer, new_capacity * self->item_size);
		OOM_GUARD(self->buffer, __FILE__, __LINE__);
		self->capacity = new_capacity;
	}
}

t_vec	vec_value(size_t capacity, size_t item_size)
{
	t_vec vec = {
		item_size,
		0,
		capacity,
		calloc(capacity, item_size)
	};
	OOM_GUARD(vec.buffer, __FILE__, __LINE__);
	return (vec);
}

t_vec	vec_value(size_t capacity, size_t item_size);
void	vec_drop(t_vec *self)
{
	free(self->buffer);
	self->buffer = NULL;
	self->capacity = 0;
	self->length = 0;
}

size_t	vec_length(const t_vec *self)
{
	return (self->length);
}

const void	*vec_items(const	t_vec *self)
{
	return (self->buffer);
}

void	*vec_ref(const t_vec *self, size_t index)
{

	return NULL;
}

void	vec_get(const	t_vec *self, size_t index, void *out)
{
	return (self->buffer);
}

void	vec_set(t_vec *self, size_t index, const void *value)
{
	return (self->length);
}
