#ifndef LUA_CONFIG_H_
#define LUA_CONFIG_H_
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};
#include <iostream>

using namespace std;
class LuaConfig {
 public:
  LuaConfig();
  ~LuaConfig();
  bool load_file(string file_str);
  string read_string(string str);
  int read_integer(string str);
  double read_double(string str);
  bool read_bool(string str);
  double read_double_from_table_index(string table, int index);
  double read_double_from_table_item(string table, string item);
 private:
  lua_State *L;
};

#endif // LUA_CONFIG_H_

