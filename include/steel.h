/**
 * Copyright 2012 Dave Majnemer and Kurtis Nusbaum
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef STEEL_STEEL_H_
#define STEEL_STEEL_H_

#include <stddef.h>

typedef int (*steel_ordered_comparator_t)(const void *vp_lhs, const void *vp_rhs);

typedef void *(*steel_allocator_t)(size_t nbytes);
typedef void (*steel_deallocator_t)(void *ptr, size_t *nbytes);

#endif  // STEEL_STEEL_H_
