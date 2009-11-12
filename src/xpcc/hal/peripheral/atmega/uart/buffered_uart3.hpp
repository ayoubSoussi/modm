// coding: utf-8
// ----------------------------------------------------------------------------
/* Copyright (c) 2009, Roboterclub Aachen e.V.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Roboterclub Aachen e.V. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ROBOTERCLUB AACHEN E.V. ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOTERCLUB AACHEN E.V. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id: buffered_uartn.hpp.tmpl 122 2009-11-12 00:06:50Z dergraaf $
 */
// ----------------------------------------------------------------------------
/*
 * WARNING: This file is generated automatically, do not edit!
 * Please modify the corresponding *.tmpl file instead and re-run the
 * script 'generate.py'.
 *
 * Generated 12 Nov 2009, 14:35:16
 */
// ----------------------------------------------------------------------------

#ifndef XPCC__UART3_HPP
#define XPCC__UART3_HPP

#include <stdint.h>

namespace xpcc
{
	/**
	 * @ingroup		hal
	 * @headerfile	<xpcc/hal/peripheral/atmega/uart/buffered_uart3.hpp>
	 * @brief		UART3
	 * 
	 * This implementation uses a ringbuffer.
	 */
	class BufferedUart3
	{
	public:
		/// @todo	check if this works as desired!
		BufferedUart3(uint32_t baudrate)
		{
			this->setBaudrate(baudrate);
		}
		
		/// @brief	Set baud rate
		///
		/// If this function is called with a constant value as parameter,
		/// all the calculation is done by the compiler, so no 32-bit
		/// arithmetic is needed at run-time!
		///
		/// @param	baudrate	desired baud rate
		/// @param	u2x			enabled double speed mode
		static inline void
		setBaudrate(uint32_t baudrate, bool u2x = false)
		{
			uint16_t ubrr;
			if (u2x) {
				ubrr  = (F_CPU / (baudrate * 8l)) - 1;
				ubrr |= 0x8000;
			}
			else {
				ubrr = (F_CPU / (baudrate * 16l)) - 1;
			}
			setBaudrateRegister(ubrr);
		}
		
		static void
		put(char data);
		
		static bool
		get(char& c);
		
	protected:
		static void
		setBaudrateRegister(uint16_t ubrr);
	};
}

#endif // XPCC__UART3_HPP