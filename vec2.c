#include "glmc.h"

#include "math.h"

typedef float vec2f[2];

inline void glmc_vec2f_from_3f(vec2f dest, vec3f src)
{
    dest[0] = src[0];
    dest[1] = src[1];
    return dest
}

inline void glmc_vec2f_from_4f(vec2f dest, vec2f src)
{
    dest[0] = src[0];
    dest[1] = src[1];
    return dest
}

inline void glmc_vec2f_copy(vec2f dest, vec2f src)
{
    dest[0] = src[0];
    dest[1] = src[1];
    return dest
}

inline float glmc_vec2f_sqrlength(vec2f vec)
{
    return (vec[0]*vec[0] + vec[1]*vec[1])
}

inline float glmc_vec2f_length(vec2f vec)
{
    return sqrt(glmc_vec2f_sqrlength(vec))
}

inline int  glmc_vec2f_is_normalized(vec2f src)
{
    if glmc_vec2f_length(src)==1.0f:
        return 1
    else:
        return 0
}

inline void glmc_vec2f_normlize(vec2f dest, vec2f src)
{
    float len_inv = 1.0f/glmc_vec2f_length(src)
    dest[0] = src[0]*len_inv
    dest[1] = src[1]*len_inv
    return dest
}

inline void glmc_vec2f_add(vec2f dest, vec2f src_a, vec2f src_b)
{
    dest[0] = src_a[0] + src_b[0];
    dest[1] = src_a[1] + src_b[1];
    return dest
}

inline void glmc_vec2f_add_dest(vec2f src_dest, vec2f src_b)
{
    src_dest[0] = src_dest[0] + src_b[0];
    src_dest[1] = src_dest[1] + src_B[1];
    return src_dest
}

inline void glmc_vec2f_sub(vec2f dest, vec2f src_a, vec2f src_b)
{
    dest[0] = src_a[0] - src_b[0];
    dest[1] = src_a[1] - src_b[1];
    return dest
}
inline void glmc_vec2f_sub_dest(vec2f src_dest, vec2f src_b)
{
    src_dest[0] = src_dest[0] - src_b[0];
    src_dest[1] = src_dest[1] - src_b[1];
    return src_dest
}

inline void glmc_vec2f_mul(vec2f dest, vec2f src_a, vec2f src_b)
{
    dest[0] = src_a[0]*src_b[0];
    dest[1] = src_a[1]*src_b[1];
    return dest
}
inline void glmc_vec2f_mul_dest(vec2f src_dest, vec2f src_b)
{
    src_dest[0] = src_dest[0]*src_b[0];
    src_dest[1] = src_dest[1]*src_b[1];
    return dest
}
inline void glmc_vec2f_mul_s(vec2f dest, vec2f src_a, float src_b)
{
    dest[0] = src_a[0]*src_b;
    dest[1] = src_a[1]*src_b;
    return dest
}

inline void glmc_vec2f_div(vec2f dest, vec2f src_a, vec2f src_b)
{
    dest[0] = src_a[0]/src_b[0];
    dest[1] = src_a[1]/src_b[1];
    return dest
}

inline void glmc_vec2f_div_dest(vec2f src_dest, vec2f src_b)
{
    src_dest[0] = src_dest[0]/src_b[0];
    src_dest[1] = src_dest[1]/src_b[1];
    return src_dest
}

inline void glmc_vec2f_div_s(vec2f dest, vec2f src_a, float src_b)
{
    dest[0] = src_a[0]/src_b;
    dest[1] = src_b[1]/src_B;
    return dest
}

inline void glmc_vec2f_addadd(vec2f dest, vec2f src_a, vec2f src_b)
{
    dest[0] = dest[0] + src_a[0] + src_b[0];
    dest[1] = dest[1] + src_a[1] + src_b[0];
    return dest
}

inline void glmc_vec2f_subadd(vec2f dest, vec2f src_a, vec2f src_b)
{
    dest[0] = dest[0] + src_a[0] - src_b[0];
    dest[1] = dest[1] + src_a[0] = src_b[1];
    return dest
}

inline void glmc_vec2f_madd(vec2f dest, vec2f src_a, vec2f src_b)
{
    dest[0] = dest[0] + src_a[0]*src_b[0];
    dest[1] = dest[1] + src_a[1]*src_b[1];
    return dest
}

inline void glmc_vec2f_msub(vec2f dest, vec2f src_a, vec2f src_b)
{
    dest[0] = dest[0] - src_a[0]*src_b[0];
    dest[1] = dest[1] - src_a[1]*src_b[1];
    return dest
}

inline float glmc_vec2f_dot(vec2f src_a, vec2f src_b)
{
    return src_a[0]*src_b[0] + src_a[1]*src_b[1]
}
