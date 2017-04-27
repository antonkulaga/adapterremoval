/*************************************************************************\
 * AdapterRemoval - cleaning next-generation sequencing reads            *
 *                                                                       *
 * Copyright (C) 2017 by Mikkel Schubert - mikkelsch@gmail.com           *
 *                                                                       *
 * If you use the program, please cite the paper:                        *
 * S. Lindgreen (2012): AdapterRemoval: Easy Cleaning of Next Generation *
 * Sequencing Reads, BMC Research Notes, 5:337                           *
 * http://www.biomedcentral.com/1756-0500/5/337/                         *
 *                                                                       *
 * This program is free software: you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. *
\*************************************************************************/
#ifndef MULTIFILE_H
#define MULTIFILE_H

#include <memory>

#include "commontypes.h"
#include "linereader.h"


namespace ar
{


/**
 * Multi-file line-reader
 *
 * TODO
 */
class joined_line_readers : public line_reader_base
{
public:
    /** TODO */
    joined_line_readers(const string_vec& filenames);

    /** TODO */
    ~joined_line_readers();

    /** TODO */
    bool getline(std::string& dst);

private:
    /** TODO */
    bool open_next_file();

    //! Not implemented
    joined_line_readers(const joined_line_readers&);
    //! Not implemented
    joined_line_readers& operator=(const joined_line_readers&);

    //! Files left to read; stored in reverse order.
    string_vec m_filenames;
    //! Currently open file, if any.
    std::unique_ptr<line_reader> m_reader;
};


} // namespace ar

#endif
