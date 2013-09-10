// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _REPOBUILD_NODES_CMAKE_H__
#define _REPOBUILD_NODES_CMAKE_H__

#include <string>
#include "repobuild/nodes/node.h"

namespace repobuild {

class CmakeNode : public Node {
 public:
  CmakeNode(const TargetInfo& t,
                   const Input& i)
      : Node(t, i) {
  }
  virtual ~CmakeNode() {}
  virtual void Parse(BuildFile* file, const BuildFileNode& input);
  virtual void WriteMakefile(Makefile* out) const {
    WriteBaseUserTarget(out);
  }
};

}  // namespace repobuild

# endif  // _REPOBUILD_NODES_CMAKE_H__
