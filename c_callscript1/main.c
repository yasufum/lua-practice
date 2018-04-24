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

	char* sname = "vars.lua";
	call_lua(L, sname);
	// Access to lua script
	lua_getglobal(L, "NAME");
	lua_getglobal(L, "LEVEL");
	lua_getglobal(L, "HP");
	lua_getglobal(L, "ATTACK");
	lua_getglobal(L, "SWIFT");
	lua_getglobal(L, "EXP");
	lua_getglobal(L, "LOCATION");

	// Check some variables
	if (!lua_isstring(L, -7) || !lua_isnumber(L, -6)) {
		printf("Could not get varibles !\n");
		return 1;
	}

	printf("NAME: %s\n", lua_tostring(L, -7));
	printf("LEVEL: %llu\n", lua_tointeger(L, -6));
	printf("HP: %llu\n", lua_tointeger(L, -5));
	printf("ATTACK: %llu\n", lua_tointeger(L, -4));
	printf("SWIFT: %llu\n", lua_tointeger(L, -3));
	printf("EXP: %llu\n", lua_tointeger(L, -2));
	printf("LOCATION: %s\n", lua_tostring(L, -1));

	lua_close(L);

	return 0;
}
