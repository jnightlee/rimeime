// vim: set sts=2 sw=2 et:
// encoding: utf-8
//
// Copyleft 2011 RIME Developers
// License: GPLv3
// 
// 2011-05-02 Wensong He <snowhws@gmail.com>
//

#include <rime/candidate.h>
#include <rime/segmentation.h>
#include "trivial_translator.h"

namespace rime {

Translation* TrivialTranslator::Query(const std::string &input,
                                      const Segment &segment) {
  if (segment.tags.find("abc") == segment.tags.end())
    return NULL;
  EZLOGGERPRINT("input = '%s', [%d, %d)",
                input.c_str(), segment.start, segment.end);
  shared_ptr<Candidate> candidate(
      new Candidate("abc", input, "", segment.start, segment.end, 0));
  Translation *translation = new UniqueTranslation(candidate);
  return translation;
}

}  // namespace rime