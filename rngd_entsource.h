/*
 * rngd_source.h -- Entropy source and conditioning
 *
 * Copyright (C) 2001 Philipp Rumpf
 * Copyright (C) 2004 Henrique de Moraes Holschuh <hmh@debian.org>
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
 */

#ifndef RNGD_ENTSOURCE__H
#define RNGD_ENTSOURCE__H

#include "rng-tools-config.h"

#include <unistd.h>
#include <stdint.h>

/*
 * Initialize entropy source and entropy conditioning
 *
 * sourcedev is the path to the entropy source
 */
extern void init_entropy_source(const char* sourcedev);

/*
 * RNG data source thread
 *
 * This thread receives data from the RNG source into the buffers.
 * Only one data source thread is supported.
 */
extern void *do_rng_data_source_loop( void *trash );

/*
 * RNG FIPS test thread 
 *
 * This thread searches for buffers full of raw data, and runs a FIPS test on
 * them.  If the buffer passes, it marks it as OK, otherwise, it marks the
 * buffer as empty (discards the old data).
 *
 * Only one FIPS test thread is supported.
 */
extern void *do_rng_fips_test_loop( void *trash );

#endif /* RNGD_ENTSOURCE__H */