/**
 * An example of lua stack usage.
 *
 * There are several apis for lua stack management.
 *
 * 1. Get stack size
 * int lua_gettop(lua_State* L);
 *
 * 2. Change stack size by poping
 * void lua_settop(lua_State* L, int index);
 *
 * 3. Push a value in direct
 * void lua_pushvalue(lua_State* L, int index);
 *
 * 4. Remove value
 * void lua_remove(lua_State* L, int index);
 *
 * 5. Insert value
 * void lua_insert(lua_State* L, int index);
 *
 * 6. Replace value
 * void lua_replace(lua_State* L, int index);
 */

#include "mylua.h"


/**
 * push contents and print them step by step.
 */
int main(void)
{
	lua_State *L = luaL_newstate();

	printf("Watch inside lua stack...\n\n");

	printf("(1) Push bool true\n");
	lua_pushboolean(L, 1);
	dumpStack(L);

	printf("(2) Push float 10.5\n");
	lua_pushnumber(L, 10.5);
	dumpStack(L);

	printf("(3) Push int 3\n");
	lua_pushinteger(L, 3);
	dumpStack(L);

	printf("(4) Push nil\n");
	lua_pushnil(L);
	dumpStack(L);

	printf("(5) Push stirng 'Hello, world!'.\n");
	lua_pushstring(L, "Hello, world!");
	dumpStack(L);

	printf("(6) Replace 2nd values with top.\n");
	lua_replace(L, 2);
	dumpStack(L);

	printf("(7) Pop two values.\n");
	lua_pop(L, 2);
	dumpStack(L);

	lua_close(L);
	return 0;
}
