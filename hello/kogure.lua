#!/usr/bin/env lua

--[[
-- Calculate daemonized age from birth year, month and date.
--]]
function age_daemon(by, bm, bd)
  today = os.date("*t")
  y = today["year"] - by
  if (today["month"] < bm) then
    y = y - 1
  elseif (today["month"] == bm) then
    print(today["day"])
    print(bd)
    if (today["day"] < bd) then
      y = y - 1
      print(y)
    end
  end

  -- daemonize!
  y = y + 100000
  return y
end

function main()
  -- He was born on Nov. 10th, 98038 BC actually, but born in 1962 in
  -- the human world!
  k_name = "Daemon Kogure"
  k_age = age_daemon(1962, 11, 10)

  print(k_name .. " is " .. string.format("%d", k_age) .. " years old!")
end

main()
