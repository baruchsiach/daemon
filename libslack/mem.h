/*
* libslack - http://libslack.org/
*
* Copyright (C) 1999-2001 raf <raf@raf.org>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
* or visit http://www.gnu.org/copyleft/gpl.html
*
* 20010215 raf <raf@raf.org>
*/

#ifndef LIBSLACK_MEM_H
#define LIBSLACK_MEM_H

#include <stdlib.h>

#include <slack/hdr.h>
#include <slack/thread.h>

#ifndef null
#define null NULL
#endif

#ifndef nul
#define nul '\0'
#endif

typedef struct Pool Pool;

_start_decls
#define mem_new(type) malloc(sizeof(type))
#define mem_create(size, type) malloc((size) * sizeof(type))
#define mem_resize(mem, size) mem_resize_fn((void **)(mem), (size) * sizeof(*(mem)))
void *mem_resize_fn _args ((void **mem, size_t size));
#define mem_release(mem) free(mem)
#define mem_destroy(mem) (mem_destroy)((void **)(mem))
void *mem_destroy _args ((void **mem));
void *mem_create_secure _args ((size_t size));
void mem_release_secure _args ((void *mem));
#define mem_destroy_secure(mem) (mem_destroy_secure)((void **)(mem))
void *mem_destroy_secure _args ((void **mem));
char *mem_strdup _args ((const char *str));
#define mem_create2d(i, j, type) ((type **)mem_create_space(sizeof(type), (i), (j), 0))
#define mem_create3d(i, j, k, type) ((type ***)mem_create_space(sizeof(type), (i), (j), (k), 0))
#define mem_create4d(i, j, k, l, type) ((type ****)mem_create_space(sizeof(type), (i), (j), (k), (l), 0))
void *mem_create_space _args ((size_t size, ...));
size_t mem_space_start _args ((size_t size, ...));
#define mem_release2d(space) mem_release_space(space)
#define mem_release3d(space) mem_release_space(space)
#define mem_release4d(space) mem_release_space(space)
#define mem_release_space(space) mem_release(space)
#define mem_destroy2d(space) mem_destroy_space(space)
#define mem_destroy3d(space) mem_destroy_space(space)
#define mem_destroy4d(space) mem_destroy_space(space)
#define mem_destroy_space(space) mem_destroy(space)
Pool *pool_create _args ((size_t size));
Pool *pool_create_locked _args ((Locker *locker, size_t size));
void pool_release _args ((Pool *pool));
void *pool_destroy _args ((Pool **pool));
Pool *pool_create_secure _args ((size_t size));
Pool *pool_create_secure_locked _args ((Locker *locker, size_t size));
void pool_release_secure _args ((Pool *pool));
void *pool_destroy_secure _args ((Pool **pool));
void pool_clear_secure _args ((Pool *pool));
#define pool_new(pool, type) pool_alloc((pool), sizeof(type))
#define pool_newsz(pool, size, type) pool_alloc((pool), (size) * sizeof(type))
void *pool_alloc _args ((Pool *pool, size_t bytes));
void pool_clear _args ((Pool *pool));
_end_decls

#endif

/* vi:set ts=4 sw=4: */