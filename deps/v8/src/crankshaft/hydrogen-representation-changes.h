// Copyright 2013 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_CRANKSHAFT_HYDROGEN_REPRESENTATION_CHANGES_H_
#define V8_CRANKSHAFT_HYDROGEN_REPRESENTATION_CHANGES_H_

#include "src/crankshaft/hydrogen.h"

namespace v8 {
namespace internal {


class HRepresentationChangesPhase : public HPhase {
 public:
  explicit HRepresentationChangesPhase(HGraph* graph)
      : HPhase("H_Representation changes", graph) { }

  void Run();

 private:
  void InsertRepresentationChangeForUse(HValue* value,
                                        HValue* use_value,
                                        int use_index,
                                        Representation to);
  void InsertRepresentationChangesForValue(HValue* value);
};


}  // namespace internal
}  // namespace v8

#endif  // V8_CRANKSHAFT_HYDROGEN_REPRESENTATION_CHANGES_H_
