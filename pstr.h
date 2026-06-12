#ifndef __PSTR__H__
#define __PSTR__H__

#include <stddef.h>

struct pstr {
	char *src;
	size_t len;
};

void pstr_sub(struct pstr *dst, struct pstr const *src, size_t idx, size_t len);
void pstr_dup(struct pstr *dst, char const *src, size_t idx, size_t len);

#endif //!__PSTR__H__
