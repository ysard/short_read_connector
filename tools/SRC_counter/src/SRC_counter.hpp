/*****************************************************************************
 *   GATB : Genome Assembly Tool Box
 *   Copyright (C) 2014  INRIA
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#ifndef _TOOL_SRC_counter_HPP_
#define _TOOL_SRC_counter_HPP_

/********************************************************************************/
#include <gatb/system/impl/SystemInfoCommon.hpp>// for having the memory
#include <gatb/gatb_core.hpp>
#include "../../../thirdparty/IteratorKmerH5/IteratorKmerH5.hpp"
#include "../../../thirdparty/quasi_dictionary/src/quasidictionary.h"
#include <common.hpp>
#include <boolean_vector.hpp>
/********************************************************************************/



class SRC_counter : public Tool
{
	
private:
	quasidictionaryKeyGeneric <IteratorKmerH5Wrapper, unsigned char > quasiDico;
	u_int64_t nbSolidKmers;
    int nbCores;
    int fingerprint_size;
	int kmer_size;
    int gamma_value;
	static const size_t span = KMER_SPAN(1);
    bool keep_low_complexity;
    int windows_size;
    int threshold;
public:

    // Constructor
	SRC_counter ();

    // Actual job done by the tool is here
    void execute ();

    void create_and_fill_quasi_dictionary ();


    void parse_query_sequences();
};

/********************************************************************************/

#endif /* _TOOL_SRC_counter_HPP_ */
