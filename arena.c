#include "arena.h"
#include <stdlib.h>
#include <string.h>

void arena_init(struct arena *arena, size_t size) {
	arena->data = malloc(size);
	arena->end = arena->data + size;
	arena->ptr = arena->data;
}

void *arena_alloc(struct arena *arena, size_t size) {
	void *ptr = arena->ptr;
	size_t misalign = size % 8;
	arena->ptr += misalign ? size + 8 - misalign : size;
	return ptr;
}

void arena_free(struct arena *arena) {
	free(arena->data);
	memset(arena, 0, sizeof(struct arena));
}

struct arena *arena_ourobourus(struct arena *tail) {
	struct arena *head = arena_alloc(tail, sizeof(struct arena));
	memcpy(head, tail, sizeof(struct arena));
	return head;
}

struct arena *arena_bootstrap(size_t size) {
	struct arena tail;
	arena_init(&tail, size);
	return arena_ourobourus(&tail);
}
