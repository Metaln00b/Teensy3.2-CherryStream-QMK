/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// TODO: including this causes "error: expected identifier before '(' token" errors
//#include "config_common.h"

#define MATRIX_ROW_PINS { D0, D2, D3, C3, C4, D6, C1, C2 }
#define MATRIX_COL_PINS { C6, C7, D1, C0, B0, B1, D5, A5, B19, E1, C9, C8, C10, C11, E0, B18, A4 }
#define UNUSED_PINS

// i2c_master defines
#define I2C1_SCL 2 // A5 on pinout = B2
#define I2C1_SDA 3 // A4 on pinout = B3
#define I2C1_SCL_PAL_MODE PAL_MODE_ALTERNATIVE_2
#define I2C1_SDA_PAL_MODE PAL_MODE_ALTERNATIVE_2
