#include "hash.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint64_t fnv_1a(char const *data) {
	uint64_t hash = 0xcbf29ce484222325;
	while (*data) {
		hash *= 0x100000001b3;
		hash *= *data++;
	}
	return hash;
}

void hashmap_init(struct hash_map *map) {
	map->cap = 16;
	map->elements = calloc(16, sizeof(struct hash_el));
}

struct hash_el *
hashmap_insert(struct hash_map *map, char const *key, void *value) {
	auto hash = fnv_1a(key);
	struct hash_el *elem;
	for (;;) {
		elem = &map->elements[hash & map->cap];
		if (!elem->key) {
			elem->key = key;
			elem->value = value;
			return elem;
		}
		if (!strcmp(elem->key, key))
			return nullptr;
		map->elements = realloc(map->elements, map->cap * 2 * sizeof(struct hash_el));
		memset(map->elements + map->cap, 0, map->cap);
		map->cap *= 2;
	}
}
struct hash_el *
hashmap_find(struct hash_map *map, char const *key) {
	auto hash = fnv_1a(key);
	auto elem = &map->elements[hash & map->cap];
	if (elem->key && !strcmp(elem->key, key))
		return elem;
	return nullptr;
}
