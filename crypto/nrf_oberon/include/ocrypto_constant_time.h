/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**@file
 * @defgroup ocrypto Oberon cryptographic library
 * @{
 * @brief Highly optimized cryptographic algorithm implementation for Cortex-M0, Cortex-M4,
 * and Cortex-M33. Created by Oberon, under distribution license with Nordic Semiconductor ASA.
 * @}
 *
 * @defgroup ocrypto_constant_time Constant-time APIs
 * @ingroup ocrypto
 * @{
 * @brief Timing-invariant functions to use with cryptography.
 */

#ifndef OCRYPTO_CONSTANT_TIME_H
#define OCRYPTO_CONSTANT_TIME_H

#include <stddef.h>
#include <string.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Variable length comparison.
 *
 * @param x      Memory region to compare with @p y.
 * @param y      Memory region to compare with @p x.
 * @param length Number of bytes to compare, @p length > 0.
 *
 * @retval 1 If @p x and @p y point to equal memory regions.
 * @retval 0 Otherwise.
 */
int ocrypto_constant_time_equal(const void *x, const void *y, size_t length);

/**
 * Variable length compare to zero.
 *
 * @param x      Memory region that will be compared.
 * @param length Number of bytes to compare, @p length > 0.
 *
 * @retval 1 If @p x is equal to a zero memory region.
 * @retval 0 Otherwise.
 */
int ocrypto_constant_time_is_zero(const void *x, size_t length);

/**
 * Variable length copy.
 *
 * @param x      Memory region to copy @p y to.
 * @param y      Memory region to copy to @p x.
 * @param length Number of bytes to copy, @p length > 0.
 */
// void ocrypto_constant_time_copy(void *x, const void *y, size_t length);
#define ocrypto_constant_time_copy(x, y, length) memcpy(x, y, length)

/**
 * Variable length fill with zero.
 *
 * @param x      Memory region to be filled with zero.
 * @param length Number of bytes to fill, @p length > 0.
 */
// void ocrypto_constant_time_fill_zero(void *x, size_t length);
#define ocrypto_constant_time_fill_zero(x, length) memset(x, 0, length)

/**
 * Variable length bitwise xor.
 *
 * @param r      Memory region to store the result.
 * @param x      Memory region containing the first argument.
 * @param y      Memory region containing the second argument.
 * @param length Number of bytes in both arguments, @p length > 0.
 *
 * @remark @p r may be same as @p x or @p y.
 */
void ocrypto_constant_time_xor(void *r, const void *x, const void *y, size_t length);

#ifdef __cplusplus
}
#endif

#endif

/** @} */
