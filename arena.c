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
	arena->ptr += size;
	return ptr;
}

void arena_free(struct arena *arena) {
	free(arena->data);
	memset(arena, 0, sizeof(struct arena));
}
