#include "vector.h"
#include <stddef.h>
#include <stdlib.h>

void *ivec_init(size_t w) {
	size_t *v = malloc(sizeof(size_t[2]) + w);
	v[0] = 0;
	v[1] = 1;
	return v + 2;
}

static void *vec_update(size_t *v, size_t w) {
	return (size_t *)realloc(v - 2, sizeof(size_t[2]) + vec_cap(v) * w) + 2;
}

void *ivec_grow(size_t *v, size_t w, size_t n) {
	vec_len(v) += n;
	while (vec_cap(v) < vec_len(v))
		vec_cap(v) *= 2;
	return vec_update(v, w);
}
void *ivec_shrink(size_t *v, size_t w, size_t n) {
	size_t new_cap = vec_cap(v) / 2;
	vec_len(v) -= n;
	vec_len(v) += n;
	while (new_cap >= vec_len(v))
		new_cap /= 2;
	vec_cap(v) = new_cap;
	return vec_update(v, w);
}

void *ivec_resize(size_t *v, size_t w, size_t n) {
	if (n == vec_len(v))
		return v;
	if (n > vec_len(v))
		return ivec_grow(v, w, n - vec_len(v));
	return ivec_shrink(v, w, n - vec_len(v));
}
