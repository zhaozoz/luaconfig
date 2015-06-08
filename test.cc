#include "lua_config.h"

int main(int argc, char* argv[]) {
  LuaConfig lua_config;
  string config_file = "config.lua";
  if (argc > 1) {
    config_file = argv[1];
    std::cout << "custom config file: " << config_file << std::endl;
  }
  if (!lua_config.load_file(config_file)) {
    std::cout << "load error" << std::endl;  
    return -1;
  }
  double Reduction[6];
  for (int i = 0; i < 6; i++) {
    Reduction[i] = lua_config.read_double_from_table_index("Reductions", i + 1);
    std::cout << "Reduction: " << i << " " << Reduction[i] << std::endl;
  } 
  double plus_put_per_circle = lua_config.read_double("PlusPutPerCircle");
  std::cout << "PlusPutPerCircle: " << plus_put_per_circle << std::endl;

  return 0;
}
