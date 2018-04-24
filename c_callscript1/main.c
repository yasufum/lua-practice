/**
 */

#include "mylua.h"

int call_lua(lua_State *L, char* script_name)
{
	if (luaL_loadfile(L, script_name) || lua_pcall(L, 0, 0, 0)) {
		printf("Failed to open %s ...\n", script_name);
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

	char* sname = "vals.lua";
	call_lua(L, sname);
	// Access to lua script
	lua_getglobal(L, "NAME");
	lua_getglobal(L, "SIZE");

	if (!lua_isstring(L, -2) || !lua_isnumber(L, -1)) {
		printf("Could not get value\n");
		return 1;
	}

	printf("NAME: %s\n", lua_tostring(L, -2));
	printf("SIZE: %llu\n", lua_tointeger(L, -1));

	lua_close(L);

	return 0;
}
