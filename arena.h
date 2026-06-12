#ifndef __ARENA__H__
#define __ARENA__H__

#define ARENA_ALIGNMENT 16

struct arena {
	char *data;
	size_t idx, len;
};

void arena_init(struct arena *arena, size_t size);
void *arena_alloc(struct arena *arena, size_t size);
void arena_free(struct arena *arena);

// BROKEN BY REALLOCATION!!!!
// struct arena *arena_ourobourus(struct arena *tail);
// struct arena *arena_bootstrap(size_t size);
#endif //!__ARENA__H__
