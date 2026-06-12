#include "arena.h"
#include <stdlib.h>
#include <string.h>

void arena_init(struct arena *arena, size_t size) {
	arena->data = malloc(size);
	arena->idx = 0;
	arena->len = size;
}

void *arena_alloc(struct arena *arena, size_t size) {
	void *ptr = arena->data + arena->idx;
	size_t misalign = size % ARENA_ALIGNMENT;
	size = misalign ? size + ARENA_ALIGNMENT - misalign : size;
	arena->idx += size;
	if (arena->idx > arena->len) {
		do
			arena->len *= 2;
		while (arena->idx > arena->len);
		void *new = realloc(arena->data, arena->len);
		if (!new)
			return NULL;
		arena->data = new;
	}
	return ptr;
}

void arena_free(struct arena *arena) {
	free(arena->data);
	memset(arena, 0, sizeof(struct arena));
}
// BROKEN BY REALLOCATION!!!!
// struct arena *arena_ourobourus(struct arena *tail) {
// 	struct arena *head = arena_alloc(tail, sizeof(struct arena));
// 	memcpy(head, tail, sizeof(struct arena));
// 	return head;
// }

// struct arena *arena_bootstrap(size_t size) {
// 	struct arena tail;
// 	arena_init(&tail, size);
// 	return arena_ourobourus(&tail);
// }
