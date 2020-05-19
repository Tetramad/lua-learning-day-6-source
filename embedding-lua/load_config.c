/*
 * load_config.c
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

#include "starry.h"

int load_config(void) {
  lua_State *L;
  int type;
  lua_Integer N;

  if ((L = luaL_newstate()) == NULL) {
    fprintf(stderr, "starry: failed to create lua instance\n");
    exit(EXIT_FAILURE);
  }
  luaL_openlibs(L);

  if (luaL_loadfile(L, "config.lua") != LUA_OK ||
      lua_pcall(L, 0, 0, 0) != LUA_OK) {
    fprintf(stderr, "starry: failed to load config.lua file: %s\n",
            lua_tostring(L, -1));
    lua_close(L);
    exit(EXIT_FAILURE);
  }

  type = lua_getglobal(L, "N");
  if (type != LUA_TNUMBER) {
    if (type == LUA_TNIL) {
      fprintf(stderr, "starry: the value of N must be set\n");
    } else {
      fprintf(stderr, "starry: N must be an integer\n");
    }
    lua_close(L);
    exit(EXIT_FAILURE);
  }
  N = lua_tointeger(L, -1);
  lua_close(L);

  if (N < N_MIN || N > N_MAX) {
    fprintf(stderr, "starry: N must be an integer between %d and %d\n", N_MIN,
            N_MAX);
    exit(EXIT_FAILURE);
  } else {
    return (int)N;
  }
}
