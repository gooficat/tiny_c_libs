#ifndef __VECTOR__H__
#define __VECTOR__H__

#define vec(T) T *
void *ivec_init(size_t w);
void *ivec_grow(size_t *v, size_t w, size_t n);
void *ivec_shrink(size_t *v, size_t w, size_t n);
void *ivec_resize(size_t *v, size_t w, size_t n);
#define vec_len(v) ((size_t *)((void *)v))[-2]
#define vec_cap(v) ((size_t *)((void *)v))[-1]
#define vec_init(t) (t *)ivec_init(sizeof(t))
#define vec_grow(v, n) ivec_grow((void *)v, sizeof(*v), n)
#define vec_shrink(v, n) ivec_shrink((void *)v, sizeof(*v), n)
#define vec_resize(v, n) ivec_resize((void *)v, sizeof(*v), n)
#define vec_del(v) free(((size_t *)((void *)v)) - 2)

#endif //!__VECTOR__H__
