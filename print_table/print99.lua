#!/usr/bin/env lua

--[[
--Calculate appropriate length of each of entry in the table
--]]
function adjust_space(x, y)
  pad = 1
  s = string.len(x * y) + pad
  return s
end

--[[
--Print multiplication table of x and y
--]]
function print_xy(x, y)
  s = adjust_space(x, y)
  for i = 1, x do
    for j = 1, y do
      -- Use io.write() if do not print '\n'
      io.write(string.format("%"..tostring(s).."d", i*j))
    end
    io.write("\n")
  end
end

function main()
  -- Get the numbers of multiplication table
  x, y = tonumber(arg[1]), tonumber(arg[2])

  if #arg == 0 then
    x, y = 9, 9
  elseif #arg ~= 2 then
    print("Required two args, or no args for default!")
    os.exit()
  end

  -- Check if the given numbers are valid
  ary = {x, y}
  for i = 1,2 do
    if ary[i] == nil then
      print("Invalid argument: "..string.format("%s", arg[i]))
      os.exit()
    end
  end

  print_xy(x, y)
end

main()
