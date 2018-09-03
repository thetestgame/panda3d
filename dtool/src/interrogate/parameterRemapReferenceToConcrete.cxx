/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file parameterRemapReferenceToConcrete.cxx
 * @author drose
 * @date 2000-08-04
 */

#include "parameterRemapReferenceToConcrete.h"
#include "typeManager.h"

#include "cppType.h"
#include "cppDeclaration.h"
#include "cppConstType.h"
#include "cppPointerType.h"
#include "cppReferenceType.h"

/**
 *
 */
ParameterRemapReferenceToConcrete::
ParameterRemapReferenceToConcrete(CPPType *orig_type) :
  ParameterRemap(orig_type)
{
  _new_type = TypeManager::unwrap_const_reference(orig_type);
}

/**
 * Outputs an expression that converts the indicated variable from the new
 * type to the original type, for passing into the actual C++ function.
 */
void ParameterRemapReferenceToConcrete::
pass_parameter(std::ostream &out, const std::string &variable_name) {
  out << variable_name;
}

/**
 * Returns an expression that evalutes to the appropriate value type for
 * returning from the function, given an expression of the original type.
 */
std::string ParameterRemapReferenceToConcrete::
get_return_expr(const std::string &expression) {
  return expression;
}
