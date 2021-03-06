/*
 Minnow Pacemaker client firmware.
    
 Copyright (C) 2013 Robert Fairlie-Cuninghame

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//
// Firmware Configuration 
//

#ifndef FIRMWARE_CONFIGURATION_H
#define FIRMWARE_CONFIGURATION_H

#include <stdint.h>

void handle_firmware_configuration_request(const char *name, const char *value);
void handle_firmware_configuration_traversal(const char *name);
void handle_firmware_configuration_value_properties(const char *name);


void apply_initial_configuration();

void apply_firmware_configuration_string_P(const char *str);

void update_firmware_configuration(bool final);


#endif
