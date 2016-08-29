/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file binToC.cxx
 * @author drose
 * @date 2003-07-18
 */

#include "binToC.h"

// The number of bytes across the page to write.
static const int col_width = 11;

/**
 *
 */
BinToC::
BinToC() :
  WithOutputFile(true, true, false)
{
  clear_runlines();
  add_runline("input output.c");
  add_runline("input -o output.c");
  add_runline("input >output.c");

  set_program_brief("convert binary data to a compilable C table");
  set_program_description
    ("bin2c is a simple utility program to read a disk file, presumably "
     "one with binary contents, and output a table that can be "
     "compiled via a C compiler to generate the same data.  It's handy "
     "for portably importing binary data into a library or executable.");

  add_option
    ("n", "name", 0,
     "Specify the name of the table that is generated.",
     &BinToC::dispatch_string, NULL, &_table_name);

  add_option
    ("static", "", 0,
     "Flag the table with the keyword 'static'.",
     &BinToC::dispatch_none, &_static_table);

  add_option
    ("string", "", 0,
     "Define the table suitablly to pass to a string constructor.",
     &BinToC::dispatch_none, &_for_string);

  add_option
    ("o", "filename", 0,
     "Specify the filename to which the resulting C code will be written.  "
     "If this option is omitted, the last parameter name is taken to be the "
     "name of the output file, or standard output is used if there are no "
     "other parameters.",
     &BinToC::dispatch_filename, &_got_output_filename, &_output_filename);

  _table_name = "data";
}

/**
 *
 */
void BinToC::
run() {
  ifstream in;
  if (!_input_filename.open_read(in)) {
    nout << "Unable to read " << _input_filename << ".\n";
    exit(1);
  }

  ostream &out = get_output();
  string static_keyword;
  if (_static_table) {
    static_keyword = "static ";
  }

  string table_type = "const unsigned char ";
  string length_type = "const int ";
  if (_for_string) {
    // Actually, declaring the table as "const char" causes VC7 to yell about
    // truncating all of the values >= 0x80. table_type = "const char ";
    length_type = "const size_t ";
  }

  out << "\n"
      << "/*\n"
      << " * This table was generated by the command:\n"
      << " *\n"
      << " * " << get_exec_command() << "\n"
      << " */\n"
      << "\n"
      << "#include <stddef.h>\n"
      << "\n"
      << static_keyword << table_type << _table_name << "[] = {";
  out << hex << setfill('0');
  int count = 0;
  int col = 0;
  unsigned int ch;
  ch = in.get();
  while (!in.fail() && !in.eof()) {
    if (col == 0) {
      out << "\n  ";
    } else if (col == col_width) {
      out << ",\n  ";
      col = 0;
    } else {
      out << ", ";
    }
    out << "0x" << setw(2) << ch;
    col++;
    count++;
    ch = in.get();
  }
  out << "\n};\n\n"
      << static_keyword << length_type << _table_name << "_len = "
      << dec << count << ";\n\n";
}

/**
 *
 */
bool BinToC::
handle_args(ProgramBase::Args &args) {
  if (args.size() == 2 && !_got_output_filename) {
    // The second argument, if present, is implicitly the output file.
    _got_output_filename = true;
    _output_filename = args[1];
    args.pop_back();
  }

  if (args.size() != 1) {
    nout << "You must specify exactly one input file to read on the command line.\n";
    return false;
  }

  _input_filename = Filename::binary_filename(args[0]);
  return true;
}


int main(int argc, char *argv[]) {
  BinToC prog;
  prog.parse_command_line(argc, argv);
  prog.run();
  return 0;
}
