/*
 * Simulator of microcontrollers (buscl.h)
 *
 * Copyright (C) 2022 Drotos Daniel
 * 
 * To contact author send email to dr.dkdb@gmail.com
 *
 */

/* This file is part of microcontroller simulator: ucsim.

UCSIM is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

UCSIM is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with UCSIM; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA. */
/*@1@*/

#ifndef BUSCL_HEADER
#define BUSCL_HEADER

#include "hwcl.h"


enum bus_confs
  {
    tbus_on	= 0,
    tbus_in	= 1,
    tbus_out	= 2,
    tbus_nuof	= 3
  };

class cl_bus: public cl_hw
{
 public:
  class cl_memory_cell *out_ff;
 public:
  cl_bus(class cl_uc *auc);
  virtual int init(void);
  virtual void reset(void);
  virtual void print_info(class cl_console_base *con);
  virtual int tick(int cycles) { return resGO; }
  virtual unsigned int cfg_size(void) { return tbus_nuof; }
  virtual const char *cfg_help(t_addr addr);
  virtual t_mem conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val);
  virtual void latch(u8_t val);
  virtual void orl(u8_t val);
  virtual void anl(u8_t val);
};


#endif

/* End of i8048.src/buscl.h */
