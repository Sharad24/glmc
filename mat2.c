#include "glmc.h"

typedef vec2f mat2f[2];

inline void glmc_mat2f_add(mat2f src_a, mat2f src_b, mat2f dest)
{
    dest[0][0] = src_a[0][0] + src_b[0][0];
    dest[0][1] = src_a[0][1] + src_b[0][1];
    dest[1][0] = src_a[1][0] + src_b[0][1];
    dest[1][1] = src_a[1][1] + src_b[1][1];
}

inline void glmc_mat2f_sub_add(mat2f src_dest, mat2f src_b)
{
    src_dest[0][0] = src_dest[0][0] + src_b[0][0];
    src_dest[0][1] = src_dest[0][1] + src_b[0][1];
    src_dest[1][0] = src_dest[1][0] + src_b[0][1];
    src_dest[1][1] = src_dest[1][1] + src_b[1][1];
}

inline void glmc_mat2f_sub(mat2f src_a, mat2f src_b, mat2f dest)
{
    dest[0][0] = src_a[0][0] - src_b[0][0];
    dest[0][1] = src_a[0][1] - src_b[0][1];
    dest[1][0] = src_a[1][0] - src_b[0][1];
    dest[1][1] = src_a[1][1] - src_b[1][1];
}

inline void glmc_mat2f_sub_dest(mat2f src_dest, mat2f src_b)
{
    src_dest[0][0] = src_dest[0][0] + src_b[0][0];
    src_dest[0][1] = src_dest[0][1] + src_b[0][1];
    src_dest[1][0] = src_dest[1][0] + src_b[0][1];
    src_dest[1][1] = src_dest[1][1] + src_b[1][1];
}

inline void glmc_mat2f_mul(mat2f dest, mat2f src_a, mat2f, src_b)
{
    dest[0][0] = src_a[0][0]*src_b[0][0] + src_a[0][1]*src_b[1][0];
    dest[0][1] = src_a[0][0]*src_b[0][1] + src_a[0][1]*src_b[1][1];
    dest[1][0] = src_a[1][0]*src_b[0][0] + src_a[1][1]*src_b[1][0];
    dest[1][1] = src_a[1][0]*src_b[1][0] + src_a[1][1]*src_b[1][1];
}

inline void glmc_mat2f_mul_dest(mat2f src_dest, mat2f src)
{
    src_dest[0][0] = src_dest[0][0]*src_b[0][0] + src_dest[0][1]*src_b[1][0];
    src_dest[0][1] = src_dest[0][0]*src_b[0][1] + src_dest[0][1]*src_b[1][1];
    src_dest[1][0] = src_dest[1][0]*src_b[0][0] + src_dest[1][1]*src_b[1][0];
    src_dest[1][1] = src_dest[1][0]*src_b[1][0] + src_dest[1][1]*src_b[1][1];
}

inline void glmc_mat2f_mul_s(mat2f dest, mat2f src_a, float src_b)
{
    dest[0][0] = src_a[0][0]*src_b;
    dest[0][1] = src_a[0][1]*src_b;
    dest[1][0] = src_a[1][0]*src_b;
    dest[1][1] = src_a[1][1]*src_b;
}

inline void glmc_mat2f_div_s(mat2f dest, mat2f src_a, float src_b)
{
    float b_inv = 1/src_b;
    dest[0][0] = src_a[0][0]*b_inv;
    dest[0][1] = src_a[0][1]*b_inv;
    dest[1][0] = src_a[1][0]*b_inv;
    dest[1][1] = src_a[1][1]*b_inv;
}

inline float mat2f_det(mat2f src)
{
    return src[0][0]*src[1][1] - src[0][1]*src[1][0]
}

inline void glmc_mat2f_inv(mat2f dest, mat2f src)
{
    float det = mat2f_det(src);
    dest[0][0] = src[1][1];
    dest[1][1] = src[0][0];
    dest[0][1] = -1*src[1][0];
    dest[1][0] = -1*src[0][1];
    glmc_mat2f_div_s(dest, dest, det)
}

inline void glmc_mat2f_div(mat2f dest, mat2f src_a, mat2f src_b)
{
    glmc_mat2f_inv(dest, src_b);
    glmc_mat2f_mul(dest, src_a, dest);
}

inline void glmc_mat2f_div_dest(mat2f src_dest, mat2f src)
{
    glmc_mat2f_inv(src, src);
    glmc_mat2f_mul(src_dest, src_dest, src);
}

inline void glmc_mat2f_transpose(mat2f dest, mat2f src)
{
    dest = src;
    dest[0][1] = src[1][0];
    dest[1][0] = src[0][1];
}

inline void glmc_mat2f_mul_add(mat2f dest, mat2f src_a, mat2f src_b)
{
    glmc_mat2f_mul_dest(src_a, src_b);
    glmc_mat2f_add_dest(dest, src_a);
}

inline void glmc_mat2f_mul_add(mat2f dest, mat2f src_a, mat2f src_b)
{
    glmc_mat2f_mul_dest(src_a, src_b);
    glmc_mat2f_sub_dest(dest, src_a);
}
