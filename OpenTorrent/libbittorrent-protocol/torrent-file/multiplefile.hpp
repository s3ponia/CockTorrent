//
// Created by Linux Oid on 28.04.2020.
//

#ifndef OPENTORRENT_MULTIPLEFILE_H
#define OPENTORRENT_MULTIPLEFILE_H

#include <libbencode/bencode-adapter.hpp>
#include <libbencode/bencode.hpp>
#include <libbittorrent-protocol/torrent-file/basefile.hpp>
#include <vector>

namespace opentorrent {
class MultipleFile : public BaseFile {
 public:
  struct File;
  using InfoDictionary = BaseFile::Dictionary;
  using String = BaseFile::String;
  using Integer = BaseFile::Integer;
  using List = std::vector<File>;
  using BencodeElement = BaseFile::BencodeElement;
  using BencodeAdapter = BaseFile::BencodeAdapter;

  struct File {
    using List = std::vector<String>;

    explicit File(BencodeElement const &dict);

    static List ListFromBencode(const BencodeAdapter::ListType &el);

    Integer length;
    List path;
  };

  explicit MultipleFile(BencodeElement const &el);

  [[nodiscard]] const List &files() const;

 private:
  List files_;
};
}  // namespace opentorrent

#endif  // OPENTORRENT_MULTIPLEFILE_H
