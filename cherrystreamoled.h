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

#include "quantum.h"

#define LAYOUT( \
                                                 K71, K21, K61, K31, K51, K41,                                      \
    K4B,      K5B, K4F, K5F, K4A,   K44, K54, K49, K4E,    K5E, K48, K43, K53,  K47, K57, K4D,  K4G, K5G, K45, K55, \
    K3B, K6B, K3F, K6F, K5A, K34, K64, K59, K3E, K6E, K58, K33, K63, K37,       K67, K5D, K3D,  K4C, K5C, K42, K62, \
    K2B,   K7B, K2F, K3A, K6A, K24, K39, K69, K2E, K38, K68, K23, K73,  K07,    K27, K6D, K2D,  K3C, K6C, K32, K72, \
    K1B,    K0B, K7F, K2A, K7A, K74, K29, K79, K7E, K28, K78, K35, K25,                         K7D, K2C, K22,      \
    K11,  K1F, K0F, K1A, K0A, K14, K19, K09, K1E, K0E, K18, K08, K01,                K77,       K1D, K7C, K12, K02, \
    K16,  K00,  K0G,              K04,                K1G,  K75,  K03,  K06,    K13, K17, K0D,  K1C,      K0C       \
) { \
    { K00,   K01,   K02,   K03,   K04,   KC_NO, K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E,   K0F,   K0G   }, \
    { KC_NO, K11,   K12,   K13,   K14,   KC_NO, K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E,   K1F,   K1G   }, \
    { KC_NO, K21,   K22,   K23,   K24,   K25,   KC_NO, K27,   K28,   K29,   K2A,   K2B,   K2C,   K2D,   K2E,   K2F,   KC_NO }, \
    { KC_NO, K31,   K32,   K33,   K34,   K35,   KC_NO, K37,   K38,   K39,   K3A,   K3B,   K3C,   K3D,   K3E,   K3F,   KC_NO }, \
    { KC_NO, K41,   K42,   K43,   K44,   K45,   KC_NO, K47,   K48,   K49,   K4A,   K4B,   K4C,   K4D,   K4E,   K4F,   K4G   }, \
    { KC_NO, K51,   KC_NO, K53,   K54,   K55,   KC_NO, K57,   K58,   K59,   K5A,   K5B,   K5C,   K5D,   K5E,   K5F,   K5G   }, \
    { KC_NO, K61,   K62,   K63,   K64,   KC_NO, KC_NO, K67,   K68,   K69,   K6A,   K6B,   K6C,   K6D,   K6E,   K6F,   KC_NO }, \
    { KC_NO, K71,   K72,   K73,   K74,   K75,   KC_NO, K77,   K78,   K79,   K7A,   K7B,   K7C,   K7D,   K7E,   K7F,   KC_NO }, \
}
