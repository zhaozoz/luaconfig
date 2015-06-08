
#include "lua_config.h"

LuaConfig::LuaConfig() {
  L = lua_open();
  luaL_openlibs(L);
}

LuaConfig::~LuaConfig() {
  lua_close(L);
}

bool LuaConfig::load_file(string file_str) {
  if (luaL_dofile(L, file_str.c_str())) {
      return false;
  }
  return true;
}

string LuaConfig::read_string(string str) {
  string ret = NULL;
  lua_getglobal(L, str.c_str());
  if (lua_isstring(L, -1)) {
    ret = (string)lua_tostring(L, -1);
  }
  lua_pop(L, 1);
  return ret;
}

int LuaConfig::read_integer(string str) {
  int ret = 0;
  lua_getglobal(L, str.c_str());
  if (lua_isnumber(L, -1)) {
      ret = (int)lua_tonumber(L, -1);
  }
  lua_pop(L, 1);
  return ret;
}

double LuaConfig::read_double(string str) {
  double ret = 0.0;
  lua_getglobal(L, str.c_str());
  if (lua_isnumber(L, -1)) {
    ret = (double)lua_tonumber(L, -1);
  }
  lua_pop(L, 1);
  return ret;
}

bool LuaConfig::read_bool(string str) {
  bool ret = false;
  lua_getglobal(L, str.c_str());
  if (lua_isboolean(L, -1)) {
    ret = (bool)lua_toboolean(L, -1);
  }
  lua_pop(L, 1);
  return ret;
}

double LuaConfig::read_double_from_table_index(string table, int index) {
  double ret = 0.0;
  lua_getglobal(L, table.c_str());
  lua_rawgeti(L, -1, index);
  if (lua_isnumber(L, -1)) {
    ret = lua_tonumber(L, -1);
  }
  lua_pop(L, 2);
  return ret;
}

double LuaConfig::read_double_from_table_item(string table, string item) {
  double ret = 0.0;
  lua_getglobal(L, table.c_str());
  lua_pushfstring(L, item.c_str());
  lua_gettable(L, -2);
  if (lua_isnumber(L, -1)) {
    ret = lua_tonumber(L, -1);
  }
  lua_pop(L, 2);
  return ret;
}
