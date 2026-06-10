#ifndef __VECTOR__H__
#define __VECTOR__H__

#define vec(T) T *
void *ivec_init(size_t w);
void *ivec_grow(size_t *v, size_t w, size_t n);
void *ivec_shrink(size_t *v, size_t w, size_t n);
void *ivec_resize(size_t *v, size_t w, size_t n);
#define vec_len(v) ((size_t *)v)[-2]
#define vec_cap(v) ((size_t *)v)[-1]
#define vec_init() ivec_init(sizeof(*v))
#define vec_grow(v, n) ivec_grow(v, sizeof(*v), n)
#define vec_shrink(v, n) ivec_shrink(v, sizeof(*v), n)
#define vec_resize(v, n) ivec_resize(v, sizeof(*v), n)
#define vec_del(v) free(((size_t *)v) - 2)

#endif //!__VECTOR__H__
