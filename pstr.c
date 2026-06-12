#include "pstr.h"
#include <stdlib.h>
#include <string.h>

void pstr_sub(struct pstr *dst, struct pstr const *src, size_t idx, size_t len) {
	dst->src = src->src + idx;
	dst->len = len;
}
void pstr_cpy(struct pstr *dst, struct pstr const *src, size_t idx, size_t len) {
	dst->src = malloc(len);
	memcpy(dst->src, src->src + idx, dst->len = len);
}
