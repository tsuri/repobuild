// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _REPOBUILD_NODES_GEN_SH_H__
#define _REPOBUILD_NODES_GEN_SH_H__

#include <map>
#include <string>
#include <vector>
#include "repobuild/nodes/node.h"

namespace repobuild {

class GenShNode : public Node {
 public:
  GenShNode(const TargetInfo& t,
            const Input& i)
      : Node(t, i),
        cd_(true) {
  }
  virtual ~GenShNode() {}
  virtual std::string Name() const { return "gen_sh"; }
  virtual void Parse(BuildFile* file, const BuildFileNode& input);
  virtual void WriteMakeClean(Makefile* out) const;
  virtual void WriteMakefile(Makefile* out) const;
  virtual void DependencyFiles(std::set<Resource>* files) const;

  // Alternative to parse
  void Set(const std::string& build_cmd,
           const std::string& clean_cmd,
           const std::vector<Resource>& input_files,
           const std::vector<std::string>& outputs);
  void SetCd(bool cd) { cd_ = cd; }

  // Static preprocessors
  static void WriteMakeHead(const Input& input, Makefile* out);

  std::string Logfile() const;

 protected:
  std::string WriteCommand(const std::map<std::string, std::string>& env_vars,
                           const std::string& prefix,
                           const std::string& cmd,
                           const std::string& admin_cmd) const;

  std::string build_cmd_;
  std::string clean_cmd_;
  std::vector<Resource> input_files_;
  std::vector<std::string> outputs_;
  bool cd_;
};

}  // namespace repobuild

# endif  // _REPOBUILD_NODES_GEN_SH_H__
