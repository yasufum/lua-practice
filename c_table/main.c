/**
 * An example of table on lua stack usage.
 *
 * Set/get key-value pair to/from table.
 *
 * Set key-value to the table.
 * void lua_settable (lua_State *L, int index);
 * void lua_setfield (lua_State *L, int index, const char *k);
 *
 * Get value from the table. Value is move to top of the stack.
 * void lua_gettable (lua_State *L, int index);
 * void lua_getfield (lua_State *L, int index, const char *k);
 */

#include "mylua.h"


int main(void)
{
	lua_State *L = luaL_newstate();
	lua_newtable(L);

	printf("Do stacking ...\n\n");


	printf("Create new table and push a key-value pair\n");
	// Add a key-value
	lua_pushnumber(L, 10);  // as key
	lua_pushstring(L, "hello");  // as value
	// Add another key-value
	lua_pushnumber(L, 11);  // as key
	lua_pushstring(L, "hello hello");  // as value
	dumpStack(L);

	printf("Move the pair from stack to table\n");
	lua_settable(L, -5);  // for 2nd pair
	lua_settable(L, -3);  // for 1st pair
	dumpStack(L);

	printf("Add another pair, {\"key\", \"world\"} from stack\n");
	lua_pushstring(L, "world");
	lua_setfield(L, -2, "key");
	dumpStack(L);

	int skey = 11;
	printf("Get value of key:%d to top of stack\n", skey);
	lua_pushnumber(L, skey);
	lua_gettable(L, -2);
	dumpStack(L);

	printf("Get value of key:\"key\" to top of stack\n");
	lua_getfield(L, -2, "key");
	dumpStack(L);

	lua_close(L);
	return 0;
}
