#ifndef __HASH__H__
#define __HASH__H__

#include <stddef.h>
#include <stdint.h>

uint64_t fnv_1a(char const *data);

struct hash_el {
	char const *key;
	void *value;
};

struct hash_map {
	struct hash_el *elements;
	size_t cap;
};

void hashmap_init(struct hash_map *map);
struct hash_el *hashmap_insert(struct hash_map *map, char const *key, void *value);
struct hash_el *hashmap_find(const struct hash_map *map, char const *key);
void hashmap_from_list(char const *const *const list, struct hash_map *map);

#endif //!__HASH__H__
