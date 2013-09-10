// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _REPOBUILD_NODES_JAVA_BINARY_H__
#define _REPOBUILD_NODES_JAVA_BINARY_H__

#include <string>
#include <vector>
#include "repobuild/nodes/node.h"
#include "repobuild/nodes/java_library.h"

namespace repobuild {

class JavaBinaryNode : public JavaLibraryNode {
 public:
  JavaBinaryNode(const TargetInfo& t,
                 const Input& i)
      : JavaLibraryNode(t, i) {
  }
  virtual ~JavaBinaryNode() {}
  virtual void Parse(BuildFile* file, const BuildFileNode& input);
  virtual void WriteMakeClean(Makefile* out) const;
  virtual void WriteMakefile(Makefile* out) const;
  virtual void FinalOutputs(std::set<Resource>* outputs) const;

 protected:
  // Helper.
  Resource OutBinary() const;
  Resource JarName() const;

  void WriteJar(const Resource& file, Makefile* out) const;

  std::vector<std::string> java_manifest_;
};

}  // namespace repobuild

# endif  // _REPOBUILD_NODES_JAVA_BINARY_H__
