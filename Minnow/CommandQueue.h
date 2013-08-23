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

#ifndef COMMAND_QUEUE_H 
#define COMMAND_QUEUE_H
 
#include "config.h"
#include <stdint.h>

//
// Command Queue class
//
// Implements queuing of commands. The stepper ISR is responsible for removing 
// commands
//
// Maybe TODO: A possible improvement in the future is have two types of queue. The first (larger) 
// queue holds the compact PaceMaker commands (straight off the wire) - which allows a much 
// larger number of commands to be held; the second is a reduced version of the current
// queue which is in the expanded ISR ready format. The main loop would ensure that commands
// transferred from the first queue to the second before the ISR is idle. 
// This has no affect on the throughput but does mean more commands could be queueud for the
// same amount of memory.
// 
class CommandQueue
{
public:

  static void Init(uint8_t *queue_buffer, uint16_t queue_buffer_len);
  
  static uint8_t *GetCommandInsertionPoint(uint8_t length_required);
  static bool EnqueueCommand(uint8_t command_length);
  static void FlushQueuedCommands();
  
  static bool IsCommandExecuting();
  static uint16_t GetQueuedCommandCount();
  static uint16_t GetRemainingQueueSpace();
  
  static uint16_t GetQueueBufferLength() { return queue_buffer_length; }

private:

  static uint8_t *queue_buffer;
  static uint16_t queue_buffer_length;
  
  static uint8_t *queue_head;
  static uint8_t *queue_tail;
  static uint8_t in_progress_length;
  
};

#endif