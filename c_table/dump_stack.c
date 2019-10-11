/**
 * print the contents inside the stack.
 */

#include "mylua.h"

void dumpStack(lua_State* L)
{
	int i;
	int stackSize = lua_gettop(L);

	for(i = stackSize; i >= 1; i--) {
		int type = lua_type(L, i);
		printf("Stack[%2d] type:%s, value:", i, lua_typename(L, type));

		switch(type) {
			case LUA_TNUMBER:
				printf("%f", lua_tonumber(L, i));
				break;
			case LUA_TBOOLEAN:
				if(lua_toboolean(L, i))
					printf("TRUE");
				else
					printf("FALSE");
				break;
			case LUA_TSTRING:
				printf("%s", lua_tostring(L, i));
				break;
			case LUA_TNIL:
				break;
			default:
				printf("%s", lua_typename(L, type));
				break;
		}
		printf("\n");
	}
	printf("\n");
}
