#ifndef __ARENA__H__
#define __ARENA__H__

struct arena {
	char *data, *ptr, *end;
};

void arena_init(struct arena *arena, size_t size);
void *arena_alloc(struct arena *arena, size_t size);
void arena_free(struct arena *arena);
struct arena *arena_ourobourus(struct arena *tail);
struct arena *arena_bootstrap(size_t size);
#endif //!__ARENA__H__
