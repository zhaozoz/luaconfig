all:
	g++ -o luaconfig lua_config.cc test.cc `pkg-config --cflags --libs lua5.1`
