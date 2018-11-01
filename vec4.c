#include "glmc.h"

#include "math.h"

typedef float vec4f[4];

inline void glmc_vec4f_from_2f(vec4f dest, vec2f src_a, float src_b, float src_c)
{
    dest[0] = src_a[0];
    dest[1] = src_a[1];
    dest[2] = src_b;
    dest[3] = src_c;
}
inline void glmc_vec4f_from_3f(vec4f dest, vec3f src_a, float src_b)
{
    dest[0] = src_a[0];
    dest[1] = src_a[1];
    dest[2] = src_a[2];
    dest[3] = src_b;
}

inline void glmc_vec4f_copy(vec4f dest, vec4f src)
{
    dest[0] = src[0];
    dest[1] = src[1];
    dest[2] = src[2];
    dest[3] = src[3];
}

inline float glmc_vec4f_sqrlength(vec4f vec)
{
    return vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2] + vec[3]*vec[3]
}
inline float glmc_vec4f_length(vec4f vec)
{
    return sqrt(glmc_vec4_sqrlength(vec))
}

inline int glmc_vec4f_is_normalized(vec4f src)
{
    if glmc_vec4f_length(vec) == 1.0f:
        return 1
    else:
        return 0
}
inline void glmc_vec4f_normlize(vec4f dest, vec4f src)
{
    float invlength = glmc_vec4f_length(src)
    dest[0] = src[0]*invlength;
    dest[1] = src[1]*invlength;
    dest[2] = src[2]*invlength;
    dest[3] = src[3]*invlength;
}

inline void glmc_vec4f_add(vec4f dest, vec4f src_a, vec4f src_b) // dest = src_a + src_b;
{
    dest[0] = src_a[0] + src_b[0];
    dest[1] = src_a[1] + src_b[1];
    dest[2] = src_a[2] + src_b[2];
    dest[3] = src_a[3] + src_b[3];
}

inline void glmc_vec4f_add_dest(vec4f src_dest, vec4f src_b) // dest += src_a;
{
    src_dest[0] = src_dest[0] + src_b[0];
    src_dest[1] = src_dest[1] + src_b[1];
    src_dest[2] = src_dest[2] + src_b[2];
    src_dest[3] = src_dest[3] + src_b[3];
}

inline void glmc_vec4f_sub(vec4f dest, vec4f src_a, vec4f src_b) // dest = src_a - src_b;
{
    dest[0] = src_a[0] - src_b[0];
    dest[1] = src_a[1] - src_b[1];
    dest[2] = src_a[2] - src_b[2];
    dest[3] = src_a[3] - src_b[3];
}
inline void glmc_vec4f_sub_dest(vec4f src_dest, vec4f src_b) // dest -= src_a;
{
    src_dest[0] = src_dest[0] - src_b[0];
    src_dest[1] = src_dest[1] - src_b[1];
    src_dest[2] = src_dest[2] - src_b[2];
    src_dest[3] = src_dest[3] - src_b[3];
}

inline void glmc_vec4f_mul(vec4f dest, vec4f src_a, vec4f src_b) // dest = src_a * src_b;
{
    dest[0] = src_a[0] * src_b[0];
    dest[1] = src_a[1] * src_b[1];
    dest[2] = src_a[2] * src_b[2];
    dest[3] = src_a[3] * src_b[3];
}
inline void glmc_vec4f_mul_dest(vec4f src_dest, vec4f src_b) // dest *= src_a;
{
    src_dest[0] = src_dest[0] * src_b[0];
    src_dest[1] = src_dest[1] * src_b[1];
    src_dest[2] = src_dest[2] * src_b[2];
    src_dest[3] = src_dest[3] * src_b[3];
}
inline void glmc_vec4f_mul_s(vec4f dest, vec4f src_a, float src_b) // dest = src_a * scalar
{
    dest[0] = src_a[0] * src_b;
    dest[1] = src_a[1] * src_b;
    dest[2] = src_a[2] * src_b;
    dest[3] = src_a[3] * src_b;
}

inline void glmc_vec4f_div(vec4f dest, vec4f src_a, vec4f src_b) // dest = src_a / src_b;
{
    dest[0] = src_a[0] / src_b[0];
    dest[1] = src_a[1] / src_b[1];
    dest[2] = src_a[2] / src_b[2];
    dest[3] = src_a[3] / src_b[3];
}

inline void glmc_vec4f_div_dest(vec4f src_dest, vec4f src_b) // dest /= src_a;
{
    src_dest[0] = src_dest[0] / src_b[0];
    src_dest[1] = src_dest[1] / src_b[1];
    src_dest[2] = src_dest[2] / src_b[2];
    src_dest[3] = src_dest[3] / src_b[3];
}

inline void glmc_vec4f_div_s(vec4f dest, vec4f src_a, float src_b)
{
    dest[0] = src_a[0] / src_b;
    dest[1] = src_a[1] / src_b;
    dest[2] = src_a[2] / src_b;
    dest[3] = src_a[3] / src_b;
}

inline void glmc_vec4f_addadd(vec4f dest, vec4f src_a, vec4f src_b) // dest += src_a + src_b;
{
    dest[0] = dest[0] + src_a[0] + src_b[0];
    dest[1] = dest[1] + src_a[1] + src_b[1];
    dest[2] = dest[2] + src_a[2] + src_b[2];
    dest[3] = dest[3] + src_a[3] + src_b[3];
}

inline void glmc_vec4f_subadd(vec4f dest, vec4f src_a, vec4f src_b) // dest += src_a - src_b;
{
    dest[0] = dest[0] + src_a[0] - src_b[0];
    dest[1] = dest[1] + src_a[1] - src_b[1];
    dest[2] = dest[2] + src_a[2] - src_b[2];
    dest[3] = dest[3] + src_a[3] - src_b[3];
}

inline void glmc_vec4f_madd(vec4f dest, vec4f src_a, vec4f src_b) // dest += src_a * src_b;
{
    dest[0] = dest[0] + src_a[0] * src_b[0];
    dest[1] = dest[1] + src_a[1] * src_b[1];
    dest[2] = dest[2] + src_a[2] * src_b[2];
    dest[3] = dest[3] + src_a[3] * src_b[3];
}

inline void glmc_vec4f_msub(vec4f dest, vec4f src_a, vec4f src_b) // dest -= src_a * src_b;
{
    dest[0] = dest[0] - src_a[0] * src_b[0];
    dest[1] = dest[1] - src_a[1] * src_b[1];
    dest[2] = dest[2] - src_a[2] * src_b[2];
    dest[3] = dest[3] - src_a[3] * src_b[3];
}

inline float glmc_vec4f_dot(vec4f src_a, vec4f src_b)
{
    return src_a[0]*src_b[0] + src_a[1]*src_b[1] + src_a[2]*src_b[2] + src_a[3]*src_b[3]
}
