/**
 */

#include "mylua.h"

int call_lua(lua_State *L, char* script_name)
{
	if (luaL_loadfile(L, script_name) || lua_pcall(L, 0, 0, 0)) {
		printf("Failed to open vals.lua ...\n");
		printf("error: %s\n", lua_tostring(L, -1));
		return 1;
	}
	return 0;
}


int main(void)
{
	// Setup lua status and configure it to enables calling funciton.
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	int x = 10, y = 5;
	char* sname = "add.lua";
	call_lua(L, sname);
	lua_getglobal(L, "add");
	lua_pushnumber(L, x);
	lua_pushnumber(L, y);
	if (lua_pcall(L, 2, 1, 0) != 0) {
		printf("Failed to funciton!\n");
		printf("error : %s\n", lua_tostring(L, -1) );
		return 1;
	}
	// calclate
	if (lua_isnumber(L, -1)) {
		printf("(C) result: x + y = %llu\n", lua_tointeger(L, -1));
		lua_pop(L, 1);
	}

	lua_close(L);

	return 0;
}
